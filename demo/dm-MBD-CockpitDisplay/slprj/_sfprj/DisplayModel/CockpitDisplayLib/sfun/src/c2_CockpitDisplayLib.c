/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c2_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_FuelPressureLow          ((uint8_T)1U)
#define c2_IN_Normal                   ((uint8_T)2U)
#define c2_IN_FuelQuantityLow          ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "guard1", "guard2", "guard3",
  "nargin", "nargout", "y" };

static const char * c2_b_debug_family_names[6] = { "guard1", "guard2", "guard3",
  "nargin", "nargout", "y" };

static const char * c2_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c2_n_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c2_dataWrittenToVector[4];

/* Function Declarations */
static void initialize_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void initialize_params_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c2_enter_atomic_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void c2_enter_internal_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void c2_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c2_exit_internal_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void c2_initc2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void initSimStructsc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_c_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_funcFuelQuantityLowc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static real_T c2_funcFuelPressLowc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_FuelPressureModes, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_EngNFuel_bus_io(void *chartInstanceVoid, void *c2_pData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_h_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_updateDataWrittenToVector(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_vectorIndex);
static real_T c2_get_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b);
static void init_dsm_address_info(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void initialize_params_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void disable_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
}

static void c2_update_debugger_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_active_FuelPressureModes == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_FuelPressureModes == c2_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_FuelPressureModes == c2_IN_FuelPressureLow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_active_FuelQuantityModes == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_FuelQuantityModes == c2_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_FuelQuantityModes == c2_IN_FuelQuantityLow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_f_hoistedGlobal;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  uint8_T c2_g_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T *c2_FuelPProblem;
  real_T *c2_FuelQProblem;
  c2_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(7), FALSE);
  c2_hoistedGlobal = *c2_FuelPProblem;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_FuelQProblem;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_CockpitDisplayLib;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_FuelPressureModes;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_FuelQuantityModes;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_is_FuelPressureModes;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = chartInstance->c2_is_FuelQuantityModes;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_FuelPProblem;
  real_T *c2_FuelQProblem;
  c2_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_FuelPProblem = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "FuelPProblem");
  *c2_FuelQProblem = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "FuelQProblem");
  chartInstance->c2_is_active_c2_CockpitDisplayLib = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_CockpitDisplayLib");
  chartInstance->c2_is_active_FuelPressureModes = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_active_FuelPressureModes");
  chartInstance->c2_is_active_FuelQuantityModes = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_FuelQuantityModes");
  chartInstance->c2_is_FuelPressureModes = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "is_FuelPressureModes");
  chartInstance->c2_is_FuelQuantityModes = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 6)), "is_FuelQuantityModes");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 7)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_active_FuelPressureModes == 1U) {
      chartInstance->c2_tp_FuelPressureModes = 1U;
    } else {
      chartInstance->c2_tp_FuelPressureModes = 0U;
    }

    if (chartInstance->c2_is_FuelPressureModes == c2_IN_FuelPressureLow) {
      chartInstance->c2_tp_FuelPressureLow = 1U;
    } else {
      chartInstance->c2_tp_FuelPressureLow = 0U;
    }

    if (chartInstance->c2_is_FuelPressureModes == c2_IN_Normal) {
      chartInstance->c2_tp_Normal = 1U;
    } else {
      chartInstance->c2_tp_Normal = 0U;
    }

    if (chartInstance->c2_is_active_FuelQuantityModes == 1U) {
      chartInstance->c2_tp_FuelQuantityModes = 1U;
    } else {
      chartInstance->c2_tp_FuelQuantityModes = 0U;
    }

    if (chartInstance->c2_is_FuelQuantityModes == c2_IN_FuelQuantityLow) {
      chartInstance->c2_tp_FuelQuantityLow = 1U;
    } else {
      chartInstance->c2_tp_FuelQuantityLow = 0U;
    }

    if (chartInstance->c2_is_FuelQuantityModes == c2_IN_Normal) {
      chartInstance->c2_b_tp_Normal = 1U;
    } else {
      chartInstance->c2_b_tp_Normal = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c2_set_sim_state_side_effects_c2_CockpitDisplayLib(chartInstance);
}

