/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c10_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c10_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c10_IN_EngineFire              ((uint8_T)1U)
#define c10_IN_Normal                  ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_c_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c10_d_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c10_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c10_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c10_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void initialize_params_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c10_update_debugger_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c10_st);
static void c10_set_sim_state_side_effects_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c10_enter_atomic_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void c10_enter_internal_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void c10_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c10_exit_internal_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void c10_initc10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void initSimStructsc10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_nargout, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static boolean_T c10_c_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_d_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static uint8_T c10_e_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_Normal, const char_T *c10_identifier);
static uint8_T c10_f_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_Misc_bus_io(void *chartInstanceVoid, void *c10_pData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_g_emlrt_marshallIn
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier);
static const mxArray *c10_h_emlrt_marshallIn
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c10_u,
   const emlrtMsgIdentifier *c10_parentId);
static void c10_updateDataWrittenToVector(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c10_vectorIndex);
static real_T c10_get_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
}

static void c10_update_debugger_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c10_prevAniVal;
  c10_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c10_is_active_c10_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_CockpitDisplayLib == c10_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_CockpitDisplayLib == c10_IN_EngineFire) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  }

  _SFD_SET_ANIMATION(c10_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  uint8_T c10_c_hoistedGlobal;
  uint8_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  real_T *c10_APUProblem;
  c10_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(3), FALSE);
  c10_hoistedGlobal = *c10_APUProblem;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_CockpitDisplayLib;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = chartInstance->c10_is_c10_CockpitDisplayLib;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_APUProblem;
  c10_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = sf_mex_dup(c10_st);
  *c10_APUProblem = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "APUProblem");
  chartInstance->c10_is_active_c10_CockpitDisplayLib = c10_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_CockpitDisplayLib");
  chartInstance->c10_is_c10_CockpitDisplayLib = c10_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
     "is_c10_CockpitDisplayLib");
  sf_mex_assign(&chartInstance->c10_setSimStateSideEffectsInfo,
                c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c10_u);
  chartInstance->c10_doSetSimStateSideEffects = 1U;
  c10_update_debugger_state_c10_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void c10_set_sim_state_side_effects_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c10_doSetSimStateSideEffects != 0) {
    if (chartInstance->c10_is_c10_CockpitDisplayLib == c10_IN_EngineFire) {
      chartInstance->c10_tp_EngineFire = 1U;
    } else {
      chartInstance->c10_tp_EngineFire = 0U;
    }

    if (chartInstance->c10_is_c10_CockpitDisplayLib == c10_IN_Normal) {
      chartInstance->c10_tp_Normal = 1U;
    } else {
      chartInstance->c10_tp_Normal = 0U;
    }

    chartInstance->c10_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c10_setSimStateSideEffectsInfo);
}

static void sf_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c10_set_sim_state_side_effects_c10_CockpitDisplayLib(chartInstance);
}

static void c10_enter_atomic_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
  chartInstance->c10_is_active_c10_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
}

