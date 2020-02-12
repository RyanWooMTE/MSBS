#ifndef RTW_HEADER_rtwdemo_logicANDsl_h_
#define RTW_HEADER_rtwdemo_logicANDsl_h_
#ifndef rtwdemo_logicANDsl_COMMON_INCLUDES_
# define rtwdemo_logicANDsl_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#endif

#include "rtwdemo_logicANDsl_types.h"

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

struct tag_RTM_rtwdemo_logicANDsl {
  const char_T * volatile errorStatus;
};

extern uint8_T u_1;
extern uint8_T y_1;
extern void rtwdemo_logicANDsl_initialize(void);
extern void rtwdemo_logicANDsl_step(void);
extern void rtwdemo_logicANDsl_terminate(void);
extern RT_MODEL_rtwdemo_logicANDsl *const rtwdemo_logicANDsl_M;

#endif

