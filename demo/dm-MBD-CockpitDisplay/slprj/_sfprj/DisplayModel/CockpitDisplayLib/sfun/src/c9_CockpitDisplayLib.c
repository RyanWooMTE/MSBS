/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c9_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_EnginesOff               ((uint8_T)1U)
#define c9_IN_Land                     ((uint8_T)2U)
#define c9_IN_PushbackAndTaxi          ((uint8_T)3U)
#define c9_IN_TakeoffCruiseDescent     ((uint8_T)4U)
#define c9_IN_Phase1                   ((uint8_T)1U)
#define c9_IN_Phase2                   ((uint8_T)2U)
#define c9_IN_Phase3                   ((uint8_T)3U)
#define c9_IN_Phase4                   ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *c9_subchartSimStateInfo;
static const mxArray *c9_b_subchartSimStateInfo;
static const mxArray *c9_c_subchartSimStateInfo;
static const mxArray *c9_d_subchartSimStateInfo;
static const mxArray *c9_e_subchartSimStateInfo;
static const mxArray *c9_f_subchartSimStateInfo;
static const mxArray *c9_g_subchartSimStateInfo;
static const mxArray *c9_h_subchartSimStateInfo;
static const char * c9_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_j_debug_family_names[7] = { "guard1", "guard2", "guard3",
  "guard4", "nargin", "nargout", "msgID" };

static const char * c9_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_m_debug_family_names[7] = { "guard1", "guard2", "guard3",
  "guard4", "nargin", "nargout", "msgID" };

static const char * c9_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_p_debug_family_names[7] = { "guard1", "guard2", "guard3",
  "guard4", "nargin", "nargout", "msgID" };

static const char * c9_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_s_debug_family_names[7] = { "guard1", "guard2", "guard3",
  "guard4", "nargin", "nargout", "msgID" };

static const char * c9_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_u_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_v_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_w_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_x_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_y_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_ab_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_bb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_cb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_db_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_eb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_fb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c9_gb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[6];

/* Function Declarations */
static void initialize_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void initialize_params_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c9_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void initSimStructsc9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static void c9_FlightPhases(SFc9_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_d_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(uint32_T c9_u);
static void c9_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10]);
static void c9_b_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10]);
static void c9_c_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10]);
static void c9_d_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10]);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_e_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_f_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_FlightPhases, const char_T
  *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_h_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_output_msgID, const char_T *c9_identifier,
  real_T c9_y[10]);
static void c9_i_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_PFD_bus_io(void *chartInstanceVoid, void *c9_pData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_EngNFuel_bus_io(void *chartInstanceVoid, void *c9_pData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_Misc_bus_io(void *chartInstanceVoid, void *c9_pData);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_j_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_i_subchartSimStateInfo, const char_T
  *c9_identifier);
static const mxArray *c9_k_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber);
static real_T c9_get_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b);
static void init_dsm_address_info(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  real_T *c9_RPMProblem;
  real_T *c9_TempProblem;
  real_T *c9_FuelPProblem;
  real_T *c9_FuelQProblem;
  real_T *c9_OilPProblem;
  real_T *c9_APUProblem;
  real_T *c9_HydProblem;
  real_T *c9_CabinPProblem;
  real_T *c9_LandingGearMode;
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  sf_exported_auto_initc17_CockpitDisplayLib(chartInstance->c9_subchartSimstruct);
  sf_exported_auto_initc15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct);
  sf_exported_auto_initc16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct);
  sf_exported_auto_initc2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct);
  sf_exported_auto_initc13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct);
  sf_exported_auto_initc10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct);
  sf_exported_auto_initc11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct);
  sf_exported_auto_initc3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c9_subchartSimStateInfo = NULL;
  c9_b_subchartSimStateInfo = NULL;
  c9_c_subchartSimStateInfo = NULL;
  c9_d_subchartSimStateInfo = NULL;
  c9_e_subchartSimStateInfo = NULL;
  c9_f_subchartSimStateInfo = NULL;
  c9_g_subchartSimStateInfo = NULL;
  c9_h_subchartSimStateInfo = NULL;
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_is_active_ComponentModes = 0U;
  chartInstance->c9_tp_ComponentModes = 0U;
  chartInstance->c9_is_active_APU = 0U;
  chartInstance->c9_tp_APU = 0U;
  chartInstance->c9_is_active_CabinPressure = 0U;
  chartInstance->c9_tp_CabinPressure = 0U;
  chartInstance->c9_is_active_Fuel = 0U;
  chartInstance->c9_tp_Fuel = 0U;
  chartInstance->c9_is_active_Hyd = 0U;
  chartInstance->c9_tp_Hyd = 0U;
  chartInstance->c9_is_active_LandingGear = 0U;
  chartInstance->c9_tp_LandingGear = 0U;
  chartInstance->c9_is_active_OilP = 0U;
  chartInstance->c9_tp_OilP = 0U;
  chartInstance->c9_is_active_RPM = 0U;
  chartInstance->c9_tp_RPM = 0U;
  chartInstance->c9_is_active_Temp = 0U;
  chartInstance->c9_tp_Temp = 0U;
  chartInstance->c9_is_active_FlightPhases = 0U;
  chartInstance->c9_is_FlightPhases = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_FlightPhases = 0U;
  chartInstance->c9_tp_EnginesOff = 0U;
  chartInstance->c9_tp_Land = 0U;
  chartInstance->c9_tp_PushbackAndTaxi = 0U;
  chartInstance->c9_tp_TakeoffCruiseDescent = 0U;
  chartInstance->c9_is_active_WarningsComputation = 0U;
  chartInstance->c9_is_WarningsComputation = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_WarningsComputation = 0U;
  chartInstance->c9_tp_Phase1 = 0U;
  chartInstance->c9_tp_Phase2 = 0U;
  chartInstance->c9_tp_Phase3 = 0U;
  chartInstance->c9_tp_Phase4 = 0U;
  chartInstance->c9_is_active_c9_CockpitDisplayLib = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c9_RPMProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c9_TempProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 4) != 0)) {
    *c9_FuelPProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 5) != 0)) {
    *c9_FuelQProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 6) != 0)) {
    *c9_OilPProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 7) != 0)) {
    *c9_APUProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 8) != 0)) {
    *c9_HydProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 9) != 0)) {
    *c9_CabinPProblem = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 10) != 0)) {
    *c9_LandingGearMode = 0.0;
  }
}

static void initialize_params_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c9_is_active_Temp == 1U) {
    sf_exported_auto_enablec17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_OilP == 1U) {
    sf_exported_auto_enablec15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_RPM == 1U) {
    sf_exported_auto_enablec16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Fuel == 1U) {
    sf_exported_auto_enablec2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Hyd == 1U) {
    sf_exported_auto_enablec13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_APU == 1U) {
    sf_exported_auto_enablec10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_CabinPressure == 1U) {
    sf_exported_auto_enablec11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_LandingGear == 1U) {
    sf_exported_auto_enablec3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
  }
}

static void disable_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c9_is_active_Temp == 1U) {
    sf_exported_auto_disablec17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_OilP == 1U) {
    sf_exported_auto_disablec15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_RPM == 1U) {
    sf_exported_auto_disablec16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Fuel == 1U) {
    sf_exported_auto_disablec2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Hyd == 1U) {
    sf_exported_auto_disablec13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_APU == 1U) {
    sf_exported_auto_disablec10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_CabinPressure == 1U) {
    sf_exported_auto_disablec11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_LandingGear == 1U) {
    sf_exported_auto_disablec3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
  }
}

