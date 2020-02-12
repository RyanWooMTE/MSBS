%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
function resultDescription = himl_0006(system)

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
            deviantBlocks = validateIfElseIfConstructInMFcn(mFunctionHandle, asts{jj}, deviantBlocks);
        end
    end
    
    if ~isempty(deviantBlocks)
        ft = ModelAdvisor.FormatTemplate('TableTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following Matlab Function block(s) with if/elseif construct without a final else, or an empty else clause.');

        setColTitles(ft, {'MATLAB Function Block', 'If/Else construct'});
        for ii=1:numel(deviantBlocks)
            % Add information to the table
            addRow(ft, {deviantBlocks{ii}.elemHandle, deviantBlocks{ii}.data});
        end
        setRecAction(ft, 'Consider adding a final else clause with atleast a comment whenever using a if/elseif construct.');
        resultDescription{end+1} = ft;
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);

        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end
end

%% The function checks for if-elseif construct in function body
function deviantBlocks = validateIfElseIfConstructInMFcn(mFunctionHandle, ast, deviantBlocks)
     
    if isa(ast, 'slci.ast.SFAstIf')
        ifChildren = ast.getChildren;
        elseIfChildIdx = hasElseIf(ifChildren);
        if elseIfChildIdx ~= -1
            % Last child of SFAstIf should be SFAstElse
            if ~isa(ifChildren{end}, 'slci.ast.SFAstElse')
                link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                link = strrep(link, '\n', '');
                node.data = link;
                node.elemHandle = mFunctionHandle;
                deviantBlocks{end+1} = node;
            else
                elseAST = ifChildren{end};
                if elseAST.fBodyEmpty
                    link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                    link = strrep(link, '\n', '');
                    node.data = link;
                    node.elemHandle = mFunctionHandle;
                    deviantBlocks{end+1} = node;
                end
            end
        end
    else
        children = ast.getChildren;
        for idx=1:numel(children)
            deviantBlocks = validateIfElseIfConstructInMFcn(mFunctionHandle, children{idx}, deviantBlocks);
        end
    end
    
end

%% This function returns the index of the SFAstElseIf child if one exists, else -1.
function out = hasElseIf(asts)

    out = -1;
    for idx=1:numel(asts)
        if isa(asts{idx}, 'slci.ast.SFAstElseIf')
            out = idx;
            return;
        end
    end
end

