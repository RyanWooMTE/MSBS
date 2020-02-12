#ifndef __c3_LandingGearModeLib_h__
#define __c3_LandingGearModeLib_h__

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

#ifndef typedef_c3_MiscData
#define typedef_c3_MiscData

typedef struct MiscData_tag c3_MiscData;

#endif                                 /*typedef_c3_MiscData*/

#ifndef typedef_SFc3_LandingGearModeLibInstanceStruct
#define typedef_SFc3_LandingGearModeLibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_LeftLock;
  uint8_T c3_tp_Locked;
  uint8_T c3_tp_Unlocked;
  uint8_T c3_tp_RightLock;
  uint8_T c3_b_tp_Unlocked;
  uint8_T c3_b_tp_Locked;
  uint8_T c3_tp_WarningModes;
  uint8_T c3_tp_BothLocked;
  uint8_T c3_tp_BothUnLocked;
  uint8_T c3_tp_OnlyOneLocked;
  uint8_T c3_tp_ERROR;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_LandingGearModeLib;
  uint8_T c3_is_LeftLock;
  uint8_T c3_is_active_LeftLock;
  uint8_T c3_is_RightLock;
  uint8_T c3_is_active_RightLock;
  uint8_T c3_is_WarningModes;
  uint8_T c3_is_active_WarningModes;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_LandingGearModeLibInstanceStruct;

#endif                                 /*typedef_SFc3_LandingGearModeLibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_LandingGearModeLib_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_LandingGearModeLib_get_check_sum(mxArray *plhs[]);
extern void c3_LandingGearModeLib_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
