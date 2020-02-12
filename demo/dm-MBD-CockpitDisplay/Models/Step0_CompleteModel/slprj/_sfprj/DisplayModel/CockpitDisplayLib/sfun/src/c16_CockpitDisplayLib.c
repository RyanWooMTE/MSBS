/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c16_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c16_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c16_IN_EngineFailure           ((uint8_T)1U)
#define c16_IN_EngineOverSpeed         ((uint8_T)2U)
#define c16_IN_Normal                  ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "y" };

static const char * c16_b_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "y" };

static const char * c16_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c16_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c16_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c16_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c16_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c16_dataWrittenToVector[3];

/* Function Declarations */
static void initialize_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c16_update_debugger_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c16_st);
static void c16_set_sim_state_side_effects_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c16_enter_atomic_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void c16_enter_internal_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void c16_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c16_exit_internal_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void c16_initc16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static boolean_T c16_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_b_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_nargout, const char_T *c16_identifier);
static real_T c16_c_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static boolean_T c16_funcEngFailureToNormalc16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static boolean_T c16_funcNormalToEngFailurec16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_d_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static uint8_T c16_e_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_b_tp_Normal, const char_T *c16_identifier);
static uint8_T c16_f_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c16_pData);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_g_emlrt_marshallIn
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c16_b_setSimStateSideEffectsInfo, const char_T *c16_identifier);
static const mxArray *c16_h_emlrt_marshallIn
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c16_u,
   const emlrtMsgIdentifier *c16_parentId);
static void c16_updateDataWrittenToVector(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c16_vectorIndex);
static real_T c16_get_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b);
static void c16_set_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b, real_T c16_c);
static real_T *c16_access_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b);
static void init_dsm_address_info(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c16_update_debugger_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c16_prevAniVal;
  c16_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c16_is_active_c16_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 8U, chartInstance->c16_sfEvent);
  }

  if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
  }

  if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_EngineFailure) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
  }

  if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_EngineOverSpeed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
  }

  _SFD_SET_ANIMATION(c16_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  uint8_T c16_c_hoistedGlobal;
  uint8_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T *c16_RPMProblem;
  c16_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(3), FALSE);
  c16_hoistedGlobal = *c16_RPMProblem;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal = chartInstance->c16_is_active_c16_CockpitDisplayLib;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_c_hoistedGlobal = chartInstance->c16_is_c16_CockpitDisplayLib;
  c16_c_u = c16_c_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T *c16_RPMProblem;
  c16_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_u = sf_mex_dup(c16_st);
  *c16_RPMProblem = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 0)), "RPMProblem");
  chartInstance->c16_is_active_c16_CockpitDisplayLib = c16_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
     "is_active_c16_CockpitDisplayLib");
  chartInstance->c16_is_c16_CockpitDisplayLib = c16_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 2)),
     "is_c16_CockpitDisplayLib");
  sf_mex_assign(&chartInstance->c16_setSimStateSideEffectsInfo,
                c16_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c16_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c16_u);
  chartInstance->c16_doSetSimStateSideEffects = 1U;
  c16_update_debugger_state_c16_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void c16_set_sim_state_side_effects_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c16_doSetSimStateSideEffects != 0) {
    if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_EngineFailure) {
      chartInstance->c16_tp_EngineFailure = 1U;
    } else {
      chartInstance->c16_tp_EngineFailure = 0U;
    }

    if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_EngineOverSpeed) {
      chartInstance->c16_tp_EngineOverSpeed = 1U;
    } else {
      chartInstance->c16_tp_EngineOverSpeed = 0U;
    }

    if (chartInstance->c16_is_c16_CockpitDisplayLib == c16_IN_Normal) {
      chartInstance->c16_tp_Normal = 1U;
    } else {
      chartInstance->c16_tp_Normal = 0U;
    }

    chartInstance->c16_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c16_setSimStateSideEffectsInfo);
}

static void sf_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c16_set_sim_state_side_effects_c16_CockpitDisplayLib(chartInstance);
}