static void c9_update_debugger_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_FlightPhases == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_FlightPhases == c9_IN_EnginesOff) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_FlightPhases == c9_IN_PushbackAndTaxi) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_FlightPhases == c9_IN_TakeoffCruiseDescent) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_FlightPhases == c9_IN_Land) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_ComponentModes == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_Temp == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_OilP == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_RPM == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_Fuel == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_Hyd == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_APU == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_CabinPressure == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_LandingGear == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_WarningsComputation == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_f_hoistedGlobal;
  real_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  real_T c9_g_hoistedGlobal;
  real_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  real_T c9_h_hoistedGlobal;
  real_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  real_T c9_i_hoistedGlobal;
  real_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  int32_T c9_i0;
  real_T c9_j_u[10];
  const mxArray *c9_k_y = NULL;
  real_T c9_j_hoistedGlobal;
  real_T c9_k_u;
  const mxArray *c9_l_y = NULL;
  uint8_T c9_k_hoistedGlobal;
  uint8_T c9_l_u;
  const mxArray *c9_m_y = NULL;
  uint8_T c9_l_hoistedGlobal;
  uint8_T c9_m_u;
  const mxArray *c9_n_y = NULL;
  uint8_T c9_m_hoistedGlobal;
  uint8_T c9_n_u;
  const mxArray *c9_o_y = NULL;
  uint8_T c9_n_hoistedGlobal;
  uint8_T c9_o_u;
  const mxArray *c9_p_y = NULL;
  uint8_T c9_o_hoistedGlobal;
  uint8_T c9_p_u;
  const mxArray *c9_q_y = NULL;
  uint8_T c9_p_hoistedGlobal;
  uint8_T c9_q_u;
  const mxArray *c9_r_y = NULL;
  uint8_T c9_q_hoistedGlobal;
  uint8_T c9_r_u;
  const mxArray *c9_s_y = NULL;
  uint8_T c9_r_hoistedGlobal;
  uint8_T c9_s_u;
  const mxArray *c9_t_y = NULL;
  uint8_T c9_s_hoistedGlobal;
  uint8_T c9_t_u;
  const mxArray *c9_u_y = NULL;
  uint8_T c9_t_hoistedGlobal;
  uint8_T c9_u_u;
  const mxArray *c9_v_y = NULL;
  uint8_T c9_u_hoistedGlobal;
  uint8_T c9_v_u;
  const mxArray *c9_w_y = NULL;
  uint8_T c9_v_hoistedGlobal;
  uint8_T c9_w_u;
  const mxArray *c9_x_y = NULL;
  uint8_T c9_w_hoistedGlobal;
  uint8_T c9_x_u;
  const mxArray *c9_y_y = NULL;
  uint8_T c9_x_hoistedGlobal;
  uint8_T c9_y_u;
  const mxArray *c9_ab_y = NULL;
  const mxArray *c9_ab_u;
  const mxArray *c9_bb_y = NULL;
  const mxArray *c9_bb_u;
  const mxArray *c9_cb_y = NULL;
  const mxArray *c9_cb_u;
  const mxArray *c9_db_y = NULL;
  const mxArray *c9_db_u;
  const mxArray *c9_eb_y = NULL;
  const mxArray *c9_eb_u;
  const mxArray *c9_fb_y = NULL;
  const mxArray *c9_fb_u;
  const mxArray *c9_gb_y = NULL;
  const mxArray *c9_gb_u;
  const mxArray *c9_hb_y = NULL;
  const mxArray *c9_hb_u;
  const mxArray *c9_ib_y = NULL;
  real_T *c9_APUProblem;
  real_T *c9_CabinPProblem;
  real_T *c9_FuelPProblem;
  real_T *c9_FuelQProblem;
  real_T *c9_HydProblem;
  real_T *c9_LandingGearMode;
  real_T *c9_OilPProblem;
  real_T *c9_RPMProblem;
  real_T *c9_TempProblem;
  real_T (*c9_output_msgID)[10];
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_output_msgID = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  sf_mex_assign(&c9_subchartSimStateInfo,
                sf_exported_auto_getSimstatec17_CockpitDisplayLib
                (chartInstance->c9_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_b_subchartSimStateInfo,
                sf_exported_auto_getSimstatec15_CockpitDisplayLib
                (chartInstance->c9_b_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_c_subchartSimStateInfo,
                sf_exported_auto_getSimstatec16_CockpitDisplayLib
                (chartInstance->c9_c_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_d_subchartSimStateInfo,
                sf_exported_auto_getSimstatec2_CockpitDisplayLib
                (chartInstance->c9_d_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_e_subchartSimStateInfo,
                sf_exported_auto_getSimstatec13_CockpitDisplayLib
                (chartInstance->c9_e_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_f_subchartSimStateInfo,
                sf_exported_auto_getSimstatec10_CockpitDisplayLib
                (chartInstance->c9_f_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_g_subchartSimStateInfo,
                sf_exported_auto_getSimstatec11_CockpitDisplayLib
                (chartInstance->c9_g_subchartSimstruct), TRUE);
  sf_mex_assign(&c9_h_subchartSimStateInfo,
                sf_exported_auto_getSimstatec3_LandingGearModeLib
                (chartInstance->c9_h_subchartSimstruct), TRUE);
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(33), FALSE);
  c9_hoistedGlobal = *c9_APUProblem;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_CabinPProblem;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_FuelPProblem;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_FuelQProblem;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = *c9_HydProblem;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_f_hoistedGlobal = *c9_LandingGearMode;
  c9_f_u = c9_f_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_g_hoistedGlobal = *c9_OilPProblem;
  c9_g_u = c9_g_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_h_hoistedGlobal = *c9_RPMProblem;
  c9_h_u = c9_h_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_i_hoistedGlobal = *c9_TempProblem;
  c9_i_u = c9_i_hoistedGlobal;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  for (c9_i0 = 0; c9_i0 < 10; c9_i0++) {
    c9_j_u[c9_i0] = (*c9_output_msgID)[c9_i0];
  }

  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_j_u, 0, 0U, 1U, 0U, 2, 10, 1),
                FALSE);
  sf_mex_setcell(c9_y, 9, c9_k_y);
  c9_j_hoistedGlobal = chartInstance->c9_id;
  c9_k_u = c9_j_hoistedGlobal;
  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", &c9_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 10, c9_l_y);
  c9_k_hoistedGlobal = chartInstance->c9_is_active_c9_CockpitDisplayLib;
  c9_l_u = c9_k_hoistedGlobal;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 11, c9_m_y);
  c9_l_hoistedGlobal = chartInstance->c9_is_active_ComponentModes;
  c9_m_u = c9_l_hoistedGlobal;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 12, c9_n_y);
  c9_m_hoistedGlobal = chartInstance->c9_is_active_RPM;
  c9_n_u = c9_m_hoistedGlobal;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_n_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 13, c9_o_y);
  c9_n_hoistedGlobal = chartInstance->c9_is_active_Temp;
  c9_o_u = c9_n_hoistedGlobal;
  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_create("y", &c9_o_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 14, c9_p_y);
  c9_o_hoistedGlobal = chartInstance->c9_is_active_OilP;
  c9_p_u = c9_o_hoistedGlobal;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_p_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 15, c9_q_y);
  c9_p_hoistedGlobal = chartInstance->c9_is_active_Hyd;
  c9_q_u = c9_p_hoistedGlobal;
  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", &c9_q_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 16, c9_r_y);
  c9_q_hoistedGlobal = chartInstance->c9_is_active_APU;
  c9_r_u = c9_q_hoistedGlobal;
  c9_s_y = NULL;
  sf_mex_assign(&c9_s_y, sf_mex_create("y", &c9_r_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 17, c9_s_y);
  c9_r_hoistedGlobal = chartInstance->c9_is_active_CabinPressure;
  c9_s_u = c9_r_hoistedGlobal;
  c9_t_y = NULL;
  sf_mex_assign(&c9_t_y, sf_mex_create("y", &c9_s_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 18, c9_t_y);
  c9_s_hoistedGlobal = chartInstance->c9_is_active_WarningsComputation;
  c9_t_u = c9_s_hoistedGlobal;
  c9_u_y = NULL;
  sf_mex_assign(&c9_u_y, sf_mex_create("y", &c9_t_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 19, c9_u_y);
  c9_t_hoistedGlobal = chartInstance->c9_is_active_FlightPhases;
  c9_u_u = c9_t_hoistedGlobal;
  c9_v_y = NULL;
  sf_mex_assign(&c9_v_y, sf_mex_create("y", &c9_u_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 20, c9_v_y);
  c9_u_hoistedGlobal = chartInstance->c9_is_active_Fuel;
  c9_v_u = c9_u_hoistedGlobal;
  c9_w_y = NULL;
  sf_mex_assign(&c9_w_y, sf_mex_create("y", &c9_v_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 21, c9_w_y);
  c9_v_hoistedGlobal = chartInstance->c9_is_active_LandingGear;
  c9_w_u = c9_v_hoistedGlobal;
  c9_x_y = NULL;
  sf_mex_assign(&c9_x_y, sf_mex_create("y", &c9_w_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 22, c9_x_y);
  c9_w_hoistedGlobal = chartInstance->c9_is_WarningsComputation;
  c9_x_u = c9_w_hoistedGlobal;
  c9_y_y = NULL;
  sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_x_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 23, c9_y_y);
  c9_x_hoistedGlobal = chartInstance->c9_is_FlightPhases;
  c9_y_u = c9_x_hoistedGlobal;
  c9_ab_y = NULL;
  sf_mex_assign(&c9_ab_y, sf_mex_create("y", &c9_y_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 24, c9_ab_y);
  c9_ab_u = sf_mex_dup(c9_c_subchartSimStateInfo);
  c9_bb_y = NULL;
  sf_mex_assign(&c9_bb_y, sf_mex_duplicatearraysafe(&c9_ab_u), FALSE);
  sf_mex_destroy(&c9_ab_u);
  sf_mex_setcell(c9_y, 25, c9_bb_y);
  c9_bb_u = sf_mex_dup(c9_subchartSimStateInfo);
  c9_cb_y = NULL;
  sf_mex_assign(&c9_cb_y, sf_mex_duplicatearraysafe(&c9_bb_u), FALSE);
  sf_mex_destroy(&c9_bb_u);
  sf_mex_setcell(c9_y, 26, c9_cb_y);
  c9_cb_u = sf_mex_dup(c9_b_subchartSimStateInfo);
  c9_db_y = NULL;
  sf_mex_assign(&c9_db_y, sf_mex_duplicatearraysafe(&c9_cb_u), FALSE);
  sf_mex_destroy(&c9_cb_u);
  sf_mex_setcell(c9_y, 27, c9_db_y);
  c9_db_u = sf_mex_dup(c9_e_subchartSimStateInfo);
  c9_eb_y = NULL;
  sf_mex_assign(&c9_eb_y, sf_mex_duplicatearraysafe(&c9_db_u), FALSE);
  sf_mex_destroy(&c9_db_u);
  sf_mex_setcell(c9_y, 28, c9_eb_y);
  c9_eb_u = sf_mex_dup(c9_f_subchartSimStateInfo);
  c9_fb_y = NULL;
  sf_mex_assign(&c9_fb_y, sf_mex_duplicatearraysafe(&c9_eb_u), FALSE);
  sf_mex_destroy(&c9_eb_u);
  sf_mex_setcell(c9_y, 29, c9_fb_y);
  c9_fb_u = sf_mex_dup(c9_g_subchartSimStateInfo);
  c9_gb_y = NULL;
  sf_mex_assign(&c9_gb_y, sf_mex_duplicatearraysafe(&c9_fb_u), FALSE);
  sf_mex_destroy(&c9_fb_u);
  sf_mex_setcell(c9_y, 30, c9_gb_y);
  c9_gb_u = sf_mex_dup(c9_d_subchartSimStateInfo);
  c9_hb_y = NULL;
  sf_mex_assign(&c9_hb_y, sf_mex_duplicatearraysafe(&c9_gb_u), FALSE);
  sf_mex_destroy(&c9_gb_u);
  sf_mex_setcell(c9_y, 31, c9_hb_y);
  c9_hb_u = sf_mex_dup(c9_h_subchartSimStateInfo);
  c9_ib_y = NULL;
  sf_mex_assign(&c9_ib_y, sf_mex_duplicatearraysafe(&c9_hb_u), FALSE);
  sf_mex_destroy(&c9_hb_u);
  sf_mex_setcell(c9_y, 32, c9_ib_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[10];
  int32_T c9_i1;
  real_T *c9_APUProblem;
  real_T *c9_CabinPProblem;
  real_T *c9_FuelPProblem;
  real_T *c9_FuelQProblem;
  real_T *c9_HydProblem;
  real_T *c9_LandingGearMode;
  real_T *c9_OilPProblem;
  real_T *c9_RPMProblem;
  real_T *c9_TempProblem;
  real_T (*c9_output_msgID)[10];
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_output_msgID = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_APUProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "APUProblem");
  *c9_CabinPProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "CabinPProblem");
  *c9_FuelPProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 2)), "FuelPProblem");
  *c9_FuelQProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 3)), "FuelQProblem");
  *c9_HydProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 4)), "HydProblem");
  *c9_LandingGearMode = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 5)), "LandingGearMode");
  *c9_OilPProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 6)), "OilPProblem");
  *c9_RPMProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 7)), "RPMProblem");
  *c9_TempProblem = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 8)), "TempProblem");
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 9)),
                        "output_msgID", c9_dv0);
  for (c9_i1 = 0; c9_i1 < 10; c9_i1++) {
    (*c9_output_msgID)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_id = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 10)), "id");
  chartInstance->c9_is_active_c9_CockpitDisplayLib = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 11)),
     "is_active_c9_CockpitDisplayLib");
  chartInstance->c9_is_active_ComponentModes = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 12)),
     "is_active_ComponentModes");
  chartInstance->c9_is_active_RPM = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 13)), "is_active_RPM");
  chartInstance->c9_is_active_Temp = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 14)), "is_active_Temp");
  chartInstance->c9_is_active_OilP = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 15)), "is_active_OilP");
  chartInstance->c9_is_active_Hyd = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 16)), "is_active_Hyd");
  chartInstance->c9_is_active_APU = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 17)), "is_active_APU");
  chartInstance->c9_is_active_CabinPressure = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 18)),
     "is_active_CabinPressure");
  chartInstance->c9_is_active_WarningsComputation = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 19)),
     "is_active_WarningsComputation");
  chartInstance->c9_is_active_FlightPhases = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 20)), "is_active_FlightPhases");
  chartInstance->c9_is_active_Fuel = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 21)), "is_active_Fuel");
  chartInstance->c9_is_active_LandingGear = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 22)), "is_active_LandingGear");
  chartInstance->c9_is_WarningsComputation = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 23)), "is_WarningsComputation");
  chartInstance->c9_is_FlightPhases = c9_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 24)), "is_FlightPhases");
  sf_mex_assign(&c9_c_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 25)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 26)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_b_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 27)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_e_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 28)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_f_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 29)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_g_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 30)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_d_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 31)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&c9_h_subchartSimStateInfo, c9_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 32)), "subchartSimStateInfo"), TRUE);
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 33)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_CockpitDisplayLib(chartInstance);
  sf_exported_auto_setSimstatec17_CockpitDisplayLib
    (chartInstance->c9_subchartSimstruct, sf_mex_dup(c9_subchartSimStateInfo));
  sf_exported_auto_setSimstatec15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct, sf_mex_dup(c9_b_subchartSimStateInfo));
  sf_exported_auto_setSimstatec16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct, sf_mex_dup(c9_c_subchartSimStateInfo));
  sf_exported_auto_setSimstatec2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct, sf_mex_dup(c9_d_subchartSimStateInfo));
  sf_exported_auto_setSimstatec13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct, sf_mex_dup(c9_e_subchartSimStateInfo));
  sf_exported_auto_setSimstatec10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct, sf_mex_dup(c9_f_subchartSimStateInfo));
  sf_exported_auto_setSimstatec11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct, sf_mex_dup(c9_g_subchartSimStateInfo));
  sf_exported_auto_setSimstatec3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct, sf_mex_dup(c9_h_subchartSimStateInfo));
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_active_FlightPhases == 1U) {
      chartInstance->c9_tp_FlightPhases = 1U;
    } else {
      chartInstance->c9_tp_FlightPhases = 0U;
    }

    if (chartInstance->c9_is_FlightPhases == c9_IN_EnginesOff) {
      chartInstance->c9_tp_EnginesOff = 1U;
    } else {
      chartInstance->c9_tp_EnginesOff = 0U;
    }

    if (chartInstance->c9_is_FlightPhases == c9_IN_Land) {
      chartInstance->c9_tp_Land = 1U;
    } else {
      chartInstance->c9_tp_Land = 0U;
    }

    if (chartInstance->c9_is_FlightPhases == c9_IN_PushbackAndTaxi) {
      chartInstance->c9_tp_PushbackAndTaxi = 1U;
    } else {
      chartInstance->c9_tp_PushbackAndTaxi = 0U;
    }

    if (chartInstance->c9_is_FlightPhases == c9_IN_TakeoffCruiseDescent) {
      chartInstance->c9_tp_TakeoffCruiseDescent = 1U;
    } else {
      chartInstance->c9_tp_TakeoffCruiseDescent = 0U;
    }

    if (chartInstance->c9_is_active_ComponentModes == 1U) {
      chartInstance->c9_tp_ComponentModes = 1U;
    } else {
      chartInstance->c9_tp_ComponentModes = 0U;
    }

    if (chartInstance->c9_is_active_RPM == 1U) {
      chartInstance->c9_tp_RPM = 1U;
    } else {
      chartInstance->c9_tp_RPM = 0U;
    }

    if (chartInstance->c9_is_active_Temp == 1U) {
      chartInstance->c9_tp_Temp = 1U;
    } else {
      chartInstance->c9_tp_Temp = 0U;
    }

    if (chartInstance->c9_is_active_Fuel == 1U) {
      chartInstance->c9_tp_Fuel = 1U;
    } else {
      chartInstance->c9_tp_Fuel = 0U;
    }

    if (chartInstance->c9_is_active_OilP == 1U) {
      chartInstance->c9_tp_OilP = 1U;
    } else {
      chartInstance->c9_tp_OilP = 0U;
    }

    if (chartInstance->c9_is_active_Hyd == 1U) {
      chartInstance->c9_tp_Hyd = 1U;
    } else {
      chartInstance->c9_tp_Hyd = 0U;
    }

    if (chartInstance->c9_is_active_APU == 1U) {
      chartInstance->c9_tp_APU = 1U;
    } else {
      chartInstance->c9_tp_APU = 0U;
    }

    if (chartInstance->c9_is_active_CabinPressure == 1U) {
      chartInstance->c9_tp_CabinPressure = 1U;
    } else {
      chartInstance->c9_tp_CabinPressure = 0U;
    }

    if (chartInstance->c9_is_active_LandingGear == 1U) {
      chartInstance->c9_tp_LandingGear = 1U;
    } else {
      chartInstance->c9_tp_LandingGear = 0U;
    }

    if (chartInstance->c9_is_active_WarningsComputation == 1U) {
      chartInstance->c9_tp_WarningsComputation = 1U;
    } else {
      chartInstance->c9_tp_WarningsComputation = 0U;
    }

    if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase1) {
      chartInstance->c9_tp_Phase1 = 1U;
    } else {
      chartInstance->c9_tp_Phase1 = 0U;
    }

    if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase2) {
      chartInstance->c9_tp_Phase2 = 1U;
    } else {
      chartInstance->c9_tp_Phase2 = 0U;
    }

    if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase3) {
      chartInstance->c9_tp_Phase3 = 1U;
    } else {
      chartInstance->c9_tp_Phase3 = 0U;
    }

    if (chartInstance->c9_is_WarningsComputation == c9_IN_Phase4) {
      chartInstance->c9_tp_Phase4 = 1U;
    } else {
      chartInstance->c9_tp_Phase4 = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c9_subchartSimStateInfo);
  sf_mex_destroy(&c9_b_subchartSimStateInfo);
  sf_mex_destroy(&c9_c_subchartSimStateInfo);
  sf_mex_destroy(&c9_d_subchartSimStateInfo);
  sf_mex_destroy(&c9_e_subchartSimStateInfo);
  sf_mex_destroy(&c9_f_subchartSimStateInfo);
  sf_mex_destroy(&c9_g_subchartSimStateInfo);
  sf_mex_destroy(&c9_h_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  c9_set_sim_state_side_effects_c9_CockpitDisplayLib(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  sf_exported_auto_gatewayc17_CockpitDisplayLib
    (chartInstance->c9_subchartSimstruct);
  sf_exported_auto_gatewayc15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct);
  sf_exported_auto_gatewayc16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct);
  sf_exported_auto_gatewayc2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct);
  sf_exported_auto_gatewayc13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct);
  sf_exported_auto_gatewayc10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct);
  sf_exported_auto_gatewayc11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct);
  sf_exported_auto_gatewayc3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
  chartInstance->c9_sfEvent = CALL_EVENT;
  sf_exported_auto_increment_call_counterc17_CockpitDisplayLib
    (chartInstance->c9_subchartSimstruct);
  sf_exported_auto_increment_call_counterc15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct);
  sf_exported_auto_increment_call_counterc16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct);
  sf_exported_auto_increment_call_counterc2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct);
  sf_exported_auto_increment_call_counterc13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct);
  sf_exported_auto_increment_call_counterc10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct);
  sf_exported_auto_increment_call_counterc11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct);
  sf_exported_auto_increment_call_counterc3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct);
  sf_exported_auto_stepBuffersc17_CockpitDisplayLib
    (chartInstance->c9_subchartSimstruct);
  sf_exported_auto_stepBuffersc15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct);
  sf_exported_auto_stepBuffersc16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct);
  sf_exported_auto_stepBuffersc2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct);
  sf_exported_auto_stepBuffersc13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct);
  sf_exported_auto_stepBuffersc10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct);
  sf_exported_auto_stepBuffersc11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct);
  sf_exported_auto_stepBuffersc3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct);
  c9_c9_CockpitDisplayLib(chartInstance);
  sf_exported_auto_reset_call_counterc17_CockpitDisplayLib
    (chartInstance->c9_subchartSimstruct);
  sf_exported_auto_reset_call_counterc15_CockpitDisplayLib
    (chartInstance->c9_b_subchartSimstruct);
  sf_exported_auto_reset_call_counterc16_CockpitDisplayLib
    (chartInstance->c9_c_subchartSimstruct);
  sf_exported_auto_reset_call_counterc2_CockpitDisplayLib
    (chartInstance->c9_d_subchartSimstruct);
  sf_exported_auto_reset_call_counterc13_CockpitDisplayLib
    (chartInstance->c9_e_subchartSimstruct);
  sf_exported_auto_reset_call_counterc10_CockpitDisplayLib
    (chartInstance->c9_f_subchartSimstruct);
  sf_exported_auto_reset_call_counterc11_CockpitDisplayLib
    (chartInstance->c9_g_subchartSimstruct);
  sf_exported_auto_reset_call_counterc3_LandingGearModeLib
    (chartInstance->c9_h_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c9_is_active_Temp == 1U) {
    sf_exported_auto_check_state_inconsistency_c17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_OilP == 1U) {
    sf_exported_auto_check_state_inconsistency_c15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_RPM == 1U) {
    sf_exported_auto_check_state_inconsistency_c16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Fuel == 1U) {
    sf_exported_auto_check_state_inconsistency_c2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_Hyd == 1U) {
    sf_exported_auto_check_state_inconsistency_c13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_APU == 1U) {
    sf_exported_auto_check_state_inconsistency_c10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_CabinPressure == 1U) {
    sf_exported_auto_check_state_inconsistency_c11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
  }

  if (chartInstance->c9_is_active_LandingGear == 1U) {
    sf_exported_auto_check_state_inconsistency_c3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
  }
}

