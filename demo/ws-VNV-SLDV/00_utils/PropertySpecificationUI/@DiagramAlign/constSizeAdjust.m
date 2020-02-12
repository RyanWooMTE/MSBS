function constSizeAdjust(content,blk)
% Adjusting Constant block size so that variable name become visible

%   Copyright 2012 The MathWorks, Inc. 

if numel(content) > 5
    oPos = get_param(blk,'Position');
    width = (numel(content)-5)*5+30;
    set_param(blk,'Position',[oPos(1), oPos(2), oPos(1)+width, oPos(4)])
end
