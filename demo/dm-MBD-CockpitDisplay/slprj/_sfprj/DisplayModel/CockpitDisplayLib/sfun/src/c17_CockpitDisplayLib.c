/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c17_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c17_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c17_IN_Cooling                 ((uint8_T)1U)
#define c17_IN_EngineFire              ((uint8_T)2U)
#define c17_IN_Heating                 ((uint8_T)3U)
#define c17_IN_Normal                  ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c17_debug_family_names[2] = { "nargin", "nargout" };

static const char * c17_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c17_c_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_d_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c17_n_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c17_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c17_update_debugger_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c17_st);
static void c17_set_sim_state_side_effects_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c17_enter_atomic_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void c17_enter_internal_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void c17_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c17_exit_internal_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void c17_initc17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_nargout, const char_T *c17_identifier);
static real_T c17_b_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static boolean_T c17_c_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_d_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static uint8_T c17_e_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_b_tp_Normal, const char_T *c17_identifier);
static uint8_T c17_f_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c17_pData);
static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_g_emlrt_marshallIn
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c17_b_setSimStateSideEffectsInfo, const char_T *c17_identifier);
static const mxArray *c17_h_emlrt_marshallIn
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c17_u,
   const emlrtMsgIdentifier *c17_parentId);
static void c17_updateDataWrittenToVector(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c17_vectorIndex);
static void init_dsm_address_info(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c17_update_debugger_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c17_prevAniVal;
  c17_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c17_is_active_c17_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 9U, chartInstance->c17_sfEvent);
  }

  if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
  }

  if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Cooling) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
  }

  if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Heating) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
  }

  if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_EngineFire) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
  }

  _SFD_SET_ANIMATION(c17_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  real_T c17_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  uint8_T c17_b_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  uint8_T c17_c_hoistedGlobal;
  uint8_T c17_c_u;
  const mxArray *c17_d_y = NULL;
  uint8_T c17_d_hoistedGlobal;
  uint8_T c17_d_u;
  const mxArray *c17_e_y = NULL;
  real_T *c17_TempProblem;
  c17_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellarray(4), FALSE);
  c17_hoistedGlobal = *c17_TempProblem;
  c17_u = c17_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = chartInstance->c17_is_active_c17_CockpitDisplayLib;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  c17_c_hoistedGlobal = chartInstance->c17_is_c17_CockpitDisplayLib;
  c17_c_u = c17_c_hoistedGlobal;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 2, c17_d_y);
  c17_d_hoistedGlobal = chartInstance->c17_temporalCounter_i1;
  c17_d_u = c17_d_hoistedGlobal;
  c17_e_y = NULL;
  sf_mex_assign(&c17_e_y, sf_mex_create("y", &c17_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 3, c17_e_y);
  sf_mex_assign(&c17_st, c17_y, FALSE);
  return c17_st;
}

static void set_sim_state_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T *c17_TempProblem;
  c17_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_u = sf_mex_dup(c17_st);
  *c17_TempProblem = c17_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c17_u, 0)), "TempProblem");
  chartInstance->c17_is_active_c17_CockpitDisplayLib = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_CockpitDisplayLib");
  chartInstance->c17_is_c17_CockpitDisplayLib = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 2)),
     "is_c17_CockpitDisplayLib");
  chartInstance->c17_temporalCounter_i1 = c17_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c17_u, 3)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c17_setSimStateSideEffectsInfo,
                c17_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c17_u, 4)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c17_u);
  chartInstance->c17_doSetSimStateSideEffects = 1U;
  c17_update_debugger_state_c17_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void c17_set_sim_state_side_effects_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c17_doSetSimStateSideEffects != 0) {
    if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Cooling) {
      chartInstance->c17_tp_Cooling = 1U;
      if (sf_mex_sub(chartInstance->c17_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c17_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c17_tp_Cooling = 0U;
    }

    if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_EngineFire) {
      chartInstance->c17_tp_EngineFire = 1U;
    } else {
      chartInstance->c17_tp_EngineFire = 0U;
    }

    if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Heating) {
      chartInstance->c17_tp_Heating = 1U;
      if (sf_mex_sub(chartInstance->c17_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c17_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c17_tp_Heating = 0U;
    }

    if (chartInstance->c17_is_c17_CockpitDisplayLib == c17_IN_Normal) {
      chartInstance->c17_tp_Normal = 1U;
    } else {
      chartInstance->c17_tp_Normal = 0U;
    }

    chartInstance->c17_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c17_setSimStateSideEffectsInfo);
}

