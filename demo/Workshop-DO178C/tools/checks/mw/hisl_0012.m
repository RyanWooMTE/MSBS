%Considerations:
% 1. The check currently flags Enebled Subsystem as explained in the
%    guideline. Should consider relaxing the rule to exclude Enabled
%    Subsystem blocks.
function ResultDescription = hisl_0012(system)

ResultDescription = {};
deviantBlocks = {};
conditionalSubSystems = {};
modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);

sampleTimeDependentBlockTypes = {'DiscreteStateSpace', 'DiscreteIntegrator', 'DiscreteFir',...
                            'DiscreteFilter', 'DiscreteTransferFcn', 'DiscreteZeroPole'};

% The following blocks all have BlockType of SubSystem, so use MaskType
% instead.
sampleTimeDependentMaskTypes = {'First Order Transfer Fcn', 'Transfer Fcn Real Zero', 'Lead or Lag Compensator'};

% Find conditionally executed subsystems within the system
subSystems = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', 'SubSystem');
for ii=1:length(subSystems)
    if strcmp(isConditionalSubsystem(subSystems(ii)), 'true')
        conditionalSubSystems(end+1) = subSystems(ii);
    end
end

% Check if all blocks except constant blocks within the conditionally
% executed subsystem have specified inherited(-1) sample time.
for ii=1:length(conditionalSubSystems)
    subSystemBlocks = find_system(conditionalSubSystems{ii}, 'FollowLinks', 'on', 'LookUnderMasks', 'all');
    conditionPortBlocks = find_system(conditionalSubSystems{ii}, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'regexp', 'on', 'BlockType', '(EnablePort|TriggerPort|ActionPort)');
    blockToValidate = setdiff(subSystemBlocks, conditionPortBlocks);
    for jj=1:length(blockToValidate)
        blockType = get_param(blockToValidate{jj}, 'BlockType');
        if strcmp(blockType, "Constant")
            sampleTime = get_param(blockToValidate{jj}, 'SampleTime');
            if ~strcmp(sampleTime, '-1') && ~strcmp(sampleTime, 'inf')
                deviantBlocks{end+1} = blockToValidate{jj};
            end
        else
            try 
                sampleTime = get_param(blockToValidate{jj}, 'SampleTime');
                if ~strcmp(sampleTime, '-1')
                    deviantBlocks{end+1} = blockToValidate{jj};
                end
            catch
                %% Block does not have sample time param
            end
        end
    end
end

if ~isempty(deviantBlocks)
    ResultDescription{end+1} = ModelAdvisor.Text(['Check if all blocks in conditionally executed subsystems ',...
                            'have specified inherited (-1) sample times.'],{'bold'});

    ft = ModelAdvisor.FormatTemplate('ListTemplate');
    ft.setSubResultStatus('Warn');
    ft.setSubResultStatusText(['Found following block(s) in conditionally executed subsystems ',... 
                            'that have not specified inherited sample time:']);

    ft.setListObj(deviantBlocks);
    ResultDescription{end+1} = ft;
    modelAdvisorObject.setActionEnable(true); 
    % Set Result data so that the fix use the same
    modelAdvisorObject.setCheckResultData(deviantBlocks);
    
else    
    for ii=1:length(sampleTimeDependentBlockTypes)
        blocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', sampleTimeDependentBlockTypes{ii});
        if ~isempty(blocks)
            for jj=1:length(blocks)
                if isAsync(blocks{jj})
                    deviantBlocks{end+1} = blocks{jj};
                end
            end
        end
    end
    
    for ii=1:length(sampleTimeDependentMaskTypes)
        blocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'MaskType', sampleTimeDependentMaskTypes{ii});
        if ~isempty(blocks)
            for jj=1:length(blocks)
                if isAsync(blocks{jj})
                    deviantBlocks{end+1} = blocks{jj};
                end
            end
        end
    end
    
    if ~isempty(deviantBlocks)
         ResultDescription{end+1} = ModelAdvisor.Text(['Check that conditionally executed subsystems ',...
                                    'called asynchronously avoid using sample time dependent blocks.'],{'bold'});

         ft = ModelAdvisor.FormatTemplate('ListTemplate');
         ft.setSubResultStatus('Warn');
         ft.setSubResultStatusText(['Found following sample time dependent block(s) in conditionally executed subsystems ',... 
                                    'that are called asynchronously:']);

         ft.setListObj(deviantBlocks);
         setRecAction(ft, ['Avoid using sample time dependent blocks with conditionally executed subsystems ',...
                            'that are called asynchronously.']);
         ResultDescription{end+1} = ft;
         
    else
        modelAdvisorObject.setCheckResultStatus(true);
        ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
        
    end

end

% Determine if a block is called asynchronously
function match = isAsync(blockHandle)
  
match = false;
compiledSampleTime = get_param(blockHandle, 'CompiledSampleTime');
if compiledSampleTime(1) == -1 && compiledSampleTime(2) < -1
    match = 'true';
end


