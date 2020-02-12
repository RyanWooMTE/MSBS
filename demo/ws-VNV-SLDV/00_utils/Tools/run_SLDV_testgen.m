function run_SLDV_testgen(mdl,opts)
% SLDV�e�X�g�������������s

%   Copyright 2012 The MathWorks, Inc. 

%% SLDV�ݒ�
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

%% SLDV���s
sldvrun(mdl,opts,true);

