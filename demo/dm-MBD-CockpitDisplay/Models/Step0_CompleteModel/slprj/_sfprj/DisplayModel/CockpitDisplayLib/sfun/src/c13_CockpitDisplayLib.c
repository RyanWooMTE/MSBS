/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c13_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c13_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c13_IN_Hyd                     ((uint8_T)1U)
#define c13_IN_EngineFire              ((uint8_T)1U)
#define c13_IN_Normal                  ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[2] = { "nargin", "nargout" };

static const char * c13_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c13_c_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c13_d_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c13_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c13_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c13_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c13_update_debugger_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c13_st);
static void c13_set_sim_state_side_effects_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c13_enter_atomic_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void c13_enter_internal_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void c13_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c13_exit_internal_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void c13_initc13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_nargout, const char_T *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static boolean_T c13_c_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_d_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static uint8_T c13_e_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_Hyd, const char_T *c13_identifier);
static uint8_T c13_f_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_Misc_bus_io(void *chartInstanceVoid, void *c13_pData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_g_emlrt_marshallIn
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c13_b_setSimStateSideEffectsInfo, const char_T *c13_identifier);
static const mxArray *c13_h_emlrt_marshallIn
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c13_u,
   const emlrtMsgIdentifier *c13_parentId);
static void c13_updateDataWrittenToVector(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c13_vectorIndex);
static real_T c13_get_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b);
static void c13_set_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b, real_T c13_c);
static real_T *c13_access_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b);
static void init_dsm_address_info(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c13_update_debugger_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c13_prevAniVal;
  c13_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c13_is_active_c13_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_c13_CockpitDisplayLib == c13_IN_Hyd) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_Hyd == c13_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_Hyd == c13_IN_EngineFire) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  }

  _SFD_SET_ANIMATION(c13_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  uint8_T c13_c_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  uint8_T c13_d_hoistedGlobal;
  uint8_T c13_d_u;
  const mxArray *c13_e_y = NULL;
  real_T *c13_HydProblem;
  c13_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(4), FALSE);
  c13_hoistedGlobal = *c13_HydProblem;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_is_active_c13_CockpitDisplayLib;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = chartInstance->c13_is_c13_CockpitDisplayLib;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = chartInstance->c13_is_Hyd;
  c13_d_u = c13_d_hoistedGlobal;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 3, c13_e_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T *c13_HydProblem;
  c13_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = sf_mex_dup(c13_st);
  *c13_HydProblem = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 0)), "HydProblem");
  chartInstance->c13_is_active_c13_CockpitDisplayLib = c13_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
     "is_active_c13_CockpitDisplayLib");
  chartInstance->c13_is_c13_CockpitDisplayLib = c13_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 2)),
     "is_c13_CockpitDisplayLib");
  chartInstance->c13_is_Hyd = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 3)), "is_Hyd");
  sf_mex_assign(&chartInstance->c13_setSimStateSideEffectsInfo,
                c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 4)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c13_u);
  chartInstance->c13_doSetSimStateSideEffects = 1U;
  c13_update_debugger_state_c13_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void c13_set_sim_state_side_effects_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c13_doSetSimStateSideEffects != 0) {
    if (chartInstance->c13_is_c13_CockpitDisplayLib == c13_IN_Hyd) {
      chartInstance->c13_tp_Hyd = 1U;
    } else {
      chartInstance->c13_tp_Hyd = 0U;
    }

    if (chartInstance->c13_is_Hyd == c13_IN_EngineFire) {
      chartInstance->c13_tp_EngineFire = 1U;
    } else {
      chartInstance->c13_tp_EngineFire = 0U;
    }

    if (chartInstance->c13_is_Hyd == c13_IN_Normal) {
      chartInstance->c13_tp_Normal = 1U;
    } else {
      chartInstance->c13_tp_Normal = 0U;
    }

    chartInstance->c13_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c13_setSimStateSideEffectsInfo);
}

static void sf_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c13_set_sim_state_side_effects_c13_CockpitDisplayLib(chartInstance);
}

static void c13_enter_atomic_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c13_sfEvent);
  chartInstance->c13_is_active_c13_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c13_sfEvent);
}