static void c2_enter_atomic_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_active_c2_CockpitDisplayLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void c2_enter_internal_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T *c2_FuelPProblem;
  real_T *c2_FuelQProblem;
  c2_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = FALSE;
  chartInstance->c2_is_active_FuelPressureModes = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_FuelPressureModes = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = FALSE;
  chartInstance->c2_is_FuelPressureModes = c2_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *c2_FuelPProblem = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c2_isStable = FALSE;
  chartInstance->c2_is_active_FuelQuantityModes = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_FuelQuantityModes = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = FALSE;
  chartInstance->c2_is_FuelQuantityModes = c2_IN_Normal;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  chartInstance->c2_b_tp_Normal = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  *c2_FuelQProblem = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_c2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 1.0;
  boolean_T c2_c_out;
  real_T c2_f_nargin = 0.0;
  real_T c2_f_nargout = 0.0;
  real_T c2_g_nargin = 0.0;
  real_T c2_g_nargout = 1.0;
  boolean_T c2_d_out;
  real_T c2_h_nargin = 0.0;
  real_T c2_h_nargout = 0.0;
  real_T *c2_FuelPProblem;
  real_T *c2_FuelQProblem;
  c2_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_isStable = TRUE;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_FuelPressureModes) {
   case c2_IN_FuelPressureLow:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_h_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_out = CV_EML_IF(2, 0, 0, CV_EML_MCDC(2, 0, 0, !(CV_EML_COND(2, 0, 0,
      c2_funcFuelPressLowc2_CockpitDisplayLib(chartInstance) != 0.0) != 0.0)));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_FuelPressureLow = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = FALSE;
      chartInstance->c2_is_FuelPressureModes = c2_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_c_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *c2_FuelPProblem = 0.0;
      c2_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_Normal:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_g_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_b_out = (CV_EML_IF(1, 0, 0, c2_funcFuelPressLowc2_CockpitDisplayLib
                          (chartInstance) != 0.0) != 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = FALSE;
      chartInstance->c2_is_FuelPressureModes = c2_IN_FuelPressureLow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_FuelPressureLow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_d_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *c2_FuelPProblem = 1.0;
      c2_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c2_is_FuelPressureModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_FuelQuantityModes) {
   case c2_IN_FuelQuantityLow:
    CV_STATE_EVAL(3, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_i_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_c_out = CV_EML_IF(4, 0, 0, CV_EML_MCDC(4, 0, 0, !(CV_EML_COND(4, 0, 0,
      c2_funcFuelQuantityLowc2_CockpitDisplayLib(chartInstance) != 0.0) != 0.0)));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_FuelQuantityLow = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = FALSE;
      chartInstance->c2_is_FuelQuantityModes = c2_IN_Normal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_b_tp_Normal = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_e_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *c2_FuelQProblem = 0.0;
      c2_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_Normal:
    CV_STATE_EVAL(3, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_j_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_out, 2U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_d_out = (CV_EML_IF(5, 0, 0, c2_funcFuelQuantityLowc2_CockpitDisplayLib
                          (chartInstance) != 0.0) != 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_b_tp_Normal = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = FALSE;
      chartInstance->c2_is_FuelQuantityModes = c2_IN_FuelQuantityLow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_FuelQuantityLow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_f_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *c2_FuelQProblem = 1.0;
      c2_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 0, 0);
    chartInstance->c2_is_FuelQuantityModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void c2_exit_internal_c2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_FuelQuantityModes) {
   case c2_IN_FuelQuantityLow:
    CV_STATE_EVAL(3, 1, 1);
    chartInstance->c2_tp_FuelQuantityLow = 0U;
    chartInstance->c2_is_FuelQuantityModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_Normal:
    CV_STATE_EVAL(3, 1, 2);
    chartInstance->c2_b_tp_Normal = 0U;
    chartInstance->c2_is_FuelQuantityModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 1, 0);
    chartInstance->c2_is_FuelQuantityModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    break;
  }

  chartInstance->c2_tp_FuelQuantityModes = 0U;
  chartInstance->c2_is_active_FuelQuantityModes = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_FuelPressureModes) {
   case c2_IN_FuelPressureLow:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c2_tp_FuelPressureLow = 0U;
    chartInstance->c2_is_FuelPressureModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_Normal:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c2_tp_Normal = 0U;
    chartInstance->c2_is_FuelPressureModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c2_is_FuelPressureModes = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    break;
  }

  chartInstance->c2_tp_FuelPressureModes = 0U;
  chartInstance->c2_is_active_FuelPressureModes = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_initc2_CockpitDisplayLib(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_active_FuelPressureModes = 0U;
  chartInstance->c2_is_FuelPressureModes = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_FuelPressureModes = 0U;
  chartInstance->c2_tp_FuelPressureLow = 0U;
  chartInstance->c2_tp_Normal = 0U;
  chartInstance->c2_is_active_FuelQuantityModes = 0U;
  chartInstance->c2_is_FuelQuantityModes = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_FuelQuantityModes = 0U;
  chartInstance->c2_tp_FuelQuantityLow = 0U;
  chartInstance->c2_b_tp_Normal = 0U;
  chartInstance->c2_is_active_c2_CockpitDisplayLib = 0U;
}

static void initSimStructsc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier)
{
  real_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static boolean_T c2_c_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_guard3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_guard3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_guard3), &c2_thisId);
  sf_mex_destroy(&c2_guard3);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  return chartInstance->c2_isStable;
}

