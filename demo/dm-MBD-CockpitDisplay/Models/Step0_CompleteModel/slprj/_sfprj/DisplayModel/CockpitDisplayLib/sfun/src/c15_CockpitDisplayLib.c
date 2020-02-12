/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c15_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c15_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c15_IN_EngineOilLowPressure    ((uint8_T)1U)
#define c15_IN_Normal                  ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c15_debug_family_names[2] = { "nargin", "nargout" };

static const char * c15_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c15_c_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c15_d_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c15_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c15_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c15_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c15_update_debugger_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c15_st);
static void c15_set_sim_state_side_effects_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c15_enter_atomic_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void c15_enter_internal_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void c15_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c15_exit_internal_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void c15_initc15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_nargout, const char_T *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static boolean_T c15_c_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static uint8_T c15_e_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_b_tp_Normal, const char_T *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c15_pData);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_g_emlrt_marshallIn
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c15_b_setSimStateSideEffectsInfo, const char_T *c15_identifier);
static const mxArray *c15_h_emlrt_marshallIn
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c15_u,
   const emlrtMsgIdentifier *c15_parentId);
static void c15_updateDataWrittenToVector(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c15_vectorIndex);
static real_T c15_get_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b);
static void c15_set_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c);
static real_T *c15_access_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b);
static void init_dsm_address_info(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c15_update_debugger_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c15_prevAniVal;
  c15_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c15_is_active_c15_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c15_sfEvent);
  }

  if (chartInstance->c15_is_c15_CockpitDisplayLib == c15_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
  }

  if (chartInstance->c15_is_c15_CockpitDisplayLib == c15_IN_EngineOilLowPressure)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
  }

  _SFD_SET_ANIMATION(c15_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_u;
  const mxArray *c15_b_y = NULL;
  uint8_T c15_b_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  uint8_T c15_c_hoistedGlobal;
  uint8_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  real_T *c15_OilPProblem;
  c15_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(3), FALSE);
  c15_hoistedGlobal = *c15_OilPProblem;
  c15_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = chartInstance->c15_is_active_c15_CockpitDisplayLib;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_c_hoistedGlobal = chartInstance->c15_is_c15_CockpitDisplayLib;
  c15_c_u = c15_c_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T *c15_OilPProblem;
  c15_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_u = sf_mex_dup(c15_st);
  *c15_OilPProblem = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 0)), "OilPProblem");
  chartInstance->c15_is_active_c15_CockpitDisplayLib = c15_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
     "is_active_c15_CockpitDisplayLib");
  chartInstance->c15_is_c15_CockpitDisplayLib = c15_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
     "is_c15_CockpitDisplayLib");
  sf_mex_assign(&chartInstance->c15_setSimStateSideEffectsInfo,
                c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c15_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c15_u);
  chartInstance->c15_doSetSimStateSideEffects = 1U;
  c15_update_debugger_state_c15_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void c15_set_sim_state_side_effects_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c15_doSetSimStateSideEffects != 0) {
    if (chartInstance->c15_is_c15_CockpitDisplayLib ==
        c15_IN_EngineOilLowPressure) {
      chartInstance->c15_tp_EngineOilLowPressure = 1U;
    } else {
      chartInstance->c15_tp_EngineOilLowPressure = 0U;
    }

    if (chartInstance->c15_is_c15_CockpitDisplayLib == c15_IN_Normal) {
      chartInstance->c15_tp_Normal = 1U;
    } else {
      chartInstance->c15_tp_Normal = 0U;
    }

    chartInstance->c15_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c15_setSimStateSideEffectsInfo);
}

static void sf_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c15_set_sim_state_side_effects_c15_CockpitDisplayLib(chartInstance);
}

static void c15_enter_atomic_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
  chartInstance->c15_is_active_c15_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
}

