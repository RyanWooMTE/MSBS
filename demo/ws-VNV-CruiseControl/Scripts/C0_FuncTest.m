%% ========================================================================
%       Requirements Based Functional Testing
%  ========================================================================
%%  Open requirements word doc
%winopen('cruise_control_reqs_mdl_linked.docx');
%winopen('cruise_control_reqs_SLT.docx');
winopen('cruise_control_testplan_short.docx');
%%  Open test cases based on reqs
%winopen('CruiseControlTests.xlsx');
winopen('CruiseControlTests_short.xlsx');
%% close
bdclose all
clear all
%%  Copy Cruise Control version for test
p = slproject.getCurrentProject;
copyfile(fullfile(p.RootFolder,'Models','CruiseControl_SLT_0.slx'), ...
    fullfile(p.RootFolder,'Models','CruiseControl.slx'));
clear p;
% clear any existing coverage
%coverageMgr('clear');
% open the model
open_system('CruiseControl.slx');