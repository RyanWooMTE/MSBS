%% Model and Block Settings
% target_model can be the same as harness_model if target model reference
% block is a direct child of haness model.
harness_model = 'do178b_dhc2';
target_model = 'Autopilot';
target_block = 'Autopilot/Roll_Autopilot'; 

%% Load Configuration
load('DO178ConfigSetSIL');

%% Set target model refernce block as SIL mode
open_system(target_model);
set_param(target_block,'SimulationMode','Software-in-the-loop (SIL)')
save_system(target_model);

%% Set Model Coverage Off and Code Coverage On with LDRA
open_system(harness_model);
set_param(gcs,'CovModelRefEnable','off')
set_param(gcs,'ProdHWDeviceType','32-bit Embedded Processor')
covSettings = get_param(gcs, 'CodeCoverageSettings');
covSettings.ReferencedModelCoverage='on';
covSettings.CoverageTool = 'LDRA Testbed';
set_param(gcs,'CodeCoverageSettings', covSettings);