static void c15_enter_internal_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c15_debug_family_var_map[2];
  real_T c15_nargin = 0.0;
  real_T c15_nargout = 0.0;
  real_T *c15_OilPProblem;
  c15_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
  chartInstance->c15_isStable = FALSE;
  chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
  chartInstance->c15_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  *c15_OilPProblem = 0.0;
  c15_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c15_c15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c15_debug_family_var_map[3];
  real_T c15_nargin = 0.0;
  real_T c15_nargout = 1.0;
  boolean_T c15_out;
  boolean_T c15_b0;
  uint32_T c15_b_debug_family_var_map[2];
  real_T c15_b_nargin = 0.0;
  real_T c15_b_nargout = 0.0;
  real_T c15_c_nargin = 0.0;
  real_T c15_c_nargout = 1.0;
  boolean_T c15_b_out;
  real_T c15_d_nargin = 0.0;
  real_T c15_d_nargout = 0.0;
  real_T *c15_OilPProblem;
  c15_EngineFuel_Bus *c15_EngNFuel;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  c15_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_EngNFuel = (c15_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_isStable = TRUE;
  switch (chartInstance->c15_is_c15_CockpitDisplayLib) {
   case c15_IN_EngineOilLowPressure:
    CV_CHART_EVAL(7, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c15_d_debug_family_names,
      c15_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 0U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 1U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_out, 2U, c15_b_sf_marshallOut,
      c15_b_sf_marshallIn);
    guard5 = FALSE;
    guard6 = FALSE;
    guard7 = FALSE;
    guard8 = FALSE;
    if (CV_EML_COND(2, 0, 0, c15_get_FlightMode(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(2, 0, 1, *(real_T *)((char_T *)c15_EngNFuel + 24) < 1000.0))
      {
        guard6 = TRUE;
      } else {
        guard8 = TRUE;
      }
    } else {
      guard8 = TRUE;
    }

    if (guard8 == TRUE) {
      if (CV_EML_COND(2, 0, 2, c15_get_FlightMode(chartInstance, 0) == 2.0)) {
        guard7 = TRUE;
      } else if (CV_EML_COND(2, 0, 3, c15_get_FlightMode(chartInstance, 0) ==
                             3.0)) {
        guard7 = TRUE;
      } else {
        guard5 = TRUE;
      }
    }

    if (guard7 == TRUE) {
      if (CV_EML_COND(2, 0, 4, *(real_T *)((char_T *)c15_EngNFuel + 24) < 2000.0))
      {
        guard6 = TRUE;
      } else {
        guard5 = TRUE;
      }
    }

    if (guard6 == TRUE) {
      c15_b0 = TRUE;
    }

    if (guard5 == TRUE) {
      c15_b0 = FALSE;
    }

    c15_out = CV_EML_IF(2, 0, 0, CV_EML_MCDC(2, 0, 0, !c15_b0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c15_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c15_sfEvent);
      chartInstance->c15_tp_EngineOilLowPressure = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
      chartInstance->c15_isStable = FALSE;
      chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
      chartInstance->c15_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c15_debug_family_names,
        c15_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargin, 0U, c15_sf_marshallOut,
        c15_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargout, 1U,
        c15_sf_marshallOut, c15_sf_marshallIn);
      *c15_OilPProblem = 0.0;
      c15_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c15_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c15_sfEvent);
    break;

   case c15_IN_Normal:
    CV_CHART_EVAL(7, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c15_c_debug_family_names,
      c15_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_c_nargin, 0U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_c_nargout, 1U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_out, 2U, c15_b_sf_marshallOut,
      c15_b_sf_marshallIn);
    guard1 = FALSE;
    guard2 = FALSE;
    guard3 = FALSE;
    guard4 = FALSE;
    if (CV_EML_COND(1, 0, 0, c15_get_FlightMode(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(1, 0, 1, *(real_T *)((char_T *)c15_EngNFuel + 24) < 1000.0))
      {
        guard2 = TRUE;
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      if (CV_EML_COND(1, 0, 2, c15_get_FlightMode(chartInstance, 0) == 2.0)) {
        guard3 = TRUE;
      } else if (CV_EML_COND(1, 0, 3, c15_get_FlightMode(chartInstance, 0) ==
                             3.0)) {
        guard3 = TRUE;
      } else {
        guard1 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      if (CV_EML_COND(1, 0, 4, *(real_T *)((char_T *)c15_EngNFuel + 24) < 2000.0))
      {
        guard2 = TRUE;
      } else {
        guard1 = TRUE;
      }
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(1, 0, 0, TRUE);
      CV_EML_IF(1, 0, 0, TRUE);
      c15_b_out = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(1, 0, 0, FALSE);
      CV_EML_IF(1, 0, 0, FALSE);
      c15_b_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c15_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
      chartInstance->c15_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
      chartInstance->c15_isStable = FALSE;
      chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_EngineOilLowPressure;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
      chartInstance->c15_tp_EngineOilLowPressure = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c15_b_debug_family_names,
        c15_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_d_nargin, 0U, c15_sf_marshallOut,
        c15_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_d_nargout, 1U,
        c15_sf_marshallOut, c15_sf_marshallIn);
      *c15_OilPProblem = 1.0;
      c15_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c15_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c15_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
}

static void c15_exit_internal_c15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c15_is_c15_CockpitDisplayLib) {
   case c15_IN_EngineOilLowPressure:
    CV_CHART_EVAL(7, 0, 1);
    chartInstance->c15_tp_EngineOilLowPressure = 0U;
    chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    break;

   case c15_IN_Normal:
    CV_CHART_EVAL(7, 0, 2);
    chartInstance->c15_tp_Normal = 0U;
    chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    break;
  }
}

static void c15_initc15_CockpitDisplayLib(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_doSetSimStateSideEffects = 0U;
  chartInstance->c15_setSimStateSideEffectsInfo = NULL;
  chartInstance->c15_tp_EngineOilLowPressure = 0U;
  chartInstance->c15_tp_Normal = 0U;
  chartInstance->c15_is_active_c15_CockpitDisplayLib = 0U;
  chartInstance->c15_is_c15_CockpitDisplayLib = c15_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc15_CockpitDisplayLib
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_nargout, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  boolean_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(boolean_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static boolean_T c15_c_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  boolean_T c15_y;
  boolean_T c15_b1;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_b1, 1, 11, 0U, 0, 0U, 0);
  c15_y = c15_b1;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_evilsf_internal_predicateOutput;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  boolean_T c15_y;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_evilsf_internal_predicateOutput = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_evilsf_internal_predicateOutput), &c15_thisId);
  sf_mex_destroy(&c15_evilsf_internal_predicateOutput);
  *(boolean_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c15_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  return chartInstance->c15_isStable;
}

void sf_exported_auto_duringc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  c15_c15_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c15_enter_atomic_c15_CockpitDisplayLib(chartInstance);
  c15_enter_internal_c15_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c15_exit_internal_c15_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
}

