function result = mycheck2_callback(system)
% ModelAdvisor �t�H�[�}�b�g�t�@�C��

%   Copyright 2012 The MathWorks, Inc. 

mdladvObj = Simulink.ModelAdvisor.getModelAdvisor(system); % get object

deviantBlocks = mycheck2_body(system);

ft = ModelAdvisor.FormatTemplate('ListTemplate');
ft.setCheckText('Switch�u���b�N�̔�������ݒ���`�F�b�N���܂�');

if isempty(deviantBlocks)
    ft.setSubResultStatus('pass');
    mdladvObj.setCheckResultStatus(true); % set to pass
else
    mdladvObj.setCheckResultStatus(false); % set to fail
    ft.setSubResultStatus('warn');
    ft.setSubResultStatusText([...
        '�ȉ���Switch�u���b�N�̔�������͊�𖞂����Ă��܂���B'...
        ])
    ft.setListObj(deviantBlocks)
end

result=ft;


