function runModelAdvisorChecks(modelName)
% Check a model to find violations of modeling guidelines.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Verification and Validation license.
if license('test', 'sl_verification_validation')
    if strcmp(modelName, 'FCC')
        checkModelStds(modelName);
    else
        checkModelStds(modelName, 'TreatAsMdlRef');
    end
else
    open(fullfile(fileparts(which(modelName)), '..', 'verification', 'design_standard_checks', [modelName, '_SMS_Conformance_Report.pdf']));
    warndlg(['License for Simulink Verification and Validation not found. ', ...
        'An existing Model Advisor report is opened instead.'], ...
        'License Not Found');
end