static void c13_enter_internal_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c13_debug_family_var_map[2];
  real_T c13_nargin = 0.0;
  real_T c13_nargout = 0.0;
  real_T *c13_HydProblem;
  c13_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c13_sfEvent);
  chartInstance->c13_isStable = FALSE;
  chartInstance->c13_is_c13_CockpitDisplayLib = c13_IN_Hyd;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  chartInstance->c13_tp_Hyd = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  chartInstance->c13_isStable = FALSE;
  chartInstance->c13_is_Hyd = c13_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
  chartInstance->c13_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  *c13_HydProblem = 0.0;
  c13_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_c13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c13_debug_family_var_map[3];
  real_T c13_nargin = 0.0;
  real_T c13_nargout = 1.0;
  boolean_T c13_out;
  boolean_T c13_b0;
  uint32_T c13_b_debug_family_var_map[2];
  real_T c13_b_nargin = 0.0;
  real_T c13_b_nargout = 0.0;
  real_T c13_c_nargin = 0.0;
  real_T c13_c_nargout = 1.0;
  boolean_T c13_b_out;
  boolean_T c13_b1;
  boolean_T c13_b2;
  boolean_T c13_b3;
  real_T c13_d_nargin = 0.0;
  real_T c13_d_nargout = 0.0;
  real_T *c13_HydProblem;
  c13_MiscData *c13_Misc;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  c13_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_Misc = (c13_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c13_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_isStable = TRUE;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  switch (chartInstance->c13_is_Hyd) {
   case c13_IN_EngineFire:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c13_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c13_c_debug_family_names,
      c13_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_out, 2U, c13_b_sf_marshallOut,
      c13_b_sf_marshallIn);
    guard4 = FALSE;
    guard5 = FALSE;
    guard6 = FALSE;
    guard7 = FALSE;
    if (CV_EML_COND(1, 0, 0, c13_get_FlightMode(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(1, 0, 1, *(real_T *)((char_T *)c13_Misc + 16) < 500.0)) {
        guard5 = TRUE;
      } else {
        guard7 = TRUE;
      }
    } else {
      guard7 = TRUE;
    }

    if (guard7 == TRUE) {
      if (CV_EML_COND(1, 0, 2, c13_get_FlightMode(chartInstance, 0) == 2.0)) {
        guard6 = TRUE;
      } else if (CV_EML_COND(1, 0, 3, c13_get_FlightMode(chartInstance, 0) ==
                             3.0)) {
        guard6 = TRUE;
      } else {
        guard4 = TRUE;
      }
    }

    if (guard6 == TRUE) {
      if (CV_EML_COND(1, 0, 4, *(real_T *)((char_T *)c13_Misc + 16) < 1500.0)) {
        guard5 = TRUE;
      } else {
        guard4 = TRUE;
      }
    }

    if (guard5 == TRUE) {
      c13_b0 = TRUE;
    }

    if (guard4 == TRUE) {
      c13_b0 = FALSE;
    }

    c13_out = CV_EML_IF(1, 0, 0, CV_EML_MCDC(1, 0, 0, !c13_b0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c13_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
      chartInstance->c13_tp_EngineFire = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
      chartInstance->c13_isStable = FALSE;
      chartInstance->c13_is_Hyd = c13_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
      chartInstance->c13_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c13_debug_family_names,
        c13_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_nargin, 0U, c13_sf_marshallOut,
        c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_nargout, 1U,
        c13_sf_marshallOut, c13_sf_marshallIn);
      *c13_HydProblem = 0.0;
      c13_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c13_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c13_sfEvent);
    break;

   case c13_IN_Normal:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c13_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c13_d_debug_family_names,
      c13_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_c_nargin, 0U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_c_nargout, 1U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_out, 2U, c13_b_sf_marshallOut,
      c13_b_sf_marshallIn);
    guard1 = FALSE;
    guard2 = FALSE;
    if (CV_EML_COND(2, 0, 0, c13_get_FlightMode(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(2, 0, 1, *(real_T *)((char_T *)c13_Misc + 16) < 500.0)) {
        guard1 = TRUE;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      guard3 = FALSE;
      if (c13_get_FlightMode(chartInstance, 0) == 2.0) {
        guard3 = TRUE;
      } else if (c13_get_FlightMode(chartInstance, 0) == 3.0) {
        guard3 = TRUE;
      } else {
        c13_b1 = FALSE;
      }

      if (guard3 == TRUE) {
        c13_b1 = TRUE;
      }

      c13_b2 = c13_b1;
      c13_b3 = (*(real_T *)((char_T *)c13_Misc + 16) < 1500.0);
      if (CV_EML_COND(2, 0, 2, c13_b2 && c13_b3)) {
        guard1 = TRUE;
      } else {
        CV_EML_MCDC(2, 0, 0, FALSE);
        CV_EML_IF(2, 0, 0, FALSE);
        c13_b_out = FALSE;
      }
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(2, 0, 0, TRUE);
      CV_EML_IF(2, 0, 0, TRUE);
      c13_b_out = TRUE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c13_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
      chartInstance->c13_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
      chartInstance->c13_isStable = FALSE;
      chartInstance->c13_is_Hyd = c13_IN_EngineFire;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
      chartInstance->c13_tp_EngineFire = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c13_b_debug_family_names,
        c13_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_d_nargin, 0U, c13_sf_marshallOut,
        c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_d_nargout, 1U,
        c13_sf_marshallOut, c13_sf_marshallIn);
      *c13_HydProblem = 1.0;
      c13_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c13_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c13_is_Hyd = c13_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c13_sfEvent);
}

static void c13_exit_internal_c13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c13_is_Hyd) {
   case c13_IN_EngineFire:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c13_tp_EngineFire = 0U;
    chartInstance->c13_is_Hyd = c13_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
    break;

   case c13_IN_Normal:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c13_tp_Normal = 0U;
    chartInstance->c13_is_Hyd = c13_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c13_is_Hyd = c13_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
    break;
  }

  chartInstance->c13_tp_Hyd = 0U;
  chartInstance->c13_is_c13_CockpitDisplayLib = c13_IN_NO_ACTIVE_CHILD;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
}