static void c16_enter_atomic_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 8U, chartInstance->c16_sfEvent);
  chartInstance->c16_is_active_c16_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c16_sfEvent);
}

static void c16_enter_internal_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c16_debug_family_var_map[2];
  real_T c16_nargin = 0.0;
  real_T c16_nargout = 0.0;
  real_T *c16_RPMProblem;
  c16_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c16_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
  chartInstance->c16_isStable = FALSE;
  chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
  chartInstance->c16_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c16_c_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 0U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 1U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  *c16_RPMProblem = 0.0;
  c16_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c16_c16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c16_debug_family_var_map[3];
  real_T c16_nargin = 0.0;
  real_T c16_nargout = 1.0;
  boolean_T c16_out;
  uint32_T c16_b_debug_family_var_map[2];
  real_T c16_b_nargin = 0.0;
  real_T c16_b_nargout = 0.0;
  real_T c16_c_nargin = 0.0;
  real_T c16_c_nargout = 1.0;
  boolean_T c16_b_out;
  boolean_T c16_b0;
  real_T c16_d_nargin = 0.0;
  real_T c16_d_nargout = 0.0;
  real_T c16_e_nargin = 0.0;
  real_T c16_e_nargout = 1.0;
  boolean_T c16_c_out;
  real_T c16_f_nargin = 0.0;
  real_T c16_f_nargout = 1.0;
  boolean_T c16_d_out;
  boolean_T c16_b1;
  real_T c16_g_nargin = 0.0;
  real_T c16_g_nargout = 0.0;
  real_T c16_h_nargin = 0.0;
  real_T c16_h_nargout = 1.0;
  boolean_T c16_e_out;
  real_T c16_i_nargin = 0.0;
  real_T c16_i_nargout = 0.0;
  real_T *c16_RPMProblem;
  c16_EngineFuel_Bus *c16_EngNFuel;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c16_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_EngNFuel = (c16_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c16_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_isStable = TRUE;
  switch (chartInstance->c16_is_c16_CockpitDisplayLib) {
   case c16_IN_EngineFailure:
    CV_CHART_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c16_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c16_h_debug_family_names,
      c16_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 0U, c16_b_sf_marshallOut,
      c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 1U, c16_b_sf_marshallOut,
      c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_out, 2U, c16_sf_marshallOut,
      c16_sf_marshallIn);
    c16_out = CV_EML_IF(3, 0, 0, c16_funcEngFailureToNormalc16_CockpitDisplayLib
                        (chartInstance));
    _SFD_SYMBOL_SCOPE_POP();
    if (c16_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_EngineFailure = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
      chartInstance->c16_isStable = FALSE;
      chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c16_c_debug_family_names,
        c16_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_nargin, 0U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_nargout, 1U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      *c16_RPMProblem = 0.0;
      c16_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c16_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c16_sfEvent);
    break;

   case c16_IN_EngineOverSpeed:
    CV_CHART_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c16_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c16_i_debug_family_names,
      c16_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_c_nargin, 0U, c16_b_sf_marshallOut,
      c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_c_nargout, 1U,
      c16_b_sf_marshallOut, c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_out, 2U, c16_sf_marshallOut,
      c16_sf_marshallIn);
    guard3 = FALSE;
    if (CV_EML_COND(4, 0, 0, c16_get_FlightMode(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(4, 0, 1, *(real_T *)((char_T *)c16_EngNFuel + 0) > 10000.0))
      {
        c16_b0 = TRUE;
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      c16_b0 = FALSE;
    }

    c16_b_out = CV_EML_IF(4, 0, 0, CV_EML_MCDC(4, 0, 0, !c16_b0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c16_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_EngineOverSpeed = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
      chartInstance->c16_isStable = FALSE;
      chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c16_c_debug_family_names,
        c16_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_d_nargin, 0U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_d_nargout, 1U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      *c16_RPMProblem = 0.0;
      c16_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c16_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c16_sfEvent);
    break;

   case c16_IN_Normal:
    CV_CHART_EVAL(8, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c16_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c16_f_debug_family_names,
      c16_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_e_nargin, 0U, c16_b_sf_marshallOut,
      c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_e_nargout, 1U,
      c16_b_sf_marshallOut, c16_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_c_out, 2U, c16_sf_marshallOut,
      c16_sf_marshallIn);
    c16_c_out = CV_EML_IF(1, 0, 0,
                          c16_funcNormalToEngFailurec16_CockpitDisplayLib
                          (chartInstance));
    _SFD_SYMBOL_SCOPE_POP();
    if (c16_c_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 1;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c16_k_debug_family_names,
          c16_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_f_nargin, 0U,
          c16_b_sf_marshallOut, c16_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_f_nargout, 1U,
          c16_b_sf_marshallOut, c16_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_d_out, 2U, c16_sf_marshallOut,
          c16_sf_marshallIn);
        guard2 = FALSE;
        if (c16_get_FlightMode(chartInstance, 0) == 1.0) {
          if (*(real_T *)((char_T *)c16_EngNFuel + 0) > 10000.0) {
            c16_b1 = TRUE;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          c16_b1 = FALSE;
        }

        c16_d_out = c16_b1;
        _SFD_SYMBOL_SCOPE_POP();
        if (c16_d_out) {
          transitionList[numTransitions] = 2;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
      chartInstance->c16_isStable = FALSE;
      chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_EngineFailure;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
      chartInstance->c16_tp_EngineFailure = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c16_d_debug_family_names,
        c16_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_g_nargin, 0U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_g_nargout, 1U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      *c16_RPMProblem = 1.0;
      c16_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c16_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c16_g_debug_family_names,
        c16_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_h_nargin, 0U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_h_nargout, 1U,
        c16_b_sf_marshallOut, c16_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_e_out, 2U, c16_sf_marshallOut,
        c16_sf_marshallIn);
      guard1 = FALSE;
      if (CV_EML_COND(2, 0, 0, c16_get_FlightMode(chartInstance, 0) == 1.0)) {
        if (CV_EML_COND(2, 0, 1, *(real_T *)((char_T *)c16_EngNFuel + 0) >
                        10000.0)) {
          CV_EML_MCDC(2, 0, 0, TRUE);
          CV_EML_IF(2, 0, 0, TRUE);
          c16_e_out = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(2, 0, 0, FALSE);
        CV_EML_IF(2, 0, 0, FALSE);
        c16_e_out = FALSE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c16_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
        chartInstance->c16_tp_Normal = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
        chartInstance->c16_isStable = FALSE;
        chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_EngineOverSpeed;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
        chartInstance->c16_tp_EngineOverSpeed = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c16_e_debug_family_names,
          c16_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_i_nargin, 0U,
          c16_b_sf_marshallOut, c16_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_i_nargout, 1U,
          c16_b_sf_marshallOut, c16_b_sf_marshallIn);
        *c16_RPMProblem = 2.0;
        c16_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c16_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c16_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c16_sfEvent);
}

static void c16_exit_internal_c16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c16_is_c16_CockpitDisplayLib) {
   case c16_IN_EngineFailure:
    CV_CHART_EVAL(8, 0, 1);
    chartInstance->c16_tp_EngineFailure = 0U;
    chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
    break;

   case c16_IN_EngineOverSpeed:
    CV_CHART_EVAL(8, 0, 2);
    chartInstance->c16_tp_EngineOverSpeed = 0U;
    chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c16_sfEvent);
    break;

   case c16_IN_Normal:
    CV_CHART_EVAL(8, 0, 3);
    chartInstance->c16_tp_Normal = 0U;
    chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c16_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c16_sfEvent);
    break;
  }
}

