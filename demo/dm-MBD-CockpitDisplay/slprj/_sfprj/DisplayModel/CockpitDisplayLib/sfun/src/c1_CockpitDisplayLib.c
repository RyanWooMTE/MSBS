/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CockpitDisplayLib_sfun.h"
#include "c1_CockpitDisplayLib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CockpitDisplayLib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_OFF                      ((uint8_T)1U)
#define c1_IN_Running                  ((uint8_T)2U)
#define c1_IN_Starting                 ((uint8_T)3U)
#define c1_IN_NDOff                    ((uint8_T)1U)
#define c1_IN_NDRunning                ((uint8_T)2U)
#define c1_IN_NDStart                  ((uint8_T)3U)
#define c1_IN_ARCPage                  ((uint8_T)1U)
#define c1_IN_ILSPage                  ((uint8_T)2U)
#define c1_IN_NAVPage                  ((uint8_T)3U)
#define c1_IN_PLANPage                 ((uint8_T)4U)
#define c1_IN_VORPage                  ((uint8_T)5U)
#define c1_IN_ON                       ((uint8_T)2U)
#define c1_IN_Engine_Boot              ((uint8_T)1U)
#define c1_IN_Engine_Off               ((uint8_T)2U)
#define c1_IN_Engine_Ready             ((uint8_T)3U)
#define c1_IN_Engine_Running           ((uint8_T)4U)
#define c1_IN_NormalFlight             ((uint8_T)1U)
#define c1_IN_Startup                  ((uint8_T)2U)
#define c1_IN_UserSelection_Faults     ((uint8_T)3U)
#define c1_IN_APU_Boot                 ((uint8_T)1U)
#define c1_IN_APU_Off                  ((uint8_T)2U)
#define c1_IN_APU_Ready                ((uint8_T)3U)
#define c1_IN_APU_Running              ((uint8_T)4U)
#define c1_IN_APU_Wait                 ((uint8_T)5U)
#define c1_IN_EngineStarting           ((uint8_T)6U)
#define c1_IN_Land                     ((uint8_T)1U)
#define c1_IN_PushbackAndTaxi          ((uint8_T)2U)
#define c1_IN_TakeoffCruiseDescent     ((uint8_T)3U)
#define c1_IN_APU                      ((uint8_T)1U)
#define c1_IN_Bleed                    ((uint8_T)2U)
#define c1_IN_Cabin_Pressure           ((uint8_T)3U)
#define c1_IN_ERROR                    ((uint8_T)4U)
#define c1_IN_Engine                   ((uint8_T)5U)
#define c1_IN_FUEL                     ((uint8_T)6U)
#define c1_IN_HYD                      ((uint8_T)7U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_w_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_cb_debug_family_names[5] = { "guard1", "nargin",
  "nargout", "flightphase", "out" };

static const char * c1_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_bc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_dc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ec_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_fc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_gc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_hc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ic_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_jc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_kc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_lc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_mc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_nc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_oc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_pc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_qc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_rc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_sc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_tc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_uc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_vc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_wc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_xc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_yc_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ad_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_bd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_dd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ed_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_fd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_gd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_hd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_id_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_jd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_kd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ld_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_md_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_nd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_od_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_pd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_qd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_rd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_sd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_td_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ud_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_vd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_wd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_xd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_yd_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ae_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_be_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ce_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_de_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ee_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_fe_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ge_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_he_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ie_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_je_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ke_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_le_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_me_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ne_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_oe_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_pe_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_qe_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_re_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_se_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_te_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ue_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ve_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_we_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_xe_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ye_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_af_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_bf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_df_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ef_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ff_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_gf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_hf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_if_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_jf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_kf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_lf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_mf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_nf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_of_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_pf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_qf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_rf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_sf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_tf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_uf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_vf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_wf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_xf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_yf_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ag_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_bg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_dg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_eg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_fg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_gg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_hg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ig_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_jg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_kg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_lg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_mg_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[9];

