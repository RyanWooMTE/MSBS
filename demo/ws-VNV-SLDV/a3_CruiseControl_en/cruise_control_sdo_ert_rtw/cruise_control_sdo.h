/*
 * File: cruise_control_sdo.h
 *
 * Code generated for Simulink model 'cruise_control_sdo'.
 *
 * Model version                  : 1.304
 * Simulink Coder version         : 8.3 (R2012b) 20-Jul-2012
 * TLC version                    : 8.3 (Jul 21 2012)
 * C/C++ source code generated on : Wed Jan 30 05:09:50 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NEC->V850
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_cruise_control_sdo_h_
#define RTW_HEADER_cruise_control_sdo_h_
#ifndef cruise_control_sdo_COMMON_INCLUDES_
# define cruise_control_sdo_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* cruise_control_sdo_COMMON_INCLUDES_ */

#include "cruise_control_sdo_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define cruise_ki                      ((int16_T) 1)
#define cruise_kp                      ((int16_T) 128)

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  int16_T Sum1;                        /* '<S1>/Sum1' */
  int16_T UnitDelay2_DSTATE;           /* '<S1>/Unit Delay2' */
  boolean_T PI_Controller_MODE;        /* '<Root>/PI_Controller' */
} D_Work_cruise_control_sdo;

/* Block signals and states (auto storage) */
extern D_Work_cruise_control_sdo cruise_control_sdo_DWork;

/* Model entry point functions */
extern void cruise_control_sdo_initialize(void);
extern void cruise_control_sdo_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern int16_T brake_pressure;
extern boolean_T dec;
extern int16_T diff_target;
extern int16_T driver_throt;
extern boolean_T enable;
extern boolean_T inc;
extern boolean_T is_ctrl;
extern boolean_T set;
extern int16_T speed;
extern int16_T target;
extern int16_T throt;
extern int16_T throt_max;
extern int16_T throt_min;
extern int16_T vel_dec;
extern int16_T vel_inc;

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const int16_T target_max;
extern const int16_T target_min;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'cruise_control_sdo'
 * '<S1>'   : 'cruise_control_sdo/PI_Controller'
 * '<S2>'   : 'cruise_control_sdo/calcTarget'
 * '<S3>'   : 'cruise_control_sdo/isControlActivate'
 * '<S4>'   : 'cruise_control_sdo/isControlActivate/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_cruise_control_sdo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