void sf_exported_auto_duringc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  c2_c2_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_enterc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c2_enter_atomic_c2_CockpitDisplayLib(chartInstance);
  c2_enter_internal_c2_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_exitc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c2_exit_internal_c2_CockpitDisplayLib(chartInstance);
}

void sf_exported_auto_gatewayc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_enablec2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_stepBuffersc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
}

void sf_exported_auto_initBuffersc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
}

void sf_exported_auto_activate_callc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  chartInstance->c2_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
}

void sf_exported_auto_initc2_CockpitDisplayLib(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  c2_initc2_CockpitDisplayLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec2_CockpitDisplayLib(SimStruct *c2_S)
{
  const mxArray *c2_out = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  c2_out = NULL;
  sf_mex_assign(&c2_out, sf_internal_get_sim_state_c2_CockpitDisplayLib(c2_S),
                FALSE);
  return c2_out;
}

void sf_exported_auto_setSimstatec2_CockpitDisplayLib(SimStruct *c2_S, const
  mxArray *c2_in)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  sf_internal_set_sim_state_c2_CockpitDisplayLib(c2_S, sf_mex_dup(c2_in));
  sf_mex_destroy(&c2_in);
}

void sf_exported_auto_check_state_inconsistency_c2_CockpitDisplayLib(SimStruct
  *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static real_T c2_funcFuelQuantityLowc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  real_T c2_y;
  boolean_T c2_guard1;
  boolean_T c2_guard2;
  boolean_T c2_guard3;
  boolean_T c2_evilsf_internal_predicateOutput;
  boolean_T c2_b_evilsf_internal_predicateOutput;
  boolean_T c2_c_evilsf_internal_predicateOutput;
  boolean_T c2_d_evilsf_internal_predicateOutput;
  c2_EngineFuel_Bus *c2_EngNFuel;
  c2_EngNFuel = (c2_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  c2_y = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 2U);
  c2_guard1 = FALSE;
  c2_guard2 = FALSE;
  c2_guard3 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c2_sfEvent);
  c2_evilsf_internal_predicateOutput = CV_EML_IF(23, 0, 0, c2_get_FlightMode
    (chartInstance, 0) == 1.0);
  if (c2_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                 chartInstance->c2_sfEvent);
    c2_b_evilsf_internal_predicateOutput = CV_EML_IF(24, 0, 0, *(real_T *)
      ((char_T *)c2_EngNFuel + 56) < 20000.0);
    if (c2_b_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
      c2_guard1 = TRUE;
    } else {
      c2_guard3 = TRUE;
    }
  } else {
    c2_guard3 = TRUE;
  }

  if (c2_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                 chartInstance->c2_sfEvent);
    c2_c_evilsf_internal_predicateOutput = CV_EML_IF(27, 0, 0, c2_get_FlightMode
      (chartInstance, 0) == 2.0);
    if (c2_c_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                   chartInstance->c2_sfEvent);
      c2_d_evilsf_internal_predicateOutput = CV_EML_IF(28, 0, 0, *(real_T *)
        ((char_T *)c2_EngNFuel + 56) < 10000.0);
      if (c2_d_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
        c2_guard1 = TRUE;
      } else {
        c2_guard2 = TRUE;
      }
    } else {
      c2_guard2 = TRUE;
    }
  }

  if (c2_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    c2_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  }

  if (c2_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
    c2_y = 1.0;
    c2_updateDataWrittenToVector(chartInstance, 2U);
  }

  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  return c2_y;
}