static void c10_enter_internal_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  real_T *c10_APUProblem;
  c10_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  chartInstance->c10_isStable = FALSE;
  chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  chartInstance->c10_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  *c10_APUProblem = 0.0;
  c10_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  boolean_T c10_b0;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 0.0;
  real_T *c10_APUMode;
  real_T *c10_APUProblem;
  c10_MiscData *c10_Misc;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  boolean_T guard9 = FALSE;
  c10_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_Misc = (c10_MiscData *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_APUMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_isStable = TRUE;
  switch (chartInstance->c10_is_c10_CockpitDisplayLib) {
   case c10_IN_EngineFire:
    CV_CHART_EVAL(4, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_d_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    guard6 = FALSE;
    guard7 = FALSE;
    guard8 = FALSE;
    guard9 = FALSE;
    if (CV_EML_COND(2, 0, 0, c10_get_FlightMode(chartInstance, 0) == 0.0)) {
      if (CV_EML_COND(2, 0, 1, *c10_APUMode == 3.0)) {
        guard7 = TRUE;
      } else {
        guard9 = TRUE;
      }
    } else {
      guard9 = TRUE;
    }

    if (guard9 == TRUE) {
      if (CV_EML_COND(2, 0, 2, c10_get_FlightMode(chartInstance, 0) == 1.0)) {
        guard8 = TRUE;
      } else if (CV_EML_COND(2, 0, 3, c10_get_FlightMode(chartInstance, 0) ==
                             2.0)) {
        guard8 = TRUE;
      } else {
        guard6 = TRUE;
      }
    }

    if (guard8 == TRUE) {
      if (CV_EML_COND(2, 0, 4, *(real_T *)((char_T *)c10_Misc + 24) < 0.8)) {
        guard7 = TRUE;
      } else {
        guard6 = TRUE;
      }
    }

    if (guard7 == TRUE) {
      c10_b0 = TRUE;
    }

    if (guard6 == TRUE) {
      c10_b0 = FALSE;
    }

    c10_out = CV_EML_IF(2, 0, 0, CV_EML_MCDC(2, 0, 0, !c10_b0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_EngineFire = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = FALSE;
      chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
        c10_sf_marshallOut, c10_sf_marshallIn);
      *c10_APUProblem = 0.0;
      c10_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_Normal:
    CV_CHART_EVAL(4, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_c_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    guard1 = FALSE;
    guard2 = FALSE;
    guard3 = FALSE;
    guard4 = FALSE;
    guard5 = FALSE;
    if (CV_EML_COND(1, 0, 0, c10_get_FlightMode(chartInstance, 0) == 0.0)) {
      if (CV_EML_COND(1, 0, 1, *c10_APUMode == 3.0)) {
        guard2 = TRUE;
      } else {
        guard5 = TRUE;
      }
    } else {
      guard5 = TRUE;
    }

    if (guard5 == TRUE) {
      if (CV_EML_COND(1, 0, 2, c10_get_FlightMode(chartInstance, 0) == 1.0)) {
        if (CV_EML_COND(1, 0, 3, *(real_T *)((char_T *)c10_Misc + 24) < 0.5)) {
          guard3 = TRUE;
        } else {
          guard4 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }
    }

    if (guard4 == TRUE) {
      if (CV_EML_COND(1, 0, 4, c10_get_FlightMode(chartInstance, 0) == 2.0)) {
        if (CV_EML_COND(1, 0, 5, *(real_T *)((char_T *)c10_Misc + 24) < 0.8)) {
          guard3 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(1, 0, 0, TRUE);
      CV_EML_IF(1, 0, 0, TRUE);
      c10_b_out = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(1, 0, 0, FALSE);
      CV_EML_IF(1, 0, 0, FALSE);
      c10_b_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = FALSE;
      chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_EngineFire;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_EngineFire = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_b_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_sf_marshallOut, c10_sf_marshallIn);
      *c10_APUProblem = 1.0;
      c10_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
}

static void c10_exit_internal_c10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c10_is_c10_CockpitDisplayLib) {
   case c10_IN_EngineFire:
    CV_CHART_EVAL(4, 0, 1);
    chartInstance->c10_tp_EngineFire = 0U;
    chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_Normal:
    CV_CHART_EVAL(4, 0, 2);
    chartInstance->c10_tp_Normal = 0U;
    chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;
  }
}

static void c10_initc10_CockpitDisplayLib(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_doSetSimStateSideEffects = 0U;
  chartInstance->c10_setSimStateSideEffectsInfo = NULL;
  chartInstance->c10_tp_EngineFire = 0U;
  chartInstance->c10_tp_Normal = 0U;
  chartInstance->c10_is_active_c10_CockpitDisplayLib = 0U;
  chartInstance->c10_is_c10_CockpitDisplayLib = c10_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc10_CockpitDisplayLib
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_nargout, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  boolean_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(boolean_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static boolean_T c10_c_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  boolean_T c10_y;
  boolean_T c10_b1;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b1, 1, 11, 0U, 0, 0U, 0);
  c10_y = c10_b1;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_evilsf_internal_predicateOutput;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  boolean_T c10_y;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_evilsf_internal_predicateOutput = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_evilsf_internal_predicateOutput), &c10_thisId);
  sf_mex_destroy(&c10_evilsf_internal_predicateOutput);
  *(boolean_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c10_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  return chartInstance->c10_isStable;
}

void sf_exported_auto_duringc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  c10_c10_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c10_enter_atomic_c10_CockpitDisplayLib(chartInstance);
  c10_enter_internal_c10_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c10_exit_internal_c10_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
}

void sf_exported_auto_initBuffersc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
}

void sf_exported_auto_activate_callc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  chartInstance->c10_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc10_CockpitDisplayLib(SimStruct
  *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
}

void sf_exported_auto_initc10_CockpitDisplayLib(SimStruct *c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  c10_initc10_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec10_CockpitDisplayLib(SimStruct
  *c10_S)
{
  const mxArray *c10_out = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  c10_out = NULL;
  sf_mex_assign(&c10_out, sf_internal_get_sim_state_c10_CockpitDisplayLib(c10_S),
                FALSE);
  return c10_out;
}

void sf_exported_auto_setSimstatec10_CockpitDisplayLib(SimStruct *c10_S, const
  mxArray *c10_in)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  sf_internal_set_sim_state_c10_CockpitDisplayLib(c10_S, sf_mex_dup(c10_in));
  sf_mex_destroy(&c10_in);
}

void sf_exported_auto_check_state_inconsistency_c10_CockpitDisplayLib(SimStruct *
  c10_S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c10_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_d_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i0, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  uint8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(uint8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static uint8_T c10_e_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_Normal, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_Normal),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_Normal);
  return c10_y;
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_tp_Normal;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_b_tp_Normal = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_Normal),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_Normal);
  *(uint8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_Misc_bus_io(void *chartInstanceVoid, void *c10_pData)
{
  const mxArray *c10_mxVal = NULL;
  c10_MiscData c10_tmp;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxVal = NULL;
  c10_tmp.FlapPosition = *(real_T *)((char_T *)c10_pData + 0);
  c10_tmp.CabinPressure = *(real_T *)((char_T *)c10_pData + 8);
  c10_tmp.HydraulicPressure = *(real_T *)((char_T *)c10_pData + 16);
  c10_tmp.APUData = *(real_T *)((char_T *)c10_pData + 24);
  c10_tmp.LGLeftLock = *(boolean_T *)((char_T *)c10_pData + 32);
  c10_tmp.LGRightLock = *(boolean_T *)((char_T *)c10_pData + 33);
  sf_mex_assign(&c10_mxVal, c10_e_sf_marshallOut(chartInstance, &c10_tmp), FALSE);
  return c10_mxVal;
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  c10_MiscData c10_u;
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_d_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_e_u;
  const mxArray *c10_e_y = NULL;
  boolean_T c10_f_u;
  const mxArray *c10_f_y = NULL;
  boolean_T c10_g_u;
  const mxArray *c10_g_y = NULL;
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(c10_MiscData *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c10_b_u = c10_u.FlapPosition;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_b_y, "FlapPosition", "FlapPosition", 0);
  c10_c_u = c10_u.CabinPressure;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_c_y, "CabinPressure", "CabinPressure", 0);
  c10_d_u = c10_u.HydraulicPressure;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c10_e_u = c10_u.APUData;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_e_y, "APUData", "APUData", 0);
  c10_f_u = c10_u.LGLeftLock;
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_f_y, "LGLeftLock", "LGLeftLock", 0);
  c10_g_u = c10_u.LGRightLock;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", &c10_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c10_y, c10_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_g_emlrt_marshallIn
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier)
{
  const mxArray *c10_y = NULL;
  emlrtMsgIdentifier c10_thisId;
  c10_y = NULL;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  sf_mex_assign(&c10_y, c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_setSimStateSideEffectsInfo), &c10_thisId), FALSE);
  sf_mex_destroy(&c10_b_setSimStateSideEffectsInfo);
  return c10_y;
}

