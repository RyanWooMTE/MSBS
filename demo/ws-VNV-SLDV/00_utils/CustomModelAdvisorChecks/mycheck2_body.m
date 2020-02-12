function deviantBlocks = mycheck2_body(system)
% SwitchƒuƒƒbƒN‚Ì”»’èğŒİ’è‚ğŒŸõ

%   Copyright 2012 The MathWorks, Inc. 

blk = find_system(system,'BlockType','Switch');

deviantBlocks = {};

for n=1:length(blk)
    if strcmp(get_param(blk{n},'Criteria'),'u2 >= Threshold') ...
            && strcmp(get_param(blk{n},'Threshold'),'0')
        deviantBlocks(end+1) = blk(n);
    end
end
