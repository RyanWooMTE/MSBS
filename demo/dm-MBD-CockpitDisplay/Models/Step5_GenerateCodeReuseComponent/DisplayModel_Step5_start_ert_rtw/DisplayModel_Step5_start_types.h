/*
 * File: DisplayModel_Step5_start_types.h
 *
 * Code generated for Simulink model 'DisplayModel_Step5_start'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Dec 11 19:21:35 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DisplayModel_Step5_start_types_h_
#define RTW_HEADER_DisplayModel_Step5_start_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_MiscData_
#define _DEFINED_TYPEDEF_FOR_MiscData_

typedef struct {
  real_T FlapPosition;
  real_T CabinPressure;
  real_T HydraulicPressure;
  real_T APUData;
  boolean_T LGLeftLock;
  boolean_T LGRightLock;
} MiscData;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_DisplayModel_Step5_star RT_MODEL_DisplayModel_Step5_sta;

#endif                                 /* RTW_HEADER_DisplayModel_Step5_start_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
