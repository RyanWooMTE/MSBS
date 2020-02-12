/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DisplayModel_sfun.h"
#include "c1_DisplayModel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DisplayModel_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Screen                   ((uint8_T)1U)
#define c1_IN_one                      ((uint8_T)1U)
#define c1_IN_three                    ((uint8_T)2U)
#define c1_IN_two                      ((uint8_T)3U)
#define c1_IN_zero                     ((uint8_T)4U)
#define c1_const_diff_max              (3.0)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "num" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_v_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_w_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_x_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ab_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_bb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_db_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_eb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[11];

/* Function Declarations */
static void initialize_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void initialize_params_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void enable_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void disable_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance);
static void set_sim_state_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance);
static void finalize_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void sf_c1_DisplayModel(SFc1_DisplayModelInstanceStruct *chartInstance);
static void initSimStructsc1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void c1_enter_internal_Screen(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void c1_enter_internal_three(SFc1_DisplayModelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_num, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_aVarTruthTableCondition_3, const char_T
  *c1_identifier);
static boolean_T c1_d_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(uint32_T c1_u);
static real_T c1_valid_sensors(SFc1_DisplayModelInstanceStruct *chartInstance);
static void c1_none(SFc1_DisplayModelInstanceStruct *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_Screen, const char_T *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_b_select, const char_T *c1_identifier, real_T c1_y[2]);
static void c1_i_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_k_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_DisplayModelInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn(SFc1_DisplayModelInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber);
static void init_dsm_address_info(SFc1_DisplayModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Screen = 0U;
  chartInstance->c1_tp_one = 0U;
  chartInstance->c1_tp_three = 0U;
  chartInstance->c1_tp_two = 0U;
  chartInstance->c1_tp_zero = 0U;
  chartInstance->c1_is_active_c1_DisplayModel = 0U;
  chartInstance->c1_is_c1_DisplayModel = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_diff_max = 3.0;
}

static void initialize_params_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
}

