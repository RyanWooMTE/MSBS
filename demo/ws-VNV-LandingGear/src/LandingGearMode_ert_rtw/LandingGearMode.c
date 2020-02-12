/*
 * File: LandingGearMode.c
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

#include "LandingGearMode.h"
#include "LandingGearMode_private.h"

/* Named constants for Chart: '<Root>/LandingGearModes' */
#define LandingGearM_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define LandingGearMod_IN_OnlyOneLocked ((uint8_T)3U)
#define LandingGearMode_IN_BothLocked  ((uint8_T)1U)
#define LandingGearMode_IN_BothUnLocked ((uint8_T)2U)
#define LandingGearMode_IN_Locked      ((uint8_T)1U)
#define LandingGearMode_IN_Unlocked    ((uint8_T)2U)

const MiscData LandingGearMode_rtZMiscData = {
  0.0,                                 /* FlapPosition */
  0.0,                                 /* CabinPressure */
  0.0,                                 /* HydraulicPressure */
  0.0,                                 /* APUData */
  false,                               /* LGLeftLock */
  false                                /* LGRightLock */
} ;                                    /* MiscData ground */

/* Block states (auto storage) */
DW_LandingGearMode LandingGearMode_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_LandingGearMode LandingGearMode_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_LandingGearMode LandingGearMode_Y;