static real_T c2_funcFuelPressLowc2_CockpitDisplayLib
  (SFc2_CockpitDisplayLibInstanceStruct *chartInstance)
{
  real_T c2_y;
  boolean_T c2_guard1;
  boolean_T c2_guard2;
  boolean_T c2_guard3;
  boolean_T c2_evilsf_internal_predicateOutput;
  boolean_T c2_b_evilsf_internal_predicateOutput;
  boolean_T c2_c_evilsf_internal_predicateOutput;
  boolean_T c2_d_evilsf_internal_predicateOutput;
  boolean_T c2_e_evilsf_internal_predicateOutput;
  c2_EngineFuel_Bus *c2_EngNFuel;
  c2_EngNFuel = (c2_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  c2_y = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 3U);
  c2_guard1 = FALSE;
  c2_guard2 = FALSE;
  c2_guard3 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c2_sfEvent);
  c2_evilsf_internal_predicateOutput = CV_EML_IF(7, 0, 0, c2_get_FlightMode
    (chartInstance, 0) == 1.0);
  if (c2_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c2_sfEvent);
    c2_b_evilsf_internal_predicateOutput = CV_EML_IF(8, 0, 0, *(real_T *)
      ((char_T *)c2_EngNFuel + 16) < 5.0);
    if (c2_b_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
      c2_guard1 = TRUE;
    } else {
      c2_guard3 = TRUE;
    }
  } else {
    c2_guard3 = TRUE;
  }

  if (c2_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c2_sfEvent);
    c2_c_evilsf_internal_predicateOutput = CV_EML_IF(11, 0, 0, c2_get_FlightMode
      (chartInstance, 0) == 2.0);
    if (c2_c_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
      c2_guard2 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c2_sfEvent);
      c2_d_evilsf_internal_predicateOutput = CV_EML_IF(14, 0, 0,
        c2_get_FlightMode(chartInstance, 0) == 3.0);
      if (c2_d_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
        c2_guard2 = TRUE;
      }
    }
  }

  if (c2_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c2_sfEvent);
    c2_e_evilsf_internal_predicateOutput = CV_EML_IF(18, 0, 0, *(real_T *)
      ((char_T *)c2_EngNFuel + 16) < 15.0);
    if (c2_e_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
      c2_guard1 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
      c2_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    }
  }

  if (c2_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
    c2_y = 1.0;
    c2_updateDataWrittenToVector(chartInstance, 3U);
  }

  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
  return c2_y;
}

real_T sf_exported_user_c2_CockpitDisplayLib_funcFuelPressLow(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  return c2_funcFuelPressLowc2_CockpitDisplayLib(chartInstance);
}

