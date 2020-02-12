function createEquivTestReport(harness, varargin)

    if ~strcmp(get_param(harness,'SimulationStatus'),'stopped')
        disp('ERROR!  createEquivTestReport:  Simulation must be stopped to run this report');
        return;
    end
    
    if nargin>1
        unitName = varargin{1};
    else
        unitName = get_param([harness '/Test Unit'], 'ModelName');
    end
    if nargin>2
        runsPerSimMode = varargin{2};
    else
        runsPerSimMode = Simulink.sdi.getRunCount/2;
    end
    
    runID = zeros(2*runsPerSimMode,1);
    for i=1:numel(runID)
        runID(i) = Simulink.sdi.getRunIDByIndex(i);
    end
    
    for idx=1:runsPerSimMode
    
        % compare actual vs expected, and create report from SDI repository
        [report(idx).result, report(idx).testCase]  = ...
            createEquivReportFromSDI(unitName,runID(idx),...
            runID(idx+runsPerSimMode));
        
    end

    % get unit under test and open test report
    
    createEquivReportPF(unitName,report);

end


%%
function [pass,reportName] = createEquivReportFromSDI(unitName,runID1,runID2)

    metaDataOfInterest = [Simulink.sdi.SignalMetaData.Result, ...
                        Simulink.sdi.SignalMetaData.SignalName1, ...
                        Simulink.sdi.SignalMetaData.RelTol1, ...
                        Simulink.sdi.SignalMetaData.AbsTol1];

    runObj = Simulink.sdi.getRun(runID1);
    testName = runObj.name;
    
    diff = Simulink.sdi.compareRuns(runID2, runID1);

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
            break;
        end
    end
    disp([testName ' ' verdict]);

    disp('------------------------');
    runNum = sscanf(testName,'Run %d:');
    testName_noSpaces = regexprep(regexp(testName,'[^:]+$','match'),' ','_');
    reportName = [unitName char(testName_noSpaces) '.html'];
    reportName = sprintf('Run_%02d_%s',runNum,reportName);
    
    Simulink.sdi.report('ReportToCreate', 'Compare Runs', ...
                        'ColumnsToReport', metaDataOfInterest, ...
                        'ReportOutputFile', reportName, ...
                        'PreventOverwritingFile', false, ...,
                        'LaunchReport', false, ...
                        'SignalsToReport', 'ReportAllSignals');

    % delete "run comparison" run
    %compID = Simulink.sdi.getRunIDByIndex(Simulink.sdi.getRunCount);
    %Simulink.sdi.deleteRun(compID);

end


%%
function createEquivReportPF(unitName,report)

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