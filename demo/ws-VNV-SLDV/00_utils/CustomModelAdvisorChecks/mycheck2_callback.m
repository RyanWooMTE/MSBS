function result = mycheck2_callback(system)
% ModelAdvisor フォーマットファイル

%   Copyright 2012 The MathWorks, Inc. 

mdladvObj = Simulink.ModelAdvisor.getModelAdvisor(system); % get object

deviantBlocks = mycheck2_body(system);

ft = ModelAdvisor.FormatTemplate('ListTemplate');
ft.setCheckText('Switchブロックの判定条件設定をチェックします');

if isempty(deviantBlocks)
    ft.setSubResultStatus('pass');
    mdladvObj.setCheckResultStatus(true); % set to pass
else
    mdladvObj.setCheckResultStatus(false); % set to fail
    ft.setSubResultStatus('warn');
    ft.setSubResultStatusText([...
        '以下のSwitchブロックの判定条件は基準を満たしていません。'...
        ])
    ft.setListObj(deviantBlocks)
end

result=ft;


