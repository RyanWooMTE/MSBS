%% Create a single report linking reports create in step1 s1, s2 and s3.
% That report is a html document. It contains 
%  - A list of all subsystems
%  - Links
%    - link to SDD
%    - link to webview
%    - link to each MA check report.

% Check that the directory name starts with 'F_'
[~,p] = fileparts(pwd); 
if ~strncmp('F_',p,2)
    error('Model Review is only implemented for functions, please go to a "F_<function name>" directory') 
end

% Close all open models first
bdclose all


%% Model Review Document
ModelReviewReport('-MRD',true)

%% Emit to SL Projects
addWorkProduct();
