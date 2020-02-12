function runTest(mdlname)

load_system(mdlname)

% specify sig builder block
blkSB = [mdlname '/Inputs'];

% clear any existing reports & runs in SDI
%clearOldReports();
Simulink.sdi.clear;

% get number of tests
[~, ~, ~, groupnames] = signalbuilder(blkSB);
numCases          = numel(groupnames);
simOut(numCases)  = Simulink.SimulationOutput; % initialized output struct
runID = zeros(1,numCases);

    for idx=1:numCases
        disp(['Running Test #' num2str(idx) ':  ' groupnames{idx}]);
        % select sig builder test case
        signalbuilder(blkSB, 'activegroup', idx);
        % run simulation / collect data
        simOut(idx) = sim(mdlname, 'SimulationMode', 'normal');                 %#ok<PFOUS>
        logsout = simOut(idx).get('logsout');
        
        [report(idx).result, report(idx).testCase] =  ...
            createCompareReportFromSDI(mdlname,logsout,groupnames{idx});

    end   
    
    unitName = get_param([mdlname '/Test Unit'], 'ModelName');
    createTestReportPF(unitName,report);
    
end

%%
function [pass , reportName] = createCompareReportFromSDI(harness,logsout,testName)

    unitName = get_param([harness '/Test Unit'], 'ModelName');

    metaDataOfInterest = [Simulink.sdi.SignalMetaData.Result, ...
                        Simulink.sdi.SignalMetaData.SignalName1, ...
                        Simulink.sdi.SignalMetaData.RelTol1, ...
                        Simulink.sdi.SignalMetaData.AbsTol1];

    outData = Simulink.SimulationData.Dataset;
    outDataExp = Simulink.SimulationData.Dataset;

    % group the data in a new run for SDI compare function
    for signalIndex = 1 : logsout.numElements
        
        %signalID = runObj.getSignalIDByIndex(signalIndex);
        %signalObj = runObj.getSignal(signalID);
        signalObj = logsout.getElement(signalIndex);

        if strcmpi('EXP_', signalObj.Name(1:4))
            outDataName = signalObj.Name(5:end);
            outDataExpElement = timeseries(signalObj.Values.Data, signalObj.Values.Time);
            outDataExpElement.Name = outDataName;
            outDataExp = outDataExp.addElement(outDataExpElement);

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


    runID_out = Simulink.sdi.createRun([unitName ' : ' testName ' - Outputs'], 'vars', outData);
    runID_exp = Simulink.sdi.createRun([unitName ' : ' testName ' - Expected Outputs'], 'vars', outDataExp);
    diff = Simulink.sdi.compareRuns(runID_out, runID_exp);


    % determine test verdict
    pass = 1;
    verdict = 'PASS';
    disp('------------------------');
    for i=1:diff.count
        diffObj = diff.getResultByIndex(i);
        sig1 =  Simulink.sdi.getSignal(diffObj.signalID1).signalLabel;
        sig2 =  Simulink.sdi.getSignal(diffObj.signalID2).signalLabel;
        if ~diffObj.match
            pass = 0;
            verdict = 'FAIL';
            disp(['FAIL: ' sig1 ' vs ' sig2]);
        end
    end
    disp([testName ' ' verdict]);

    disp('------------------------');
    testName_noSpaces = regexprep(regexp(testName,'[^:]+$','match'),' ','_');
    %testName_noSpaces = strrep(testName, ' ', '_');

    reportName = [unitName '_' char(testName_noSpaces) '.html'];

    Simulink.sdi.report('ReportToCreate', 'Compare Runs', ...
                        'ColumnsToReport', metaDataOfInterest, ...
                        'ReportOutputFile', reportName, ...
                        'PreventOverwritingFile', false, ...,
                        'LaunchReport', false, ...
                        'SignalsToReport', 'ReportAllSignals');

    % clear out the compare runs
    Simulink.sdi.deleteRun(runID_exp);
    Simulink.sdi.deleteRun(runID_out);

    % delete "run comparison" run
    compID = Simulink.sdi.getRunIDByIndex(Simulink.sdi.getRunCount);
    Simulink.sdi.deleteRun(compID);

end

%%
function createTestReportPF(unitName,report)

    % Get everything in report folder
    reportFolder = fullfile(pwd, 'slprj', 'sdi');

    contentList = ls(reportFolder);
    contentListSize = size(contentList);

    reportList = {};
    nReports = 0;

    % Extract only reports for specified unit
    for i = 1 : contentListSize(1)
        [folder, name, ext] = fileparts(contentList(i,:)); %#ok<ASGLU>
        ext = deblank(ext);
        if ( strcmpi(ext, '.html') & strfind(name, unitName) ) %#ok<AND2>
            nReports = nReports + 1;
            reportList{nReports} = name; %#ok<AGROW>
        end
    end

    % Generate html menu file
    fid = fopen([unitName '_TestMenu.html'], 'w');
    fprintf(fid, '<HTML>\n');
    fprintf(fid, '<HEAD>\n');
    fprintf(fid, '<TITLE>Menu</TITLE>\n');
    fprintf(fid, '</HEAD>\n');
    fprintf(fid, '<BODY link="#005fce" alink="#005fce" vlink="#004aa0">\n');
    fprintf(fid, '<font face="arial" size="2">\n');

    linkStr = ' ';
    for i = 1 : nReports
        nameStr = reportList{i};
        linkStr = ['slprj' filesep 'sdi' filesep nameStr '.html'];
        for j = 1:length(report)
            name = regexp(report(j).testCase,'\.','split');
            name = name(1);
            if strcmp(nameStr,name)
                break;
            end
        end
        if report(j).result
            fontColor = '#009900';
        else
            fontColor = '#990000';
        end
        fprintf(fid, '<a href="%s" style="color:%s"target="main">%s</a><br><br>\n', linkStr,fontColor, nameStr);
    end

    fprintf(fid, '</BODY>\n');
    fprintf(fid, '</HTML>\n');
    fclose(fid);

    % Generate html frame/main file
    fid = fopen([unitName '_TestReport.html'], 'w');
    fprintf(fid, '<HTML>\n');
    fprintf(fid, '<HEAD>\n');
    fprintf(fid, '<TITLE>%s Test Report</TITLE>\n', unitName);
    fprintf(fid, '</HEAD>\n');
    fprintf(fid, '<FRAMESET cols="220, *">\n');
    fprintf(fid, '  <FRAME name="left" src="%s_TestMenu.html">\n', unitName);
    fprintf(fid, '  <FRAME name="main" src="%s">\n', linkStr);
    fprintf(fid, '</FRAMESET>\n');
    fprintf(fid, '</HTML>\n');
    fclose(fid);

    % Open generated report
    web([unitName '_TestReport.html'], '-new')
    
end
    