static void c16_initc16_CockpitDisplayLib(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_doSetSimStateSideEffects = 0U;
  chartInstance->c16_setSimStateSideEffectsInfo = NULL;
  chartInstance->c16_tp_EngineFailure = 0U;
  chartInstance->c16_tp_EngineOverSpeed = 0U;
  chartInstance->c16_tp_Normal = 0U;
  chartInstance->c16_is_active_c16_CockpitDisplayLib = 0U;
  chartInstance->c16_is_c16_CockpitDisplayLib = c16_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  boolean_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(boolean_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static boolean_T c16_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  boolean_T c16_y;
  boolean_T c16_b2;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_b2, 1, 11, 0U, 0, 0U, 0);
  c16_y = c16_b2;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_y;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  boolean_T c16_b_y;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_y = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_y = c16_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId);
  sf_mex_destroy(&c16_y);
  *(boolean_T *)c16_outData = c16_b_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_b_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_nargout, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  return c16_y;
}

static real_T c16_c_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c16_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  return chartInstance->c16_isStable;
}

void sf_exported_auto_duringc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  c16_c16_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c16_enter_atomic_c16_CockpitDisplayLib(chartInstance);
  c16_enter_internal_c16_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c16_exit_internal_c16_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
}

void sf_exported_auto_initBuffersc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
}

