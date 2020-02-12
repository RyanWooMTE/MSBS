function [runsOK,reports] = run_coverage_tests(mdl)
%RUN_COVERAGE_TESTS    Execute unit tests on a host machine.
%   RUN_COVERAGE_TESTS accepts up to two arguments. The first is the model
%   name. The second, optional argument, is the filename of a spreadsheet
%   containing existing unit test data. If specified, the existing test
%   data will be read in instead of the generated cases. The model must
%   generate tests with SLDV for this script to run.

%   Copyright 2011 The MathWorks, Inc.  

if nargin < 1 
    error('Expected run_coverage_tests(modelname)')
end


% Start with Simulink in a clean state
bdclose('all')
reportFolder = fullfile(getWorkProducts(),'CodeTest');

% Test harness model should be 
harnessModel = [mdl,'_eqHarness'];
load_system(mdl);
open_system(harnessModel);
% Get the signal builder block
blk = [harnessModel '/Inputs'];
% Get the model reference block
[~, modelBlks] = find_mdlrefs(harnessModel);
subsys = modelBlks{1};



% Test to see if we already have an ert SIL target and delete if so. This
% will force a rebuild of the SIL component and reset the coverage data
bi = RTW.getBuildDir(mdl);
bdir = fullfile(bi.CodeGenFolder,bi.ModelRefRelativeBuildDir);
if exist(bdir,'dir')
    rmdir(bdir,'s');
end


runsOK = ones(size(signalbuilder(blk),2),1);
% loop through test cases in Normal Mode 
for m=1:size(signalbuilder(blk),2)

    if m == 2
        set_param(harnessModel,'UpdateModelReferenceTargets','AssumeUpToDate', ...
            'CheckModelReferenceTargetMessage','none');
    end
        
    disp(['### SIM:TEST CASE ' num2str(m) ' ###'])
    % Set active group
    signalbuilder(blk,'activegroup',m)
    % setup coverage tests for cvsim
    cvto1 = cvtest(harnessModel);
    cvto2 = cvtest(mdl); 
    cvto2.settings.mcdc = 0;
    cvto2.settings.condition = 1;
    cvto2.settings.decision = 1;
    cvtg = cv.cvtestgroup(cvto1,cvto2);
    cvdg{m} = cvsimref(harnessModel,cvtg); %#ok<*AGROW>
    cvdo{m} = cvdg{m}.get(mdl);
    %SIMlogsOut(m)=logsOut;
    SIMID(m) = Simulink.sdi.createRun(['SIM_',num2str(m)],'namevalue',{'logsOut'},{logsOut});

    disp(['### PIL:TEST CASE ' num2str(m) ' ###'])
    % Put the model reference block into SIL mode
    set_param(subsys,'SimulationMode','Software-in-the-loop (SIL)');
    % Original model gets touched during this process for 12a. Have verified
    % with an xml comparison that no actual changes are being made.
    set_param(mdl,'Dirty','off')
    sim(harnessModel);
    %PILlogsOut(m)=logsOut;
    PILID(m) = Simulink.sdi.createRun(['PIL_',num2str(m)],'namevalue',{'logsOut'},{logsOut});
    
    %% Compare the runs
    difference(m) = Simulink.sdi.compareRuns(SIMID(m), PILID(m));
    
    %% Report on the run comparison
    % Specify columns to include in the report
    metaDataOfInterest = [Simulink.sdi.SignalMetaData.Result, ...
                        Simulink.sdi.SignalMetaData.BlockPath1, ...
                        Simulink.sdi.SignalMetaData.RelTol1];

    reportName   = [mdl,'_Run',num2str(m),'_EqReport.html'];
    reports{m} = fullfile(reportFolder,reportName);

    Simulink.sdi.report('LaunchReport',false, ...
                        'ReportOutputFile',reportName, ... 
                        'ReportOutputFolder',reportFolder, ...
                        'PreventOverwritingFile',false, ...
                        'ReportToCreate', 'Compare Runs', ...
                        'ColumnsToReport', metaDataOfInterest, ...
                        'SignalsToReport', 'ReportAllSignals' );
    Simulink.sdi.clear;

    % Add report to artefacts
    addWorkProduct(fullfile(reportFolder,reportName),{certifname,'Classification'},{'Report','Artifact'});

    for mm = 1:difference(m).count
        if ~difference(m).getResultByIndex(mm).match               
            runsOK(m) = 0; 
        end
    end
    % set back to Normal mode
    set_param(subsys,'SimulationMode','Normal');
    % Original model gets touched during this process for 12a. Have verified
    % with an xml comparison that no actual changes are being made.
    set_param(mdl,'Dirty','off')

    if runsOK(m)
        fprintf('=== RUN %s OK       ',m);
    else        
        fprintf('=== RUN %s FAILED   ',m);
    end
    fprintf(' <a href = "matlab: web(''%s'')">Equivalence test report %u</a> ===\n',fullfile(reportFolder,reportName), m);
end

% save artefacts 
reportName = [mdl,'_summary_cov'];
cvhtml(fullfile(reportFolder,reportName),cvdo{:});
addWorkProduct(fullfile(reportFolder,[reportName,'.html']),{certifname,'Classification'},{'Report','Artifact'});
cvsave(fullfile(reportFolder,[mdl,'_cvdata']),cvdo{:});
addWorkProduct(fullfile(reportFolder,[mdl,'_cvdata.cvt']),{certifname,'Classification'},{'Data','Artifact'});

end

