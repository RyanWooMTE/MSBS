%% ���ҏo�͂Ƃ̈�v�m�F���f���̎����쐬
%
% * MATLAB R2009b�ȍ~�Ή�
% * Simulink Veirification and Validation�����Simulink Design Verifier���K�v(R2009b, R2010a) 
% * Simulink Veirification and Validation���K�v (R2010b�ȍ~)

%% �T�v
% (1) �Ώۃ��f����I������B
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic02.png>>
%
% (2) ���ҏo�͈�v�m�F�p�n�[�l�X���f�� ���N���b�N����B
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic01.png>>
%
% (3) �n�[�l�X���f����������������A���Ғl�ƃ��f���o�͂̈�v��r���s����
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic03.png>>
%

%% �f�����s���@
% # cmtdtool\demo�t�H���_�� cmtdtool_samplemode.mdl ���J��
% # cmtdtool ��Łu���ҏo�͈�v�m�F�p�n�[�l�X���f���v�{�^�����N���b�N����
% # �V�K���f�����cmtdtool_samplemode.mdl �̃e�X�g�n�[�l�X���f�����쐬����Ă��邱�Ƃ��m�F����B
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
open_system('cmtdtool_sample')
makeharness_compareresults('cmtdtool_sample');
