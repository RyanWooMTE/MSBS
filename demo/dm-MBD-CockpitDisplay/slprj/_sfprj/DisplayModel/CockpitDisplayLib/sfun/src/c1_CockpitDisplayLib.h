#ifndef __c1_CockpitDisplayLib_h__
#define __c1_CockpitDisplayLib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef enum_EFIS_Pressure
#define enum_EFIS_Pressure

enum EFIS_Pressure
{
  EFIS_Pressure_inHg,
  EFIS_Pressure_mmHg
};

#endif                                 /*enum_EFIS_Pressure*/

#ifndef typedef_c1_EFIS_Pressure
#define typedef_c1_EFIS_Pressure

typedef enum EFIS_Pressure c1_EFIS_Pressure;

#endif                                 /*typedef_c1_EFIS_Pressure*/

#ifndef enum_ECAMInput
#define enum_ECAMInput

enum ECAMInput
{
  ECAMInput_None,
  ECAMInput_ENG,
  ECAMInput_BLEED,
  ECAMInput_PRESS,
  ECAMInput_HYD,
  ECAMInput_FUEL,
  ECAMInput_APU
};

#endif                                 /*enum_ECAMInput*/

#ifndef typedef_c1_ECAMInput
#define typedef_c1_ECAMInput

typedef enum ECAMInput c1_ECAMInput;

#endif                                 /*typedef_c1_ECAMInput*/

#ifndef enum_NDPageInput
#define enum_NDPageInput

enum NDPageInput
{
  NDPageInput_ILS,
  NDPageInput_VOR,
  NDPageInput_NAV,
  NDPageInput_ARC,
  NDPageInput_PLAN
};

#endif                                 /*enum_NDPageInput*/

#ifndef typedef_c1_NDPageInput
#define typedef_c1_NDPageInput

typedef enum NDPageInput c1_NDPageInput;

#endif                                 /*typedef_c1_NDPageInput*/

#ifndef struct_NDAdditionalDisplay_tag
#define struct_NDAdditionalDisplay_tag

struct NDAdditionalDisplay_tag
{
  real_T CSTR;
  real_T WPT;
  real_T VORD;
  real_T NDB;
  real_T ARPT;
};

#endif                                 /*struct_NDAdditionalDisplay_tag*/

#ifndef typedef_c1_NDAdditionalDisplay
#define typedef_c1_NDAdditionalDisplay

typedef struct NDAdditionalDisplay_tag c1_NDAdditionalDisplay;

#endif                                 /*typedef_c1_NDAdditionalDisplay*/

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

#ifndef typedef_c1_FlightInputs
#define typedef_c1_FlightInputs

typedef struct FlightInputs_tag c1_FlightInputs;

#endif                                 /*typedef_c1_FlightInputs*/

#ifndef struct_NavData_tag
#define struct_NavData_tag

struct NavData_tag
{
  real_T bearing;
  real_T distance;
  real_T groundspeed;
  real_T selectedheading;
};

#endif                                 /*struct_NavData_tag*/

#ifndef typedef_c1_NavData
#define typedef_c1_NavData

typedef struct NavData_tag c1_NavData;

#endif                                 /*typedef_c1_NavData*/

#ifndef struct_FCU_Output_tag
#define struct_FCU_Output_tag

struct FCU_Output_tag
{
  real_T Speed;
  real_T Heading;
  real_T Altitude;
};

#endif                                 /*struct_FCU_Output_tag*/

#ifndef typedef_c1_FCU_Output
#define typedef_c1_FCU_Output

typedef struct FCU_Output_tag c1_FCU_Output;

#endif                                 /*typedef_c1_FCU_Output*/

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

#ifndef typedef_c1_EngineFuel_Bus
#define typedef_c1_EngineFuel_Bus

typedef struct EngineFuel_Bus_tag c1_EngineFuel_Bus;

#endif                                 /*typedef_c1_EngineFuel_Bus*/

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

#ifndef typedef_c1_MiscData
#define typedef_c1_MiscData

typedef struct MiscData_tag c1_MiscData;

#endif                                 /*typedef_c1_MiscData*/

#ifndef struct_EngineDisplayBus_tag
#define struct_EngineDisplayBus_tag

struct EngineDisplayBus_tag
{
  real_T EPR1;
  real_T EPR2;
  real_T EGT1;
  real_T EGT2;
  real_T FlapConfig;
  real_T N1_L;
  real_T N1_R;
  real_T ED_Mode_L;
  real_T ED_Mode_R;
  real_T FuelQuantity;
};

#endif                                 /*struct_EngineDisplayBus_tag*/

#ifndef typedef_c1_EngineDisplayBus
#define typedef_c1_EngineDisplayBus

typedef struct EngineDisplayBus_tag c1_EngineDisplayBus;

#endif                                 /*typedef_c1_EngineDisplayBus*/

#ifndef struct_PFDOutput_tag
#define struct_PFDOutput_tag

struct PFDOutput_tag
{
  real_T Altitude;
  real_T Heading;
  real_T Attitude;
  real_T AirSpeed;
  real_T AltMode;
  real_T AirSpeedMode;
  real_T AttMode;
  real_T HeadingMode;
};

#endif                                 /*struct_PFDOutput_tag*/

#ifndef typedef_c1_PFDOutput
#define typedef_c1_PFDOutput

typedef struct PFDOutput_tag c1_PFDOutput;

#endif                                 /*typedef_c1_PFDOutput*/

#ifndef struct_warnings_bus_tag
#define struct_warnings_bus_tag

struct warnings_bus_tag
{
  real_T flightmode;
  real_T ED_Mode_R;
  real_T ED_Mode_L;
  real_T warn_msgID[10];
};

#endif                                 /*struct_warnings_bus_tag*/

