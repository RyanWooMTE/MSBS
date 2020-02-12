/* F28335SerialRtiostream-Rtiostream.c
 *
 * Specifies rtiostream functions to implement serial PIL
 *
 * NOTES: 
 *  - Baud rate is specified as 115.2Kbaud in SCIA_Init();
 *  - rtIOStreamSend & rtIOStreamRecv functions call routines
 *    to perform packing and unpacking data. This is required
 *    because on a C2000, the size of a char is 16-bits, and
 *    serial channel expects 8-bit data. When you implement
 *    for your processor, if it supports 8-bit characters,
 *    you will not need to implement this packing/unpacking.
 *
 * Copyright 2011 The MathWorks, Inc.
 */

// Include header files
#include <stdlib.h>
#include <stdio.h>
#include "PeripheralHeaderIncludes.h"
#include "F28335SerialRtiostream-ProfilerTimer.h"

// Function prototypes
void DeviceInit(void);
void SCIB_Init();

// FIFO Length for F28335 is 16 (Note FIFO Length for F28035 is 4)
#define MW_PIL_SCIFIFOLEN 16    
        
#define NOERROR                        0                         // no error
#define TIMEOUT                        1                         // waiting timeout
#define DATAERR                        2                         // data error (checksum error)
#define PRTYERR                        3                         // parity error
#define FRAMERR                        4                         // frame error
#define FIFOOVRFLWERR                  5						 // FIFO overflow error
#define RCVMAXRETRY                    10
#define RCVMAXCNTS                     1000
#define RCVMAXCNTL                     50000

int scib_rcv(char *rcvBuff, int buffLen, int*sizeCharsRcvd);
int byteswap_L8cmp(unsigned int* outdata, char* recdata, int inportWidth, int
                   typeLen);
void scib_xmit(char* pmsg, int msglen);
int byteswap_L8exp(char* outdata, char* inport ,int inportWidth, int typeLen);

void getSciBaudRegisters(Uint16 * pSCIHBAUD, Uint16 * pSCILBAUD);
/* Allocate large temporary variables in global memory so that they do not
 * show up in stack profiling numbers
 */
#define RTIOSTREAM_MAX_CHAR            32
//#define RTIOSTREAM_MAX_CHAR            1000
char srcSerial[RTIOSTREAM_MAX_CHAR];
char dstSerial[RTIOSTREAM_MAX_CHAR];


/***************** DEFINES ****************************************************/

#define RTIOSTREAM_NO_ERROR (0)
#define RTIOSTREAM_ERROR (-1)
#define SERVER_STREAM_ID (1) /* Allow a single server-side connection */
#define HOSTNAME_MAXLEN (64U)
#define SERVER_PORT_NUM  (17725U)   /* sqrt(pi)*10000 */
#define TMP_BUF_SIZ (40)
#define DEFAULT_RECV_TIMEOUT_SECS (1)
#define EXT_BLOCKING (0)  
#define SOCK_ERR (-1)


/* Function: rtIOStreamOpen ================================================= */
int rtIOStreamOpen(int argc, void * argv[])
{
    // Initialize device
  	DeviceInit();
    
    // Initialize timer for profiling
    profileTimerInit();
  	
  	// Initalize the Serial Comms A peripheral
  	SCIB_Init();
  
    return SERVER_STREAM_ID;
}


/* Function: rtIOStreamClose ================================================ */
int rtIOStreamClose(int streamID)
{
    return RTIOSTREAM_NO_ERROR;
}


/* Function: rtIOStreamSend ================================================ */
int rtIOStreamSend(int streamID, const void *src, size_t size, size_t *sizeSent)
{
    size_t  sizeCharsToSend;

	sizeCharsToSend = size*2;
	*sizeSent = size;

    // Bound to maximum size of buffer to send
	if (sizeCharsToSend > RTIOSTREAM_MAX_CHAR) {
	    sizeCharsToSend = RTIOSTREAM_MAX_CHAR;
   	    *sizeSent       = RTIOSTREAM_MAX_CHAR/2;
 	}

    // Perform byte swap and expand upper and lower 8-bits into
    // into individual 16-bit chars to send
    byteswap_L8exp(srcSerial, (char *) src, *sizeSent, 2);
    
    // Transmit 16-bit chars
    scib_xmit( srcSerial, sizeCharsToSend);
    
    return RTIOSTREAM_NO_ERROR;
}


 /* Function: rtIOStreamRecv ================================================ */
