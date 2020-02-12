function runCodeInspection(modelName, top)
% Inspect the code generated from a model for equivalence. Treat the model
% as a referenced model if the argument top is false. Otherwise, treat it
% as a top-level model.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Code Inspector license.
if license('test', 'simulink_code_inspector')
    if top
        verifySrcCode2Model(modelName, 'IncludeAllChildMdls');
    else
        verifySrcCode2Model(modelName, 'TreatAsMdlRef');
    end
else
    web(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_reviews', modelName, [modelName, '_report.html']), '-new');
    warndlg(['License for Simulink Code Inspector not found. ', ...
        'An existing Code Inspection report is opened instead.'], ...
        'License Not Found');
end
