% Run simulation test cases for AHRS_Voter.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Test and Simulink Verification and Validation
% licenses.
if license('test', 'simulink_test') && license('test', 'sl_verification_validation')
    verifyModel2Reqs('AHRS_voter');
    if exist('slcov_output', 'dir')
        rmdir('slcov_output', 's');
    end
else
    open(fullfile(fileparts(which('AHRS_voter')), '..', 'verification', 'simulation_tests', 'high_level_tests', 'AHRS_voter_REQ_Based_Test_Report.pdf'));
    pause(1);
    web(fullfile(fileparts(which('AHRS_voter')), '..', 'verification', 'model_coverages', 'high_level_tests', 'AHRS_voter_REQ_Based_Model_Coverage_Report.html'), '-new');
    warndlg(['License for Simulink Test or Simulink Verification and Validation not found. ', ...
        'Existing Simulink Test and Model Coverage reports are opened instead.'], ...
        'License Not Found');
end