void sf_exported_auto_activate_callc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  chartInstance->c16_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc16_CockpitDisplayLib(SimStruct
  *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
}

void sf_exported_auto_initc16_CockpitDisplayLib(SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  c16_initc16_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec16_CockpitDisplayLib(SimStruct
  *c16_S)
{
  const mxArray *c16_out = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  c16_out = NULL;
  sf_mex_assign(&c16_out, sf_internal_get_sim_state_c16_CockpitDisplayLib(c16_S),
                FALSE);
  return c16_out;
}

void sf_exported_auto_setSimstatec16_CockpitDisplayLib(SimStruct *c16_S, const
  mxArray *c16_in)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  sf_internal_set_sim_state_c16_CockpitDisplayLib(c16_S, sf_mex_dup(c16_in));
  sf_mex_destroy(&c16_in);
}

void sf_exported_auto_check_state_inconsistency_c16_CockpitDisplayLib(SimStruct *
  c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static boolean_T c16_funcEngFailureToNormalc16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  boolean_T c16_y;
  uint32_T c16_debug_family_var_map[7];
  boolean_T c16_aVarTruthTableCondition_1;
  boolean_T c16_aVarTruthTableCondition_2;
  boolean_T c16_aVarTruthTableCondition_3;
  boolean_T c16_aVarTruthTableCondition_4;
  real_T c16_nargin = 0.0;
  real_T c16_nargout = 1.0;
  c16_EngineFuel_Bus *c16_EngNFuel;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c16_EngNFuel = (c16_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_1, 0U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_2, 1U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_3, 2U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_4, 3U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 4U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 5U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_y, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 3);
  c16_aVarTruthTableCondition_1 = FALSE;
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 4);
  c16_aVarTruthTableCondition_2 = FALSE;
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 5);
  c16_aVarTruthTableCondition_3 = FALSE;
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 6);
  c16_aVarTruthTableCondition_4 = FALSE;
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 10);
  c16_aVarTruthTableCondition_1 = (c16_get_FlightMode(chartInstance, 0) == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 13);
  c16_aVarTruthTableCondition_2 = (c16_get_FlightMode(chartInstance, 0) == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 16);
  c16_aVarTruthTableCondition_3 = (*(real_T *)((char_T *)c16_EngNFuel + 0) <
    700.0);
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 19);
  c16_aVarTruthTableCondition_4 = (*(real_T *)((char_T *)c16_EngNFuel + 0) <
    1500.0);
  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 21);
  guard1 = FALSE;
  if (CV_EML_COND(3, 1, 0, c16_aVarTruthTableCondition_1)) {
    if (CV_EML_COND(3, 1, 1, c16_aVarTruthTableCondition_3)) {
      CV_EML_MCDC(3, 1, 0, TRUE);
      CV_EML_IF(3, 1, 0, TRUE);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 22);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 37);
      c16_y = FALSE;
      c16_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, -37);
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(3, 1, 0, FALSE);
    CV_EML_IF(3, 1, 0, FALSE);
    _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 23);
    guard2 = FALSE;
    if (CV_EML_COND(3, 1, 2, c16_aVarTruthTableCondition_2)) {
      if (CV_EML_COND(3, 1, 3, c16_aVarTruthTableCondition_4)) {
        CV_EML_MCDC(3, 1, 1, TRUE);
        CV_EML_IF(3, 1, 1, TRUE);
        _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 24);
        CV_EML_FCN(3, 2);
        _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 37);
        c16_y = FALSE;
        c16_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, -37);
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(3, 1, 1, FALSE);
      CV_EML_IF(3, 1, 1, FALSE);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 26);
      CV_EML_FCN(3, 1);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, 32);
      c16_y = TRUE;
      c16_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, -32);
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c16_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  return c16_y;
}

