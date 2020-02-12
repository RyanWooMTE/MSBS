#ifndef __c2_CockpitDisplayLib_h__
#define __c2_CockpitDisplayLib_h__

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

#ifndef typedef_c2_EngineFuel_Bus
#define typedef_c2_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c2_EngineFuel_Bus;

#endif                                 /*typedef_c2_EngineFuel_Bus*/

#ifndef typedef_SFc2_CockpitDisplayLibInstanceStruct
#define typedef_SFc2_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_FuelPressureModes;
  uint8_T c2_tp_Normal;
  uint8_T c2_tp_FuelPressureLow;
  uint8_T c2_tp_FuelQuantityModes;
  uint8_T c2_b_tp_Normal;
  uint8_T c2_tp_FuelQuantityLow;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_CockpitDisplayLib;
  uint8_T c2_is_FuelPressureModes;
  uint8_T c2_is_active_FuelPressureModes;
  uint8_T c2_is_FuelQuantityModes;
  uint8_T c2_is_active_FuelQuantityModes;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  real_T *c2_FlightMode_address;
  int32_T c2_FlightMode_index;
} SFc2_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc2_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_duringc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_enterc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_exitc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_gatewayc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_enablec2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_disablec2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_stepBuffersc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_initBuffersc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_activate_callc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_increment_call_counterc2_CockpitDisplayLib
  (SimStruct *c2_S);
extern void sf_exported_auto_reset_call_counterc2_CockpitDisplayLib(SimStruct
  *c2_S);
extern void sf_exported_auto_deactivate_callc2_CockpitDisplayLib(SimStruct *c2_S);
extern void sf_exported_auto_initc2_CockpitDisplayLib(SimStruct *c2_S);
extern const mxArray *sf_exported_auto_getSimstatec2_CockpitDisplayLib(SimStruct
  *c2_S);
extern const mxArray *sf_internal_get_sim_state_c2_CockpitDisplayLib(SimStruct
  *c2_S);
extern void sf_exported_auto_setSimstatec2_CockpitDisplayLib(SimStruct *c2_S,
  const mxArray *c2_in);
extern void sf_internal_set_sim_state_c2_CockpitDisplayLib(SimStruct *c2_S,
  const mxArray *c2_in);
extern void sf_exported_auto_check_state_inconsistency_c2_CockpitDisplayLib
  (SimStruct *c2_S);
extern real_T sf_exported_user_c2_CockpitDisplayLib_funcFuelPressLow(SimStruct
  *c2_S);
extern real_T sf_exported_user_c2_CockpitDisplayLib_funcFuelQuantityLow
  (SimStruct *c2_S);

/* Function Definitions */
extern void sf_c2_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c2_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