/* Model step function */
void LandingGearMode_step(void)
{
  /* Chart: '<Root>/LandingGearModes' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_LandingGearModes_at_inport_0'
   *  Inport: '<Root>/misc'
   *
   * Block requirements for '<Root>/misc':
   *  1. The state of the landing gear will be contained in a bus object: MiscData. This bus object is defined as follows:
   */
  /* Gateway: LandingGearModes */
  /* During: LandingGearModes */
  if (((uint32_T)LandingGearMode_DW.is_active_c3_LandingGearMode) == ((uint32_T)
       0U)) {
    /* Entry: LandingGearModes */
    LandingGearMode_DW.is_active_c3_LandingGearMode = 1U;

    /* Entry Internal: LandingGearModes */
    /* Entry Internal 'LeftLock': '<S1>:111' */
    /* Transition: '<S1>:125' */
    if ((int32_T)((boolean_T)LandingGearMode_U.misc.LGLeftLock)) {
      /* Transition: '<S1>:120' */
      LandingGearMode_DW.is_LeftLock = LandingGearMode_IN_Locked;
    } else {
      /* Transition: '<S1>:118' */
      LandingGearMode_DW.is_LeftLock = LandingGearMode_IN_Unlocked;
    }

    /* Entry Internal 'RightLock': '<S1>:138' */
    /* Transition: '<S1>:133' */
    if ((int32_T)((boolean_T)LandingGearMode_U.misc.LGRightLock)) {
      /* Transition: '<S1>:131' */
      LandingGearMode_DW.is_RightLock = LandingGearMode_IN_Locked;
    } else {
      /* Transition: '<S1>:132' */
      LandingGearMode_DW.is_RightLock = LandingGearMode_IN_Unlocked;
    }

    /* Entry Internal 'WarningModes': '<S1>:90' */
    /* Transition: '<S1>:107' */
    if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Locked) &&
        (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Locked)) {
      /* Transition: '<S1>:94' */
      LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothLocked;

      /* Outport: '<Root>/LGMode'
       *
       * Block requirements for '<Root>/LGMode':
       *  1. The output of the system shall be an integer of type double, LandingGearMode.
       */
      /* Entry 'BothLocked': '<S1>:96' */
      LandingGearMode_Y.LGMode = 1.0;
    } else if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Unlocked) &&
               (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Unlocked))
    {
      /* Transition: '<S1>:100' */
      LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothUnLocked;

      /* Outport: '<Root>/LGMode'
       *
       * Block requirements for '<Root>/LGMode':
       *  1. The output of the system shall be an integer of type double, LandingGearMode.
       */
      /* Entry 'BothUnLocked': '<S1>:104' */
      LandingGearMode_Y.LGMode = 3.0;
    } else {
      /* Transition: '<S1>:105' */
      LandingGearMode_DW.is_WarningModes = LandingGearMod_IN_OnlyOneLocked;

      /* Outport: '<Root>/LGMode'
       *
       * Block requirements for '<Root>/LGMode':
       *  1. The output of the system shall be an integer of type double, LandingGearMode.
       */
      /* Entry 'OnlyOneLocked': '<S1>:98' */
      LandingGearMode_Y.LGMode = 2.0;
    }
  } else {
    /* During 'LeftLock': '<S1>:111' */
    if (LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Locked) {
      /* During 'Locked': '<S1>:112' */
      if (!LandingGearMode_U.misc.LGLeftLock) {
        /* Transition: '<S1>:117' */
        LandingGearMode_DW.is_LeftLock = LandingGearMode_IN_Unlocked;
      }
    } else {
      /* During 'Unlocked': '<S1>:110' */
      if ((int32_T)((boolean_T)LandingGearMode_U.misc.LGLeftLock)) {
        /* Transition: '<S1>:128' */
        LandingGearMode_DW.is_LeftLock = LandingGearMode_IN_Locked;
      }
    }

    /* During 'RightLock': '<S1>:138' */
    if (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Locked) {
      /* During 'Locked': '<S1>:130' */
      if (!LandingGearMode_U.misc.LGRightLock) {
        /* Transition: '<S1>:134' */
        LandingGearMode_DW.is_RightLock = LandingGearMode_IN_Unlocked;
      }
    } else {
      /* During 'Unlocked': '<S1>:135' */
      if ((int32_T)((boolean_T)LandingGearMode_U.misc.LGRightLock)) {
        /* Transition: '<S1>:137' */
        LandingGearMode_DW.is_RightLock = LandingGearMode_IN_Locked;
      }
    }

    /* During 'WarningModes': '<S1>:90' */
    switch (LandingGearMode_DW.is_WarningModes) {
     case LandingGearMode_IN_BothLocked:
      /* During 'BothLocked': '<S1>:96' */
      if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Unlocked) &&
          (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Unlocked)) {
        /* Transition: '<S1>:93' */
        LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothUnLocked;

        /* Outport: '<Root>/LGMode'
         *
         * Block requirements for '<Root>/LGMode':
         *  1. The output of the system shall be an integer of type double, LandingGearMode.
         */
        /* Entry 'BothUnLocked': '<S1>:104' */
        LandingGearMode_Y.LGMode = 3.0;
      } else {
        if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Unlocked) ||
            (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Unlocked)) {
          /* Transition: '<S1>:103' */
          LandingGearMode_DW.is_WarningModes = LandingGearMod_IN_OnlyOneLocked;

          /* Outport: '<Root>/LGMode'
           *
           * Block requirements for '<Root>/LGMode':
           *  1. The output of the system shall be an integer of type double, LandingGearMode.
           */
          /* Entry 'OnlyOneLocked': '<S1>:98' */
          LandingGearMode_Y.LGMode = 2.0;
        }
      }
      break;

     case LandingGearMode_IN_BothUnLocked:
      /* During 'BothUnLocked': '<S1>:104' */
      if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Locked) &&
          (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Locked)) {
        /* Transition: '<S1>:91' */
        LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothLocked;

        /* Outport: '<Root>/LGMode'
         *
         * Block requirements for '<Root>/LGMode':
         *  1. The output of the system shall be an integer of type double, LandingGearMode.
         */
        /* Entry 'BothLocked': '<S1>:96' */
        LandingGearMode_Y.LGMode = 1.0;
      } else {
        if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Locked) ||
            (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Locked)) {
          /* Transition: '<S1>:106' */
          LandingGearMode_DW.is_WarningModes = LandingGearMod_IN_OnlyOneLocked;

          /* Outport: '<Root>/LGMode'
           *
           * Block requirements for '<Root>/LGMode':
           *  1. The output of the system shall be an integer of type double, LandingGearMode.
           */
          /* Entry 'OnlyOneLocked': '<S1>:98' */
          LandingGearMode_Y.LGMode = 2.0;
        }
      }
      break;

     default:
      /* During 'OnlyOneLocked': '<S1>:98' */
      if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Unlocked) &&
          (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Unlocked)) {
        /* Transition: '<S1>:101' */
        LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothUnLocked;

        /* Outport: '<Root>/LGMode'
         *
         * Block requirements for '<Root>/LGMode':
         *  1. The output of the system shall be an integer of type double, LandingGearMode.
         */
        /* Entry 'BothUnLocked': '<S1>:104' */
        LandingGearMode_Y.LGMode = 3.0;
      } else {
        if ((LandingGearMode_DW.is_LeftLock == LandingGearMode_IN_Locked) &&
            (LandingGearMode_DW.is_RightLock == LandingGearMode_IN_Locked)) {
          /* Transition: '<S1>:97' */
          LandingGearMode_DW.is_WarningModes = LandingGearMode_IN_BothLocked;

          /* Outport: '<Root>/LGMode'
           *
           * Block requirements for '<Root>/LGMode':
           *  1. The output of the system shall be an integer of type double, LandingGearMode.
           */
          /* Entry 'BothLocked': '<S1>:96' */
          LandingGearMode_Y.LGMode = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/LandingGearModes' */
}

/* Model initialize function */
void LandingGearMode_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&LandingGearMode_DW, 0,
                sizeof(DW_LandingGearMode));

  /* external inputs */
  LandingGearMode_U.misc = LandingGearMode_rtZMiscData;

  /* external outputs */
  LandingGearMode_Y.LGMode = 0.0;

  /* InitializeConditions for Chart: '<Root>/LandingGearModes' */
  LandingGearMode_DW.is_LeftLock = LandingGearM_IN_NO_ACTIVE_CHILD;
  LandingGearMode_DW.is_RightLock = LandingGearM_IN_NO_ACTIVE_CHILD;
  LandingGearMode_DW.is_WarningModes = LandingGearM_IN_NO_ACTIVE_CHILD;
  LandingGearMode_DW.is_active_c3_LandingGearMode = 0U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