/* Function Declarations */
static void initialize_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void initialize_params_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void enable_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void disable_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void set_sim_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void finalize_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void sf_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_enter_internal_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void initSimStructsc1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_PrimaryFlightDisplay(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_NavigationDisplay(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_NDDisplayPages(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_NDRunning(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_exit_internal_NDRunning(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_CSTRDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_EngineDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_SystemDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_Startup(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_enter_internal_NormalFlight(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance);
static void c1_exit_internal_NormalFlight(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_enter_internal_UserSelection_Faults
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_UserSelection_Faults(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);
static void c1_exit_internal_UserSelection_Faults
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void c1_isequal(SFc1_CockpitDisplayLibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(uint32_T c1_u);
static real_T c1_calcFlapConfig(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, real_T c1_flightphase);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_PrimaryFlightDisplay, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ND_AD_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_outputDisplay_bus_io(void *chartInstanceVoid, void
  *c1_pData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_outputDisplay, const char_T *c1_identifier,
  c1_warnings_bus *c1_y);
static void c1_h_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_warnings_bus *c1_y);
static void c1_i_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_PFD_Input_bus_io(void *chartInstanceVoid, void
  *c1_pData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_Nav_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_FCU_Display_bus_io(void *chartInstanceVoid, void
  *c1_pData);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_FCU_Output c1_j_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance, const mxArray *c1_FCU_Display, const char_T *c1_identifier);
static c1_FCU_Output c1_k_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_EnF_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_Misc_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ED_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, c1_EngineDisplayBus
   *c1_u);
static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_l_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_ED, const char_T *c1_identifier,
  c1_EngineDisplayBus *c1_y);
static void c1_m_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_EngineDisplayBus *c1_y);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_PFD_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_PFDOutput c1_n_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_PFD, const char_T *c1_identifier);
static c1_PFDOutput c1_o_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static c1_NDAdditionalDisplay c1_p_emlrt_marshallIn
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c1_ND_AD_OP, const char_T *c1_identifier);
static c1_NDAdditionalDisplay c1_q_emlrt_marshallIn
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_r_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_s_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void init_dsm_address_info(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_EngineDisplay = 0U;
  chartInstance->c1_is_EngineDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_EngineDisplay = 0U;
  chartInstance->c1_tp_Engine_Boot = 0U;
  chartInstance->c1_temporalCounter_i6 = 0U;
  chartInstance->c1_tp_Engine_Off = 0U;
  chartInstance->c1_tp_Engine_Ready = 0U;
  chartInstance->c1_tp_Engine_Running = 0U;
  chartInstance->c1_is_active_FCU_EFIS_Display = 0U;
  chartInstance->c1_tp_FCU_EFIS_Display = 0U;
  chartInstance->c1_is_active_NavigationDisplay = 0U;
  chartInstance->c1_tp_NavigationDisplay = 0U;
  chartInstance->c1_is_active_ARPTDisplay = 0U;
  chartInstance->c1_is_ARPTDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_ARPTDisplay = 0U;
  chartInstance->c1_i_tp_OFF = 0U;
  chartInstance->c1_e_tp_ON = 0U;
  chartInstance->c1_is_active_CSTRDisplay = 0U;
  chartInstance->c1_is_CSTRDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_CSTRDisplay = 0U;
  chartInstance->c1_e_tp_OFF = 0U;
  chartInstance->c1_tp_ON = 0U;
  chartInstance->c1_is_active_NDBDisplay = 0U;
  chartInstance->c1_is_NDBDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_NDBDisplay = 0U;
  chartInstance->c1_h_tp_OFF = 0U;
  chartInstance->c1_d_tp_ON = 0U;
  chartInstance->c1_is_active_NDDisplayPages = 0U;
  chartInstance->c1_is_NDDisplayPages = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_NDDisplayPages = 0U;
  chartInstance->c1_tp_NDOff = 0U;
  chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_NDRunning = 0U;
  chartInstance->c1_tp_ARCPage = 0U;
  chartInstance->c1_tp_ILSPage = 0U;
  chartInstance->c1_tp_NAVPage = 0U;
  chartInstance->c1_tp_PLANPage = 0U;
  chartInstance->c1_tp_VORPage = 0U;
  chartInstance->c1_tp_NDStart = 0U;
  chartInstance->c1_temporalCounter_i5 = 0U;
  chartInstance->c1_is_active_VORDDisplay = 0U;
  chartInstance->c1_is_VORDDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_VORDDisplay = 0U;
  chartInstance->c1_g_tp_OFF = 0U;
  chartInstance->c1_c_tp_ON = 0U;
  chartInstance->c1_is_active_WPTDisplay = 0U;
  chartInstance->c1_is_WPTDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_WPTDisplay = 0U;
  chartInstance->c1_f_tp_OFF = 0U;
  chartInstance->c1_b_tp_ON = 0U;
  chartInstance->c1_is_active_PrimaryFlightDisplay = 0U;
  chartInstance->c1_tp_PrimaryFlightDisplay = 0U;
  chartInstance->c1_is_active_AirSpeed = 0U;
  chartInstance->c1_is_AirSpeed = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_AirSpeed = 0U;
  chartInstance->c1_tp_OFF = 0U;
  chartInstance->c1_tp_Running = 0U;
  chartInstance->c1_tp_Starting = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_active_Altitude = 0U;
  chartInstance->c1_is_Altitude = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Altitude = 0U;
  chartInstance->c1_b_tp_OFF = 0U;
  chartInstance->c1_b_tp_Running = 0U;
  chartInstance->c1_b_tp_Starting = 0U;
  chartInstance->c1_temporalCounter_i2 = 0U;
  chartInstance->c1_is_active_Attitude = 0U;
  chartInstance->c1_is_Attitude = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Attitude = 0U;
  chartInstance->c1_d_tp_OFF = 0U;
  chartInstance->c1_d_tp_Running = 0U;
  chartInstance->c1_d_tp_Starting = 0U;
  chartInstance->c1_temporalCounter_i4 = 0U;
  chartInstance->c1_is_active_Heading = 0U;
  chartInstance->c1_is_Heading = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Heading = 0U;
  chartInstance->c1_c_tp_OFF = 0U;
  chartInstance->c1_c_tp_Running = 0U;
  chartInstance->c1_c_tp_Starting = 0U;
  chartInstance->c1_temporalCounter_i3 = 0U;
  chartInstance->c1_is_active_SystemDisplay = 0U;
  chartInstance->c1_is_SystemDisplay = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_SystemDisplay = 0U;
  chartInstance->c1_is_NormalFlight = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_NormalFlight = 0U;
  chartInstance->c1_tp_Land = 0U;
  chartInstance->c1_tp_PushbackAndTaxi = 0U;
  chartInstance->c1_tp_TakeoffCruiseDescent = 0U;
  chartInstance->c1_is_Startup = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Startup = 0U;
  chartInstance->c1_tp_APU_Boot = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_APU_Off = 0U;
  chartInstance->c1_tp_APU_Ready = 0U;
  chartInstance->c1_tp_APU_Running = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_APU_Wait = 0U;
  chartInstance->c1_tp_EngineStarting = 0U;
  chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_UserSelection_Faults = 0U;
  chartInstance->c1_temporalCounter_i8 = 0U;
  chartInstance->c1_tp_APU = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_Bleed = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_Cabin_Pressure = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_ERROR = 0U;
  chartInstance->c1_tp_Engine = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_FUEL = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_tp_HYD = 0U;
  chartInstance->c1_temporalCounter_i7 = 0U;
  chartInstance->c1_is_active_c1_CockpitDisplayLib = 0U;
}

static void initialize_params_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void enable_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_CockpitDisplayLib == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_PrimaryFlightDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_AirSpeed == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_AirSpeed == c1_IN_Starting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_AirSpeed == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_AirSpeed == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Altitude == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Altitude == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Altitude == c1_IN_Starting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Altitude == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Heading == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Heading == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Heading == c1_IN_Starting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Heading == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Attitude == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Attitude == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Attitude == c1_IN_Starting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Attitude == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_NavigationDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_NDDisplayPages == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDRunning == c1_IN_ILSPage) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDRunning == c1_IN_VORPage) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDRunning == c1_IN_NAVPage) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDRunning == c1_IN_ARCPage) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDRunning == c1_IN_PLANPage) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDOff) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_CSTRDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CSTRDisplay == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CSTRDisplay == c1_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_WPTDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_WPTDisplay == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_WPTDisplay == c1_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_VORDDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_VORDDisplay == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_VORDDisplay == c1_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_NDBDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDBDisplay == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NDBDisplay == c1_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_ARPTDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ARPTDisplay == c1_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ARPTDisplay == c1_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_EngineDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Ready) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Boot) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_FCU_EFIS_Display == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_SystemDisplay == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_SystemDisplay == c1_IN_Startup) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_APU_Ready) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_APU_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_APU_Boot) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_APU_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_APU_Wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Startup == c1_IN_EngineStarting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_SystemDisplay == c1_IN_NormalFlight) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NormalFlight == c1_IN_PushbackAndTaxi) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NormalFlight == c1_IN_TakeoffCruiseDescent) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NormalFlight == c1_IN_Land) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_SystemDisplay == c1_IN_UserSelection_Faults) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Engine) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Cabin_Pressure) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_HYD) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_FUEL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_APU) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Bleed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UserSelection_Faults == c1_IN_ERROR) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  c1_EngineDisplayBus c1_r0;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_n_y = NULL;
  const mxArray *c1_o_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_o_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_p_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_q_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_r_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_s_u;
  const mxArray *c1_w_y = NULL;
  const mxArray *c1_x_y = NULL;
  real_T c1_t_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_u_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_v_u;
  const mxArray *c1_bb_y = NULL;
  int32_T c1_i0;
  real_T c1_w_u[10];
  const mxArray *c1_cb_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_x_u;
  const mxArray *c1_db_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_y_u;
  const mxArray *c1_eb_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_ab_u;
  const mxArray *c1_fb_y = NULL;
  uint8_T c1_g_hoistedGlobal;
  uint8_T c1_bb_u;
  const mxArray *c1_gb_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  uint8_T c1_cb_u;
  const mxArray *c1_hb_y = NULL;
  uint8_T c1_i_hoistedGlobal;
  uint8_T c1_db_u;
  const mxArray *c1_ib_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_eb_u;
  const mxArray *c1_jb_y = NULL;
  uint8_T c1_k_hoistedGlobal;
  uint8_T c1_fb_u;
  const mxArray *c1_kb_y = NULL;
  uint8_T c1_l_hoistedGlobal;
  uint8_T c1_gb_u;
  const mxArray *c1_lb_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_hb_u;
  const mxArray *c1_mb_y = NULL;
  uint8_T c1_n_hoistedGlobal;
  uint8_T c1_ib_u;
  const mxArray *c1_nb_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  uint8_T c1_jb_u;
  const mxArray *c1_ob_y = NULL;
  uint8_T c1_p_hoistedGlobal;
  uint8_T c1_kb_u;
  const mxArray *c1_pb_y = NULL;
  uint8_T c1_q_hoistedGlobal;
  uint8_T c1_lb_u;
  const mxArray *c1_qb_y = NULL;
  uint8_T c1_r_hoistedGlobal;
  uint8_T c1_mb_u;
  const mxArray *c1_rb_y = NULL;
  uint8_T c1_s_hoistedGlobal;
  uint8_T c1_nb_u;
  const mxArray *c1_sb_y = NULL;
  uint8_T c1_t_hoistedGlobal;
  uint8_T c1_ob_u;
  const mxArray *c1_tb_y = NULL;
  uint8_T c1_u_hoistedGlobal;
  uint8_T c1_pb_u;
  const mxArray *c1_ub_y = NULL;
  uint8_T c1_v_hoistedGlobal;
  uint8_T c1_qb_u;
  const mxArray *c1_vb_y = NULL;
  uint8_T c1_w_hoistedGlobal;
  uint8_T c1_rb_u;
  const mxArray *c1_wb_y = NULL;
  uint8_T c1_x_hoistedGlobal;
  uint8_T c1_sb_u;
  const mxArray *c1_xb_y = NULL;
  uint8_T c1_y_hoistedGlobal;
  uint8_T c1_tb_u;
  const mxArray *c1_yb_y = NULL;
  uint8_T c1_ab_hoistedGlobal;
  uint8_T c1_ub_u;
  const mxArray *c1_ac_y = NULL;
  uint8_T c1_bb_hoistedGlobal;
  uint8_T c1_vb_u;
  const mxArray *c1_bc_y = NULL;
  uint8_T c1_cb_hoistedGlobal;
  uint8_T c1_wb_u;
  const mxArray *c1_cc_y = NULL;
  uint8_T c1_db_hoistedGlobal;
  uint8_T c1_xb_u;
  const mxArray *c1_dc_y = NULL;
  uint8_T c1_eb_hoistedGlobal;
  uint8_T c1_yb_u;
  const mxArray *c1_ec_y = NULL;
  uint8_T c1_fb_hoistedGlobal;
  uint8_T c1_ac_u;
  const mxArray *c1_fc_y = NULL;
  uint8_T c1_gb_hoistedGlobal;
  uint8_T c1_bc_u;
  const mxArray *c1_gc_y = NULL;
  uint8_T c1_hb_hoistedGlobal;
  uint8_T c1_cc_u;
  const mxArray *c1_hc_y = NULL;
  uint8_T c1_ib_hoistedGlobal;
  uint8_T c1_dc_u;
  const mxArray *c1_ic_y = NULL;
  uint8_T c1_jb_hoistedGlobal;
  uint8_T c1_ec_u;
  const mxArray *c1_jc_y = NULL;
  uint8_T c1_kb_hoistedGlobal;
  uint8_T c1_fc_u;
  const mxArray *c1_kc_y = NULL;
  uint8_T c1_lb_hoistedGlobal;
  uint8_T c1_gc_u;
  const mxArray *c1_lc_y = NULL;
  uint8_T c1_mb_hoistedGlobal;
  uint8_T c1_hc_u;
  const mxArray *c1_mc_y = NULL;
  uint8_T c1_nb_hoistedGlobal;
  uint8_T c1_ic_u;
  const mxArray *c1_nc_y = NULL;
  uint8_T c1_ob_hoistedGlobal;
  uint8_T c1_jc_u;
  const mxArray *c1_oc_y = NULL;
  uint8_T c1_pb_hoistedGlobal;
  uint8_T c1_kc_u;
  const mxArray *c1_pc_y = NULL;
  uint8_T c1_qb_hoistedGlobal;
  uint8_T c1_lc_u;
  const mxArray *c1_qc_y = NULL;
  uint8_T c1_rb_hoistedGlobal;
  uint8_T c1_mc_u;
  const mxArray *c1_rc_y = NULL;
  real_T *c1_ECAMMode;
  real_T *c1_EFIS_Pressure_Output;
  real_T *c1_NDMode;
  c1_FCU_Output *c1_FCU_Display;
  c1_NDAdditionalDisplay *c1_ND_AD_OP;
  c1_PFDOutput *c1_PFD;
  c1_warnings_bus *c1_outputDisplay;
  c1_EngineDisplayBus *c1_ED;
  c1_PFD = (c1_PFDOutput *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal(chartInstance->S,
    7);
  c1_NDMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_ED = (c1_EngineDisplayBus *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_EFIS_Pressure_Output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_FCU_Display = (c1_FCU_Output *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_outputDisplay = (c1_warnings_bus *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(48), FALSE);
  c1_hoistedGlobal = *c1_ECAMMode;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_r0.EPR1 = *(real_T *)((char_T *)c1_ED + 0);
  c1_r0.EPR2 = *(real_T *)((char_T *)c1_ED + 8);
  c1_r0.EGT1 = *(real_T *)((char_T *)c1_ED + 16);
  c1_r0.EGT2 = *(real_T *)((char_T *)c1_ED + 24);
  c1_r0.FlapConfig = *(real_T *)((char_T *)c1_ED + 32);
  c1_r0.N1_L = *(real_T *)((char_T *)c1_ED + 40);
  c1_r0.N1_R = *(real_T *)((char_T *)c1_ED + 48);
  c1_r0.ED_Mode_L = *(real_T *)((char_T *)c1_ED + 56);
  c1_r0.ED_Mode_R = *(real_T *)((char_T *)c1_ED + 64);
  c1_r0.FuelQuantity = *(real_T *)((char_T *)c1_ED + 72);
  sf_mex_setcell(c1_y, 1, c1_c_emlrt_marshallOut(chartInstance, &c1_r0));
  c1_b_hoistedGlobal = *c1_EFIS_Pressure_Output;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_c_u = *(real_T *)((char_T *)c1_FCU_Display + 0);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_d_y, c1_e_y, "Speed", "Speed", 0);
  c1_d_u = *(real_T *)((char_T *)c1_FCU_Display + 8);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_d_y, c1_f_y, "Heading", "Heading", 0);
  c1_e_u = *(real_T *)((char_T *)c1_FCU_Display + 16);
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_d_y, c1_g_y, "Altitude", "Altitude", 0);
  sf_mex_setcell(c1_y, 3, c1_d_y);
  c1_c_hoistedGlobal = *c1_NDMode;
  c1_f_u = c1_c_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_h_y);
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_g_u = *(real_T *)((char_T *)c1_ND_AD_OP + 0);
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_i_y, c1_j_y, "CSTR", "CSTR", 0);
  c1_h_u = *(real_T *)((char_T *)c1_ND_AD_OP + 8);
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_i_y, c1_k_y, "WPT", "WPT", 0);
  c1_i_u = *(real_T *)((char_T *)c1_ND_AD_OP + 16);
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_i_y, c1_l_y, "VORD", "VORD", 0);
  c1_j_u = *(real_T *)((char_T *)c1_ND_AD_OP + 24);
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_i_y, c1_m_y, "NDB", "NDB", 0);
  c1_k_u = *(real_T *)((char_T *)c1_ND_AD_OP + 32);
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_i_y, c1_n_y, "ARPT", "ARPT", 0);
  sf_mex_setcell(c1_y, 5, c1_i_y);
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_l_u = *(real_T *)((char_T *)c1_PFD + 0);
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_p_y, "Altitude", "Altitude", 0);
  c1_m_u = *(real_T *)((char_T *)c1_PFD + 8);
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_q_y, "Heading", "Heading", 0);
  c1_n_u = *(real_T *)((char_T *)c1_PFD + 16);
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_r_y, "Attitude", "Attitude", 0);
  c1_o_u = *(real_T *)((char_T *)c1_PFD + 24);
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_s_y, "AirSpeed", "AirSpeed", 0);
  c1_p_u = *(real_T *)((char_T *)c1_PFD + 32);
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_t_y, "AltMode", "AltMode", 0);
  c1_q_u = *(real_T *)((char_T *)c1_PFD + 40);
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_u_y, "AirSpeedMode", "AirSpeedMode", 0);
  c1_r_u = *(real_T *)((char_T *)c1_PFD + 48);
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_v_y, "AttMode", "AttMode", 0);
  c1_s_u = *(real_T *)((char_T *)c1_PFD + 56);
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_o_y, c1_w_y, "HeadingMode", "HeadingMode", 0);
  sf_mex_setcell(c1_y, 6, c1_o_y);
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_t_u = *(real_T *)((char_T *)c1_outputDisplay + 0);
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_x_y, c1_y_y, "flightmode", "flightmode", 0);
  c1_u_u = *(real_T *)((char_T *)c1_outputDisplay + 8);
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_x_y, c1_ab_y, "ED_Mode_R", "ED_Mode_R", 0);
  c1_v_u = *(real_T *)((char_T *)c1_outputDisplay + 16);
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_x_y, c1_bb_y, "ED_Mode_L", "ED_Mode_L", 0);
  for (c1_i0 = 0; c1_i0 < 10; c1_i0++) {
    c1_w_u[c1_i0] = ((real_T *)((char_T *)c1_outputDisplay + 24))[c1_i0];
  }

  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", c1_w_u, 0, 0U, 1U, 0U, 2, 10, 1),
                FALSE);
  sf_mex_addfield(c1_x_y, c1_cb_y, "warn_msgID", "warn_msgID", 0);
  sf_mex_setcell(c1_y, 7, c1_x_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_CockpitDisplayLib;
  c1_x_u = c1_d_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_x_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_db_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_NavigationDisplay;
  c1_y_u = c1_e_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_y_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_eb_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_SystemDisplay;
  c1_ab_u = c1_f_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_ab_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_fb_y);
  c1_g_hoistedGlobal = chartInstance->c1_is_active_EngineDisplay;
  c1_bb_u = c1_g_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_bb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_gb_y);
  c1_h_hoistedGlobal = chartInstance->c1_is_active_PrimaryFlightDisplay;
  c1_cb_u = c1_h_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_cb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_hb_y);
  c1_i_hoistedGlobal = chartInstance->c1_is_active_AirSpeed;
  c1_db_u = c1_i_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_db_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 13, c1_ib_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_active_Altitude;
  c1_eb_u = c1_j_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_eb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 14, c1_jb_y);
  c1_k_hoistedGlobal = chartInstance->c1_is_active_Attitude;
  c1_fb_u = c1_k_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_fb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 15, c1_kb_y);
  c1_l_hoistedGlobal = chartInstance->c1_is_active_Heading;
  c1_gb_u = c1_l_hoistedGlobal;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_gb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 16, c1_lb_y);
  c1_m_hoistedGlobal = chartInstance->c1_is_active_FCU_EFIS_Display;
  c1_hb_u = c1_m_hoistedGlobal;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_hb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 17, c1_mb_y);
  c1_n_hoistedGlobal = chartInstance->c1_is_active_NDDisplayPages;
  c1_ib_u = c1_n_hoistedGlobal;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_ib_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 18, c1_nb_y);
  c1_o_hoistedGlobal = chartInstance->c1_is_active_CSTRDisplay;
  c1_jb_u = c1_o_hoistedGlobal;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_jb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 19, c1_ob_y);
  c1_p_hoistedGlobal = chartInstance->c1_is_active_WPTDisplay;
  c1_kb_u = c1_p_hoistedGlobal;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_kb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 20, c1_pb_y);
  c1_q_hoistedGlobal = chartInstance->c1_is_active_VORDDisplay;
  c1_lb_u = c1_q_hoistedGlobal;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_lb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 21, c1_qb_y);
  c1_r_hoistedGlobal = chartInstance->c1_is_active_NDBDisplay;
  c1_mb_u = c1_r_hoistedGlobal;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_mb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 22, c1_rb_y);
  c1_s_hoistedGlobal = chartInstance->c1_is_active_ARPTDisplay;
  c1_nb_u = c1_s_hoistedGlobal;
  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", &c1_nb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 23, c1_sb_y);
  c1_t_hoistedGlobal = chartInstance->c1_is_SystemDisplay;
  c1_ob_u = c1_t_hoistedGlobal;
  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", &c1_ob_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 24, c1_tb_y);
  c1_u_hoistedGlobal = chartInstance->c1_is_EngineDisplay;
  c1_pb_u = c1_u_hoistedGlobal;
  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", &c1_pb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 25, c1_ub_y);
  c1_v_hoistedGlobal = chartInstance->c1_is_AirSpeed;
  c1_qb_u = c1_v_hoistedGlobal;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_qb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 26, c1_vb_y);
  c1_w_hoistedGlobal = chartInstance->c1_is_Altitude;
  c1_rb_u = c1_w_hoistedGlobal;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_rb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 27, c1_wb_y);
  c1_x_hoistedGlobal = chartInstance->c1_is_Attitude;
  c1_sb_u = c1_x_hoistedGlobal;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_create("y", &c1_sb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 28, c1_xb_y);
  c1_y_hoistedGlobal = chartInstance->c1_is_Heading;
  c1_tb_u = c1_y_hoistedGlobal;
  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", &c1_tb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 29, c1_yb_y);
  c1_ab_hoistedGlobal = chartInstance->c1_is_NormalFlight;
  c1_ub_u = c1_ab_hoistedGlobal;
  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_create("y", &c1_ub_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 30, c1_ac_y);
  c1_bb_hoistedGlobal = chartInstance->c1_is_UserSelection_Faults;
  c1_vb_u = c1_bb_hoistedGlobal;
  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", &c1_vb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 31, c1_bc_y);
  c1_cb_hoistedGlobal = chartInstance->c1_is_Startup;
  c1_wb_u = c1_cb_hoistedGlobal;
  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", &c1_wb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 32, c1_cc_y);
  c1_db_hoistedGlobal = chartInstance->c1_is_NDDisplayPages;
  c1_xb_u = c1_db_hoistedGlobal;
  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", &c1_xb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 33, c1_dc_y);
  c1_eb_hoistedGlobal = chartInstance->c1_is_NDRunning;
  c1_yb_u = c1_eb_hoistedGlobal;
  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", &c1_yb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 34, c1_ec_y);
  c1_fb_hoistedGlobal = chartInstance->c1_is_CSTRDisplay;
  c1_ac_u = c1_fb_hoistedGlobal;
  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", &c1_ac_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 35, c1_fc_y);
  c1_gb_hoistedGlobal = chartInstance->c1_is_WPTDisplay;
  c1_bc_u = c1_gb_hoistedGlobal;
  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_create("y", &c1_bc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 36, c1_gc_y);
  c1_hb_hoistedGlobal = chartInstance->c1_is_VORDDisplay;
  c1_cc_u = c1_hb_hoistedGlobal;
  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", &c1_cc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 37, c1_hc_y);
  c1_ib_hoistedGlobal = chartInstance->c1_is_NDBDisplay;
  c1_dc_u = c1_ib_hoistedGlobal;
  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", &c1_dc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 38, c1_ic_y);
  c1_jb_hoistedGlobal = chartInstance->c1_is_ARPTDisplay;
  c1_ec_u = c1_jb_hoistedGlobal;
  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", &c1_ec_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 39, c1_jc_y);
  c1_kb_hoistedGlobal = chartInstance->c1_temporalCounter_i8;
  c1_fc_u = c1_kb_hoistedGlobal;
  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", &c1_fc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 40, c1_kc_y);
  c1_lb_hoistedGlobal = chartInstance->c1_temporalCounter_i6;
  c1_gc_u = c1_lb_hoistedGlobal;
  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", &c1_gc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 41, c1_lc_y);
  c1_mb_hoistedGlobal = chartInstance->c1_temporalCounter_i5;
  c1_hc_u = c1_mb_hoistedGlobal;
  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_create("y", &c1_hc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 42, c1_mc_y);
  c1_nb_hoistedGlobal = chartInstance->c1_temporalCounter_i2;
  c1_ic_u = c1_nb_hoistedGlobal;
  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", &c1_ic_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 43, c1_nc_y);
  c1_ob_hoistedGlobal = chartInstance->c1_temporalCounter_i4;
  c1_jc_u = c1_ob_hoistedGlobal;
  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_create("y", &c1_jc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 44, c1_oc_y);
  c1_pb_hoistedGlobal = chartInstance->c1_temporalCounter_i3;
  c1_kc_u = c1_pb_hoistedGlobal;
  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_create("y", &c1_kc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 45, c1_pc_y);
  c1_qb_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_lc_u = c1_qb_hoistedGlobal;
  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_create("y", &c1_lc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 46, c1_qc_y);
  c1_rb_hoistedGlobal = chartInstance->c1_temporalCounter_i7;
  c1_mc_u = c1_rb_hoistedGlobal;
  c1_rc_y = NULL;
  sf_mex_assign(&c1_rc_y, sf_mex_create("y", &c1_mc_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 47, c1_rc_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  c1_EngineDisplayBus c1_r1;
  c1_FCU_Output c1_r2;
  c1_NDAdditionalDisplay c1_r3;
  c1_PFDOutput c1_r4;
  c1_warnings_bus c1_r5;
  int32_T c1_i1;
  real_T *c1_ECAMMode;
  real_T *c1_EFIS_Pressure_Output;
  real_T *c1_NDMode;
  c1_EngineDisplayBus *c1_ED;
  c1_warnings_bus *c1_outputDisplay;
  c1_FCU_Output *c1_FCU_Display;
  c1_NDAdditionalDisplay *c1_ND_AD_OP;
  c1_PFDOutput *c1_PFD;
  c1_PFD = (c1_PFDOutput *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal(chartInstance->S,
    7);
  c1_NDMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_ED = (c1_EngineDisplayBus *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_EFIS_Pressure_Output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_FCU_Display = (c1_FCU_Output *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_outputDisplay = (c1_warnings_bus *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c1_u = sf_mex_dup(c1_st);
  *c1_ECAMMode = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "ECAMMode");
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)), "ED",
                        &c1_r1);
  *(real_T *)((char_T *)c1_ED + 0) = c1_r1.EPR1;
  *(real_T *)((char_T *)c1_ED + 8) = c1_r1.EPR2;
  *(real_T *)((char_T *)c1_ED + 16) = c1_r1.EGT1;
  *(real_T *)((char_T *)c1_ED + 24) = c1_r1.EGT2;
  *(real_T *)((char_T *)c1_ED + 32) = c1_r1.FlapConfig;
  *(real_T *)((char_T *)c1_ED + 40) = c1_r1.N1_L;
  *(real_T *)((char_T *)c1_ED + 48) = c1_r1.N1_R;
  *(real_T *)((char_T *)c1_ED + 56) = c1_r1.ED_Mode_L;
  *(real_T *)((char_T *)c1_ED + 64) = c1_r1.ED_Mode_R;
  *(real_T *)((char_T *)c1_ED + 72) = c1_r1.FuelQuantity;
  *c1_EFIS_Pressure_Output = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "EFIS_Pressure_Output");
  c1_r2 = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "FCU_Display");
  *(real_T *)((char_T *)c1_FCU_Display + 0) = c1_r2.Speed;
  *(real_T *)((char_T *)c1_FCU_Display + 8) = c1_r2.Heading;
  *(real_T *)((char_T *)c1_FCU_Display + 16) = c1_r2.Altitude;
  *c1_NDMode = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "NDMode");
  c1_r3 = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
    "ND_AD_OP");
  *(real_T *)((char_T *)c1_ND_AD_OP + 0) = c1_r3.CSTR;
  *(real_T *)((char_T *)c1_ND_AD_OP + 8) = c1_r3.WPT;
  *(real_T *)((char_T *)c1_ND_AD_OP + 16) = c1_r3.VORD;
  *(real_T *)((char_T *)c1_ND_AD_OP + 24) = c1_r3.NDB;
  *(real_T *)((char_T *)c1_ND_AD_OP + 32) = c1_r3.ARPT;
  c1_r4 = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
    "PFD");
  *(real_T *)((char_T *)c1_PFD + 0) = c1_r4.Altitude;
  *(real_T *)((char_T *)c1_PFD + 8) = c1_r4.Heading;
  *(real_T *)((char_T *)c1_PFD + 16) = c1_r4.Attitude;
  *(real_T *)((char_T *)c1_PFD + 24) = c1_r4.AirSpeed;
  *(real_T *)((char_T *)c1_PFD + 32) = c1_r4.AltMode;
  *(real_T *)((char_T *)c1_PFD + 40) = c1_r4.AirSpeedMode;
  *(real_T *)((char_T *)c1_PFD + 48) = c1_r4.AttMode;
  *(real_T *)((char_T *)c1_PFD + 56) = c1_r4.HeadingMode;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "outputDisplay", &c1_r5);
  *(real_T *)((char_T *)c1_outputDisplay + 0) = c1_r5.flightmode;
  *(real_T *)((char_T *)c1_outputDisplay + 8) = c1_r5.ED_Mode_R;
  *(real_T *)((char_T *)c1_outputDisplay + 16) = c1_r5.ED_Mode_L;
  for (c1_i1 = 0; c1_i1 < 10; c1_i1++) {
    ((real_T *)((char_T *)c1_outputDisplay + 24))[c1_i1] =
      c1_r5.warn_msgID[c1_i1];
  }

  chartInstance->c1_is_active_c1_CockpitDisplayLib = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
     "is_active_c1_CockpitDisplayLib");
  chartInstance->c1_is_active_NavigationDisplay = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 9)),
     "is_active_NavigationDisplay");
  chartInstance->c1_is_active_SystemDisplay = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
     "is_active_SystemDisplay");
  chartInstance->c1_is_active_EngineDisplay = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 11)),
     "is_active_EngineDisplay");
  chartInstance->c1_is_active_PrimaryFlightDisplay = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
     "is_active_PrimaryFlightDisplay");
  chartInstance->c1_is_active_AirSpeed = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 13)), "is_active_AirSpeed");
  chartInstance->c1_is_active_Altitude = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 14)), "is_active_Altitude");
  chartInstance->c1_is_active_Attitude = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 15)), "is_active_Attitude");
  chartInstance->c1_is_active_Heading = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "is_active_Heading");
  chartInstance->c1_is_active_FCU_EFIS_Display = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 17)),
     "is_active_FCU_EFIS_Display");
  chartInstance->c1_is_active_NDDisplayPages = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 18)),
     "is_active_NDDisplayPages");
  chartInstance->c1_is_active_CSTRDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 19)), "is_active_CSTRDisplay");
  chartInstance->c1_is_active_WPTDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 20)), "is_active_WPTDisplay");
  chartInstance->c1_is_active_VORDDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 21)), "is_active_VORDDisplay");
  chartInstance->c1_is_active_NDBDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 22)), "is_active_NDBDisplay");
  chartInstance->c1_is_active_ARPTDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 23)), "is_active_ARPTDisplay");
  chartInstance->c1_is_SystemDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 24)), "is_SystemDisplay");
  chartInstance->c1_is_EngineDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 25)), "is_EngineDisplay");
  chartInstance->c1_is_AirSpeed = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "is_AirSpeed");
  chartInstance->c1_is_Altitude = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "is_Altitude");
  chartInstance->c1_is_Attitude = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 28)), "is_Attitude");
  chartInstance->c1_is_Heading = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 29)), "is_Heading");
  chartInstance->c1_is_NormalFlight = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 30)), "is_NormalFlight");
  chartInstance->c1_is_UserSelection_Faults = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 31)),
     "is_UserSelection_Faults");
  chartInstance->c1_is_Startup = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 32)), "is_Startup");
  chartInstance->c1_is_NDDisplayPages = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "is_NDDisplayPages");
  chartInstance->c1_is_NDRunning = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 34)), "is_NDRunning");
  chartInstance->c1_is_CSTRDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 35)), "is_CSTRDisplay");
  chartInstance->c1_is_WPTDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 36)), "is_WPTDisplay");
  chartInstance->c1_is_VORDDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 37)), "is_VORDDisplay");
  chartInstance->c1_is_NDBDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 38)), "is_NDBDisplay");
  chartInstance->c1_is_ARPTDisplay = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 39)), "is_ARPTDisplay");
  chartInstance->c1_temporalCounter_i8 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 40)), "temporalCounter_i8");
  chartInstance->c1_temporalCounter_i6 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 41)), "temporalCounter_i6");
  chartInstance->c1_temporalCounter_i5 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 42)), "temporalCounter_i5");
  chartInstance->c1_temporalCounter_i2 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 43)), "temporalCounter_i2");
  chartInstance->c1_temporalCounter_i4 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 44)), "temporalCounter_i4");
  chartInstance->c1_temporalCounter_i3 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 45)), "temporalCounter_i3");
  chartInstance->c1_temporalCounter_i1 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 46)), "temporalCounter_i1");
  chartInstance->c1_temporalCounter_i7 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 47)), "temporalCounter_i7");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 48)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_CockpitDisplayLib(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_PrimaryFlightDisplay == 1U) {
      chartInstance->c1_tp_PrimaryFlightDisplay = 1U;
    } else {
      chartInstance->c1_tp_PrimaryFlightDisplay = 0U;
    }

    if (chartInstance->c1_is_active_AirSpeed == 1U) {
      chartInstance->c1_tp_AirSpeed = 1U;
    } else {
      chartInstance->c1_tp_AirSpeed = 0U;
    }

    if (chartInstance->c1_is_AirSpeed == c1_IN_OFF) {
      chartInstance->c1_tp_OFF = 1U;
    } else {
      chartInstance->c1_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_AirSpeed == c1_IN_Running) {
      chartInstance->c1_tp_Running = 1U;
    } else {
      chartInstance->c1_tp_Running = 0U;
    }

    if (chartInstance->c1_is_AirSpeed == c1_IN_Starting) {
      chartInstance->c1_tp_Starting = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_Starting = 0U;
    }

    if (chartInstance->c1_is_active_Altitude == 1U) {
      chartInstance->c1_tp_Altitude = 1U;
    } else {
      chartInstance->c1_tp_Altitude = 0U;
    }

    if (chartInstance->c1_is_Altitude == c1_IN_OFF) {
      chartInstance->c1_b_tp_OFF = 1U;
    } else {
      chartInstance->c1_b_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_Altitude == c1_IN_Running) {
      chartInstance->c1_b_tp_Running = 1U;
    } else {
      chartInstance->c1_b_tp_Running = 0U;
    }

    if (chartInstance->c1_is_Altitude == c1_IN_Starting) {
      chartInstance->c1_b_tp_Starting = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c1_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c1_b_tp_Starting = 0U;
    }

    if (chartInstance->c1_is_active_Heading == 1U) {
      chartInstance->c1_tp_Heading = 1U;
    } else {
      chartInstance->c1_tp_Heading = 0U;
    }

    if (chartInstance->c1_is_Heading == c1_IN_OFF) {
      chartInstance->c1_c_tp_OFF = 1U;
    } else {
      chartInstance->c1_c_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_Heading == c1_IN_Running) {
      chartInstance->c1_c_tp_Running = 1U;
    } else {
      chartInstance->c1_c_tp_Running = 0U;
    }

    if (chartInstance->c1_is_Heading == c1_IN_Starting) {
      chartInstance->c1_c_tp_Starting = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c1_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c1_c_tp_Starting = 0U;
    }

    if (chartInstance->c1_is_active_Attitude == 1U) {
      chartInstance->c1_tp_Attitude = 1U;
    } else {
      chartInstance->c1_tp_Attitude = 0U;
    }

    if (chartInstance->c1_is_Attitude == c1_IN_OFF) {
      chartInstance->c1_d_tp_OFF = 1U;
    } else {
      chartInstance->c1_d_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_Attitude == c1_IN_Running) {
      chartInstance->c1_d_tp_Running = 1U;
    } else {
      chartInstance->c1_d_tp_Running = 0U;
    }

    if (chartInstance->c1_is_Attitude == c1_IN_Starting) {
      chartInstance->c1_d_tp_Starting = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 18) == 0.0) {
        chartInstance->c1_temporalCounter_i4 = 0U;
      }
    } else {
      chartInstance->c1_d_tp_Starting = 0U;
    }

    if (chartInstance->c1_is_active_NavigationDisplay == 1U) {
      chartInstance->c1_tp_NavigationDisplay = 1U;
    } else {
      chartInstance->c1_tp_NavigationDisplay = 0U;
    }

    if (chartInstance->c1_is_active_NDDisplayPages == 1U) {
      chartInstance->c1_tp_NDDisplayPages = 1U;
    } else {
      chartInstance->c1_tp_NDDisplayPages = 0U;
    }

    if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDOff) {
      chartInstance->c1_tp_NDOff = 1U;
    } else {
      chartInstance->c1_tp_NDOff = 0U;
    }

    if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDRunning) {
      chartInstance->c1_tp_NDRunning = 1U;
    } else {
      chartInstance->c1_tp_NDRunning = 0U;
    }

    if (chartInstance->c1_is_NDRunning == c1_IN_ARCPage) {
      chartInstance->c1_tp_ARCPage = 1U;
    } else {
      chartInstance->c1_tp_ARCPage = 0U;
    }

    if (chartInstance->c1_is_NDRunning == c1_IN_ILSPage) {
      chartInstance->c1_tp_ILSPage = 1U;
    } else {
      chartInstance->c1_tp_ILSPage = 0U;
    }

    if (chartInstance->c1_is_NDRunning == c1_IN_NAVPage) {
      chartInstance->c1_tp_NAVPage = 1U;
    } else {
      chartInstance->c1_tp_NAVPage = 0U;
    }

    if (chartInstance->c1_is_NDRunning == c1_IN_PLANPage) {
      chartInstance->c1_tp_PLANPage = 1U;
    } else {
      chartInstance->c1_tp_PLANPage = 0U;
    }

    if (chartInstance->c1_is_NDRunning == c1_IN_VORPage) {
      chartInstance->c1_tp_VORPage = 1U;
    } else {
      chartInstance->c1_tp_VORPage = 0U;
    }

    if (chartInstance->c1_is_NDDisplayPages == c1_IN_NDStart) {
      chartInstance->c1_tp_NDStart = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 28) == 0.0) {
        chartInstance->c1_temporalCounter_i5 = 0U;
      }
    } else {
      chartInstance->c1_tp_NDStart = 0U;
    }

    if (chartInstance->c1_is_active_CSTRDisplay == 1U) {
      chartInstance->c1_tp_CSTRDisplay = 1U;
    } else {
      chartInstance->c1_tp_CSTRDisplay = 0U;
    }

    if (chartInstance->c1_is_CSTRDisplay == c1_IN_OFF) {
      chartInstance->c1_e_tp_OFF = 1U;
    } else {
      chartInstance->c1_e_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_CSTRDisplay == c1_IN_ON) {
      chartInstance->c1_tp_ON = 1U;
    } else {
      chartInstance->c1_tp_ON = 0U;
    }

    if (chartInstance->c1_is_active_WPTDisplay == 1U) {
      chartInstance->c1_tp_WPTDisplay = 1U;
    } else {
      chartInstance->c1_tp_WPTDisplay = 0U;
    }

    if (chartInstance->c1_is_WPTDisplay == c1_IN_OFF) {
      chartInstance->c1_f_tp_OFF = 1U;
    } else {
      chartInstance->c1_f_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_WPTDisplay == c1_IN_ON) {
      chartInstance->c1_b_tp_ON = 1U;
    } else {
      chartInstance->c1_b_tp_ON = 0U;
    }

    if (chartInstance->c1_is_active_VORDDisplay == 1U) {
      chartInstance->c1_tp_VORDDisplay = 1U;
    } else {
      chartInstance->c1_tp_VORDDisplay = 0U;
    }

    if (chartInstance->c1_is_VORDDisplay == c1_IN_OFF) {
      chartInstance->c1_g_tp_OFF = 1U;
    } else {
      chartInstance->c1_g_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_VORDDisplay == c1_IN_ON) {
      chartInstance->c1_c_tp_ON = 1U;
    } else {
      chartInstance->c1_c_tp_ON = 0U;
    }

    if (chartInstance->c1_is_active_NDBDisplay == 1U) {
      chartInstance->c1_tp_NDBDisplay = 1U;
    } else {
      chartInstance->c1_tp_NDBDisplay = 0U;
    }

    if (chartInstance->c1_is_NDBDisplay == c1_IN_OFF) {
      chartInstance->c1_h_tp_OFF = 1U;
    } else {
      chartInstance->c1_h_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_NDBDisplay == c1_IN_ON) {
      chartInstance->c1_d_tp_ON = 1U;
    } else {
      chartInstance->c1_d_tp_ON = 0U;
    }

    if (chartInstance->c1_is_active_ARPTDisplay == 1U) {
      chartInstance->c1_tp_ARPTDisplay = 1U;
    } else {
      chartInstance->c1_tp_ARPTDisplay = 0U;
    }

    if (chartInstance->c1_is_ARPTDisplay == c1_IN_OFF) {
      chartInstance->c1_i_tp_OFF = 1U;
    } else {
      chartInstance->c1_i_tp_OFF = 0U;
    }

    if (chartInstance->c1_is_ARPTDisplay == c1_IN_ON) {
      chartInstance->c1_e_tp_ON = 1U;
    } else {
      chartInstance->c1_e_tp_ON = 0U;
    }

    if (chartInstance->c1_is_active_EngineDisplay == 1U) {
      chartInstance->c1_tp_EngineDisplay = 1U;
    } else {
      chartInstance->c1_tp_EngineDisplay = 0U;
    }

    if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Boot) {
      chartInstance->c1_tp_Engine_Boot = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 45) == 0.0) {
        chartInstance->c1_temporalCounter_i6 = 0U;
      }
    } else {
      chartInstance->c1_tp_Engine_Boot = 0U;
    }

    if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Off) {
      chartInstance->c1_tp_Engine_Off = 1U;
    } else {
      chartInstance->c1_tp_Engine_Off = 0U;
    }

    if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Ready) {
      chartInstance->c1_tp_Engine_Ready = 1U;
    } else {
      chartInstance->c1_tp_Engine_Ready = 0U;
    }

    if (chartInstance->c1_is_EngineDisplay == c1_IN_Engine_Running) {
      chartInstance->c1_tp_Engine_Running = 1U;
    } else {
      chartInstance->c1_tp_Engine_Running = 0U;
    }

    if (chartInstance->c1_is_active_SystemDisplay == 1U) {
      chartInstance->c1_tp_SystemDisplay = 1U;
    } else {
      chartInstance->c1_tp_SystemDisplay = 0U;
    }

    if (chartInstance->c1_is_SystemDisplay == c1_IN_NormalFlight) {
      chartInstance->c1_tp_NormalFlight = 1U;
    } else {
      chartInstance->c1_tp_NormalFlight = 0U;
    }

    if (chartInstance->c1_is_NormalFlight == c1_IN_Land) {
      chartInstance->c1_tp_Land = 1U;
    } else {
      chartInstance->c1_tp_Land = 0U;
    }

    if (chartInstance->c1_is_NormalFlight == c1_IN_PushbackAndTaxi) {
      chartInstance->c1_tp_PushbackAndTaxi = 1U;
    } else {
      chartInstance->c1_tp_PushbackAndTaxi = 0U;
    }

    if (chartInstance->c1_is_NormalFlight == c1_IN_TakeoffCruiseDescent) {
      chartInstance->c1_tp_TakeoffCruiseDescent = 1U;
    } else {
      chartInstance->c1_tp_TakeoffCruiseDescent = 0U;
    }

    if (chartInstance->c1_is_SystemDisplay == c1_IN_Startup) {
      chartInstance->c1_tp_Startup = 1U;
    } else {
      chartInstance->c1_tp_Startup = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_APU_Boot) {
      chartInstance->c1_tp_APU_Boot = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 55) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_APU_Boot = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_APU_Off) {
      chartInstance->c1_tp_APU_Off = 1U;
    } else {
      chartInstance->c1_tp_APU_Off = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_APU_Ready) {
      chartInstance->c1_tp_APU_Ready = 1U;
    } else {
      chartInstance->c1_tp_APU_Ready = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_APU_Running) {
      chartInstance->c1_tp_APU_Running = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 58) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_APU_Running = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_APU_Wait) {
      chartInstance->c1_tp_APU_Wait = 1U;
    } else {
      chartInstance->c1_tp_APU_Wait = 0U;
    }

    if (chartInstance->c1_is_Startup == c1_IN_EngineStarting) {
      chartInstance->c1_tp_EngineStarting = 1U;
    } else {
      chartInstance->c1_tp_EngineStarting = 0U;
    }

    if (chartInstance->c1_is_SystemDisplay == c1_IN_UserSelection_Faults) {
      chartInstance->c1_tp_UserSelection_Faults = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 61) == 0.0) {
        chartInstance->c1_temporalCounter_i8 = 0U;
      }
    } else {
      chartInstance->c1_tp_UserSelection_Faults = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_APU) {
      chartInstance->c1_tp_APU = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 62) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_APU = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Bleed) {
      chartInstance->c1_tp_Bleed = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 63) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_Bleed = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Cabin_Pressure) {
      chartInstance->c1_tp_Cabin_Pressure = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 64) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_Cabin_Pressure = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_ERROR) {
      chartInstance->c1_tp_ERROR = 1U;
    } else {
      chartInstance->c1_tp_ERROR = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_Engine) {
      chartInstance->c1_tp_Engine = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 66) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_Engine = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_FUEL) {
      chartInstance->c1_tp_FUEL = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 67) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_FUEL = 0U;
    }

    if (chartInstance->c1_is_UserSelection_Faults == c1_IN_HYD) {
      chartInstance->c1_tp_HYD = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 68) == 0.0) {
        chartInstance->c1_temporalCounter_i7 = 0U;
      }
    } else {
      chartInstance->c1_tp_HYD = 0U;
    }

    if (chartInstance->c1_is_active_FCU_EFIS_Display == 1U) {
      chartInstance->c1_tp_FCU_EFIS_Display = 1U;
    } else {
      chartInstance->c1_tp_FCU_EFIS_Display = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_CockpitDisplayLib(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_a;
  c1_EFIS_Pressure *c1_EFIS_Input;
  real_T *c1_EFIS_Pressure_Output;
  c1_FCU_Output *c1_FCU_Display;
  c1_FlightInputs *c1_PFD_Input;
  c1_NavData *c1_Nav;
  c1_MiscData *c1_Misc;
  c1_EFIS_Pressure_Output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_Misc = (c1_MiscData *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_FCU_Display = (c1_FCU_Output *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Nav = (c1_NavData *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_PFD_Input = (c1_FlightInputs *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_EFIS_Input = (c1_EFIS_Pressure *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_CockpitDisplayLib(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c1_temporalCounter_i1 < 7U) {
    chartInstance->c1_temporalCounter_i1++;
  }

  if (chartInstance->c1_temporalCounter_i2 < 7U) {
    chartInstance->c1_temporalCounter_i2++;
  }

  if (chartInstance->c1_temporalCounter_i3 < 7U) {
    chartInstance->c1_temporalCounter_i3++;
  }

  if (chartInstance->c1_temporalCounter_i4 < 7U) {
    chartInstance->c1_temporalCounter_i4++;
  }

  if (chartInstance->c1_temporalCounter_i5 < 7U) {
    chartInstance->c1_temporalCounter_i5++;
  }

  if (chartInstance->c1_temporalCounter_i6 < 7U) {
    chartInstance->c1_temporalCounter_i6++;
  }

  if (chartInstance->c1_temporalCounter_i7 < 7U) {
    chartInstance->c1_temporalCounter_i7++;
  }

  if (chartInstance->c1_temporalCounter_i8 < 3U) {
    chartInstance->c1_temporalCounter_i8++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_CockpitDisplayLib == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_CockpitDisplayLib = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    c1_enter_internal_c1_CockpitDisplayLib(chartInstance);
  } else {
    c1_PrimaryFlightDisplay(chartInstance);
    c1_NavigationDisplay(chartInstance);
    c1_EngineDisplay(chartInstance);
    c1_SystemDisplay(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_lb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *(real_T *)((char_T *)c1_FCU_Display + 0) = *(real_T *)((char_T *)
      c1_PFD_Input + 16);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    *(real_T *)((char_T *)c1_FCU_Display + 8) = *(real_T *)((char_T *)c1_Nav +
      24);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    *(real_T *)((char_T *)c1_FCU_Display + 16) = *(real_T *)((char_T *)
      c1_PFD_Input + 24);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    if (CV_EML_IF(6, 1, 1, *c1_EFIS_Input == EFIS_Pressure_inHg)) {
      *c1_EFIS_Pressure_Output = *(real_T *)((char_T *)c1_Misc + 8);
      c1_updateDataWrittenToVector(chartInstance, 3U);
    } else {
      c1_a = *(real_T *)((char_T *)c1_Misc + 8);
      *c1_EFIS_Pressure_Output = c1_a * 25.4;
      c1_updateDataWrittenToVector(chartInstance, 3U);
    }

    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CockpitDisplayLibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_enter_internal_c1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  int32_T c1_i2;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_a;
  real_T *c1_FlightMode;
  c1_EFIS_Pressure *c1_EFIS_Input;
  real_T *c1_EFIS_Pressure_Output;
  real_T (*c1_warn_msgID)[10];
  c1_PFDOutput *c1_PFD;
  c1_FlightInputs *c1_PFD_Input;
  c1_NDAdditionalDisplay *c1_ND_AD_OP;
  c1_warnings_bus *c1_outputDisplay;
  c1_EngineDisplayBus *c1_ED;
  c1_EngineFuel_Bus *c1_EnF;
  c1_FCU_Output *c1_FCU_Display;
  c1_NavData *c1_Nav;
  c1_MiscData *c1_Misc;
  c1_PFD = (c1_PFDOutput *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal(chartInstance->S,
    7);
  c1_ED = (c1_EngineDisplayBus *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_EFIS_Pressure_Output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_Misc = (c1_MiscData *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_EnF = (c1_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_FCU_Display = (c1_FCU_Output *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Nav = (c1_NavData *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_PFD_Input = (c1_FlightInputs *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_outputDisplay = (c1_warnings_bus *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c1_warn_msgID = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 4);
  c1_EFIS_Input = (c1_EFIS_Pressure *)ssGetInputPortSignal(chartInstance->S, 1);
  chartInstance->c1_is_active_PrimaryFlightDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_PrimaryFlightDisplay = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_PFD + 24) = *(real_T *)((char_T *)c1_PFD_Input + 16);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 16) = *(real_T *)((char_T *)c1_PFD_Input + 40);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 8) = *(real_T *)((char_T *)c1_PFD_Input + 0);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 0) = *(real_T *)((char_T *)c1_PFD_Input + 24);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_AirSpeed = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_AirSpeed = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_AirSpeed = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_OFF = 1U;
  chartInstance->c1_is_active_Altitude = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Altitude = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_Altitude = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  chartInstance->c1_b_tp_OFF = 1U;
  chartInstance->c1_is_active_Heading = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Heading = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_Heading = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  chartInstance->c1_c_tp_OFF = 1U;
  chartInstance->c1_is_active_Attitude = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Attitude = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_Attitude = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  chartInstance->c1_d_tp_OFF = 1U;
  chartInstance->c1_is_active_NavigationDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NavigationDisplay = 1U;
  chartInstance->c1_is_active_NDDisplayPages = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NDDisplayPages = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_NDDisplayPages = c1_IN_NDOff;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NDOff = 1U;
  chartInstance->c1_is_active_CSTRDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_CSTRDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_CSTRDisplay = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  chartInstance->c1_e_tp_OFF = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_q_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_ND_AD_OP + 0) = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_WPTDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_WPTDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_WPTDisplay = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  chartInstance->c1_f_tp_OFF = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_s_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_ND_AD_OP + 8) = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_VORDDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_VORDDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_VORDDisplay = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  chartInstance->c1_g_tp_OFF = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_u_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_ND_AD_OP + 16) = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_NDBDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NDBDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_NDBDisplay = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  chartInstance->c1_h_tp_OFF = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_w_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_ND_AD_OP + 24) = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_ARPTDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_ARPTDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_ARPTDisplay = c1_IN_OFF;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  chartInstance->c1_i_tp_OFF = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_y_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_ND_AD_OP + 32) = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_EngineDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_EngineDisplay = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_bb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  for (c1_i2 = 0; c1_i2 < 10; c1_i2++) {
    ((real_T *)((char_T *)c1_outputDisplay + 24))[c1_i2] = (*c1_warn_msgID)
      [c1_i2];
  }

  c1_updateDataWrittenToVector(chartInstance, 0U);
  *(real_T *)((char_T *)c1_outputDisplay + 0) = *c1_FlightMode;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  *(real_T *)((char_T *)c1_ED + 40) = *(real_T *)((char_T *)c1_EnF + 0);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 48) = *(real_T *)((char_T *)c1_EnF + 0);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 32) = c1_calcFlapConfig(chartInstance,
    *c1_FlightMode);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 16) = *(real_T *)((char_T *)c1_EnF + 32);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 24) = *(real_T *)((char_T *)c1_EnF + 32);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 0) = *(real_T *)((char_T *)c1_EnF + 40);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 8) = *(real_T *)((char_T *)c1_EnF + 48);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 72) = *(real_T *)((char_T *)c1_EnF + 56);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_EngineDisplay = c1_IN_Engine_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Engine_Off = 1U;
  chartInstance->c1_is_active_SystemDisplay = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_SystemDisplay = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_SystemDisplay = c1_IN_Startup;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Startup = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_Startup = c1_IN_APU_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_APU_Off = 1U;
  chartInstance->c1_is_active_FCU_EFIS_Display = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_FCU_EFIS_Display = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_kb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_FCU_Display + 0) = *(real_T *)((char_T *)c1_PFD_Input
    + 16);
  c1_updateDataWrittenToVector(chartInstance, 2U);
  *(real_T *)((char_T *)c1_FCU_Display + 8) = *(real_T *)((char_T *)c1_Nav + 24);
  c1_updateDataWrittenToVector(chartInstance, 2U);
  *(real_T *)((char_T *)c1_FCU_Display + 16) = *(real_T *)((char_T *)
    c1_PFD_Input + 24);
  c1_updateDataWrittenToVector(chartInstance, 2U);
  if (CV_EML_IF(6, 1, 0, *c1_EFIS_Input == EFIS_Pressure_inHg)) {
    *c1_EFIS_Pressure_Output = *(real_T *)((char_T *)c1_Misc + 8);
    c1_updateDataWrittenToVector(chartInstance, 3U);
  } else {
    c1_a = *(real_T *)((char_T *)c1_Misc + 8);
    *c1_EFIS_Pressure_Output = c1_a * 25.4;
    c1_updateDataWrittenToVector(chartInstance, 3U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void initSimStructsc1_CockpitDisplayLib
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
}

static void c1_PrimaryFlightDisplay(SFc1_CockpitDisplayLibInstanceStruct
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
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 0.0;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 0.0;
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_q_nargin = 0.0;
  real_T c1_q_nargout = 0.0;
  real_T *c1_APU_Mode;
  c1_PFDOutput *c1_PFD;
  c1_FlightInputs *c1_PFD_Input;
  c1_PFD = (c1_PFDOutput *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_PFD_Input = (c1_FlightInputs *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_APU_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  *(real_T *)((char_T *)c1_PFD + 24) = *(real_T *)((char_T *)c1_PFD_Input + 16);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 16) = *(real_T *)((char_T *)c1_PFD_Input + 40);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 8) = *(real_T *)((char_T *)c1_PFD_Input + 0);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  *(real_T *)((char_T *)c1_PFD + 0) = *(real_T *)((char_T *)c1_PFD_Input + 24);
  c1_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_AirSpeed) {
   case c1_IN_OFF:
    CV_STATE_EVAL(33, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_bc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_out = CV_EML_IF(68, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_AirSpeed = c1_IN_Starting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_Starting = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 40) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Running:
    CV_STATE_EVAL(33, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Starting:
    CV_STATE_EVAL(33, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 69U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_cc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(69, 0, 0, chartInstance->c1_temporalCounter_i1 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Starting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_AirSpeed = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 40) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(33, 0, 0);
    chartInstance->c1_is_AirSpeed = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_Altitude) {
   case c1_IN_OFF:
    CV_STATE_EVAL(37, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_dc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(59, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Altitude = c1_IN_Starting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i2 = 0U;
      chartInstance->c1_b_tp_Starting = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 32) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Running:
    CV_STATE_EVAL(37, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Starting:
    CV_STATE_EVAL(37, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 60U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ec_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_d_out = CV_EML_IF(60, 0, 0, chartInstance->c1_temporalCounter_i2 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Starting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Altitude = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_f_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 32) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(37, 0, 0);
    chartInstance->c1_is_Altitude = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_Heading) {
   case c1_IN_OFF:
    CV_STATE_EVAL(45, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_e_out = CV_EML_IF(65, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Heading = c1_IN_Starting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i3 = 0U;
      chartInstance->c1_c_tp_Starting = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_g_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 56) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Running:
    CV_STATE_EVAL(45, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Starting:
    CV_STATE_EVAL(45, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 66U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_gc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_f_out = CV_EML_IF(66, 0, 0, chartInstance->c1_temporalCounter_i3 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_Starting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Heading = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_h_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 56) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(45, 0, 0);
    chartInstance->c1_is_Heading = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_Attitude) {
   case c1_IN_OFF:
    CV_STATE_EVAL(41, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_hc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_g_out = CV_EML_IF(62, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
      chartInstance->c1_d_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Attitude = c1_IN_Starting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i4 = 0U;
      chartInstance->c1_d_tp_Starting = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_i_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 48) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Running:
    CV_STATE_EVAL(41, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Starting:
    CV_STATE_EVAL(41, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ic_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_h_out = CV_EML_IF(63, 0, 0, chartInstance->c1_temporalCounter_i4 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_h_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
      chartInstance->c1_d_tp_Starting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Attitude = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
      chartInstance->c1_d_tp_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_j_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_PFD + 48) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(41, 0, 0);
    chartInstance->c1_is_Attitude = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
}

static void c1_NavigationDisplay(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 0.0;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 0.0;
  c1_NDAdditionalDisplay *c1_ND_AD_OP;
  c1_NDAdditionalDisplay *c1_ND_AD;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal(chartInstance->S,
    7);
  c1_ND_AD = (c1_NDAdditionalDisplay *)ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
  c1_NDDisplayPages(chartInstance);
  c1_CSTRDisplay(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_WPTDisplay) {
   case c1_IN_OFF:
    CV_STATE_EVAL(29, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_sc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard4 = FALSE;
    if (CV_EML_COND(47, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 8) == 1.0)) {
      if (CV_EML_COND(47, 0, 1, chartInstance->c1_is_NDDisplayPages ==
                      c1_IN_NDRunning)) {
        CV_EML_MCDC(47, 0, 0, TRUE);
        CV_EML_IF(47, 0, 0, TRUE);
        c1_out = TRUE;
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      CV_EML_MCDC(47, 0, 0, FALSE);
      CV_EML_IF(47, 0, 0, FALSE);
      c1_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
      chartInstance->c1_f_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_WPTDisplay = c1_IN_ON;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_ON = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_t_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 8) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ON:
    CV_STATE_EVAL(29, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_tc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(48, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 8) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_WPTDisplay = c1_IN_OFF;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
      chartInstance->c1_f_tp_OFF = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_s_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 8) = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(29, 0, 0);
    chartInstance->c1_is_WPTDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_VORDDisplay) {
   case c1_IN_OFF:
    CV_STATE_EVAL(26, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_uc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard3 = FALSE;
    if (CV_EML_COND(50, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 16) == 1.0)) {
      if (CV_EML_COND(50, 0, 1, chartInstance->c1_is_NDDisplayPages ==
                      c1_IN_NDRunning)) {
        CV_EML_MCDC(50, 0, 0, TRUE);
        CV_EML_IF(50, 0, 0, TRUE);
        c1_c_out = TRUE;
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      CV_EML_MCDC(50, 0, 0, FALSE);
      CV_EML_IF(50, 0, 0, FALSE);
      c1_c_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
      chartInstance->c1_g_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_VORDDisplay = c1_IN_ON;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_ON = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_v_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 16) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ON:
    CV_STATE_EVAL(26, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 49U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_d_out = CV_EML_IF(49, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 16) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_VORDDisplay = c1_IN_OFF;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
      chartInstance->c1_g_tp_OFF = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_u_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 16) = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(26, 0, 0);
    chartInstance->c1_is_VORDDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_NDBDisplay) {
   case c1_IN_OFF:
    CV_STATE_EVAL(14, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard2 = FALSE;
    if (CV_EML_COND(54, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 24) == 1.0)) {
      if (CV_EML_COND(54, 0, 1, chartInstance->c1_is_NDDisplayPages ==
                      c1_IN_NDRunning)) {
        CV_EML_MCDC(54, 0, 0, TRUE);
        CV_EML_IF(54, 0, 0, TRUE);
        c1_e_out = TRUE;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(54, 0, 0, FALSE);
      CV_EML_IF(54, 0, 0, FALSE);
      c1_e_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
      chartInstance->c1_h_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NDBDisplay = c1_IN_ON;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_d_tp_ON = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_x_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 24) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ON:
    CV_STATE_EVAL(14, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_f_out = CV_EML_IF(53, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 24) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
      chartInstance->c1_d_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NDBDisplay = c1_IN_OFF;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_h_tp_OFF = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_w_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 24) = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(14, 0, 0);
    chartInstance->c1_is_NDBDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_ARPTDisplay) {
   case c1_IN_OFF:
    CV_STATE_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_yc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard1 = FALSE;
    if (CV_EML_COND(55, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 32) == 1.0)) {
      if (CV_EML_COND(55, 0, 1, chartInstance->c1_is_NDDisplayPages ==
                      c1_IN_NDRunning)) {
        CV_EML_MCDC(55, 0, 0, TRUE);
        CV_EML_IF(55, 0, 0, TRUE);
        c1_g_out = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(55, 0, 0, FALSE);
      CV_EML_IF(55, 0, 0, FALSE);
      c1_g_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
      chartInstance->c1_i_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_ARPTDisplay = c1_IN_ON;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_e_tp_ON = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ab_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 32) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ON:
    CV_STATE_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ad_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_h_out = CV_EML_IF(57, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 32) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_h_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
      chartInstance->c1_e_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_ARPTDisplay = c1_IN_OFF;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_i_tp_OFF = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_y_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 32) = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(8, 0, 0);
    chartInstance->c1_is_ARPTDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
}

static void c1_NDDisplayPages(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T *c1_APU_Mode;
  real_T *c1_NDMode;
  c1_NDMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_APU_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_NDDisplayPages) {
   case c1_IN_NDOff:
    CV_STATE_EVAL(17, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_oc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_out = CV_EML_IF(34, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NDOff = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NDDisplayPages = c1_IN_NDStart;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i5 = 0U;
      chartInstance->c1_tp_NDStart = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_p_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_NDMode = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_NDRunning:
    CV_STATE_EVAL(17, 0, 2);
    c1_NDRunning(chartInstance);
    break;

   case c1_IN_NDStart:
    CV_STATE_EVAL(17, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_pc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(41, 0, 0, chartInstance->c1_temporalCounter_i5 >= 3);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NDStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NDDisplayPages = c1_IN_NDRunning;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NDRunning = 1U;
      chartInstance->c1_is_NDRunning = c1_IN_ILSPage;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ILSPage = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_NDMode = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 0, 0);
    chartInstance->c1_is_NDDisplayPages = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
}

static void c1_NDRunning(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 1.0;
  boolean_T c1_j_out;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 1.0;
  boolean_T c1_k_out;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 1.0;
  boolean_T c1_l_out;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 0.0;
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 1.0;
  boolean_T c1_m_out;
  real_T c1_q_nargin = 0.0;
  real_T c1_q_nargout = 1.0;
  boolean_T c1_n_out;
  real_T c1_r_nargin = 0.0;
  real_T c1_r_nargout = 0.0;
  real_T c1_s_nargin = 0.0;
  real_T c1_s_nargout = 1.0;
  boolean_T c1_o_out;
  real_T c1_t_nargin = 0.0;
  real_T c1_t_nargout = 0.0;
  c1_NDPageInput *c1_NDInput;
  real_T *c1_NDMode;
  c1_NDMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_NDInput = (c1_NDPageInput *)ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_jc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(36, 0, 0, *c1_NDInput == NDPageInput_ILS);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[5];
      unsigned int numTransitions = 1;
      transitionList[0] = 36;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_re_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = (*c1_NDInput == NDPageInput_VOR);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 37;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_te_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = (*c1_NDInput == NDPageInput_NAV);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 38;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_se_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = (*c1_NDInput == NDPageInput_ARC);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        transitionList[numTransitions] = 39;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_e_out = (*c1_NDInput == NDPageInput_PLAN);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_e_out) {
        transitionList[numTransitions] = 40;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    c1_exit_internal_NDRunning(chartInstance);
    chartInstance->c1_is_NDRunning = c1_IN_ILSPage;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ILSPage = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *c1_NDMode = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 5U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_lc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_f_out = CV_EML_IF(37, 0, 0, *c1_NDInput == NDPageInput_VOR);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[4];
        unsigned int numTransitions = 1;
        transitionList[0] = 37;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_te_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_g_out = (*c1_NDInput == NDPageInput_NAV);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          transitionList[numTransitions] = 38;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_se_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_h_out = (*c1_NDInput == NDPageInput_ARC);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_h_out) {
          transitionList[numTransitions] = 39;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_i_out = (*c1_NDInput == NDPageInput_PLAN);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_i_out) {
          transitionList[numTransitions] = 40;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
      c1_exit_internal_NDRunning(chartInstance);
      chartInstance->c1_is_NDRunning = c1_IN_VORPage;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_VORPage = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_l_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_NDMode = 2.0;
      c1_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_nc_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_j_out = CV_EML_IF(38, 0, 0, *c1_NDInput == NDPageInput_NAV);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_j_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[3];
          unsigned int numTransitions = 1;
          transitionList[0] = 38;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_se_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_k_out = (*c1_NDInput == NDPageInput_ARC);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_k_out) {
            transitionList[numTransitions] = 39;
            numTransitions++;
          }

          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_l_out = (*c1_NDInput == NDPageInput_PLAN);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_l_out) {
            transitionList[numTransitions] = 40;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
        c1_exit_internal_NDRunning(chartInstance);
        chartInstance->c1_is_NDRunning = c1_IN_NAVPage;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_NAVPage = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_m_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_NDMode = 3.0;
        c1_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_mc_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_m_out = CV_EML_IF(39, 0, 0, *c1_NDInput == NDPageInput_ARC);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_m_out) {
          if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 39;
            _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_out, 2U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_n_out = (*c1_NDInput == NDPageInput_PLAN);
            _SFD_SYMBOL_SCOPE_POP();
            if (c1_n_out) {
              transitionList[numTransitions] = 40;
              numTransitions++;
            }

            _SFD_TRANSITION_CONFLICT_CHECK_END();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
          c1_exit_internal_NDRunning(chartInstance);
          chartInstance->c1_is_NDRunning = c1_IN_ARCPage;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_ARCPage = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_n_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_NDMode = 4.0;
          c1_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_kc_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_s_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_s_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_o_out = CV_EML_IF(40, 0, 0, *c1_NDInput == NDPageInput_PLAN);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_o_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
            c1_exit_internal_NDRunning(chartInstance);
            chartInstance->c1_is_NDRunning = c1_IN_PLANPage;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_PLANPage = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_o_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            *c1_NDMode = 5.0;
            c1_updateDataWrittenToVector(chartInstance, 5U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            switch (chartInstance->c1_is_NDRunning) {
             case c1_IN_ARCPage:
              CV_STATE_EVAL(19, 0, 1);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                           chartInstance->c1_sfEvent);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U,
                           chartInstance->c1_sfEvent);
              break;

             case c1_IN_ILSPage:
              CV_STATE_EVAL(19, 0, 2);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                           chartInstance->c1_sfEvent);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U,
                           chartInstance->c1_sfEvent);
              break;

             case c1_IN_NAVPage:
              CV_STATE_EVAL(19, 0, 3);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                           chartInstance->c1_sfEvent);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U,
                           chartInstance->c1_sfEvent);
              break;

             case c1_IN_PLANPage:
              CV_STATE_EVAL(19, 0, 4);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                           chartInstance->c1_sfEvent);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U,
                           chartInstance->c1_sfEvent);
              break;

             case c1_IN_VORPage:
              CV_STATE_EVAL(19, 0, 5);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                           chartInstance->c1_sfEvent);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U,
                           chartInstance->c1_sfEvent);
              break;

             default:
              CV_STATE_EVAL(19, 0, 0);
              chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
              break;
            }
          }
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_NDRunning(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_NDRunning) {
   case c1_IN_ARCPage:
    CV_STATE_EVAL(19, 1, 1);
    chartInstance->c1_tp_ARCPage = 0U;
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ILSPage:
    CV_STATE_EVAL(19, 1, 2);
    chartInstance->c1_tp_ILSPage = 0U;
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_NAVPage:
    CV_STATE_EVAL(19, 1, 3);
    chartInstance->c1_tp_NAVPage = 0U;
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_PLANPage:
    CV_STATE_EVAL(19, 1, 4);
    chartInstance->c1_tp_PLANPage = 0U;
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_VORPage:
    CV_STATE_EVAL(19, 1, 5);
    chartInstance->c1_tp_VORPage = 0U;
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(19, 1, 0);
    chartInstance->c1_is_NDRunning = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_CSTRDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  c1_NDAdditionalDisplay *c1_ND_AD_OP;
  c1_NDAdditionalDisplay *c1_ND_AD;
  boolean_T guard1 = FALSE;
  c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal(chartInstance->S,
    7);
  c1_ND_AD = (c1_NDAdditionalDisplay *)ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_CSTRDisplay) {
   case c1_IN_OFF:
    CV_STATE_EVAL(11, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 44U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard1 = FALSE;
    if (CV_EML_COND(44, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 0) == 1.0)) {
      if (CV_EML_COND(44, 0, 1, chartInstance->c1_is_NDDisplayPages ==
                      c1_IN_NDRunning)) {
        CV_EML_MCDC(44, 0, 0, TRUE);
        CV_EML_IF(44, 0, 0, TRUE);
        c1_out = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(44, 0, 0, FALSE);
      CV_EML_IF(44, 0, 0, FALSE);
      c1_out = FALSE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
      chartInstance->c1_e_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CSTRDisplay = c1_IN_ON;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ON = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_r_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 0) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ON:
    CV_STATE_EVAL(11, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(45, 0, 0, *(real_T *)((char_T *)c1_ND_AD + 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CSTRDisplay = c1_IN_OFF;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_e_tp_OFF = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_q_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ND_AD_OP + 0) = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 0, 0);
    chartInstance->c1_is_CSTRDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
}

static void c1_EngineDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i3;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T *c1_FlightMode;
  real_T *c1_Engine_Mode;
  real_T (*c1_warn_msgID)[10];
  c1_warnings_bus *c1_outputDisplay;
  c1_EngineDisplayBus *c1_ED;
  c1_EngineFuel_Bus *c1_EnF;
  c1_ED = (c1_EngineDisplayBus *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_EnF = (c1_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_Engine_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_outputDisplay = (c1_warnings_bus *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c1_warn_msgID = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 4);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_db_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  for (c1_i3 = 0; c1_i3 < 10; c1_i3++) {
    ((real_T *)((char_T *)c1_outputDisplay + 24))[c1_i3] = (*c1_warn_msgID)
      [c1_i3];
  }

  c1_updateDataWrittenToVector(chartInstance, 0U);
  *(real_T *)((char_T *)c1_outputDisplay + 0) = *c1_FlightMode;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  *(real_T *)((char_T *)c1_ED + 40) = *(real_T *)((char_T *)c1_EnF + 0);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 48) = *(real_T *)((char_T *)c1_EnF + 0);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 32) = c1_calcFlapConfig(chartInstance,
    *c1_FlightMode);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 16) = *(real_T *)((char_T *)c1_EnF + 32);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 24) = *(real_T *)((char_T *)c1_EnF + 32);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 0) = *(real_T *)((char_T *)c1_EnF + 40);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 8) = *(real_T *)((char_T *)c1_EnF + 48);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  *(real_T *)((char_T *)c1_ED + 72) = *(real_T *)((char_T *)c1_EnF + 56);
  c1_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_SYMBOL_SCOPE_POP();
  switch (chartInstance->c1_is_EngineDisplay) {
   case c1_IN_Engine_Boot:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_cd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_out = CV_EML_IF(21, 0, 0, chartInstance->c1_temporalCounter_i6 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Engine_Boot = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_EngineDisplay = c1_IN_Engine_Ready;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Engine_Ready = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_gb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ED + 56) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_ED + 64) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_outputDisplay + 16) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      *(real_T *)((char_T *)c1_outputDisplay + 8) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ED + 56) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_ED + 64) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_outputDisplay + 16) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      *(real_T *)((char_T *)c1_outputDisplay + 8) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Engine_Off:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_dd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(20, 0, 0, *c1_Engine_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Engine_Off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_EngineDisplay = c1_IN_Engine_Boot;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i6 = 0U;
      chartInstance->c1_tp_Engine_Boot = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ib_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ED + 56) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_ED + 64) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_outputDisplay + 16) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      *(real_T *)((char_T *)c1_outputDisplay + 8) = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Engine_Ready:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_bd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(23, 0, 0, *c1_Engine_Mode == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Engine_Ready = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_EngineDisplay = c1_IN_Engine_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Engine_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_eb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ED + 56) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_ED + 64) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_outputDisplay + 16) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      *(real_T *)((char_T *)c1_outputDisplay + 8) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_hb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *(real_T *)((char_T *)c1_ED + 56) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_ED + 64) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      *(real_T *)((char_T *)c1_outputDisplay + 16) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      *(real_T *)((char_T *)c1_outputDisplay + 8) = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Engine_Running:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *(real_T *)((char_T *)c1_ED + 56) = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    *(real_T *)((char_T *)c1_ED + 64) = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    *(real_T *)((char_T *)c1_outputDisplay + 16) = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    *(real_T *)((char_T *)c1_outputDisplay + 8) = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c1_is_EngineDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void c1_SystemDisplay(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal[7];
  int32_T c1_i4;
  boolean_T c1_x[7];
  boolean_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  boolean_T c1_b0;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  c1_ECAMInput *c1_ECAMDisp;
  real_T *c1_FlightMode;
  real_T *c1_RPMProblem;
  real_T *c1_TempProblem;
  real_T *c1_HydProblem;
  real_T *c1_APUProblem;
  real_T *c1_FuelPProblem;
  real_T *c1_FuelQProblem;
  real_T *c1_CabinPProblem;
  real_T *c1_ECAMMode;
  boolean_T guard1 = FALSE;
  boolean_T exitg1;
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_CabinPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_HydProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_APUProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_FuelQProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_FuelPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_TempProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_RPMProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_ECAMDisp = (c1_ECAMInput *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_SystemDisplay) {
   case c1_IN_NormalFlight:
    CV_STATE_EVAL(49, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ge_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_hoistedGlobal = *c1_RPMProblem;
    c1_b_hoistedGlobal = *c1_TempProblem;
    c1_c_hoistedGlobal = *c1_HydProblem;
    c1_d_hoistedGlobal = *c1_APUProblem;
    c1_e_hoistedGlobal = *c1_FuelPProblem;
    c1_f_hoistedGlobal = *c1_FuelQProblem;
    c1_g_hoistedGlobal = *c1_CabinPProblem;
    c1_h_hoistedGlobal[0] = c1_hoistedGlobal;
    c1_h_hoistedGlobal[1] = c1_b_hoistedGlobal;
    c1_h_hoistedGlobal[2] = c1_c_hoistedGlobal;
    c1_h_hoistedGlobal[3] = c1_d_hoistedGlobal;
    c1_h_hoistedGlobal[4] = c1_e_hoistedGlobal;
    c1_h_hoistedGlobal[5] = c1_f_hoistedGlobal;
    c1_h_hoistedGlobal[6] = c1_g_hoistedGlobal;
    for (c1_i4 = 0; c1_i4 < 7; c1_i4++) {
      c1_x[c1_i4] = (c1_h_hoistedGlobal[c1_i4] != 0.0);
    }

    c1_isequal(chartInstance);
    c1_y = FALSE;
    c1_k = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c1_k < 7)) {
      c1_b_k = 1.0 + (real_T)c1_k;
      if ((real_T)c1_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c1_b_k), 1, 7, 1, 0) - 1] == 0.0) {
        c1_b0 = TRUE;
      } else {
        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_b_k), 1, 7, 1, 0);
        c1_b0 = FALSE;
      }

      if (!c1_b0) {
        c1_y = TRUE;
        exitg1 = TRUE;
      } else {
        c1_k++;
      }
    }

    guard1 = FALSE;
    if (CV_EML_COND(7, 0, 0, c1_y)) {
      guard1 = TRUE;
    } else if (CV_EML_COND(7, 0, 1, (real_T)(int32_T)*c1_ECAMDisp != 0.0)) {
      guard1 = TRUE;
    } else {
      CV_EML_MCDC(7, 0, 0, FALSE);
      CV_EML_IF(7, 0, 0, FALSE);
      c1_out = FALSE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(7, 0, 0, TRUE);
      CV_EML_IF(7, 0, 0, TRUE);
      c1_out = TRUE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      c1_exit_internal_NormalFlight(chartInstance);
      chartInstance->c1_tp_NormalFlight = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_SystemDisplay = c1_IN_UserSelection_Faults;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i8 = 0U;
      chartInstance->c1_tp_UserSelection_Faults = 1U;
      c1_enter_internal_UserSelection_Faults(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 76U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_jd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = CV_EML_IF(76, 0, 0, *c1_FlightMode == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 76;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qf_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_c_out = (*c1_FlightMode == 2.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_c_out) {
            transitionList[numTransitions] = 6;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, chartInstance->c1_sfEvent);
        c1_exit_internal_NormalFlight(chartInstance);
        chartInstance->c1_is_NormalFlight = c1_IN_PushbackAndTaxi;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_PushbackAndTaxi = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_rb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_ECAMMode = 1.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_kd_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_d_out = CV_EML_IF(6, 0, 0, *c1_FlightMode == 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
          c1_exit_internal_NormalFlight(chartInstance);
          chartInstance->c1_is_NormalFlight = c1_IN_TakeoffCruiseDescent;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_TakeoffCruiseDescent = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_sb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_ECAMMode = 2.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
          c1_exit_internal_NormalFlight(chartInstance);
          chartInstance->c1_is_NormalFlight = c1_IN_Land;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_Land = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_tb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_ECAMMode = 3.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Startup:
    CV_STATE_EVAL(49, 0, 2);
    c1_Startup(chartInstance);
    break;

   case c1_IN_UserSelection_Faults:
    CV_STATE_EVAL(49, 0, 3);
    c1_UserSelection_Faults(chartInstance);
    break;

   default:
    CV_STATE_EVAL(49, 0, 0);
    chartInstance->c1_is_SystemDisplay = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, chartInstance->c1_sfEvent);
}

static void c1_Startup(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 1.0;
  boolean_T c1_f_out;
  real_T *c1_ECAMMode;
  real_T *c1_APU_Mode;
  real_T *c1_Engine_Mode;
  real_T *c1_FlightMode;
  boolean_T guard1 = FALSE;
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Engine_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_APU_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U, chartInstance->c1_sfEvent);
  guard1 = FALSE;
  switch (chartInstance->c1_is_Startup) {
   case c1_IN_APU_Boot:
    CV_STATE_EVAL(54, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_out = CV_EML_IF(18, 0, 0, chartInstance->c1_temporalCounter_i7 >= 2);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Boot = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Startup = c1_IN_APU_Ready;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Ready = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_mb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 8.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;

   case c1_IN_APU_Off:
    CV_STATE_EVAL(54, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ed_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(17, 0, 0, *c1_APU_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Startup = c1_IN_APU_Boot;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i7 = 0U;
      chartInstance->c1_tp_APU_Boot = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ob_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;

   case c1_IN_APU_Ready:
    CV_STATE_EVAL(54, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_gd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(16, 0, 0, *c1_APU_Mode == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Ready = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Startup = c1_IN_APU_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i7 = 0U;
      chartInstance->c1_tp_APU_Running = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_nb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 8.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;

   case c1_IN_APU_Running:
    CV_STATE_EVAL(54, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_id_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_d_out = CV_EML_IF(19, 0, 0, chartInstance->c1_temporalCounter_i7 >= 3);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Running = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Startup = c1_IN_APU_Wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Wait = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_pb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 11.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;

   case c1_IN_APU_Wait:
    CV_STATE_EVAL(54, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 78U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_hd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_e_out = CV_EML_IF(78, 0, 0, *c1_Engine_Mode == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_APU_Wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Startup = c1_IN_EngineStarting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_EngineStarting = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_qb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 4.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;

   case c1_IN_EngineStarting:
    CV_STATE_EVAL(54, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 81U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ee_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_f_out = CV_EML_IF(81, 0, 0, *c1_FlightMode > 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_EngineStarting = 0U;
      chartInstance->c1_is_Startup = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Startup = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_SystemDisplay = c1_IN_NormalFlight;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NormalFlight = 1U;
      c1_enter_internal_NormalFlight(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_SystemDisplay != c1_IN_Startup) {
    } else {
      guard1 = TRUE;
    }
    break;

   default:
    CV_STATE_EVAL(54, 0, 0);
    chartInstance->c1_is_Startup = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
    guard1 = TRUE;
    break;
  }

  if (guard1 == TRUE) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, chartInstance->c1_sfEvent);
  }
}

static void c1_enter_internal_NormalFlight(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T *c1_FlightMode;
  real_T *c1_ECAMMode;
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 76U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_jd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(76, 0, 0, *c1_FlightMode == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 76;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qf_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = (*c1_FlightMode == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 6;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_NormalFlight = c1_IN_PushbackAndTaxi;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_PushbackAndTaxi = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_rb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *c1_ECAMMode = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_kd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(6, 0, 0, *c1_FlightMode == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NormalFlight = c1_IN_TakeoffCruiseDescent;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_TakeoffCruiseDescent = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_sb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 2.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NormalFlight = c1_IN_Land;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Land = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_tb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 3.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    }
  }
}

static void c1_exit_internal_NormalFlight(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_NormalFlight) {
   case c1_IN_Land:
    CV_STATE_EVAL(50, 0, 1);
    chartInstance->c1_tp_Land = 0U;
    chartInstance->c1_is_NormalFlight = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_PushbackAndTaxi:
    CV_STATE_EVAL(50, 0, 2);
    chartInstance->c1_tp_PushbackAndTaxi = 0U;
    chartInstance->c1_is_NormalFlight = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_TakeoffCruiseDescent:
    CV_STATE_EVAL(50, 0, 3);
    chartInstance->c1_tp_TakeoffCruiseDescent = 0U;
    chartInstance->c1_is_NormalFlight = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(50, 0, 0);
    chartInstance->c1_is_NormalFlight = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_enter_internal_UserSelection_Faults
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 0.0;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 0.0;
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_q_nargin = 0.0;
  real_T c1_q_nargout = 0.0;
  real_T c1_r_nargin = 0.0;
  real_T c1_r_nargout = 1.0;
  boolean_T c1_j_out;
  real_T c1_s_nargin = 0.0;
  real_T c1_s_nargout = 0.0;
  real_T c1_t_nargin = 0.0;
  real_T c1_t_nargout = 1.0;
  boolean_T c1_k_out;
  real_T c1_u_nargin = 0.0;
  real_T c1_u_nargout = 0.0;
  real_T c1_v_nargin = 0.0;
  real_T c1_v_nargout = 1.0;
  boolean_T c1_l_out;
  real_T c1_w_nargin = 0.0;
  real_T c1_w_nargout = 0.0;
  c1_ECAMInput *c1_ECAMDisp;
  real_T *c1_RPMProblem;
  real_T *c1_TempProblem;
  real_T *c1_CabinPProblem;
  real_T *c1_HydProblem;
  real_T *c1_FuelPProblem;
  real_T *c1_FuelQProblem;
  real_T *c1_APUProblem;
  real_T *c1_ECAMMode;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_CabinPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_HydProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_APUProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_FuelQProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_FuelPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_TempProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_RPMProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_ECAMDisp = (c1_ECAMInput *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 90U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 84U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ld_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(84, 0, 0, (real_T)(int32_T)*c1_ECAMDisp != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = FALSE;
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 84U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 95U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 88U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_md_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(88, 0, 0, *c1_ECAMDisp == ECAMInput_ENG);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 88U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_UserSelection_Faults = c1_IN_Engine;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i7 = 0U;
      chartInstance->c1_tp_Engine = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ub_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 4.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_pd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = CV_EML_IF(3, 0, 0, *c1_ECAMDisp == ECAMInput_PRESS);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_UserSelection_Faults = c1_IN_Cabin_Pressure;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i7 = 0U;
        chartInstance->c1_tp_Cabin_Pressure = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_vb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_ECAMMode = 10.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 86U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 89U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_td_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_d_out = CV_EML_IF(89, 0, 0, *c1_ECAMDisp == ECAMInput_HYD);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 89U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_UserSelection_Faults = c1_IN_HYD;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i7 = 0U;
          chartInstance->c1_tp_HYD = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_wb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_ECAMMode = 7.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 87U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 91U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wd_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_e_out = CV_EML_IF(91, 0, 0, *c1_ECAMDisp == ECAMInput_FUEL);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 91U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_UserSelection_Faults = c1_IN_FUEL;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
            chartInstance->c1_temporalCounter_i7 = 0U;
            chartInstance->c1_tp_FUEL = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_xb_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            *c1_ECAMMode = 9.0;
            c1_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 92U,
                         chartInstance->c1_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ae_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_f_out = CV_EML_IF(92, 0, 0, *c1_ECAMDisp == ECAMInput_APU);
            _SFD_SYMBOL_SCOPE_POP();
            if (c1_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 92U, chartInstance->c1_sfEvent);
              chartInstance->c1_is_UserSelection_Faults = c1_IN_APU;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
              chartInstance->c1_temporalCounter_i7 = 0U;
              chartInstance->c1_tp_APU = 1U;
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yb_debug_family_names,
                c1_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              *c1_ECAMMode = 8.0;
              c1_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_SYMBOL_SCOPE_POP();
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 85U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U,
                           chartInstance->c1_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ce_debug_family_names,
                c1_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U,
                c1_b_sf_marshallOut, c1_b_sf_marshallIn);
              c1_g_out = CV_EML_IF(93, 0, 0, *c1_ECAMDisp == ECAMInput_BLEED);
              _SFD_SYMBOL_SCOPE_POP();
              if (c1_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U,
                             chartInstance->c1_sfEvent);
                chartInstance->c1_is_UserSelection_Faults = c1_IN_Bleed;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
                chartInstance->c1_temporalCounter_i7 = 0U;
                chartInstance->c1_tp_Bleed = 1U;
                _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ac_debug_family_names,
                  c1_b_debug_family_var_map);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U,
                  c1_sf_marshallOut, c1_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U,
                  c1_sf_marshallOut, c1_sf_marshallIn);
                *c1_ECAMMode = 5.0;
                c1_updateDataWrittenToVector(chartInstance, 1U);
                _SFD_SYMBOL_SCOPE_POP();
              } else {
                guard1 = TRUE;
              }
            }
          }
        }
      }
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_nd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard3 = FALSE;
    if (CV_EML_COND(1, 0, 0, *c1_RPMProblem > 0.0)) {
      guard3 = TRUE;
    } else if (CV_EML_COND(1, 0, 1, *c1_TempProblem > 0.0)) {
      guard3 = TRUE;
    } else {
      CV_EML_MCDC(1, 0, 0, FALSE);
      CV_EML_IF(1, 0, 0, FALSE);
      c1_h_out = FALSE;
    }

    if (guard3 == TRUE) {
      CV_EML_MCDC(1, 0, 0, TRUE);
      CV_EML_IF(1, 0, 0, TRUE);
      c1_h_out = TRUE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_h_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_UserSelection_Faults = c1_IN_Engine;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i7 = 0U;
      chartInstance->c1_tp_Engine = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ub_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_ECAMMode = 4.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 97U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_i_out = CV_EML_IF(97, 0, 0, *c1_CabinPProblem > 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_i_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 97U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_UserSelection_Faults = c1_IN_Cabin_Pressure;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i7 = 0U;
        chartInstance->c1_tp_Cabin_Pressure = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_vb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_ECAMMode = 10.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 96U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_sd_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_j_out = CV_EML_IF(0, 0, 0, *c1_HydProblem > 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_j_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_UserSelection_Faults = c1_IN_HYD;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i7 = 0U;
          chartInstance->c1_tp_HYD = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_wb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_s_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_s_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_ECAMMode = 7.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vd_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          guard2 = FALSE;
          if (CV_EML_COND(2, 0, 0, *c1_FuelPProblem > 0.0)) {
            guard2 = TRUE;
          } else if (CV_EML_COND(2, 0, 1, *c1_FuelQProblem > 0.0)) {
            guard2 = TRUE;
          } else {
            CV_EML_MCDC(2, 0, 0, FALSE);
            CV_EML_IF(2, 0, 0, FALSE);
            c1_k_out = FALSE;
          }

          if (guard2 == TRUE) {
            CV_EML_MCDC(2, 0, 0, TRUE);
            CV_EML_IF(2, 0, 0, TRUE);
            c1_k_out = TRUE;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c1_k_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_UserSelection_Faults = c1_IN_FUEL;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
            chartInstance->c1_temporalCounter_i7 = 0U;
            chartInstance->c1_tp_FUEL = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_xb_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_u_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_u_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            *c1_ECAMMode = 9.0;
            c1_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                         chartInstance->c1_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_yd_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_v_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_v_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_out, 2U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_l_out = CV_EML_IF(5, 0, 0, *c1_APUProblem > 0.0);
            _SFD_SYMBOL_SCOPE_POP();
            if (c1_l_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
              chartInstance->c1_is_UserSelection_Faults = c1_IN_APU;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
              chartInstance->c1_temporalCounter_i7 = 0U;
              chartInstance->c1_tp_APU = 1U;
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yb_debug_family_names,
                c1_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_w_nargin, 0U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_w_nargout, 1U,
                c1_sf_marshallOut, c1_sf_marshallIn);
              *c1_ECAMMode = 8.0;
              c1_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_SYMBOL_SCOPE_POP();
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, chartInstance->c1_sfEvent);
              chartInstance->c1_is_UserSelection_Faults = c1_IN_ERROR;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_ERROR = 1U;
            }
          }
        }
      }
    }
  }
}

static void c1_UserSelection_Faults(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal[7];
  int32_T c1_i5;
  boolean_T c1_x[7];
  boolean_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_g_out;
  c1_ECAMInput *c1_ECAMDisp;
  real_T *c1_RPMProblem;
  real_T *c1_TempProblem;
  real_T *c1_HydProblem;
  real_T *c1_APUProblem;
  real_T *c1_FuelPProblem;
  real_T *c1_FuelQProblem;
  real_T *c1_CabinPProblem;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T exitg1;
  c1_CabinPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_HydProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_APUProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_FuelQProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_FuelPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_TempProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_RPMProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_ECAMDisp = (c1_ECAMInput *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fe_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  guard1 = FALSE;
  guard2 = FALSE;
  if (CV_EML_COND(11, 0, 0, chartInstance->c1_temporalCounter_i8 >= 1)) {
    c1_hoistedGlobal = *c1_RPMProblem;
    c1_b_hoistedGlobal = *c1_TempProblem;
    c1_c_hoistedGlobal = *c1_HydProblem;
    c1_d_hoistedGlobal = *c1_APUProblem;
    c1_e_hoistedGlobal = *c1_FuelPProblem;
    c1_f_hoistedGlobal = *c1_FuelQProblem;
    c1_g_hoistedGlobal = *c1_CabinPProblem;
    c1_h_hoistedGlobal[0] = c1_hoistedGlobal;
    c1_h_hoistedGlobal[1] = c1_b_hoistedGlobal;
    c1_h_hoistedGlobal[2] = c1_c_hoistedGlobal;
    c1_h_hoistedGlobal[3] = c1_d_hoistedGlobal;
    c1_h_hoistedGlobal[4] = c1_e_hoistedGlobal;
    c1_h_hoistedGlobal[5] = c1_f_hoistedGlobal;
    c1_h_hoistedGlobal[6] = c1_g_hoistedGlobal;
    for (c1_i5 = 0; c1_i5 < 7; c1_i5++) {
      c1_x[c1_i5] = (c1_h_hoistedGlobal[c1_i5] == 0.0);
    }

    c1_isequal(chartInstance);
    c1_y = TRUE;
    c1_k = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c1_k < 7)) {
      c1_b_k = 1.0 + (real_T)c1_k;
      if ((real_T)c1_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c1_b_k), 1, 7, 1, 0) - 1] == 0.0) {
        c1_y = FALSE;
        exitg1 = TRUE;
      } else {
        c1_k++;
      }
    }

    if (CV_EML_COND(11, 0, 1, c1_y)) {
      if (CV_EML_COND(11, 0, 2, (real_T)(int32_T)*c1_ECAMDisp == 0.0)) {
        CV_EML_MCDC(11, 0, 0, TRUE);
        CV_EML_IF(11, 0, 0, TRUE);
        c1_out = TRUE;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(11, 0, 0, FALSE);
    CV_EML_IF(11, 0, 0, FALSE);
    c1_out = FALSE;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    c1_exit_internal_UserSelection_Faults(chartInstance);
    chartInstance->c1_tp_UserSelection_Faults = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_SystemDisplay = c1_IN_NormalFlight;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_NormalFlight = 1U;
    c1_enter_internal_NormalFlight(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_UserSelection_Faults) {
     case c1_IN_APU:
      CV_STATE_EVAL(61, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 74U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_be_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = CV_EML_IF(74, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_APU = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Bleed:
      CV_STATE_EVAL(61, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 75U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_de_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = CV_EML_IF(75, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Bleed = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Cabin_Pressure:
      CV_STATE_EVAL(61, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = CV_EML_IF(72, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Cabin_Pressure = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_ERROR:
      CV_STATE_EVAL(61, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Engine:
      CV_STATE_EVAL(61, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 73U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_od_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_e_out = CV_EML_IF(73, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Engine = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_FUEL:
      CV_STATE_EVAL(61, 0, 6);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_f_out = CV_EML_IF(70, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_FUEL = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_HYD:
      CV_STATE_EVAL(61, 0, 7);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 71U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ud_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_g_out = CV_EML_IF(71, 0, 0, chartInstance->c1_temporalCounter_i7 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_HYD = 0U;
        chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
        c1_enter_internal_UserSelection_Faults(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(61, 0, 0);
      chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_UserSelection_Faults
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
  switch (chartInstance->c1_is_UserSelection_Faults) {
   case c1_IN_APU:
    CV_STATE_EVAL(61, 1, 1);
    chartInstance->c1_tp_APU = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Bleed:
    CV_STATE_EVAL(61, 1, 2);
    chartInstance->c1_tp_Bleed = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Cabin_Pressure:
    CV_STATE_EVAL(61, 1, 3);
    chartInstance->c1_tp_Cabin_Pressure = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_ERROR:
    CV_STATE_EVAL(61, 1, 4);
    chartInstance->c1_tp_ERROR = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Engine:
    CV_STATE_EVAL(61, 1, 5);
    chartInstance->c1_tp_Engine = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_FUEL:
    CV_STATE_EVAL(61, 1, 6);
    chartInstance->c1_tp_FUEL = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_HYD:
    CV_STATE_EVAL(61, 1, 7);
    chartInstance->c1_tp_HYD = 0U;
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(61, 1, 0);
    chartInstance->c1_is_UserSelection_Faults = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_isequal(SFc1_CockpitDisplayLibInstanceStruct *chartInstance)
{
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
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
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
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b1, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_guard1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_guard1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_guard1), &c1_thisId);
  sf_mex_destroy(&c1_guard1);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_CockpitDisplayLib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 16, 1),
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("EFIS_Pressure"), "name",
                  "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[N]C:/Mathworks/WSpace/Demo/MBD_CockpitDisplay_13b/data/EFIS_Pressure.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1384502590U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mtimes"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("NDPageInput"), "name", "name",
                  3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[N]C:/Mathworks/WSpace/Demo/MBD_CockpitDisplay_13b/data/NDPageInput.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1384502590U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("ECAMInput"), "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[N]C:/Mathworks/WSpace/Demo/MBD_CockpitDisplay_13b/data/ECAMInput.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1384502590U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("all"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688676U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_all_or_any"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797094U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isequal"), "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797096U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("any"), "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688676U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_all_or_any"), "name",
                  "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797094U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688658U), "fileTimeLo",
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
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

static real_T c1_calcFlapConfig(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, real_T c1_flightphase)
{
  real_T c1_out;
  uint32_T c1_debug_family_var_map[5];
  boolean_T c1_guard1;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_evilsf_internal_predicateOutput;
  boolean_T c1_b_evilsf_internal_predicateOutput;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_cb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_guard1, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_flightphase, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  c1_guard1 = FALSE;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, chartInstance->c1_sfEvent);
  c1_evilsf_internal_predicateOutput = CV_EML_IF(26, 0, 0, c1_flightphase == 1.0);
  if (c1_evilsf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    c1_out = 1.0;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    c1_guard1 = TRUE;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c1_sfEvent);
    c1_b_evilsf_internal_predicateOutput = CV_EML_IF(28, 0, 0, c1_flightphase ==
      2.0);
    if (c1_b_evilsf_internal_predicateOutput) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
      c1_out = 2.0;
      c1_guard1 = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
      c1_out = 3.0;
    }
  }

  if (c1_guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  return c1_out;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i6;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i6, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i6;
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
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
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
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_PrimaryFlightDisplay, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_tp_PrimaryFlightDisplay), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_PrimaryFlightDisplay);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
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
  const mxArray *c1_b_tp_PrimaryFlightDisplay;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_b_tp_PrimaryFlightDisplay = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_tp_PrimaryFlightDisplay), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_PrimaryFlightDisplay);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_ECAMInput c1_u;
  const mxArray *c1_y = NULL;
  static const int32_T c1_enumValues[7] = { 0, 1, 2, 3, 4, 5, 6 };

  static const char * c1_enumNames[7] = { "None", "ENG", "BLEED", "PRESS", "HYD",
    "FUEL", "APU" };

  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_m0 = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_ECAMInput *)c1_inData;
  c1_y = NULL;
  sf_mex_check_enum("ECAMInput", 7, c1_enumNames, c1_enumValues);
  c1_b_u = (int32_T)c1_u;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_m0, c1_b_y, FALSE);
  sf_mex_assign(&c1_y, sf_mex_create_enum("ECAMInput", c1_m0), FALSE);
  sf_mex_destroy(&c1_m0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_EFIS_Pressure c1_u;
  const mxArray *c1_y = NULL;
  static const int32_T c1_enumValues[2] = { 0, 1 };

  static const char * c1_enumNames[2] = { "inHg", "mmHg" };

  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_m1 = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_EFIS_Pressure *)c1_inData;
  c1_y = NULL;
  sf_mex_check_enum("EFIS_Pressure", 2, c1_enumNames, c1_enumValues);
  c1_b_u = (int32_T)c1_u;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_m1, c1_b_y, FALSE);
  sf_mex_assign(&c1_y, sf_mex_create_enum("EFIS_Pressure", c1_m1), FALSE);
  sf_mex_destroy(&c1_m1);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_NDPageInput c1_u;
  const mxArray *c1_y = NULL;
  static const int32_T c1_enumValues[5] = { 0, 1, 2, 3, 4 };

  static const char * c1_enumNames[5] = { "ILS", "VOR", "NAV", "ARC", "PLAN" };

  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_m2 = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_NDPageInput *)c1_inData;
  c1_y = NULL;
  sf_mex_check_enum("NDPageInput", 5, c1_enumNames, c1_enumValues);
  c1_b_u = (int32_T)c1_u;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_m2, c1_b_y, FALSE);
  sf_mex_assign(&c1_y, sf_mex_create_enum("NDPageInput", c1_m2), FALSE);
  sf_mex_destroy(&c1_m2);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ND_AD_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_NDAdditionalDisplay c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.CSTR = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.WPT = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.VORD = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.NDB = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.ARPT = *(real_T *)((char_T *)c1_pData + 32);
  sf_mex_assign(&c1_mxVal, c1_h_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_NDAdditionalDisplay c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_NDAdditionalDisplay *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.CSTR;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "CSTR", "CSTR", 0);
  c1_c_u = c1_u.WPT;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "WPT", "WPT", 0);
  c1_d_u = c1_u.VORD;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "VORD", "VORD", 0);
  c1_e_u = c1_u.NDB;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "NDB", "NDB", 0);
  c1_f_u = c1_u.ARPT;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "ARPT", "ARPT", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i7;
  real_T c1_b_inData[10];
  int32_T c1_i8;
  real_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i7 = 0; c1_i7 < 10; c1_i7++) {
    c1_b_inData[c1_i7] = (*(real_T (*)[10])c1_inData)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 10; c1_i8++) {
    c1_u[c1_i8] = c1_b_inData[c1_i8];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 10, 1), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_outputDisplay_bus_io(void *chartInstanceVoid, void
  *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_warnings_bus c1_tmp;
  int32_T c1_i9;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.flightmode = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.ED_Mode_R = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.ED_Mode_L = *(real_T *)((char_T *)c1_pData + 16);
  for (c1_i9 = 0; c1_i9 < 10; c1_i9++) {
    c1_tmp.warn_msgID[c1_i9] = ((real_T *)((char_T *)c1_pData + 24))[c1_i9];
  }

  sf_mex_assign(&c1_mxVal, c1_j_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_warnings_bus c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i10;
  real_T c1_e_u[10];
  const mxArray *c1_e_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_warnings_bus *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.flightmode;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "flightmode", "flightmode", 0);
  c1_c_u = c1_u.ED_Mode_R;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "ED_Mode_R", "ED_Mode_R", 0);
  c1_d_u = c1_u.ED_Mode_L;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "ED_Mode_L", "ED_Mode_L", 0);
  for (c1_i10 = 0; c1_i10 < 10; c1_i10++) {
    c1_e_u[c1_i10] = c1_u.warn_msgID[c1_i10];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 2, 10, 1),
                FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "warn_msgID", "warn_msgID", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_outputDisplay, const char_T *c1_identifier,
  c1_warnings_bus *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_outputDisplay), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_outputDisplay);
}

