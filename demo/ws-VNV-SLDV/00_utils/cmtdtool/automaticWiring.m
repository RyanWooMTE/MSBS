function connectedLineH = automaticWiring(dstBlock)
% autoWire: automatic wiring
% dstBlockのポート名と同名の信号名・ポート名を探索し、自動的に結線する

%   Copyright 2012 The MathWorks, Inc. 

if isempty(dstBlock) || ~strcmp(get_param(dstBlock,'BlockType'),'SubSystem')
    warning('cmtdtool:automaticWiring','Selected block is empty or not a subsystem')
    return;
end

sys = get_param(dstBlock,'Parent');
dstBlockPortH = get_param(dstBlock,'PortHandles');
connectedLineH = {};

inBlk = find_system(dstBlock,'LookUnderMasks','all','SearchDepth',1,'BlockType','Inport');
for n=1:length(inBlk)
    portName = get_param(inBlk{n},'Name');
    portNum = get_param(inBlk{n},'Port');
    lineH = find_system(sys,'FindAll','on','SearchDepth',1,'type','line','Name',portName);
    portH = find_system(sys,'FindAll','on','SearchDepth',1,'type','port','PropagatedSignals',portName);
    if isempty(lineH) && isempty(portH)
        % No corresponding name
        connectedLineH{n} = [];
    elseif get(dstBlockPortH.Inport(str2double(portNum)),'Line') ~= -1
        % There is an existing line.
        connectedLineH{n} = get(dstBlockPortH.Inport(str2double(portNum)),'Line');
    elseif ~isempty(lineH)
        srcBlockName = get(get(lineH(1),'SrcBlockHandle'),'Name');
        srcPortNum = get(get(lineH(1),'SrcPortHandle'),'PortNumber');
        connectedLineH{n} = ...
            add_line(sys,sprintf('%s/%d',srcBlockName,srcPortNum),...
            sprintf('%s/%s',get_param(dstBlock,'Name'),portNum),'autorouting','on');
    else % portH
        connectedLineH{n} = add_line(...
            sys,sprintf('%s/%d',get_param(get(portH(1),'Parent'),'Name'),get(portH(1),'PortNumber')),...
            sprintf('%s/%s',get_param(dstBlock,'Name'),portNum),'autorouting','on');
    end
end

