%Limitations:
% 1. Part A will flag virtual blocks that are currently ignored by Simulink
%    engine. Should consider removing part A and the check entirely since
%    Simulink already errors out.
% 2. Does not implement part B.
function [ResultDescription, ResultHandles] = hisl_0015(system)

ResultDescription = {};
ResultHandles     = {};
deviantBlocks     = {};

modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
modelAdvisorObject.setCheckResultStatus(false);

% Find Merge blocks and check that they are connected to conditionally
% executed subsystems.
mergeBlocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', 'Merge');
for i=1:length(mergeBlocks)
    lineHandles = get_param(mergeBlocks{i}, 'LineHandles');
    inputLineHandles = lineHandles.Inport;
    match = isBlkConnectedToConditionalSubsys(inputLineHandles);
    if strcmp(match, 'false')
        deviantBlocks{end+1} = mergeBlocks(i);
    end
end

if ~isempty(deviantBlocks)
    ResultDescription{end+1} = ModelAdvisor.Text('Check that merge blocks are used only with conditionally executed subsystems.',{'bold'});

    ft = ModelAdvisor.FormatTemplate('ListTemplate');
    ft.setSubResultStatus('Warn');
    ft.setSubResultStatusText('Found merge block(s) used with blocks which are not conditionally executed subsystems:');

    ft.setListObj(deviantBlocks);
    ResultDescription{end+1} = ft;
    ResultHandles{end+1}     = [];
    setRecAction(ft, 'Use the merge blocks with conditionally executed subsystems.');
    
else
    % Find Merge blocks and check that 'Allow Unequal Port Widths' option is unset
    mergeBlocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'BlockType', 'Merge');
    for i=1:length(mergeBlocks)
        if strcmp(get_param(mergeBlocks{i},'AllowUnequalInputPortWidths'),'on')   
            deviantBlocks{end+1} = mergeBlocks{i};
        end
    end
    
   if ~isempty(deviantBlocks)
        ResultDescription{end+1} = ModelAdvisor.Text('Check that "Allow Unequal Port Width" setting for merge blocks is unset',{'bold'});

        ft = ModelAdvisor.FormatTemplate('ListTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following Merge Blocks(s) with  "Allow Unequal Port Widths" option set:');
        ft.setListObj(deviantBlocks);
        ResultDescription{end+1} = ft;
        ResultHandles{end+1}     = [];
        modelAdvisorObject.setActionEnable(true);
        % Set Result data so that the fix use the same
        modelAdvisorObject.setCheckResultData(deviantBlocks);
   else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);

        ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
        ResultHandles{end+1}     = {};
   end
end

% Check if a block is connected to conditionally executed subsystems.
function match = isBlkConnectedToConditionalSubsys(lineHandles)
match = 'true';
for i=1:length(lineHandles)
   srcBlkHandle = get_param(lineHandles(i), 'SrcBlockHandle');
   srcBlockType = get_param(srcBlkHandle, 'BlockType');
   if (~strcmp(srcBlockType, 'SubSystem'))
       match = 'false';
       return;
   end
   
   if strcmp(isConditionalSubsystem(srcBlkHandle), 'false')
       match = 'false';
       return;
   end
end