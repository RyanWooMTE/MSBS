% Run SIL test cases for AHRS_Voter.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Test and Simulink Verification and Validation
% licenses.
if license('test', 'simulink_test') && license('test', 'sl_verification_validation')
    verifySrcCode2Reqs('AHRS_voter');
    if exist('slcov_output', 'dir')
        rmdir('slcov_output', 's');
    end
else % open the pre-existing report and post a warning
    open(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'executable_tests', 'AHRS_voter', 'host', 'high_level_tests', 'AHRS_voter_SIL_REQ_Based_Test_Report.pdf'));
    pause(1);
    web(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_coverages', 'AHRS_voter', 'high_level_tests', 'AHRS_voter_REQ_Based_Code_Coverage_Report.html'), '-new');
    warndlg(['License for Simulink Test or Simulink Verification and Validation not found. ', ...
        'Existing Simulink Test and Code Coverage reports are opened instead.'], ...
        'License Not Found');
end
