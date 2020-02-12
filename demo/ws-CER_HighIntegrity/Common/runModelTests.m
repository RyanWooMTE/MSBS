function runModelTests
%% Batch run unit tests for the Models in current directory
%
% For each models 'foo', it looks for the associated test harness
% 'foo_testHarness' and executes it.
%
% Test data is in the signal builder inside the test harness.
% The test data contains both model input s and the expected output.
% The run_model_tests functions verifies that the model produces the expected output
% and reports in 'runsOK' and 'reports'.

% Note current dir to return to the same place at the end.
currdir = cd;

% Get the list of validation models under the current directory.
harnesslist = findit('Type', 'ValidationModel', currdir);

if ~isempty(harnesslist)
    
    for idx = 1:length(harnesslist)
        [mpath, harnessmdl] = fileparts(harnesslist{idx});
        mdl = strrep(harnessmdl,'_testHarness', '');
        
        cd([mpath '\..']);
        
        % Run the simulation
        [runsOK, reports,details] = run_model_tests(mdl);
        assignin('base', 'mdl', mdl);
        assignin('base', 'runsOK', runsOK);
        assignin('base', 'reports', reports);
        assignin('base', 'details', details);
        
        % Run the report execution
        testsPath = fullfile(getWorkProducts(),'ModelTest');
        rFull = report('ModelTestReport',['-o',fullfile(testsPath,[mdl,'_UnitTestReport'])],'-quiet','-noview');
        [rPath,rName,rExt] = fileparts(rFull);
        
        fprintf(1,'View ModelTest Report <a href = "matlab: web(''%s'')">%s%s</a>\n',rFull,rName,rExt);
        addWorkProduct(rFull,{certifname ,'Classification'},{'Report','Artifact'})
        
    end
    
    bdclose all
    
    %% Emit to SL Projects
    addWorkProduct();
    
    
else
    disp('No test harness models found here');
end

% Go back to original directory.
cd(currdir);

end