static void c1_h_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_warnings_bus *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "flightmode", "ED_Mode_R",
    "ED_Mode_L", "warn_msgID" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 4, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "flightmode";
  c1_y->flightmode = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "flightmode", "flightmode", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ED_Mode_R";
  c1_y->ED_Mode_R = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "ED_Mode_R", "ED_Mode_R", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ED_Mode_L";
  c1_y->ED_Mode_L = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "ED_Mode_L", "ED_Mode_L", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "warn_msgID";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "warn_msgID", "warn_msgID", 0)), &c1_thisId, c1_y->warn_msgID);
  sf_mex_destroy(&c1_u);
}

static void c1_i_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10])
{
  real_T c1_dv0[10];
  int32_T c1_i11;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 10, 1);
  for (c1_i11 = 0; c1_i11 < 10; c1_i11++) {
    c1_y[c1_i11] = c1_dv0[c1_i11];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_outputDisplay;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_warnings_bus c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_outputDisplay = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_outputDisplay), &c1_thisId,
                        &c1_y);
  sf_mex_destroy(&c1_outputDisplay);
  *(c1_warnings_bus *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_PFD_Input_bus_io(void *chartInstanceVoid, void
  *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_FlightInputs c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.Direction = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.VerticalSpeed = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.AirSpeed = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.Altitude = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.RateOfTurn = *(real_T *)((char_T *)c1_pData + 32);
  c1_tmp.Attitude = *(real_T *)((char_T *)c1_pData + 40);
  sf_mex_assign(&c1_mxVal, c1_k_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_FlightInputs c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_FlightInputs *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.Direction;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "Direction", "Direction", 0);
  c1_c_u = c1_u.VerticalSpeed;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "VerticalSpeed", "VerticalSpeed", 0);
  c1_d_u = c1_u.AirSpeed;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "AirSpeed", "AirSpeed", 0);
  c1_e_u = c1_u.Altitude;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "Altitude", "Altitude", 0);
  c1_f_u = c1_u.RateOfTurn;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "RateOfTurn", "RateOfTurn", 0);
  c1_g_u = c1_u.Attitude;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_g_y, "Attitude", "Attitude", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_Nav_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_NavData c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.bearing = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.distance = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.groundspeed = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.selectedheading = *(real_T *)((char_T *)c1_pData + 24);
  sf_mex_assign(&c1_mxVal, c1_l_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_NavData c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_NavData *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.bearing;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "bearing", "bearing", 0);
  c1_c_u = c1_u.distance;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "distance", "distance", 0);
  c1_d_u = c1_u.groundspeed;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "groundspeed", "groundspeed", 0);
  c1_e_u = c1_u.selectedheading;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "selectedheading", "selectedheading", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_FCU_Display_bus_io(void *chartInstanceVoid, void
  *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_FCU_Output c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.Speed = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.Heading = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.Altitude = *(real_T *)((char_T *)c1_pData + 16);
  sf_mex_assign(&c1_mxVal, c1_m_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_FCU_Output c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_FCU_Output *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.Speed;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "Speed", "Speed", 0);
  c1_c_u = c1_u.Heading;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "Heading", "Heading", 0);
  c1_d_u = c1_u.Altitude;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "Altitude", "Altitude", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static c1_FCU_Output c1_j_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance, const mxArray *c1_FCU_Display, const char_T *c1_identifier)
{
  c1_FCU_Output c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_FCU_Display),
    &c1_thisId);
  sf_mex_destroy(&c1_FCU_Display);
  return c1_y;
}

