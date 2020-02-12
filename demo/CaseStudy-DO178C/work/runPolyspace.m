function runPolyspace(modelName, mode, ref)
% Examine the code generated from a model for defects. Perform analysis
% using either Polyspace Bug Finder or Polyspace Code Prover if the
% argument mode is 'BugFinder' or 'CodeProver', respectively. Treat the
% model as a referenced model if the argument ref is true. Otherwise, treat
% it as a top-level model.
 
% Copyright 2016 The MathWorks, Inc.

% Check for Polyspace Bug Finder or Polyspace Code Prover license.
if strcmp(mode, 'CodeProver')
    lic_text ='polyspace_server_c_cpp';
else
    lic_text ='polyspace_bug_finder';
end

if license('test', lic_text)
    if strcmp(mode, 'CodeProver')
        if ref
            proveCodeQuality(modelName, 'TreatAsMdlRef');
        else
            proveCodeQuality(modelName, 'IncludeAllChildMdls');
        end
    else
        if ref
            checkCodeStds(modelName, 'TreatAsMdlRef')
        else
            checkCodeStds(modelName)
        end
    end
else
    if strcmp(mode, 'CodeProver')
        open(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_proving', modelName, [modelName, '_Code_Prover_Report.pdf']));
    else
        open(fullfile(Simulink.fileGenControl('get', 'CodeGenFolder'), '..', 'verification', 'code_standard_checks', modelName, [modelName, '_SCS_Conformance_Report.pdf']));
    end
    warndlg(['License for Polyspace Bug Finder or Polyspace Code Prover not found. ', ...
        'An existing Polyspace Code Verification report is opened instead.'], ...
        'License Not Found');
end
