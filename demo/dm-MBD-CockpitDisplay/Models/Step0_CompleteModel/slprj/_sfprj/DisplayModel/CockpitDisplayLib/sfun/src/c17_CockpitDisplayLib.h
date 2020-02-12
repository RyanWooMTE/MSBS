#ifndef __c17_CockpitDisplayLib_h__
#define __c17_CockpitDisplayLib_h__

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

#ifndef typedef_c17_EngineFuel_Bus
#define typedef_c17_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c17_EngineFuel_Bus;

#endif                                 /*typedef_c17_EngineFuel_Bus*/

#ifndef typedef_SFc17_CockpitDisplayLibInstanceStruct
#define typedef_SFc17_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  uint8_T c17_tp_Normal;
  uint8_T c17_tp_Cooling;
  uint8_T c17_tp_Heating;
  uint8_T c17_tp_EngineFire;
  boolean_T c17_isStable;
  uint8_T c17_is_active_c17_CockpitDisplayLib;
  uint8_T c17_is_c17_CockpitDisplayLib;
  uint8_T c17_temporalCounter_i1;
  uint8_T c17_doSetSimStateSideEffects;
  const mxArray *c17_setSimStateSideEffectsInfo;
} SFc17_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc17_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_duringc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_enterc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_exitc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_gatewayc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_enablec17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_disablec17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_stepBuffersc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_initBuffersc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_activate_callc17_CockpitDisplayLib(SimStruct *c17_S);
extern void sf_exported_auto_increment_call_counterc17_CockpitDisplayLib
  (SimStruct *c17_S);
extern void sf_exported_auto_reset_call_counterc17_CockpitDisplayLib(SimStruct
  *c17_S);
extern void sf_exported_auto_deactivate_callc17_CockpitDisplayLib(SimStruct
  *c17_S);
extern void sf_exported_auto_initc17_CockpitDisplayLib(SimStruct *c17_S);
extern const mxArray *sf_exported_auto_getSimstatec17_CockpitDisplayLib
  (SimStruct *c17_S);
extern const mxArray *sf_internal_get_sim_state_c17_CockpitDisplayLib(SimStruct *
  c17_S);
extern void sf_exported_auto_setSimstatec17_CockpitDisplayLib(SimStruct *c17_S,
  const mxArray *c17_in);
extern void sf_internal_set_sim_state_c17_CockpitDisplayLib(SimStruct *c17_S,
  const mxArray *c17_in);
extern void sf_exported_auto_check_state_inconsistency_c17_CockpitDisplayLib
  (SimStruct *c17_S);

/* Function Definitions */
extern void sf_c17_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c17_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
