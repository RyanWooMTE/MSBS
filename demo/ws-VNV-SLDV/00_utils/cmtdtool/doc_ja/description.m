%% cmtdtool

%% �T�v
% cmtdtool�͐��䃂�f���̌��؂ɗ��p�\�ȕ⏕�c�[���ł��B
% �����A���̃c�[���́AJMAAB-CMTD-WG (JMAAB: Japan MBD Automotive Advisory Board, 
% CMTD-WG: ���䃂�f�����ؐ݌v(Contol Model Test Design) Working Group)������
% �쐬����܂������A���x�̉��ς��o�āAMATLAB Central�����ʂɌ��J����܂����B
%
% ���䃂�f���̃e�X�g�����{����ۂɂ́A�e�X�g�݌v�A�e�X�g���f���̍\�z�A�e�X�g���s�A
% ���|�[�g���s���܂����A���̃c�[���́A�����̃t�F�[�Y�ɂ����ĕK�v�ƂȂ�
% ���Ƃ��\�Ȍ���팸���A���������܂��B
% 
%% (1) Excel����SignalBuilder
%
% * <cd010_xls2SignalBuilder.html Excel�I������SignalBuilder���쐬>
% Excel��őI������Ă���̈�̎��n��f�[�^��SignalBuilder��Ɏ�荞��(�V�K�쐬�A�ǉ��A�u��)�܂��B
% * <cd015_xls2SignalBuilder_multiple.html Excel�I������SignalBuilder���쐬(�ꊇ)> 
% ���݊J���Ă���Excel�̃V�[�g�ɒ�`����Ă��镡���̎��n��M�����ꊇ����SignalBuilder��Ɏ�荞�݂܂��B
%
%% (2) Excel����^���l�\
%
% * <cd020_xls2TruthTable.html �^���l�\���쐬>
% Excel��ɒ�`���ꂽ�^���l�\��TruthTable�u���b�N�Ƃ��Ď�荞�݂܂��B
% * <cd030_xls2VerificationTruthTable.html ���ؗp�^���l�\���쐬>
% Excel��ŋL�q������������TruthTable�u���b�N�Ƃ��Ď�荞�݂܂��B
% * <cd035_xls2TestObjective.html ���[�U��`�e�X�g�쐬> 
% Excel��ŋL�q�������͂Ɗ��ҏo�͒l�Ƃ̑g�ݍ��킹����A���̊֌W�������`�F�b�N�\�ȃu���b�N���쐬���܂��B
% * <cd040_xls2RequirementBaseTestTruthTable.html �v���x�[�X�e�X�g�p�T�u�V�X�e���쐬> 
% Excel��ŋL�q�������������A�v���x�[�X�e�X�g�p�Ɏ�荞�݂܂��B
%
%% (3) �e�X�g�n�[�l�X��������
%
% * <cd040_makeharness.html �e�X�g�n�[�l�X���f���쐬>
% �P�̃R���g���[�����f������e�X�g�n�[�l�X���f��(SignalBuilder + �f�[�^�ϊ� + �R���g���[��)���쐬���܂��B
% * <cd050_makeharness_compareresults.html ���ҏo�͈�v�m�F�p�n�[�l�X���f����������>
% �e�X�g���͂Ɗ��Ғl����͂Ƃ��A�R���g���[���o�͂Ɗ��Ғl�Ƃ̈�v�����m�F���邽�߂̃n�[�l�X���f�����쐬���܂��B
%
%% (4) �e�X�g�������s�ƃ��|�[�g��������
%
% * <cd060_runCMTDReport.html �e�X�g���|�[�g��������>
% ���ҏo�͈�v�m�F�p�n�[�l�X���f���Ɋ܂܂��SignalBuider�u���b�N�̊e�M���^�u���������s���A�e�X�g���|�[�g�������I�ɍ쐬���܂��B
%
% <<description_pic00.png>> 
%

%% �X�V����
% * 2010/06/29 JMAAB-CMTD-WG�����ɏ��Ō��J
% * 2010/08/04 JMAAB-CMTD-WG�����ɏC���Ō��J
% * 2010/11/04 JMAAB-CMTD-WG������v0.8���J
% * 2011/02/14 JMAAB-CMTD-WG������v0.9���J
% * 2011/05/27 MATLAB Central��v1.0���A�b�v���[�h.
% * 2011/12/28 MATLAB Central��v1.1���A�b�v���[�h.
% * 2012/12/12 v1.2 �������[�X