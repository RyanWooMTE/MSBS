function objs = validateArrayIndicesInStatesTransitionsMFns(slciStatesTransitionsMFns, objs)
   
    for ii=1:numel(slciStatesTransitionsMFns)
        if isa(slciStatesTransitionsMFns(ii), 'slci.stateflow.SFState') ||...
           isa(slciStatesTransitionsMFns(ii), 'slci.stateflow.Transition')
            asts = slciStatesTransitionsMFns(ii).getASTs();
        else          
            asts = getASTsFromSLCIMFn(slciStatesTransitionsMFns(ii));
        end
        for jj=1:numel(asts)
            objs = validateIndicesOfSfASTArrayObjects(slciStatesTransitionsMFns(ii), asts{jj}, objs);
        end
    end
            
end

function objs = validateIndicesOfSfASTArrayObjects(parent, ast, objs)

    if isa(ast, 'slci.ast.SFAstArray')
        children = ast.getChildren();
        indexAsts = children(2:end);
        
        [isValid, objs.invalidDataTypeIndices] = validateIndexDataType(parent, indexAsts, objs.invalidDataTypeIndices);
        %% If all indices are valid, check if it covers the range of values.
        if isValid
            objs.invalidRangeIndices = validateIndexDataTypeRange(parent, ast, objs.invalidRangeIndices);    
        end
    else   
        childASTs = ast.getChildren();
        for ii=1:length(childASTs)
            objs = validateIndicesOfSfASTArrayObjects(parent, childASTs{ii}, objs);
        end
    end
end

function [isValid, objs] = validateIndexDataType(parent, indexAsts, objs)
    isValid = true;
    
    for ii=1:numel(indexAsts)
        match = matchDataType(indexAsts{ii}.getDataType, SignalDataTypes.INTEGER);
        if ~match
            isValid = false;  
            objs = addToDeviantElems(parent, indexAsts{ii}, objs);
        end
    end

end

function objs = validateIndexDataTypeRange(parent, arrayAst, objs)
    
    dataTypeRangeMaxMap = containers.Map({'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32'},... 
                                        {127, 255, 32768, 65535, 2147483648, 4294967295});
    dataDim = arrayAst.ResolveDataDim;
    children = arrayAst.getChildren();
    indexAsts = children(2:end);
    
    % Check if single subscript indexing is used
    if (numel(indexAsts) == 1) && (numel(dataDim) > 1)
        numOfElems = prod(dataDim);
        indexDataType = indexAsts{1}.getDataType;
        if numOfElems > dataTypeRangeMaxMap(indexDataType)
            objs = addToDeviantElems(parent, indexAsts{1}, objs);
        end
    else
        for ii=1:numel(indexAsts)      
            indexDataType = indexAsts{ii}.getDataType;
            if dataDim(ii) > dataTypeRangeMaxMap(indexDataType)
                objs = addToDeviantElems(parent, indexAsts{ii}, objs);
            end
        end
    end
end

function objs = addToDeviantElems(parent, ast, objs)
    rt = sfroot;
    
    if isa(parent, 'slci.simulink.MatlabFunctionBlock')
        handle = idToHandle(rt, parent.fEMChart.fChartId);
        link = slci.internal.ReportUtil.appendCallBack(ast.getSID, bdroot, ast.getSID);
        link = strrep(link, '\n', '');
        node.data = link;
        node.elemHandle = handle;
    else
        handle = idToHandle(rt, parent.getSfId);
        % For Stateflow, cannot get SID for the identifier, hence return
        % the handle to the parent itself.
        if any(strcmp('fName', properties(ast))) && ~isempty(ast.fName)    
            link = slci.internal.ReportUtil.appendCallBack(ast.fName, bdroot, parent.getSID);
        else
            link = slci.internal.ReportUtil.appendCallBack(parent.getSID, bdroot, parent.getSID);
        end
        link = strrep(link, '\n', '');
        node.data = link;
        node.elemHandle = handle;
    end
    objs{end+1} = node;
end