static void enable_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_DisplayModel == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_DisplayModel == c1_IN_Screen) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_three) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_zero) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_one) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_two) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  boolean_T c1_h_hoistedGlobal;
  boolean_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i0;
  real_T c1_i_u[2];
  const mxArray *c1_j_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  uint8_T c1_k_hoistedGlobal;
  uint8_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_l_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  boolean_T *c1_valid_signal;
  c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(13), FALSE);
  c1_hoistedGlobal = *c1_valid_signal;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_bad;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_count;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_diff;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_mean;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_middle;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_n;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_prev_signal;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_i_u[c1_i0] = chartInstance->c1_select[c1_i0];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_i_hoistedGlobal = chartInstance->c1_sum_sig;
  c1_j_u = c1_i_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_active_c1_DisplayModel;
  c1_k_u = c1_j_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_k_hoistedGlobal = chartInstance->c1_is_c1_DisplayModel;
  c1_l_u = c1_k_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_l_hoistedGlobal = chartInstance->c1_is_Screen;
  c1_m_u = c1_l_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[2];
  int32_T c1_i1;
  boolean_T *c1_valid_signal;
  c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_valid_signal = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "valid_signal");
  chartInstance->c1_bad = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "bad");
  chartInstance->c1_count = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "count");
  chartInstance->c1_diff = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "diff");
  chartInstance->c1_mean = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "mean");
  chartInstance->c1_middle = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "middle");
  chartInstance->c1_n = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "n");
  chartInstance->c1_prev_signal = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 7)), "prev_signal");
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
                        "select", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    chartInstance->c1_select[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_sum_sig = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "sum_sig");
  chartInstance->c1_is_active_c1_DisplayModel = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
     "is_active_c1_DisplayModel");
  chartInstance->c1_is_c1_DisplayModel = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 11)), "is_c1_DisplayModel");
  chartInstance->c1_is_Screen = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "is_Screen");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 13)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_DisplayModel(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_DisplayModel
  (SFc1_DisplayModelInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_DisplayModel == c1_IN_Screen) {
      chartInstance->c1_tp_Screen = 1U;
    } else {
      chartInstance->c1_tp_Screen = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_one) {
      chartInstance->c1_tp_one = 1U;
    } else {
      chartInstance->c1_tp_one = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_three) {
      chartInstance->c1_tp_three = 1U;
    } else {
      chartInstance->c1_tp_three = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_two) {
      chartInstance->c1_tp_two = 1U;
    } else {
      chartInstance->c1_tp_two = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_zero) {
      chartInstance->c1_tp_zero = 1U;
    } else {
      chartInstance->c1_tp_zero = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_DisplayModel(SFc1_DisplayModelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  c1_set_sim_state_side_effects_c1_DisplayModel(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_DisplayModel == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_DisplayModel = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_y_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    chartInstance->c1_bad = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    chartInstance->c1_count = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    chartInstance->c1_prev_signal = FALSE;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_is_c1_DisplayModel = c1_IN_Screen;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Screen = 1U;
    c1_enter_internal_Screen(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_Screen) {
     case c1_IN_one:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_one = 0U;
      chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      c1_enter_internal_Screen(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_three:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_three = 0U;
      chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      c1_enter_internal_Screen(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_two:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_two = 0U;
      chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      c1_enter_internal_Screen(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_zero:
      CV_STATE_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_zero = 0U;
      chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      c1_enter_internal_Screen(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DisplayModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_DisplayModel(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
}

static void c1_enter_internal_Screen(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 0.0;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 0.0;
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 0.0;
  real_T c1_q_nargin = 0.0;
  real_T c1_q_nargout = 0.0;
  real_T c1_r_nargin = 0.0;
  real_T c1_r_nargout = 0.0;
  boolean_T *c1_valid_signal;
  boolean_T (*c1_signals)[3];
  c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_signals = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_u_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  chartInstance->c1_n = c1_valid_sensors(chartInstance);
  c1_updateDataWrittenToVector(chartInstance, 5U);
  chartInstance->c1_bad = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_v_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
  c1_out = CV_EML_IF(32, 0, 0, chartInstance->c1_n == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[3];
      unsigned int numTransitions = 1;
      transitionList[0] = 32;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_db_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
      c1_b_out = (chartInstance->c1_n == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 18;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
      c1_c_out = (chartInstance->c1_n == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 17;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_Screen = c1_IN_three;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_three = 1U;
    c1_enter_internal_three(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_w_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
    c1_d_out = CV_EML_IF(18, 0, 0, chartInstance->c1_n == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 18;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
        c1_e_out = (chartInstance->c1_n == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_e_out) {
          transitionList[numTransitions] = 17;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Screen = c1_IN_two;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_two = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_n_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 9U);
      c1_x = (real_T)(*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, (int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #1551 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
        "Signals/Chart (MATLAB)\' (#1516): {diff=abs(signals(select(1))-signals(select(2)));}\n                                            "
        "                                                                                                                               ^"
        "^^^^^^", (int32_T)_SFD_INTEGER_CHECK(
        "Transition #1551 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
        "Signals/Chart (MATLAB)\' (#1516): {diff=abs(signals(select(1))-signals(select(2)));}\n                                            "
        "                                                                                                                                "
        "       ^^^^^^^^^", chartInstance->c1_select[0]), 1, 3, 1, 0) - 1, 1, 3,
        1, 0)] - (real_T)(*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, (int32_T)
        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #1551 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
        "Signals/Chart (MATLAB)\' (#1516): {diff=abs(signals(select(1))-signals(select(2)));}\n                                            "
        "                                                                                                                                "
        "                  ^^^^^^^", (int32_T)_SFD_INTEGER_CHECK(
        "Transition #1551 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
        "Signals/Chart (MATLAB)\' (#1516): {diff=abs(signals(select(1))-signals(select(2)));}\n                                            "
        "                                                                                                                                "
        "                          ^^^^^^^^^", chartInstance->c1_select[1]), 1,
        3, 1, 0) - 1, 1, 3, 1, 0)];
      c1_b_x = c1_x;
      chartInstance->c1_diff = muDoubleScalarAbs(c1_b_x);
      c1_updateDataWrittenToVector(chartInstance, 6U);
      c1_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_o_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 8U, 11U);
      c1_f_out = CV_EML_IF(10, 0, 0, chartInstance->c1_diff > c1_const_diff_max);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_p_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_none(chartInstance);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_q_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 9U);
        c1_A = (real_T)(*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, (int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #1554 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {mean=(signals(select(1))+signals(select(2)))/2;}\n                                             "
          "                                                                                                                           ^^^^^"
          "^^", (int32_T)_SFD_INTEGER_CHECK(
          "Transition #1554 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {mean=(signals(select(1))+signals(select(2)))/2;}\n                                             "
          "                                                                                                                                "
          "   ^^^^^^^^^", chartInstance->c1_select[0]), 1, 3, 1, 0) - 1, 1, 3, 1,
          0)] + (real_T)(*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, (int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #1554 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {mean=(signals(select(1))+signals(select(2)))/2;}\n                                             "
          "                                                                                                                                "
          "              ^^^^^^^", (int32_T)_SFD_INTEGER_CHECK(
          "Transition #1554 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {mean=(signals(select(1))+signals(select(2)))/2;}\n                                             "
          "                                                                                                                                "
          "                      ^^^^^^^^^", chartInstance->c1_select[1]), 1, 3,
          1, 0) - 1, 1, 3, 1, 0)];
        c1_c_x = c1_A;
        c1_d_x = c1_c_x;
        chartInstance->c1_mean = c1_d_x / 2.0;
        c1_updateDataWrittenToVector(chartInstance, 6U);
        c1_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_r_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 12U);
        *c1_valid_signal = (chartInstance->c1_mean != 0.0);
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_s_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U);
        chartInstance->c1_prev_signal = *c1_valid_signal;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_t_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        chartInstance->c1_count = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_x_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 8U);
      c1_g_out = CV_EML_IF(17, 0, 0, chartInstance->c1_n == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Screen = c1_IN_one;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_one = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 9U);
        *c1_valid_signal = (*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, (int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #1542 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {valid_signal=signals(select(1));}\n                                                            "
          "                                                                                                                   ^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "Transition #1542 in Chart \'Control_and_Display_Logic/SignalConditioning/SignalSelection/DataValidityLandingGearRightLock/Screen "
          "Signals/Chart (MATLAB)\' (#1516): {valid_signal=signals(select(1));}\n                                                            "
          "                                                                                                                           ^^^^^"
          "^^^^", chartInstance->c1_select[0]), 1, 3, 1, 0) - 1, 1, 3, 1, 0)];
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_l_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U);
        chartInstance->c1_prev_signal = *c1_valid_signal;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_m_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        chartInstance->c1_count = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Screen = c1_IN_zero;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_zero = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_j_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_none(chartInstance);
        _SFD_SYMBOL_SCOPE_POP();
      }
    }
  }
}

