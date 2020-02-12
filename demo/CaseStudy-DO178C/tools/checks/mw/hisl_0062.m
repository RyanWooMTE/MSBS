%Limitations:
% 1. Do not handle Stateflow chart with MATLAB action language.
function resultDescription = hisl_0062(system)

    resultDescription = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    
    % Map object to store {Function - Global Vars}
    graphicalFnGlobalVarMap = containers.Map('KeyType','double','ValueType','any');
    deviantElements = {};
    
    m = get_param(system, 'Object');
    chartArray = m.find('-isa', 'Stateflow.Chart');
    for ii=1:numel(chartArray)
        chartObj = chartArray(ii);
        graphicalFns = chartObj.find('-isa', 'Stateflow.Function');
        for jj=1:numel(graphicalFns)
            graphicalFnGlobalVarMap = getGlobalVarsUsedInFunction(chartObj, graphicalFns(jj), graphicalFnGlobalVarMap);
        end
        
        chartStatesTransitions = chartObj.find('-isa', 'Stateflow.State', '-or', '-isa', 'Stateflow.Transition');
        % Filter out Commented States/Transitions.
        chartStatesTransitions = chartStatesTransitions.find('IsExplicitlyCommented', 0);
        
        % Filter out States/Transitions that are part of graphical functions.
        for jj=1:numel(chartStatesTransitions)
            deviantExpressions = getExpressionsUsingGlobalVars(chartStatesTransitions(jj), graphicalFnGlobalVarMap);
            if ~isempty(deviantExpressions)
                deviantElements{end+1} = chartStatesTransitions(jj);
            end
        end
    end

    if ~isempty(deviantElements)
        ft = ModelAdvisor.FormatTemplate('ListTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following State/Transition using data with a global scope that is modified in a function, in a calling expression:');

        ft.setListObj(deviantElements);
        setRecAction(ft, 'Avoid using  data in the calling expression if a value is assigned to the data in a function that is called in the same expression.');
        resultDescription{end+1} = ft;
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);

        resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    end

end
