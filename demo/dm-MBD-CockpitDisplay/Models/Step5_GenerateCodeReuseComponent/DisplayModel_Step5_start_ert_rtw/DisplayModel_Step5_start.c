/*
 * File: DisplayModel_Step5_start.c
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

#include "DisplayModel_Step5_start.h"
#include "DisplayModel_Step5_start_private.h"

/* Named constants for Chart: '<Root>/LandingGear' */
#define DisplayModel_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DisplayModel_S_IN_OnlyOneLocked ((uint8_T)4U)
#define DisplayModel_St_IN_BothUnLocked ((uint8_T)2U)
#define DisplayModel_Step5__IN_Unlocked ((uint8_T)2U)
#define DisplayModel_Step5_st_IN_Locked ((uint8_T)1U)
#define DisplayModel_Step5_sta_IN_ERROR ((uint8_T)3U)
#define DisplayModel_Step_IN_BothLocked ((uint8_T)1U)

const MiscData DisplayModel_Step5_start_rtZMiscData = {
  0.0,                                 /* FlapPosition */
  0.0,                                 /* CabinPressure */
  0.0,                                 /* HydraulicPressure */
  0.0,                                 /* APUData */
  FALSE,                               /* LGLeftLock */
  FALSE                                /* LGRightLock */
} ;                                    /* MiscData ground */

/* Block states (auto storage) */
D_Work_DisplayModel_Step5_start DisplayModel_Step5_start_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_DisplayModel_Ste DisplayModel_Step5_start_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_DisplayModel_St DisplayModel_Step5_start_Y;

/* Real-time model */
RT_MODEL_DisplayModel_Step5_sta DisplayModel_Step5_start_M_;
RT_MODEL_DisplayModel_Step5_sta *const DisplayModel_Step5_start_M =
  &DisplayModel_Step5_start_M_;