int rtIOStreamRecv(int streamID, void * dst, size_t size, size_t * sizeRecv) 
{
    size_t sizeCharsToRecv;
	int    sizeCharsRecvd = 0;

	sizeCharsToRecv = size*2;
	*sizeRecv = size;

	if (sizeCharsToRecv > RTIOSTREAM_MAX_CHAR) {
	    sizeCharsToRecv = RTIOSTREAM_MAX_CHAR;
 	}            

 	if( scib_rcv(dstSerial, sizeCharsToRecv, &sizeCharsRecvd) != NOERROR)
	    return RTIOSTREAM_ERROR;

    // Unpack 8-bit serial data into 16-bit chars 
	*sizeRecv       = sizeCharsRecvd/2;
	byteswap_L8cmp((unsigned int *)dst, dstSerial, *sizeRecv, 2);
    
    return RTIOSTREAM_NO_ERROR;
}

// Initialize serial port
void SCIB_Init()
{    
   	EALLOW;    
	/*
	* Initialize SCI_A with following parameters:
	*    BaudRate              : 115200
	*    CharacterLengthBits   : 8
	*    EnableLoopBack        : 0
	*    NumberOfStopBits      : 1
	*    ParityMode            : None
	*    SuspensionMode        : Free_run
	*    CommMode              : Raw_data
	*/
	ScibRegs.SCICCR.bit.STOPBITS = 0;    //Number of stop bits. (0: One stop bit, 1: Two stop bits)
	ScibRegs.SCICCR.bit.PARITY = 0;      //Parity mode (0: Odd parity, 1: Even parity)
	ScibRegs.SCICCR.bit.PARITYENA = 0;   //Enable Parity Mode
	ScibRegs.SCICCR.bit.LOOPBKENA = 0;   //Loop Back enable
	ScibRegs.SCICCR.bit.ADDRIDLE_MODE = 0;//ADDR/IDLE Mode control
	ScibRegs.SCICCR.bit.SCICHAR = 7;     //Character length
	ScibRegs.SCICTL1.bit.RXERRINTENA = 0;//Disable receive error interrupt
	ScibRegs.SCICTL1.bit.SWRESET = 1;    //Software reset
	ScibRegs.SCICTL1.bit.TXENA = 1;      // SCI transmitter enable
	ScibRegs.SCICTL1.bit.RXENA = 1;      // SCI receiver enable

    ScibRegs.SCIHBAUD = 0x0000;

 	//SciaRegs.SCILBAUD = 0x0079;		// 79h = 38.4Kbaud  @ LSPCLK = 150/4 MHz
 	//SciaRegs.SCILBAUD = 0x0050;		// 50h = 57.6Kbaud  @ LSPCLK = 150 /4 MHz
 	ScibRegs.SCILBAUD = 0x0028;		    // 28h = 115.2Kbaud @ LSPCLK = 150/4 MHz
    
	//Free run, continue SCI operation regardless of suspend
	ScibRegs.SCIPRI.bit.FREE = 1;        // Free emulation mode control
	ScibRegs.SCIPRI.bit.SOFT = 0;        // Interrupt priority select
	ScibRegs.SCIFFCT.bit.ABDCLR = 0;
	ScibRegs.SCIFFCT.bit.CDC = 0;
	ScibRegs.SCIFFTX.bit.SCIRST = 1;     // SCI reset rx/tx channels
	ScibRegs.SCIFFTX.bit.SCIFFENA = 1;   // SCI FIFO enhancements are enabled.
	ScibRegs.SCIFFTX.bit.TXFIFOXRESET = 1;// Re-enable transmit FIFO operation.
	ScibRegs.SCIFFRX.bit.RXFIFORESET = 1;// Re-enable receive FIFO operation.
    
    // Initialize GPIO for SCIB
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;   // Configure GPIO14 for SCITXDB operation
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;   // Configure GPIO15 for SCIRXDB operation

	EDIS;
}


