function s5_CreateHarness
%% Batch run Data collection for the Models in current directory
%
% For each models 'foo', it looks for the associated test harness
% 'foo_testHarness' and executes it.
%
% The output of the simulation is captured and added as the expected
% output for 

[~,p] = fileparts(pwd); 
if ~strncmp('F_',p,2)
    error('Model test is only implemented for functions, please go to a "F_<function name>" directory') 
end

ModelList = getModelList();
if isempty(ModelList)
    error('There are no models to test');
end

mkdir('Tests')

for idx = 1:length(ModelList)
    
    [~,mdl] = fileparts(ModelList(idx).name); 
    if (~exist(fullfile('.','Tests',[mdl,'_testHarness.mdl']),'file') && ~exist(fullfile('.','Tests',[mdl,'_testHarness.slx']),'file'))
        disp(['There is no test harness for model ' mdl '  Skipping this model']);
        continue
    end
           
    testsPath = fullfile(getWorkProducts(),'ModelTest');

    [runsOK,reports] = run_model_cap(mdl);
    
    % run the report execution
    rFull = report('ModelTestReport',['-o',fullfile(testsPath,[mdl,'_UnitTestReport'])],'-quiet','-noview');
    [rPath,rName,rExt] = fileparts(rFull);

    fprintf(1,'View Test Report <a href = "matlab: web(''%s'')">%s%s</a>\n',rFull,rName,rExt);
    addWorkProduct(rFull,{certifname ,'Classification'},{'Report','Artifact'})

end

bdclose all
end


% run_model_cap
function [runsOK,reports] = run_model_cap(varargin)
%RUN_MODEL_TESTS    Execute unit tests on a host machine.
%   RUN_MODEL_TESTS accepts up to two arguments. The first is the model
%   name. The second, optional argument, is the filename of a spreadsheet
%   containing existing unit test data. If specified, the existing test
%   data will be read in instead of the generated cases. The model must
%   generate tests with SLDV for this script to run.

if nargin < 1 || nargin > 1
    error('Expected run_model_tests(modelname)')
end
reports = {};
%% Generate tests for model

% Start with Simulink in a clean state
bdclose('all')
reportFolder = fullfile(getWorkProducts(),'ModelTest');

mdl = varargin{1};
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
save(fullfile(reportFolder,[mdl,'_testdata']), 'description');

% Disable warning for TBD
warning('off', 'Simulink:Logging:LegacyModelDataLogsFormat');

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
    TestUnit.unpack;
    
    n=size(signalbuilder(blk),1)
    for mm = 1:length(io.out)
    [time, value] = signalbuilder([harnessModel, '/Inputs'], 'get', n-length(io.out)+mm, m);

    equalCondition = eval(['isequal(',[io.ref{mm},'.Data'],',',[io.sim{mm},'.Data'],');']);
        if ~equalCondition
            runsOK(m) = 0; 
            SIMID = Simulink.sdi.createRun(['Test Case ',num2str(m)],'namevalue',{'logsOut'},{logsOut});            
        end
    end

% Use this if using a dataset:
%     for elem = 1: logsOut.getLength
%         a = logsOut.get(logsOut.get(elem).Name).Values;
%     end 


    eval(['logsOut',num2str(m),'=logsOut;']);
    rname = [fullfile(reportFolder,mdl),'_testdata'];
    eval(['save ', rname,' -append logsOut',num2str(m)]);
    addWorkProduct([rname,'.mat'],{certifname,'Classification'},{'Data','Artifact'})
    if runsOK(m)
        fprintf('=== RUN %s OK ===\n',m);
    else        
        fprintf('=== RUN %s FAILED ===\n',m);
    end
%    fprintf('=== See <a href = "matlab: web(''%s'')">unit test report</a> ===\n',fullfile(reportFolder,reportName));
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
