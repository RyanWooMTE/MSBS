function expressions = getExpressionsUsingGlobalVars(StateflowObj, graphicalFnGlobalVarMap)
    expressions = {};
    
    asts = Advisor.Utils.Stateflow.getAbstractSyntaxTree(StateflowObj);  
    if isempty(asts)
        return;
    end

    sections = asts.sections; 
    for ii=1:numel(sections)
        roots = sections{ii}.roots;
        for jj=1:numel(roots)
            ast = roots{jj};
            graphicalFunctionsUsedInExpr = [];
            graphicalFunctionsUsedInExpr = getGraphicalFunctionsInExpr(ast, graphicalFnGlobalVarMap, graphicalFunctionsUsedInExpr);

            for kk=1:numel(graphicalFunctionsUsedInExpr)
                globalVars = graphicalFnGlobalVarMap(graphicalFunctionsUsedInExpr(kk));
                if isGlobalVarsUsedInExpr(ast, globalVars)
                   expressions{end+1} = ast.sourceSnippet; 
                end
            end
        end
    end  
end

function graphicalFunctions = getGraphicalFunctionsInExpr(ast, graphicalFnGlobalVarMap, graphicalFunctions)
    
    % TODO::Check if it is a graphical function
    if isa(ast, 'Stateflow.Ast.UserFunction')
        if isKey(graphicalFnGlobalVarMap, ast.id)
            graphicalFunctions(end+1) = ast.id;
        end
    else
        children = ast.children;
        for ii=1:numel(children)
            graphicalFunctions = getGraphicalFunctionsInExpr(children{ii}, graphicalFnGlobalVarMap, graphicalFunctions);
        end
    end
end

function out = isGlobalVarsUsedInExpr(ast, globalVars)
    out = false;
    
    if isa(ast, 'Stateflow.Ast.Identifier') && ~isempty(find(globalVars==ast.id, 1))
        out = true;
        return;
    else
        children = ast.children;
        for ii=1:numel(children)
            out = isGlobalVarsUsedInExpr(children{ii}, globalVars);
            if out
                return;
            end
        end
    end   
end