/*
 * File: cruise_control_sdo.c
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

#include "cruise_control_sdo.h"
#include "cruise_control_sdo_private.h"

/* Exported data definition */

/* Definition for custom storage class: Default */
int16_T brake_pressure;
boolean_T dec;
int16_T diff_target;
int16_T driver_throt;
boolean_T enable;
boolean_T inc;
boolean_T is_ctrl;
boolean_T set;
int16_T speed;
int16_T target;
int16_T throt;
int16_T throt_max = 100;
int16_T throt_min = 0;
int16_T vel_dec = 1;
int16_T vel_inc = 1;

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T target_max = 100;
const int16_T target_min = 40;

/* Block signals and states (auto storage) */
D_Work_cruise_control_sdo cruise_control_sdo_DWork;

/* Model step function */
void cruise_control_sdo_step(void)
{
  int16_T tmp;

  /* Switch: '<S2>/Switch1' incorporates:
   *  Inport: '<Root>/dec'
   *  Inport: '<Root>/inc'
   *  Inport: '<Root>/set'
   *  Switch: '<S2>/Switch2'
   *  Switch: '<S2>/Switch3'
   */
  if (set) {
    /* Saturate: '<Root>/Saturation' incorporates:
     *  Inport: '<Root>/speed'
     */
    throt = speed;
  } else {
    if (inc) {
      /* Sum: '<S2>/Sum' incorporates:
       *  Constant: '<S2>/Constant1'
       *  Switch: '<S2>/Switch2'
       */
      if (vel_inc > 2047) {
        tmp = MAX_int16_T;
      } else if (vel_inc <= -2048) {
        tmp = MIN_int16_T;
      } else {
        tmp = (int16_T)(vel_inc << 4);
      }

      /* Switch: '<S2>/Switch2' incorporates:
       *  Sum: '<S2>/Sum'
       *  UnitDelay: '<S2>/Unit Delay'
       */
      target = (int16_T)(tmp + target);
    } else {
      if (dec) {
        /* Sum: '<S2>/Sum2' incorporates:
         *  Constant: '<S2>/Constant3'
         *  Switch: '<S2>/Switch2'
         *  Switch: '<S2>/Switch3'
         */
        if (vel_dec > 2047) {
          tmp = MAX_int16_T;
        } else if (vel_dec <= -2048) {
          tmp = MIN_int16_T;
        } else {
          tmp = (int16_T)(vel_dec << 4);
        }

        /* Switch: '<S2>/Switch3' incorporates:
         *  Sum: '<S2>/Sum2'
         *  Switch: '<S2>/Switch2'
         *  UnitDelay: '<S2>/Unit Delay'
         */
        target = (int16_T)(target - tmp);
      }
    }

    /* Saturate: '<Root>/Saturation' incorporates:
     *  Inport: '<Root>/dec'
     *  Switch: '<S2>/Switch2'
     *  Switch: '<S2>/Switch3'
     */
    throt = target;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Saturate: '<S2>/Saturation' */
  if (target_max > 2047) {
    tmp = MAX_int16_T;
  } else if (target_max <= -2048) {
    tmp = MIN_int16_T;
  } else {
    tmp = (int16_T)(target_max << 4);
  }

  if (throt >= tmp) {
    if (target_max > 2047) {
      target = MAX_int16_T;
    } else if (target_max <= -2048) {
      target = MIN_int16_T;
    } else {
      target = (int16_T)(target_max << 4);
    }
  } else {
    if (target_min > 2047) {
      tmp = MAX_int16_T;
    } else if (target_min <= -2048) {
      tmp = MIN_int16_T;
    } else {
      tmp = (int16_T)(target_min << 4);
    }

    if (throt <= tmp) {
      if (target_min > 2047) {
        target = MAX_int16_T;
      } else if (target_min <= -2048) {
        target = MIN_int16_T;
      } else {
        target = (int16_T)(target_min << 4);
      }
    } else {
      target = throt;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Sum: '<S2>/Sum1' incorporates:
   *  Inport: '<Root>/speed'
   */
  diff_target = (int16_T)(target - speed);

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/brake_pressure'
   *  Inport: '<Root>/enable'
   *  Inport: '<Root>/set'
   *  Inport: '<Root>/speed'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator1'
   *  RelationalOperator: '<S4>/Compare'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  is_ctrl = ((((enable) && (!(brake_pressure > 0))) && ((set) || (is_ctrl))) &&
             ((speed <= (target_max << 4)) && (speed >= (target_min << 4))));

  /* Outputs for Enabled SubSystem: '<Root>/PI_Controller' incorporates:
   *  EnablePort: '<S1>/is_ctrl'
   */
  if (is_ctrl) {
    if (!cruise_control_sdo_DWork.PI_Controller_MODE) {
      /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
      cruise_control_sdo_DWork.UnitDelay2_DSTATE = 0;
      cruise_control_sdo_DWork.PI_Controller_MODE = TRUE;
    }

    /* Sum: '<S1>/Sum1' incorporates:
     *  Gain: '<S1>/Kp'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    cruise_control_sdo_DWork.Sum1 = (int16_T)(((int16_T)((cruise_kp *
      diff_target) >> 8)) + cruise_control_sdo_DWork.UnitDelay2_DSTATE);

    /* Gain: '<S1>/Gain1' */
    if (cruise_ki > 1) {
      tmp = MAX_int16_T;
    } else if (cruise_ki <= -2) {
      tmp = MIN_int16_T;
    } else {
      tmp = (int16_T)(cruise_ki << 14);
    }

    /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Sum: '<S1>/Sum2'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    cruise_control_sdo_DWork.UnitDelay2_DSTATE += ((tmp * diff_target) >> 22);
  } else {
    if (cruise_control_sdo_DWork.PI_Controller_MODE) {
      cruise_control_sdo_DWork.PI_Controller_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/PI_Controller' */

  /* Switch: '<Root>/Switch' */
  if (is_ctrl) {
    /* Saturate: '<Root>/Saturation' */
    throt = cruise_control_sdo_DWork.Sum1;
  } else {
    /* Saturate: '<Root>/Saturation' incorporates:
     *  Inport: '<Root>/driver_throt'
     */
    throt = driver_throt;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Saturation' */
  if (throt_max > 2047) {
    tmp = MAX_int16_T;
  } else if (throt_max <= -2048) {
    tmp = MIN_int16_T;
  } else {
    tmp = (int16_T)(throt_max << 4);
  }

  if (throt >= tmp) {
    if (throt_max > 2047) {
      throt = MAX_int16_T;
    } else if (throt_max <= -2048) {
      throt = MIN_int16_T;
    } else {
      throt = (int16_T)(throt_max << 4);
    }
  } else {
    if (throt_min > 2047) {
      tmp = MAX_int16_T;
    } else if (throt_min <= -2048) {
      tmp = MIN_int16_T;
    } else {
      tmp = (int16_T)(throt_min << 4);
    }

    if (throt <= tmp) {
      if (throt_min > 2047) {
        throt = MAX_int16_T;
      } else if (throt_min <= -2048) {
        throt = MIN_int16_T;
      } else {
        throt = (int16_T)(throt_min << 4);
      }
    }
  }
}

/* Model initialize function */
void cruise_control_sdo_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
