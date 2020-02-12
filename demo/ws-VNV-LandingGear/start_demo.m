
rmi('httpLink');

addpath(genpath(fullfile(pwd,'models')));
addpath(genpath(fullfile(pwd,'libraries')));
addpath(genpath(fullfile(pwd,'utilities')));
addpath(genpath(fullfile(pwd,'data')));
addpath(genpath(fullfile(pwd,'images')));
addpath(genpath(fullfile(pwd,'GUIs')));

cd('.\work');
web('..\scripts\html\LandingGear_demo_script.html');