static void c1_enter_internal_three(SFc1_DisplayModelInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  boolean_T c1_mtmp;
  int32_T c1_ix;
  int32_T c1_b_ix;
  boolean_T c1_a;
  boolean_T c1_b;
  boolean_T c1_p;
  boolean_T c1_b_mtmp;
  boolean_T c1_maxval;
  boolean_T c1_c_mtmp;
  int32_T c1_c_ix;
  int32_T c1_d_ix;
  boolean_T c1_b_a;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_d_mtmp;
  boolean_T c1_minval;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  boolean_T *c1_valid_signal;
  boolean_T (*c1_signals)[3];
  c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_signals = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  chartInstance->c1_sum_sig = ((real_T)(*c1_signals)[0] + (real_T)(*c1_signals)
    [1]) + (real_T)(*c1_signals)[2];
  c1_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 4U, 7U);
  c1_hoistedGlobal = chartInstance->c1_sum_sig;
  c1_mtmp = (*c1_signals)[0];
  for (c1_ix = 2; c1_ix < 4; c1_ix++) {
    c1_b_ix = c1_ix;
    c1_a = (*c1_signals)[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
    c1_b = c1_mtmp;
    c1_p = ((int32_T)c1_a > (int32_T)c1_b);
    if (c1_p) {
      c1_mtmp = (*c1_signals)[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
    }
  }

  c1_b_mtmp = c1_mtmp;
  c1_maxval = c1_b_mtmp;
  c1_c_mtmp = (*c1_signals)[0];
  for (c1_c_ix = 2; c1_c_ix < 4; c1_c_ix++) {
    c1_d_ix = c1_c_ix;
    c1_b_a = (*c1_signals)[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_d_ix), 1, 3, 1, 0) - 1];
    c1_b_b = c1_c_mtmp;
    c1_b_p = ((int32_T)c1_b_a < (int32_T)c1_b_b);
    if (c1_b_p) {
      c1_c_mtmp = (*c1_signals)[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_d_ix), 1, 3, 1, 0) - 1];
    }
  }

  c1_d_mtmp = c1_c_mtmp;
  c1_minval = c1_d_mtmp;
  chartInstance->c1_middle = c1_hoistedGlobal - ((real_T)c1_maxval + (real_T)
    c1_minval);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_e_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
  c1_out = CV_EML_IF(24, 0, 0, chartInstance->c1_bad == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_f_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_none(chartInstance);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_g_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 10U);
    *c1_valid_signal = (chartInstance->c1_middle != 0.0);
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_h_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U);
    chartInstance->c1_prev_signal = *c1_valid_signal;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_i_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    chartInstance->c1_count = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  }
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_num, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_num), &c1_thisId);
  sf_mex_destroy(&c1_num);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_num;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_num = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_num), &c1_thisId);
  sf_mex_destroy(&c1_num);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_aVarTruthTableCondition_3, const char_T
  *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_3), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_3);
  return c1_y;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_aVarTruthTableCondition_3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_aVarTruthTableCondition_3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_3), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_3);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DisplayModel_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 23, 1),
                FALSE);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("max"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1311233716U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688670U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797096U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688658U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797178U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1346488740U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmax"), "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_relop"), "name", "name",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1342429582U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("min"), "name", "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1311233718U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688670U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1373284908U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1319708366U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688666U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
}

