function blk = mycheck1_body(system)
% �u���b�N�̌�����������A�������̃u���b�N��T��

%   Copyright 2012 The MathWorks, Inc. 

blk_up = find_system(system,'Orientation','up');
blk_dw = find_system(system,'Orientation','down');

blk = [blk_up; blk_dw];
