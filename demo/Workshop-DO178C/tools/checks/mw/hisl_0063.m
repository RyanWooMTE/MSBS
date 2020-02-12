function resultDescription = hisl_0063(system)

resultDescription = {};
deviantElems = {};
simulinkDataTypes = {'Simulink.AliasType', 'Simulink.NumericType',...
                    'Simulink.Variant', 'Simulink.Bus', 'Simulink.BusElement'};
simulinkSignalParamTypes = {'Simulink.Signal', 'Simulink.Parameter'};
storageClasses = {'ExportedGlobal', 'ImportedExtern', 'ImportedExternPointer', 'Custom'};

model = bdroot(system);
activeConfig = getActiveConfigSet(model);
maxIdLength = activeConfig.get_param('MaxIdLength');
modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
modelAdvisorObject.setCheckResultStatus(false);

subSystems = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', 'SubSystem');
for ii=1:numel(subSystems)
    functionName = get_param(subSystems(ii), 'RTWFcnName');
    if ~isempty(cell2mat(functionName))
        if length(cell2mat(functionName)) > maxIdLength
            node.name = subSystems(ii);
            node.type = 'SubSystem';
            deviantElems{end+1} = node;
        end
    end
end

%% Limit the length of data object names to Maximum identifier length (MaxIdLength) characters or fewer for Simulink Variables
baseWSVars = Simulink.findVars(system, 'SearchMethod', 'cached', 'SourceType', 'base workspace');
modelWSVars = Simulink.findVars(system, 'SearchMethod', 'cached', 'SourceType', 'model workspace');

simulinkVariables = [baseWSVars, modelWSVars];
for ii=1:numel(simulinkVariables)
    if strcmp(simulinkVariables(ii).SourceType, 'base workspace')
        ws = 'base';
        varType = evalin('base',['class(',simulinkVariables(ii).Name,')']);
    elseif strcmp(simulinkVariables(ii).SourceType, 'model workspace')
        ws = 'model';
        mdlws = get_param(model, 'ModelWorkspace');
        varType = mdlws.evalin(['class(',simulinkVariables(ii).Name,')']);
    end       
    if any(strcmp(varType, simulinkDataTypes))
        if length(simulinkVariables(ii).Name) > maxIdLength
            node.name = simulinkVariables(ii).Name;
            node.type = varType;
            deviantElems{end+1} = node;
        end
    elseif any(strcmp(varType, simulinkSignalParamTypes))
        switch ws
            case 'base'
                storageClass = evalin('base',[simulinkVariables(ii).Name,'.CoderInfo.StorageClass']);
            case 'model'
                storageClass = mdlws.evalin([simulinkVariables(ii).Name,'.CoderInfo.StorageClass']);
        end
        if any(strcmp(storageClass, storageClasses))
            if length(simulinkVariables(ii).Name) > maxIdLength
                node.name = simulinkVariables(ii).Name;
                node.type = varType;
                deviantElems{end+1} = node;
            end
        end
    end
end

%% Evaluate name length for enum types
allVars = Simulink.findVars(system, 'SearchMethod', 'cached');
allVarsWithEnum = Simulink.findVars(system, 'SearchMethod', 'cached', 'IncludeEnumTypes', true);
enumVars = setdiff(allVarsWithEnum, allVars);
for ii=1:numel(enumVars)
    if length(enumVars(ii).Name) > maxIdLength
        node.name = enumVars(ii).Name;
        node.type = 'Simulink.IntEnumType';
        deviantElems{end+1} = node;
    end
end

if ~isempty(deviantElems)    
    ft = ModelAdvisor.FormatTemplate('TableTemplate');
    ft.setSubResultStatus('Warn');
    ft.setSubResultStatusText('Found following element(s) with name longer than maximum ID length:');
    setColTitles(ft, {'Element Name', 'Element Type'});
    for ii=1:numel(deviantElems)
        % Add information to the table
        addRow(ft, {deviantElems{ii}.name, deviantElems{ii}.type});
    end
    setRecAction(ft, ['Consider limiting the length of name of the elements to Maximum identifier length(MaxIdLength): ',...
                 num2str(maxIdLength),' characters or fewer.']);
    resultDescription{end+1} = ft;
   
else
    % There are no subsystems or this was a
    % model reference, so the test passed. 
    modelAdvisorObject.setCheckResultStatus(true);
    resultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    
end
