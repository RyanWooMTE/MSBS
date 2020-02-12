/*
 * File: LandingGearMode.h
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

#ifndef RTW_HEADER_LandingGearMode_h_
#define RTW_HEADER_LandingGearMode_h_
#include <string.h>
#ifndef LandingGearMode_COMMON_INCLUDES_
# define LandingGearMode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LandingGearMode_COMMON_INCLUDES_ */

#include "LandingGearMode_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_LandingGearMode;/* '<Root>/LandingGearModes' */
  uint8_T is_LeftLock;                 /* '<Root>/LandingGearModes' */
  uint8_T is_RightLock;                /* '<Root>/LandingGearModes' */
  uint8_T is_WarningModes;             /* '<Root>/LandingGearModes' */
} DW_LandingGearMode;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  MiscData misc;                       /* '<Root>/misc' */
} ExtU_LandingGearMode;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T LGMode;                       /* '<Root>/LGMode' */
} ExtY_LandingGearMode;

/* Block states (auto storage) */
extern DW_LandingGearMode LandingGearMode_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_LandingGearMode LandingGearMode_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_LandingGearMode LandingGearMode_Y;

/* External data declarations for dependent source files */
extern const MiscData LandingGearMode_rtZMiscData;/* MiscData ground */

/* Model entry point functions */
extern void LandingGearMode_initialize(void);
extern void LandingGearMode_step(void);

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
 * '<Root>' : 'LandingGearMode'
 * '<S1>'   : 'LandingGearMode/LandingGearModes'
 */

/*-
 * Requirements for '<Root>': LandingGearMode
 *  1. Landing Gear
 */
#endif                                 /* RTW_HEADER_LandingGearMode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