static c1_FCU_Output c1_k_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_FCU_Output c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[3] = { "Speed", "Heading", "Altitude" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 3, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "Speed";
  c1_y.Speed = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Speed", "Speed", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Heading";
  c1_y.Heading = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "Heading", "Heading", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "Altitude";
  c1_y.Altitude = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "Altitude", "Altitude", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_FCU_Display;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_FCU_Output c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_FCU_Display = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_FCU_Display),
    &c1_thisId);
  sf_mex_destroy(&c1_FCU_Display);
  *(c1_FCU_Output *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_EnF_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_EngineFuel_Bus c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.RPM = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.temperature = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.fuelpressure = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.oilpressure = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.EGT = *(real_T *)((char_T *)c1_pData + 32);
  c1_tmp.EPR1 = *(real_T *)((char_T *)c1_pData + 40);
  c1_tmp.EPR2 = *(real_T *)((char_T *)c1_pData + 48);
  c1_tmp.FuelQuantity = *(real_T *)((char_T *)c1_pData + 56);
  sf_mex_assign(&c1_mxVal, c1_n_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_EngineFuel_Bus c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_EngineFuel_Bus *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.RPM;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "RPM", "RPM", 0);
  c1_c_u = c1_u.temperature;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "temperature", "temperature", 0);
  c1_d_u = c1_u.fuelpressure;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "fuelpressure", "fuelpressure", 0);
  c1_e_u = c1_u.oilpressure;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "oilpressure", "oilpressure", 0);
  c1_f_u = c1_u.EGT;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "EGT", "EGT", 0);
  c1_g_u = c1_u.EPR1;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_g_y, "EPR1", "EPR1", 0);
  c1_h_u = c1_u.EPR2;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_h_y, "EPR2", "EPR2", 0);
  c1_i_u = c1_u.FuelQuantity;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_i_y, "FuelQuantity", "FuelQuantity", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_Misc_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_MiscData c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.FlapPosition = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.CabinPressure = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.HydraulicPressure = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.APUData = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.LGLeftLock = *(boolean_T *)((char_T *)c1_pData + 32);
  c1_tmp.LGRightLock = *(boolean_T *)((char_T *)c1_pData + 33);
  sf_mex_assign(&c1_mxVal, c1_o_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_MiscData c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  boolean_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  boolean_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_MiscData *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.FlapPosition;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "FlapPosition", "FlapPosition", 0);
  c1_c_u = c1_u.CabinPressure;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "CabinPressure", "CabinPressure", 0);
  c1_d_u = c1_u.HydraulicPressure;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "HydraulicPressure", "HydraulicPressure", 0);
  c1_e_u = c1_u.APUData;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "APUData", "APUData", 0);
  c1_f_u = c1_u.LGLeftLock;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "LGLeftLock", "LGLeftLock", 0);
  c1_g_u = c1_u.LGRightLock;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_g_y, "LGRightLock", "LGRightLock", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ED_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_EngineDisplayBus c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.EPR1 = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.EPR2 = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.EGT1 = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.EGT2 = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.FlapConfig = *(real_T *)((char_T *)c1_pData + 32);
  c1_tmp.N1_L = *(real_T *)((char_T *)c1_pData + 40);
  c1_tmp.N1_R = *(real_T *)((char_T *)c1_pData + 48);
  c1_tmp.ED_Mode_L = *(real_T *)((char_T *)c1_pData + 56);
  c1_tmp.ED_Mode_R = *(real_T *)((char_T *)c1_pData + 64);
  c1_tmp.FuelQuantity = *(real_T *)((char_T *)c1_pData + 72);
  sf_mex_assign(&c1_mxVal, c1_p_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, c1_EngineDisplayBus
   *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u->EPR1;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "EPR1", "EPR1", 0);
  c1_c_u = c1_u->EPR2;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "EPR2", "EPR2", 0);
  c1_d_u = c1_u->EGT1;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "EGT1", "EGT1", 0);
  c1_e_u = c1_u->EGT2;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "EGT2", "EGT2", 0);
  c1_f_u = c1_u->FlapConfig;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "FlapConfig", "FlapConfig", 0);
  c1_g_u = c1_u->N1_L;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_g_y, "N1_L", "N1_L", 0);
  c1_h_u = c1_u->N1_R;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_h_y, "N1_R", "N1_R", 0);
  c1_i_u = c1_u->ED_Mode_L;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_i_y, "ED_Mode_L", "ED_Mode_L", 0);
  c1_j_u = c1_u->ED_Mode_R;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_j_y, "ED_Mode_R", "ED_Mode_R", 0);
  c1_k_u = c1_u->FuelQuantity;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_k_y, "FuelQuantity", "FuelQuantity", 0);
  return c1_y;
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_EngineDisplayBus c1_b_inData;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData = *(c1_EngineDisplayBus *)c1_inData;
  sf_mex_assign(&c1_mxArrayOutData, c1_c_emlrt_marshallOut(chartInstance,
    &c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static void c1_l_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_ED, const char_T *c1_identifier,
  c1_EngineDisplayBus *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ED), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_ED);
}

