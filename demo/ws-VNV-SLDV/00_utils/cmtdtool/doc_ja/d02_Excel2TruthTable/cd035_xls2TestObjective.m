%% ���[�U��`�e�X�g�pTruthTable�u���b�N�쐬
%
% * MATLAB R2007a�ȍ~�Ή�
% * Simulink Verification and Validation(TM) �K�v
% * Simulink Design Verifier(TM) �K�v
% * Simulink(R) ����� Stateflow(R)�K�v
%

%% �@�\�ڍ�
% ���̋@�\�́ASimulink Design Verifier�̃��[�U��`�e�X�g�̎��������@�\�𗘗p���āA
% ���[�U�̏��]����e�X�g�������������A���ҏo�͂Ƃ̈�v��r��e�ՂɎ��s���邽�߂�
% ���p���邱�Ƃ��ł��܂��B
%
% *(1) Excel�ɁA���̓e�X�g�x�N�^�{���ҏo�͒l�����X�g����B*
%
% <<d02_Excel2TruthTable/cd035_xls2TestObjective_pic01.png>>
%
% *(2) �u���[�U��`�e�X�g�v���N���b�N����*
%
% <<d02_Excel2TruthTable/cd035_xls2TestObjective_pic02.png>>
%
% *(3)���L�̂悤�ȃ��f�����쐬�����*
%
% �쐬���ꂽ"VerificationSubsystem"�u���b�N�����f�����ɔz�u���A
% Excel��ɋL�q�������҂������͒l�Ƃ��̊��ҏo�͂�
% �Y������M�����Ɍ������܂��B
%
% <<d02_Excel2TruthTable/cd035_xls2TestObjective_pic03.png>>
%
% *��L(3)�}�� (A) Compare_ExpectedOutputs TruthTable�̐���*
%
% ����TruthTable�u���b�N���ł́A����_�� implies
%   (~P||Q) 
% �̋L�q�ɂ��A���҂���e�X�g�x�N�^�ɑ΂�����ҏo�͂�
% �_�����L�q���Ă��܂��B
% ���Ƃ��΁AExcel���case01�ɂ����ẮA
% �ȉ��̏��������߂��Ă��܂��B
%
%  X0==uint8(1) && X1==uint8(2) && Y==double(3) �Ȃ��
%  abs(Z-int16(4))<=0 && abs(Z2-double(5))<=0 ����������
%
% ���̏������񐬗��ƂȂ�ꍇ�ATruthTable�u���b�N�́A�o��out�Ƃ���1���o�͂��܂��B
% ���̌��ʁAAssertion�u���b�N�ɂ����Ĉᔽ���������邱�ƂɂȂ�܂��B
%
% �����e�[�u�����̂ǂ̏����ɂ��ᔽ���Ȃ��ꍇ�ɂ́A
% out�Ƃ���0�ȊO���o�͂���AAssertion�u���b�N�ɂ����Ĉᔽ�͔������܂���B
%
% <<d02_Excel2TruthTable/cd035_xls2TestObjective_pic05.png>>
%
% *��L(3)�}�� (B)TestObjective TruthTable�̐���*
%
% TurthTable�u���b�N���ł́AExcel��ɋL�q���ꂽ�ecase01-03�̏����𖞂���
% �e�X�g��Simulink Design Verifier �ɂ��e�X�g�P�[�X���������@�\��
% ���p���Đ�������悤�ɐݒ肳��Ă��܂��B
% �A�N�V�����e�[�u�����́usldv.test(1)�v�́A���̃A�N�V�����e�[�u���s��
% ���B����e�X�g�𐶐�����悤Simulink Design Verifier�Ɏw�������Ă��܂��B
%
% <<d02_Excel2TruthTable/cd035_xls2TestObjective_pic04.png>>
%
%% �{�@�\�̗��p���@
% �{�@�\�ɂ�2�̗��p���@������܂��B
%
% * *�e�X�g����+�V�~�����[�V����* 
% Simulink Design Verifier�̎����e�X�g�����@�\�����s�����
% Excel���Ɏw�肵�����҂�����͂�^����e�X�g�x�N�^���܂ރe�X�g�n�[�l�X����������܂��B
% �������ꂽ�e�X�g�n�[�l�X�ɑ΂��ăV�~�����[�V���������{���邱�ƂŁA
% ���ҏo�͂ƈ�v���邱�Ƃ��m�F���邱�Ƃ��ł��܂��B
% * *�v���p�e�B���؂𗘗p* Simulink Design Verifier�̃v���p�e�B���؂�
% ���̋@�\����񋟂����u���b�N���܂ރ��f���ɑ΂��Ď��s����ƁA
% Compare_ExpectedOutputs TruthTable�u���b�N�Ɏw�肳��Ă���
% ���ؖ���ɑ΂��ďؖ����s���܂��B�����ACompare_ExpectedOutputs TruthTable�u���b�N��
% �e�������ɑ΂��Ĉᔽ������̓p�^�[�������݂���̂ł���΁A
% ���̏؋��ƂȂ锽����͂��܂ރe�X�g�n�[�l�X�𐶐����܂��B

%% ���[�U��`�e�X�g�L�q���[��
% * 1�s�ځF 2��ڈȍ~�ɕϐ������L�q�B���̕ϐ�����TruthTable�u���b�N�̓��o�͖��ɑΉ����܂��B
% * 2�s��: 2��ڈȍ~�ɁA���͂̏ꍇ��u1,u2,u3,... ���A���ҏo�͂̏ꍇ�ɂ�e1,e2,e3,...���L�q���܂��B
% * 3�b�ځF �f�[�^�^�C�v�����L�q (double, single, int8, uint8, int16, uint16, int32, uint32, boolean) 
% �������_�ŌŒ菬���_�ɂ͖��Ή�
% * 4�s�ڈȍ~�F 1��ڂɃe�X�g�P�[�X�����L�q���A2��ڈȍ~�ɂ́A���ꂼ��̗�ɑΉ�������͒l�A���Ғl���L�q���܂��B


%% �f�����s��
% # cmtdtoo\demo�t�H���_�� cmtdtool_sampledata.xls ���J��
% # �u���[�U��`�e�X�g�v�^�u�� B2:G7��I������
% # cmtdtool ��Łu���[�U��`�e�X�g�v�{�^�����N���b�N����
% # �V�K���f����ɁuVerificationSubsystem�v�u���b�N���쐬����Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
xls2TestObjective('cmtdtool_sampledata.xls','���[�U��`�e�X�g','B2:G7');
