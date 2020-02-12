
rmi('httpLink');

addpath(genpath(fullfile(pwd,'models')));
addpath(genpath(fullfile(pwd,'utilities')));
addpath(genpath(fullfile(pwd,'data')));
addpath(genpath(fullfile(pwd,'CAD')));
addpath(genpath(fullfile(pwd,'images')));
addpath(genpath(fullfile(pwd,'targets')));

cd('.\work');
web('..\scripts\html\quadrotor_demo_script.html');