static const mxArray *c10_h_emlrt_marshallIn
  (SFc10_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c10_u,
   const emlrtMsgIdentifier *c10_parentId)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_duplicatearraysafe(&c10_u), FALSE);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_updateDataWrittenToVector(SFc10_CockpitDisplayLibInstanceStruct *
  chartInstance, uint32_T c10_vectorIndex)
{
  c10_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c10_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static real_T c10_get_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1042) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_FlightMode_address;
}

static void c10_set_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1042) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_FlightMode_address = c10_c;
}

static real_T *c10_access_FlightMode(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1042) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_FlightMode_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c10_FlightMode_address, &chartInstance->c10_FlightMode_index);
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

void sf_c10_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1325857807U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1945976778U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1310049034U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(789074463U);
}

mxArray *sf_c10_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gZJsOEUOtbqEgiMD5K1cCD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c10_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"APUProblem\",},{M[8],M[0],T\"is_active_c10_CockpitDisplayLib\",},{M[9],M[0],T\"is_c10_CockpitDisplayLib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           10,
           2,
           3,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"APUMode");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Misc");
          _SFD_SET_DATA_PROPS(2,11,0,0,"FlightMode");
          _SFD_SET_DATA_PROPS(3,2,0,1,"APUProblem");
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
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,6,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,122,1,52);

        {
          static int condStart[] = { 2, 21, 42, 61, 83, 102 };

          static int condEnd[] = { 17, 33, 57, 79, 98, 120 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, 4, 5, -3, -2, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,122,6,0,&(condStart[0]),&(condEnd[0]),11,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,102,1,52);

        {
          static int condStart[] = { 4, 23, 44, 62, 82 };

          static int condEnd[] = { 19, 35, 59, 77, 100 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, 4, -3, -2, -1 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,102,5,0,&(condStart[0]),&(condEnd[0]),10,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);

        {
          real_T *c10_APUMode;
          c10_MiscData *c10_Misc;
          real_T *c10_APUProblem;
          c10_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c10_Misc = (c10_MiscData *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_APUMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_APUMode);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_Misc);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_FlightMode_address);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_APUProblem);
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
  return "myeDCvYTHGgXDZUtF9JxqF";
}

static void sf_opaque_initialize_c10_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_CockpitDisplayLib
    ((SFc10_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c10_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c10_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c10_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_CockpitDisplayLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_CockpitDisplayLib((SFc10_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_CockpitDisplayLib
      ((SFc10_CockpitDisplayLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2733671536U));
  ssSetChecksum1(S,(3930881032U));
  ssSetChecksum2(S,(756622739U));
  ssSetChecksum3(S,(951819393U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c10_CockpitDisplayLib(SimStruct *S)
{
  SFc10_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc10_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc10_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_CockpitDisplayLib;
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

void c10_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
