function alignToDstInport(srcBlock,srcPortNum,dstBlock,dstPortNum,Distance)
% align a position of srcPortNum of srcBlock To a posiiton of dstPortNum of dstOutport

%   Copyright 2012 The MathWorks, Inc. 

% get origiran positions
sph = get_param(srcBlock,'PortHandles');
sPos = get_param(sph.Outport(srcPortNum),'Position');
sph = get_param(dstBlock,'PortHandles');
dPos = get_param(sph.Inport(dstPortNum),'Position');

orgPos = get_param(srcBlock,'Position');

% intermediate values
deltaY = sPos(2)-dPos(2);
orgWidth = (orgPos(3)-orgPos(1));
newXpos = dPos(1)-Distance-orgWidth;

set_param(srcBlock,'Position',[newXpos, orgPos(2)-deltaY, newXpos+orgWidth, orgPos(4)-deltaY])
end