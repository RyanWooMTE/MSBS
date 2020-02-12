#ifndef __c8_DisplayModel_h__
#define __c8_DisplayModel_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_DisplayModelInstanceStruct
#define typedef_SFc8_DisplayModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_Screen;
  uint8_T c8_tp_three;
  uint8_T c8_tp_zero;
  uint8_T c8_tp_one;
  uint8_T c8_tp_two;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_DisplayModel;
  uint8_T c8_is_c8_DisplayModel;
  uint8_T c8_is_Screen;
  boolean_T c8_prev_signal;
  real_T c8_count;
  real_T c8_diff_max;
  real_T c8_bad;
  real_T c8_sum_sig;
  real_T c8_n;
  real_T c8_select[2];
  real_T c8_middle;
  real_T c8_diff;
  real_T c8_mean;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
} SFc8_DisplayModelInstanceStruct;

#endif                                 /*typedef_SFc8_DisplayModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_DisplayModel_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_DisplayModel_get_check_sum(mxArray *plhs[]);
extern void c8_DisplayModel_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
