function LineInfo = storeConnectedLineInfo(blk)

%   Copyright 2012 The MathWorks, Inc. 

LineInfo = get_param(blk,'LineHandles');
LineInfo.InportPos = {};

for n=1:length(LineInfo.Inport)
    if LineInfo.Inport(n) ~= -1
        LineInfo.InportPos{n} = get(LineInfo.Inport(n),'Points');
    end
end