static boolean_T c16_funcNormalToEngFailurec16_CockpitDisplayLib
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance)
{
  boolean_T c16_y;
  uint32_T c16_debug_family_var_map[7];
  boolean_T c16_aVarTruthTableCondition_1;
  boolean_T c16_aVarTruthTableCondition_2;
  boolean_T c16_aVarTruthTableCondition_3;
  boolean_T c16_aVarTruthTableCondition_4;
  real_T c16_nargin = 0.0;
  real_T c16_nargout = 1.0;
  c16_EngineFuel_Bus *c16_EngNFuel;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c16_EngNFuel = (c16_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c16_b_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_1, 0U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_2, 1U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_3, 2U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_aVarTruthTableCondition_4, 3U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 4U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 5U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_y, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 3);
  c16_aVarTruthTableCondition_1 = FALSE;
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 4);
  c16_aVarTruthTableCondition_2 = FALSE;
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 5);
  c16_aVarTruthTableCondition_3 = FALSE;
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 6);
  c16_aVarTruthTableCondition_4 = FALSE;
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 11);
  c16_aVarTruthTableCondition_1 = (c16_get_FlightMode(chartInstance, 0) == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 15);
  c16_aVarTruthTableCondition_2 = (c16_get_FlightMode(chartInstance, 0) == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 19);
  c16_aVarTruthTableCondition_3 = (*(real_T *)((char_T *)c16_EngNFuel + 0) <
    650.0);
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 23);
  c16_aVarTruthTableCondition_4 = (*(real_T *)((char_T *)c16_EngNFuel + 0) <
    1500.0);
  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 25);
  guard1 = FALSE;
  if (CV_EML_COND(4, 1, 0, c16_aVarTruthTableCondition_1)) {
    if (CV_EML_COND(4, 1, 1, c16_aVarTruthTableCondition_3)) {
      CV_EML_MCDC(4, 1, 0, TRUE);
      CV_EML_IF(4, 1, 0, TRUE);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 26);
      CV_EML_FCN(4, 1);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 37);
      c16_y = TRUE;
      c16_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, -37);
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(4, 1, 0, FALSE);
    CV_EML_IF(4, 1, 0, FALSE);
    _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 27);
    guard2 = FALSE;
    if (CV_EML_COND(4, 1, 2, c16_aVarTruthTableCondition_2)) {
      if (CV_EML_COND(4, 1, 3, c16_aVarTruthTableCondition_4)) {
        CV_EML_MCDC(4, 1, 1, TRUE);
        CV_EML_IF(4, 1, 1, TRUE);
        _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 28);
        CV_EML_FCN(4, 1);
        _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 37);
        c16_y = TRUE;
        c16_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, -37);
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(4, 1, 1, FALSE);
      CV_EML_IF(4, 1, 1, FALSE);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 30);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, 43);
      c16_y = FALSE;
      c16_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, -43);
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c16_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  return c16_y;
}

boolean_T sf_exported_user_c16_CockpitDisplayLib_funcEngFailureToNormal
  (SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  return c16_funcEngFailureToNormalc16_CockpitDisplayLib(chartInstance);
}

