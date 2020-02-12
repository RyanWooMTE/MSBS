/*
 * cruise_control_sdo_sf.c
 *
 * This file contains a "wrapper style S-Function" for testing the generated
 * code from Simulink.  Simulink invokes the generated code through its
 * S-Function API.  Note that this file is not required for deployment
 * of the generated code outside of Simulink.
 *
 * Code generation for model "cruise_control_sdo".
 *
 * Model version              : 1.304
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Wed Jan 30 05:09:50 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NEC->V850
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 *
 */

#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME                cruise_control_sdo_sf
#endif

#define S_FUNCTION_LEVEL               2

/* So mdlEnable and mdlDisable will be defined in the simstruc.h */
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif

#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#define RTWSfcnInfo                    void *
#include "cruise_control_sdo.h"

static int8_T cruise_control_sdo_sf_counter = 0;
static void cruise_control_sdo_ertSfcnZeroMemory(void)
{
  /* block I/O */

  /* custom signals */
  target = 0;
  diff_target = 0;
  throt = 0;
  is_ctrl = FALSE;

  /* states (dwork) */
  (void) memset((void *)&cruise_control_sdo_DWork, 0,
                sizeof(D_Work_cruise_control_sdo));

  /* external inputs */
  enable = FALSE;
  brake_pressure = 0;
  set = FALSE;
  inc = FALSE;
  dec = FALSE;
  driver_throt = 0;
  speed = 0;
}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Check attributes of parameter 'throt_max' */
  {
    int dimsArray[2] = { 1, 1 };

    ssCheckSFcnParamValueAttribs(S, 0, "throt_max", DYNAMICALLY_TYPED,
      2, dimsArray, FALSE);
  }

  /* Check attributes of parameter 'throt_min' */
  {
    int dimsArray[2] = { 1, 1 };

    ssCheckSFcnParamValueAttribs(S, 1, "throt_min", DYNAMICALLY_TYPED,
      2, dimsArray, FALSE);
  }

  /* Check attributes of parameter 'vel_dec' */
  {
    int dimsArray[2] = { 1, 1 };

    ssCheckSFcnParamValueAttribs(S, 2, "vel_dec", DYNAMICALLY_TYPED,
      2, dimsArray, FALSE);
  }

  /* Check attributes of parameter 'vel_inc' */
  {
    int dimsArray[2] = { 1, 1 };

    ssCheckSFcnParamValueAttribs(S, 3, "vel_inc", DYNAMICALLY_TYPED,
      2, dimsArray, FALSE);
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

/* Copy parameter values from run-time parameters to global variables. */
static void updateGlobalVarsFromRunTimeParams(SimStruct *S)
{
  int_T i;

  /* Update parameter 'throt_max' */
  throt_max = (((int16_T *) ssGetRunTimeParamInfo(S,0)->data)[0]);

  /* Update parameter 'throt_min' */
  throt_min = (((int16_T *) ssGetRunTimeParamInfo(S,1)->data)[0]);

  /* Update parameter 'vel_dec' */
  vel_dec = (((int16_T *) ssGetRunTimeParamInfo(S,2)->data)[0]);

  /* Update parameter 'vel_inc' */
  vel_inc = (((int16_T *) ssGetRunTimeParamInfo(S,3)->data)[0]);
}

/* This function updates tunable parameter values during simulation. */
#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlProcessParameters(SimStruct *S)
{
  ssUpdateAllTunableParamsAsRunTimeParams(S);
  updateGlobalVarsFromRunTimeParams(S);
}

#endif                                 /* MDL_PROCESS_PARAMETERS */

/*
 * This function registers the input and output signal properties of the
 * generated ERT code.
 */
static void mdlInitializeSizes(SimStruct *S)
{
  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 4);
  ssFxpSetU32BitRegionCompliant(S, 1);

  /* Number of expected parameters */
  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL)) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

  ssSetNumContStates(S, 0);
  ssSetNumDiscStates(S, 0);
  ssSetRTWGeneratedSFcn(S, 3);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 7))
    return;
  if (!ssSetInputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetInputPortDataType(S, 0, SS_BOOLEAN);
  }

  ssSetBusInputAsStruct(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortSampleTime(S, 0, 0.01);
  ssSetInputPortOffsetTime(S, 0, 0.0);
  if (!ssSetInputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg =
        ssRegisterDataTypeFxpFSlopeFixExpBias(
        S,
        1,
        16,
        1.0,
        -4,
        0.0,
        0                              /* false means do NOT obey data type override setting for this subsystem */
        );
      ssSetInputPortDataType(S, 1, dataTypeIdReg );
    }

#endif

  }

  ssSetBusInputAsStruct(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortSampleTime(S, 1, 0.01);
  ssSetInputPortOffsetTime(S, 1, 0.0);
  if (!ssSetInputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetInputPortDataType(S, 2, SS_BOOLEAN);
  }

  ssSetBusInputAsStruct(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortSampleTime(S, 2, 0.01);
  ssSetInputPortOffsetTime(S, 2, 0.0);
  if (!ssSetInputPortVectorDimension(S, 3, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetInputPortDataType(S, 3, SS_BOOLEAN);
  }

  ssSetBusInputAsStruct(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortSampleTime(S, 3, 0.01);
  ssSetInputPortOffsetTime(S, 3, 0.0);
  if (!ssSetInputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetInputPortDataType(S, 4, SS_BOOLEAN);
  }

  ssSetBusInputAsStruct(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortSampleTime(S, 4, 0.01);
  ssSetInputPortOffsetTime(S, 4, 0.0);
  if (!ssSetInputPortVectorDimension(S, 5, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg =
        ssRegisterDataTypeFxpFSlopeFixExpBias(
        S,
        1,
        16,
        1.0,
        -4,
        0.0,
        0                              /* false means do NOT obey data type override setting for this subsystem */
        );
      ssSetInputPortDataType(S, 5, dataTypeIdReg );
    }

#endif

  }

  ssSetBusInputAsStruct(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortSampleTime(S, 5, 0.01);
  ssSetInputPortOffsetTime(S, 5, 0.0);
  if (!ssSetInputPortVectorDimension(S, 6, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg =
        ssRegisterDataTypeFxpFSlopeFixExpBias(
        S,
        1,
        16,
        1.0,
        -4,
        0.0,
        0                              /* false means do NOT obey data type override setting for this subsystem */
        );
      ssSetInputPortDataType(S, 6, dataTypeIdReg );
    }

#endif

  }

  ssSetBusInputAsStruct(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortSampleTime(S, 6, 0.01);
  ssSetInputPortOffsetTime(S, 6, 0.0);

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 2))
    return;
  if (!ssSetOutputPortMatrixDimensions(S, 0, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg =
        ssRegisterDataTypeFxpFSlopeFixExpBias(
        S,
        1,
        16,
        1.0,
        -4,
        0.0,
        0                              /* false means do NOT obey data type override setting for this subsystem */
        );
      ssSetOutputPortDataType(S, 0, dataTypeIdReg );
    }

#endif

  }

  ssSetOutputPortSampleTime(S, 0, 0.01);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  if (!ssSetOutputPortMatrixDimensions(S, 1, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg =
        ssRegisterDataTypeFxpFSlopeFixExpBias(
        S,
        1,
        16,
        1.0,
        -4,
        0.0,
        0                              /* false means do NOT obey data type override setting for this subsystem */
        );
      ssSetOutputPortDataType(S, 1, dataTypeIdReg );
    }

#endif

  }

  ssSetOutputPortSampleTime(S, 1, 0.01);
  ssSetOutputPortOffsetTime(S, 1, 0.0);

  /* Number of sample-times */
  ssSetNumSampleTimes(S, 1);
  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumPWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);

  /* ERT S-Function works with model reference normal mode */
  ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);
}

/* This function registers the sample times of the generated ERT code. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, 0.01);
  ssSetOffsetTime(S, 0, 0.0);
}

/* This function registers run-time parameters for tunable parameters. */
#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)

static void mdlSetWorkWidths(SimStruct *S)
{
  /* Set number of run-time parameters */
  if (!ssSetNumRunTimeParams(S, 4))
    return;

  {
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "P0_throt_max", SS_INT16);
    if (ssGetErrorStatus(S) != (NULL)) {
      return;
    }
  }

  {
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "P1_throt_min", SS_INT16);
    if (ssGetErrorStatus(S) != (NULL)) {
      return;
    }
  }

  {
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "P2_vel_dec", SS_INT16);
    if (ssGetErrorStatus(S) != (NULL)) {
      return;
    }
  }

  {
    ssRegDlgParamAsRunTimeParam(S, 3, 3, "P3_vel_inc", SS_INT16);
    if (ssGetErrorStatus(S) != (NULL)) {
      return;
    }
  }

  updateGlobalVarsFromRunTimeParams(S);
}