static void c9_c9_CockpitDisplayLib(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_dv1[10];
  int32_T c9_i2;
  uint32_T c9_b_debug_family_var_map[3];
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  int32_T c9_i3;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  int32_T c9_i4;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  int32_T c9_i5;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 0.0;
  int32_T c9_i6;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 0.0;
  int32_T c9_i7;
  real_T c9_k_nargin = 0.0;
  real_T c9_k_nargout = 0.0;
  int32_T c9_i8;
  real_T c9_l_nargin = 0.0;
  real_T c9_l_nargout = 0.0;
  int32_T c9_i9;
  real_T (*c9_output_msgID)[10];
  c9_output_msgID = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
  if (chartInstance->c9_is_active_c9_CockpitDisplayLib == 0U) {
    sf_exported_auto_initBuffersc17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
    sf_exported_auto_initBuffersc15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
    sf_exported_auto_initBuffersc16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
    sf_exported_auto_initBuffersc2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
    sf_exported_auto_initBuffersc13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
    sf_exported_auto_initBuffersc10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
    sf_exported_auto_initBuffersc11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
    sf_exported_auto_initBuffersc3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_active_c9_CockpitDisplayLib = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_active_FlightPhases = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_FlightPhases = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 89U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_FlightPhases = c9_IN_EnginesOff;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_EnginesOff = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    c9_set_FlightMode(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c9_is_active_ComponentModes = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_ComponentModes = 1U;
    chartInstance->c9_is_active_RPM = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_RPM = 1U;
    sf_exported_auto_enterc16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
    chartInstance->c9_is_active_Temp = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_Temp = 1U;
    sf_exported_auto_enterc17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
    chartInstance->c9_is_active_Fuel = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_Fuel = 1U;
    sf_exported_auto_enterc2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
    chartInstance->c9_is_active_OilP = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_OilP = 1U;
    sf_exported_auto_enterc15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
    chartInstance->c9_is_active_Hyd = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_Hyd = 1U;
    sf_exported_auto_enterc13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
    chartInstance->c9_is_active_APU = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_APU = 1U;
    sf_exported_auto_enterc10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
    chartInstance->c9_is_active_CabinPressure = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_CabinPressure = 1U;
    sf_exported_auto_enterc11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
    chartInstance->c9_is_active_LandingGear = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_LandingGear = 1U;
    sf_exported_auto_enterc3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
    chartInstance->c9_is_active_WarningsComputation = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_WarningsComputation = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_WarningsComputation = c9_IN_Phase1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_Phase1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_i_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    c9_calcMsgID(chartInstance, c9_dv1);
    for (c9_i2 = 0; c9_i2 < 10; c9_i2++) {
      (*c9_output_msgID)[c9_i2] = c9_dv1[c9_i2];
    }

    c9_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    c9_FlightPhases(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc16_CockpitDisplayLib
      (chartInstance->c9_c_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc17_CockpitDisplayLib
      (chartInstance->c9_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc2_CockpitDisplayLib
      (chartInstance->c9_d_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc15_CockpitDisplayLib
      (chartInstance->c9_b_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc13_CockpitDisplayLib
      (chartInstance->c9_e_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc10_CockpitDisplayLib
      (chartInstance->c9_f_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc11_CockpitDisplayLib
      (chartInstance->c9_g_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
    sf_exported_auto_duringc3_LandingGearModeLib
      (chartInstance->c9_h_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
    switch (chartInstance->c9_is_WarningsComputation) {
     case c9_IN_Phase1:
      CV_STATE_EVAL(14, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_x_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_out = CV_EML_IF(1, 0, 0, c9_get_FlightMode(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
        chartInstance->c9_is_WarningsComputation = c9_IN_Phase2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase2 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_l_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_b_calcMsgID(chartInstance, c9_dv1);
        for (c9_i3 = 0; c9_i3 < 10; c9_i3++) {
          (*c9_output_msgID)[c9_i3] = c9_dv1[c9_i3];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_k_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_calcMsgID(chartInstance, c9_dv1);
        for (c9_i4 = 0; c9_i4 < 10; c9_i4++) {
          (*c9_output_msgID)[c9_i4] = c9_dv1[c9_i4];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
      break;

     case c9_IN_Phase2:
      CV_STATE_EVAL(14, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_y_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_b_out = CV_EML_IF(2, 0, 0, c9_get_FlightMode(chartInstance, 0) == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_is_WarningsComputation = c9_IN_Phase3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase3 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_o_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_c_calcMsgID(chartInstance, c9_dv1);
        for (c9_i5 = 0; c9_i5 < 10; c9_i5++) {
          (*c9_output_msgID)[c9_i5] = c9_dv1[c9_i5];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_n_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_b_calcMsgID(chartInstance, c9_dv1);
        for (c9_i6 = 0; c9_i6 < 10; c9_i6++) {
          (*c9_output_msgID)[c9_i6] = c9_dv1[c9_i6];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c9_sfEvent);
      break;

     case c9_IN_Phase3:
      CV_STATE_EVAL(14, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ab_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_c_out = CV_EML_IF(3, 0, 0, c9_get_FlightMode(chartInstance, 0) == 3.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
        chartInstance->c9_is_WarningsComputation = c9_IN_Phase4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_Phase4 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_r_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_d_calcMsgID(chartInstance, c9_dv1);
        for (c9_i7 = 0; c9_i7 < 10; c9_i7++) {
          (*c9_output_msgID)[c9_i7] = c9_dv1[c9_i7];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_q_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        c9_c_calcMsgID(chartInstance, c9_dv1);
        for (c9_i8 = 0; c9_i8 < 10; c9_i8++) {
          (*c9_output_msgID)[c9_i8] = c9_dv1[c9_i8];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
      break;

     case c9_IN_Phase4:
      CV_STATE_EVAL(14, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_t_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_l_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_l_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_d_calcMsgID(chartInstance, c9_dv1);
      for (c9_i9 = 0; c9_i9 < 10; c9_i9++) {
        (*c9_output_msgID)[c9_i9] = c9_dv1[c9_i9];
      }

      c9_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c9_sfEvent);
      break;

     default:
      CV_STATE_EVAL(14, 0, 0);
      chartInstance->c9_is_WarningsComputation = c9_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_CockpitDisplayLib
  (SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
  chartInstance->c9_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.Temp");
  chartInstance->c9_b_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.OilP");
  chartInstance->c9_c_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.RPM");
  chartInstance->c9_d_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.Fuel");
  chartInstance->c9_e_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.Hyd");
  chartInstance->c9_f_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.APU");
  chartInstance->c9_g_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.CabinPressure");
  chartInstance->c9_h_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "ComponentModes.LandingGear");
}

static void c9_FlightPhases(SFc9_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 0.0;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 0.0;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 0.0;
  real_T *c9_Engine_Mode;
  c9_FlightInputs *c9_PFD;
  c9_PFD = (c9_FlightInputs *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_Engine_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_FlightPhases) {
   case c9_IN_EnginesOff:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 90U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_u_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_out = CV_EML_IF(90, 0, 0, *c9_Engine_Mode == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 90U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_EnginesOff = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      chartInstance->c9_is_FlightPhases = c9_IN_PushbackAndTaxi;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_PushbackAndTaxi = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_c_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_b_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_Land:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_h_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    c9_set_FlightMode(chartInstance, 0, 3.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_PushbackAndTaxi:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 91U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_v_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(91, 0, 0, *(real_T *)((char_T *)c9_PFD + 16) > 180.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 91U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_PushbackAndTaxi = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_is_FlightPhases = c9_IN_TakeoffCruiseDescent;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_TakeoffCruiseDescent = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_e_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_d_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_TakeoffCruiseDescent:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 92U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_w_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_c_out = CV_EML_IF(92, 0, 0, *(real_T *)((char_T *)c9_PFD + 16) < 180.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 92U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_TakeoffCruiseDescent = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_is_FlightPhases = c9_IN_Land;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_Land = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_g_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 3.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_f_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      c9_set_FlightMode(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    chartInstance->c9_is_FlightPhases = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i10;
  real_T c9_b_inData[10];
  int32_T c9_i11;
  real_T c9_u[10];
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i10 = 0; c9_i10 < 10; c9_i10++) {
    c9_b_inData[c9_i10] = (*(real_T (*)[10])c9_inData)[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 10; c9_i11++) {
    c9_u[c9_i11] = c9_b_inData[c9_i11];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10])
{
  real_T c9_dv2[10];
  int32_T c9_i12;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 1, 10);
  for (c9_i12 = 0; c9_i12 < 10; c9_i12++) {
    c9_y[c9_i12] = c9_dv2[c9_i12];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_msgID;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[10];
  int32_T c9_i13;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_msgID = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_msgID), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_msgID);
  for (c9_i13 = 0; c9_i13 < 10; c9_i13++) {
    (*(real_T (*)[10])c9_outData)[c9_i13] = c9_y[c9_i13];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static boolean_T c9_d_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_guard4;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_guard4 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_guard4), &c9_thisId);
  sf_mex_destroy(&c9_guard4);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                FALSE);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
}

static const mxArray *c9_emlrt_marshallOut(char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), FALSE);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c9_y;
}

static void c9_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_guard1;
  boolean_T c9_guard2;
  boolean_T c9_guard3;
  boolean_T c9_guard4;
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i14;
  boolean_T c9_evilsf_internal_predicateOutput;
  boolean_T c9_b_evilsf_internal_predicateOutput;
  boolean_T c9_c_evilsf_internal_predicateOutput;
  boolean_T c9_d_evilsf_internal_predicateOutput;
  boolean_T c9_e_evilsf_internal_predicateOutput;
  boolean_T c9_f_evilsf_internal_predicateOutput;
  boolean_T c9_g_evilsf_internal_predicateOutput;
  real_T *c9_RPMProblem;
  real_T *c9_APUProblem;
  real_T *c9_LandingGearMode;
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_j_debug_family_names,
    c9_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard1, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard2, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard3, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard4, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_msgID, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  chartInstance->c9_id = 1.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  for (c9_i14 = 0; c9_i14 < 10; c9_i14++) {
    c9_msgID[c9_i14] = 0.0;
  }

  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c9_sfEvent);
  c9_evilsf_internal_predicateOutput = CV_EML_IF(5, 0, 0, *c9_RPMProblem == 0.0);
  if (c9_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #688 in Chart \'Warnings\' (#661): {msgID(id) = 5; id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #688 in Chart \'Warnings\' (#661): {msgID(id) = 5; id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 5.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #687 in Chart \'Warnings\' (#661): {msgID(id) = 12;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #687 in Chart \'Warnings\' (#661): {msgID(id) = 12;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 12.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c9_sfEvent);
  c9_b_evilsf_internal_predicateOutput = CV_EML_IF(10, 0, 0, *c9_APUProblem ==
    1.0);
  if (c9_b_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #693 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #693 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 11.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  c9_guard1 = FALSE;
  c9_guard2 = FALSE;
  c9_guard3 = FALSE;
  c9_guard4 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c9_sfEvent);
  c9_c_evilsf_internal_predicateOutput = CV_EML_IF(15, 0, 0, *c9_LandingGearMode
    == 0.0);
  if (c9_c_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #698 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #698 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 41.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
    c9_guard4 = TRUE;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c9_sfEvent);
    c9_d_evilsf_internal_predicateOutput = CV_EML_IF(18, 0, 0,
      *c9_LandingGearMode == 1.0);
    if (c9_d_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #701 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                             ^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "Transition #701 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                                   ^^",
        chartInstance->c9_id), 1, 10, 1, 0) - 1] = 42.0;
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      chartInstance->c9_id++;
      c9_updateDataWrittenToVector(chartInstance, 1U);
      c9_guard4 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 125U,
                   chartInstance->c9_sfEvent);
      c9_e_evilsf_internal_predicateOutput = CV_EML_IF(125, 0, 0,
        *c9_LandingGearMode == 2.0);
      if (c9_e_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 125U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 126U, chartInstance->c9_sfEvent);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #704 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                             ^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "Transition #704 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                                   ^^",
          chartInstance->c9_id), 1, 10, 1, 0) - 1] = 45.0;
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        chartInstance->c9_id++;
        c9_updateDataWrittenToVector(chartInstance, 1U);
        c9_guard3 = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 124U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                     chartInstance->c9_sfEvent);
        c9_f_evilsf_internal_predicateOutput = CV_EML_IF(21, 0, 0,
          *c9_LandingGearMode == 3.0);
        if (c9_f_evilsf_internal_predicateOutput) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "Transition #707 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                             ^^^^^",
            (int32_T)_SFD_INTEGER_CHECK(
            "Transition #707 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                                   ^^",
            chartInstance->c9_id), 1, 10, 1, 0) - 1] = 43.0;
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          chartInstance->c9_id++;
          c9_updateDataWrittenToVector(chartInstance, 1U);
          c9_guard2 = TRUE;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                       chartInstance->c9_sfEvent);
          c9_g_evilsf_internal_predicateOutput = CV_EML_IF(24, 0, 0,
            *c9_LandingGearMode == 4.0);
          if (c9_g_evilsf_internal_predicateOutput) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
              "Transition #710 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                             ^^^^^",
              (int32_T)_SFD_INTEGER_CHECK(
              "Transition #710 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                                   ^^",
              chartInstance->c9_id), 1, 10, 1, 0) - 1] = 44.0;
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            chartInstance->c9_id++;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            c9_guard1 = TRUE;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
          }
        }
      }
    }
  }

  if (c9_guard4) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
    c9_guard3 = TRUE;
  }

  if (c9_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 123U, chartInstance->c9_sfEvent);
    c9_guard2 = TRUE;
  }

  if (c9_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
    c9_guard1 = TRUE;
  }

  if (c9_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
}

static void c9_b_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_guard1;
  boolean_T c9_guard2;
  boolean_T c9_guard3;
  boolean_T c9_guard4;
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i15;
  boolean_T c9_evilsf_internal_predicateOutput;
  boolean_T c9_b_evilsf_internal_predicateOutput;
  boolean_T c9_c_evilsf_internal_predicateOutput;
  boolean_T c9_d_evilsf_internal_predicateOutput;
  boolean_T c9_e_evilsf_internal_predicateOutput;
  boolean_T c9_f_evilsf_internal_predicateOutput;
  boolean_T c9_g_evilsf_internal_predicateOutput;
  boolean_T c9_h_evilsf_internal_predicateOutput;
  boolean_T c9_i_evilsf_internal_predicateOutput;
  boolean_T c9_j_evilsf_internal_predicateOutput;
  boolean_T c9_k_evilsf_internal_predicateOutput;
  real_T *c9_FuelQProblem;
  real_T *c9_FuelPProblem;
  real_T *c9_OilPProblem;
  real_T *c9_HydProblem;
  real_T *c9_LandingGearMode;
  real_T *c9_RPMProblem;
  real_T *c9_APUProblem;
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_m_debug_family_names,
    c9_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard1, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard2, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard3, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard4, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_msgID, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c9_sfEvent);
  chartInstance->c9_id = 1.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  for (c9_i15 = 0; c9_i15 < 10; c9_i15++) {
    c9_msgID[c9_i15] = 0.0;
  }

  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U, chartInstance->c9_sfEvent);
  c9_evilsf_internal_predicateOutput = CV_EML_IF(32, 0, 0, *c9_FuelQProblem ==
    1.0);
  if (c9_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #747 in Chart \'Warnings\' (#661): {msgID(id) = 51; id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #747 in Chart \'Warnings\' (#661): {msgID(id) = 51; id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 51.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 99U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 100U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, chartInstance->c9_sfEvent);
  c9_b_evilsf_internal_predicateOutput = CV_EML_IF(35, 0, 0, *c9_FuelPProblem ==
    1.0);
  if (c9_b_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #752 in Chart \'Warnings\' (#661): {msgID(id) = 52; id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #752 in Chart \'Warnings\' (#661): {msgID(id) = 52; id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 52.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 98U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 97U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U, chartInstance->c9_sfEvent);
  c9_c_evilsf_internal_predicateOutput = CV_EML_IF(38, 0, 0, *c9_OilPProblem ==
    1.0);
  if (c9_c_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #757 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #757 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 3.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 96U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #756 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #756 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 4.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 95U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U, chartInstance->c9_sfEvent);
  c9_d_evilsf_internal_predicateOutput = CV_EML_IF(41, 0, 0, *c9_HydProblem ==
    1.0);
  if (c9_d_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #762 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #762 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 31.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #761 in Chart \'Warnings\' (#661): {msgID(id) = 32;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #761 in Chart \'Warnings\' (#661): {msgID(id) = 32;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 32.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, chartInstance->c9_sfEvent);
  c9_guard1 = FALSE;
  c9_guard2 = FALSE;
  c9_guard3 = FALSE;
  c9_guard4 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 146U, chartInstance->c9_sfEvent);
  c9_e_evilsf_internal_predicateOutput = CV_EML_IF(146U, 0, 0,
    *c9_LandingGearMode == 0.0);
  if (c9_e_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 146U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 128U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #767 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #767 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 41.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 127U, chartInstance->c9_sfEvent);
    c9_guard4 = TRUE;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 145U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 140U,
                 chartInstance->c9_sfEvent);
    c9_f_evilsf_internal_predicateOutput = CV_EML_IF(140U, 0, 0,
      *c9_LandingGearMode == 1.0);
    if (c9_f_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 129U, chartInstance->c9_sfEvent);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #770 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                             ^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "Transition #770 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                                   ^^",
        chartInstance->c9_id), 1, 10, 1, 0) - 1] = 42.0;
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      chartInstance->c9_id++;
      c9_updateDataWrittenToVector(chartInstance, 1U);
      c9_guard4 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 144U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U,
                   chartInstance->c9_sfEvent);
      c9_g_evilsf_internal_predicateOutput = CV_EML_IF(139U, 0, 0,
        *c9_LandingGearMode == 2.0);
      if (c9_g_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 131U, chartInstance->c9_sfEvent);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #773 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                             ^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "Transition #773 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                                   ^^",
          chartInstance->c9_id), 1, 10, 1, 0) - 1] = 45.0;
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        chartInstance->c9_id++;
        c9_updateDataWrittenToVector(chartInstance, 1U);
        c9_guard3 = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 142U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 135U,
                     chartInstance->c9_sfEvent);
        c9_h_evilsf_internal_predicateOutput = CV_EML_IF(135U, 0, 0,
          *c9_LandingGearMode == 3.0);
        if (c9_h_evilsf_internal_predicateOutput) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 135U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 133U, chartInstance->c9_sfEvent);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "Transition #776 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                             ^^^^^",
            (int32_T)_SFD_INTEGER_CHECK(
            "Transition #776 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                                   ^^",
            chartInstance->c9_id), 1, 10, 1, 0) - 1] = 43.0;
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          chartInstance->c9_id++;
          c9_updateDataWrittenToVector(chartInstance, 1U);
          c9_guard2 = TRUE;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 138U,
                       chartInstance->c9_sfEvent);
          c9_i_evilsf_internal_predicateOutput = CV_EML_IF(138U, 0, 0,
            *c9_LandingGearMode == 4.0);
          if (c9_i_evilsf_internal_predicateOutput) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, chartInstance->c9_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, chartInstance->c9_sfEvent);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
              "Transition #779 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                             ^^^^^",
              (int32_T)_SFD_INTEGER_CHECK(
              "Transition #779 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                                   ^^",
              chartInstance->c9_id), 1, 10, 1, 0) - 1] = 44.0;
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            chartInstance->c9_id++;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            c9_guard1 = TRUE;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 143U, chartInstance->c9_sfEvent);
          }
        }
      }
    }
  }

  if (c9_guard4) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 130U, chartInstance->c9_sfEvent);
    c9_guard3 = TRUE;
  }

  if (c9_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 132U, chartInstance->c9_sfEvent);
    c9_guard2 = TRUE;
  }

  if (c9_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 134U, chartInstance->c9_sfEvent);
    c9_guard1 = TRUE;
  }

  if (c9_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U, chartInstance->c9_sfEvent);
  c9_j_evilsf_internal_predicateOutput = CV_EML_IF(45, 0, 0, *c9_RPMProblem ==
    1.0);
  if (c9_j_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #788 in Chart \'Warnings\' (#661): {msgID(id) = 6;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #788 in Chart \'Warnings\' (#661): {msgID(id) = 6;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 6.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 101U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #787 in Chart \'Warnings\' (#661): {msgID(id) = 2;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #787 in Chart \'Warnings\' (#661): {msgID(id) = 2;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 2.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 102U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U, chartInstance->c9_sfEvent);
  c9_k_evilsf_internal_predicateOutput = CV_EML_IF(48, 0, 0, *c9_APUProblem ==
    1.0);
  if (c9_k_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #793 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #793 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 11.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 103U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c9_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
}

static void c9_c_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_guard1;
  boolean_T c9_guard2;
  boolean_T c9_guard3;
  boolean_T c9_guard4;
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i16;
  boolean_T c9_evilsf_internal_predicateOutput;
  boolean_T c9_b_evilsf_internal_predicateOutput;
  boolean_T c9_c_evilsf_internal_predicateOutput;
  boolean_T c9_d_evilsf_internal_predicateOutput;
  boolean_T c9_e_evilsf_internal_predicateOutput;
  boolean_T c9_f_evilsf_internal_predicateOutput;
  boolean_T c9_g_evilsf_internal_predicateOutput;
  boolean_T c9_h_evilsf_internal_predicateOutput;
  boolean_T c9_i_evilsf_internal_predicateOutput;
  boolean_T c9_j_evilsf_internal_predicateOutput;
  boolean_T c9_k_evilsf_internal_predicateOutput;
  boolean_T c9_l_evilsf_internal_predicateOutput;
  real_T *c9_RPMProblem;
  real_T *c9_OilPProblem;
  real_T *c9_HydProblem;
  real_T *c9_APUProblem;
  real_T *c9_FuelQProblem;
  real_T *c9_FuelPProblem;
  real_T *c9_CabinPProblem;
  real_T *c9_LandingGearMode;
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_p_debug_family_names,
    c9_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard1, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard2, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard3, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard4, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_msgID, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c9_sfEvent);
  chartInstance->c9_id = 1.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  for (c9_i16 = 0; c9_i16 < 10; c9_i16++) {
    c9_msgID[c9_i16] = 0.0;
  }

  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U, chartInstance->c9_sfEvent);
  c9_evilsf_internal_predicateOutput = CV_EML_IF(52, 0, 0, *c9_RPMProblem == 1.0);
  if (c9_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #842 in Chart \'Warnings\' (#661): {msgID(id) = 6; id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #842 in Chart \'Warnings\' (#661): {msgID(id) = 6; id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 6.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 105U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #841 in Chart \'Warnings\' (#661): {msgID(id) = 2;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #841 in Chart \'Warnings\' (#661): {msgID(id) = 2;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 2.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 104U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U, chartInstance->c9_sfEvent);
  c9_b_evilsf_internal_predicateOutput = CV_EML_IF(55, 0, 0, *c9_OilPProblem ==
    1.0);
  if (c9_b_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #847 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #847 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 3.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 107U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #846 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #846 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 4.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 106U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 58U, chartInstance->c9_sfEvent);
  c9_c_evilsf_internal_predicateOutput = CV_EML_IF(58, 0, 0, *c9_HydProblem ==
    1.0);
  if (c9_c_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #852 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #852 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 31.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 108U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #851 in Chart \'Warnings\' (#661): {msgID(id) = 32;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #851 in Chart \'Warnings\' (#661): {msgID(id) = 32;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 32.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 109U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 61U, chartInstance->c9_sfEvent);
  c9_d_evilsf_internal_predicateOutput = CV_EML_IF(61, 0, 0, *c9_APUProblem ==
    1.0);
  if (c9_d_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #857 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #857 in Chart \'Warnings\' (#661): {msgID(id) = 11;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 11.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 110U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 111U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U, chartInstance->c9_sfEvent);
  c9_e_evilsf_internal_predicateOutput = CV_EML_IF(64, 0, 0, *c9_FuelQProblem ==
    1.0);
  if (c9_e_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #862 in Chart \'Warnings\' (#661): {msgID(id) = 51;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #862 in Chart \'Warnings\' (#661): {msgID(id) = 51;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 51.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 112U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 113U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U, chartInstance->c9_sfEvent);
  c9_f_evilsf_internal_predicateOutput = CV_EML_IF(67, 0, 0, *c9_FuelPProblem ==
    1.0);
  if (c9_f_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #867 in Chart \'Warnings\' (#661): {msgID(id) = 52;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #867 in Chart \'Warnings\' (#661): {msgID(id) = 52;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 52.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 114U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 115U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U, chartInstance->c9_sfEvent);
  c9_g_evilsf_internal_predicateOutput = CV_EML_IF(70, 0, 0, *c9_CabinPProblem ==
    1.0);
  if (c9_g_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #872 in Chart \'Warnings\' (#661): {msgID(id) = 21;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #872 in Chart \'Warnings\' (#661): {msgID(id) = 21;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 21.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 116U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #871 in Chart \'Warnings\' (#661): {msgID(id) = 22;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #871 in Chart \'Warnings\' (#661): {msgID(id) = 22;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 22.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, chartInstance->c9_sfEvent);
  c9_guard1 = FALSE;
  c9_guard2 = FALSE;
  c9_guard3 = FALSE;
  c9_guard4 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 166U, chartInstance->c9_sfEvent);
  c9_h_evilsf_internal_predicateOutput = CV_EML_IF(166U, 0, 0,
    *c9_LandingGearMode == 0.0);
  if (c9_h_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 166U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 148U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #877 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #877 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 41.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 147U, chartInstance->c9_sfEvent);
    c9_guard4 = TRUE;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 165U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 160U,
                 chartInstance->c9_sfEvent);
    c9_i_evilsf_internal_predicateOutput = CV_EML_IF(160U, 0, 0,
      *c9_LandingGearMode == 1.0);
    if (c9_i_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 160U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 149U, chartInstance->c9_sfEvent);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #880 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                             ^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "Transition #880 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                                   ^^",
        chartInstance->c9_id), 1, 10, 1, 0) - 1] = 42.0;
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      chartInstance->c9_id++;
      c9_updateDataWrittenToVector(chartInstance, 1U);
      c9_guard4 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 164U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 159U,
                   chartInstance->c9_sfEvent);
      c9_j_evilsf_internal_predicateOutput = CV_EML_IF(159U, 0, 0,
        *c9_LandingGearMode == 2.0);
      if (c9_j_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 159U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 151U, chartInstance->c9_sfEvent);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #883 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                             ^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "Transition #883 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                                   ^^",
          chartInstance->c9_id), 1, 10, 1, 0) - 1] = 45.0;
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        chartInstance->c9_id++;
        c9_updateDataWrittenToVector(chartInstance, 1U);
        c9_guard3 = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 162U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 155U,
                     chartInstance->c9_sfEvent);
        c9_k_evilsf_internal_predicateOutput = CV_EML_IF(155U, 0, 0,
          *c9_LandingGearMode == 3.0);
        if (c9_k_evilsf_internal_predicateOutput) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 155U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 153U, chartInstance->c9_sfEvent);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "Transition #886 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                             ^^^^^",
            (int32_T)_SFD_INTEGER_CHECK(
            "Transition #886 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                                   ^^",
            chartInstance->c9_id), 1, 10, 1, 0) - 1] = 43.0;
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          chartInstance->c9_id++;
          c9_updateDataWrittenToVector(chartInstance, 1U);
          c9_guard2 = TRUE;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 161U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 158U,
                       chartInstance->c9_sfEvent);
          c9_l_evilsf_internal_predicateOutput = CV_EML_IF(158U, 0, 0,
            *c9_LandingGearMode == 4.0);
          if (c9_l_evilsf_internal_predicateOutput) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 158U, chartInstance->c9_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 156U, chartInstance->c9_sfEvent);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
              "Transition #889 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                             ^^^^^",
              (int32_T)_SFD_INTEGER_CHECK(
              "Transition #889 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                                   ^^",
              chartInstance->c9_id), 1, 10, 1, 0) - 1] = 44.0;
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            chartInstance->c9_id++;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            c9_guard1 = TRUE;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 163U, chartInstance->c9_sfEvent);
          }
        }
      }
    }
  }

  if (c9_guard4) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 150U, chartInstance->c9_sfEvent);
    c9_guard3 = TRUE;
  }

  if (c9_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 152U, chartInstance->c9_sfEvent);
    c9_guard2 = TRUE;
  }

  if (c9_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 154U, chartInstance->c9_sfEvent);
    c9_guard1 = TRUE;
  }

  if (c9_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 157U, chartInstance->c9_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c9_sfEvent);
}

