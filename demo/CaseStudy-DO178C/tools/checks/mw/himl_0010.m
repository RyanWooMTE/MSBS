%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
% 2. Cannot support logical function. So the check will flag all use of
%    logical function to be replaced with operators.
function resultDescription = himl_0010(system)

    resultDescription = {};
    deviantElems = {};   
    unsupportedElems = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    
    slciModel = slci.simulink.Model(bdroot(system));
    mFunctions = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
    for ii=1:numel(mFunctions)
        mFunctionHandle = get_param(mFunctions{ii}, 'Handle');
        slciMFunctionBlock = slci.simulink.MatlabFunctionBlock(mFunctionHandle, slciModel);
        asts = getASTsFromSLCIMFn(slciMFunctionBlock);
        for jj=1:numel(asts)
            [deviantElems, unsupportedElems] = validateLogicalOperatorOperands(mFunctionHandle, asts{jj}, deviantElems, unsupportedElems);
        end
    end
    
    if ~isempty(deviantElems) || ~isempty(unsupportedElems)  
        if ~isempty(deviantElems)
            ft1 = ModelAdvisor.FormatTemplate('TableTemplate');
            ft1.setSubResultStatus('Warn');
            ft1.setSubResultStatusText('Found following Matlab Function block code with logical operators using one or more non-logical operands:');
            setColTitles(ft1, {'MATLAB Function', 'Code'});
            for ii=1:numel(deviantElems)
                % Add information to the table
                addRow(ft1, {deviantElems{ii}.elemHandle, deviantElems{ii}.data});
            end
            setRecAction(ft1, 'Consider using logical data types for operands of logical operators in MATLAB code.');
            resultDescription{end+1} = ft1;
        end
        
        if ~isempty(unsupportedElems)
            ft2 = ModelAdvisor.FormatTemplate('TableTemplate');
            ft2.setSubResultStatus('Warn');
            ft2.setSubResultStatusText('Found following Matlab Function block code with logical functions(and,or,xor,not):');
            setColTitles(ft2, {'MATLAB Function', 'Code'});
            for ii=1:numel(unsupportedElems)
                % Add information to the table
                addRow(ft2, {unsupportedElems{ii}.elemHandle, unsupportedElems{ii}.data});
            end
            setRecAction(ft2, 'Consider replacing the logical functions with corresponding logical operators/ manually reviewing the operands of the functions.');
            resultDescription{end+1} = ft2;
        end
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);
        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end
    
end

function [deviantElems, unsupportedElems] = validateLogicalOperatorOperands(mFunctionHandle, ast, deviantElems, unsupportedElems)

    if isLogicalOperatorOrFunction(ast)
        children = ast.getChildren;
        for idx=1:numel(children)
            if isLogicalOperatorOrFunction(children{idx})
                [deviantElems, unsupportedElems] = validateLogicalOperatorOperands(mFunctionHandle, children{idx}, deviantElems, unsupportedElems);
            else
                if ~strcmp(children{idx}.getDataType, 'boolean')
                    link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                    link = strrep(link, '\n', '');
                    node.data = link;
                    node.elemHandle = mFunctionHandle;
                    deviantElems{end+1} = node;
                end
            end
        end
    % Need to do this since logical functions - and/or/xor/not are not
    % supported in slci
    elseif isa(ast, 'slci.ast.SFAstUnsupported')
        mtree = ast.getMtree;
        if strcmp(mtree.kind, 'CALL')
            func = mtree.Left;
            if isLogicalFunctionCall(func)
                link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
                link = strrep(link, '\n', '');
                node.data = link;
                node.elemHandle = mFunctionHandle;
                unsupportedElems{end+1} = node;
            end
        end
        
    else
        children = ast.getChildren;
        for idx=1:numel(children)
            [deviantElems, unsupportedElems] = validateLogicalOperatorOperands(mFunctionHandle, children{idx}, deviantElems, unsupportedElems);
        end
    end
end

function out = isLogicalOperatorOrFunction(ast)
    out = false;
    
    if isa(ast, 'slci.ast.SFAstAndAnd') ||...
       isa(ast, 'slci.ast.SFAstOrOr') ||...
       isa(ast, 'slci.ast.SFAstLogicalAnd') ||...
       isa(ast, 'slci.ast.SFAstLogicalOr') ||...
       isa(ast, 'slci.ast.SFAstNot')
        out = true;
    end
end


function out = isLogicalFunctionCall(mtreeNode)
    out = false;
    logicalFunctions = {'and', 'or', 'xor', 'not'};
    
    for ii=1:numel(logicalFunctions)
        logicalFns = mtreeNode.mtfind('Fun', logicalFunctions{ii});
        if ~isempty(logicalFns)
            out = true;
            return;
        end
    end
    
end