static const mxArray *c1_emlrt_marshallOut(char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), FALSE);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c1_y;
}

static real_T c1_valid_sensors(SFc1_DisplayModelInstanceStruct *chartInstance)
{
  real_T c1_num;
  uint32_T c1_debug_family_var_map[6];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  real_T (*c1_validity)[3];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  boolean_T guard9 = FALSE;
  boolean_T guard10 = FALSE;
  boolean_T guard11 = FALSE;
  boolean_T guard12 = FALSE;
  boolean_T guard13 = FALSE;
  boolean_T guard14 = FALSE;
  c1_validity = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_num, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = FALSE;
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = FALSE;
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = FALSE;
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_1 = ((*c1_validity)[0] == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 12);
  c1_aVarTruthTableCondition_2 = ((*c1_validity)[1] == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_3 = ((*c1_validity)[2] == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 17);
  guard1 = FALSE;
  guard2 = FALSE;
  if (CV_EML_COND(6, 1, 0, c1_aVarTruthTableCondition_1)) {
    if (CV_EML_COND(6, 1, 1, c1_aVarTruthTableCondition_2)) {
      if (CV_EML_COND(6, 1, 2, c1_aVarTruthTableCondition_3)) {
        CV_EML_MCDC(6, 1, 0, TRUE);
        CV_EML_IF(6, 1, 0, TRUE);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 18);
        CV_EML_FCN(6, 1);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 39);
        c1_num = 3.0;
        c1_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -39);
      } else {
        guard1 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(6, 1, 0, FALSE);
    CV_EML_IF(6, 1, 0, FALSE);
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 19);
    guard3 = FALSE;
    guard4 = FALSE;
    if (CV_EML_COND(6, 1, 3, c1_aVarTruthTableCondition_1)) {
      if (CV_EML_COND(6, 1, 4, c1_aVarTruthTableCondition_2)) {
        if (!CV_EML_COND(6, 1, 5, c1_aVarTruthTableCondition_3)) {
          CV_EML_MCDC(6, 1, 1, TRUE);
          CV_EML_IF(6, 1, 1, TRUE);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 20);
          CV_EML_FCN(6, 2);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 45);
          c1_num = 2.0;
          c1_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 46);
          chartInstance->c1_select[0] = 1.0;
          c1_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 47);
          chartInstance->c1_select[1] = 2.0;
          c1_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -47);
        } else {
          guard3 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      CV_EML_MCDC(6, 1, 1, FALSE);
      CV_EML_IF(6, 1, 1, FALSE);
      _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 21);
      guard5 = FALSE;
      guard6 = FALSE;
      if (CV_EML_COND(6, 1, 6, c1_aVarTruthTableCondition_1)) {
        if (!CV_EML_COND(6, 1, 7, c1_aVarTruthTableCondition_2)) {
          if (CV_EML_COND(6, 1, 8, c1_aVarTruthTableCondition_3)) {
            CV_EML_MCDC(6, 1, 2, TRUE);
            CV_EML_IF(6, 1, 2, TRUE);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 22);
            CV_EML_FCN(6, 3);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 53);
            c1_num = 2.0;
            c1_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 54);
            chartInstance->c1_select[0] = 1.0;
            c1_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 55);
            chartInstance->c1_select[1] = 3.0;
            c1_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -55);
          } else {
            guard5 = TRUE;
          }
        } else {
          guard6 = TRUE;
        }
      } else {
        guard6 = TRUE;
      }

      if (guard6 == TRUE) {
        guard5 = TRUE;
      }

      if (guard5 == TRUE) {
        CV_EML_MCDC(6, 1, 2, FALSE);
        CV_EML_IF(6, 1, 2, FALSE);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 23);
        guard7 = FALSE;
        guard8 = FALSE;
        if (CV_EML_COND(6, 1, 9, c1_aVarTruthTableCondition_1)) {
          if (!CV_EML_COND(6, 1, 10, c1_aVarTruthTableCondition_2)) {
            if (!CV_EML_COND(6, 1, 11, c1_aVarTruthTableCondition_3)) {
              CV_EML_MCDC(6, 1, 3, TRUE);
              CV_EML_IF(6, 1, 3, TRUE);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 24);
              CV_EML_FCN(6, 5);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 69);
              c1_num = 1.0;
              c1_updateDataWrittenToVector(chartInstance, 10U);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 70);
              chartInstance->c1_select[0] = 1.0;
              c1_updateDataWrittenToVector(chartInstance, 6U);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 71);
              chartInstance->c1_select[1] = 0.0;
              c1_updateDataWrittenToVector(chartInstance, 6U);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -71);
            } else {
              guard7 = TRUE;
            }
          } else {
            guard8 = TRUE;
          }
        } else {
          guard8 = TRUE;
        }

        if (guard8 == TRUE) {
          guard7 = TRUE;
        }

        if (guard7 == TRUE) {
          CV_EML_MCDC(6, 1, 3, FALSE);
          CV_EML_IF(6, 1, 3, FALSE);
          _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 25);
          guard9 = FALSE;
          guard10 = FALSE;
          if (!CV_EML_COND(6, 1, 12, c1_aVarTruthTableCondition_1)) {
            if (CV_EML_COND(6, 1, 13, c1_aVarTruthTableCondition_2)) {
              if (CV_EML_COND(6, 1, 14, c1_aVarTruthTableCondition_3)) {
                CV_EML_MCDC(6, 1, 4, TRUE);
                CV_EML_IF(6, 1, 4, TRUE);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 26);
                CV_EML_FCN(6, 4);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 61);
                c1_num = 2.0;
                c1_updateDataWrittenToVector(chartInstance, 10U);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 62);
                chartInstance->c1_select[0] = 2.0;
                c1_updateDataWrittenToVector(chartInstance, 6U);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 63);
                chartInstance->c1_select[1] = 3.0;
                c1_updateDataWrittenToVector(chartInstance, 6U);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -63);
              } else {
                guard9 = TRUE;
              }
            } else {
              guard10 = TRUE;
            }
          } else {
            guard10 = TRUE;
          }

          if (guard10 == TRUE) {
            guard9 = TRUE;
          }

          if (guard9 == TRUE) {
            CV_EML_MCDC(6, 1, 4, FALSE);
            CV_EML_IF(6, 1, 4, FALSE);
            _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 27);
            guard11 = FALSE;
            guard12 = FALSE;
            if (!CV_EML_COND(6, 1, 15, c1_aVarTruthTableCondition_1)) {
              if (CV_EML_COND(6, 1, 16, c1_aVarTruthTableCondition_2)) {
                if (!CV_EML_COND(6, 1, 17, c1_aVarTruthTableCondition_3)) {
                  CV_EML_MCDC(6, 1, 5, TRUE);
                  CV_EML_IF(6, 1, 5, TRUE);
                  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 28);
                  CV_EML_FCN(6, 6);
                  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 77);
                  c1_num = 1.0;
                  c1_updateDataWrittenToVector(chartInstance, 10U);
                  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 78);
                  chartInstance->c1_select[0] = 2.0;
                  c1_updateDataWrittenToVector(chartInstance, 6U);
                  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 79);
                  chartInstance->c1_select[1] = 0.0;
                  c1_updateDataWrittenToVector(chartInstance, 6U);
                  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -79);
                } else {
                  guard11 = TRUE;
                }
              } else {
                guard12 = TRUE;
              }
            } else {
              guard12 = TRUE;
            }

            if (guard12 == TRUE) {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              CV_EML_MCDC(6, 1, 5, FALSE);
              CV_EML_IF(6, 1, 5, FALSE);
              _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 29);
              guard13 = FALSE;
              guard14 = FALSE;
              if (!CV_EML_COND(6, 1, 18, c1_aVarTruthTableCondition_1)) {
                if (!CV_EML_COND(6, 1, 19, c1_aVarTruthTableCondition_2)) {
                  if (CV_EML_COND(6, 1, 20, c1_aVarTruthTableCondition_3)) {
                    CV_EML_MCDC(6, 1, 6, TRUE);
                    CV_EML_IF(6, 1, 6, TRUE);
                    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 30);
                    CV_EML_FCN(6, 7);
                    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 85);
                    c1_num = 1.0;
                    c1_updateDataWrittenToVector(chartInstance, 10U);
                    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 86);
                    chartInstance->c1_select[0] = 3.0;
                    c1_updateDataWrittenToVector(chartInstance, 6U);
                    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 87);
                    chartInstance->c1_select[1] = 0.0;
                    c1_updateDataWrittenToVector(chartInstance, 6U);
                    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -87);
                  } else {
                    guard13 = TRUE;
                  }
                } else {
                  guard14 = TRUE;
                }
              } else {
                guard14 = TRUE;
              }

              if (guard14 == TRUE) {
                guard13 = TRUE;
              }

              if (guard13 == TRUE) {
                CV_EML_MCDC(6, 1, 6, FALSE);
                CV_EML_IF(6, 1, 6, FALSE);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 32);
                CV_EML_FCN(6, 8);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 93);
                c1_num = 0.0;
                c1_updateDataWrittenToVector(chartInstance, 10U);
                _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -93);
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -32);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_num;
}