static void c9_d_calcMsgID(SFc9_CockpitDisplayLibInstanceStruct *chartInstance,
  real_T c9_msgID[10])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_guard1;
  boolean_T c9_guard2;
  boolean_T c9_guard3;
  boolean_T c9_guard4;
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i17;
  boolean_T c9_evilsf_internal_predicateOutput;
  boolean_T c9_b_evilsf_internal_predicateOutput;
  boolean_T c9_c_evilsf_internal_predicateOutput;
  boolean_T c9_d_evilsf_internal_predicateOutput;
  boolean_T c9_e_evilsf_internal_predicateOutput;
  boolean_T c9_f_evilsf_internal_predicateOutput;
  boolean_T c9_g_evilsf_internal_predicateOutput;
  boolean_T c9_h_evilsf_internal_predicateOutput;
  boolean_T c9_i_evilsf_internal_predicateOutput;
  real_T *c9_FuelPProblem;
  real_T *c9_OilPProblem;
  real_T *c9_HydProblem;
  real_T *c9_LandingGearMode;
  real_T *c9_RPMProblem;
  c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_s_debug_family_names,
    c9_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard1, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard2, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard3, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_guard4, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_msgID, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, chartInstance->c9_sfEvent);
  chartInstance->c9_id = 1.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  for (c9_i17 = 0; c9_i17 < 10; c9_i17++) {
    c9_msgID[c9_i17] = 0.0;
  }

  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 75U, chartInstance->c9_sfEvent);
  c9_evilsf_internal_predicateOutput = CV_EML_IF(75, 0, 0, *c9_FuelPProblem ==
    1.0);
  if (c9_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #946 in Chart \'Warnings\' (#661): {msgID(id) = 52; id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #946 in Chart \'Warnings\' (#661): {msgID(id) = 52; id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 52.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 117U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 118U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 78U, chartInstance->c9_sfEvent);
  c9_b_evilsf_internal_predicateOutput = CV_EML_IF(78, 0, 0, *c9_OilPProblem ==
    1.0);
  if (c9_b_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #951 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #951 in Chart \'Warnings\' (#661): {msgID(id) = 3;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 3.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #950 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #950 in Chart \'Warnings\' (#661): {msgID(id) = 4;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 4.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 121U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 81U, chartInstance->c9_sfEvent);
  c9_c_evilsf_internal_predicateOutput = CV_EML_IF(81, 0, 0, *c9_HydProblem ==
    1.0);
  if (c9_c_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #956 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #956 in Chart \'Warnings\' (#661): {msgID(id) = 31;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 31.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 120U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 84U, chartInstance->c9_sfEvent);
  c9_guard1 = FALSE;
  c9_guard2 = FALSE;
  c9_guard3 = FALSE;
  c9_guard4 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 186U, chartInstance->c9_sfEvent);
  c9_d_evilsf_internal_predicateOutput = CV_EML_IF(186U, 0, 0,
    *c9_LandingGearMode == 0.0);
  if (c9_d_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 186U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 168U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #961 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #961 in Chart \'Warnings\' (#661): {msgID(id) = 41;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 41.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 167U, chartInstance->c9_sfEvent);
    c9_guard4 = TRUE;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 185U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U,
                 chartInstance->c9_sfEvent);
    c9_e_evilsf_internal_predicateOutput = CV_EML_IF(180U, 0, 0,
      *c9_LandingGearMode == 1.0);
    if (c9_e_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 169U, chartInstance->c9_sfEvent);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Transition #964 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                             ^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "Transition #964 in Chart \'Warnings\' (#661): {msgID(id) = 42;id = id + 1;}\n                                                   ^^",
        chartInstance->c9_id), 1, 10, 1, 0) - 1] = 42.0;
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
      chartInstance->c9_id++;
      c9_updateDataWrittenToVector(chartInstance, 1U);
      c9_guard4 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 184U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 179U,
                   chartInstance->c9_sfEvent);
      c9_f_evilsf_internal_predicateOutput = CV_EML_IF(179U, 0, 0,
        *c9_LandingGearMode == 2.0);
      if (c9_f_evilsf_internal_predicateOutput) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 171U, chartInstance->c9_sfEvent);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Transition #967 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                             ^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "Transition #967 in Chart \'Warnings\' (#661): {msgID(id) = 45;id = id + 1;}\n                                                   ^^",
          chartInstance->c9_id), 1, 10, 1, 0) - 1] = 45.0;
        c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
        chartInstance->c9_id++;
        c9_updateDataWrittenToVector(chartInstance, 1U);
        c9_guard3 = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 182U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 175U,
                     chartInstance->c9_sfEvent);
        c9_g_evilsf_internal_predicateOutput = CV_EML_IF(175U, 0, 0,
          *c9_LandingGearMode == 3.0);
        if (c9_g_evilsf_internal_predicateOutput) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 175U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 173U, chartInstance->c9_sfEvent);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "Transition #970 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                             ^^^^^",
            (int32_T)_SFD_INTEGER_CHECK(
            "Transition #970 in Chart \'Warnings\' (#661): {msgID(id) = 43;id = id + 1;}\n                                                   ^^",
            chartInstance->c9_id), 1, 10, 1, 0) - 1] = 43.0;
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
          chartInstance->c9_id++;
          c9_updateDataWrittenToVector(chartInstance, 1U);
          c9_guard2 = TRUE;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, chartInstance->c9_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 178U,
                       chartInstance->c9_sfEvent);
          c9_h_evilsf_internal_predicateOutput = CV_EML_IF(178U, 0, 0,
            *c9_LandingGearMode == 4.0);
          if (c9_h_evilsf_internal_predicateOutput) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 178U, chartInstance->c9_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 176U, chartInstance->c9_sfEvent);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
              "Transition #973 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                             ^^^^^",
              (int32_T)_SFD_INTEGER_CHECK(
              "Transition #973 in Chart \'Warnings\' (#661): {msgID(id) = 44;id = id + 1;}\n                                                   ^^",
              chartInstance->c9_id), 1, 10, 1, 0) - 1] = 44.0;
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
            chartInstance->c9_id++;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            c9_guard1 = TRUE;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 183U, chartInstance->c9_sfEvent);
          }
        }
      }
    }
  }

  if (c9_guard4) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 170U, chartInstance->c9_sfEvent);
    c9_guard3 = TRUE;
  }

  if (c9_guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 172U, chartInstance->c9_sfEvent);
    c9_guard2 = TRUE;
  }

  if (c9_guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 174U, chartInstance->c9_sfEvent);
    c9_guard1 = TRUE;
  }

  if (c9_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 177U, chartInstance->c9_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 85U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 86U, chartInstance->c9_sfEvent);
  c9_i_evilsf_internal_predicateOutput = CV_EML_IF(86, 0, 0, *c9_RPMProblem ==
    1.0);
  if (c9_i_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 86U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 87U, chartInstance->c9_sfEvent);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    c9_msgID[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "Transition #981 in Chart \'Warnings\' (#661): {msgID(id) = 6;id = id + 1;}\n                                             ^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "Transition #981 in Chart \'Warnings\' (#661): {msgID(id) = 6;id = id + 1;}\n                                                   ^^",
      chartInstance->c9_id), 1, 10, 1, 0) - 1] = 6.0;
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 15U);
    chartInstance->c9_id++;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 122U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 88U, chartInstance->c9_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c9_sfEvent);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_e_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i18;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i18, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i18;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_FlightPhases, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_FlightPhases),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_FlightPhases);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_tp_FlightPhases;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_b_tp_FlightPhases = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_FlightPhases),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_FlightPhases);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i19;
  real_T c9_b_inData[10];
  int32_T c9_i20;
  real_T c9_u[10];
  const mxArray *c9_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i19 = 0; c9_i19 < 10; c9_i19++) {
    c9_b_inData[c9_i19] = (*(real_T (*)[10])c9_inData)[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 10; c9_i20++) {
    c9_u[c9_i20] = c9_b_inData[c9_i20];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 10, 1), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_h_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_output_msgID, const char_T *c9_identifier,
  real_T c9_y[10])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_output_msgID), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_output_msgID);
}

