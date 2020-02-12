/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c11_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_CabinPressureLow        ((uint8_T)1U)
#define c11_IN_Normal                  ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_c_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c11_d_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c11_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c11_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c11_update_debugger_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c11_enter_atomic_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void c11_enter_internal_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void c11_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c11_exit_internal_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void c11_initc11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_c_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_d_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_e_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_Normal, const char_T *c11_identifier);
static uint8_T c11_f_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_Misc_bus_io(void *chartInstanceVoid, void *c11_pData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_g_emlrt_marshallIn
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier);
static const mxArray *c11_h_emlrt_marshallIn
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c11_u,
   const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c11_vectorIndex);
static real_T c11_get_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c11_update_debugger_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_CockpitDisplayLib == c11_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_CockpitDisplayLib == c11_IN_CabinPressureLow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T c11_c_hoistedGlobal;
  uint8_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  real_T *c11_CabinPProblem;
  c11_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(3), FALSE);
  c11_hoistedGlobal = *c11_CabinPProblem;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_is_active_c11_CockpitDisplayLib;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_hoistedGlobal = chartInstance->c11_is_c11_CockpitDisplayLib;
  c11_c_u = c11_c_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T *c11_CabinPProblem;
  c11_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_CabinPProblem = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "CabinPProblem");
  chartInstance->c11_is_active_c11_CockpitDisplayLib = c11_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_CockpitDisplayLib");
  chartInstance->c11_is_c11_CockpitDisplayLib = c11_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
     "is_c11_CockpitDisplayLib");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_CockpitDisplayLib == c11_IN_CabinPressureLow)
    {
      chartInstance->c11_tp_CabinPressureLow = 1U;
    } else {
      chartInstance->c11_tp_CabinPressureLow = 0U;
    }

    if (chartInstance->c11_is_c11_CockpitDisplayLib == c11_IN_Normal) {
      chartInstance->c11_tp_Normal = 1U;
    } else {
      chartInstance->c11_tp_Normal = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c11_set_sim_state_side_effects_c11_CockpitDisplayLib(chartInstance);
}

static void c11_enter_atomic_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T *c11_CabinPProblem;
  c11_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = FALSE;
  chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  *c11_CabinPProblem = 0.0;
  c11_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  boolean_T c11_b0;
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_b_out;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 0.0;
  real_T *c11_CabinPProblem;
  c11_MiscData *c11_Misc;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c11_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_Misc = (c11_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_isStable = TRUE;
  switch (chartInstance->c11_is_c11_CockpitDisplayLib) {
   case c11_IN_CabinPressureLow:
    CV_CHART_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_d_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    guard3 = FALSE;
    guard4 = FALSE;
    if (CV_EML_COND(2, 0, 0, c11_get_FlightMode(chartInstance, 0) == 1.0)) {
      guard4 = TRUE;
    } else if (CV_EML_COND(2, 0, 1, c11_get_FlightMode(chartInstance, 0) == 2.0))
    {
      guard4 = TRUE;
    } else {
      guard3 = TRUE;
    }

    if (guard4 == TRUE) {
      if (CV_EML_COND(2, 0, 2, *(real_T *)((char_T *)c11_Misc + 8) < 0.5)) {
        c11_b0 = TRUE;
      } else {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c11_b0 = FALSE;
    }

    c11_out = CV_EML_IF(2, 0, 0, CV_EML_MCDC(2, 0, 0, !c11_b0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_CabinPressureLow = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = FALSE;
      chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      *c11_CabinPProblem = 0.0;
      c11_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_Normal:
    CV_CHART_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_c_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    guard1 = FALSE;
    guard2 = FALSE;
    if (CV_EML_COND(1, 0, 0, c11_get_FlightMode(chartInstance, 0) == 1.0)) {
      guard2 = TRUE;
    } else if (CV_EML_COND(1, 0, 1, c11_get_FlightMode(chartInstance, 0) == 2.0))
    {
      guard2 = TRUE;
    } else {
      guard1 = TRUE;
    }

    if (guard2 == TRUE) {
      if (CV_EML_COND(1, 0, 2, *(real_T *)((char_T *)c11_Misc + 8) < 0.5)) {
        CV_EML_MCDC(1, 0, 0, TRUE);
        CV_EML_IF(1, 0, 0, TRUE);
        c11_b_out = TRUE;
      } else {
        guard1 = TRUE;
      }
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(1, 0, 0, FALSE);
      CV_EML_IF(1, 0, 0, FALSE);
      c11_b_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = FALSE;
      chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_CabinPressureLow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_CabinPressureLow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_b_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      *c11_CabinPProblem = 1.0;
      c11_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_c11_CockpitDisplayLib) {
   case c11_IN_CabinPressureLow:
    CV_CHART_EVAL(5, 0, 1);
    chartInstance->c11_tp_CabinPressureLow = 0U;
    chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_Normal:
    CV_CHART_EVAL(5, 0, 2);
    chartInstance->c11_tp_Normal = 0U;
    chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_CockpitDisplayLib(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_CabinPressureLow = 0U;
  chartInstance->c11_tp_Normal = 0U;
  chartInstance->c11_is_active_c11_CockpitDisplayLib = 0U;
  chartInstance->c11_is_c11_CockpitDisplayLib = c11_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc11_CockpitDisplayLib
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static boolean_T c11_c_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b1;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b1, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_evilsf_internal_predicateOutput;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_evilsf_internal_predicateOutput = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_evilsf_internal_predicateOutput), &c11_thisId);
  sf_mex_destroy(&c11_evilsf_internal_predicateOutput);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c11_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  c11_c11_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c11_enter_atomic_c11_CockpitDisplayLib(chartInstance);
  c11_enter_internal_c11_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c11_exit_internal_c11_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
}

void sf_exported_auto_initBuffersc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
}

void sf_exported_auto_activate_callc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_CockpitDisplayLib(SimStruct
  *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
}

void sf_exported_auto_initc11_CockpitDisplayLib(SimStruct *c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  c11_initc11_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_CockpitDisplayLib(SimStruct
  *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_CockpitDisplayLib(c11_S),
                FALSE);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_CockpitDisplayLib(SimStruct *c11_S, const
  mxArray *c11_in)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  sf_internal_set_sim_state_c11_CockpitDisplayLib(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_CockpitDisplayLib(SimStruct *
  c11_S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c11_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_d_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i0, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_Normal, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_Normal),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_Normal);
  return c11_y;
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_Normal;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_b_tp_Normal = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_Normal),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_Normal);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_Misc_bus_io(void *chartInstanceVoid, void *c11_pData)
{
  const mxArray *c11_mxVal = NULL;
  c11_MiscData c11_tmp;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxVal = NULL;
  c11_tmp.FlapPosition = *(real_T *)((char_T *)c11_pData + 0);
  c11_tmp.CabinPressure = *(real_T *)((char_T *)c11_pData + 8);
  c11_tmp.HydraulicPressure = *(real_T *)((char_T *)c11_pData + 16);
  c11_tmp.APUData = *(real_T *)((char_T *)c11_pData + 24);
  c11_tmp.LGLeftLock = *(boolean_T *)((char_T *)c11_pData + 32);
  c11_tmp.LGRightLock = *(boolean_T *)((char_T *)c11_pData + 33);
  sf_mex_assign(&c11_mxVal, c11_e_sf_marshallOut(chartInstance, &c11_tmp), FALSE);
  return c11_mxVal;
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  c11_MiscData c11_u;
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_e_u;
  const mxArray *c11_e_y = NULL;
  boolean_T c11_f_u;
  const mxArray *c11_f_y = NULL;
  boolean_T c11_g_u;
  const mxArray *c11_g_y = NULL;
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(c11_MiscData *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c11_b_u = c11_u.FlapPosition;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_b_y, "FlapPosition", "FlapPosition", 0);
  c11_c_u = c11_u.CabinPressure;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_c_y, "CabinPressure", "CabinPressure", 0);
  c11_d_u = c11_u.HydraulicPressure;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c11_e_u = c11_u.APUData;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_e_y, "APUData", "APUData", 0);
  c11_f_u = c11_u.LGLeftLock;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_f_y, "LGLeftLock", "LGLeftLock", 0);
  c11_g_u = c11_u.LGRightLock;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c11_y, c11_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_g_emlrt_marshallIn
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), FALSE);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_h_emlrt_marshallIn
  (SFc11_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c11_u,
   const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), FALSE);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector(SFc11_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c11_vectorIndex)
{
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static real_T c11_get_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1051) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_FlightMode_address;
}

