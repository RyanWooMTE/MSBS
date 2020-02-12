function generateSDD(modelName)
% Generate an SDD report for a model.

% Copyright 2016 The MathWorks, Inc.

% Check for MATLAB Report Generator and Simulink Report Generator licenses.
if license('test', 'matlab_report_gen') && license('test', 'simulink_report_gen')
    genSDD(modelName);
else
    open(fullfile(fileparts(which(modelName)), 'documents', [modelName, '_SDD.pdf']));
    warndlg(['License for MATLAB Report Generator or Simulink Report Generator not found. ', ...
        'An existing Software Design Description report is opened instead.'], ...
        'License Not Found');
end
