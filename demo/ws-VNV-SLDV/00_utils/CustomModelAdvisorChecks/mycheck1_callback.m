function result = mycheck1_callback(system)
% ModelAdvisor �t�H�[�}�b�g�t�@�C��

%   Copyright 2012 The MathWorks, Inc. 

mdladvObj = Simulink.ModelAdvisor.getModelAdvisor(system); % get object

deviantBlocks = mycheck1_body(system);

ft = ModelAdvisor.FormatTemplate('ListTemplate');
ft.setCheckText('�u���b�N�̌��������E�łȂ��u���b�N��T�����܂�');

if isempty(deviantBlocks)
    ft.setSubResultStatus('pass');
    mdladvObj.setCheckResultStatus(true); % set to pass
else
    mdladvObj.setCheckResultStatus(false); % set to fail
    ft.setSubResultStatus('warn');
    ft.setSubResultStatusText([...
        '�ȉ��̃u���b�N�͏�����������͉������ŗ��p����Ă��܂��B'...
        '�E�����������͍������ƂȂ�悤�A�u���b�N����]�����ĉ������B'...
        ])
    ft.setListObj(deviantBlocks)
end

result=ft;


