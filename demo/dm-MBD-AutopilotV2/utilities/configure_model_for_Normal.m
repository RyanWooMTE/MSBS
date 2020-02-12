%% Model and Block Settings
% target_model can be the same as harness_model if target model reference
% block is a direct child of haness model.
harness_model = 'do178b_dhc2';
target_model = 'Autopilot';
target_block = 'Autopilot/Roll_Autopilot'; 

%% Load Configuration
load('DO178ConfigSetNormal');

%% Set target model refernce block as Normal mode
open_system(target_model);
set_param(target_block,'SimulationMode','Normal')
save_system(target_model);
close_system(target_model);

%% Set Model Coverage On
open_system(harness_model);
set_param(gcs,'CovModelRefEnable','on')
set_param(gcs,'ProdHWDeviceType','32-bit Embedded Processor')
covSettings = get_param(gcs, 'CodeCoverageSettings');
covSettings.ReferencedModelCoverage='off';
covSettings.CoverageTool = 'None';
set_param(gcs,'CodeCoverageSettings', covSettings);
save_system(harness_model);
