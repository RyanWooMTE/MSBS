#ifndef __c9_CockpitDisplayLib_h__
#define __c9_CockpitDisplayLib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_FlightInputs_tag
#define struct_FlightInputs_tag

struct FlightInputs_tag
{
  real_T Direction;
  real_T VerticalSpeed;
  real_T AirSpeed;
  real_T Altitude;
  real_T RateOfTurn;
  real_T Attitude;
};

#endif                                 /*struct_FlightInputs_tag*/

#ifndef typedef_c9_FlightInputs
#define typedef_c9_FlightInputs

typedef struct FlightInputs_tag c9_FlightInputs;

#endif                                 /*typedef_c9_FlightInputs*/

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

#ifndef typedef_c9_EngineFuel_Bus
#define typedef_c9_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c9_EngineFuel_Bus;

#endif                                 /*typedef_c9_EngineFuel_Bus*/

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

#ifndef typedef_c9_MiscData
#define typedef_c9_MiscData

typedef struct MiscData_tag c9_MiscData;

#endif                                 /*typedef_c9_MiscData*/

#ifndef typedef_SFc9_CockpitDisplayLibInstanceStruct
#define typedef_SFc9_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_FlightPhases;
  uint8_T c9_tp_EnginesOff;
  uint8_T c9_tp_PushbackAndTaxi;
  uint8_T c9_tp_TakeoffCruiseDescent;
  uint8_T c9_tp_Land;
  uint8_T c9_tp_ComponentModes;
  uint8_T c9_tp_Temp;
  uint8_T c9_tp_OilP;
  uint8_T c9_tp_RPM;
  uint8_T c9_tp_Fuel;
  uint8_T c9_tp_Hyd;
  uint8_T c9_tp_APU;
  uint8_T c9_tp_CabinPressure;
  uint8_T c9_tp_LandingGear;
  uint8_T c9_tp_WarningsComputation;
  uint8_T c9_tp_Phase1;
  uint8_T c9_tp_Phase2;
  uint8_T c9_tp_Phase3;
  uint8_T c9_tp_Phase4;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_CockpitDisplayLib;
  uint8_T c9_is_FlightPhases;
  uint8_T c9_is_active_FlightPhases;
  uint8_T c9_is_active_ComponentModes;
  uint8_T c9_is_active_Temp;
  uint8_T c9_is_active_OilP;
  uint8_T c9_is_active_RPM;
  uint8_T c9_is_active_Fuel;
  uint8_T c9_is_active_Hyd;
  uint8_T c9_is_active_APU;
  uint8_T c9_is_active_CabinPressure;
  uint8_T c9_is_active_LandingGear;
  uint8_T c9_is_WarningsComputation;
  uint8_T c9_is_active_WarningsComputation;
  real_T c9_id;
  SimStruct *c9_subchartSimstruct;
  SimStruct *c9_b_subchartSimstruct;
  SimStruct *c9_c_subchartSimstruct;
  SimStruct *c9_d_subchartSimstruct;
  SimStruct *c9_e_subchartSimstruct;
  SimStruct *c9_f_subchartSimstruct;
  SimStruct *c9_g_subchartSimstruct;
  SimStruct *c9_h_subchartSimstruct;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T *c9_FlightMode_address;
  int32_T c9_FlightMode_index;
} SFc9_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc9_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_gatewayc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc17_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc15_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc16_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc2_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc13_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc10_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc11_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc3_LandingGearModeLib
  (SimStruct *c9_S);
extern void sf_exported_auto_reset_call_counterc17_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc15_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc16_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc2_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc13_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc10_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc11_CockpitDisplayLib(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc3_LandingGearModeLib(SimStruct
  *c9_S);
extern void sf_exported_auto_stepBuffersc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enterc3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_duringc3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_enablec3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_disablec3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c17_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c15_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c16_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c2_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c13_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c10_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c11_CockpitDisplayLib
  (SimStruct *c9_S);
extern void sf_exported_auto_check_state_inconsistency_c3_LandingGearModeLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec17_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec15_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec16_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec2_CockpitDisplayLib(SimStruct
  *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec13_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec10_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec11_CockpitDisplayLib
  (SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec3_LandingGearModeLib
  (SimStruct *c9_S);
extern void sf_exported_auto_setSimstatec17_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec15_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec16_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec2_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec13_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec10_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec11_CockpitDisplayLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_setSimstatec3_LandingGearModeLib(SimStruct *c9_S,
  const mxArray *c9_input);
extern void sf_exported_auto_initc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initc3_LandingGearModeLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc17_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc15_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc16_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc2_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc13_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc10_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc11_CockpitDisplayLib(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc3_LandingGearModeLib(SimStruct *c9_S);

/* Function Definitions */
extern void sf_c9_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c9_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