// Receive character(s) from the SCIa
int scib_rcv(char *rcvBuff, int buffLen, int*sizeCharsRcvd)
{
  int i;
  
  *sizeCharsRcvd = 0;

  for (i = 0; i<buffLen; i++) {
    while (ScibRegs.SCIFFRX.bit.RXFFST == 0){ 
    } // Wait until data is received

    // Get an 8-bit number
    rcvBuff[i] = ScibRegs.SCIRXBUF.all;
    
    // Check for errors
    if (ScibRegs.SCIFFRX.bit.RXFFOVF == 1){
      ScibRegs.SCIFFRX.bit.RXFFOVRCLR = 1;
	  return FIFOOVRFLWERR;
    }
    if (ScibRegs.SCIRXST.bit.FE)
      return FRAMERR;
    if (ScibRegs.SCIRXST.bit.PE)
      return PRTYERR;
    if ((ScibRegs.SCIRXST.bit.RXWAKE ==1) && (ScibRegs.SCIRXST.bit.RXERROR == 1)){
      ScibRegs.SCICTL1.bit.SWRESET = 1;
      ScibRegs.SCICTL1.bit.SWRESET = 0;
      ScibRegs.SCICTL1.bit.SWRESET = 1;
    }

	*sizeCharsRcvd = *sizeCharsRcvd + 1;
  }

  return NOERROR;
}

// Compress 8-bit values from serial into 16-bit chars
// Required since size of a char is 16-bit for a C2000 based processor
int byteswap_L8cmp(unsigned int* outdata, char* recdata, int inportWidth, int
                   typeLen)
{
  int i, j;
  int numWrd = (inportWidth * typeLen)/2;

  /* Little Endian, 8bit swap */
  for (i = 0; i < numWrd; i++) {
    outdata[i] = 0;
    for (j = 0; j<2; j++) {
      outdata[i] += recdata[i*2+j] <<(8*j);
    }
  }

  return 0;
}

// Transmit character(s) from the SCIb
void scib_xmit(char* pmsg, int msglen)
{
  int i;
  for (i = 0; i < msglen; i++) {
    while (ScibRegs.SCIFFTX.bit.TXFFST == MW_PIL_SCIFIFOLEN) {
    } // Wait if the buffer is full

    ScibRegs.SCITXBUF = pmsg[i];
  }

  while (ScibRegs.SCIFFTX.bit.TXFFST != 0) {
  }
}

// expand 16-bit chars into 8-bit values 
// Required since size of a char is 16-bit for a C2000 based processor
int byteswap_L8exp(char* outdata, char* inport ,int inportWidth, int typeLen)
{
  int i,j;
  int k = 0;
  int numWrd = (inportWidth * typeLen)/2;

  /* Little Endian, 8bit swap */
  for (i = 0; i < numWrd; i++) {
    for (j = 0; j < 2; j++) {
      outdata[k++] = (inport[i] >>(8*j)) & 255;
    }
  }

  return 0;
}
/* Calculate the baud rate for registers */
void getSciBaudRegisters(Uint16 * pSCIHBAUD, Uint16 * pSCILBAUD)
{
    // The below parameters are expected to be passed in as defines on the compiler string
    //#define CPU_CLOCK_RATE_MHZ 150
    //#define BAUD_RATE 9600
    
    float LSPCLK;
    float SCIBAUD;
    
    LSPCLK = ((float) CPU_CLOCK_RATE_MHZ) * 1000000.0F  / 4.0F;

    // SCILBAUD follows method specified by sprug71b and ti_c28x_init_sci.tlc
    SCIBAUD = (LSPCLK/((float) BAUD_RATE*8))-1;

    *pSCIHBAUD = SCIBAUD / 256;
    *pSCILBAUD = SCIBAUD - (*pSCIHBAUD * 256);
}