#endif                                 /* MDL_SET_WORK_WIDTHS */

static boolean_T enable_first_entry;

/*
 *   This function does sfunction consistent check, initializes internal memory if neccessary, and
 *   calls the initialization function of the generated ERT code.
 */
#define MDL_START                                                /* Change to #undef to remove function */
#if defined(MDL_START)

static void mdlStart(SimStruct *S)
{
  int16_T *OutPort_0 = (int16_T *)ssGetOutputPortSignal(S, 0);
  int16_T *OutPort_1 = (int16_T *)ssGetOutputPortSignal(S, 1);

  /* check if more than one instance of this S-Function has been used */
  if (++cruise_control_sdo_sf_counter > 1) {
    ssSetErrorStatus(S,"This S-Function is limited to one copy per model.");
    cruise_control_sdo_sf_counter = 0;
    return;
  }

  /* check if parent model's start time is the same as that used to generate code */
  if (ssGetTStart(S) != 0.0) {
    ssSetErrorStatus(S,
                     "The parent model of this S-Function must set the value of the 'Start time' on the Solver page of its Configuration Parameters Dialog to 0.0 since that was the value used when generating code for the S-Function's original model.");
    return;
  }

  enable_first_entry = TRUE;

#ifdef PIL_S_FUNCTION

  pilMarshallInitSFcnSimStruct(S);
  pilMarshallInitRootSimStruct(ssGetRootSS(S));

#endif

  cruise_control_sdo_ertSfcnZeroMemory();
  cruise_control_sdo_initialize();
  OutPort_0[0] = throt;
  OutPort_1[0] = target;
}