static void c1_none(SFc1_DisplayModelInstanceStruct *chartInstance)
{
  boolean_T c1_evilsf_internal_predicateOutput;
  boolean_T *c1_valid_signal;
  c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
  chartInstance->c1_count++;
  c1_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c1_sfEvent);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
  c1_evilsf_internal_predicateOutput = CV_EML_IF(2, 0, 0,
    chartInstance->c1_count > 3.0);
  if (c1_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_count = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    *c1_valid_signal = FALSE;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
    *c1_valid_signal = chartInstance->c1_prev_signal;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i2, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_Screen, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Screen),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Screen);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_Screen;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_b_tp_Screen = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Screen),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Screen);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i3;
  boolean_T c1_b_inData[3];
  int32_T c1_i4;
  boolean_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_b_inData[c1_i3] = (*(boolean_T (*)[3])c1_inData)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_u[c1_i4] = c1_b_inData[c1_i4];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 11, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i5;
  real_T c1_b_inData[3];
  int32_T c1_i6;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_b_inData[c1_i5] = (*(real_T (*)[3])c1_inData)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_u[c1_i6] = c1_b_inData[c1_i6];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i7;
  real_T c1_b_inData[2];
  int32_T c1_i8;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_b_inData[c1_i7] = (*(real_T (*)[2])c1_inData)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_u[c1_i8] = c1_b_inData[c1_i8];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_b_select, const char_T *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_select), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_select);
}