static void c9_i_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10])
{
  real_T c9_dv3[10];
  int32_T c9_i21;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv3, 1, 0, 0U, 1, 0U, 2, 10, 1);
  for (c9_i21 = 0; c9_i21 < 10; c9_i21++) {
    c9_y[c9_i21] = c9_dv3[c9_i21];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_output_msgID;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[10];
  int32_T c9_i22;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_output_msgID = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_output_msgID), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_output_msgID);
  for (c9_i22 = 0; c9_i22 < 10; c9_i22++) {
    (*(real_T (*)[10])c9_outData)[c9_i22] = c9_y[c9_i22];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_PFD_bus_io(void *chartInstanceVoid, void *c9_pData)
{
  const mxArray *c9_mxVal = NULL;
  c9_FlightInputs c9_tmp;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxVal = NULL;
  c9_tmp.Direction = *(real_T *)((char_T *)c9_pData + 0);
  c9_tmp.VerticalSpeed = *(real_T *)((char_T *)c9_pData + 8);
  c9_tmp.AirSpeed = *(real_T *)((char_T *)c9_pData + 16);
  c9_tmp.Altitude = *(real_T *)((char_T *)c9_pData + 24);
  c9_tmp.RateOfTurn = *(real_T *)((char_T *)c9_pData + 32);
  c9_tmp.Attitude = *(real_T *)((char_T *)c9_pData + 40);
  sf_mex_assign(&c9_mxVal, c9_g_sf_marshallOut(chartInstance, &c9_tmp), FALSE);
  return c9_mxVal;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  c9_FlightInputs c9_u;
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_g_u;
  const mxArray *c9_g_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_FlightInputs *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c9_b_u = c9_u.Direction;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_b_y, "Direction", "Direction", 0);
  c9_c_u = c9_u.VerticalSpeed;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_c_y, "VerticalSpeed", "VerticalSpeed", 0);
  c9_d_u = c9_u.AirSpeed;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_d_y, "AirSpeed", "AirSpeed", 0);
  c9_e_u = c9_u.Altitude;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_e_y, "Altitude", "Altitude", 0);
  c9_f_u = c9_u.RateOfTurn;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_f_y, "RateOfTurn", "RateOfTurn", 0);
  c9_g_u = c9_u.Attitude;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_g_y, "Attitude", "Attitude", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_EngNFuel_bus_io(void *chartInstanceVoid, void *c9_pData)
{
  const mxArray *c9_mxVal = NULL;
  c9_EngineFuel_Bus c9_tmp;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxVal = NULL;
  c9_tmp.RPM = *(real_T *)((char_T *)c9_pData + 0);
  c9_tmp.temperature = *(real_T *)((char_T *)c9_pData + 8);
  c9_tmp.fuelpressure = *(real_T *)((char_T *)c9_pData + 16);
  c9_tmp.oilpressure = *(real_T *)((char_T *)c9_pData + 24);
  c9_tmp.EGT = *(real_T *)((char_T *)c9_pData + 32);
  c9_tmp.EPR1 = *(real_T *)((char_T *)c9_pData + 40);
  c9_tmp.EPR2 = *(real_T *)((char_T *)c9_pData + 48);
  c9_tmp.FuelQuantity = *(real_T *)((char_T *)c9_pData + 56);
  sf_mex_assign(&c9_mxVal, c9_h_sf_marshallOut(chartInstance, &c9_tmp), FALSE);
  return c9_mxVal;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  c9_EngineFuel_Bus c9_u;
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_g_u;
  const mxArray *c9_g_y = NULL;
  real_T c9_h_u;
  const mxArray *c9_h_y = NULL;
  real_T c9_i_u;
  const mxArray *c9_i_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_EngineFuel_Bus *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c9_b_u = c9_u.RPM;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_b_y, "RPM", "RPM", 0);
  c9_c_u = c9_u.temperature;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_c_y, "temperature", "temperature", 0);
  c9_d_u = c9_u.fuelpressure;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_d_y, "fuelpressure", "fuelpressure", 0);
  c9_e_u = c9_u.oilpressure;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_e_y, "oilpressure", "oilpressure", 0);
  c9_f_u = c9_u.EGT;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_f_y, "EGT", "EGT", 0);
  c9_g_u = c9_u.EPR1;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_g_y, "EPR1", "EPR1", 0);
  c9_h_u = c9_u.EPR2;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_h_y, "EPR2", "EPR2", 0);
  c9_i_u = c9_u.FuelQuantity;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_Misc_bus_io(void *chartInstanceVoid, void *c9_pData)
{
  const mxArray *c9_mxVal = NULL;
  c9_MiscData c9_tmp;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxVal = NULL;
  c9_tmp.FlapPosition = *(real_T *)((char_T *)c9_pData + 0);
  c9_tmp.CabinPressure = *(real_T *)((char_T *)c9_pData + 8);
  c9_tmp.HydraulicPressure = *(real_T *)((char_T *)c9_pData + 16);
  c9_tmp.APUData = *(real_T *)((char_T *)c9_pData + 24);
  c9_tmp.LGLeftLock = *(boolean_T *)((char_T *)c9_pData + 32);
  c9_tmp.LGRightLock = *(boolean_T *)((char_T *)c9_pData + 33);
  sf_mex_assign(&c9_mxVal, c9_i_sf_marshallOut(chartInstance, &c9_tmp), FALSE);
  return c9_mxVal;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  c9_MiscData c9_u;
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  boolean_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  boolean_T c9_g_u;
  const mxArray *c9_g_y = NULL;
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_MiscData *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c9_b_u = c9_u.FlapPosition;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_b_y, "FlapPosition", "FlapPosition", 0);
  c9_c_u = c9_u.CabinPressure;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_c_y, "CabinPressure", "CabinPressure", 0);
  c9_d_u = c9_u.HydraulicPressure;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c9_e_u = c9_u.APUData;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_e_y, "APUData", "APUData", 0);
  c9_f_u = c9_u.LGLeftLock;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_f_y, "LGLeftLock", "LGLeftLock", 0);
  c9_g_u = c9_u.LGRightLock;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c9_y, c9_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_i_subchartSimStateInfo, const char_T
  *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_i_subchartSimStateInfo), &c9_thisId), FALSE);
  sf_mex_destroy(&c9_i_subchartSimStateInfo);
  return c9_y;
}

