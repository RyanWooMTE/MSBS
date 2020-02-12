function [runsOK,reports,details] = run_model_tests(mdl)
%RUN_MODEL_TESTS    Execute unit tests on a host machine.
%   RUN_MODEL_TESTS accepts up to two arguments. The first is the model
%   name. The second, optional argument, is the filename of a spreadsheet
%   containing existing unit test data. If specified, the existing test
%   data will be read in instead of the generated cases. The model must
%   generate tests with SLDV for this script to run.

%   Copyright 2012 The MathWorks, Inc.


if nargin ~= 1
    error('Expected run_model_tests(modelname)')
end
reports = {};
details = {};
%% Generate tests for model

% Start with Simulink in a clean state
bdclose('all')
reportFolder = fullfile(getWorkProducts(),'ModelTest');

harnessModel = [mdl,'_testHarness'];

folder = fileparts(which(mdl));
cd(fullfile(folder,'Tests'));
open_system(mdl)
open_system(harnessModel)
cd ..



% Apply settings and make testpoints
io = getModelIO(mdl);
% set_param(harnessModel, ...
%     'InspectSignalLogs','Off', ...
%     'SignalLabelMismatchMsg','none', ...
%     'SolverPrmCheckMsg','none', ...
%     'ModelReferenceSymbolNameMessage', 'none', ...
%     'RecordCoverage','off', ...
%     'CovModelRefEnable','Off');

blk = [harnessModel '/Inputs'];


% Clear the test data file by saving it with no data
description = 'This is the data file for test execution';
save(fullfile(reportFolder,[mdl,'_testdata']),'description');

runsOK = ones(size(signalbuilder(blk),2),1);
% Loop through test cases in Normal Mode
for m=1:size(signalbuilder(blk),2)
    
    % Clear result logging in each loop  
    ResultLogger.clear(); 
    
    if m == 2
        set_param(harnessModel,'UpdateModelReferenceTargets','AssumeUpToDate', ...
            'CheckModelReferenceTargetMessage','none');
    end
    
    fprintf(['### SIM:TEST CASE ' num2str(m) '    '])
    % Set active group
    signalbuilder(blk,'activegroup',m)
    
    % Setup coverage tests for cvsim
    cvto1 = cvtest(harnessModel);
    cvto2 = cvtest(mdl);
    cvto2.settings.mcdc = 0;
    cvto2.settings.condition = 1;
    cvto2.settings.decision = 1;
    cvtg = cv.cvtestgroup(cvto1,cvto2);
    cvdg{m} = cvsimref(harnessModel,cvtg); %#ok<*AGROW>
    cvdo{m} = cvdg{m}.get(mdl);
    %     sim(harnessModel);
    
    logsOut.unpack;
    try  %#ok<TRYNC>
        TestUnit.unpack;
    end
    resultlogs = ResultLogger.getLogs();
    
    % Optional ways of evaluating tests 
    if ~isempty(resultlogs.info)  
        % ResultLogger is being used 
        runsOK(m)  = (isempty(resultlogs.assert));  
        details{m} = ResultLogger.print('assert');
    else
        % ResultLogger not used
        % Equality is evaluated with explicit  
        for mm = 1:length(io.out)
            equalCondition = eval(['isequal(',[io.ref{mm},'.Data'],',',[io.sim{mm},'.Data'],');']);
            if ~equalCondition
                runsOK(m) = 0;
            end
        end
        details{m} = '';
    end
    
    [~, ~, signalIDs]  = Simulink.sdi.createRun(['Test Case ',num2str(m)],'namevalue',{'logsOut'},{logsOut});
    reportName   = [mdl,'_Run',num2str(m),'_TestReport.html'];
    reports{m} = fullfile(reportFolder,reportName);
    metaDataOfInterest = [Simulink.sdi.SignalMetaData.SignalName ...
        Simulink.sdi.SignalMetaData.Line ...
        Simulink.sdi.SignalMetaData.BlockPath ...
        ];
    
    % Select signals for plotting
    for i = 1:length( signalIDs )
        signal = Simulink.sdi.getSignal(signalIDs(i));
        signal.checked = true;
    end
    
    Simulink.sdi.report('ReportOutputFile',reportName, ...
        'ReportOutputFolder',reportFolder, ...
        'ColumnsToReport', metaDataOfInterest, ...
        'PreventOverwritingFile', false ...
        );
    
    Simulink.sdi.clear;
    
    eval(['logsOut',num2str(m),'=logsOut;']);
    rname = [fullfile(reportFolder,mdl),'_testdata'];
    eval(['save ', rname,' -append logsOut',num2str(m)]);
    addWorkProduct([rname,'.mat'],{certifname,'Classification'},{'Data','Artifact'})
    if runsOK(m)
        fprintf('=== RUN %s OK      ',m);
    else
        fprintf('=== RUN %s FAILED  ',m);
    end
    fprintf('<a href = "matlab: web(''%s'')">Unit test report %u</a> ===\n',reports{m}, m);
end


% Coverage report
rname = fullfile(reportFolder,[mdl,'_summary_cov']);
cvhtml(rname,cvdo{:});
addWorkProduct([rname,'.html'],{certifname, 'Classification'},{'Report','Artifact'})
%cvsave(fullfile(reportFolder,[mdl,'_cvdata']),mdl);
currdir = pwd;
cd(reportFolder);
cvsave([mdl,'_cvdata'],cvdo{:});
cd(currdir);
addWorkProduct(fullfile(reportFolder,[mdl,'_cvdata.cvt']),{certifname,'Classification'},{'Data','Artifact'})

end


function io = getModelIO(mdl)
% in,out are the model under test input and output
% inp,sim,ref are the test stimuli, test output and reference signals
ip = find_system(mdl,'SearchDepth',1,'BlockType','Inport');
for idx=1:length(ip)
    io.in{idx} = get_param(ip{idx},'Name');
    io.inp{idx} = ['INP_',io.in{idx}];
end
op = find_system(mdl,'SearchDepth',1,'BlockType','Outport');
for idx=1:length(op)
    io.out{idx} = get_param(op{idx},'Name');
    io.sim{idx} = ['SIM_',io.out{idx}];
    io.ref{idx} = ['EXP_',io.out{idx}];
end
end
