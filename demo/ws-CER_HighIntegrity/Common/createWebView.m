%% Create the webview for all models in the current folder
% The WebView is a html document that allows users to visualise the model
% in a Web browser (must support SVG).

% Check that the directory name starts with 'F_'
[~,p] = fileparts(pwd);
if ~strncmp('F_',p,2)
    error('Webview generation is only implemented for functions, please go to a "F_<function name>" directory') 
end

% Close all open models first
bdclose all

%% Generate the Web View
ModelReviewReport('-WebView',true)

%% Emit to SL Projects
addWorkProduct();

