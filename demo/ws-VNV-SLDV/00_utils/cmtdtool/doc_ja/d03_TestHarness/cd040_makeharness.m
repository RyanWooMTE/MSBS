%% �e�X�g�n�[�l�X�����쐬
%
% * MATLAB R2009b�ȍ~�Ή�
% * Simulink Veirification and Validation�����Simulink Design Verifier���K�v(R2009b, R2010a) 
% * Simulink Veirification and Validation���K�v (R2010b�ȍ~)
%

%% �T�v
% <<d03_TestHarness/cd040_makeharness_pic01.png>>

%% ���s���@
% # cmtdtool\demo�t�H���_�� cmtdtool_samplemodel.mdl ���J��
% # cmtdtool ��Łu�n�[�l�X���f���쐬�v�{�^�����N���b�N����
% # �V�K���f�����cmtdtool_samplemode.mdl �̃e�X�g�n�[�l�X���f�����쐬����Ă��邱�Ƃ��m�F����B
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
open_system('cmtdtool_sample')
sldvmakeharness('cmtdtool_sample');
