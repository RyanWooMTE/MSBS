%% Excel�̑I���ӏ���SignalBuilder�u���b�N�ɏo��
%
% * MATLAB R2007a�ȍ~�Ή�
%
%% �T�v
%
% (1) SignalBuilder���������͈͂�I��
% 
% <<d01_Excel2SignalBuilder/cd010_xls2SignalBuilder_pic01.png>>
%
% (2) *SignalBuilder���쐬* �{�^�����N���b�N
%
% <<d01_Excel2SignalBuilder/cd010_xls2SignalBuilder_pic02.png>>
%
% (3) SignalBuilder�u���b�N���쐬�i�������͒ǉ��A�u���j
%
% <<d01_Excel2SignalBuilder/cd010_xls2SignalBuilder_pic03.png>>
%
% <<d01_Excel2SignalBuilder/cd010_xls2SignalBuilder_pic04.png>>
%

%% �e�X�g�p�^�[���L�q���[��
% * 1�s�ځF ���[�̃Z���Ƀe�X�g�P�[�X�����L�q
% * 2�s�ځF ���ԁA�M����1, �M����2,... ���L�q
% * 3�b�ځF �f�[�^�^�C�v�����L�q (double, single, int8, uint8, int16, uint16, int32, uint32, boolean) 
% �������_�ŌŒ菬���_�ɂ͖��Ή�
% * 4�s�ڈȍ~�F ���n��f�[�^���L�q
% 
% *���ӎ���*
%
% * �u�V�K�v�̏ꍇ�ɂ́A�I���-1��SignalBuilder�u���b�N����̏o�̓|�[�g���ƂȂ�
% * �u�ǉ��v�A�u�u���v�̏ꍇ�ɂ́A�I������Ă���SignalBuilder�u���b�N�Ɋ܂܂��M�����ƁA�I���-1����v���Ȃ��Ă͂Ȃ�Ȃ�
% * �f�[�^�^�C�v����SignalBuider��ł͌��ݎg�p����Ă��܂���B���̋@�\���g�p�����ۂ�MATLAB���[�N�X�y�[�X��ɍ쐬�����ϐ�
% |simdata| �ɂ����Ďg�p����Ă��܂��B

%% SignalBuilder����Excel�ւ̃����N�@�\
%
% Simulink Verification and Validation �̃��C�Z���X�����p����MATLAB�ɑ��݂���ꍇ�A
% SignalBuilder�u���b�N�ɍ쐬���ꂽ�M���O���[�v�ɑ΂��AExcel�̑I���ӏ��ւ̃����N��
% �����I�ɐݒ肳��܂��B
%
% SignalBuilder�u���b�N����A���̌��ƂȂ�Excel�̑I���ӏ����m�F���邽�߂ɂ́A
% SignalBuilder�u���b�N��́u���ؐݒ�̕\���v�{�^��(���}�Ԙg)���N���b�N���A
% �uRequirements�v���ɕ\������Ă��郉�x�����ŉE�N���b�N���uView�v��I�����܂��B
% (���}�Θg)
%
% <<d01_Excel2SignalBuilder/cd010_xls2SignalBuilder_pic05.png>>
%
% * <http://www.mathworks.com/help/toolbox/slvnv/ug/bsc_3xe.html �v�������N�@�\�̐��i�h�L�������g>
% 

%% �f���̎��s���@ 
% # cmtdtool�t�H���_�� cmtdtool_sampledata.xls ���J��
% # TestVectors�^�u��C2:E15 ��I������
% # cmtdtool ��Łu�V�K�v���W�I�{�^����I��������ԂŁuSignalBuilder���쐬�v�{�^�����N���b�N����
% # �V�K���f�����쐬����ASignalBuilder�u���b�N���Excel�̎��n��f�[�^���쐬����Ă��邱�Ƃ��m�F
% # TestVectors�^�u��C17:E21 ��I������
% # ��L(4)�ō쐬���ꂽ SignalBuilder�u���b�N���}�E�X�N���b�N(�J�����g�̃u���b�N��)����
% # cmtdtool ��Łu�ǉ��v���W�I�{�^����I��������ԂŁuSignalBuilder���쐬�v�{�^�����N���b�N����
% # ��L(4)�ō쐬���ꂽSignalBuilder�u���b�N��̐V�����M���O���[�v��Excel�̎��n��f�[�^���쐬����Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F

xls2SignalBuilder('cmtdtool_sampledata.xls','�e�X�g�x�N�^','C2:E15','','new');
xls2SignalBuilder('cmtdtool_sampledata.xls','�e�X�g�x�N�^','C17:E21',[bdroot '/TestCases'],'append');
