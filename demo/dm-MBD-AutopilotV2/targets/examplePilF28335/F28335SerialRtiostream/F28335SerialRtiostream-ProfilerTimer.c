
/* F28335SerialRtiostream-ProfilerTimer.c
 *
 * Specifies profile timer access functions
 *
 * Copyright 2011 The MathWorks, Inc.
 */

#include "F28335SerialRtiostream-ProfilerTimer.h"

void profileTimerInit( void )       
{
  CpuTimer1Regs.PRD.all = 0xFFFFFFFF;  // max Period
  CpuTimer1Regs.TIM.all = 0xFFFFFFFF;  // set Ctr
  CpuTimer1Regs.TPR.all = 0x00;        // no prescaler
  StartCpuTimer1();
}

unsigned long profileTimerRead( void )
{
    asm(" SETC INTM");
    return(ReadCpuTimer1Counter());
    asm(" CLRC INTM");
}
