%% ���ؗpTruthTable�u���b�N�����쐬
%
% * MATLAB R2007a�ȍ~�Ή�
% * Stateflow�K�v
%

%% �T�v
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic01.png>>
%
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic02.png>>
%
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic03.png>>
%
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic04.png>>
%

%% ���؎��L�q���[��
% * ��1��u�����v�F ���f�����̃R�����g�Ƃ��ė��p����܂��B�V�~�����[�V�����ɂ͒��ډe����^���܂���B
% * ��2��u�������v�F  ��1��ɑΉ�������������L�q���܂��B�Z�p���Z�q�A�_�����Z�q�A��r���Z�q���܂�MATLAB���ŋL�q���܂��B�Ȃ��A���̃c�[���Ǝ��̋@�\�Ƃ��āAimplies �u->�v �����p�\�ł��B �������Ƃ��� �uA  -> B �v�ƋL�q�����ꍇ�A����͎����I�� ~A || B �ɕϊ�����܂��B(�L�q�̊ȑf���̂���)
% 
% *���ӎ���*
%
% * ���������ł͎����_���𒼐ڈ������Ƃ��ł��܂���B���̏ꍇ�ɂ́A���ԂɊւ�镔�������[�U���쐬����K�v������܂��B�i�Ⴆ�΁Aup_sw_old  �ϐ������������Ŏg���A Unit delay �u���b�N��p����1�T���v���ߋ���up_sw�l�� up_sw_old �|�[�g�ɐڑ�����ȂǁB�j


%% �ُ�n�p�^�[���L�q
% �ُ킪�������Ă͂Ȃ�Ȃ��������L�q����
% 	(������ُ̈�����ɂ����v���Ȃ��ꍇ�͐���Ƃ���)
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic05.png>>

%% ����n�p�^�[���L�q
% ����ȏ��������ׂċL�q����
% 	(����ȊO�͂��ׂĈُ�Ƃ݂Ȃ�)
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic06.png>>

%% ���f���C���[�W
%
% <<d02_Excel2TruthTable/cd030_xls2VerificationTruthTable_pic07.png>>

%% �f�����s��
% # cmtdtool\demo�t�H���_�� cmtdtool_sampledata.xls ���J��
% # �u���؎��v�^�u�� E7:F10��I������
% # cmtdtool ��Łu���ؗp�^���l�\���쐬�v�{�^�����N���b�N����
% # �V�K���f�����Truth Table �u���b�N���쐬����Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
xls2VerificationTruthTable('cmtdtool_sampledata.xls','���؎�','E7:F10');