static void c13_initc13_CockpitDisplayLib(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_doSetSimStateSideEffects = 0U;
  chartInstance->c13_setSimStateSideEffectsInfo = NULL;
  chartInstance->c13_is_Hyd = c13_IN_NO_ACTIVE_CHILD;
  chartInstance->c13_tp_Hyd = 0U;
  chartInstance->c13_tp_EngineFire = 0U;
  chartInstance->c13_tp_Normal = 0U;
  chartInstance->c13_is_active_c13_CockpitDisplayLib = 0U;
  chartInstance->c13_is_c13_CockpitDisplayLib = c13_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc13_CockpitDisplayLib
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_nargout, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static boolean_T c13_c_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  boolean_T c13_y;
  boolean_T c13_b4;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_b4, 1, 11, 0U, 0, 0U, 0);
  c13_y = c13_b4;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_evilsf_internal_predicateOutput;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  boolean_T c13_y;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_evilsf_internal_predicateOutput = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_evilsf_internal_predicateOutput), &c13_thisId);
  sf_mex_destroy(&c13_evilsf_internal_predicateOutput);
  *(boolean_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c13_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  return chartInstance->c13_isStable;
}

void sf_exported_auto_duringc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  c13_c13_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c13_enter_atomic_c13_CockpitDisplayLib(chartInstance);
  c13_enter_internal_c13_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c13_exit_internal_c13_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
}

void sf_exported_auto_initBuffersc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
}

void sf_exported_auto_activate_callc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  chartInstance->c13_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc13_CockpitDisplayLib(SimStruct
  *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
}

void sf_exported_auto_initc13_CockpitDisplayLib(SimStruct *c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  c13_initc13_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec13_CockpitDisplayLib(SimStruct
  *c13_S)
{
  const mxArray *c13_out = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  c13_out = NULL;
  sf_mex_assign(&c13_out, sf_internal_get_sim_state_c13_CockpitDisplayLib(c13_S),
                FALSE);
  return c13_out;
}

void sf_exported_auto_setSimstatec13_CockpitDisplayLib(SimStruct *c13_S, const
  mxArray *c13_in)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  sf_internal_set_sim_state_c13_CockpitDisplayLib(c13_S, sf_mex_dup(c13_in));
  sf_mex_destroy(&c13_in);
}

