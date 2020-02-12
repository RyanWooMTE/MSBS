function generate_tests(mdl)
%GENERATE_TESTS    Execute unit tests on a host machine.
%   GENERATE_TESTS accepts a model as argument, it will generate tests to
%   extend an existing test harness for the model

%   Copyright 2011 The MathWorks, Inc.  

if nargin < 1 
    error('Expected generate_tests(modelname)')
end

%% Generate tests for model

% Start with Simulink in a clean state
bdclose('all')
reportFolder = fullfile(getWorkProducts(),'CodeTest');

open_system(mdl)
opts = sldvoptions(mdl);
opts.DisplayReport = 'off';
opts.HarnessModelFileName = fullfile(reportFolder,[mdl,'_eqHarness_cov']);
opts.OutputDir = reportFolder;
opts.DataFileName = [mdl,'_sldvdata.mat'];
opts.ReportFileName = [mdl,'_SLDV.html'];
opts.MakeOutputFilesUnique = 'off';
opts.TestSuiteOptimization = 'LongTestcases'; % fewer longer tests will make PIL run faster 

% Use existing coverage data 
opts.IgnoreCovSatisfied = 'on';
opts.CoverageDataFile = fullfile(getWorkProducts(),'ModelTest',[mdl,'_cvdata.cvt']);

% Save options 
opts.SaveHarnessModel = 'off';                  % Save the harness as model file
opts.SaveReport = 'on';                         % Save the HTML report
[~,files] = sldvrun(mdl, opts);
set_param(mdl,'dirty','off');

%% Manipulate the generated harness for SIL testing

% Total tests model should be 
files.HarnessModel  = fullfile(reportFolder,[mdl,'_eqHarness']);
[~,harnessModel]=fileparts(files.HarnessModel);

% The requirements based tests in the ./Tests directory 
p = fileparts(which(mdl)); % path to model 
reqTestHarnessModel = fullfile(p,'Tests',[mdl,'_eqHarness_req']);

try  %#ok<TRYNC> If there is a harness model already, delete 
    delete(which(harnessModel));
end

% Extend with test generation if necessary 
if isempty(files.DataFile)
    % coverage was complete from the manual tests 
    sldvmergeharness(files.HarnessModel,{reqTestHarnessModel});

else
    % Extend coverage with test generation
    
    % Get the SLDV generated test cases
    load(files.DataFile);

    % Make the standard harness (could be sldv's or the custom one)
    covModel = sldvmakeharness(mdl,sldvData);
    sldvmergeharness(files.HarnessModel,{reqTestHarnessModel,covModel});
    save_system(harnessModel);
    addWorkProduct(which(harnessModel),{certifname,'Classification'},{'Data','Artifact'})
end


% Apply settings and make testpoints
inheritTestPoints(harnessModel,mdl); 
covSettings = get_param(mdl, 'CodeCoverageSettings');
covSettings.TopModelCoverage = 'off'; 
covSettings.ReferencedModelCoverage = 'on'; 
covSettings.CoverageTool = 'BullseyeCoverage'; 

set_param(harnessModel, ...
    'InspectSignalLogs','Off', ...
    'SignalLabelMismatchMsg','none', ...
    'SolverPrmCheckMsg','none', ...
    'ModelReferenceSymbolNameMessage', 'none', ...
    'RecordCoverage','off', ...
    'CovModelRefEnable','Off', ...
    'CodeCoverageSettings', covSettings );

% close model, leave harness open 
bdclose(mdl);
save_system(harnessModel);

end


function inheritTestPoints(harness,mdl)
    [~, modelBlock] = find_mdlrefs(harness);
    ph = get_param(modelBlock{1},'PortHandles');
    ip = find_system(mdl,'SearchDepth',1,'BlockType','Inport');
    op = find_system(mdl,'SearchDepth',1,'BlockType','Inport');
    for idx=1:length(ip)
        l = get_param(ph.Inport(idx),'Line');
        sp = get_param(l,'SrcPortHandle');
        name = get_param(ip{idx},'Name');
        set_param(sp,'Name',['INP_',name],'TestPoint','On','DataLogging','On');
    end
    op = find_system(mdl,'SearchDepth',1,'BlockType','Outport');
    for idx=1:length(op)
        name = get_param(op{idx},'Name');
        set_param(ph.Outport(idx),'Name',['SIM_',name],'TestPoint','on','DataLogging','On');
    end       
end
