#ifndef __c1_DisplayModel_h__
#define __c1_DisplayModel_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_DisplayModelInstanceStruct
#define typedef_SFc1_DisplayModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Screen;
  uint8_T c1_tp_three;
  uint8_T c1_tp_zero;
  uint8_T c1_tp_one;
  uint8_T c1_tp_two;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_DisplayModel;
  uint8_T c1_is_c1_DisplayModel;
  uint8_T c1_is_Screen;
  boolean_T c1_prev_signal;
  real_T c1_count;
  real_T c1_diff_max;
  real_T c1_bad;
  real_T c1_sum_sig;
  real_T c1_n;
  real_T c1_select[2];
  real_T c1_middle;
  real_T c1_diff;
  real_T c1_mean;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_DisplayModelInstanceStruct;

#endif                                 /*typedef_SFc1_DisplayModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_DisplayModel_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_DisplayModel_get_check_sum(mxArray *plhs[]);
extern void c1_DisplayModel_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
