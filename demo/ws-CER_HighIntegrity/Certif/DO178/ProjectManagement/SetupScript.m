function SetupScript()



%% Set-up for DO178 demonstration
certifname('DO-178C');
modelname('autopilot');

% Note: There is currently only one model per kit so I won't ask for the
% model name.
disp(['Demonstrating DO178 with model:' modelname]);


%% Load models data
Plant_data
Roll_Ap_init
slbus_Inertial
slBus_AirData

%% Load models configuration set reference object
assignin('base','configSetObj_autopilot', autopilot_codegen_config);

end
