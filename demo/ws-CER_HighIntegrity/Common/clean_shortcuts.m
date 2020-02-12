%% Clean-upshort cut for all standards

% ISO26262 clean-up
setShortcutStatus('Certif/ISO26262/Model/C_DoorLock/I_DoorLock/cd_I_DoorLock.m', 0);
setShortcutStatus('Certif/ISO26262/Model/C_DoorLock/F_Actuator_Ctrl/cd_F_Actuator_Ctrl.m', 0);
setShortcutStatus('Certif/ISO26262/Model/Scripts/runIntegrationTest.m', 0);
setShortcutStatus('Certif/ISO26262/Model/Scripts/DoorLockTraceabilityReport.m', 0);

% DO178 clean-up
setShortcutStatus('Certif/DO178/Model/C_Autopilot/I_Autopilot/Autopilot_harness.mdl' , 0);
setShortcutStatus('Certif/DO178/Model/C_Autopilot/F_Roll_Ap_Cmp/cd_F_Roll_ap.m' , 0);
setShortcutStatus('Certif/DO178/Model/C_Autopilot/F_Pitch_Ap_Cmp/cd_F_Pitch_ap.m' , 0);
setShortcutStatus('Certif/DO178/Model/C_Autopilot/F_Attitude_Controller_Cmp/cd_F_Attitude_ap.m' , 0);

setShortcutStatus('Utilities/s3_runMAChecks_sanity.m' , 0);
setShortcutStatus('Utilities/s3_runMAChecks_traceability.m' , 0);