boolean_T sf_exported_user_c16_CockpitDisplayLib_funcNormalToEngFailure
  (SimStruct *c16_S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c16_S))->chartInstance;
  return c16_funcNormalToEngFailurec16_CockpitDisplayLib(chartInstance);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_d_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i0, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  uint8_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(uint8_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static uint8_T c16_e_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_b_tp_Normal, const char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_tp_Normal),
    &c16_thisId);
  sf_mex_destroy(&c16_b_tp_Normal);
  return c16_y;
}

static uint8_T c16_f_emlrt_marshallIn(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_tp_Normal;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  uint8_T c16_y;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_b_tp_Normal = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_tp_Normal),
    &c16_thisId);
  sf_mex_destroy(&c16_b_tp_Normal);
  *(uint8_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c16_pData)
{
  const mxArray *c16_mxVal = NULL;
  c16_EngineFuel_Bus c16_tmp;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxVal = NULL;
  c16_tmp.RPM = *(real_T *)((char_T *)c16_pData + 0);
  c16_tmp.temperature = *(real_T *)((char_T *)c16_pData + 8);
  c16_tmp.fuelpressure = *(real_T *)((char_T *)c16_pData + 16);
  c16_tmp.oilpressure = *(real_T *)((char_T *)c16_pData + 24);
  c16_tmp.EGT = *(real_T *)((char_T *)c16_pData + 32);
  c16_tmp.EPR1 = *(real_T *)((char_T *)c16_pData + 40);
  c16_tmp.EPR2 = *(real_T *)((char_T *)c16_pData + 48);
  c16_tmp.FuelQuantity = *(real_T *)((char_T *)c16_pData + 56);
  sf_mex_assign(&c16_mxVal, c16_e_sf_marshallOut(chartInstance, &c16_tmp), FALSE);
  return c16_mxVal;
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  c16_EngineFuel_Bus c16_u;
  const mxArray *c16_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_d_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_e_u;
  const mxArray *c16_e_y = NULL;
  real_T c16_f_u;
  const mxArray *c16_f_y = NULL;
  real_T c16_g_u;
  const mxArray *c16_g_y = NULL;
  real_T c16_h_u;
  const mxArray *c16_h_y = NULL;
  real_T c16_i_u;
  const mxArray *c16_i_y = NULL;
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(c16_EngineFuel_Bus *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c16_b_u = c16_u.RPM;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_b_y, "RPM", "RPM", 0);
  c16_c_u = c16_u.temperature;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_c_y, "temperature", "temperature", 0);
  c16_d_u = c16_u.fuelpressure;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_d_y, "fuelpressure", "fuelpressure", 0);
  c16_e_u = c16_u.oilpressure;
  c16_e_y = NULL;
  sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_e_y, "oilpressure", "oilpressure", 0);
  c16_f_u = c16_u.EGT;
  c16_f_y = NULL;
  sf_mex_assign(&c16_f_y, sf_mex_create("y", &c16_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_f_y, "EGT", "EGT", 0);
  c16_g_u = c16_u.EPR1;
  c16_g_y = NULL;
  sf_mex_assign(&c16_g_y, sf_mex_create("y", &c16_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_g_y, "EPR1", "EPR1", 0);
  c16_h_u = c16_u.EPR2;
  c16_h_y = NULL;
  sf_mex_assign(&c16_h_y, sf_mex_create("y", &c16_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_h_y, "EPR2", "EPR2", 0);
  c16_i_u = c16_u.FuelQuantity;
  c16_i_y = NULL;
  sf_mex_assign(&c16_i_y, sf_mex_create("y", &c16_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c16_y, c16_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_g_emlrt_marshallIn
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c16_b_setSimStateSideEffectsInfo, const char_T *c16_identifier)
{
  const mxArray *c16_y = NULL;
  emlrtMsgIdentifier c16_thisId;
  c16_y = NULL;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  sf_mex_assign(&c16_y, c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_setSimStateSideEffectsInfo), &c16_thisId), FALSE);
  sf_mex_destroy(&c16_b_setSimStateSideEffectsInfo);
  return c16_y;
}

static const mxArray *c16_h_emlrt_marshallIn
  (SFc16_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c16_u,
   const emlrtMsgIdentifier *c16_parentId)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_duplicatearraysafe(&c16_u), FALSE);
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_updateDataWrittenToVector(SFc16_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c16_vectorIndex)
{
  c16_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c16_vectorIndex, 0, 2, 1, 0)] = TRUE;
}