#endif                                 /*  MDL_START */

#define MDL_INITIALIZE_CONDITIONS

/*   Nothing runs in this function */
static void mdlInitializeConditions(SimStruct *S)
{
}

/*
 * This function calls the step function of the generated ERT code
 * and provides an interface with the simulation data.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  InputBooleanPtrsType InPort_0 = (InputBooleanPtrsType)
    ssGetInputPortSignalPtrs(S, 0);
  InputInt16PtrsType InPort_1 = (InputInt16PtrsType) ssGetInputPortSignalPtrs(S,
    1);
  InputBooleanPtrsType InPort_2 = (InputBooleanPtrsType)
    ssGetInputPortSignalPtrs(S, 2);
  InputBooleanPtrsType InPort_3 = (InputBooleanPtrsType)
    ssGetInputPortSignalPtrs(S, 3);
  InputBooleanPtrsType InPort_4 = (InputBooleanPtrsType)
    ssGetInputPortSignalPtrs(S, 4);
  InputInt16PtrsType InPort_5 = (InputInt16PtrsType) ssGetInputPortSignalPtrs(S,
    5);
  InputInt16PtrsType InPort_6 = (InputInt16PtrsType) ssGetInputPortSignalPtrs(S,
    6);
  int16_T *OutPort_0 = (int16_T *)ssGetOutputPortSignal(S, 0);
  int16_T *OutPort_1 = (int16_T *)ssGetOutputPortSignal(S, 1);
  enable = InPort_0[0][0];
  brake_pressure = InPort_1[0][0];
  set = InPort_2[0][0];
  inc = InPort_3[0][0];
  dec = InPort_4[0][0];
  driver_throt = InPort_5[0][0];
  speed = InPort_6[0][0];
  cruise_control_sdo_step();
  OutPort_0[0] = throt;
  OutPort_1[0] = target;
}

/* This function calls the termination function of the generated ERT code. */
static void mdlTerminate(SimStruct *S)
{
  cruise_control_sdo_sf_counter = 0;
}

#define MDL_ENABLE

static void mdlEnable(SimStruct *S)
{
  if (!enable_first_entry) {
    static char msg[256];
    if (strlen(ssGetPath(S)) < 128) {
      sprintf(msg,
              "The model is attempting to invoke the enable method of the S-Function block %s for model 'cruise_control_sdo', yet the code generated for the model does not include the enable method\n",
              ssGetPath(S));
    } else {
      sprintf(msg,
              "The model is attempting to invoke the enable method of the S-Function block for model 'cruise_control_sdo', yet the code generated for the model does not include the enable method\n");
    }

    ssSetErrorStatus(S, msg);
  }

  enable_first_entry = FALSE;
}

#define MDL_DISABLE

static void mdlDisable(SimStruct *S)
{
  static char msg[256];
  if (strlen(ssGetPath(S)) < 128) {
    sprintf(msg,
            "The model is attempting to invoke the disable mothod of the S-Function block %s for model 'cruise_control_sdo', yet the code generated for the model does not include the disable method\n",
            ssGetPath(S));
  } else {
    sprintf(msg,
            "The model is attempting to invoke the disable mothod of the S-Function block for model 'cruise_control_sdo', yet the code generated for the model does not include the disable method\n");
  }

  ssSetErrorStatus(S, msg);
}

#ifdef MATLAB_MEX_FILE                 /* Is this file being compiled as a MEX-file? */
#include "simulink.c"                  /* MEX-file interface mechanism */
#include "fixedpoint.c"
#else
#include "cg_sfun.h"                   /* Code generation registration function */
#endif
