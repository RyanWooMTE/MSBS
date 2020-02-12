
% load DO178
p = Simulink.ModelManagement.Project.CurrentProject();
p.loadProject(fullfile(fileparts(mfilename('fullpath')),'../Certif/ISO26262/'));

% go to function 
cd_F_Roll_ap

% run through shortcuts 
s1_createSDD
s2_createWebView
s3_runMAChecks
s4_createModelReviewReport
s5_runModelTests
s6_generateCode
s7_generateTests
s8_runEquivalenceTests
s9_TraceabilityReport



