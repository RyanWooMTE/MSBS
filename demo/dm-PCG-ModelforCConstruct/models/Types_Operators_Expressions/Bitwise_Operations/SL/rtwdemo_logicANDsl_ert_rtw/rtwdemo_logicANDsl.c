#include "rtwdemo_logicANDsl.h"
#include "rtwdemo_logicANDsl_private.h"

uint8_T u_1;
uint8_T y_1;
RT_MODEL_rtwdemo_logicANDsl rtwdemo_logicANDsl_M_;
RT_MODEL_rtwdemo_logicANDsl *const rtwdemo_logicANDsl_M = &rtwdemo_logicANDsl_M_;
void rtwdemo_logicANDsl_step(void)
{
  y_1 = (uint8_T)(u_1 & 217);
}

void rtwdemo_logicANDsl_initialize(void)
{
  rtmSetErrorStatus(rtwdemo_logicANDsl_M, (NULL));
  y_1 = 0U;
  u_1 = 0U;
}

void rtwdemo_logicANDsl_terminate(void)
{
}
