function SetupScript(projectRoot)

%% Set Script path for IEC62304
addpath( fullfile(projectRoot, 'Certif/IEC62304/Model/Scripts') );
addpath( fullfile(projectRoot, 'Certif/IEC62304/Scripts') );
addpath( fullfile(projectRoot, 'Certif/IEC62304/MAConfig') );


%% Move  this section in a certif/script new script.
certifname('IEC62304');
certiffolder('IEC62304');
modelname('doorlock');

%% Prepare the shortcuts for this certif kit
% setShortcutStatus([projectRoot '/Certif/IEC62304/Model/C_DoorLock/I_DoorLock/cd_I_DoorLock.m'], 1);
% setShortcutStatus([projectRoot '/Certif/IEC62304/Model/C_DoorLock/F_Actuator_Ctrl/cd_F_Actuator_Ctrl.m'], 1);
% setShortcutStatus([projectRoot '/Certif/IEC62304/Model/Scripts/DoorLockTraceabilityReport.m'], 1);
% setShortcutStatus([projectRoot '/Certif/IEC62304/Model/Scripts/runIntegrationTest.m'], 1);

disp(['Demonstration IEC62304 using model:' modelname]);

end