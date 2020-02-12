function run_SLDV_testgen(mdl,opts)
% SLDVテスト自動生成を実行

%   Copyright 2012 The MathWorks, Inc. 

%% SLDV設定
opts.Mode = 'TestGeneration';
if verLessThan('SLDV','2.0')
    opts.TestSuiteOptimization = 'LargeModel';
else
    opts.TestSuiteOptimization = 'CombinedObjectives (Nonlinear Extended)';
end
opts.ModelCoverageObjectives = 'MCDC';
opts.SaveHarnessModel = 'on';
opts.SaveExpectedOutput = 'on';
opts.SaveReport = 'on';
opts.DisplayReport = 'on';
opts.MakeOutputFilesUnique = 'off';

%% SLDV実行
sldvrun(mdl,opts,true);

