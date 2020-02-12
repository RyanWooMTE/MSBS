function connectedLineH = autoWire(dstBlock,useFromGoto)

%   Copyright 2012 The MathWorks, Inc. 

if ~exist('useFromGoto','var')
    useFromGoto = false;
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
        if useFromGoto
            handles = replaceLine2FromGoto(connectedLineH{n},portName);
            connectedLineH{n} = [connectedLineH{n} handles];
        end
    else % portH
        connectedLineH{n} = add_line(...
            sys,sprintf('%s/%d',get_param(get(portH(1),'Parent'),'Name'),get(portH(1),'PortNumber')),...
            sprintf('%s/%s',get_param(dstBlock,'Name'),portNum),'autorouting','on');
        
        1;
    end
end
end


function handles = replaceLine2FromGoto(lineH,TagName)
% length between port and From / Goto block.
Dist = 10;
Width = 70;
Height = 18;
YOffset = 15;
handles = [];

Parent = get(lineH,'Parent');

SrcPortHandle = get(lineH,'SrcPortHandle');
SrcBlockHandle = get(lineH,'SrcBlockHandle');
DstPortHandle = get(lineH,'DstPortHandle');
% DstBlockHandle = get(lineH,'DstBlockHandle');

delete_line(lineH)

GotoBlockH = add_block('built-in/Goto',sprintf('%s/%s_Goto',Parent,TagName),'MAKENAMEUNIQUE','ON');
handles(end+1) = GotoBlockH;
DstPos = get(SrcPortHandle,'Position');
set(GotoBlockH,'Position',[DstPos(1)+Dist DstPos(2)-Height/2+YOffset DstPos(1)+Dist+Width DstPos(2)+Height/2+YOffset]);
set(GotoBlockH,'GotoTag',TagName,'ShowName','off');

GotoLineH = add_line(Parent,sprintf('%s/%d',get(SrcBlockHandle,'Name'),get(SrcPortHandle,'PortNumber')),...
    sprintf('%s/%d',get(GotoBlockH,'Name'),1),'autorouting','on');
handles(end+1) = GotoLineH;

% replace all lines connected from src port
for n=1:length(DstPortHandle)
    FromBlockH = add_block('built-in/From',sprintf('%s/%s_From',Parent,TagName),'MAKENAMEUNIQUE','ON');
    handles(end+1) = FromBlockH;
    SrcPos = get(DstPortHandle(n),'Position');
    set(FromBlockH,'Position',[SrcPos(1)-Dist-Width SrcPos(2)-Height/2 SrcPos(1)-Dist SrcPos(2)+Height/2]);
    set(FromBlockH,'GotoTag',TagName,'ShowName','off');
    FromPortH = get(FromBlockH,'PortHandles');
    FromLineH = add_line(Parent,FromPortH.Outport,DstPortHandle(n),'autorouting','on');
    handles(end+1) = FromLineH;
end
end
