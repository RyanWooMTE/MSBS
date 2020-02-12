
% Return a list of gobal variables that are modified in the function.
function graphicalFnGlobalVarMap = getGlobalVarsUsedInFunction(chartObj, graphicalFn, graphicalFnGlobalVarMap)

    globalValArray = [];
    graphicalFnTransitions = graphicalFn.find('-isa', 'Stateflow.Transition');
    for ii=1:numel(graphicalFnTransitions)
        asts = Advisor.Utils.Stateflow.getAbstractSyntaxTree(graphicalFnTransitions(ii));
        if isempty(asts)
            continue;
        end
        % Just need to check action sections
        sections = [asts.conditionActionSection; asts.transitionActionSection];
        for jj=1:numel(sections)
            roots = sections{jj}.roots;
            for kk=1:numel(roots)
                ast = roots{kk};
                if isa(ast, 'Stateflow.Ast.EqualAssignment')
                    % We are only concerned with variables on the LHS
                    globalValArray = getGlobalVarsFromAST(chartObj, ast.lhs, graphicalFn, globalValArray);
                end
            end
        end
    end
    
    if ~isempty(globalValArray)
        graphicalFnGlobalVarMap(graphicalFn.id) = globalValArray;
    end
end

function globalValArray = getGlobalVarsFromAST(chart, ast, graphicalFn, globalValArray)

    if isa(ast, 'Stateflow.Ast.Identifier')
        sfID = ast.id;
        data = chart.find('-isa', 'Stateflow.Data','Id', sfID);
        if getParent(data) ~= graphicalFn
            globalValArray = [globalValArray; sfID];
        end
    else
        children = ast.children;
        for ii=1:numel(children)
            globalValArray = getGlobalVarsFromAST(chart, children(ii), graphicalFn, globalValArray);
        end
    end
    
end