static void c1_m_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_EngineDisplayBus *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[10] = { "EPR1", "EPR2", "EGT1", "EGT2",
    "FlapConfig", "N1_L", "N1_R", "ED_Mode_L", "ED_Mode_R", "FuelQuantity" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 10, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "EPR1";
  c1_y->EPR1 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "EPR1", "EPR1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "EPR2";
  c1_y->EPR2 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "EPR2", "EPR2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "EGT1";
  c1_y->EGT1 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "EGT1", "EGT1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "EGT2";
  c1_y->EGT2 = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "EGT2", "EGT2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "FlapConfig";
  c1_y->FlapConfig = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "FlapConfig", "FlapConfig", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "N1_L";
  c1_y->N1_L = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "N1_L", "N1_L", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "N1_R";
  c1_y->N1_R = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "N1_R", "N1_R", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ED_Mode_L";
  c1_y->ED_Mode_L = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "ED_Mode_L", "ED_Mode_L", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ED_Mode_R";
  c1_y->ED_Mode_R = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "ED_Mode_R", "ED_Mode_R", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "FuelQuantity";
  c1_y->FuelQuantity = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "FuelQuantity", "FuelQuantity", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ED;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_EngineDisplayBus c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_ED = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ED), &c1_thisId, &c1_y);
  sf_mex_destroy(&c1_ED);
  *(c1_EngineDisplayBus *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_PFD_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_PFDOutput c1_tmp;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.Altitude = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.Heading = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.Attitude = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.AirSpeed = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.AltMode = *(real_T *)((char_T *)c1_pData + 32);
  c1_tmp.AirSpeedMode = *(real_T *)((char_T *)c1_pData + 40);
  c1_tmp.AttMode = *(real_T *)((char_T *)c1_pData + 48);
  c1_tmp.HeadingMode = *(real_T *)((char_T *)c1_pData + 56);
  sf_mex_assign(&c1_mxVal, c1_q_sf_marshallOut(chartInstance, &c1_tmp), FALSE);
  return c1_mxVal;
}

