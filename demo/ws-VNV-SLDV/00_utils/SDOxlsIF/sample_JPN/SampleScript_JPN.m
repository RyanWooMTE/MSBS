%%%%%%%%%%%%%%%%%%%% SDOxlsIF�̎g�p�� %%%%%%%%%%%%%%%%%%%%

% ���炩���ߒ񋟂̃R�}���h(xlssdoinfo/xlsreadsdo/xlswritesdo)�A
% ����юg�p�����`�̃t�@�C��(Simulink.xls, mpt.xls��)��
% MATLAB�p�X��ݒ肷��K�v������܂��B

% <<SDOxlsIF�̃C���X�g�[���f�B���N�g��>>         ��FC:\hoge\SDOxlsIF
% <<��`�̃t�@�C���i�[�f�B���N�g��>>             ��FC:\hoge\SDOxlsIF\JPN

% TestFile_JPN.xls����f�[�^�I�u�W�F�N�g��Simulink�p�b�P�[�W�Ƃ��ă��[�h���܂��B
xlsreadsdo('TestFile_JPN.xls', 'Simulink')

% Simulink�f�[�^�I�u�W�F�N�g��TestFile_JPN_Simulink.xls�ɃZ�[�u���܂��B
% ���ӁF�t�@�C�������ɂ���ꍇ�ɂ͏㏑������܂��B
xlswritesdo('TestFile_JPN_Simulink.xls', 'Simulink')

% TestFile_JPN.xls����f�[�^�I�u�W�F�N�g��mpt�p�b�P�[�W�Ƃ��ă��[�h���܂��B
xlsreadsdo('TestFile_JPN.xls', 'mpt')

% mpt�f�[�^�I�u�W�F�N�g��TestFile_JPN_mpt.xls�ɃZ�[�u���܂��B
% ���ӁF�t�@�C�������ɂ���ꍇ�ɂ͏㏑������܂��B
xlswritesdo('TestFile_JPN_mpt.xls', 'mpt')



%%%%%%%%%%%%%%%%%%%% MAT��`�̃t�@�C���̉^�p�ɂ��� %%%%%%%%%%%%%%%%%%%%

% ��`�̏��͒ʏ�AXLS��`�̃t�@�C������ǂݍ��܂�܂��B
% XLS��`�̃t�@�C���̏��́Axlssdoinfo�R�}���h�ɂ��A
% MATLAB���[�N�X�y�[�X��Ɏ�荞�ގ����ł��܂��B

Simulink = xlssdoinfo('Simulink');% Simulink�p�b�P�[�W�̒�`�̏��
mpt = xlssdoinfo('mpt');% mpt�p�b�P�[�W�̒�`�̏��

% xlssdoinfo�R�}���h�̖߂�l��
% <<�ϐ������p�b�P�[�W���A�t�@�C�������p�b�P�[�W��>>
% �Ƃ���MAT�t�@�C���ɃZ�[�u���A����XLS��`�̃t�@�C���Ɠ��l��
% MATLAB�p�X��ɔz�u����ƁAXLS��`�̃t�@�C���̑����
% ����MAT��`�̃t�@�C�������`�̏�񂪓ǂݍ��܂��悤�ɂȂ�܂��B
% XLS��`�̃t�@�C���̑����MAT��`�̃t�@�C�����g�p����ƁA
% ��ʂ�xlsreadsdo/xlswritesdo�̏���������������܂��B

% Simulink�p�b�P�[�W�pMAT��`�̃t�@�C����JPN�f�B���N�g���ɍ쐬����܂��B
save('..\JPN\Simulink', 'Simulink')

% mpt�p�b�P�[�W�pMAT��`�̃t�@�C����JPN�f�B���N�g���ɍ쐬����܂��B
save('..\JPN\mpt', 'mpt')

% ���ӁG��`�̃t�@�C���Ɋg���q�������w�肳��Ă���ꍇ�ɂ́A���̊g���q�̒�`�̃t�@�C�����g�p����܂��B
% XLS��`�̃t�@�C�����g�p
xlsreadsdo('TestFile_JPN.xls', 'Simulink.xls')
% MAT��`�̃t�@�C�����g�p
xlswritesdo('TestFile_JPN_Simulink.xls', 'Simulink.mat')

% xlssdoinfo/xlsreadsdo/xlswritesdo�R�}���h�ɂ́A����ȊO�ɂ�
% ���܂��܂Ȉ�����I�v�V�������w��ł��܂��B�ڍׂ̓h�L�������g���Q�Ɗ肢�܂��B
% �܂��AXLS��`�̃t�@�C���̏ڍׂɂ��܂��Ă͈ȉ��̃e���v���[�g�t�@�C�����Q�Ɗ肢�܂��B

% JPN\Simulink.xls ---> Simulink�p�b�P�[�W�p�e���v���[�g�t�@�C���i���{��j
% JPN\mpt.xls      ---> mpt�p�b�P�[�W�p�e���v���[�g�t�@�C���i���{��j
