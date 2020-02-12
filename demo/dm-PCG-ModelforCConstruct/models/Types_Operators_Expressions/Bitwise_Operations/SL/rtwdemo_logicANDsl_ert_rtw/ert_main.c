#include <stdio.h>
#include "rtwdemo_logicANDsl.h"
#include "rtwtypes.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = 0;
  if (OverrunFlag) {
    rtmSetErrorStatus(rtwdemo_logicANDsl_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;
  rtwdemo_logicANDsl_step();
  OverrunFlag = FALSE;
}

int_T main(int_T argc, const char_T *argv[]);
int_T main(int_T argc, const char_T *argv[])
{
  rtwdemo_logicANDsl_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(rtwdemo_logicANDsl_M) == (NULL)) {
  }

  rtwdemo_logicANDsl_terminate();
  return 0;
}
