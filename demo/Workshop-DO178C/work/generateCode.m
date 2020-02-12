function generateCode(modelName, top)
% Generate embedded code from a model. Treat the model as a referenced
% model if the argument top is false. Otherwise, treat it as a top-level
% model.

% Copyright 2016 The MathWorks, Inc.

% Check for Embedded Coder license.
if license('test', 'rtw_embedded_coder')
    if top
        genSrcCode(modelName);
    else
        genSrcCode(modelName, 'TreatAsMdlRef');
    end
else
    if top
        web(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), [modelName, '_ert_rtw'], 'html', [modelName, '_codegen_rpt.html']), '-new');
    else
        web(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), 'slprj', 'ert', modelName, 'html', [modelName, '_codegen_rpt.html']), '-new');
    end
    warndlg(['License for Embedded Coder not found. ', ...
        'An existing Code Generation report is opened instead.'], ...
        'License Not Found');
end
