%% Model and Block Settings
% target_model can be the same as harness_model if target model reference
% block is a direct child of haness model.
harness_model = 'do178b_dhc2';
target_model = 'Autopilot';
target_block = 'Autopilot/Roll_Autopilot'; 

%% Load Configuration
load('DO178ConfigSetPIL');

%% Remove the Previous Files.
if exist('..\work\slprj','dir'), rmdir('..\work\slprj','s'); end

%% Preprocess for PIL simulation
addpath(genpath(fullfile('..\targets')));
sl_refresh_customizations;

setpref('examplePilF28335','examplePilF28335Dir', fullfile(pwd,'..\targets\examplePilF28335'));
setpref('examplePilF28335','CCSRootDir',          'C:\Program Files (x86)\Texas Instruments\ccsv4');
setpref('examplePilF28335','TI_F28xxx_SysSWDir',  'C:\Program Files (x86)\Texas Instruments\TI_F28xxx_SysSW');
setpref('examplePilF28335','targetConfigFile',    fullfile(pwd,'..\targets\examplePilF28335','f28335_XDS100v1.ccxml'));
setpref('examplePilF28335','baudRate',            115200);
setpref('examplePilF28335','cpuClockRateMHz',     150);
setpref('examplePilF28335','boardConfigPLL',      10);
setpref('examplePilF28335','COMPort',             'COM4');

%% Set target model refernce block as PIL mode
open_system(target_model);
set_param(target_block,'SimulationMode','Processor-in-the-loop (PIL)')
save_system(target_model);

%% Set Model Coverage Off
open_system(harness_model);
set_param(gcs,'CovModelRefEnable','off')
set_param(gcs,'ProdHWDeviceType','Texas Instruments->C2000')
covSettings = get_param(gcs, 'CodeCoverageSettings');
covSettings.ReferencedModelCoverage='off';
covSettings.CoverageTool = 'None';
set_param(gcs,'CodeCoverageSettings', covSettings);
