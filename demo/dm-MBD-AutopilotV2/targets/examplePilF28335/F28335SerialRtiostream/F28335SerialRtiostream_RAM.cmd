// FILE:    F28335SerialRtiostream_RAM.cmd
//
// TITLE:   Linker Command File For PIL example that runs out of RAM
//
// For most meaningful profiling results during PIL, you should
// specify a memory map which matches your production configuration
//
// Copyright 2011 The MathWorks, Inc.


MEMORY
{
PAGE 0 :
   
   BEGIN      : origin = 0x000000, length = 0x000002
   BOOT_RSVD  : origin = 0x000002, length = 0x00004E
   RAMM0      : origin = 0x000050, length = 0x0003B0
   RAML0L3    : origin = 0x008000, length = 0x004800    
   ZONE7A     : origin = 0x200000, length = 0x00FC00
   CSM_RSVD   : origin = 0x33FF80, length = 0x000076
   CSM_PWL    : origin = 0x33FFF8, length = 0x000008
   ADC_CAL    : origin = 0x380080, length = 0x000009
   RESET      : origin = 0x3FFFC0, length = 0x000002
   IQTABLES   : origin = 0x3FE000, length = 0x000b50
   IQTABLES2  : origin = 0x3FEB50, length = 0x00008c
   FPUTABLES  : origin = 0x3FEBDC, length = 0x0006A0
   BOOTROM    : origin = 0x3FF27C, length = 0x000D44               

         
PAGE 1 : 
   RAMM1      : origin = 0x000400, length = 0x000400
   RAML4L7    : origin = 0x00C000, length = 0x004000    
   ZONE7B     : origin = 0x20FC00, length = 0x000400
}
 
 
SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAML0L3,   PAGE = 0  
   .text            : > RAML0L3,   PAGE = 0
   .cinit           : > RAML0L3,   PAGE = 0
   .pinit           : > RAML0L3,   PAGE = 0
   .switch          : > RAML0L3,   PAGE = 0
   
   .stack           : > RAMM1,     PAGE = 1
   .ebss            : > RAML4L7,   PAGE = 1
   .econst          : > RAML4L7,   PAGE = 1      
   .esysmem         : > RAMM1,     PAGE = 1

   IQmath           : > RAML0L3,   PAGE = 0
   IQmathTables     : > IQTABLES,  PAGE = 0, TYPE = NOLOAD 
   IQmathTables2    : > IQTABLES2, PAGE = 0, TYPE = NOLOAD 
   FPUmathTables    : > FPUTABLES, PAGE = 0, TYPE = NOLOAD 
      
   DMARAML4         : > RAML4L7,   PAGE = 1
   DMARAML5         : > RAML4L7,   PAGE = 1
   DMARAML6         : > RAML4L7,   PAGE = 1
   DMARAML7         : > RAML4L7,   PAGE = 1
   
   ZONE7DATA        : > ZONE7B,    PAGE = 1  

   .reset           : > RESET,     PAGE = 0, TYPE = DSECT
   csm_rsvd         : > CSM_RSVD   PAGE = 0, TYPE = DSECT
   csmpasswds       : > CSM_PWL    PAGE = 0, TYPE = DSECT
   
   .adc_cal     : load = ADC_CAL,   PAGE = 0, TYPE = NOLOAD
     
}

SECTIONS
{
	Net_terminals:	> RAML4L7,PAGE = 1
	Controller:		> RAML4L7,PAGE = 1
	IBx_addr: 		> RAML4L7,PAGE = 1
	Buck1Loop:		> RAML4L7,PAGE = 1
	Buck2Loop:		> RAML4L7,PAGE = 1
	DataLogTST: 	> RAML4L7,PAGE = 1
	GraphData: 		> RAML4L7,PAGE = 1
}
