function alignToSrcOutport(srcBlock,srcPortNum,dstBlock,dstPortNum,Distance)
% align a position of dstPortNum of dstBlock To a posiiton of srcPortNum of SrcOutport

%   Copyright 2012 The MathWorks, Inc. 

% get origiran positions
sph = get_param(srcBlock,'PortHandles');
sPos = get_param(sph.Outport(srcPortNum),'Position');
sph = get_param(dstBlock,'PortHandles');
dPos = get_param(sph.Inport(dstPortNum),'Position');
orgPos = get_param(dstBlock,'Position');

% intermediate values
deltaY = dPos(2)-sPos(2);
newXpos = sPos(1)+Distance;
orgWidth = (orgPos(3)-orgPos(1));

set_param(dstBlock,'Position',[newXpos, orgPos(2)-deltaY, newXpos+orgWidth, orgPos(4)-deltaY])
end