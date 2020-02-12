function replaceLineToFromGoto(lineH,TagName)
% replaceLineToFromGoto Replace a line to From/Goto blocks
%
% input:
%  lineH: Line handle
%  TagName: Label of From/Goto block 
%     (A warning will be shown if the label is already used in the model)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

if ~exist('TagName','var')
    error('TagName must be specified');
end

% show warning if the TagName is already used.
taggedBlocks = find_system(bdroot(gcs),'GotoTag',TagName);
if ~isempty(taggedBlocks)
    warning(['Specified TagName: ' TagName 'is already used by the following blocks:'])
    for n=1:length(taggedBlocks)
        fprintf('%s\n',taggedBlocks{n})
    end
end

% length between port and From / Goto block.
Dist = 10;
Width = 70;
Height = 18;

Parent = get(lineH,'Parent');
SrcPortHandle = get(lineH,'SrcPortHandle');
SrcBlockHandle = get(lineH,'SrcBlockHandle');
% to handle branched lines, get handles from src block's
sblh = get(SrcBlockHandle,'LineHandles');
DstPortHandle = get(sblh.Outport(get(SrcPortHandle,'PortNumber')),'DstPortHandle');
DstBlockHandle = get(sblh.Outport(get(SrcPortHandle,'PortNumber')),'DstBlockHandle');

delete_line(sblh.Outport(get(SrcPortHandle,'PortNumber')));

GotoBlockH = add_block('built-in/Goto',sprintf('%s/%s_Goto',Parent,TagName),'MAKENAMEUNIQUE','ON');
DstPos = get(SrcPortHandle,'Position');
set(GotoBlockH,'Position',[DstPos(1)+Dist DstPos(2)-Height/2 DstPos(1)+Dist+Width DstPos(2)+Height/2]);
set(GotoBlockH,'GotoTag',TagName,'ShowName','off');

add_line(Parent,sprintf('%s/%d',get(SrcBlockHandle,'Name'),get(SrcPortHandle,'PortNumber')),...
    sprintf('%s/%d',get(GotoBlockH,'Name'),1),'autorouting','on')

% replace all lines connected from src port
for n=1:length(DstPortHandle)
    FromBlockH = add_block('built-in/From',sprintf('%s/%s_From',Parent,TagName),'MAKENAMEUNIQUE','ON');
    SrcPos = get(DstPortHandle(n),'Position');
    set(FromBlockH,'Position',[SrcPos(1)-Dist-Width SrcPos(2)-Height/2 SrcPos(1)-Dist SrcPos(2)+Height/2]);
    set(FromBlockH,'GotoTag',TagName,'ShowName','off');
    add_line(Parent,sprintf('%s/%d',get(FromBlockH,'Name'),1),...
        sprintf('%s/%d',get(DstBlockHandle(n),'Name'),get(DstPortHandle(n),'PortNumber')),'autorouting','on')
end