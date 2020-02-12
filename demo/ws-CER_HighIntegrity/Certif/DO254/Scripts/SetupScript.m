function SetupScript(projectRoot)

%% Set Script path for DO254
addpath( fullfile(projectRoot, 'Certif/DO254/MAConfig') );
% TBD addpath( fullfile(projectRoot, 'Certif/DO254/Model/Scripts') );
% TBD: Add all your useful DO254 standard specific paths here


%% Set-up for DO254 demonstration
certifname('DO-254');
modelname('TBD');


% TBD: Add all your useful DO254 specific shortcuts here
setShortcutStatus([projectRoot '/Certif/DO254/Model/cd_UART.m'] , 1);


% Note: There is currently only one model per kit so I won't ask for the
% model name.
disp(['Demonstrating DO254 with model:' modelname]);


%% Load models data
% TBD



end
