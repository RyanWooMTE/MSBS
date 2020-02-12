function reConnectLines(blk,srcInfo)

ph = get_param(blk,'PortHandles');
if length(ph.Inport) ~= length(srcInfo)
    warning('Port Info mismatch!')
    return;
end
portName = getPortName(blk);

sys = get_param(blk,'Parent');
for n=1:length(srcInfo)
    if ~isempty(srcInfo(n).SrcName) ... 
        && strcmp(portName{n},srcInfo(n).DstPortName)
        add_line(sys,srcInfo(n).SrcName,sprintf('%s/%d',get_param(blk,'Name'),n),'autorouting','on');
    end
end

function portName = getPortName(blk)
inportblk = find_system(blk,'LookUnderMasks','all','SearchDepth',1,'BlockType','Inport');
portName = {};
for n=1:length(inportblk)
    portName{str2double(get_param(inportblk{n},'Port'))} = get_param(inportblk{n},'Name'); %#ok
end
