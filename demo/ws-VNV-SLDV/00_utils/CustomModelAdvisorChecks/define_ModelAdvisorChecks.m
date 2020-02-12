function define_ModelAdvisorChecks
mdladvRoot = ModelAdvisor.Root;

%   Copyright 2012 The MathWorks, Inc. 

% 
rec = ModelAdvisor.Check('com.mathworks.slapi.sample1');
rec.Title = '[���Z���[��001]�u���b�N�̌����̃`�F�b�N';
rec.TitleTips = '�u���b�N�̌��������E�ȊO�̃u���b�N��T�����܂�';
rec.setCallbackFcn(@mycheck1_callback,'None','StyleOne');
mdladvRoot.publish(rec, '���Z�`�F�b�N');

rec = ModelAdvisor.Check('com.mathworks.slapi.sample2');
rec.Title = '[���Z���[��002]Switch�u���b�N�̔���������`�F�b�N';
rec.TitleTips = 'Switch�u���b�N�̔�������� u2 >= 0 �łȂ����Ƃ��`�F�b�N���܂�';
rec.setCallbackFcn(@mycheck2_callback,'None','StyleOne');
% Define an automatic fix action for this check
modifyAction = ModelAdvisor.Action;
modifyAction.setCallbackFcn(@mycheck2_action);
modifyAction.Name = 'Swtich�u���b�N�̐ݒ�������C��';
modifyAction.Description = 'Switch�u���b�N�̔�������� u2 >= 0 �ɐݒ肳��Ă���ꍇ�Au2 ~= 0 �ɏC�����܂�';
modifyAction.Enable = true;
rec.setAction(modifyAction);
mdladvRoot.publish(rec, '���Z�`�F�b�N');

