#ifndef __c13_CockpitDisplayLib_h__
#define __c13_CockpitDisplayLib_h__

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

#ifndef typedef_c13_MiscData
#define typedef_c13_MiscData

typedef struct MiscData_tag c13_MiscData;

#endif                                 /*typedef_c13_MiscData*/

#ifndef typedef_SFc13_CockpitDisplayLibInstanceStruct
#define typedef_SFc13_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  uint8_T c13_tp_Hyd;
  uint8_T c13_tp_Normal;
  uint8_T c13_tp_EngineFire;
  boolean_T c13_isStable;
  uint8_T c13_is_active_c13_CockpitDisplayLib;
  uint8_T c13_is_c13_CockpitDisplayLib;
  uint8_T c13_is_Hyd;
  uint8_T c13_doSetSimStateSideEffects;
  const mxArray *c13_setSimStateSideEffectsInfo;
  real_T *c13_FlightMode_address;
  int32_T c13_FlightMode_index;
} SFc13_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc13_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_duringc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_enterc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_exitc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_gatewayc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_enablec13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_disablec13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_stepBuffersc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_initBuffersc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_activate_callc13_CockpitDisplayLib(SimStruct *c13_S);
extern void sf_exported_auto_increment_call_counterc13_CockpitDisplayLib
  (SimStruct *c13_S);
extern void sf_exported_auto_reset_call_counterc13_CockpitDisplayLib(SimStruct
  *c13_S);
extern void sf_exported_auto_deactivate_callc13_CockpitDisplayLib(SimStruct
  *c13_S);
extern void sf_exported_auto_initc13_CockpitDisplayLib(SimStruct *c13_S);
extern const mxArray *sf_exported_auto_getSimstatec13_CockpitDisplayLib
  (SimStruct *c13_S);
extern const mxArray *sf_internal_get_sim_state_c13_CockpitDisplayLib(SimStruct *
  c13_S);
extern void sf_exported_auto_setSimstatec13_CockpitDisplayLib(SimStruct *c13_S,
  const mxArray *c13_in);
extern void sf_internal_set_sim_state_c13_CockpitDisplayLib(SimStruct *c13_S,
  const mxArray *c13_in);
extern void sf_exported_auto_check_state_inconsistency_c13_CockpitDisplayLib
  (SimStruct *c13_S);

/* Function Definitions */
extern void sf_c13_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c13_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
