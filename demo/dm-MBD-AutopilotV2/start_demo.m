% enableservice('AutomationServer',true);
% rmiut.matlabConnectorOn(); % R2012a
rmi('httpLink'); % R2012b

addpath(genpath(fullfile(pwd,'models')));
addpath(genpath(fullfile(pwd,'utilities')));
addpath(genpath(fullfile(pwd,'data')));
addpath(genpath(fullfile(pwd,'targets')));
addpath(genpath(fullfile(pwd,'libraries')));

cd('.\work');
web('..\presentations\html\do178_Autopilot_demo_script.html');