static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_PFDOutput c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_PFDOutput *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.Altitude;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "Altitude", "Altitude", 0);
  c1_c_u = c1_u.Heading;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "Heading", "Heading", 0);
  c1_d_u = c1_u.Attitude;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_d_y, "Attitude", "Attitude", 0);
  c1_e_u = c1_u.AirSpeed;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_e_y, "AirSpeed", "AirSpeed", 0);
  c1_f_u = c1_u.AltMode;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_f_y, "AltMode", "AltMode", 0);
  c1_g_u = c1_u.AirSpeedMode;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_g_y, "AirSpeedMode", "AirSpeedMode", 0);
  c1_h_u = c1_u.AttMode;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_h_y, "AttMode", "AttMode", 0);
  c1_i_u = c1_u.HeadingMode;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_i_y, "HeadingMode", "HeadingMode", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static c1_PFDOutput c1_n_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_PFD, const char_T *c1_identifier)
{
  c1_PFDOutput c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_PFD), &c1_thisId);
  sf_mex_destroy(&c1_PFD);
  return c1_y;
}

static c1_PFDOutput c1_o_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_PFDOutput c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[8] = { "Altitude", "Heading", "Attitude",
    "AirSpeed", "AltMode", "AirSpeedMode", "AttMode", "HeadingMode" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 8, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "Altitude";
  c1_y.Altitude = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "Altitude", "Altitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Heading";
  c1_y.Heading = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "Heading", "Heading", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "Attitude";
  c1_y.Attitude = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "Attitude", "Attitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "AirSpeed";
  c1_y.AirSpeed = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "AirSpeed", "AirSpeed", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "AltMode";
  c1_y.AltMode = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "AltMode", "AltMode", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "AirSpeedMode";
  c1_y.AirSpeedMode = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "AirSpeedMode", "AirSpeedMode", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "AttMode";
  c1_y.AttMode = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_u, "AttMode", "AttMode", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "HeadingMode";
  c1_y.HeadingMode = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "HeadingMode", "HeadingMode", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_PFD;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PFDOutput c1_y;
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)chartInstanceVoid;
  c1_PFD = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_PFD), &c1_thisId);
  sf_mex_destroy(&c1_PFD);
  *(c1_PFDOutput *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static c1_NDAdditionalDisplay c1_p_emlrt_marshallIn
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray
   *c1_ND_AD_OP, const char_T *c1_identifier)
{
  c1_NDAdditionalDisplay c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ND_AD_OP),
    &c1_thisId);
  sf_mex_destroy(&c1_ND_AD_OP);
  return c1_y;
}

