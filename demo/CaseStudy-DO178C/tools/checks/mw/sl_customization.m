% Copyright 2017 The MathWorks, Inc.
function sl_customization(cm)

    % Register custom checks
    cm.addModelAdvisorCheckFcn(@defineModelAdvisorChecks);
    cm.addModelAdvisorTaskFcn(@defineTaskAdvisor);

    % Define custom checks
    function defineModelAdvisorChecks
        
        mdladvRoot = ModelAdvisor.Root;
        
        % hisl_0003: Usage of Square Root blocks
        rec = ModelAdvisor.Check('mathworks.example.hisl_0003');
        rec.Title = 'Check usage of Square Root blocks';
        setCallbackFcn(rec, @hisl_0003, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0012: Usage of conditionally executed subsystems
        rec = ModelAdvisor.Check('mathworks.example.hisl_0012');
        rec.Title = 'Check usage of conditionally executed subsystems';
        setCallbackFcn(rec, @hisl_0012, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        fixAction = ModelAdvisor.Action;
        setCallbackFcn(fixAction, @hisl_0012_fix);
        fixAction.Name = 'Modify Sample Time Settings';
        fixAction.Description = 'Change Sample Time of blocks used in Conditionally executed subsystems to inherited(-1)';
        fixAction.Enable = false;
        setAction(rec, fixAction);
        mdladvRoot.register(rec);
        
        % hisl_0015: Usage of Merge blocks
        rec = ModelAdvisor.Check('mathworks.example.hisl_0015');
        rec.Title = 'Check usage of Merge blocks';
        setCallbackFcn(rec, @hisl_0015,'None','StyleOne');
        fixAction = ModelAdvisor.Action;
        setCallbackFcn(fixAction, @hisl_0015_fix);
        fixAction.Name = 'Modify Merge Block Settings';
        fixAction.Description = 'Turn off Allow Unequal Port Width Setting in merge blocks';
        fixAction.Enable = false;
        setAction(rec, fixAction);
        mdladvRoot.register(rec);
        
        % hisl_0019: Usage of Bitwise Operator block
        rec = ModelAdvisor.Check('mathworks.example.hisl_0019');
        rec.Title = 'Check usage of Bitwise Operator Block';
        setCallbackFcn(rec, @hisl_0019,'None','StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0022: Data type selection for index signals
        rec = ModelAdvisor.Check('mathworks.example.hisl_0022');
        rec.Title = 'Check data type selection for index signals';
        setCallbackFcn(rec, @hisl_0022,'None','StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0028: Usage of Reciprocal Square Root blocks
        rec = ModelAdvisor.Check('mathworks.example.hisl_0028');
        rec.Title = 'Check usage of Reciprocal Square Root blocks';
        setCallbackFcn(rec, @hisl_0028, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0031: Model file names
        rec = ModelAdvisor.Check('mathworks.example.hisl_0031');
        rec.Title = 'Check model file names';
        setCallbackFcn(rec, @hisl_0031, 'None', 'StyleOne');
        mdladvRoot.register(rec);
        
%%%%%%%%% OBSOLETE RULE
%         % hisl_0055: Prioritization of code generation objectives for high-integrity systems
%         rec = ModelAdvisor.Check('mathworks.example.hisl_0055');
%         rec.Title = 'Check prioritization of code generation objectives for high-integrity systems';
%         setCallbackFcn(rec, @hisl_0055,'None','StyleOne');
%         mdladvRoot.register(rec);
        
        % hisl_0062: Global variables in graphical functions
        rec = ModelAdvisor.Check('mathworks.example.hisl_0062');
        rec.Title = 'Check global variables in graphical functions';
        setCallbackFcn(rec, @hisl_0062, 'None', 'StyleOne');
        mdladvRoot.register(rec);
        
        % hisl_0063: Length of user-defined object names to improve MISRA C:2012 compliance
        rec = ModelAdvisor.Check('mathworks.example.hisl_0063');
        rec.Title = 'Check length of user-defined object names to improve MISRA C:2012 compliance';
        setCallbackFcn(rec, @hisl_0063, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0102: Data type of loop control variables to improve MISRA C:2012 compliance
        rec = ModelAdvisor.Check('mathworks.example.hisl_0102');
        rec.Title = 'Check data type of loop control variables to improve MISRA C:2012 compliance';
        setCallbackFcn(rec, @hisl_0102, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % hisl_0201: Define reserved keywords to improve MISRA C:2012 compliance
        rec = ModelAdvisor.Check('mathworks.example.hisl_0201');
        rec.Title = 'Check reserved keywords to improve MISRA C:2012 compliance';
        rec.TitleTips = 'This check looks for reserved keywords specified by user in the dialog box in the keywords defined in Configuration Parameters.';
        inputParam = ModelAdvisor.InputParameter;
        inputParam.Value = '';
        inputParam.Name = 'Reserved Keywords:';
        inputParam.Description = 'Specify a consistent set of reserved keywords as a comma separated list:';
        inputParam.setRowSpan([1 1]);
        inputParam.setColSpan([1 1]);
        setInputParameters(rec, {inputParam});
        setCallbackFcn(rec, @hisl_0201, 'None', 'StyleOne');
        mdladvRoot.register(rec);

        % hisf_0014: Usage of transition paths (passing through states)
        rec = ModelAdvisor.Check('mathworks.example.hisf_0014');
        rec.Title = 'Check usage of transition paths (passing through states)';
        setCallbackFcn(rec, @hisf_0014, 'None', 'StyleOne');
        mdladvRoot.register(rec);
        
        % himl_0001: Usage of standardized MATLAB function headers
        rec = ModelAdvisor.Check('mathworks.example.himl_0001');
        rec.Title = 'Check usage of standardized MATLAB function headers';
        setCallbackFcn(rec, @himl_0001, 'None', 'StyleOne');
        mdladvRoot.register(rec);
        
        % himl_0006: MATLAB code if / elseif / else patterns
        rec = ModelAdvisor.Check('mathworks.example.himl_0006');
        rec.Title = 'Check MATLAB code if / elseif / else patterns';
        setCallbackFcn(rec, @himl_0006, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % himl_0007: MATLAB code switch / case / otherwise patterns
        rec = ModelAdvisor.Check('mathworks.example.himl_0007');
        rec.Title = 'Check MATLAB code switch / case / otherwise patterns';
        setCallbackFcn(rec, @himl_0007, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % himl_0008: MATLAB code relational operator data types
        rec = ModelAdvisor.Check('mathworks.example.himl_0008');
        rec.Title = 'Check MATLAB code relational operator data types';
        setCallbackFcn(rec, @himl_0008, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % himl_0009: MATLAB code with equal / not equal relational operators
        rec = ModelAdvisor.Check('mathworks.example.himl_0009');
        rec.Title = 'Check MATLAB code with equal / not equal relational operators';
        setCallbackFcn(rec, @himl_0009, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
        % himl_0010: MATLAB code with logical operators and functions
        rec = ModelAdvisor.Check('mathworks.example.himl_0010');
        rec.Title = 'Check MATLAB code with logical operators and functions';
        setCallbackFcn(rec, @himl_0010, 'None', 'StyleOne');
        rec.CallbackContext = 'PostCompile';
        mdladvRoot.register(rec);
        
    end

    % Define custom tasks
    function defineTaskAdvisor
        
        mdladvRoot = ModelAdvisor.Root;
        
        rec = ModelAdvisor.FactoryGroup('mathworks.do178');
        rec.DisplayName = 'High-Integrity Modeling Guidelines';
        rec.Description = 'Additional checks for High-Integrity Modeling Guidelines';
        rec.addCheck('mathworks.example.hisl_0003');
        rec.addCheck('mathworks.example.hisl_0012');
        rec.addCheck('mathworks.example.hisl_0015');
        rec.addCheck('mathworks.example.hisl_0019');
        rec.addCheck('mathworks.example.hisl_0022');
        rec.addCheck('mathworks.example.hisl_0028');
        rec.addCheck('mathworks.example.hisl_0031');
%         rec.addCheck('mathworks.example.hisl_0055');
        rec.addCheck('mathworks.example.hisl_0062');
        rec.addCheck('mathworks.example.hisl_0063');
        rec.addCheck('mathworks.example.hisl_0102');
        rec.addCheck('mathworks.example.hisl_0201');
        rec.addCheck('mathworks.example.hisf_0014');
        rec.addCheck('mathworks.example.himl_0001');
        rec.addCheck('mathworks.example.himl_0006');
        rec.addCheck('mathworks.example.himl_0007');
        rec.addCheck('mathworks.example.himl_0008');
        rec.addCheck('mathworks.example.himl_0009');
        rec.addCheck('mathworks.example.himl_0010');
        mdladvRoot.publish(rec);
        
    end

end
