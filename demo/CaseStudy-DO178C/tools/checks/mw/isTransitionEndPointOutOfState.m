function transitionoutOfState = isTransitionEndPointOutOfState(junction, transition, option, junctionsChecked)
    transitionoutOfState = 'false';
      
    switch option
        case 'entry'
            source = transition.Source;
            if getParent(source) ~= getParent(junction) && getParent(transition) ~= source
                transitionoutOfState = 'true';
                return;
            else
                if isa(source, 'Stateflow.State')
                    return;
                else
                    sinkedTransitions = source.sinkedTransitions;
                    for i=1:length(sinkedTransitions)
                        transitionoutOfState = isTransitionEndPointOutOfState(source, sinkedTransitions(i), 'entry', junctionsChecked);
                        if strcmp(transitionoutOfState, 'true')
                            return;
                        end
                    end
                    % Add junction source to array to mark it traversed. 
                    junctionsChecked(end+1) = source.ID;
                end
            end
            
        case 'exit'
            destination = transition.Destination;
            if getParent(destination) ~= getParent(junction) && getParent(transition) ~= destination
                transitionoutOfState = 'true';
                return;
            else
                % Transition destination is within the state, but it could be
                % another junction or a state.
                % If it is a state, no need to look further
                if isa(destination, 'Stateflow.State')
                    return;
                else
                    % Transition destination end is a junction.
                    sourcedTransitions = destination.sourcedTransitions;
                    for i=1:length(sourcedTransitions)
                        transitionoutOfState = isTransitionEndPointOutOfState(destination, sourcedTransitions(i), 'exit', junctionsChecked);
                        if strcmp(transitionoutOfState, 'true')
                            return;
                        end
                    end
                    % Add junction destination to array to mark it traversed. 
                    junctionsChecked(end+1) = destination.ID;
                end
            end
    end
end