%% Batch run unit tests for the Models in current directory
%
% For each model 'foo', it looks for the associated test harness
% 'tests/foo_testHarness' and executes it.
%
% Test data is in the signal builder inside the test harness.
% The test data contains both model inputs and the expected output.
% The run_model_tests functions verifies that the model produces the expected output
% and reports in 'runsOK' and 'reports'.
function s5_runModelTests()

% call common utility script  
runModelTests();
