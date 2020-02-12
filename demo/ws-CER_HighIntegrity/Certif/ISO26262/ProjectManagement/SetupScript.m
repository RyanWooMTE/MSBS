function SetupScript(projectRoot)

%% Set Script path for ISO26262
addpath( fullfile(projectRoot, 'Certif/ISO26262/Model/Scripts') );
addpath( fullfile(projectRoot, 'Certif/ISO26262/Scripts') );
addpath( fullfile(projectRoot, 'Certif/ISO26262/MAConfig') );


%% Move  this section in a certif/script new script.
certifname('ISO26262');
certiffolder('ISO26262');
modelname('doorlock');

%% Prepare the shortcuts for this certif kit
setShortcutStatus([projectRoot '/Certif/ISO26262/Model/C_DoorLock/I_DoorLock/cd_I_DoorLock.m'], 1);
setShortcutStatus([projectRoot '/Certif/ISO26262/Model/C_DoorLock/F_Actuator_Ctrl/cd_F_Actuator_Ctrl.m'], 1);
setShortcutStatus([projectRoot '/Certif/ISO26262/Model/Scripts/DoorLockTraceabilityReport.m'], 1);
setShortcutStatus([projectRoot '/Certif/ISO26262/Model/Scripts/runIntegrationTest.m'], 1);

disp(['Demonstration ISO26262 using model:' modelname]);

end