static void c1_i_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv1[2];
  int32_T c1_i9;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_y[c1_i9] = c1_dv1[c1_i9];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_select;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i10;
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)chartInstanceVoid;
  c1_b_select = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_select), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_select);
  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    (*(real_T (*)[2])c1_outData)[c1_i10] = c1_y[c1_i10];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_k_emlrt_marshallIn(SFc1_DisplayModelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_DisplayModelInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 10, 1, 0)] = TRUE;
}

static void c1_errorIfDataNotWrittenToFcn(SFc1_DisplayModelInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber)
{
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 10, 1,
    0)]);
}

static void init_dsm_address_info(SFc1_DisplayModelInstanceStruct *chartInstance)
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

void sf_c1_DisplayModel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1914778628U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3574185918U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(109700634U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3699426889U);
}

mxArray *sf_c1_DisplayModel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("npwy5vShTPqvOlpXt58NyE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_DisplayModel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_DisplayModel_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_DisplayModel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[149],T\"valid_signal\",},{M[3],M[144],T\"bad\",},{M[3],M[142],T\"count\",},{M[3],M[20],T\"diff\",},{M[3],M[21],T\"mean\",},{M[3],M[109],T\"middle\",},{M[3],M[152],T\"n\",},{M[3],M[141],T\"prev_signal\",},{M[3],M[153],T\"select\",},{M[3],M[151],T\"sum_sig\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_DisplayModel\",},{M[9],M[0],T\"is_c1_DisplayModel\",},{M[9],M[19],T\"is_Screen\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DisplayModel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DisplayModelInstanceStruct *chartInstance;
    chartInstance = (SFc1_DisplayModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DisplayModelMachineNumber_,
           1,
           7,
           38,
           14,
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
          init_script_number_translation(_DisplayModelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DisplayModelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DisplayModelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"signals");
          _SFD_SET_DATA_PROPS(1,0,0,0,"prev_signal");
          _SFD_SET_DATA_PROPS(2,0,0,0,"count");
          _SFD_SET_DATA_PROPS(3,7,0,0,"diff_max");
          _SFD_SET_DATA_PROPS(4,0,0,0,"bad");
          _SFD_SET_DATA_PROPS(5,1,1,0,"validity");
          _SFD_SET_DATA_PROPS(6,2,0,1,"valid_signal");
          _SFD_SET_DATA_PROPS(7,0,0,0,"sum_sig");
          _SFD_SET_DATA_PROPS(8,0,0,0,"n");
          _SFD_SET_DATA_PROPS(9,0,0,0,"select");
          _SFD_SET_DATA_PROPS(10,0,0,0,"middle");
          _SFD_SET_DATA_PROPS(11,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(12,0,0,0,"mean");
          _SFD_SET_DATA_PROPS(13,9,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,4);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,4,1,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,9,7,0,0,0,0,0,21,7);
        _SFD_CV_INIT_EML_FCN(6,0,"valid_sensors",0,-1,1206);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",1206,-1,1274);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",1274,-1,1366);
        _SFD_CV_INIT_EML_FCN(6,3,"aFcnTruthTableAction_3",1366,-1,1458);
        _SFD_CV_INIT_EML_FCN(6,4,"aFcnTruthTableAction_4",1458,-1,1550);
        _SFD_CV_INIT_EML_FCN(6,5,"aFcnTruthTableAction_5",1550,-1,1639);
        _SFD_CV_INIT_EML_FCN(6,6,"aFcnTruthTableAction_6",1639,-1,1728);
        _SFD_CV_INIT_EML_FCN(6,7,"aFcnTruthTableAction_7",1728,-1,1817);
        _SFD_CV_INIT_EML_FCN(6,8,"None",1817,-1,1863);
        _SFD_CV_INIT_EML_IF(6,1,0,308,396,427,1204);
        _SFD_CV_INIT_EML_IF(6,1,1,427,520,551,1204);
        _SFD_CV_INIT_EML_IF(6,1,2,551,644,675,1204);
        _SFD_CV_INIT_EML_IF(6,1,3,675,769,800,1204);
        _SFD_CV_INIT_EML_IF(6,1,4,800,893,924,1204);
        _SFD_CV_INIT_EML_IF(6,1,5,924,1018,1049,1204);
        _SFD_CV_INIT_EML_IF(6,1,6,1049,1143,1174,1204);

        {
          static int condStart[] = { 312, 341, 370 };

          static int condEnd[] = { 337, 366, 395 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,0,312,395,3,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 435, 464, 494 };

          static int condEnd[] = { 460, 489, 519 };

          static int pfixExpr[] = { 0, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,1,435,519,3,3,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 559, 589, 618 };

          static int condEnd[] = { 584, 614, 643 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,2,559,643,3,6,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 683, 713, 743 };

          static int condEnd[] = { 708, 738, 768 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,3,683,768,3,9,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 809, 838, 867 };

          static int condEnd[] = { 834, 863, 892 };

          static int pfixExpr[] = { 0, -1, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,4,808,892,3,12,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 933, 962, 992 };

          static int condEnd[] = { 958, 987, 1017 };

          static int pfixExpr[] = { 0, -1, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,5,932,1017,3,15,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1058, 1088, 1117 };

          static int condEnd[] = { 1083, 1113, 1142 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,1,6,1057,1142,3,18,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,7,1,7);
        _SFD_CV_INIT_EML(25,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(11,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,1,5,1,5);
        _SFD_CV_INIT_EML(35,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,5,1,5);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,5,1,5);
        _SFD_CV_INIT_EML(36,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(3,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(37,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));

        {
          boolean_T *c1_valid_signal;
          boolean_T (*c1_signals)[3];
          real_T (*c1_validity)[3];
          c1_valid_signal = (boolean_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c1_validity = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c1_signals = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_signals);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c1_prev_signal);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c1_count);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c1_diff_max);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c1_bad);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_validity);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_valid_signal);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_sum_sig);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_n);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_select);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c1_middle);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c1_diff);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c1_mean);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DisplayModelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KFUJQX4Crxj273ii4qyExF";
}

