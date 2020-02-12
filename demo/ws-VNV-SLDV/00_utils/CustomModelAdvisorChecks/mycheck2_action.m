function result = mycheck2_action(taskobj)
% Action callback function

%   Copyright 2012 The MathWorks, Inc. 

mdladvObj = taskobj.MAObj;
system = bdroot(mdladvObj.System);

blk =  fixSettings(system);
 
ft = ModelAdvisor.FormatTemplate('ListTemplate');
ft.setCheckText('����Switch�u���b�N�̐ݒ肪�C������܂����B');
ft.setListObj(blk)

result = ft;

function blk = fixSettings(system)

 blk = find_system(system,'BlockType','Switch','Threshold','0','Criteria','u2 >= Threshold');
 
for n=1:length(blk)
    set_param(blk(n),'Criteria','u2 ~= 0');
end