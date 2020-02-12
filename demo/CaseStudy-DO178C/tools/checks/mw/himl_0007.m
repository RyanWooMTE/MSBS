%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
function resultDescription = himl_0007(system)

    resultDescription = {};
    deviantBlocks = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);

    slciModel = slci.simulink.Model(bdroot(system));
    mFunctions = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
    for ii=1:numel(mFunctions)
        mFunctionHandle = get_param(mFunctions{ii}, 'Handle');
        slciMFunctionBlock = slci.simulink.MatlabFunctionBlock(mFunctionHandle, slciModel);
        asts = getASTsFromSLCIMFn(slciMFunctionBlock);
        for jj=1:numel(asts)
            deviantBlocks = validateSwitchCaseConstructInMFcn(mFunctionHandle, asts{jj}, deviantBlocks);
        end
    end
    
    if ~isempty(deviantBlocks)
        ft = ModelAdvisor.FormatTemplate('TableTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following Matlab Function block(s) with switch/case construct with only one case, without a final otherwise, or an empty otherwise clause.');

        setColTitles(ft, {'MATLAB Function Block', 'Switch/Case construct'});
        for ii=1:numel(deviantBlocks)
            % Add information to the table
            addRow(ft, {deviantBlocks{ii}.elemHandle, deviantBlocks{ii}.data});
        end
        setRecAction(ft, 'Consider having atleast two case statements and a final otherwise clause with atleast a comment when using switch/case constructs.');
        resultDescription{end+1} = ft;
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);

        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end
    
end


function deviantBlocks = validateSwitchCaseConstructInMFcn(mFunctionHandle, ast, deviantBlocks)
    
    if isa(ast, 'slci.ast.SFAstSwitch')
        numOfCases = numel(ast.fCaseIdx);
        otherwiseIDX = ast.fOtherwiseIdx;
        if numOfCases < 2 || isempty(otherwiseIDX)
            link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
            link = strrep(link, '\n', '');
            node.data = link;
            node.elemHandle = mFunctionHandle;
            deviantBlocks{end+1} = node;
        else
            otherwiseAst = ast.getOtherwiseAST;
            if otherwiseAst{1}.fBodyEmpty
                link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                link = strrep(link, '\n', '');
                node.data = link;
                node.elemHandle = mFunctionHandle;
                deviantBlocks{end+1} = node;
            end
        end
    else
        children = ast.getChildren;
        for idx=1:numel(children)
            deviantBlocks = validateSwitchCaseConstructInMFcn(mFunctionHandle, children{idx}, deviantBlocks);
        end
    end
end