void sf_exported_auto_initBuffersc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
}

void sf_exported_auto_activate_callc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  chartInstance->c15_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc15_CockpitDisplayLib(SimStruct
  *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
}

void sf_exported_auto_initc15_CockpitDisplayLib(SimStruct *c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  c15_initc15_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec15_CockpitDisplayLib(SimStruct
  *c15_S)
{
  const mxArray *c15_out = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  c15_out = NULL;
  sf_mex_assign(&c15_out, sf_internal_get_sim_state_c15_CockpitDisplayLib(c15_S),
                FALSE);
  return c15_out;
}

void sf_exported_auto_setSimstatec15_CockpitDisplayLib(SimStruct *c15_S, const
  mxArray *c15_in)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  sf_internal_set_sim_state_c15_CockpitDisplayLib(c15_S, sf_mex_dup(c15_in));
  sf_mex_destroy(&c15_in);
}

void sf_exported_auto_check_state_inconsistency_c15_CockpitDisplayLib(SimStruct *
  c15_S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c15_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i0, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  uint8_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(uint8_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_b_tp_Normal, const char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_tp_Normal),
    &c15_thisId);
  sf_mex_destroy(&c15_b_tp_Normal);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_tp_Normal;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  uint8_T c15_y;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_b_tp_Normal = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_tp_Normal),
    &c15_thisId);
  sf_mex_destroy(&c15_b_tp_Normal);
  *(uint8_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c15_pData)
{
  const mxArray *c15_mxVal = NULL;
  c15_EngineFuel_Bus c15_tmp;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxVal = NULL;
  c15_tmp.RPM = *(real_T *)((char_T *)c15_pData + 0);
  c15_tmp.temperature = *(real_T *)((char_T *)c15_pData + 8);
  c15_tmp.fuelpressure = *(real_T *)((char_T *)c15_pData + 16);
  c15_tmp.oilpressure = *(real_T *)((char_T *)c15_pData + 24);
  c15_tmp.EGT = *(real_T *)((char_T *)c15_pData + 32);
  c15_tmp.EPR1 = *(real_T *)((char_T *)c15_pData + 40);
  c15_tmp.EPR2 = *(real_T *)((char_T *)c15_pData + 48);
  c15_tmp.FuelQuantity = *(real_T *)((char_T *)c15_pData + 56);
  sf_mex_assign(&c15_mxVal, c15_e_sf_marshallOut(chartInstance, &c15_tmp), FALSE);
  return c15_mxVal;
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  c15_EngineFuel_Bus c15_u;
  const mxArray *c15_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_d_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_e_u;
  const mxArray *c15_e_y = NULL;
  real_T c15_f_u;
  const mxArray *c15_f_y = NULL;
  real_T c15_g_u;
  const mxArray *c15_g_y = NULL;
  real_T c15_h_u;
  const mxArray *c15_h_y = NULL;
  real_T c15_i_u;
  const mxArray *c15_i_y = NULL;
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(c15_EngineFuel_Bus *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c15_b_u = c15_u.RPM;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_b_y, "RPM", "RPM", 0);
  c15_c_u = c15_u.temperature;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_c_y, "temperature", "temperature", 0);
  c15_d_u = c15_u.fuelpressure;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_d_y, "fuelpressure", "fuelpressure", 0);
  c15_e_u = c15_u.oilpressure;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_e_y, "oilpressure", "oilpressure", 0);
  c15_f_u = c15_u.EGT;
  c15_f_y = NULL;
  sf_mex_assign(&c15_f_y, sf_mex_create("y", &c15_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_f_y, "EGT", "EGT", 0);
  c15_g_u = c15_u.EPR1;
  c15_g_y = NULL;
  sf_mex_assign(&c15_g_y, sf_mex_create("y", &c15_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_g_y, "EPR1", "EPR1", 0);
  c15_h_u = c15_u.EPR2;
  c15_h_y = NULL;
  sf_mex_assign(&c15_h_y, sf_mex_create("y", &c15_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_h_y, "EPR2", "EPR2", 0);
  c15_i_u = c15_u.FuelQuantity;
  c15_i_y = NULL;
  sf_mex_assign(&c15_i_y, sf_mex_create("y", &c15_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c15_y, c15_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static const mxArray *c15_g_emlrt_marshallIn
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c15_b_setSimStateSideEffectsInfo, const char_T *c15_identifier)
{
  const mxArray *c15_y = NULL;
  emlrtMsgIdentifier c15_thisId;
  c15_y = NULL;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  sf_mex_assign(&c15_y, c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_setSimStateSideEffectsInfo), &c15_thisId), FALSE);
  sf_mex_destroy(&c15_b_setSimStateSideEffectsInfo);
  return c15_y;
}

static const mxArray *c15_h_emlrt_marshallIn
  (SFc15_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c15_u,
   const emlrtMsgIdentifier *c15_parentId)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_duplicatearraysafe(&c15_u), FALSE);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_updateDataWrittenToVector(SFc15_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c15_vectorIndex)
{
  c15_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c15_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static real_T c15_get_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c15_b);
  if (chartInstance->c15_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1071) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c15_FlightMode_address;
}

