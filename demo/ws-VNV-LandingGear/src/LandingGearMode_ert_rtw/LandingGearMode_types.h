/*
 * File: LandingGearMode_types.h
 *
 * Code generated for Simulink model 'LandingGearMode'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Thu Mar 19 17:23:03 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LandingGearMode_types_h_
#define RTW_HEADER_LandingGearMode_types_h_
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
#endif                                 /* RTW_HEADER_LandingGearMode_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
