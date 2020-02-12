function generateTests(modelName)
% Generate test cases for a model. If a cvt file containing coverage data
% is found, objectives for existing coverages are ignored.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Design Verifier license.
if license('test', 'simulink_design_verifier')
    genLowLevelTests(modelName, 'AbsTol', 1e-6, 'RelTol', 1e-3);
else
    open(fullfile(fileparts(which(modelName)), '..', 'verification', 'simulation_tests', 'low_level_tests', [modelName, '_Test_Generation_Report.pdf']));
    warndlg(['License for Simulink Design Verifier not found. ', ...
        'An existing Test Case Generation report is opened instead.'], ...
        'License Not Found');
end
