% Hydraulic actuator tuning example
 
% Copyright 2019 The MathWorks, Inc.

% first, test for a Simulink Control Design, Control System Toolbox and
% Robust Control Toolbox licenses
if license('test','simulink_control_design')&&...
        license('test','control_toolbox')&&license('test','robust_toolbox')
    
    % bring command window to the front
    commandwindow;
    
    ST0 = slTuner('act_loop_Sdomain','PID Controller');
    ST0.OperatingPoints = 0.2; %set time point such that valve is open
    addPoint(ST0,'act-ref');   % setpoint commands
    addPoint(ST0,'pos');       % corresponding outputs
    addPoint(ST0,{'cmd','pos'});
    
    % Less than 5% mismatch with reference model 1/(s+1)
    TrackReq = TuningGoal.StepTracking('act-ref','pos',0.0159,10);
    TrackReq.RelGap = 0.05;
    
    % Gain and phase margins at plant inputs and outputs
    MarginReq1 = TuningGoal.Margins('cmd',5,40);
    MarginReq2 = TuningGoal.Margins('pos',5,40);
    
    % Limit on decay, damping, frequency
    PoleReq = TuningGoal.Poles(0,0,inf);
    
    AllReqs = [TrackReq,MarginReq1,MarginReq2,PoleReq];
    [ST1,fSoft,~,Info] = systune(ST0,AllReqs);
    
    T1 = getIOTransfer(ST1,'act-ref','pos');
    opt = stepDataOptions('StepAmplitude',0.02);
    step(T1,1,opt);
    
    figure('Position',[100,100,900,474]);
    viewGoal(AllReqs,ST1);
    
    showTunable(ST1);
    
    % Clean up
    bdclose('all');
    clearvars;
    
else % open the pre-existing report and post a warning
    % Get the ProjectManager.
    prj = simulinkproject;
    prjRoot = prj.RootFolder;
    open(fullfile(prjRoot, 'ARP_03_SystemArchitecture', 'validation', 'Act-Tuning-Report.pdf'));
    warndlg(['There is a license missing for Simulink Control Design '...
        'or Control System Toolbox or Robust Control Toolbox, a ' ...
        'pre-existing tuning report has been opened'],...
        'Missing Product License');
end

