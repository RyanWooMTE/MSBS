proj = simulinkproject(); 
rootFolder =  proj.RootFolder;
addpath(fullfile(rootFolder,'\Libraries')) 
addpath(fullfile(rootFolder,'\MATLABFiles')) 
addpath(fullfile(rootFolder,'\data')) 
addpath(fullfile(rootFolder,'\Powerpoint')) 
addpath(fullfile(rootFolder,'\Requirements')) 
addpath(fullfile(rootFolder,'\Models')) 
addpath(fullfile(rootFolder,'\Models\Step0_CompleteModel')) 
addpath(fullfile(rootFolder,'\Models\Step1_BuildLogic_Link')) 
addpath(fullfile(rootFolder,'\Models\Step2_ReqBasedTesting_ModelCoverage')) 
addpath(fullfile(rootFolder,'\Models\Step3_TestCaseGeneration')) 
addpath(fullfile(rootFolder,'\Models\Step4_SILSignalComparison')) 
addpath(fullfile(rootFolder,'\Models\Step5_GenerateCodeReuseComponent')) 
