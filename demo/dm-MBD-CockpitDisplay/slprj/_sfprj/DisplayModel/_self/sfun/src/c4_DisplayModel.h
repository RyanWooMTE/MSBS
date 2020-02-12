#ifndef __c4_DisplayModel_h__
#define __c4_DisplayModel_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_DisplayModelInstanceStruct
#define typedef_SFc4_DisplayModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_APU_LOGIC;
  uint8_T c4_tp_OFF;
  uint8_T c4_tp_APU_PrepareForStart;
  uint8_T c4_tp_APU_Start;
  uint8_T c4_tp_APU_Running;
  uint8_T c4_tp_Engine_LOGIC;
  uint8_T c4_b_tp_OFF;
  uint8_T c4_tp_Engine_PrepareForStart;
  uint8_T c4_tp_Engine_Start;
  uint8_T c4_tp_Engine_Running;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_DisplayModel;
  uint8_T c4_is_APU_LOGIC;
  uint8_T c4_is_active_APU_LOGIC;
  uint8_T c4_is_Engine_LOGIC;
  uint8_T c4_is_active_Engine_LOGIC;
  uint8_T c4_temporalCounter_i1;
  uint8_T c4_temporalCounter_i2;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_DisplayModelInstanceStruct;

#endif                                 /*typedef_SFc4_DisplayModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_DisplayModel_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_DisplayModel_get_check_sum(mxArray *plhs[]);
extern void c4_DisplayModel_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
