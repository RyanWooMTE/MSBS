/* Include files */

#include <stddef.h>
#include "blas.h"
#include "LandingGearModeLib_sfun.h"
#include "c3_LandingGearModeLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LandingGearModeLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Locked                   ((uint8_T)1U)
#define c3_IN_Unlocked                 ((uint8_T)2U)
#define c3_IN_BothLocked               ((uint8_T)1U)
#define c3_IN_BothUnLocked             ((uint8_T)2U)
#define c3_IN_ERROR                    ((uint8_T)3U)
#define c3_IN_OnlyOneLocked            ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_y_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_ab_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_bb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_cb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_db_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_eb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_fb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_gb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_hb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_ib_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_jb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_kb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void initialize_params_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void enable_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void disable_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct *
  chartInstance);
static void c3_update_debugger_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void set_sim_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void finalize_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void sf_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void c3_enter_atomic_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void c3_enter_internal_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void c3_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void c3_exit_internal_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void c3_initc3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void initSimStructsc3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void c3_WarningModes(SFc3_LandingGearModeLibInstanceStruct *chartInstance);
static void c3_OnlyOneLocked(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_LeftLock, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_Misc_bus_io(void *chartInstanceVoid, void *c3_pData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_emlrt_marshallIn
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void init_dsm_address_info(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
}

static void initialize_params_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
}

static void enable_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
}

static void disable_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct *
  chartInstance)
{
}

static void c3_update_debugger_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_LandingGearModeLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_LeftLock == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_LeftLock == c3_IN_Locked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_LeftLock == c3_IN_Unlocked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_RightLock == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_RightLock == c3_IN_Unlocked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_RightLock == c3_IN_Locked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_WarningModes == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_WarningModes == c3_IN_BothLocked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_WarningModes == c3_IN_BothUnLocked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_WarningModes == c3_IN_OnlyOneLocked) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_WarningModes == c3_IN_ERROR) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T *c3_LandingGearMode;
  c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(9), FALSE);
  c3_hoistedGlobal = *c3_LandingGearMode;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_LandingGearModeLib;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_LeftLock;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_active_RightLock;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_WarningModes;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_LeftLock;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_RightLock;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_WarningModes;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_LandingGearMode;
  c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_LandingGearMode = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "LandingGearMode");
  chartInstance->c3_is_active_c3_LandingGearModeLib = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_LandingGearModeLib");
  chartInstance->c3_is_active_LeftLock = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_LeftLock");
  chartInstance->c3_is_active_RightLock = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 3)), "is_active_RightLock");
  chartInstance->c3_is_active_WarningModes = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "is_active_WarningModes");
  chartInstance->c3_is_LeftLock = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "is_LeftLock");
  chartInstance->c3_is_RightLock = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 6)), "is_RightLock");
  chartInstance->c3_is_WarningModes = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_WarningModes");
  chartInstance->c3_temporalCounter_i1 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 8)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 9)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_LandingGearModeLib(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_active_LeftLock == 1U) {
      chartInstance->c3_tp_LeftLock = 1U;
    } else {
      chartInstance->c3_tp_LeftLock = 0U;
    }

    if (chartInstance->c3_is_LeftLock == c3_IN_Locked) {
      chartInstance->c3_tp_Locked = 1U;
    } else {
      chartInstance->c3_tp_Locked = 0U;
    }

    if (chartInstance->c3_is_LeftLock == c3_IN_Unlocked) {
      chartInstance->c3_tp_Unlocked = 1U;
    } else {
      chartInstance->c3_tp_Unlocked = 0U;
    }

    if (chartInstance->c3_is_active_RightLock == 1U) {
      chartInstance->c3_tp_RightLock = 1U;
    } else {
      chartInstance->c3_tp_RightLock = 0U;
    }

    if (chartInstance->c3_is_RightLock == c3_IN_Locked) {
      chartInstance->c3_b_tp_Locked = 1U;
    } else {
      chartInstance->c3_b_tp_Locked = 0U;
    }

    if (chartInstance->c3_is_RightLock == c3_IN_Unlocked) {
      chartInstance->c3_b_tp_Unlocked = 1U;
    } else {
      chartInstance->c3_b_tp_Unlocked = 0U;
    }

    if (chartInstance->c3_is_active_WarningModes == 1U) {
      chartInstance->c3_tp_WarningModes = 1U;
    } else {
      chartInstance->c3_tp_WarningModes = 0U;
    }

    if (chartInstance->c3_is_WarningModes == c3_IN_BothLocked) {
      chartInstance->c3_tp_BothLocked = 1U;
    } else {
      chartInstance->c3_tp_BothLocked = 0U;
    }

    if (chartInstance->c3_is_WarningModes == c3_IN_BothUnLocked) {
      chartInstance->c3_tp_BothUnLocked = 1U;
    } else {
      chartInstance->c3_tp_BothUnLocked = 0U;
    }

    if (chartInstance->c3_is_WarningModes == c3_IN_ERROR) {
      chartInstance->c3_tp_ERROR = 1U;
    } else {
      chartInstance->c3_tp_ERROR = 0U;
    }

    if (chartInstance->c3_is_WarningModes == c3_IN_OnlyOneLocked) {
      chartInstance->c3_tp_OnlyOneLocked = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_OnlyOneLocked = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
  c3_set_sim_state_side_effects_c3_LandingGearModeLib(chartInstance);
}