static real_T c16_get_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c16_b);
  if (chartInstance->c16_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1085) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c16_FlightMode_address;
}

static void c16_set_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b, real_T c16_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c16_b);
  if (chartInstance->c16_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1085) in the initialization routine of the chart.\n");
  }

  *chartInstance->c16_FlightMode_address = c16_c;
}

static real_T *c16_access_FlightMode(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c16_b)
{
  real_T *c16_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c16_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1085) in the initialization routine of the chart.\n");
  }

  c16_c = chartInstance->c16_FlightMode_address;
  if (c16_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c16_c;
}

static void init_dsm_address_info(SFc16_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c16_FlightMode_address, &chartInstance->c16_FlightMode_index);
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

void sf_c16_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2927901051U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4274534833U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2329582366U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3837046271U);
}

mxArray *sf_c16_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("U0DCBEjgkCVZMuNZ5m9noH");
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

mxArray *sf_c16_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c16_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"RPMProblem\",},{M[8],M[0],T\"is_active_c16_CockpitDisplayLib\",},{M[9],M[0],T\"is_c16_CockpitDisplayLib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           16,
           5,
           5,
           5,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"RPMProblem");
          _SFD_SET_DATA_PROPS(2,11,0,0,"FlightMode");
          _SFD_SET_DATA_PROPS(3,9,0,0,"");
          _SFD_SET_DATA_PROPS(4,9,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,3,2,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(3,0,"funcEngFailureToNormalc16_CockpitDisplayLib",0,
                             -1,644);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",644,-1,691);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",691,-1,738);
        _SFD_CV_INIT_EML_IF(3,1,0,410,469,500,642);
        _SFD_CV_INIT_EML_IF(3,1,1,500,563,594,642);

        {
          static int condStart[] = { 414, 443 };

          static int condEnd[] = { 439, 468 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,0,414,468,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 508, 537 };

          static int condEnd[] = { 533, 562 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,1,508,562,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,1,3,2,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(4,0,"funcNormalToEngFailurec16_CockpitDisplayLib",0,
                             -1,856);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",856,-1,970);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",970,-1,1094);
        _SFD_CV_INIT_EML_IF(4,1,0,622,681,712,854);
        _SFD_CV_INIT_EML_IF(4,1,1,712,775,806,854);

        {
          static int condStart[] = { 626, 655 };

          static int condEnd[] = { 651, 680 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,1,0,626,680,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 720, 749 };

          static int condEnd[] = { 745, 774 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,1,1,720,774,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 16, 43 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,46,1,46);

        {
          static int condStart[] = { 3, 26 };

          static int condEnd[] = { 18, 45 };

          static int pfixExpr[] = { 0, 1, -3, -1 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,46,2,0,&(condStart[0]),&(condEnd[0]),4,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_EngNFuel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
          c16_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
          c16_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(3,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));

        {
          c16_EngineFuel_Bus *c16_EngNFuel;
          real_T *c16_RPMProblem;
          c16_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c16_EngNFuel = (c16_EngineFuel_Bus *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_EngNFuel);
          _SFD_SET_DATA_VALUE_PTR(1U, c16_RPMProblem);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c16_FlightMode_address);
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
  return "c4SvDWIK6I6oUDbOkTJD2F";
}

static void sf_opaque_initialize_c16_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c16_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c16_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c16_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_CockpitDisplayLib
    ((SFc16_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c16_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c16_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c16_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_CockpitDisplayLib((SFc16_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_CockpitDisplayLib
      ((SFc16_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(880883594U));
  ssSetChecksum1(S,(1168149345U));
  ssSetChecksum2(S,(66705093U));
  ssSetChecksum3(S,(3190927015U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c16_CockpitDisplayLib(SimStruct *S)
{
  SFc16_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc16_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc16_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_CockpitDisplayLib;
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

void c16_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
