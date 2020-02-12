%% Run Equivalence Tests for models in the current folder 
% SIL/PIL is used for eqivalence testing of the generated code versus the
% tests run in simulation. Reports generated are
% * Equivalence Test Report containing signal comparison
% * Model coverage report 
% * Code coverage report 
%
% The complete workflow require a manual review of the coverage (model vs
% code) to avoid unintended functionality. This should be placed in a
% separate report referencing the above artifacts. 
%
function s7_runEquivalenceTests

% call common utility script  
runEquivalenceTests(); 