static void c3_enter_atomic_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_active_c3_LandingGearModeLib = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_enter_internal_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_d_out;
  boolean_T c3_b0;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T *c3_LandingGearMode;
  c3_MiscData *c3_Misc;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Misc = (c3_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_isStable = FALSE;
  chartInstance->c3_is_active_LeftLock = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_LeftLock = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_out = CV_EML_IF(1, 0, 0, *(boolean_T *)((char_T *)c3_Misc + 32));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_LeftLock = c3_IN_Locked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Locked = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_LeftLock = c3_IN_Unlocked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Unlocked = 1U;
  }

  chartInstance->c3_isStable = FALSE;
  chartInstance->c3_is_active_RightLock = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_RightLock = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_b_out = CV_EML_IF(7, 0, 0, *(boolean_T *)((char_T *)c3_Misc + 33));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_RightLock = c3_IN_Locked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_b_tp_Locked = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_RightLock = c3_IN_Unlocked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_b_tp_Unlocked = 1U;
  }

  chartInstance->c3_isStable = FALSE;
  chartInstance->c3_is_active_WarningModes = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_WarningModes = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  guard3 = FALSE;
  if (CV_EML_COND(11, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Locked)) {
    if (CV_EML_COND(11, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Locked)) {
      CV_EML_MCDC(11, 0, 0, TRUE);
      CV_EML_IF(11, 0, 0, TRUE);
      c3_c_out = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    CV_EML_MCDC(11, 0, 0, FALSE);
    CV_EML_IF(11, 0, 0, FALSE);
    c3_c_out = FALSE;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_c_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 11;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cb_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard2 = FALSE;
      if (chartInstance->c3_is_LeftLock == c3_IN_Unlocked) {
        if (chartInstance->c3_is_RightLock == c3_IN_Unlocked) {
          c3_b0 = TRUE;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        c3_b0 = FALSE;
      }

      c3_d_out = c3_b0;
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        transitionList[numTransitions] = 12;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_WarningModes = c3_IN_BothLocked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_BothLocked = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *c3_LandingGearMode = 1.0;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = FALSE;
    if (CV_EML_COND(12, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Unlocked))
    {
      if (CV_EML_COND(12, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Unlocked))
      {
        CV_EML_MCDC(12, 0, 0, TRUE);
        CV_EML_IF(12, 0, 0, TRUE);
        c3_e_out = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(12, 0, 0, FALSE);
      CV_EML_IF(12, 0, 0, FALSE);
      c3_e_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_BothUnLocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_BothUnLocked = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 3.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_OnlyOneLocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_OnlyOneLocked = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 2.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    }
  }
}

static void c3_c3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_d_out;
  c3_MiscData *c3_Misc;
  c3_Misc = (c3_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_isStable = TRUE;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_LeftLock) {
   case c3_IN_Locked:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(3, 0, 0, CV_EML_MCDC(3, 0, 0, !CV_EML_COND(3, 0, 0,
      *(boolean_T *)((char_T *)c3_Misc + 32))));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Locked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_LeftLock = c3_IN_Unlocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Unlocked = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Unlocked:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_b_out = CV_EML_IF(4, 0, 0, *(boolean_T *)((char_T *)c3_Misc + 32));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Unlocked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_LeftLock = c3_IN_Locked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Locked = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c3_is_LeftLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_RightLock) {
   case c3_IN_Locked:
    CV_STATE_EVAL(3, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_c_out = CV_EML_IF(8, 0, 0, CV_EML_MCDC(8, 0, 0, !CV_EML_COND(8, 0, 0,
      *(boolean_T *)((char_T *)c3_Misc + 33))));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_Locked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_RightLock = c3_IN_Unlocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_Unlocked = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Unlocked:
    CV_STATE_EVAL(3, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_d_out = CV_EML_IF(9, 0, 0, *(boolean_T *)((char_T *)c3_Misc + 33));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_Unlocked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_RightLock = c3_IN_Locked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_b_tp_Locked = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 0, 0);
    chartInstance->c3_is_RightLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
  c3_WarningModes(chartInstance);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_c3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c3_is_WarningModes) {
   case c3_IN_BothLocked:
    CV_STATE_EVAL(6, 1, 1);
    chartInstance->c3_tp_BothLocked = 0U;
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_BothUnLocked:
    CV_STATE_EVAL(6, 1, 2);
    chartInstance->c3_tp_BothUnLocked = 0U;
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_ERROR:
    CV_STATE_EVAL(6, 1, 3);
    chartInstance->c3_tp_ERROR = 0U;
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_OnlyOneLocked:
    CV_STATE_EVAL(6, 1, 4);
    chartInstance->c3_tp_OnlyOneLocked = 0U;
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_WarningModes = 0U;
  chartInstance->c3_is_active_WarningModes = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_RightLock) {
   case c3_IN_Locked:
    CV_STATE_EVAL(3, 1, 1);
    chartInstance->c3_b_tp_Locked = 0U;
    chartInstance->c3_is_RightLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Unlocked:
    CV_STATE_EVAL(3, 1, 2);
    chartInstance->c3_b_tp_Unlocked = 0U;
    chartInstance->c3_is_RightLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 1, 0);
    chartInstance->c3_is_RightLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_RightLock = 0U;
  chartInstance->c3_is_active_RightLock = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_LeftLock) {
   case c3_IN_Locked:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c3_tp_Locked = 0U;
    chartInstance->c3_is_LeftLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Unlocked:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c3_tp_Unlocked = 0U;
    chartInstance->c3_is_LeftLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c3_is_LeftLock = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_LeftLock = 0U;
  chartInstance->c3_is_active_LeftLock = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_initc3_LandingGearModeLib(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_LeftLock = 0U;
  chartInstance->c3_is_LeftLock = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_LeftLock = 0U;
  chartInstance->c3_tp_Locked = 0U;
  chartInstance->c3_tp_Unlocked = 0U;
  chartInstance->c3_is_active_RightLock = 0U;
  chartInstance->c3_is_RightLock = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_RightLock = 0U;
  chartInstance->c3_b_tp_Locked = 0U;
  chartInstance->c3_b_tp_Unlocked = 0U;
  chartInstance->c3_is_active_WarningModes = 0U;
  chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_WarningModes = 0U;
  chartInstance->c3_tp_BothLocked = 0U;
  chartInstance->c3_tp_BothUnLocked = 0U;
  chartInstance->c3_tp_ERROR = 0U;
  chartInstance->c3_tp_OnlyOneLocked = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_is_active_c3_LandingGearModeLib = 0U;
}

static void initSimStructsc3_LandingGearModeLib
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
}

static void c3_WarningModes(SFc3_LandingGearModeLibInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_b1;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_e_out;
  boolean_T c3_b2;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  real_T *c3_LandingGearMode;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  boolean_T guard9 = FALSE;
  c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_WarningModes) {
   case c3_IN_BothLocked:
    CV_STATE_EVAL(6, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard9 = FALSE;
    if (CV_EML_COND(20, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Unlocked))
    {
      if (CV_EML_COND(20, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Unlocked))
      {
        CV_EML_MCDC(20, 0, 0, TRUE);
        CV_EML_IF(20, 0, 0, TRUE);
        c3_out = TRUE;
      } else {
        guard9 = TRUE;
      }
    } else {
      guard9 = TRUE;
    }

    if (guard9 == TRUE) {
      CV_EML_MCDC(20, 0, 0, FALSE);
      CV_EML_IF(20, 0, 0, FALSE);
      c3_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 20;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_gb_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard8 = FALSE;
        if (chartInstance->c3_is_LeftLock == c3_IN_Unlocked) {
          guard8 = TRUE;
        } else if (chartInstance->c3_is_RightLock == c3_IN_Unlocked) {
          guard8 = TRUE;
        } else {
          c3_b1 = FALSE;
        }

        if (guard8 == TRUE) {
          c3_b1 = TRUE;
        }

        c3_b_out = c3_b1;
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          transitionList[numTransitions] = 17;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_BothLocked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_BothUnLocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_BothUnLocked = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 3.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard7 = FALSE;
      if (CV_EML_COND(17, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Unlocked))
      {
        guard7 = TRUE;
      } else if (CV_EML_COND(17, 0, 1, chartInstance->c3_is_RightLock ==
                             c3_IN_Unlocked)) {
        guard7 = TRUE;
      } else {
        CV_EML_MCDC(17, 0, 0, FALSE);
        CV_EML_IF(17, 0, 0, FALSE);
        c3_c_out = FALSE;
      }

      if (guard7 == TRUE) {
        CV_EML_MCDC(17, 0, 0, TRUE);
        CV_EML_IF(17, 0, 0, TRUE);
        c3_c_out = TRUE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_BothLocked = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_isStable = FALSE;
        chartInstance->c3_is_WarningModes = c3_IN_OnlyOneLocked;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_OnlyOneLocked = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_LandingGearMode = 2.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_BothUnLocked:
    CV_STATE_EVAL(6, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard6 = FALSE;
    if (CV_EML_COND(21, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Locked)) {
      if (CV_EML_COND(21, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Locked))
      {
        CV_EML_MCDC(21, 0, 0, TRUE);
        CV_EML_IF(21, 0, 0, TRUE);
        c3_d_out = TRUE;
      } else {
        guard6 = TRUE;
      }
    } else {
      guard6 = TRUE;
    }

    if (guard6 == TRUE) {
      CV_EML_MCDC(21, 0, 0, FALSE);
      CV_EML_IF(21, 0, 0, FALSE);
      c3_d_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 21;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_db_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard5 = FALSE;
        if (chartInstance->c3_is_LeftLock == c3_IN_Locked) {
          guard5 = TRUE;
        } else if (chartInstance->c3_is_RightLock == c3_IN_Locked) {
          guard5 = TRUE;
        } else {
          c3_b2 = FALSE;
        }

        if (guard5 == TRUE) {
          c3_b2 = TRUE;
        }

        c3_e_out = c3_b2;
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          transitionList[numTransitions] = 14;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_BothUnLocked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_BothLocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_BothLocked = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 1.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard4 = FALSE;
      if (CV_EML_COND(14, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Locked))
      {
        guard4 = TRUE;
      } else if (CV_EML_COND(14, 0, 1, chartInstance->c3_is_RightLock ==
                             c3_IN_Locked)) {
        guard4 = TRUE;
      } else {
        CV_EML_MCDC(14, 0, 0, FALSE);
        CV_EML_IF(14, 0, 0, FALSE);
        c3_f_out = FALSE;
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(14, 0, 0, TRUE);
        CV_EML_IF(14, 0, 0, TRUE);
        c3_f_out = TRUE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_BothUnLocked = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_isStable = FALSE;
        chartInstance->c3_is_WarningModes = c3_IN_OnlyOneLocked;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_OnlyOneLocked = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_LandingGearMode = 2.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_ERROR:
    CV_STATE_EVAL(6, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = FALSE;
    guard2 = FALSE;
    guard3 = FALSE;
    if (CV_EML_COND(19, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Locked)) {
      if (CV_EML_COND(19, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Locked))
      {
        guard2 = TRUE;
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      if (CV_EML_COND(19, 0, 2, chartInstance->c3_is_LeftLock == c3_IN_Unlocked))
      {
        if (CV_EML_COND(19, 0, 3, chartInstance->c3_is_RightLock ==
                        c3_IN_Unlocked)) {
          guard2 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(19, 0, 0, TRUE);
      CV_EML_IF(19, 0, 0, TRUE);
      c3_g_out = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(19, 0, 0, FALSE);
      CV_EML_IF(19, 0, 0, FALSE);
      c3_g_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_ERROR = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_OnlyOneLocked;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_OnlyOneLocked = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 2.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_OnlyOneLocked:
    CV_STATE_EVAL(6, 0, 4);
    c3_OnlyOneLocked(chartInstance);
    break;

   default:
    CV_STATE_EVAL(6, 0, 0);
    chartInstance->c3_is_WarningModes = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
}

static void c3_OnlyOneLocked(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_b3;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T *c3_LandingGearMode;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  guard3 = FALSE;
  if (CV_EML_COND(16, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Unlocked)) {
    if (CV_EML_COND(16, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Unlocked))
    {
      CV_EML_MCDC(16, 0, 0, TRUE);
      CV_EML_IF(16, 0, 0, TRUE);
      c3_out = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    CV_EML_MCDC(16, 0, 0, FALSE);
    CV_EML_IF(16, 0, 0, FALSE);
    c3_out = FALSE;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 16;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_eb_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard2 = FALSE;
      if (chartInstance->c3_is_LeftLock == c3_IN_Locked) {
        if (chartInstance->c3_is_RightLock == c3_IN_Locked) {
          c3_b3 = TRUE;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        c3_b3 = FALSE;
      }

      c3_b_out = c3_b3;
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        transitionList[numTransitions] = 15;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_OnlyOneLocked = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
    chartInstance->c3_isStable = FALSE;
    chartInstance->c3_is_WarningModes = c3_IN_BothUnLocked;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_BothUnLocked = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *c3_LandingGearMode = 3.0;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_c_out = CV_EML_IF(18, 0, 0, chartInstance->c3_temporalCounter_i1 >= 10);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_OnlyOneLocked = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_isStable = FALSE;
      chartInstance->c3_is_WarningModes = c3_IN_ERROR;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_ERROR = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_LandingGearMode = 4.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = FALSE;
      if (CV_EML_COND(15, 0, 0, chartInstance->c3_is_LeftLock == c3_IN_Locked))
      {
        if (CV_EML_COND(15, 0, 1, chartInstance->c3_is_RightLock == c3_IN_Locked))
        {
          CV_EML_MCDC(15, 0, 0, TRUE);
          CV_EML_IF(15, 0, 0, TRUE);
          c3_d_out = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(15, 0, 0, FALSE);
        CV_EML_IF(15, 0, 0, FALSE);
        c3_d_out = FALSE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_OnlyOneLocked = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_isStable = FALSE;
        chartInstance->c3_is_WarningModes = c3_IN_BothLocked;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_BothLocked = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_LandingGearMode = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c3_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b4;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b4, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b4;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_evilsf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_evilsf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_evilsf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_evilsf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_LandingGearModeLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c3_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  return chartInstance->c3_isStable;
}

void sf_exported_auto_duringc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  c3_c3_LandingGearModeLib(chartInstance);
}

void sf_exported_auto_enterc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c3_enter_atomic_c3_LandingGearModeLib(chartInstance);
  c3_enter_internal_c3_LandingGearModeLib(chartInstance);
}

void sf_exported_auto_exitc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c3_exit_internal_c3_LandingGearModeLib(chartInstance);
}

void sf_exported_auto_gatewayc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c3_temporalCounter_i1 < 15U) {
    chartInstance->c3_temporalCounter_i1++;
  }
}

void sf_exported_auto_enablec3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

void sf_exported_auto_disablec3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c3_temporalCounter_i1 < 15U) {
    chartInstance->c3_temporalCounter_i1++;
  }
}

void sf_exported_auto_stepBuffersc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
}

void sf_exported_auto_initBuffersc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
}

void sf_exported_auto_activate_callc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  chartInstance->c3_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc3_LandingGearModeLib(SimStruct
  *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
}

void sf_exported_auto_reset_call_counterc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
}

void sf_exported_auto_deactivate_callc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
}

void sf_exported_auto_initc3_LandingGearModeLib(SimStruct *c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  c3_initc3_LandingGearModeLib(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec3_LandingGearModeLib(SimStruct *c3_S)
{
  const mxArray *c3_out = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  c3_out = NULL;
  sf_mex_assign(&c3_out, sf_internal_get_sim_state_c3_LandingGearModeLib(c3_S),
                FALSE);
  return c3_out;
}

void sf_exported_auto_setSimstatec3_LandingGearModeLib(SimStruct *c3_S, const
  mxArray *c3_in)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  sf_internal_set_sim_state_c3_LandingGearModeLib(c3_S, sf_mex_dup(c3_in));
  sf_mex_destroy(&c3_in);
}

void sf_exported_auto_check_state_inconsistency_c3_LandingGearModeLib(SimStruct *
  c3_S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)((ChartInfoStruct *)
    ssGetUserData(c3_S))->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LandingGearModeLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_LeftLock, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_LeftLock),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_LeftLock);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_LeftLock;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_b_tp_LeftLock = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_LeftLock),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_LeftLock);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_Misc_bus_io(void *chartInstanceVoid, void *c3_pData)
{
  const mxArray *c3_mxVal = NULL;
  c3_MiscData c3_tmp;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxVal = NULL;
  c3_tmp.FlapPosition = *(real_T *)((char_T *)c3_pData + 0);
  c3_tmp.CabinPressure = *(real_T *)((char_T *)c3_pData + 8);
  c3_tmp.HydraulicPressure = *(real_T *)((char_T *)c3_pData + 16);
  c3_tmp.APUData = *(real_T *)((char_T *)c3_pData + 24);
  c3_tmp.LGLeftLock = *(boolean_T *)((char_T *)c3_pData + 32);
  c3_tmp.LGRightLock = *(boolean_T *)((char_T *)c3_pData + 33);
  sf_mex_assign(&c3_mxVal, c3_e_sf_marshallOut(chartInstance, &c3_tmp), FALSE);
  return c3_mxVal;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  c3_MiscData c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  boolean_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  boolean_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(c3_MiscData *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c3_b_u = c3_u.FlapPosition;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_b_y, "FlapPosition", "FlapPosition", 0);
  c3_c_u = c3_u.CabinPressure;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_c_y, "CabinPressure", "CabinPressure", 0);
  c3_d_u = c3_u.HydraulicPressure;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c3_e_u = c3_u.APUData;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_e_y, "APUData", "APUData", 0);
  c3_f_u = c3_u.LGLeftLock;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_f_y, "LGLeftLock", "LGLeftLock", 0);
  c3_g_u = c3_u.LGRightLock;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c3_y, c3_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_emlrt_marshallIn
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), FALSE);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_LandingGearModeLibInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), FALSE);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_LandingGearModeLibInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static void init_dsm_address_info(SFc3_LandingGearModeLibInstanceStruct
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

void sf_c3_LandingGearModeLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3186225869U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3927918726U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2000018540U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2349128819U);
}

