#ifndef __c11_CockpitDisplayLib_h__
#define __c11_CockpitDisplayLib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_MiscData_tag
#define struct_MiscData_tag

struct MiscData_tag
{
  real_T FlapPosition;
  real_T CabinPressure;
  real_T HydraulicPressure;
  real_T APUData;
  boolean_T LGLeftLock;
  boolean_T LGRightLock;
};

#endif                                 /*struct_MiscData_tag*/

#ifndef typedef_c11_MiscData
#define typedef_c11_MiscData

typedef struct MiscData_tag c11_MiscData;

#endif                                 /*typedef_c11_MiscData*/

#ifndef typedef_SFc11_CockpitDisplayLibInstanceStruct
#define typedef_SFc11_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_Normal;
  uint8_T c11_tp_CabinPressureLow;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_CockpitDisplayLib;
  uint8_T c11_is_c11_CockpitDisplayLib;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T *c11_FlightMode_address;
  int32_T c11_FlightMode_index;
} SFc11_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc11_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_duringc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_exitc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_enablec11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_disablec11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_activate_callc11_CockpitDisplayLib(SimStruct *c11_S);
extern void sf_exported_auto_increment_call_counterc11_CockpitDisplayLib
  (SimStruct *c11_S);
extern void sf_exported_auto_reset_call_counterc11_CockpitDisplayLib(SimStruct
  *c11_S);
extern void sf_exported_auto_deactivate_callc11_CockpitDisplayLib(SimStruct
  *c11_S);
extern void sf_exported_auto_initc11_CockpitDisplayLib(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_CockpitDisplayLib
  (SimStruct *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_CockpitDisplayLib(SimStruct *
  c11_S);
extern void sf_exported_auto_setSimstatec11_CockpitDisplayLib(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_CockpitDisplayLib(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_exported_auto_check_state_inconsistency_c11_CockpitDisplayLib
  (SimStruct *c11_S);

/* Function Definitions */
extern void sf_c11_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c11_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
