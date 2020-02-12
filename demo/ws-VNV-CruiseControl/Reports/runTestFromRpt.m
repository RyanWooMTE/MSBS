function [slrg] = runTestFromRpt()

    try
        
        % slrg.modelName = UUT
        % slrg.harnessModel = harness model
        slrg.harnessModel = bdroot;
        slrg.modelName = get_param([slrg.harnessModel, '/Test Unit'], 'ModelName');
        slrg.title = 'Functional Test';

        % clear any existing reports & runs in SDI
        Simulink.sdi.clear;

        % specify sig builder block
        slrg.blkSB = find_system(slrg.harnessModel,'SearchDepth',1, ...
            'MaskType','Sigbuilder block');
        slrg.blkSB = char(slrg.blkSB);

        % get number of tests
        [~, ~, ~, slrg.nameTC] = signalbuilder(slrg.blkSB);
        numCases = numel(slrg.nameTC);
        slrg.numTC = numCases;
        slrg.simOut = cell(numCases,1); % initialized output struct
        slrg.pass = zeros(numCases,1);
        
        % set data logging for report
        set_param(slrg.harnessModel,'ReturnWorkspaceOutputs','on');
        open_system(slrg.modelName);
        inpBlk = find_system(slrg.modelName, 'SearchDepth', 1, ...
            'BlockType', 'Inport');
        for idx = 1:numel(inpBlk)
            ph = get_param(inpBlk{idx},'PortHandles');
            set_param(ph(1).Outport,'DataLogging','on');
        end
        dl = get_param(slrg.harnessModel,'DataLoggingOverride');
        dlSave = dl;
        dl.LoggingMode = 'LogAllAsSpecifiedInModel';
        set_param(slrg.harnessModel,'DataLoggingOverride',dl);

        for idx=1:numCases

            testName = slrg.nameTC{idx};
            disp(['Running Test #' num2str(idx) ':  ' testName]);
            % select sig builder test case
            signalbuilder(slrg.blkSB, 'activegroup', idx);

            % run simulation / collect data / measure coverage
            cvTestObj = cvtest(slrg.harnessModel);
            [cvData, simOut] = cvsim(cvTestObj);
            slrg.covOut{idx} = cvData;
            slrg.simOut{idx} = simOut;

            % compare exp to actual for test verdict
            %[slrg, runResult(idx)] =  compareExpToActualInSDI(slrg,idx);
            [slrg] =  compareExpToActualInSDI(slrg,idx);

        end   
        
        % reset model data logging
        set_param(slrg.harnessModel,'ReturnWorkspaceOutputs','off');
        for idx = 1:numel(inpBlk)
            ph = get_param(inpBlk{idx},'PortHandles');
            set_param(ph(1).Outport,'DataLogging','off');
        end
        set_param(slrg.harnessModel,'DataLoggingOverride',dlSave);

        % set status flags
        slrg.runFlg = 1;
        slrg.allStatus = all(slrg.pass==1);
        slrg.failedTC = slrg.nameTC(slrg.pass==0);
        
    catch
        
        slrg.runFlg = 0;
        
    end
    
end

%%
%function [slrg, pass] = compareExpToActualInSDI(slrg,idx)
function [slrg] = compareExpToActualInSDI(slrg,idx)

    testName = slrg.nameTC{idx};
    logsout = slrg.simOut{idx}.get('logsout');
    outData = Simulink.SimulationData.Dataset;
    outDataExp = Simulink.SimulationData.Dataset;

    % group the data in a new run for SDI compare function
    for signalIndex = 1 : logsout.numElements
        
        signalObj = logsout.getElement(signalIndex);

        if strcmpi('EXP_', signalObj.Name(1:4))
            outDataName = signalObj.Name(5:end);
            % create a new instance
            Exp_signalObj = Simulink.SimulationData.Signal;
            Exp_signalObj.Name = outDataName;
            Exp_signalObj.BlockPath = signalObj.BlockPath;
            Exp_signalObj.PortType = signalObj.PortType;
            Exp_signalObj.PortIndex = signalObj.PortIndex;
            Exp_signalObj.Values = signalObj.Values;
            
            outDataExp = outDataExp.addElement(Exp_signalObj);

            for i = 1 : logsout.numElements
                obj = logsout.getElement(i);

                if strcmp(obj.Name, outDataName)
                    outDataElement = timeseries(obj.Values.Data, obj.Values.Time);
                    outDataElement.Name = outDataName;
                    outData = outData.addElement(outDataElement);
                end
            end
        end
    end
    
    %slrg.simOut{idx} = outData;
    slrg.EOlogsig{idx} = outDataExp;

    runID_out = Simulink.sdi.createRun([slrg.modelName ' : ' testName ' - Outputs'], 'vars', outData);
    runID_exp = Simulink.sdi.createRun([slrg.modelName ' : ' testName ' - Expected Outputs'], 'vars', outDataExp);
    diff = Simulink.sdi.compareRuns(runID_out, runID_exp);

    % determine test verdict
    slrg.pass(idx) = 1;
    verdict = 'PASS';
    disp('------------------------');
    for i=1:diff.count
        diffObj = diff.getResultByIndex(i);
        sig1 =  Simulink.sdi.getSignal(diffObj.signalID1).signalLabel;
        sig2 =  Simulink.sdi.getSignal(diffObj.signalID2).signalLabel;
        if ~diffObj.match
            slrg.pass(idx) = 0;
            verdict = 'FAIL';
            disp(['FAIL: ' sig1 ' vs ' sig2]);
        end
    end
    disp([testName ' ' verdict]);
    disp('------------------------');

    % clear out the compare runs
    Simulink.sdi.deleteRun(runID_exp);
    Simulink.sdi.deleteRun(runID_out);

    % delete "run comparison" run
    compID = Simulink.sdi.getRunIDByIndex(Simulink.sdi.getRunCount);
    Simulink.sdi.deleteRun(compID);

end