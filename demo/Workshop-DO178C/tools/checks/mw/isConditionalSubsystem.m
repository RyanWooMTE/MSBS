function match = isConditionalSubsystem(blockHandle)
match = 'true';
controlPorts = find_system(blockHandle, 'SearchDepth', '1', 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'regexp', 'on', 'BlockType', '(EnablePort|TriggerPort|ActionPort)');
if isempty(controlPorts)
   match = 'false';
   return;
end