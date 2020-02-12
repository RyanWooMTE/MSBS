function result = mycheck1_callback(system)
% ModelAdvisor フォーマットファイル

%   Copyright 2012 The MathWorks, Inc. 

mdladvObj = Simulink.ModelAdvisor.getModelAdvisor(system); % get object

deviantBlocks = mycheck1_body(system);

ft = ModelAdvisor.FormatTemplate('ListTemplate');
ft.setCheckText('ブロックの向きが左右でないブロックを探索します');

if isempty(deviantBlocks)
    ft.setSubResultStatus('pass');
    mdladvObj.setCheckResultStatus(true); % set to pass
else
    mdladvObj.setCheckResultStatus(false); % set to fail
    ft.setSubResultStatus('warn');
    ft.setSubResultStatusText([...
        '以下のブロックは上向きもしくは下向きで利用されています。'...
        '右向きもしくは左向きとなるよう、ブロックを回転させて下さい。'...
        ])
    ft.setListObj(deviantBlocks)
end

result=ft;