real_T sf_exported_user_c2_CockpitDisplayLib_funcFuelQuantityLow(SimStruct *c2_S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c2_S))->chartInstance;
  return c2_funcFuelQuantityLowc2_CockpitDisplayLib(chartInstance);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_FuelPressureModes, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_tp_FuelPressureModes), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_FuelPressureModes);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_FuelPressureModes;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_b_tp_FuelPressureModes = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_tp_FuelPressureModes), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_FuelPressureModes);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_EngNFuel_bus_io(void *chartInstanceVoid, void *c2_pData)
{
  const mxArray *c2_mxVal = NULL;
  c2_EngineFuel_Bus c2_tmp;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxVal = NULL;
  c2_tmp.RPM = *(real_T *)((char_T *)c2_pData + 0);
  c2_tmp.temperature = *(real_T *)((char_T *)c2_pData + 8);
  c2_tmp.fuelpressure = *(real_T *)((char_T *)c2_pData + 16);
  c2_tmp.oilpressure = *(real_T *)((char_T *)c2_pData + 24);
  c2_tmp.EGT = *(real_T *)((char_T *)c2_pData + 32);
  c2_tmp.EPR1 = *(real_T *)((char_T *)c2_pData + 40);
  c2_tmp.EPR2 = *(real_T *)((char_T *)c2_pData + 48);
  c2_tmp.FuelQuantity = *(real_T *)((char_T *)c2_pData + 56);
  sf_mex_assign(&c2_mxVal, c2_e_sf_marshallOut(chartInstance, &c2_tmp), FALSE);
  return c2_mxVal;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_EngineFuel_Bus c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_EngineFuel_Bus *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c2_b_u = c2_u.RPM;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_b_y, "RPM", "RPM", 0);
  c2_c_u = c2_u.temperature;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_c_y, "temperature", "temperature", 0);
  c2_d_u = c2_u.fuelpressure;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_d_y, "fuelpressure", "fuelpressure", 0);
  c2_e_u = c2_u.oilpressure;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_e_y, "oilpressure", "oilpressure", 0);
  c2_f_u = c2_u.EGT;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_f_y, "EGT", "EGT", 0);
  c2_g_u = c2_u.EPR1;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_g_y, "EPR1", "EPR1", 0);
  c2_h_u = c2_u.EPR2;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_h_y, "EPR2", "EPR2", 0);
  c2_i_u = c2_u.FuelQuantity;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_updateDataWrittenToVector(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_vectorIndex)
{
  c2_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c2_vectorIndex, 0, 3, 1, 0)] = TRUE;
}

static real_T c2_get_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#526) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_FlightMode_address;
}

static void c2_set_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#526) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_FlightMode_address = c2_c;
}

static real_T *c2_access_FlightMode(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c2_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#526) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_FlightMode_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c2_c;
}

static void init_dsm_address_info(SFc2_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c2_FlightMode_address, &chartInstance->c2_FlightMode_index);
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

void sf_c2_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1943274357U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2743289647U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3110793975U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(991715132U);
}

mxArray *sf_c2_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5jAOQk4juO8aVBnsmzFU9F");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[66],T\"FuelPProblem\",},{M[1],M[67],T\"FuelQProblem\",},{M[8],M[0],T\"is_active_c2_CockpitDisplayLib\",},{M[8],M[2],T\"is_active_FuelPressureModes\",},{M[8],M[8],T\"is_active_FuelQuantityModes\",},{M[9],M[2],T\"is_FuelPressureModes\",},{M[9],M[8],T\"is_FuelQuantityModes\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           2,
           8,
           32,
           6,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"FuelPProblem");
          _SFD_SET_DATA_PROPS(2,2,0,1,"FuelQProblem");
          _SFD_SET_DATA_PROPS(3,11,0,0,"FlightMode");
          _SFD_SET_DATA_PROPS(4,9,0,0,"");
          _SFD_SET_DATA_PROPS(5,9,0,0,"");
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,20,1,20);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 20 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,20,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,23,1,23);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 23 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,23,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(22,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(25,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(29,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(9,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(12,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(15,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,25,1,25);
        _SFD_CV_INIT_EML(19,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_EngNFuel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));

        {
          c2_EngineFuel_Bus *c2_EngNFuel;
          real_T *c2_FuelPProblem;
          real_T *c2_FuelQProblem;
          c2_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_EngNFuel = (c2_EngineFuel_Bus *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_EngNFuel);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_FuelPProblem);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_FuelQProblem);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_FlightMode_address);
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
  return "jIlAUuERun6KqKxBRRYll";
}

static void sf_opaque_initialize_c2_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CockpitDisplayLib
    ((SFc2_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c2_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_CockpitDisplayLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c2_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c2_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CockpitDisplayLibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CockpitDisplayLib((SFc2_CockpitDisplayLibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3440833480U));
  ssSetChecksum1(S,(296501534U));
  ssSetChecksum2(S,(3391252623U));
  ssSetChecksum3(S,(1359626407U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_CockpitDisplayLib(SimStruct *S)
{
  SFc2_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc2_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc2_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_CockpitDisplayLib;
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

void c2_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
