function resultDescription = hisf_0014(system)

    resultDescription = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    junctionsChecked = [];
    junctions = {};
    
    % Find all charts in the system.
    charts = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'Chart');    
    for i=1:numel(charts)
        chartObj = get_param(charts(i), 'Object');
        % Find all junctions in the chart
        chartJunctions = chartObj{1}.find('-isa', 'Stateflow.Junction');
        % We are only interested in junctions within states. Filter them out.
        for j=1:numel(chartJunctions)
            if isa(getParent(chartJunctions(j)), 'Stateflow.State')
                junctions{end+1} = chartJunctions(j);
            end
        end
    end

    for i=1:length(junctions)
        if ~ismember(junctions{i}.ID, junctionsChecked)
            sourcedTransitions = junctions{i}.sourcedTransitions;
            for j=1:length(sourcedTransitions)
                if strcmp(isTransitionEndPointOutOfState(junctions{i}, sourcedTransitions(j), 'exit', junctionsChecked), 'true')
                    % TODO: Check source 
                    sinkedTransitions = junctions{i}.sinkedTransitions;
                    for k=1:length(sinkedTransitions)
                        if strcmp(isTransitionEndPointOutOfState(junctions{i}, sinkedTransitions(k), 'entry', junctionsChecked), 'true')
                            ft = ModelAdvisor.FormatTemplate('ListTemplate');
                            ft.setSubResultStatus('Warn');
                            ft.setSubResultStatusText('Found following junction with transition paths that go into and out of a state without ending on a substate:');

                            ft.setListObj(junctions{i});
                            setRecAction(ft, 'Avoid transition paths that go into and out of a state without ending on a substate.');
                            resultDescription{end+1} = ft;
                            return;
                        end
                    end
                end
            end
        end
    end

    modelAdvisorObject.setCheckResultStatus(true);    
    resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});

end