static void sf_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c17_set_sim_state_side_effects_c17_CockpitDisplayLib(chartInstance);
}

static void c17_enter_atomic_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 9U, chartInstance->c17_sfEvent);
  chartInstance->c17_is_active_c17_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c17_sfEvent);
}

static void c17_enter_internal_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c17_debug_family_var_map[2];
  real_T c17_nargin = 0.0;
  real_T c17_nargout = 0.0;
  real_T *c17_TempProblem;
  c17_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c17_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
  chartInstance->c17_isStable = FALSE;
  chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
  chartInstance->c17_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  *c17_TempProblem = 0.0;
  c17_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c17_c17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c17_debug_family_var_map[3];
  real_T c17_nargin = 0.0;
  real_T c17_nargout = 1.0;
  boolean_T c17_out;
  uint32_T c17_b_debug_family_var_map[2];
  real_T c17_b_nargin = 0.0;
  real_T c17_b_nargout = 0.0;
  real_T c17_c_nargin = 0.0;
  real_T c17_c_nargout = 1.0;
  boolean_T c17_b_out;
  real_T c17_d_nargin = 0.0;
  real_T c17_d_nargout = 0.0;
  real_T c17_e_nargin = 0.0;
  real_T c17_e_nargout = 1.0;
  boolean_T c17_c_out;
  real_T c17_f_nargin = 0.0;
  real_T c17_f_nargout = 1.0;
  boolean_T c17_d_out;
  real_T c17_g_nargin = 0.0;
  real_T c17_g_nargout = 0.0;
  real_T c17_h_nargin = 0.0;
  real_T c17_h_nargout = 1.0;
  boolean_T c17_e_out;
  real_T c17_i_nargin = 0.0;
  real_T c17_i_nargout = 0.0;
  real_T c17_j_nargin = 0.0;
  real_T c17_j_nargout = 1.0;
  boolean_T c17_f_out;
  real_T *c17_TempProblem;
  c17_EngineFuel_Bus *c17_EngNFuel;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c17_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_EngNFuel = (c17_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c17_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_isStable = TRUE;
  switch (chartInstance->c17_is_c17_CockpitDisplayLib) {
   case c17_IN_Cooling:
    CV_CHART_EVAL(9, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c17_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_f_debug_family_names,
      c17_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_out, 2U, c17_b_sf_marshallOut,
      c17_b_sf_marshallIn);
    c17_out = CV_EML_IF(6, 0, 0, *(real_T *)((char_T *)c17_EngNFuel + 8) >
                        2000.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c17_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_Cooling = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
      chartInstance->c17_isStable = FALSE;
      chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_EngineFire;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_EngineFire = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c17_b_debug_family_names,
        c17_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargin, 0U, c17_sf_marshallOut,
        c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargout, 1U,
        c17_sf_marshallOut, c17_sf_marshallIn);
      *c17_TempProblem = 1.0;
      c17_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c17_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_e_debug_family_names,
        c17_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_c_nargin, 0U, c17_sf_marshallOut,
        c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_c_nargout, 1U,
        c17_sf_marshallOut, c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_out, 2U, c17_b_sf_marshallOut,
        c17_b_sf_marshallIn);
      guard2 = FALSE;
      if (CV_EML_COND(4, 0, 0, chartInstance->c17_temporalCounter_i1 >= 1)) {
        if (CV_EML_COND(4, 0, 1, *(real_T *)((char_T *)c17_EngNFuel + 8) <=
                        2000.0)) {
          CV_EML_MCDC(4, 0, 0, TRUE);
          CV_EML_IF(4, 0, 0, TRUE);
          c17_b_out = TRUE;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(4, 0, 0, FALSE);
        CV_EML_IF(4, 0, 0, FALSE);
        c17_b_out = FALSE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c17_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c17_sfEvent);
        chartInstance->c17_tp_Cooling = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
        chartInstance->c17_isStable = FALSE;
        chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_Normal;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
        chartInstance->c17_tp_Normal = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c17_debug_family_names,
          c17_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_d_nargin, 0U,
          c17_sf_marshallOut, c17_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_d_nargout, 1U,
          c17_sf_marshallOut, c17_sf_marshallIn);
        *c17_TempProblem = 0.0;
        c17_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c17_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_EngineFire:
    CV_CHART_EVAL(9, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c17_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_g_debug_family_names,
      c17_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_nargin, 0U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_nargout, 1U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_c_out, 2U, c17_b_sf_marshallOut,
      c17_b_sf_marshallIn);
    c17_c_out = CV_EML_IF(2, 0, 0, *(real_T *)((char_T *)c17_EngNFuel + 8) <=
                          2000.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c17_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_EngineFire = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
      chartInstance->c17_isStable = FALSE;
      chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_Cooling;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
      chartInstance->c17_temporalCounter_i1 = 0U;
      chartInstance->c17_tp_Cooling = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c17_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_Heating:
    CV_CHART_EVAL(9, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c17_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_h_debug_family_names,
      c17_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_f_nargin, 0U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_f_nargout, 1U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_d_out, 2U, c17_b_sf_marshallOut,
      c17_b_sf_marshallIn);
    guard1 = FALSE;
    if (CV_EML_COND(3, 0, 0, chartInstance->c17_temporalCounter_i1 >= 1)) {
      if (CV_EML_COND(3, 0, 1, *(real_T *)((char_T *)c17_EngNFuel + 8) > 2000.0))
      {
        CV_EML_MCDC(3, 0, 0, TRUE);
        CV_EML_IF(3, 0, 0, TRUE);
        c17_d_out = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(3, 0, 0, FALSE);
      CV_EML_IF(3, 0, 0, FALSE);
      c17_d_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c17_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_Heating = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
      chartInstance->c17_isStable = FALSE;
      chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_EngineFire;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_EngineFire = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c17_b_debug_family_names,
        c17_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_g_nargin, 0U, c17_sf_marshallOut,
        c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_g_nargout, 1U,
        c17_sf_marshallOut, c17_sf_marshallIn);
      *c17_TempProblem = 1.0;
      c17_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c17_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_d_debug_family_names,
        c17_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_h_nargin, 0U, c17_sf_marshallOut,
        c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_h_nargout, 1U,
        c17_sf_marshallOut, c17_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_out, 2U, c17_b_sf_marshallOut,
        c17_b_sf_marshallIn);
      c17_e_out = CV_EML_IF(5, 0, 0, *(real_T *)((char_T *)c17_EngNFuel + 8) <=
                            2000.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c17_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c17_sfEvent);
        chartInstance->c17_tp_Heating = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
        chartInstance->c17_isStable = FALSE;
        chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_Normal;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
        chartInstance->c17_tp_Normal = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c17_debug_family_names,
          c17_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_i_nargin, 0U,
          c17_sf_marshallOut, c17_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_i_nargout, 1U,
          c17_sf_marshallOut, c17_sf_marshallIn);
        *c17_TempProblem = 0.0;
        c17_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c17_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_Normal:
    CV_CHART_EVAL(9, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c17_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c17_c_debug_family_names,
      c17_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_j_nargin, 0U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_j_nargout, 1U, c17_sf_marshallOut,
      c17_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_f_out, 2U, c17_b_sf_marshallOut,
      c17_b_sf_marshallIn);
    c17_f_out = CV_EML_IF(1, 0, 0, *(real_T *)((char_T *)c17_EngNFuel + 8) >
                          2000.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c17_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
      chartInstance->c17_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
      chartInstance->c17_isStable = FALSE;
      chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_Heating;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
      chartInstance->c17_temporalCounter_i1 = 0U;
      chartInstance->c17_tp_Heating = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c17_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c17_sfEvent);
    break;

   default:
    CV_CHART_EVAL(9, 0, 0);
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c17_sfEvent);
}