#ifndef typedef_c1_warnings_bus
#define typedef_c1_warnings_bus

typedef struct warnings_bus_tag c1_warnings_bus;

#endif                                 /*typedef_c1_warnings_bus*/

#ifndef typedef_SFc1_CockpitDisplayLibInstanceStruct
#define typedef_SFc1_CockpitDisplayLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_PrimaryFlightDisplay;
  uint8_T c1_tp_AirSpeed;
  uint8_T c1_tp_Starting;
  uint8_T c1_tp_OFF;
  uint8_T c1_tp_Running;
  uint8_T c1_tp_Altitude;
  uint8_T c1_b_tp_OFF;
  uint8_T c1_b_tp_Starting;
  uint8_T c1_b_tp_Running;
  uint8_T c1_tp_Heading;
  uint8_T c1_c_tp_OFF;
  uint8_T c1_c_tp_Starting;
  uint8_T c1_c_tp_Running;
  uint8_T c1_tp_Attitude;
  uint8_T c1_d_tp_OFF;
  uint8_T c1_d_tp_Starting;
  uint8_T c1_d_tp_Running;
  uint8_T c1_tp_NavigationDisplay;
  uint8_T c1_tp_NDDisplayPages;
  uint8_T c1_tp_NDRunning;
  uint8_T c1_tp_ILSPage;
  uint8_T c1_tp_VORPage;
  uint8_T c1_tp_NAVPage;
  uint8_T c1_tp_ARCPage;
  uint8_T c1_tp_PLANPage;
  uint8_T c1_tp_NDOff;
  uint8_T c1_tp_NDStart;
  uint8_T c1_tp_CSTRDisplay;
  uint8_T c1_e_tp_OFF;
  uint8_T c1_tp_ON;
  uint8_T c1_tp_WPTDisplay;
  uint8_T c1_f_tp_OFF;
  uint8_T c1_b_tp_ON;
  uint8_T c1_tp_VORDDisplay;
  uint8_T c1_g_tp_OFF;
  uint8_T c1_c_tp_ON;
  uint8_T c1_tp_NDBDisplay;
  uint8_T c1_h_tp_OFF;
  uint8_T c1_d_tp_ON;
  uint8_T c1_tp_ARPTDisplay;
  uint8_T c1_i_tp_OFF;
  uint8_T c1_e_tp_ON;
  uint8_T c1_tp_EngineDisplay;
  uint8_T c1_tp_Engine_Running;
  uint8_T c1_tp_Engine_Ready;
  uint8_T c1_tp_Engine_Off;
  uint8_T c1_tp_Engine_Boot;
  uint8_T c1_tp_FCU_EFIS_Display;
  uint8_T c1_tp_SystemDisplay;
  uint8_T c1_tp_Startup;
  uint8_T c1_tp_APU_Ready;
  uint8_T c1_tp_APU_Running;
  uint8_T c1_tp_APU_Boot;
  uint8_T c1_tp_APU_Off;
  uint8_T c1_tp_APU_Wait;
  uint8_T c1_tp_EngineStarting;
  uint8_T c1_tp_NormalFlight;
  uint8_T c1_tp_PushbackAndTaxi;
  uint8_T c1_tp_TakeoffCruiseDescent;
  uint8_T c1_tp_Land;
  uint8_T c1_tp_UserSelection_Faults;
  uint8_T c1_tp_Engine;
  uint8_T c1_tp_Cabin_Pressure;
  uint8_T c1_tp_HYD;
  uint8_T c1_tp_FUEL;
  uint8_T c1_tp_APU;
  uint8_T c1_tp_Bleed;
  uint8_T c1_tp_ERROR;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_CockpitDisplayLib;
  uint8_T c1_is_active_PrimaryFlightDisplay;
  uint8_T c1_is_AirSpeed;
  uint8_T c1_is_active_AirSpeed;
  uint8_T c1_is_Altitude;
  uint8_T c1_is_active_Altitude;
  uint8_T c1_is_Heading;
  uint8_T c1_is_active_Heading;
  uint8_T c1_is_Attitude;
  uint8_T c1_is_active_Attitude;
  uint8_T c1_is_active_NavigationDisplay;
  uint8_T c1_is_NDDisplayPages;
  uint8_T c1_is_active_NDDisplayPages;
  uint8_T c1_is_NDRunning;
  uint8_T c1_is_CSTRDisplay;
  uint8_T c1_is_active_CSTRDisplay;
  uint8_T c1_is_WPTDisplay;
  uint8_T c1_is_active_WPTDisplay;
  uint8_T c1_is_VORDDisplay;
  uint8_T c1_is_active_VORDDisplay;
  uint8_T c1_is_NDBDisplay;
  uint8_T c1_is_active_NDBDisplay;
  uint8_T c1_is_ARPTDisplay;
  uint8_T c1_is_active_ARPTDisplay;
  uint8_T c1_is_EngineDisplay;
  uint8_T c1_is_active_EngineDisplay;
  uint8_T c1_is_active_FCU_EFIS_Display;
  uint8_T c1_is_SystemDisplay;
  uint8_T c1_is_active_SystemDisplay;
  uint8_T c1_is_Startup;
  uint8_T c1_is_NormalFlight;
  uint8_T c1_is_UserSelection_Faults;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_temporalCounter_i2;
  uint8_T c1_temporalCounter_i3;
  uint8_T c1_temporalCounter_i4;
  uint8_T c1_temporalCounter_i5;
  uint8_T c1_temporalCounter_i6;
  uint8_T c1_temporalCounter_i7;
  uint8_T c1_temporalCounter_i8;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_CockpitDisplayLibInstanceStruct;

#endif                                 /*typedef_SFc1_CockpitDisplayLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_CockpitDisplayLib_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
extern void c1_CockpitDisplayLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