static const mxArray *c9_k_emlrt_marshallIn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), FALSE);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_updateDataWrittenToVector(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex)
{
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 5, 1, 0)] = TRUE;
}

static void c9_errorIfDataNotWrittenToFcn(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber)
{
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 5, 1,
    0)]);
}

static real_T c9_get_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1031) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_FlightMode_address;
}

static void c9_set_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1031) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_FlightMode_address = c9_c;
}

static real_T *c9_access_FlightMode(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_FlightMode_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FlightMode\' (#1031) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_FlightMode_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info(SFc9_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FlightMode", (void **)
    &chartInstance->c9_FlightMode_address, &chartInstance->c9_FlightMode_index);
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

void sf_c9_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2461958889U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(807950112U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(282654839U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2240273506U);
}

mxArray *sf_c9_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PjiImBEceHz4RH0xs85hnB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[124],T\"APUProblem\",},{M[1],M[153],T\"CabinPProblem\",},{M[1],M[110],T\"FuelPProblem\",},{M[1],M[861],T\"FuelQProblem\",},{M[1],M[125],T\"HydProblem\",},{M[1],M[445],T\"LandingGearMode\",},{M[1],M[108],T\"OilPProblem\",},{M[1],M[107],T\"RPMProblem\",},{M[1],M[109],T\"TempProblem\",},{M[1],M[443],T\"output_msgID\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[444],T\"id\",},{M[8],M[0],T\"is_active_c9_CockpitDisplayLib\",},{M[8],M[1142],T\"is_active_ComponentModes\",},{M[8],M[1144],T\"is_active_RPM\",},{M[8],M[1145],T\"is_active_Temp\",},{M[8],M[1147],T\"is_active_OilP\",},{M[8],M[1148],T\"is_active_Hyd\",},{M[8],M[1149],T\"is_active_APU\",},{M[8],M[1150],T\"is_active_CabinPressure\",},{M[8],M[1152],T\"is_active_WarningsComputation\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[1406],T\"is_active_FlightPhases\",},{M[8],M[1585],T\"is_active_Fuel\",},{M[8],M[1711],T\"is_active_LandingGear\",},{M[9],M[1152],T\"is_WarningsComputation\",},{M[9],M[1406],T\"is_FlightPhases\",},{M[14],M[1144],T\"subchartSimStateInfo\",},{M[14],M[1145],T\"subchartSimStateInfo\",},{M[14],M[1147],T\"subchartSimStateInfo\",},{M[14],M[1148],T\"subchartSimStateInfo\",},{M[14],M[1149],T\"subchartSimStateInfo\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[14],M[1150],T\"subchartSimStateInfo\",},{M[14],M[1585],T\"subchartSimStateInfo\",},{M[14],M[1711],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 33, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           9,
           23,
           187,
           21,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"output_msgID");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Engine_Mode");
          _SFD_SET_DATA_PROPS(3,1,1,0,"PFD");
          _SFD_SET_DATA_PROPS(4,1,1,0,"EngNFuel");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Misc");
          _SFD_SET_DATA_PROPS(6,2,0,1,"RPMProblem");
          _SFD_SET_DATA_PROPS(7,2,0,1,"TempProblem");
          _SFD_SET_DATA_PROPS(8,2,0,1,"FuelPProblem");
          _SFD_SET_DATA_PROPS(9,2,0,1,"FuelQProblem");
          _SFD_SET_DATA_PROPS(10,2,0,1,"OilPProblem");
          _SFD_SET_DATA_PROPS(11,11,0,0,"FlightMode");
          _SFD_SET_DATA_PROPS(12,2,0,1,"APUProblem");
          _SFD_SET_DATA_PROPS(13,2,0,1,"HydProblem");
          _SFD_SET_DATA_PROPS(14,2,0,1,"CabinPProblem");
          _SFD_SET_DATA_PROPS(15,0,0,0,"id");
          _SFD_SET_DATA_PROPS(16,2,0,1,"LandingGearMode");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_STATE_INFO(0,1,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,1);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,1);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,1);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,1);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(16,0,2);
          _SFD_STATE_INFO(18,0,2);
          _SFD_STATE_INFO(20,0,2);
          _SFD_STATE_INFO(22,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,9);
          _SFD_CH_SUBSTATE_INDEX(1,0);
          _SFD_CH_SUBSTATE_INDEX(2,14);
          _SFD_ST_SUBSTATE_COUNT(9,4);
          _SFD_ST_SUBSTATE_INDEX(9,0,10);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_INDEX(9,2,12);
          _SFD_ST_SUBSTATE_INDEX(9,3,13);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(0,8);
          _SFD_ST_SUBSTATE_INDEX(0,0,7);
          _SFD_ST_SUBSTATE_INDEX(0,1,8);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,6);
          _SFD_ST_SUBSTATE_INDEX(0,4,4);
          _SFD_ST_SUBSTATE_INDEX(0,5,1);
          _SFD_ST_SUBSTATE_INDEX(0,6,2);
          _SFD_ST_SUBSTATE_INDEX(0,7,5);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(14,4);
          _SFD_ST_SUBSTATE_INDEX(14,0,15);
          _SFD_ST_SUBSTATE_INDEX(14,1,17);
          _SFD_ST_SUBSTATE_INDEX(14,2,19);
          _SFD_ST_SUBSTATE_INDEX(14,3,21);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,8,0,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(89,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(90,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(91,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(92,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_TRANS(125,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(124,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(126,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(123,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(99,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(100,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(98,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(97,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(96,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(95,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(93,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(94,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(146,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(145,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(128,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(140,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(144,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(129,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(139,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(142,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(131,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(135,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(141,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(133,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(138,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(143,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(136,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(137,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(134,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(132,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(130,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(127,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(101,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(102,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(103,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(105,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(104,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(107,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(106,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(108,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(109,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(110,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(111,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(65,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(112,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(113,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(69,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(114,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(115,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(70,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(72,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(71,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(116,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(73,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(166,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(165,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(148,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(160,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(164,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(149,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(159,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(162,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(151,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(155,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(161,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(153,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(158,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(163,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(156,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(157,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(154,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(152,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(150,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(147,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(74,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(75,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(77,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(76,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(117,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(118,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(78,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(80,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(79,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(119,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(121,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(81,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(83,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(82,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(120,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(84,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(186,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(185,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(168,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(180,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(184,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(169,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(179,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(182,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(171,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(175,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(181,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(173,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(178,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(183,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(176,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(177,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(174,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(172,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(170,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(167,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(85,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(86,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(87,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(88,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(122,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(89,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(90,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(90,0,0,24,40,24,40);
        _SFD_CV_INIT_EML(91,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(91,0,0,32,52,32,52);
        _SFD_CV_INIT_EML(92,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(92,0,0,29,49,29,49);
        _SFD_CV_INIT_EML(4,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(11,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(16,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(19,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(125,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(125,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(124,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(126,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(22,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(25,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(123,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(34,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(99,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(100,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(37,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(98,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(97,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(40,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(96,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(95,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(43,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(42,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(93,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(94,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(146,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(146,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(145,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(128,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(140,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(140,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(144,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(129,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(139,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(139,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(142,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(131,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(135,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(135,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(141,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(133,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(138,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(138,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(143,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(136,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(137,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(134,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(132,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(130,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(127,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(45,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(47,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(101,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(102,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(48,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(48,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(50,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(49,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(103,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(51,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(52,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(52,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(54,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(53,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(105,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(104,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(55,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(55,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(57,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(56,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(107,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(106,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(58,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(58,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(60,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(59,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(108,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(109,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(61,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(61,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(63,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(62,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(110,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(111,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(64,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(64,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(66,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(65,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(112,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(113,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(67,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(67,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(69,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(68,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(114,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(115,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(70,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(70,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(72,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(71,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(116,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(73,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(166,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(166,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(165,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(148,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(160,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(160,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(164,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(149,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(159,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(159,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(162,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(151,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(155,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(155,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(161,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(153,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(158,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(158,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(163,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(156,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(157,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(154,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(152,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(150,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(147,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(74,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(75,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(75,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(77,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(76,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(117,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(118,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(78,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(78,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(80,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(79,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(119,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(121,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(81,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(81,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(83,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(82,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(120,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(84,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(186,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(186,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(185,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(168,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(180,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(180,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(184,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(169,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(179,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(179,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(182,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(171,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(175,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(175,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(181,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(173,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(178,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(178,0,0,1,21,1,21);
        _SFD_CV_INIT_EML(183,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(176,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(177,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(174,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(172,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(170,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(167,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(85,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(86,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(86,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(87,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(88,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(122,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,50,65,50,65);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,61,76,61,76);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,50,65,50,65);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 10;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_f_sf_marshallOut,(MexInFcnForType)
            c9_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_PFD_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_EngNFuel_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));

        {
          real_T *c9_APUMode;
          real_T *c9_Engine_Mode;
          c9_FlightInputs *c9_PFD;
          c9_EngineFuel_Bus *c9_EngNFuel;
          c9_MiscData *c9_Misc;
          real_T *c9_RPMProblem;
          real_T *c9_TempProblem;
          real_T *c9_FuelPProblem;
          real_T *c9_FuelQProblem;
          real_T *c9_OilPProblem;
          real_T *c9_APUProblem;
          real_T *c9_HydProblem;
          real_T *c9_CabinPProblem;
          real_T *c9_LandingGearMode;
          real_T (*c9_output_msgID)[10];
          c9_LandingGearMode = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            10);
          c9_CabinPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c9_HydProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c9_APUProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c9_OilPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c9_FuelQProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c9_FuelPProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c9_TempProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_RPMProblem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_Misc = (c9_MiscData *)ssGetInputPortSignal(chartInstance->S, 4);
          c9_EngNFuel = (c9_EngineFuel_Bus *)ssGetInputPortSignal
            (chartInstance->S, 3);
          c9_PFD = (c9_FlightInputs *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_Engine_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_output_msgID = (real_T (*)[10])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c9_APUMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_APUMode);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_output_msgID);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_Engine_Mode);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_PFD);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_EngNFuel);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_Misc);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_RPMProblem);
          _SFD_SET_DATA_VALUE_PTR(7U, c9_TempProblem);
          _SFD_SET_DATA_VALUE_PTR(8U, c9_FuelPProblem);
          _SFD_SET_DATA_VALUE_PTR(9U, c9_FuelQProblem);
          _SFD_SET_DATA_VALUE_PTR(10U, c9_OilPProblem);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_FlightMode_address);
          _SFD_SET_DATA_VALUE_PTR(12U, c9_APUProblem);
          _SFD_SET_DATA_VALUE_PTR(13U, c9_HydProblem);
          _SFD_SET_DATA_VALUE_PTR(14U, c9_CabinPProblem);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c9_id);
          _SFD_SET_DATA_VALUE_PTR(16U, c9_LandingGearMode);
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
  return "4jLo8WmUvbXQ3AUIW2WggH";
}

static void sf_opaque_initialize_c9_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_CockpitDisplayLib
    ((SFc9_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c9_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_CockpitDisplayLib(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_CockpitDisplayLib(S);
}

static void sf_opaque_set_sim_state_c9_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_CockpitDisplayLib(S, st);
}

static void sf_opaque_terminate_c9_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_CockpitDisplayLibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_CockpitDisplayLib((SFc9_CockpitDisplayLibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,10);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=10; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2314517392U));
  ssSetChecksum1(S,(477410983U));
  ssSetChecksum2(S,(1015450035U));
  ssSetChecksum3(S,(1053711173U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c9_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_CockpitDisplayLib(SimStruct *S)
{
  SFc9_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc9_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc9_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_CockpitDisplayLib;
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

void c9_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