static void c17_exit_internal_c17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c17_is_c17_CockpitDisplayLib) {
   case c17_IN_Cooling:
    CV_CHART_EVAL(9, 0, 1);
    chartInstance->c17_tp_Cooling = 0U;
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_EngineFire:
    CV_CHART_EVAL(9, 0, 2);
    chartInstance->c17_tp_EngineFire = 0U;
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_Heating:
    CV_CHART_EVAL(9, 0, 3);
    chartInstance->c17_tp_Heating = 0U;
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c17_sfEvent);
    break;

   case c17_IN_Normal:
    CV_CHART_EVAL(9, 0, 4);
    chartInstance->c17_tp_Normal = 0U;
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c17_sfEvent);
    break;

   default:
    CV_CHART_EVAL(9, 0, 0);
    chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c17_sfEvent);
    break;
  }
}

static void c17_initc17_CockpitDisplayLib(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_doSetSimStateSideEffects = 0U;
  chartInstance->c17_setSimStateSideEffectsInfo = NULL;
  chartInstance->c17_tp_Cooling = 0U;
  chartInstance->c17_temporalCounter_i1 = 0U;
  chartInstance->c17_tp_EngineFire = 0U;
  chartInstance->c17_tp_Heating = 0U;
  chartInstance->c17_temporalCounter_i1 = 0U;
  chartInstance->c17_tp_Normal = 0U;
  chartInstance->c17_is_active_c17_CockpitDisplayLib = 0U;
  chartInstance->c17_is_c17_CockpitDisplayLib = c17_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc17_CockpitDisplayLib
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber)
{
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static real_T c17_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_nargout, const char_T *c17_identifier)
{
  real_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  return c17_y;
}