mxArray *sf_c3_LandingGearModeLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eDci7jCKTJ9BWQcpG9dVGB");
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

mxArray *sf_c3_LandingGearModeLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_LandingGearModeLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_LandingGearModeLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[39],T\"LandingGearMode\",},{M[8],M[0],T\"is_active_c3_LandingGearModeLib\",},{M[8],M[2],T\"is_active_LeftLock\",},{M[8],M[11],T\"is_active_RightLock\",},{M[8],M[20],T\"is_active_WarningModes\",},{M[9],M[2],T\"is_LeftLock\",},{M[9],M[11],T\"is_RightLock\",},{M[9],M[20],T\"is_WarningModes\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[36],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_LandingGearModeLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_LandingGearModeLibInstanceStruct *chartInstance;
    chartInstance = (SFc3_LandingGearModeLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LandingGearModeLibMachineNumber_,
           3,
           11,
           22,
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
          init_script_number_translation(_LandingGearModeLibMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_LandingGearModeLibMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _LandingGearModeLibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Misc");
          _SFD_SET_DATA_PROPS(1,2,0,1,"LandingGearMode");
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,6);
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
          _SFD_ST_SUBSTATE_COUNT(6,4);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_INDEX(6,2,9);
          _SFD_ST_SUBSTATE_INDEX(6,3,10);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

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
          _SFD_CV_INIT_STATE(6,4,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(2,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,17,1,17);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 17 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,17,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(5,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,18,1,18);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 18 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,18,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(10,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(11,0,0,1,47,1,47);

        {
          static int condStart[] = { 1, 27 };

          static int condEnd[] = { 20, 47 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(11,0,0,1,47,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(12,0,0,1,51,1,51);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 22, 51 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,1,51,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(14,0,0,1,47,1,47);

        {
          static int condStart[] = { 1, 27 };

          static int condEnd[] = { 20, 47 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(14,0,0,1,47,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(15,0,0,1,47,1,47);

        {
          static int condStart[] = { 1, 27 };

          static int condEnd[] = { 20, 47 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(15,0,0,1,47,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(16,0,0,1,51,1,51);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 22, 51 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(16,0,0,1,51,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(17,0,0,1,51,1,51);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 22, 51 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(17,0,0,1,51,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(19,0,0,1,99,1,52);

        {
          static int condStart[] = { 2, 23, 53, 76 };

          static int condEnd[] = { 21, 43, 74, 98 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(19,0,0,1,99,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(20,0,0,1,51,1,51);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 22, 51 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(20,0,0,1,51,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(21,0,0,1,47,1,47);

        {
          static int condStart[] = { 1, 27 };

          static int condEnd[] = { 20, 47 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(21,0,0,1,47,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          c3_MiscData *c3_Misc;
          real_T *c3_LandingGearMode;
          c3_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c3_Misc = (c3_MiscData *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Misc);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_LandingGearMode);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _LandingGearModeLibMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6pER6kMsK3Z18p3Bgt0MWD";
}

static void sf_opaque_initialize_c3_LandingGearModeLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
  initialize_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_LandingGearModeLib(void *chartInstanceVar)
{
  enable_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_LandingGearModeLib(void *chartInstanceVar)
{
  disable_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_LandingGearModeLib(void *chartInstanceVar)
{
  sf_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_LandingGearModeLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_LandingGearModeLib
    ((SFc3_LandingGearModeLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_LandingGearModeLib();/* state var info */
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

extern void sf_internal_set_sim_state_c3_LandingGearModeLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_LandingGearModeLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_LandingGearModeLib(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c3_LandingGearModeLib(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c3_LandingGearModeLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_LandingGearModeLibInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LandingGearModeLib_optimization_info();
    }

    finalize_c3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_LandingGearModeLib((SFc3_LandingGearModeLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_LandingGearModeLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_LandingGearModeLib
      ((SFc3_LandingGearModeLibInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_LandingGearModeLib(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_LandingGearModeLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2720473720U));
  ssSetChecksum1(S,(1474578673U));
  ssSetChecksum2(S,(1524701402U));
  ssSetChecksum3(S,(1228598953U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_LandingGearModeLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_LandingGearModeLib(SimStruct *S)
{
  SFc3_LandingGearModeLibInstanceStruct *chartInstance;
  chartInstance = (SFc3_LandingGearModeLibInstanceStruct *)utMalloc(sizeof
    (SFc3_LandingGearModeLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_LandingGearModeLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_LandingGearModeLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_LandingGearModeLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_LandingGearModeLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_LandingGearModeLib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_LandingGearModeLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_LandingGearModeLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_LandingGearModeLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_LandingGearModeLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_LandingGearModeLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_LandingGearModeLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_LandingGearModeLib;
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

void c3_LandingGearModeLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_LandingGearModeLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_LandingGearModeLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_LandingGearModeLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_LandingGearModeLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
