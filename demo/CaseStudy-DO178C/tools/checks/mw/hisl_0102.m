%Limitations:
% 1. Do not handle Stateflow chart with MATLAB action language.
function resultDescription = hisl_0102(system)
    resultDescription = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    deviantBlocks = {};
    deviantElems = {};
    
    iteratorBlocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', 'ForIterator');
    for ii=1:numel(iteratorBlocks)
        iteratorDataType = get_param(iteratorBlocks(ii), 'IterationVariableDataType');
        if strcmp(iteratorDataType, 'double')
            deviantBlocks{end+1} = iteratorBlocks{ii};
        end
    end
    
    %% Check for datatype of loop control variables in stateflow
    charts = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'Chart');
    slciModel = slci.simulink.Model(bdroot(system));

    for ii=1:length(charts)
        chartHandle = cell2mat(get_param(charts(ii), 'Handle'));
        slciSF = slci.simulink.StateflowBlock(chartHandle, slciModel);
        slciChart = slci.stateflow.Chart(chartHandle, slciSF, slciModel);       
        cycles = slciChart.getCycles;
        for jj=1:numel(cycles)
            deviantElems = validateLoopControlVarsInCycle(slciChart, cycles{jj}, deviantElems);
        end       
    end
    
    %% Check for data type of loop control variables in Matlab Function Blocks
    mFunctions = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
    for ii=1:numel(mFunctions)
        mFunctionHandle = get_param(mFunctions{ii}, 'Handle');
        slciMFcn = slci.simulink.MatlabFunctionBlock(mFunctionHandle, slciModel);
        asts = getASTsFromSLCIMFn(slciMFcn);
        for jj=1:numel(asts)
            deviantElems = validateLoopControlVarsInMFcnAst(asts{jj}, deviantElems);
        end
    end
    
    if ~isempty(deviantBlocks) || ~isempty(deviantElems)  
        
        if ~isempty(deviantBlocks)
            ft1 = ModelAdvisor.FormatTemplate('ListTemplate');
            ft1.setSubResultStatus('Warn');
            ft1.setSubResultStatusText('Found following For Iterator Block(s) with non integer data type for loop control variable:');

            ft1.setListObj(deviantBlocks);
            setRecAction(ft1, 'Consider changing the datatype of the loop control variables to integers.');
            resultDescription{end+1} = ft1;
        end
        
        if ~isempty(deviantElems)
            ft2 = ModelAdvisor.FormatTemplate('TableTemplate');
            ft2.setSubResultStatus('Warn');
            ft2.setSubResultStatusText('Found following Stateflow/Matlab Function element(s) with non integer data type for loop control variable:');
            setColTitles(ft2, {'Element', 'Loop Control Variable'});
            for ii=1:numel(deviantElems)
                % Add information to the table
                addRow(ft2, {deviantElems{ii}.elemHandle, deviantElems{ii}.data});
            end
            setRecAction(ft2, 'Consider changing the datatype of the loop control variables to integers.');
            resultDescription{end+1} = ft2;
        end
        
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);
        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
        
    end

end

%% Helper Functions for Stateflow
function deviantElems = validateLoopControlVarsInCycle(chart, cycle, deviantElems)
    
    % A cycle can look like: 
    % 1. Junction -> Loop Condition Transition -> Junction -> LoopBody
    %    Transition (Counter Increment within the Body)
    % 2. Junction -> Loop Condition Transition -> Junction -> LoopBody
    %    Transition -> Junction -> Loop Increment Transition
    % TODO:: assert numel(cycle) ~= 4
    
    rt = sfroot;    
    if numel(cycle) == 4
        condTransitionId = str2double(cycle{2});
        countTransitionId = str2double(cycle{4});
    elseif numel(cycle) == 6
        condTransitionId = str2double(cycle{2});
        countTransitionId = str2double(cycle{6});
    else
        % Error!
        return;
    end
    slciCondTransition = chart.getTransitionFromId(condTransitionId);
    transitionHandle = idToHandle(rt, condTransitionId);
    condAsts = slciCondTransition.getASTs();
    loopCondVars = [];
    for ii=1:numel(condAsts)
        loopCondVars = getVarsFromLoopCondition(condAsts{ii}, loopCondVars);
    end
      
    slciBodyTransition = chart.getTransitionFromId(countTransitionId);
    bodyAsts = slciBodyTransition.getASTs();
    loopBodyVars = [];
    for ii=1:numel(bodyAsts)
        loopBodyVars = getVarsFromLoopBody(bodyAsts{ii}, loopBodyVars);
    end
    
    vars = intersect(loopCondVars, loopBodyVars);
    for ii=1:numel(vars)
        data = rt.find('-isa', 'Stateflow.Data', 'Id', vars(ii));
        if ~matchDataType(data.CompiledType, SignalDataTypes.INTEGER)
            node.data = data;
            node.elemHandle = transitionHandle;
            deviantElems{end+1} = node;
        end
    end
    
end


%% Returns vars used in condition
function vars = getVarsFromLoopCondition(ast, vars)     
    if isa(ast, 'slci.ast.SFAstLesserThan')...
            || isa(ast, 'slci.ast.SFAstLesserThanOrEqual')...
            || isa(ast, 'slci.ast.SFAstGreaterThan')...
            || isa(ast, 'slci.ast.SFAstGreaterThanOrEqual')
            children = ast.getChildren;
            % Need to check only LHS
            vars = getVarsFromLoopCondition(children{1}, vars);
    elseif isa(ast, 'slci.ast.SFAstIdentifier')
        vars(end+1) = ast.fId;          
    else
        children = ast.getChildren;
        for ii=1:numel(children)
            vars = getVarsFromLoopCondition(children{ii}, vars);
        end
    end
end

%% Returns vars used in Loop Body
function vars = getVarsFromLoopBody(ast, vars)

    if isa(ast, 'slci.ast.SFAstEqualAssignment')
        varsOnLHS = [];
        varsOnRHS = [];
        children = ast.getChildren;
        varsOnLHS = getVarsFromLoopBody(children{1}, varsOnLHS);
        varsOnRHS = getVarsFromLoopBody(children{2}, varsOnRHS);
        if ~isempty(intersect(varsOnLHS, varsOnRHS))
            vars = union(vars, intersect(varsOnLHS, varsOnRHS));
        end
    elseif isa(ast, 'slci.ast.SFAstIdentifier')
        vars(end+1) = ast.fId;
    else
        children = ast.getChildren;
        for ii=1:numel(children)
            vars = getVarsFromLoopBody(children{ii}, vars);
        end
    end
end


%% Helper functions for Matlab Functions

function deviantElems = validateLoopControlVarsInMFcnAst(ast, deviantElems)
    if isa(ast, 'slci.ast.SFAstFor')
        indexAsts = ast.getIndexAST;
        for ii=1:numel(indexAsts)
            indexType = indexAsts{ii}.getDataType;
            if ~matchDataType(indexType, SignalDataTypes.INTEGER)               
                link = slci.internal.ReportUtil.appendCallBack(ast.getRootAst.fName, bdroot, ast.getSID);
                link = strrep(link, '\n', '');
                node.data = indexAsts{ii}.fName;
                node.elemHandle = link;
                deviantElems{end+1} = node;
            end
        end
    else
        children = ast.getChildren;
        for ii=1:numel(children)
            deviantElems = validateLoopControlVarsInMFcnAst(children{ii}, deviantElems);
        end
    end
end