static real_T c17_b_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  boolean_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(boolean_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static boolean_T c17_c_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  boolean_T c17_y;
  boolean_T c17_b0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_b0, 1, 11, 0U, 0, 0U, 0);
  c17_y = c17_b0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_evilsf_internal_predicateOutput;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  boolean_T c17_y;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_evilsf_internal_predicateOutput = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_evilsf_internal_predicateOutput), &c17_thisId);
  sf_mex_destroy(&c17_evilsf_internal_predicateOutput);
  *(boolean_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c17_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  return chartInstance->c17_isStable;
}

void sf_exported_auto_duringc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  c17_c17_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c17_enter_atomic_c17_CockpitDisplayLib(chartInstance);
  c17_enter_internal_c17_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c17_exit_internal_c17_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c17_temporalCounter_i1 < 3U) {
    chartInstance->c17_temporalCounter_i1++;
  }
}

void sf_exported_auto_enablec17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c17_temporalCounter_i1 < 3U) {
    chartInstance->c17_temporalCounter_i1++;
  }
}

void sf_exported_auto_stepBuffersc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
}

void sf_exported_auto_initBuffersc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
}

void sf_exported_auto_activate_callc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  chartInstance->c17_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc17_CockpitDisplayLib(SimStruct
  *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
}

void sf_exported_auto_initc17_CockpitDisplayLib(SimStruct *c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  c17_initc17_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec17_CockpitDisplayLib(SimStruct
  *c17_S)
{
  const mxArray *c17_out = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  c17_out = NULL;
  sf_mex_assign(&c17_out, sf_internal_get_sim_state_c17_CockpitDisplayLib(c17_S),
                FALSE);
  return c17_out;
}

void sf_exported_auto_setSimstatec17_CockpitDisplayLib(SimStruct *c17_S, const
  mxArray *c17_in)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  sf_internal_set_sim_state_c17_CockpitDisplayLib(c17_S, sf_mex_dup(c17_in));
  sf_mex_destroy(&c17_in);
}