static c1_NDAdditionalDisplay c1_q_emlrt_marshallIn
  (SFc1_CockpitDisplayLibInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_NDAdditionalDisplay c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[5] = { "CSTR", "WPT", "VORD", "NDB", "ARPT"
  };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 5, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "CSTR";
  c1_y.CSTR = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "CSTR", "CSTR", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "WPT";
  c1_y.WPT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "WPT", "WPT", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "VORD";
  c1_y.VORD = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "VORD", "VORD", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "NDB";
  c1_y.NDB = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "NDB", "NDB", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "ARPT";
  c1_y.ARPT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "ARPT", "ARPT", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_r_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_s_emlrt_marshallIn(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_CockpitDisplayLibInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 8, 1, 0)] = TRUE;
}

static void init_dsm_address_info(SFc1_CockpitDisplayLibInstanceStruct
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

void sf_c1_CockpitDisplayLib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1709553397U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4189802687U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1326447731U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2391924115U);
}

mxArray *sf_c1_CockpitDisplayLib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("y4KOtv65EZLx6U726DZS3D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,19,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
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
      pr[0] = (double)(10);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_CockpitDisplayLib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_CockpitDisplayLib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_CockpitDisplayLib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[129],T\"ECAMMode\",},{M[1],M[226],T\"ED\",},{M[1],M[190],T\"EFIS_Pressure_Output\",},{M[1],M[185],T\"FCU_Display\",},{M[1],M[266],T\"NDMode\",},{M[1],M[302],T\"ND_AD_OP\",},{M[1],M[322],T\"PFD\",},{M[1],M[119],T\"outputDisplay\",},{M[8],M[0],T\"is_active_c1_CockpitDisplayLib\",},{M[8],M[2],T\"is_active_NavigationDisplay\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[3],T\"is_active_SystemDisplay\",},{M[8],M[4],T\"is_active_EngineDisplay\",},{M[8],M[7],T\"is_active_PrimaryFlightDisplay\",},{M[8],M[15],T\"is_active_AirSpeed\",},{M[8],M[40],T\"is_active_Altitude\",},{M[8],M[53],T\"is_active_Attitude\",},{M[8],M[59],T\"is_active_Heading\",},{M[8],M[179],T\"is_active_FCU_EFIS_Display\",},{M[8],M[264],T\"is_active_NDDisplayPages\",},{M[8],M[272],T\"is_active_CSTRDisplay\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[280],T\"is_active_WPTDisplay\",},{M[8],M[285],T\"is_active_VORDDisplay\",},{M[8],M[290],T\"is_active_NDBDisplay\",},{M[8],M[298],T\"is_active_ARPTDisplay\",},{M[9],M[3],T\"is_SystemDisplay\",},{M[9],M[4],T\"is_EngineDisplay\",},{M[9],M[15],T\"is_AirSpeed\",},{M[9],M[40],T\"is_Altitude\",},{M[9],M[53],T\"is_Attitude\",},{M[9],M[59],T\"is_Heading\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[95],T\"is_NormalFlight\",},{M[9],M[96],T\"is_UserSelection_Faults\",},{M[9],M[191],T\"is_Startup\",},{M[9],M[264],T\"is_NDDisplayPages\",},{M[9],M[269],T\"is_NDRunning\",},{M[9],M[272],T\"is_CSTRDisplay\",},{M[9],M[280],T\"is_WPTDisplay\",},{M[9],M[285],T\"is_VORDDisplay\",},{M[9],M[290],T\"is_NDBDisplay\",},{M[9],M[298],T\"is_ARPTDisplay\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i8\",S'et','os','ct'{{T\"at\",M[96],M[1]}}},{M[11],M[0],T\"temporalCounter_i6\",S'et','os','ct'{{T\"at\",M[211],M[1]}}},{M[11],M[0],T\"temporalCounter_i5\",S'et','os','ct'{{T\"at\",M[267],M[1]}}},{M[11],M[0],T\"temporalCounter_i2\",S'et','os','ct'{{T\"at\",M[305],M[1]}}},{M[11],M[0],T\"temporalCounter_i4\",S'et','os','ct'{{T\"at\",M[313],M[1]}}},{M[11],M[0],T\"temporalCounter_i3\",S'et','os','ct'{{T\"at\",M[319],M[1]}}},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[326],M[1]}}},{M[11],M[0],T\"temporalCounter_i7\",S'et','os','ct'{{T\"at\",M1x8[194 207 69 70 72 73 74 178],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 48, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CockpitDisplayLib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
    chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CockpitDisplayLibMachineNumber_,
           1,
           69,
           98,
           29,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"ECAMDisp");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EFIS_Input");
          _SFD_SET_DATA_PROPS(2,1,1,0,"NDInput");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ND_AD");
          _SFD_SET_DATA_PROPS(4,1,1,0,"warn_msgID");
          _SFD_SET_DATA_PROPS(5,2,0,1,"outputDisplay");
          _SFD_SET_DATA_PROPS(6,1,1,0,"RPMProblem");
          _SFD_SET_DATA_PROPS(7,1,1,0,"TempProblem");
          _SFD_SET_DATA_PROPS(8,1,1,0,"FuelPProblem");
          _SFD_SET_DATA_PROPS(9,1,1,0,"FuelQProblem");
          _SFD_SET_DATA_PROPS(10,1,1,0,"FlightMode");
          _SFD_SET_DATA_PROPS(11,1,1,0,"APUProblem");
          _SFD_SET_DATA_PROPS(12,1,1,0,"HydProblem");
          _SFD_SET_DATA_PROPS(13,1,1,0,"CabinPProblem");
          _SFD_SET_DATA_PROPS(14,1,1,0,"APU_Mode");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Engine_Mode");
          _SFD_SET_DATA_PROPS(16,1,1,0,"PFD_Input");
          _SFD_SET_DATA_PROPS(17,1,1,0,"Nav");
          _SFD_SET_DATA_PROPS(18,2,0,1,"ECAMMode");
          _SFD_SET_DATA_PROPS(19,2,0,1,"FCU_Display");
          _SFD_SET_DATA_PROPS(20,1,1,0,"EnF");
          _SFD_SET_DATA_PROPS(21,1,1,0,"Misc");
          _SFD_SET_DATA_PROPS(22,2,0,1,"EFIS_Pressure_Output");
          _SFD_SET_DATA_PROPS(23,2,0,1,"ED");
          _SFD_SET_DATA_PROPS(24,2,0,1,"NDMode");
          _SFD_SET_DATA_PROPS(25,2,0,1,"ND_AD_OP");
          _SFD_SET_DATA_PROPS(26,2,0,1,"PFD");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,1,1);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,1);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,1);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,1);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,1);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,1,1);
          _SFD_STATE_INFO(33,0,1);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,1);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,1);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,1);
          _SFD_STATE_INFO(46,0,0);
          _SFD_STATE_INFO(47,0,0);
          _SFD_STATE_INFO(48,0,0);
          _SFD_STATE_INFO(49,0,1);
          _SFD_STATE_INFO(50,0,0);
          _SFD_STATE_INFO(51,0,0);
          _SFD_STATE_INFO(52,0,0);
          _SFD_STATE_INFO(53,0,0);
          _SFD_STATE_INFO(54,0,0);
          _SFD_STATE_INFO(55,0,0);
          _SFD_STATE_INFO(56,0,0);
          _SFD_STATE_INFO(57,0,0);
          _SFD_STATE_INFO(58,0,0);
          _SFD_STATE_INFO(59,0,0);
          _SFD_STATE_INFO(60,0,0);
          _SFD_STATE_INFO(61,0,0);
          _SFD_STATE_INFO(62,0,0);
          _SFD_STATE_INFO(63,0,0);
          _SFD_STATE_INFO(64,0,0);
          _SFD_STATE_INFO(65,0,0);
          _SFD_STATE_INFO(66,0,0);
          _SFD_STATE_INFO(67,0,0);
          _SFD_STATE_INFO(68,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,32);
          _SFD_CH_SUBSTATE_INDEX(1,7);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_CH_SUBSTATE_INDEX(3,49);
          _SFD_CH_SUBSTATE_INDEX(4,6);
          _SFD_ST_SUBSTATE_COUNT(32,4);
          _SFD_ST_SUBSTATE_INDEX(32,0,33);
          _SFD_ST_SUBSTATE_INDEX(32,1,37);
          _SFD_ST_SUBSTATE_INDEX(32,2,45);
          _SFD_ST_SUBSTATE_INDEX(32,3,41);
          _SFD_ST_SUBSTATE_COUNT(33,3);
          _SFD_ST_SUBSTATE_INDEX(33,0,34);
          _SFD_ST_SUBSTATE_INDEX(33,1,35);
          _SFD_ST_SUBSTATE_INDEX(33,2,36);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,3);
          _SFD_ST_SUBSTATE_INDEX(37,0,38);
          _SFD_ST_SUBSTATE_INDEX(37,1,39);
          _SFD_ST_SUBSTATE_INDEX(37,2,40);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(45,3);
          _SFD_ST_SUBSTATE_INDEX(45,0,46);
          _SFD_ST_SUBSTATE_INDEX(45,1,47);
          _SFD_ST_SUBSTATE_INDEX(45,2,48);
          _SFD_ST_SUBSTATE_COUNT(46,0);
          _SFD_ST_SUBSTATE_COUNT(47,0);
          _SFD_ST_SUBSTATE_COUNT(48,0);
          _SFD_ST_SUBSTATE_COUNT(41,3);
          _SFD_ST_SUBSTATE_INDEX(41,0,42);
          _SFD_ST_SUBSTATE_INDEX(41,1,43);
          _SFD_ST_SUBSTATE_INDEX(41,2,44);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,0);
          _SFD_ST_SUBSTATE_COUNT(7,6);
          _SFD_ST_SUBSTATE_INDEX(7,0,17);
          _SFD_ST_SUBSTATE_INDEX(7,1,11);
          _SFD_ST_SUBSTATE_INDEX(7,2,29);
          _SFD_ST_SUBSTATE_INDEX(7,3,26);
          _SFD_ST_SUBSTATE_INDEX(7,4,14);
          _SFD_ST_SUBSTATE_INDEX(7,5,8);
          _SFD_ST_SUBSTATE_COUNT(17,3);
          _SFD_ST_SUBSTATE_INDEX(17,0,18);
          _SFD_ST_SUBSTATE_INDEX(17,1,19);
          _SFD_ST_SUBSTATE_INDEX(17,2,25);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,5);
          _SFD_ST_SUBSTATE_INDEX(19,0,20);
          _SFD_ST_SUBSTATE_INDEX(19,1,21);
          _SFD_ST_SUBSTATE_INDEX(19,2,22);
          _SFD_ST_SUBSTATE_INDEX(19,3,23);
          _SFD_ST_SUBSTATE_INDEX(19,4,24);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(11,2);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(29,2);
          _SFD_ST_SUBSTATE_INDEX(29,0,30);
          _SFD_ST_SUBSTATE_INDEX(29,1,31);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(26,2);
          _SFD_ST_SUBSTATE_INDEX(26,0,27);
          _SFD_ST_SUBSTATE_INDEX(26,1,28);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(14,2);
          _SFD_ST_SUBSTATE_INDEX(14,0,15);
          _SFD_ST_SUBSTATE_INDEX(14,1,16);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(8,2);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(0,4);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(49,3);
          _SFD_ST_SUBSTATE_INDEX(49,0,50);
          _SFD_ST_SUBSTATE_INDEX(49,1,54);
          _SFD_ST_SUBSTATE_INDEX(49,2,61);
          _SFD_ST_SUBSTATE_COUNT(50,3);
          _SFD_ST_SUBSTATE_INDEX(50,0,51);
          _SFD_ST_SUBSTATE_INDEX(50,1,52);
          _SFD_ST_SUBSTATE_INDEX(50,2,53);
          _SFD_ST_SUBSTATE_COUNT(51,0);
          _SFD_ST_SUBSTATE_COUNT(52,0);
          _SFD_ST_SUBSTATE_COUNT(53,0);
          _SFD_ST_SUBSTATE_COUNT(54,6);
          _SFD_ST_SUBSTATE_INDEX(54,0,55);
          _SFD_ST_SUBSTATE_INDEX(54,1,56);
          _SFD_ST_SUBSTATE_INDEX(54,2,57);
          _SFD_ST_SUBSTATE_INDEX(54,3,58);
          _SFD_ST_SUBSTATE_INDEX(54,4,59);
          _SFD_ST_SUBSTATE_INDEX(54,5,60);
          _SFD_ST_SUBSTATE_COUNT(55,0);
          _SFD_ST_SUBSTATE_COUNT(56,0);
          _SFD_ST_SUBSTATE_COUNT(57,0);
          _SFD_ST_SUBSTATE_COUNT(58,0);
          _SFD_ST_SUBSTATE_COUNT(59,0);
          _SFD_ST_SUBSTATE_COUNT(60,0);
          _SFD_ST_SUBSTATE_COUNT(61,7);
          _SFD_ST_SUBSTATE_INDEX(61,0,62);
          _SFD_ST_SUBSTATE_INDEX(61,1,63);
          _SFD_ST_SUBSTATE_INDEX(61,2,64);
          _SFD_ST_SUBSTATE_INDEX(61,3,65);
          _SFD_ST_SUBSTATE_INDEX(61,4,66);
          _SFD_ST_SUBSTATE_INDEX(61,5,67);
          _SFD_ST_SUBSTATE_INDEX(61,6,68);
          _SFD_ST_SUBSTATE_COUNT(62,0);
          _SFD_ST_SUBSTATE_COUNT(63,0);
          _SFD_ST_SUBSTATE_COUNT(64,0);
          _SFD_ST_SUBSTATE_COUNT(65,0);
          _SFD_ST_SUBSTATE_COUNT(66,0);
          _SFD_ST_SUBSTATE_COUNT(67,0);
          _SFD_ST_SUBSTATE_COUNT(68,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(5,0,0,0);

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
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,6,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,5,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,4,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(37,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(44,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(45,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(46,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(47,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(48,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(49,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(50,3,0,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(51,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(52,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(53,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(54,6,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(55,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(56,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(57,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(58,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(59,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(60,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(61,7,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(62,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(63,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(64,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(65,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(66,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(67,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(68,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(69,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(65,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(78,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(77,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(76,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(90,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(84,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(95,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(94,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(88,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(83,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(73,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(97,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(86,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(96,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(72,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(89,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(87,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(71,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(91,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(82,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(70,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(92,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(79,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(85,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(74,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(93,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(75,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(80,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(81,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(37,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(40,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(45,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(48,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(47,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(41,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(42,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(43,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,1,0,159,194,242,302);
        _SFD_CV_INIT_EML_IF(6,1,1,159,194,242,302);
        _SFD_CV_INIT_EML(49,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(54,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(57,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(58,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(55,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(56,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(59,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(60,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(50,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(52,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(53,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(51,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(61,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(66,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(64,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(68,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(67,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(62,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(63,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(65,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(67,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(68,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(68,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(69,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(69,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(58,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(59,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(59,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(60,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(60,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(64,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(65,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(65,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(66,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(66,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(61,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(62,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(62,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(63,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(63,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(35,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(36,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(40,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(42,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(34,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(43,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(44,0,0,1,45,1,45);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 45 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(44,0,0,1,45,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(45,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(46,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(47,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(47,0,0,1,44,1,44);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 44 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(47,0,0,1,44,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(48,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(48,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(51,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(50,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(50,0,0,1,45,1,45);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 45 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(50,0,0,1,45,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(49,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(49,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(52,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(54,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(54,0,0,1,44,1,44);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 44 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(54,0,0,1,44,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(53,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(53,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(56,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(55,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(55,0,0,1,45,1,45);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 45 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(55,0,0,1,45,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(57,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(57,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(24,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(25,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(32,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(15,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(78,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(78,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(9,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(77,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(76,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(76,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(8,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(90,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(84,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(84,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(12,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(95,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(94,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(88,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(88,0,0,1,26,1,26);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,31,1,31);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 14, 31 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,31,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(83,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(73,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(73,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(97,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(97,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(86,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(96,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(72,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(72,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(89,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(89,0,0,1,26,1,26);
        _SFD_CV_INIT_EML(13,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(87,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(71,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(71,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,41,1,41);

        {
          static int condStart[] = { 1, 25 };

          static int condEnd[] = { 17, 41 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,41,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(91,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(91,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(82,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(70,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(70,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(92,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(92,0,0,1,26,1,26);
        _SFD_CV_INIT_EML(79,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(85,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(74,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(74,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(93,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(93,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(75,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(75,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(80,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(81,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(81,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(11,0,0,0,138,0,51);

        {
          static int condStart[] = { 0, 13, 126 };

          static int condEnd[] = { 12, 118, 137 };

          static int pfixExpr[] = { 0, 1, 2, -3, -3 };

          _SFD_CV_INIT_EML_MCDC(11,0,0,0,138,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,124,1,52);

        {
          static int condStart[] = { 1, 113 };

          static int condEnd[] = { 106, 124 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,124,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_ND_AD_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 10;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_outputDisplay_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_PFD_Input_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_Nav_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_FCU_Display_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_EnF_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_Misc_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_ED_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_ND_AD_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_PFD_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));

        {
          c1_ECAMInput *c1_ECAMDisp;
          c1_EFIS_Pressure *c1_EFIS_Input;
          c1_NDPageInput *c1_NDInput;
          c1_NDAdditionalDisplay *c1_ND_AD;
          c1_warnings_bus *c1_outputDisplay;
          real_T *c1_RPMProblem;
          real_T *c1_TempProblem;
          real_T *c1_FuelPProblem;
          real_T *c1_FuelQProblem;
          real_T *c1_FlightMode;
          real_T *c1_APUProblem;
          real_T *c1_HydProblem;
          real_T *c1_CabinPProblem;
          real_T *c1_APU_Mode;
          real_T *c1_Engine_Mode;
          c1_FlightInputs *c1_PFD_Input;
          c1_NavData *c1_Nav;
          real_T *c1_ECAMMode;
          c1_FCU_Output *c1_FCU_Display;
          c1_EngineFuel_Bus *c1_EnF;
          c1_MiscData *c1_Misc;
          real_T *c1_EFIS_Pressure_Output;
          c1_EngineDisplayBus *c1_ED;
          real_T *c1_NDMode;
          c1_NDAdditionalDisplay *c1_ND_AD_OP;
          c1_PFDOutput *c1_PFD;
          real_T (*c1_warn_msgID)[10];
          c1_PFD = (c1_PFDOutput *)ssGetOutputPortSignal(chartInstance->S, 8);
          c1_ND_AD_OP = (c1_NDAdditionalDisplay *)ssGetOutputPortSignal
            (chartInstance->S, 7);
          c1_NDMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_ED = (c1_EngineDisplayBus *)ssGetOutputPortSignal(chartInstance->S,
            5);
          c1_EFIS_Pressure_Output = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 4);
          c1_Misc = (c1_MiscData *)ssGetInputPortSignal(chartInstance->S, 18);
          c1_EnF = (c1_EngineFuel_Bus *)ssGetInputPortSignal(chartInstance->S,
            17);
          c1_FCU_Display = (c1_FCU_Output *)ssGetOutputPortSignal
            (chartInstance->S, 3);
          c1_ECAMMode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Nav = (c1_NavData *)ssGetInputPortSignal(chartInstance->S, 16);
          c1_PFD_Input = (c1_FlightInputs *)ssGetInputPortSignal
            (chartInstance->S, 15);
          c1_Engine_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_APU_Mode = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_CabinPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_HydProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_APUProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_FlightMode = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_FuelQProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_FuelPProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_TempProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_RPMProblem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_outputDisplay = (c1_warnings_bus *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c1_warn_msgID = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S,
            4);
          c1_ND_AD = (c1_NDAdditionalDisplay *)ssGetInputPortSignal
            (chartInstance->S, 3);
          c1_NDInput = (c1_NDPageInput *)ssGetInputPortSignal(chartInstance->S,
            2);
          c1_EFIS_Input = (c1_EFIS_Pressure *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c1_ECAMDisp = (c1_ECAMInput *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_ECAMDisp);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_EFIS_Input);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_NDInput);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_ND_AD);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_warn_msgID);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_outputDisplay);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_RPMProblem);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_TempProblem);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_FuelPProblem);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_FuelQProblem);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_FlightMode);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_APUProblem);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_HydProblem);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_CabinPProblem);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_APU_Mode);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_Engine_Mode);
          _SFD_SET_DATA_VALUE_PTR(16U, c1_PFD_Input);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_Nav);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_ECAMMode);
          _SFD_SET_DATA_VALUE_PTR(19U, c1_FCU_Display);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_EnF);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_Misc);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_EFIS_Pressure_Output);
          _SFD_SET_DATA_VALUE_PTR(23U, c1_ED);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_NDMode);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_ND_AD_OP);
          _SFD_SET_DATA_VALUE_PTR(26U, c1_PFD);
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
  return "xYNtpxs0GdL4m1YB5d4fWE";
}

static void sf_opaque_initialize_c1_CockpitDisplayLib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
  initialize_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_CockpitDisplayLib(void *chartInstanceVar)
{
  enable_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_CockpitDisplayLib(void *chartInstanceVar)
{
  disable_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_CockpitDisplayLib(void *chartInstanceVar)
{
  sf_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_CockpitDisplayLib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_CockpitDisplayLib
    ((SFc1_CockpitDisplayLibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CockpitDisplayLib();/* state var info */
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

extern void sf_internal_set_sim_state_c1_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CockpitDisplayLib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_CockpitDisplayLib(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_CockpitDisplayLib(S);
}

static void sf_opaque_set_sim_state_c1_CockpitDisplayLib(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_CockpitDisplayLib(S, st);
}

static void sf_opaque_terminate_c1_CockpitDisplayLib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CockpitDisplayLibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CockpitDisplayLib_optimization_info();
    }

    finalize_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CockpitDisplayLib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CockpitDisplayLib((SFc1_CockpitDisplayLibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_CockpitDisplayLib(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CockpitDisplayLib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,19);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 19; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3471556069U));
  ssSetChecksum1(S,(3262024778U));
  ssSetChecksum2(S,(3321893062U));
  ssSetChecksum3(S,(2300229188U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_CockpitDisplayLib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_CockpitDisplayLib(SimStruct *S)
{
  SFc1_CockpitDisplayLibInstanceStruct *chartInstance;
  chartInstance = (SFc1_CockpitDisplayLibInstanceStruct *)utMalloc(sizeof
    (SFc1_CockpitDisplayLibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_CockpitDisplayLibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_CockpitDisplayLib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CockpitDisplayLib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_CockpitDisplayLib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_CockpitDisplayLib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_CockpitDisplayLib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_CockpitDisplayLib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_CockpitDisplayLib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CockpitDisplayLib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CockpitDisplayLib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CockpitDisplayLib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_CockpitDisplayLib;
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

void c1_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CockpitDisplayLib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CockpitDisplayLib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CockpitDisplayLib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