void sf_exported_auto_check_state_inconsistency_c13_CockpitDisplayLib(SimStruct *
  c13_S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c13_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_d_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  uint8_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint8_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_Hyd, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_Hyd),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_Hyd);
  return c13_y;
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_tp_Hyd;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  uint8_T c13_y;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_b_tp_Hyd = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_Hyd),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_Hyd);
  *(uint8_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_Misc_bus_io(void *chartInstanceVoid, void *c13_pData)
{
  const mxArray *c13_mxVal = NULL;
  c13_MiscData c13_tmp;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxVal = NULL;
  c13_tmp.FlapPosition = *(real_T *)((char_T *)c13_pData + 0);
  c13_tmp.CabinPressure = *(real_T *)((char_T *)c13_pData + 8);
  c13_tmp.HydraulicPressure = *(real_T *)((char_T *)c13_pData + 16);
  c13_tmp.APUData = *(real_T *)((char_T *)c13_pData + 24);
  c13_tmp.LGLeftLock = *(boolean_T *)((char_T *)c13_pData + 32);
  c13_tmp.LGRightLock = *(boolean_T *)((char_T *)c13_pData + 33);
  sf_mex_assign(&c13_mxVal, c13_e_sf_marshallOut(chartInstance, &c13_tmp), FALSE);
  return c13_mxVal;
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  c13_MiscData c13_u;
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_e_u;
  const mxArray *c13_e_y = NULL;
  boolean_T c13_f_u;
  const mxArray *c13_f_y = NULL;
  boolean_T c13_g_u;
  const mxArray *c13_g_y = NULL;
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(c13_MiscData *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c13_b_u = c13_u.FlapPosition;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_b_y, "FlapPosition", "FlapPosition", 0);
  c13_c_u = c13_u.CabinPressure;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_c_y, "CabinPressure", "CabinPressure", 0);
  c13_d_u = c13_u.HydraulicPressure;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c13_e_u = c13_u.APUData;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_e_y, "APUData", "APUData", 0);
  c13_f_u = c13_u.LGLeftLock;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_f_y, "LGLeftLock", "LGLeftLock", 0);
  c13_g_u = c13_u.LGRightLock;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c13_y, c13_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static const mxArray *c13_g_emlrt_marshallIn
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c13_b_setSimStateSideEffectsInfo, const char_T *c13_identifier)
{
  const mxArray *c13_y = NULL;
  emlrtMsgIdentifier c13_thisId;
  c13_y = NULL;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  sf_mex_assign(&c13_y, c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_setSimStateSideEffectsInfo), &c13_thisId), FALSE);
  sf_mex_destroy(&c13_b_setSimStateSideEffectsInfo);
  return c13_y;
}

static const mxArray *c13_h_emlrt_marshallIn
  (SFc13_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c13_u,
   const emlrtMsgIdentifier *c13_parentId)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_duplicatearraysafe(&c13_u), FALSE);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_updateDataWrittenToVector(SFc13_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c13_vectorIndex)
{
  c13_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c13_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static real_T c13_get_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c13_b);
  if (chartInstance->c13_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1064) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c13_FlightMode_address;
}

static void c13_set_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b, real_T c13_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c13_b);
  if (chartInstance->c13_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1064) in the initialization routine of the chart.\n");
  }

  *chartInstance->c13_FlightMode_address = c13_c;
}

static real_T *c13_access_FlightMode(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c13_b)
{
  real_T *c13_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c13_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1064) in the initialization routine of the chart.\n");
  }

  c13_c = chartInstance->c13_FlightMode_address;
  if (c13_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c13_c;
}

static void init_dsm_address_info(SFc13_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c13_FlightMode_address, &chartInstance->c13_FlightMode_index);
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

void sf_c13_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2659076720U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3836012483U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1779819607U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(964105314U);
}

mxArray *sf_c13_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xE9GjW6QHKjATtJnr1iNhH");
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

mxArray *sf_c13_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"HydProblem\",},{M[8],M[0],T\"is_active_c13_CockpitDisplayLib\",},{M[9],M[0],T\"is_c13_CockpitDisplayLib\",},{M[9],M[1],T\"is_Hyd\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           13,
           3,
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
          _SFD_SET_DATA_PROPS(2,2,0,1,"HydProblem");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,128,1,52);

        {
          static int condStart[] = { 4, 23, 61, 78, 97 };

          static int condEnd[] = { 19, 51, 76, 93, 126 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, 4, -3, -2, -1 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,128,5,0,&(condStart[0]),&(condEnd[0]),10,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,129,1,52);

        {
          static int condStart[] = { 2, 21, 58 };

          static int condEnd[] = { 17, 49, 128 };

          static int pfixExpr[] = { 0, 1, -3, 2, -2 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,129,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);

        {
          c13_MiscData *c13_Misc;
          real_T *c13_HydProblem;
          c13_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_Misc = (c13_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_Misc);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c13_FlightMode_address);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_HydProblem);
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
  return "iPTVwMnyHmZh7eYYogrSEF";
}

static void sf_opaque_initialize_c13_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_CockpitDisplayLib
    ((SFc13_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c13_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c13_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c13_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_CockpitDisplayLib((SFc13_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_CockpitDisplayLib
      ((SFc13_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(251268491U));
  ssSetChecksum1(S,(840372238U));
  ssSetChecksum2(S,(515502744U));
  ssSetChecksum3(S,(1568378976U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c13_CockpitDisplayLib(SimStruct *S)
{
  SFc13_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc13_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc13_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_CockpitDisplayLib;
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

void c13_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
