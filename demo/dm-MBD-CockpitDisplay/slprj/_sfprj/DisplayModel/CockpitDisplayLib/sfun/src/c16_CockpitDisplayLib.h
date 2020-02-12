#ifndef __c16_CockpitDisplayLib_h__
#define __c16_CockpitDisplayLib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_EngineFuel_Bus_tag
#define struct_EngineFuel_Bus_tag

struct EngineFuel_Bus_tag
{
  real_T RPM;
  real_T temperature;
  real_T fuelpressure;
  real_T oilpressure;
  real_T EGT;
  real_T EPR1;
  real_T EPR2;
  real_T FuelQuantity;
};

#endif                                 /*struct_EngineFuel_Bus_tag*/

#ifndef typedef_c16_EngineFuel_Bus
#define typedef_c16_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c16_EngineFuel_Bus;

#endif                                 /*typedef_c16_EngineFuel_Bus*/

#ifndef typedef_SFc16_CockpitDisplayLibInstanceStruct
#define typedef_SFc16_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  uint8_T c16_tp_Normal;
  uint8_T c16_tp_EngineFailure;
  uint8_T c16_tp_EngineOverSpeed;
  boolean_T c16_isStable;
  uint8_T c16_is_active_c16_CockpitDisplayLib;
  uint8_T c16_is_c16_CockpitDisplayLib;
  uint8_T c16_doSetSimStateSideEffects;
  const mxArray *c16_setSimStateSideEffectsInfo;
  real_T *c16_FlightMode_address;
  int32_T c16_FlightMode_index;
} SFc16_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc16_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_duringc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_enterc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_exitc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_gatewayc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_enablec16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_disablec16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_stepBuffersc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_initBuffersc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_activate_callc16_CockpitDisplayLib(SimStruct *c16_S);
extern void sf_exported_auto_increment_call_counterc16_CockpitDisplayLib
  (SimStruct *c16_S);
extern void sf_exported_auto_reset_call_counterc16_CockpitDisplayLib(SimStruct
  *c16_S);
extern void sf_exported_auto_deactivate_callc16_CockpitDisplayLib(SimStruct
  *c16_S);
extern void sf_exported_auto_initc16_CockpitDisplayLib(SimStruct *c16_S);
extern const mxArray *sf_exported_auto_getSimstatec16_CockpitDisplayLib
  (SimStruct *c16_S);
extern const mxArray *sf_internal_get_sim_state_c16_CockpitDisplayLib(SimStruct *
  c16_S);
extern void sf_exported_auto_setSimstatec16_CockpitDisplayLib(SimStruct *c16_S,
  const mxArray *c16_in);
extern void sf_internal_set_sim_state_c16_CockpitDisplayLib(SimStruct *c16_S,
  const mxArray *c16_in);
extern void sf_exported_auto_check_state_inconsistency_c16_CockpitDisplayLib
  (SimStruct *c16_S);
extern boolean_T sf_exported_user_c16_CockpitDisplayLib_funcEngFailureToNormal
  (SimStruct *c16_S);
extern boolean_T sf_exported_user_c16_CockpitDisplayLib_funcNormalToEngFailure
  (SimStruct *c16_S);

/* Function Definitions */
extern void sf_c16_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c16_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
