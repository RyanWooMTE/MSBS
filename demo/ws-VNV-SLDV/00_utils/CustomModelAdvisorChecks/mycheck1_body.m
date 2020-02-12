function blk = mycheck1_body(system)
% ブロックの向きが上向き、下向きのブロックを探索

%   Copyright 2012 The MathWorks, Inc. 

blk_up = find_system(system,'Orientation','up');
blk_dw = find_system(system,'Orientation','down');

blk = [blk_up; blk_dw];
