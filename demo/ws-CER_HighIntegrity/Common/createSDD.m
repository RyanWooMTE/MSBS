%% Create the System Design Description for models in the current folder
% The SDD is a pdf file showing the Simulink model, every subsystem, their
% description and their model configuration information.

% Check that the directory name starts with 'F_'
[~,p] = fileparts(pwd);
if ~strncmp('F_',p,2)
    error('SDD Generation is only implemented for functions, please cd to a "F_<function name>" directory')
end

% Close all open models first
bdclose all


%% Generate System Design Description
ModelReviewReport('-SDD',true)

%% Emit to SL Projects
addWorkProduct();
