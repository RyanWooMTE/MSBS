classdef DiagramAlign
    % DiagramAlign is a set of utility functions to improve looks of a block diagram
    
    %   Copyright 2012 The MathWorks, Inc. 
    
    methods(Static)
        BlockAutoAlign(btree,sys)
        fixLineOverlap(sys)
        refreshAllLines(sys)
        constSizeAdjust(content,blk)
        alignToSrcOutport(srcBlock,srcPortNum,dstBlock,dstPortNum,Distance)
        alignToDstInport(srcBlock,srcPortNum,dstBlock,dstPortNum,Distance)
        %%

    end
end

    