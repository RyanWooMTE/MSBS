%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
% 2. Do not handle Stateflow chart with MATLAB action language.
function ResultDescription = hisl_0022(system)

ResultDescription = {};
deviantElems.invalidDataTypeIndices = {};
deviantElems.invalidRangeIndices = {};

modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
modelAdvisorObject.setCheckResultStatus(false);

blockTypes = { 'Assignment',...
               'LookupNDDirect',...
               'MultiPortSwitch',...
               'Selector',...
               'Lookup_n-D',...
               'Interpolation_n-D'
             };
            
for ii=1:length(blockTypes)
    BlocksToValidate = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', blockTypes{ii});
    for jj=1:length(BlocksToValidate)
        [indexPorts, indexPortDatatypes] = getIndexPortsDatatypes(blockTypes{ii}, BlocksToValidate{jj});
        deviantElems = validateIndexPortsInSimulinkBlocks(BlocksToValidate{jj}, indexPorts, indexPortDatatypes, deviantElems);
    end
end

%% Check for datatype of vector indices in Stateflow
charts = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'Chart');
slciModel = slci.simulink.Model(bdroot(system));

for ii=1:length(charts)
    chartHandle = cell2mat(get_param(charts(ii), 'Handle'));
    slciSF = slci.simulink.StateflowBlock(chartHandle, slciModel);
    slciChart = slci.stateflow.Chart(chartHandle, slciSF, slciModel);
       
    % Validate all Identifier Objects for index in transitions
    slciTransitions = slciChart.getTransitions();  
    deviantElems = validateArrayIndicesInStatesTransitionsMFns(slciTransitions, deviantElems);
    
    % Validate all Identifier Objects for index in States
    slciStates = slciChart.getStates();
    deviantElems = validateArrayIndicesInStatesTransitionsMFns(slciStates, deviantElems);
end

%% Check for datatype of vector indices in Matlab Functions
slciMFunctions = [];
mFunctions = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
for ii=1:numel(mFunctions)
    mFunctionHandle = get_param(mFunctions{ii}, 'Handle');
    slciMFunctionBlock = slci.simulink.MatlabFunctionBlock(mFunctionHandle, slciModel);
    if isempty(slciMFunctions)
        slciMFunctions = slciMFunctionBlock;
    else
        slciMFunctions(end+1) = slciMFunctionBlock;
    end
end
deviantElems = validateArrayIndicesInStatesTransitionsMFns(slciMFunctions, deviantElems);

%% 
if ~isempty(deviantElems.invalidDataTypeIndices)  || ~isempty(deviantElems.invalidRangeIndices)
    
    if ~isempty(deviantElems.invalidDataTypeIndices)
        ft2 = ModelAdvisor.FormatTemplate('TableTemplate');
        ft2.setSubResultStatus('Warn');
        ft2.setSubResultStatusText('Found following Simulink Blocks(s) or Stateflow/Matlab Function element(s) with floating point datatype for index:');
        setColTitles(ft2, {'Element', 'Index Port/Variable'});
        for ii=1:numel(deviantElems.invalidDataTypeIndices)
            % Add information to the table
            addRow(ft2, {deviantElems.invalidDataTypeIndices{ii}.elemHandle, deviantElems.invalidDataTypeIndices{ii}.data});
        end
        setRecAction(ft2, 'Consider changing the datatype of the indices to integers.');
        ResultDescription{end+1} = ft2;      
    end
    
    if ~isempty(deviantElems.invalidRangeIndices)
        ft2 = ModelAdvisor.FormatTemplate('TableTemplate');
        ft2.setSubResultStatus('Warn');
        ft2.setSubResultStatusText('Found following Simulink Blocks(s) or Stateflow/Matlab Function element(s) with datatype of indices that do not cover the range of indexed values:');
        setColTitles(ft2, {'Element', 'Index Port/Variable'});
        for ii=1:numel(deviantElems.invalidRangeIndices)
            % Add information to the table
            addRow(ft2, {deviantElems.invalidRangeIndices{ii}.elemHandle, deviantElems.invalidRangeIndices{ii}.data});
        end
        setRecAction(ft2, 'Consider changing the datatype of the indices to integer types that can cover the range of indexed values.');
        ResultDescription{end+1} = ft2;      
    end
    
else  
    % There are no subsystems or this was a
    % model reference, so the test passed. 
    modelAdvisorObject.setCheckResultStatus(true);
    ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
        
end