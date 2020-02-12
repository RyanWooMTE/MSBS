proj = simulinkproject(); 
rootFolder =  proj.RootFolder;
rmpath(fullfile(rootFolder,'\Libraries')) 
rmpath(fullfile(rootFolder,'\MATLABFiles')) 
rmpath(fullfile(rootFolder,'\data')) 
rmpath(fullfile(rootFolder,'\Powerpoint')) 
rmpath(fullfile(rootFolder,'\Requirements')) 
rmpath(fullfile(rootFolder,'\Models')) 
rmpath(fullfile(rootFolder,'\Models\Step0_CompleteModel')) 
rmpath(fullfile(rootFolder,'\Models\Step1_BuildLogic_Link')) 
rmpath(fullfile(rootFolder,'\Models\Step2_ReqBasedTesting_ModelCoverage')) 
rmpath(fullfile(rootFolder,'\Models\Step3_TestCaseGeneration')) 
rmpath(fullfile(rootFolder,'\Models\Step4_SILSignalComparison')) 
rmpath(fullfile(rootFolder,'\Models\Step5_GenerateCodeReuseComponent')) 
bdclose all;
clear all;
clc;
