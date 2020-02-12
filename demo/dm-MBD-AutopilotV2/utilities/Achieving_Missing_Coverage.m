%% Save the coverage data in a file
cvsave('existingcov',covdata);

%% Finding Test Cases for the Missing Coverage
open_system('roll_ap');

opts = sldvoptions;
opts.IgnoreCovSatisfied = 'on';
opts.CoverageDataFile = 'existingcov.cvt';
% opts.ModelReferenceHarness = 'on';
% opts.TestSuiteOptimization = 'LongTestCases';

[status, fileNames] = sldvrun('roll_ap',opts,true);

%% Achieving the Missing Coverage
cvt = cvtest('roll_ap');
cvt.settings.decision = 1;
cvt.settings.condition = 1;
cvt.settings.mcdc = 1;

[~, covdata_missing] = sldvruntest('roll_ap', fileNames.DataFile, [], cvt);

%% Verifying 100% Model Coverage
totalCov = covdata + covdata_missing;
cvhtml('Coverage_Summary', totalCov);