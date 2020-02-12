%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
% 2. Cannot copare fixed-point types since they are all returned as
%    embedded.fi. For example, sfix16 and int16 will be flagged as
%    different while sfix16En8 and sfix16En9 will not be flagged. So this
%    check will flag all use of sfix and ufix for manual review.
function resultDescription = himl_0008(system)

    resultDescription = {};
    deviantElems.invalidExprs = {}; 
    deviantElems.invalidExprsWithFixedPoint = {};
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
    
    if ~isempty(deviantElems.invalidExprs) || ~isempty(deviantElems.invalidExprsWithFixedPoint)
        
        if ~isempty(deviantElems.invalidExprs)
            ft = ModelAdvisor.FormatTemplate('TableTemplate');
            ft.setSubResultStatus('Warn');
            ft.setSubResultStatusText('Found following Matlab Function block(s) code with relational operators having different data type for left and right operands:');
            setColTitles(ft, {'MATLAB Function', 'Code'});
            for ii=1:numel(deviantElems.invalidExprs)
                % Add information to the table
                addRow(ft, {deviantElems.invalidExprs{ii}.elemHandle, deviantElems.invalidExprs{ii}.data});
            end
            setRecAction(ft, 'Consider changing the data type of the operands such that the right and left operands of relational operators have same type.');
            resultDescription{end+1} = ft;
            
        else
            ft = ModelAdvisor.FormatTemplate('TableTemplate');
            ft.setSubResultStatus('Warn');
            ft.setSubResultStatusText('Found following Matlab Function block(s) code with relational operators using Fixed point datatypes for one or more operands:');
            setColTitles(ft, {'MATLAB Function', 'Code'});
            for ii=1:numel(deviantElems.invalidExprsWithFixedPoint)
                % Add information to the table
                addRow(ft, {deviantElems.invalidExprsWithFixedPoint{ii}.elemHandle, deviantElems.invalidExprsWithFixedPoint{ii}.data});
            end
            setRecAction(ft, 'The fixed point operands used with the relational operators may/may not be of the same type. Please review it manually.');
            resultDescription{end+1} = ft;
            
        end
        
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);
        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end
end

function deviantElems = validateRelationalOperatorOperands(mFunctionHandle, ast, deviantElems)
    
    if isaRelationalOperator(ast)
        children = ast.getChildren;
        lhs = children{1};
        lhsDataType = lhs.getDataType;        
        rhs = children{2};
        rhsDataType = rhs.getDataType;
        if strcmp(lhsDataType, 'embedded.fi') || strcmp(rhsDataType, 'embedded.fi')
            link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
            link = strrep(link, '\n', '');
            node.data = link;
            node.elemHandle = mFunctionHandle;
            deviantElems.invalidExprsWithFixedPoint{end+1} = node;
        elseif ~strcmp(lhsDataType, rhsDataType)
            link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
            link = strrep(link, '\n', '');
            node.data = link;
            node.elemHandle = mFunctionHandle;
            deviantElems.invalidExprs{end+1} = node;
        end
    else
        children = ast.getChildren;
        for ii=1:numel(children)
            deviantElems = validateRelationalOperatorOperands(mFunctionHandle, children{ii}, deviantElems);
        end
    end

end

function out = isaRelationalOperator(ast)
    out = false;

    if isa(ast, 'slci.ast.SFAstIsEqual') ||...
            isa(ast, 'slci.ast.SFAstIsNotEqual') ||...
            isa(ast, 'slci.ast.SFAstGreaterThan') ||...
            isa(ast, 'slci.ast.SFAstGreaterThanOrEqual') ||...
            isa(ast, 'slci.ast.SFAstLesserThan') ||...
            isa(ast, 'slci.ast.SFAstLesserThanGreaterThan') ||...
            isa(ast, 'slci.ast.SFAstLesserThanOrEqual')
        out = true;
    end
end