static void c11_set_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1051) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_FlightMode_address = c11_c;
}

static real_T *c11_access_FlightMode(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1051) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_FlightMode_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c11_FlightMode_address, &chartInstance->c11_FlightMode_index);
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

void sf_c11_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2147620774U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3776115487U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(629945791U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2681685506U);
}

mxArray *sf_c11_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("H3iaA84uWqbTxdRmgqMByD");
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

mxArray *sf_c11_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"CabinPProblem\",},{M[8],M[0],T\"is_active_c11_CockpitDisplayLib\",},{M[9],M[0],T\"is_c11_CockpitDisplayLib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Misc");
          _SFD_SET_DATA_PROPS(1,11,0,0,"FlightMode");
          _SFD_SET_DATA_PROPS(2,2,0,1,"CabinPProblem");
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
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,66,1,52);

        {
          static int condStart[] = { 2, 19, 42 };

          static int condEnd[] = { 17, 34, 66 };

          static int pfixExpr[] = { 0, 1, -2, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,66,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,69,1,52);

        {
          static int condStart[] = { 4, 21, 44 };

          static int condEnd[] = { 19, 36, 68 };

          static int pfixExpr[] = { 0, 1, -2, 2, -3, -1 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,69,3,0,&(condStart[0]),&(condEnd[0]),6,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);

        {
          c11_MiscData *c11_Misc;
          real_T *c11_CabinPProblem;
          c11_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c11_Misc = (c11_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_Misc);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_FlightMode_address);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_CabinPProblem);
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
  return "uMC4rCRI0p7zfPKoXb5HBH";
}

static void sf_opaque_initialize_c11_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_CockpitDisplayLib
    ((SFc11_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c11_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c11_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_CockpitDisplayLib((SFc11_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_CockpitDisplayLib
      ((SFc11_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(687196424U));
  ssSetChecksum1(S,(2668023528U));
  ssSetChecksum2(S,(1410912245U));
  ssSetChecksum3(S,(1616312060U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_CockpitDisplayLib(SimStruct *S)
{
  SFc11_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc11_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc11_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_CockpitDisplayLib;
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

void c11_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