/* Model step function */
void DisplayModel_Step5_start_step(void)
{
  /* Chart: '<Root>/LandingGear' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_LandingGear_at_inport_0'
   *  Inport: '<Root>/In1'
   */
  if (DisplayModel_Step5_start_DWork.temporalCounter_i1 < 63U) {
    DisplayModel_Step5_start_DWork.temporalCounter_i1++;
  }

  /* Gateway: LandingGear */
  /* During: LandingGear */
  if (DisplayModel_Step5_start_DWork.is_active_c3_LandingGearModeLib == 0U) {
    /* Entry: LandingGear */
    DisplayModel_Step5_start_DWork.is_active_c3_LandingGearModeLib = 1U;

    /* Entry Internal: LandingGear */
    DisplayModel_Step5_start_DWork.is_active_LeftLock = 1U;

    /* Entry Internal 'LeftLock': '<S1>:2' */
    /* Transition: '<S1>:4' */
    if (DisplayModel_Step5_start_U.In1.LGLeftLock) {
      /* Transition: '<S1>:5' */
      DisplayModel_Step5_start_DWork.is_LeftLock =
        DisplayModel_Step5_st_IN_Locked;
    } else {
      /* Transition: '<S1>:6' */
      DisplayModel_Step5_start_DWork.is_LeftLock =
        DisplayModel_Step5__IN_Unlocked;
    }

    DisplayModel_Step5_start_DWork.is_active_RightLock = 1U;

    /* Entry Internal 'RightLock': '<S1>:11' */
    /* Transition: '<S1>:13' */
    if (DisplayModel_Step5_start_U.In1.LGRightLock) {
      /* Transition: '<S1>:15' */
      DisplayModel_Step5_start_DWork.is_RightLock =
        DisplayModel_Step5_st_IN_Locked;
    } else {
      /* Transition: '<S1>:14' */
      DisplayModel_Step5_start_DWork.is_RightLock =
        DisplayModel_Step5__IN_Unlocked;
    }

    DisplayModel_Step5_start_DWork.is_active_WarningModes = 1U;

    /* Entry Internal 'WarningModes': '<S1>:20' */
    /* Transition: '<S1>:22' */
    if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
         DisplayModel_Step5_st_IN_Locked) &&
        (DisplayModel_Step5_start_DWork.is_RightLock ==
         DisplayModel_Step5_st_IN_Locked)) {
      /* Transition: '<S1>:23' */
      DisplayModel_Step5_start_DWork.is_WarningModes =
        DisplayModel_Step_IN_BothLocked;

      /* Outport: '<Root>/Out1' */
      /* Entry 'BothLocked': '<S1>:34' */
      DisplayModel_Step5_start_Y.Out1 = 1.0;
    } else if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
                DisplayModel_Step5__IN_Unlocked) &&
               (DisplayModel_Step5_start_DWork.is_RightLock ==
                DisplayModel_Step5__IN_Unlocked)) {
      /* Transition: '<S1>:24' */
      DisplayModel_Step5_start_DWork.is_WarningModes =
        DisplayModel_St_IN_BothUnLocked;

      /* Outport: '<Root>/Out1' */
      /* Entry 'BothUnLocked': '<S1>:35' */
      DisplayModel_Step5_start_Y.Out1 = 3.0;
    } else {
      /* Transition: '<S1>:25' */
      DisplayModel_Step5_start_DWork.is_WarningModes =
        DisplayModel_S_IN_OnlyOneLocked;
      DisplayModel_Step5_start_DWork.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/Out1' */
      /* Entry 'OnlyOneLocked': '<S1>:36' */
      DisplayModel_Step5_start_Y.Out1 = 2.0;
    }
  } else {
    /* During 'LeftLock': '<S1>:2' */
    if (DisplayModel_Step5_start_DWork.is_LeftLock ==
        DisplayModel_Step5_st_IN_Locked) {
      /* During 'Locked': '<S1>:9' */
      if (!DisplayModel_Step5_start_U.In1.LGLeftLock) {
        /* Transition: '<S1>:7' */
        DisplayModel_Step5_start_DWork.is_LeftLock =
          DisplayModel_Step5__IN_Unlocked;
      }
    } else {
      /* During 'Unlocked': '<S1>:10' */
      if (DisplayModel_Step5_start_U.In1.LGLeftLock) {
        /* Transition: '<S1>:8' */
        DisplayModel_Step5_start_DWork.is_LeftLock =
          DisplayModel_Step5_st_IN_Locked;
      }
    }

    /* During 'RightLock': '<S1>:11' */
    if (DisplayModel_Step5_start_DWork.is_RightLock ==
        DisplayModel_Step5_st_IN_Locked) {
      /* During 'Locked': '<S1>:19' */
      if (!DisplayModel_Step5_start_U.In1.LGRightLock) {
        /* Transition: '<S1>:16' */
        DisplayModel_Step5_start_DWork.is_RightLock =
          DisplayModel_Step5__IN_Unlocked;
      }
    } else {
      /* During 'Unlocked': '<S1>:18' */
      if (DisplayModel_Step5_start_U.In1.LGRightLock) {
        /* Transition: '<S1>:17' */
        DisplayModel_Step5_start_DWork.is_RightLock =
          DisplayModel_Step5_st_IN_Locked;
      }
    }

    /* During 'WarningModes': '<S1>:20' */
    switch (DisplayModel_Step5_start_DWork.is_WarningModes) {
     case DisplayModel_Step_IN_BothLocked:
      /* During 'BothLocked': '<S1>:34' */
      if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
           DisplayModel_Step5__IN_Unlocked) &&
          (DisplayModel_Step5_start_DWork.is_RightLock ==
           DisplayModel_Step5__IN_Unlocked)) {
        /* Transition: '<S1>:32' */
        DisplayModel_Step5_start_DWork.is_WarningModes =
          DisplayModel_St_IN_BothUnLocked;

        /* Outport: '<Root>/Out1' */
        /* Entry 'BothUnLocked': '<S1>:35' */
        DisplayModel_Step5_start_Y.Out1 = 3.0;
      } else {
        if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
             DisplayModel_Step5__IN_Unlocked) ||
            (DisplayModel_Step5_start_DWork.is_RightLock ==
             DisplayModel_Step5__IN_Unlocked)) {
          /* Transition: '<S1>:29' */
          DisplayModel_Step5_start_DWork.is_WarningModes =
            DisplayModel_S_IN_OnlyOneLocked;
          DisplayModel_Step5_start_DWork.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/Out1' */
          /* Entry 'OnlyOneLocked': '<S1>:36' */
          DisplayModel_Step5_start_Y.Out1 = 2.0;
        }
      }
      break;

     case DisplayModel_St_IN_BothUnLocked:
      /* During 'BothUnLocked': '<S1>:35' */
      if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
           DisplayModel_Step5_st_IN_Locked) &&
          (DisplayModel_Step5_start_DWork.is_RightLock ==
           DisplayModel_Step5_st_IN_Locked)) {
        /* Transition: '<S1>:33' */
        DisplayModel_Step5_start_DWork.is_WarningModes =
          DisplayModel_Step_IN_BothLocked;

        /* Outport: '<Root>/Out1' */
        /* Entry 'BothLocked': '<S1>:34' */
        DisplayModel_Step5_start_Y.Out1 = 1.0;
      } else {
        if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
             DisplayModel_Step5_st_IN_Locked) ||
            (DisplayModel_Step5_start_DWork.is_RightLock ==
             DisplayModel_Step5_st_IN_Locked)) {
          /* Transition: '<S1>:26' */
          DisplayModel_Step5_start_DWork.is_WarningModes =
            DisplayModel_S_IN_OnlyOneLocked;
          DisplayModel_Step5_start_DWork.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/Out1' */
          /* Entry 'OnlyOneLocked': '<S1>:36' */
          DisplayModel_Step5_start_Y.Out1 = 2.0;
        }
      }
      break;

     case DisplayModel_Step5_sta_IN_ERROR:
      /* During 'ERROR': '<S1>:37' */
      if (((DisplayModel_Step5_start_DWork.is_LeftLock ==
            DisplayModel_Step5_st_IN_Locked) &&
           (DisplayModel_Step5_start_DWork.is_RightLock ==
            DisplayModel_Step5_st_IN_Locked)) ||
          ((DisplayModel_Step5_start_DWork.is_LeftLock ==
            DisplayModel_Step5__IN_Unlocked) &&
           (DisplayModel_Step5_start_DWork.is_RightLock ==
            DisplayModel_Step5__IN_Unlocked))) {
        /* Transition: '<S1>:31' */
        DisplayModel_Step5_start_DWork.is_WarningModes =
          DisplayModel_S_IN_OnlyOneLocked;
        DisplayModel_Step5_start_DWork.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        /* Entry 'OnlyOneLocked': '<S1>:36' */
        DisplayModel_Step5_start_Y.Out1 = 2.0;
      }
      break;

     default:
      /* During 'OnlyOneLocked': '<S1>:36' */
      if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
           DisplayModel_Step5__IN_Unlocked) &&
          (DisplayModel_Step5_start_DWork.is_RightLock ==
           DisplayModel_Step5__IN_Unlocked)) {
        /* Transition: '<S1>:28' */
        DisplayModel_Step5_start_DWork.is_WarningModes =
          DisplayModel_St_IN_BothUnLocked;

        /* Outport: '<Root>/Out1' */
        /* Entry 'BothUnLocked': '<S1>:35' */
        DisplayModel_Step5_start_Y.Out1 = 3.0;
      } else if (DisplayModel_Step5_start_DWork.temporalCounter_i1 >= 50U) {
        /* Transition: '<S1>:30' */
        DisplayModel_Step5_start_DWork.is_WarningModes =
          DisplayModel_Step5_sta_IN_ERROR;

        /* Outport: '<Root>/Out1' */
        /* Entry 'ERROR': '<S1>:37' */
        DisplayModel_Step5_start_Y.Out1 = 4.0;
      } else {
        if ((DisplayModel_Step5_start_DWork.is_LeftLock ==
             DisplayModel_Step5_st_IN_Locked) &&
            (DisplayModel_Step5_start_DWork.is_RightLock ==
             DisplayModel_Step5_st_IN_Locked)) {
          /* Transition: '<S1>:27' */
          DisplayModel_Step5_start_DWork.is_WarningModes =
            DisplayModel_Step_IN_BothLocked;

          /* Outport: '<Root>/Out1' */
          /* Entry 'BothLocked': '<S1>:34' */
          DisplayModel_Step5_start_Y.Out1 = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/LandingGear' */
}

/* Model initialize function */
void DisplayModel_Step5_start_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DisplayModel_Step5_start_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&DisplayModel_Step5_start_DWork, 0,
                sizeof(D_Work_DisplayModel_Step5_start));

  /* external inputs */
  DisplayModel_Step5_start_U.In1 = DisplayModel_Step5_start_rtZMiscData;

  /* external outputs */
  DisplayModel_Step5_start_Y.Out1 = 0.0;

  /* InitializeConditions for Chart: '<Root>/LandingGear' */
  DisplayModel_Step5_start_DWork.is_active_LeftLock = 0U;
  DisplayModel_Step5_start_DWork.is_LeftLock = DisplayModel_IN_NO_ACTIVE_CHILD;
  DisplayModel_Step5_start_DWork.is_active_RightLock = 0U;
  DisplayModel_Step5_start_DWork.is_RightLock = DisplayModel_IN_NO_ACTIVE_CHILD;
  DisplayModel_Step5_start_DWork.is_active_WarningModes = 0U;
  DisplayModel_Step5_start_DWork.is_WarningModes =
    DisplayModel_IN_NO_ACTIVE_CHILD;
  DisplayModel_Step5_start_DWork.temporalCounter_i1 = 0U;
  DisplayModel_Step5_start_DWork.is_active_c3_LandingGearModeLib = 0U;
}

/* Model terminate function */
void DisplayModel_Step5_start_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
