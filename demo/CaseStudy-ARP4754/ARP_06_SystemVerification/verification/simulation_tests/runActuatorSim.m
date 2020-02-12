% Script to run hydrualic actutor loop simulation using Simulink Test
 
% Copyright 2019 The MathWorks, Inc.

% first, test for a Simulink Test and Simulink Verification and Validation
% licenses
if license('test','sl_verification_validation')&&...
        license('test','sl_verification_validation')
    
    % this brings the command window to the front and displays a message
    commandwindow;
    disp('Running simulation tests for Actuator Loop');
    
    % make sure simulation results directory exists and clear old results if
    % they exist
    resultsDir = fullfile(fileparts(which('ActLoopTest.mldatx')), 'simulation_results');
    if exist(resultsDir,'dir')
        if exist(fullfile(resultsDir,'ActuatorLoopTestReport.pdf'),'file')
            delete(fullfile(resultsDir,'ActuatorLoopTestReport.pdf'));
        end
        if exist(fullfile(resultsDir,'ActuatorLoopTestResults.mldatx'),'file')
            delete(fullfile(resultsDir,'ActuatorLoopTestResults.mldatx'));
        end
    else
        mkdir(resultsDir);
    end
    reportDir = fullfile(resultsDir, 'ActuatorLoopTestReport');
    if exist(reportDir, 'dir')
        rmdir(reportDir, 's');
    end

    % run simulations
    testobj = sltest.testmanager.load('ActLoopTest.mldatx');
    resultObj = testobj.run;
    
    % Save test results.
    sltest.testmanager.exportResults(resultObj, fullfile(resultsDir,'ActuatorLoopTestResults.mldatx'));
    
    % Clean up
    bdclose('all');
    if exist(reportDir, 'dir')
        rmdir(reportDir, 's');
    end
    clearvars;
    
else % open the pre-existing report and post a warning
    open(fullfile(resultsDir, 'ActuatorLoopTestReport.pdf'));
    pause(1);
    web(fullfile(resultsDir,'ActuatorLoop_Model_Coverage_Report.html'));
    warndlg(['There is a license missing for Simulink Test or '...
        'Simulink Verification and Validation, pre-existing  ' ...
        'simulation and coverage reports have been opened'],...
        'Missing Product License');
end