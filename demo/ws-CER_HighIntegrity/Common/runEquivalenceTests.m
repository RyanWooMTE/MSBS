function runEquivalenceTests
%% Setup and run test harness(es)
% run SignalBuilder "all tests" in Normal and SIL mode and compare results in Signal
% Inspector that opens automatically

bdclose all

eqharness = findit('Type', 'EquivalenceTestingModel', pwd);
if isempty(eqharness)
    disp('No harness found, availables harnesses are:');
    allharnesses = findit('Type', 'EquivalenceTestingModel', [getProjectRoot() '\Certif\' certiffolder '\Model']);
    for idx = 1:length(allharnesses)
        disp([' - ' allharnesses{idx}]);
    end
else
    for idx=1:length(eqharness)
        [~, name ,~] = fileparts(eqharness{idx});
        mdl = strrep(name, '_eqHarness_req', '');

        [runsOK, reports]=run_coverage_tests(mdl);
        assignin('base', 'mdl', mdl);
        assignin('base', 'runsOK', runsOK);
        assignin('base', 'reports', reports);

        eqReportName = fullfile(getWorkProducts,'CodeTest',[mdl,'_equivalenceTestReport.html']);
        rFull = report('EquivalenceTestReport',['-o',eqReportName],'-quiet');

        [rPath,rName,rExt] = fileparts(rFull);
        fprintf(1,'View EquivalenceTest Report <a href = "matlab: web(''%s'')">%s%s</a>\n',rFull,rName,rExt);
        
        addWorkProduct(eqReportName,{certifname, 'Classification'},{'Report','Artifact'});
        modelCovReport = fullfile(getWorkProducts,'CodeTest',[mdl,'_summary_cov.html']);
        addWorkProduct(modelCovReport,{certifname, 'Classification'},{'Report','Artifact'});
        codeCovReport = fullfile(getWorkProducts,'Code','slprj','ert',mdl,'html',[mdl,'_codegen_rpt.html']);
        %addWorkProduct(codeCovReport,{certifname, 'Classification'},{'Report','Artifact'});
    end
    
    addWorkProduct(); % emit to projects
end
end
