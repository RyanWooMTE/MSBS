/*
 * File: DisplayModel_Step5_start.h
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

#ifndef RTW_HEADER_DisplayModel_Step5_start_h_
#define RTW_HEADER_DisplayModel_Step5_start_h_
#ifndef DisplayModel_Step5_start_COMMON_INCLUDES_
# define DisplayModel_Step5_start_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* DisplayModel_Step5_start_COMMON_INCLUDES_ */

#include "DisplayModel_Step5_start_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_LandingGearModeLib;/* '<Root>/LandingGear' */
  uint8_T is_LeftLock;                 /* '<Root>/LandingGear' */
  uint8_T is_active_LeftLock;          /* '<Root>/LandingGear' */
  uint8_T is_RightLock;                /* '<Root>/LandingGear' */
  uint8_T is_active_RightLock;         /* '<Root>/LandingGear' */
  uint8_T is_WarningModes;             /* '<Root>/LandingGear' */
  uint8_T is_active_WarningModes;      /* '<Root>/LandingGear' */
  uint8_T temporalCounter_i1;          /* '<Root>/LandingGear' */
} D_Work_DisplayModel_Step5_start;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  MiscData In1;                        /* '<Root>/In1' */
} ExternalInputs_DisplayModel_Ste;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_DisplayModel_St;

/* Real-time Model Data Structure */
struct tag_RTM_DisplayModel_Step5_star {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern D_Work_DisplayModel_Step5_start DisplayModel_Step5_start_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_DisplayModel_Ste DisplayModel_Step5_start_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_DisplayModel_St DisplayModel_Step5_start_Y;

/* External data declarations for dependent source files */
extern const MiscData DisplayModel_Step5_start_rtZMiscData;/* MiscData ground */

/* Model entry point functions */
extern void DisplayModel_Step5_start_initialize(void);
extern void DisplayModel_Step5_start_step(void);
extern void DisplayModel_Step5_start_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DisplayModel_Step5_sta *const DisplayModel_Step5_start_M;

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
 * '<Root>' : 'DisplayModel_Step5_start'
 * '<S1>'   : 'DisplayModel_Step5_start/LandingGear'
 */

/*-
 * Requirements for '<Root>': DisplayModel_Step5_start
 */
#endif                                 /* RTW_HEADER_DisplayModel_Step5_start_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
