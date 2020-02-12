%% Run the Model Advisor check on models in the current folder
% The Model Advisor produces reports for each subsystem in the current
% folder. Reports are .mat file. In addition, an html report is also
% created.


% Check that the directory name starts with 'F_'
[~,p] = fileparts(pwd); 
if ~strncmp('F_',p,2)
    error('ModelAdvisor Check  is only implemented for functions, please go to a "F_<function name>" directory') 
end

% Close all open models first
bdclose all


%% Model Advisor Checks 
ModelReviewReport('-MACheck',true, '-MACheckExt','_traceability')

%% Emit to SL Projects
addWorkProduct(); 