static void sf_opaque_initialize_c1_DisplayModel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DisplayModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DisplayModel(void *chartInstanceVar)
{
  enable_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_DisplayModel(void *chartInstanceVar)
{
  disable_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_DisplayModel(void *chartInstanceVar)
{
  sf_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_DisplayModel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DisplayModel
    ((SFc1_DisplayModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DisplayModel();/* state var info */
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

extern void sf_internal_set_sim_state_c1_DisplayModel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DisplayModel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_DisplayModel(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DisplayModel(S);
}

static void sf_opaque_set_sim_state_c1_DisplayModel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_DisplayModel(S, st);
}

static void sf_opaque_terminate_c1_DisplayModel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DisplayModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DisplayModel_optimization_info();
    }

    finalize_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DisplayModel((SFc1_DisplayModelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DisplayModel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DisplayModel((SFc1_DisplayModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DisplayModel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DisplayModel_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(225656627U));
  ssSetChecksum1(S,(882346682U));
  ssSetChecksum2(S,(426991247U));
  ssSetChecksum3(S,(3482731004U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DisplayModel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_DisplayModel(SimStruct *S)
{
  SFc1_DisplayModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DisplayModelInstanceStruct *)utMalloc(sizeof
    (SFc1_DisplayModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DisplayModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_DisplayModel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DisplayModel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_DisplayModel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_DisplayModel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_DisplayModel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_DisplayModel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_DisplayModel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DisplayModel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DisplayModel;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DisplayModel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_DisplayModel;
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

void c1_DisplayModel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DisplayModel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DisplayModel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DisplayModel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DisplayModel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
