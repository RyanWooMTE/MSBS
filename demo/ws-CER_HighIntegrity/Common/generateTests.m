function generateTests()
%% Setup and generate tests (es)
% use SLDV to generate tests to extend test cases for existing test
% harnesses
% 

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

        % call out to the test generation for specific model
        generate_tests(mdl);
    end
    
    addWorkProduct(); % emit to projects
end
end
