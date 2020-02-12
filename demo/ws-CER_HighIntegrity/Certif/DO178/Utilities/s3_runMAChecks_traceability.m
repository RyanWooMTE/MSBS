%% Run the Model Advisor check on models in the current folder
% The Model Advisor produces reports for each subsystem in the current
% folder. Reports are .mat file. In addition, an html report is also
% created.
function s3_runMAChecks_traceability()
% Specify configuration
CurrentRelease = ['R',version('-release')];
MAConfFileName = ['MAConfFile_', CurrentRelease, '_traceability.mat'];
% Call main routine
s3_runMAChecks(MAConfFileName);