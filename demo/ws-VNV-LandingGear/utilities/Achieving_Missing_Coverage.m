%% Model Setting
model = 'LandingGearMode';

%% Save the coverage data in a file
cvsave('existingcov',covdata);

%% Finding Test Cases for the Missing Coverage

opts = sldvoptions;
opts.IgnoreCovSatisfied = 'on';
opts.CoverageDataFile = 'existingcov.cvt';
% opts.SaveHarnessModel = 'on';
% opts.HarnessModelFileName = 'second_harness';

[status, fileNames] = sldvrun(model,opts,true);

%% Achieving the Missing Coverage
cvt = cvtest(model);
cvt.settings.decision = 1;
cvt.settings.condition = 1;
cvt.settings.mcdc = 1;

[~, covdata_missing] = sldvruntest(model, fileNames.DataFile, [], cvt);

%% Verifying 100% Model Coverage
cvhtml('Coverage_Summary', covdata, covdata_missing);
