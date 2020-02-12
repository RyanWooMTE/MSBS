%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
function resultDescription = himl_0009(system)

    resultDescription = {};
    deviantElems = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    
    slciModel = slci.simulink.Model(bdroot(system));
    mFunctions = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
    for ii=1:numel(mFunctions)
        mFunctionHandle = get_param(mFunctions{ii}, 'Handle');
        slciMFunctionBlock = slci.simulink.MatlabFunctionBlock(mFunctionHandle, slciModel);
        asts = getASTsFromSLCIMFn(slciMFunctionBlock);
        for jj=1:numel(asts)
            deviantElems = validateRelationalOperatorOperands(mFunctionHandle, asts{jj}, deviantElems);
        end
    end
    
    if ~isempty(deviantElems)        
        ft = ModelAdvisor.FormatTemplate('TableTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following Matlab Function block code with Equal/Not Equal relational operators having one or more floating point data type for operands:');
        setColTitles(ft, {'MATLAB Function', 'Code'});
        for ii=1:numel(deviantElems)
            % Add information to the table
            addRow(ft, {deviantElems{ii}.elemHandle, deviantElems{ii}.data});
        end
        setRecAction(ft, 'Consider changing the datatype of operands of Equal/Not Equal relational operators to integer.');
        resultDescription{end+1} = ft;
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);
        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end
    
end
      
function deviantElems = validateRelationalOperatorOperands(mFunctionHandle, ast, deviantElems)
    
    if isa(ast, 'slci.ast.SFAstIsEqual') || isa(ast, 'slci.ast.SFAstIsNotEqual')
        children = ast.getChildren;
        for idx=1:numel(children)
            if matchDataType(children{idx}.getDataType, SignalDataTypes.FLOAT)  
                link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                link = strrep(link, '\n', '');
                node.data = link;
                node.elemHandle = mFunctionHandle;
                deviantElems{end+1} = node;
                return;
            end
        end
    else
        children = ast.getChildren;
        for idx=1:numel(children)
            deviantElems = validateRelationalOperatorOperands(mFunctionHandle, children{idx}, deviantElems);
        end
    end

end