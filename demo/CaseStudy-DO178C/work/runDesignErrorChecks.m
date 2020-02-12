function runDesignErrorChecks(modelName, mode)
% Check a model to find potential design errors. Perform dead logic
% detection if the argument mode is 'DeadLogic'. Otherwise, perform other
% design error detection.

% Copyright 2016 The MathWorks, Inc.

% Check for Simulink Design Verifier license.
if license('test', 'simulink_design_verifier')
    if strcmp(mode, 'DeadLogic')
        detectDesignErrs(modelName, 'DetectDeadLogic');
    else
        detectDesignErrs(modelName);
    end
    if exist('rtwgen_tlc', 'dir')
        rmdir('rtwgen_tlc', 's');
    end
else
    if strcmp(mode, 'DeadLogic')
        open(fullfile(fileparts(which(modelName)), '..', 'verification', 'design_error_detections', 'dead_logic', [modelName, '_Dead_Logic_Detection_Report.pdf']));
        warndlg(['License for Simulink Design Verifier not found. ', ...
            'An existing Dead Logic Detection report is opened instead.'], ...
            'License Not Foun');
    else
        open(fullfile(fileparts(which(modelName)), '..', 'verification', 'design_error_detections', 'design_error', [modelName, '_Design_Error_Detection_Report.pdf']));
        warndlg(['License for Simulink Design Verifier not found. ', ...
            'An existing Design Error Detection report is opened instead.'], ...
            'License Not Foun');
    end
end
