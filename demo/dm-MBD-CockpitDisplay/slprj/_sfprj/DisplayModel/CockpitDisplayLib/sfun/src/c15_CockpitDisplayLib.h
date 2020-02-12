#ifndef __c15_CockpitDisplayLib_h__
#define __c15_CockpitDisplayLib_h__

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

#ifndef typedef_c15_EngineFuel_Bus
#define typedef_c15_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c15_EngineFuel_Bus;

#endif                                 /*typedef_c15_EngineFuel_Bus*/

#ifndef typedef_SFc15_CockpitDisplayLibInstanceStruct
#define typedef_SFc15_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  uint8_T c15_tp_Normal;
  uint8_T c15_tp_EngineOilLowPressure;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_CockpitDisplayLib;
  uint8_T c15_is_c15_CockpitDisplayLib;
  uint8_T c15_doSetSimStateSideEffects;
  const mxArray *c15_setSimStateSideEffectsInfo;
  real_T *c15_FlightMode_address;
  int32_T c15_FlightMode_index;
} SFc15_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc15_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_duringc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_enterc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_exitc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_gatewayc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_enablec15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_disablec15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_stepBuffersc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_initBuffersc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_activate_callc15_CockpitDisplayLib(SimStruct *c15_S);
extern void sf_exported_auto_increment_call_counterc15_CockpitDisplayLib
  (SimStruct *c15_S);
extern void sf_exported_auto_reset_call_counterc15_CockpitDisplayLib(SimStruct
  *c15_S);
extern void sf_exported_auto_deactivate_callc15_CockpitDisplayLib(SimStruct
  *c15_S);
extern void sf_exported_auto_initc15_CockpitDisplayLib(SimStruct *c15_S);
extern const mxArray *sf_exported_auto_getSimstatec15_CockpitDisplayLib
  (SimStruct *c15_S);
extern const mxArray *sf_internal_get_sim_state_c15_CockpitDisplayLib(SimStruct *
  c15_S);
extern void sf_exported_auto_setSimstatec15_CockpitDisplayLib(SimStruct *c15_S,
  const mxArray *c15_in);
extern void sf_internal_set_sim_state_c15_CockpitDisplayLib(SimStruct *c15_S,
  const mxArray *c15_in);
extern void sf_exported_auto_check_state_inconsistency_c15_CockpitDisplayLib
  (SimStruct *c15_S);

/* Function Definitions */
extern void sf_c15_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c15_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