static void c15_set_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c15_b);
  if (chartInstance->c15_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1071) in the initialization routine of the chart.\n");
  }

  *chartInstance->c15_FlightMode_address = c15_c;
}

static real_T *c15_access_FlightMode(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  real_T *c15_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c15_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1071) in the initialization routine of the chart.\n");
  }

  c15_c = chartInstance->c15_FlightMode_address;
  if (c15_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c15_c;
}

static void init_dsm_address_info(SFc15_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c15_FlightMode_address, &chartInstance->c15_FlightMode_index);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c15_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3973801422U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(710430698U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(854649316U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3539234944U);
}

mxArray *sf_c15_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NLmHEqAWVEIWwhxL91q5QE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c15_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"OilPProblem\",},{M[8],M[0],T\"is_active_c15_CockpitDisplayLib\",},{M[9],M[0],T\"is_c15_CockpitDisplayLib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           15,
           2,
           3,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_CockpitDisplayLibMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CockpitDisplayLibMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CockpitDisplayLibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EngNFuel");
          _SFD_SET_DATA_PROPS(1,2,0,1,"OilPProblem");
          _SFD_SET_DATA_PROPS(2,11,0,0,"FlightMode");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,127,1,52);

        {
          static int condStart[] = { 2, 21, 57, 76, 99 };

          static int condEnd[] = { 17, 48, 72, 91, 126 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, 4, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,127,5,0,&(condStart[0]),&(condEnd[0]),9,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,130,1,52);

        {
          static int condStart[] = { 4, 23, 59, 78, 101 };

          static int condEnd[] = { 19, 50, 74, 93, 128 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, 4, -3, -2, -1 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,130,5,0,&(condStart[0]),&(condEnd[0]),10,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_EngNFuel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);

        {
          c15_EngineFuel_Bus *c15_EngNFuel;
          real_T *c15_OilPProblem;
          c15_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c15_EngNFuel = (c15_EngineFuel_Bus *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c15_EngNFuel);
          _SFD_SET_DATA_VALUE_PTR(1U, c15_OilPProblem);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c15_FlightMode_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CockpitDisplayLibMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "AbIUuPVKjGrpISYpajZ2R";
}

static void sf_opaque_initialize_c15_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_CockpitDisplayLib
    ((SFc15_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c15_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c15_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c15_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_CockpitDisplayLib((SFc15_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_CockpitDisplayLib
      ((SFc15_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,15,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2718778452U));
  ssSetChecksum1(S,(219155475U));
  ssSetChecksum2(S,(3989839511U));
  ssSetChecksum3(S,(950947029U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c15_CockpitDisplayLib(SimStruct *S)
{
  SFc15_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc15_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc15_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_CockpitDisplayLib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c15_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
