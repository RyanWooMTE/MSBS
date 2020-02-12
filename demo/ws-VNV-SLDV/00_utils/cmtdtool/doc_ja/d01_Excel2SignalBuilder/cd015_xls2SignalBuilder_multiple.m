%% Excel��̃e�X�g�x�N�^��SignalBuilder�u���b�N�Ɉꊇ�o��
%
% * MATLAB R2007a�ȍ~�Ή�
%

%% ����
% �{�@�\�Ɨގ��̋@�\��MATLAB R2010b���Simulink��SignalBuilder�u���b�N�ŗ��p�\�ł��B
% �{�c�[���̍쐬�҂� MATLAB R2010b�Œ񋟂���鐻�i�̋@�\�̗��p�� *��������* �v���܂��B
% �Ȃ��AR2010b�ō쐬���ꂽSignalBuider�u���b�N�����ʃo�[�W�����Ƀo�b�N�|�[�g���邱�Ƃ��\�ł��B
% 
% �h�L�������g�f�ډӏ��ւ̃����N
%
% <http://www.mathworks.com/help/toolbox/simulink/ug/f15-109640.html#bskwu0h-1>

%% �T�v
%
% (1) �ꊇ�o�͂������e�X�g�x�N�^���܂�Excel�V�[�g���J��
%
% ���݊J���Ă���Excel�t�@�C���̃V�[�g�S�̂��ꊇ��荞�݂̑ΏۂƂȂ�܂��B
% ����̃Z����I������K�v�͂���܂���B
% 
% <<d01_Excel2SignalBuilder/cd015_xls2SignalBuilder_multiple_pic01.png>>
%
% (2) *Excel����SignalBuilder���쐬(�ꊇ)* �{�^�����N���b�N
%
% <<d01_Excel2SignalBuilder/cd015_xls2SignalBuilder_multiple_pic02.png>>
%
% (3) SignalBuilder�u���b�N���쐬�����
%
% <<d01_Excel2SignalBuilder/cd015_xls2SignalBuilder_multiple_pic03.png>>
%
% SinalBuilder�u���b�N�ɂ͊Y����Excel�V�[�g�ɋL�q���ꂽ�M�����ꊇ����
% ��荞�܂��
%
% <<d01_Excel2SignalBuilder/cd015_xls2SignalBuilder_multiple_pic04.png>>
%

%% �e�X�g�x�N�^�L�q���[��
% * 1�s�ځF ���[�̃Z���� |*�u<TV>�e�X�g�x�N�^���v*|
% ���L�q�B�ŏ��̕����́u<TV>�v(���ׂĔ��p����)�ł��邱�ƁB
% ����������SignalBuilder�u���b�N�̃O���[�v���ɔ��f����܂��B
% ���̃L�[���[�h�u<TV>�v���e�X�g�x�N�^�̎n�܂�������܂��B
% * 2�s�ځF ���ԁA�M����1, �M����2,... ���L�q
% * 3�b�ځF �f�[�^�^�C�v�����L�q (|double, single, int8, uint8, int16, uint16, int32, uint32, boolean|) 
% �������_�ŌŒ菬���_�ɂ͖��Ή�
% * 4�s�ڈȍ~�F ���n��f�[�^���L�q
% * ���̃e�X�g�x�N�^���L�q���܂��B�O�e�X�g�x�N�^�̎��n��f�[�^�ƐV�e�X�g�x�N�^�̊Ԃɂ́A��s�╶����݂̂��܂ލs��
% �܂ނ��Ƃ��ł��܂��B
% 
% *���ӎ���*
%
% * �{�@�\�Ɨގ��̋@�\��MATLAB R2010b���Simulink��SignalBuilder�u���b�N�ŗ��p�\�ł��B 
% �{�c�[���̍쐬�҂� MATLAB R2010b�Œ񋟂���鐻�i�̋@�\�̗��p�����������v���܂��B 
% �Ȃ��AR2010b�ō쐬���ꂽSignalBuider�u���b�N�����ʃo�[�W�����Ƀo�b�N�|�[�g���邱�Ƃ��\�ł��B
% �h�L�������g�f�ډӏ��ւ̃����N
% <http://www.mathworks.com/help/toolbox/simulink/ug/f15-109640.html#bskwu0h-1>
% 
% * �O�e�X�g�x�N�^�̎��n��f�[�^�ƐV�e�X�g�x�N�^�̊Ԃɐ��l�f�[�^(���p�����݂̂��܂܂��Z��)���܂܂��ƁA
% ��������荞�݂��ł��܂���B��s��������݂̂��܂ނ悤�ɂ��ĉ������B
% * ���Ԃ���ѐM����ȊO�̍s�ɕ�������ѐ��l�f�[�^���܂܂Ȃ��悤�ɂ��ĉ������B
% �{�c�[���́A�e��ɑ΂��A1�ł������E���l���܂܂��ƁA���Ԃ���ѐM�����܂܂��L���񂾂�
% ���f���A�C���|�[�g���悤�Ƃ��܂��B
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
% # �u�ꊇ��荞�ݗp�e�X�g�x�N�^�v�^�u���J���B
% # cmtdtool ��ŁuExcel����SignalBuilder���쐬(�ꊇ)�v�{�^�����N���b�N����
% # ��L�ō쐬���ꂽSignalBuilder�u���b�N���Excel�̎��n��f�[�^���ꊇ�Ŏ�荞�܂�Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F

xls2SignalBuilder_multiple('cmtdtool_sampledata.xls','�ꊇ��荞�ݗp�e�X�g�x�N�^',[],[]);
