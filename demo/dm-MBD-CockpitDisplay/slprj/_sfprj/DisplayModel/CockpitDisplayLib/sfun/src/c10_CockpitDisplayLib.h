#ifndef __c10_CockpitDisplayLib_h__
#define __c10_CockpitDisplayLib_h__

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

#ifndef typedef_c10_MiscData
#define typedef_c10_MiscData

typedef struct MiscData_tag c10_MiscData;

#endif                                 /*typedef_c10_MiscData*/

#ifndef typedef_SFc10_CockpitDisplayLibInstanceStruct
#define typedef_SFc10_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  uint8_T c10_tp_Normal;
  uint8_T c10_tp_EngineFire;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_CockpitDisplayLib;
  uint8_T c10_is_c10_CockpitDisplayLib;
  uint8_T c10_doSetSimStateSideEffects;
  const mxArray *c10_setSimStateSideEffectsInfo;
  real_T *c10_FlightMode_address;
  int32_T c10_FlightMode_index;
} SFc10_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc10_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_duringc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_enterc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_exitc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_gatewayc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_enablec10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_disablec10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_stepBuffersc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_initBuffersc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_activate_callc10_CockpitDisplayLib(SimStruct *c10_S);
extern void sf_exported_auto_increment_call_counterc10_CockpitDisplayLib
  (SimStruct *c10_S);
extern void sf_exported_auto_reset_call_counterc10_CockpitDisplayLib(SimStruct
  *c10_S);
extern void sf_exported_auto_deactivate_callc10_CockpitDisplayLib(SimStruct
  *c10_S);
extern void sf_exported_auto_initc10_CockpitDisplayLib(SimStruct *c10_S);
extern const mxArray *sf_exported_auto_getSimstatec10_CockpitDisplayLib
  (SimStruct *c10_S);
extern const mxArray *sf_internal_get_sim_state_c10_CockpitDisplayLib(SimStruct *
  c10_S);
extern void sf_exported_auto_setSimstatec10_CockpitDisplayLib(SimStruct *c10_S,
  const mxArray *c10_in);
extern void sf_internal_set_sim_state_c10_CockpitDisplayLib(SimStruct *c10_S,
  const mxArray *c10_in);
extern void sf_exported_auto_check_state_inconsistency_c10_CockpitDisplayLib
  (SimStruct *c10_S);

/* Function Definitions */
extern void sf_c10_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c10_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