void sf_exported_auto_check_state_inconsistency_c17_CockpitDisplayLib(SimStruct *
  c17_S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c17_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static int32_T c17_d_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i0, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  uint8_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(uint8_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static uint8_T c17_e_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_b_tp_Normal, const char_T *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_tp_Normal),
    &c17_thisId);
  sf_mex_destroy(&c17_b_tp_Normal);
  return c17_y;
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_tp_Normal;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  uint8_T c17_y;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_b_tp_Normal = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_tp_Normal),
    &c17_thisId);
  sf_mex_destroy(&c17_b_tp_Normal);
  *(uint8_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_EngNFuel_bus_io(void *chartInstanceVoid, void
  *c17_pData)
{
  const mxArray *c17_mxVal = NULL;
  c17_EngineFuel_Bus c17_tmp;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxVal = NULL;
  c17_tmp.RPM = *(real_T *)((char_T *)c17_pData + 0);
  c17_tmp.temperature = *(real_T *)((char_T *)c17_pData + 8);
  c17_tmp.fuelpressure = *(real_T *)((char_T *)c17_pData + 16);
  c17_tmp.oilpressure = *(real_T *)((char_T *)c17_pData + 24);
  c17_tmp.EGT = *(real_T *)((char_T *)c17_pData + 32);
  c17_tmp.EPR1 = *(real_T *)((char_T *)c17_pData + 40);
  c17_tmp.EPR2 = *(real_T *)((char_T *)c17_pData + 48);
  c17_tmp.FuelQuantity = *(real_T *)((char_T *)c17_pData + 56);
  sf_mex_assign(&c17_mxVal, c17_e_sf_marshallOut(chartInstance, &c17_tmp), FALSE);
  return c17_mxVal;
}

static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  c17_EngineFuel_Bus c17_u;
  const mxArray *c17_y = NULL;
  real_T c17_b_u;
  const mxArray *c17_b_y = NULL;
  real_T c17_c_u;
  const mxArray *c17_c_y = NULL;
  real_T c17_d_u;
  const mxArray *c17_d_y = NULL;
  real_T c17_e_u;
  const mxArray *c17_e_y = NULL;
  real_T c17_f_u;
  const mxArray *c17_f_y = NULL;
  real_T c17_g_u;
  const mxArray *c17_g_y = NULL;
  real_T c17_h_u;
  const mxArray *c17_h_y = NULL;
  real_T c17_i_u;
  const mxArray *c17_i_y = NULL;
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(c17_EngineFuel_Bus *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c17_b_u = c17_u.RPM;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_b_y, "RPM", "RPM", 0);
  c17_c_u = c17_u.temperature;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_c_y, "temperature", "temperature", 0);
  c17_d_u = c17_u.fuelpressure;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_d_y, "fuelpressure", "fuelpressure", 0);
  c17_e_u = c17_u.oilpressure;
  c17_e_y = NULL;
  sf_mex_assign(&c17_e_y, sf_mex_create("y", &c17_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_e_y, "oilpressure", "oilpressure", 0);
  c17_f_u = c17_u.EGT;
  c17_f_y = NULL;
  sf_mex_assign(&c17_f_y, sf_mex_create("y", &c17_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_f_y, "EGT", "EGT", 0);
  c17_g_u = c17_u.EPR1;
  c17_g_y = NULL;
  sf_mex_assign(&c17_g_y, sf_mex_create("y", &c17_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_g_y, "EPR1", "EPR1", 0);
  c17_h_u = c17_u.EPR2;
  c17_h_y = NULL;
  sf_mex_assign(&c17_h_y, sf_mex_create("y", &c17_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_h_y, "EPR2", "EPR2", 0);
  c17_i_u = c17_u.FuelQuantity;
  c17_i_y = NULL;
  sf_mex_assign(&c17_i_y, sf_mex_create("y", &c17_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c17_y, c17_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static const mxArray *c17_g_emlrt_marshallIn
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c17_b_setSimStateSideEffectsInfo, const char_T *c17_identifier)
{
  const mxArray *c17_y = NULL;
  emlrtMsgIdentifier c17_thisId;
  c17_y = NULL;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  sf_mex_assign(&c17_y, c17_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_setSimStateSideEffectsInfo), &c17_thisId), FALSE);
  sf_mex_destroy(&c17_b_setSimStateSideEffectsInfo);
  return c17_y;
}

static const mxArray *c17_h_emlrt_marshallIn
  (SFc17_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c17_u,
   const emlrtMsgIdentifier *c17_parentId)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_duplicatearraysafe(&c17_u), FALSE);
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_updateDataWrittenToVector(SFc17_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c17_vectorIndex)
{
  c17_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c17_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static void init_dsm_address_info(SFc17_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
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

void sf_c17_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4062844980U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(436012338U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(994028370U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4173108135U);
}

mxArray *sf_c17_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("drqumRl6SabqoYXYurJV4");
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

mxArray *sf_c17_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[8],T\"TempProblem\",},{M[8],M[0],T\"is_active_c17_CockpitDisplayLib\",},{M[9],M[0],T\"is_c17_CockpitDisplayLib\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[14 13],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           17,
           4,
           7,
           2,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"TempProblem");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,29,1,29);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,0,41,0,41);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 41 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,0,41,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,0,40,0,40);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 40 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,0,40,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_EngNFuel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);

        {
          c17_EngineFuel_Bus *c17_EngNFuel;
          real_T *c17_TempProblem;
          c17_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c17_EngNFuel = (c17_EngineFuel_Bus *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c17_EngNFuel);
          _SFD_SET_DATA_VALUE_PTR(1U, c17_TempProblem);
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
  return "mvMe3DCpbcbBaSqi2sy4a";
}

static void sf_opaque_initialize_c17_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c17_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_CockpitDisplayLib
    ((SFc17_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c17_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c17_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c17_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_CockpitDisplayLib((SFc17_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c17_CockpitDisplayLib
      ((SFc17_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_CockpitDisplayLib(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,17,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1687571765U));
  ssSetChecksum1(S,(3340820740U));
  ssSetChecksum2(S,(1778090973U));
  ssSetChecksum3(S,(2521580013U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c17_CockpitDisplayLib(SimStruct *S)
{
  SFc17_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc17_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc17_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_CockpitDisplayLib;
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

void c17_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
