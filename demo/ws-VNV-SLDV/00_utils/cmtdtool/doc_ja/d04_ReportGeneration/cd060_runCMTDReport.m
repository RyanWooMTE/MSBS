%% �e�X�g���|�[�g�̎�������
%
% * MATLAB R2008a�ȍ~�Ή�
% * Simulink(R) Report Generator(TM) ����� MATLAB(R) Report Generator(TM) ���K�v�B 

%% �@�\�ڍ�
%
% *(1) �����̊m�F*
% 
% ���̃e�X�g���|�[�g�̎��������@�\�́A���̏����𖞂����ꍇ�ɗ��p�ł��܂��B
%
% * ���f�����Ƀe�X�g�x�N�^����ъ��ҏo�͒l���܂�SignalBuilder�u���b�N��1���݂��邱��
% * �e�X�g�ΏۂƂȂ�T�u�V�X�e��(�������̓��f���Q�ƃu���b�N)�����݂��A���̓��o�͐M���̓X�J���[�M���ł��邱��
% * �A�T�[�V�����u���b�N�Ȃǂɂ���āA���f���̓�����r����M���������A���̐M����0(false)��1�X�e�b�v�ł��܂ޏꍇ�ɂ̓e�X�g�s���i�Ƃ��邱�ƁB
%
% *(2) ���̋L�q�ɏ]���ă��f�����ɓK�؂ȐM������t����*
%
% * �e�X�g�ΏۂƂȂ�T�u�V�X�e��(�������̓��f���Q�ƃu���b�N)�̓��o�͐M��
% * �\�����Ғl�ƂȂ�M���� |Exp_| �Ŏn�܂�M����
% * �A�T�[�V�����M��(�\�����Ғl�Ƃ̈�v��r�����{����M��)�� |Assertion_| ����n�܂�M����
%
% *(3) �e�X�g�ΏۂƂȂ�T�u�V�X�e��(�������̓��f���Q�ƃu���b�N)��I������B*
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic01.png>>
%
% *(4) �u���ҏo�͈�v�m�F�p�n�[�l�X���f���v ���N���b�N����B*
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic02.png>>
%
% ����ɂ��A��L(1)�Őݒ肵��3��ނ̊e�M���ɐM�����M���O���ݒ肳��܂��B
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic03.png>>
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic04.png>>
%
% *(5) �u�V�~�����[�V�����ꊇ���s�v���N���b�N����B*
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic05.png>>
%
% SignalBuilder�u���b�N�̊e�^�u�ɑ΂��ăV�~�����[�V�������s���A
% 3��ނ̃��M���O�ݒ肳�ꂽ�e�M���ɑ΂��āA���n��M����`�悵�܂��B
% �`�悵���M���́A�J�����g�t�H���_�� figs�t�H���_���ɕۑ�����܂��B
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic06.png>>
%
% *(6) �u���|�[�g�����v�{�^�����N���b�N����B*
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic07.png>>
%
% �{�c�[���́A���|�[�g�W�F�l���[�^�ݒ�t�@�C��: runCMTDreport.rpt (cmtdtool�C���X�g�[���t�H���_���ɕۑ�)
% �̐ݒ�ɏ]���āA���̏����}�C�N���\�t�g���[�h�t�@�C�� |"���f����"_report.doc| �ɏo�͂��܂��B
%
% * ���f���̃X�i�b�v�V���b�g���f��
% * SignalBuilder�u���b�N�̊e�M���O���[�v�ɑ΂���ΏۃT�u�V�X�e���̓��M����`��
% * SignalBuilder�u���b�N�̊e�M���O���[�v�ɑ΂�����ҏo�͒l��`��
% * SignalBuilder�u���b�N�̊e�M���O���[�v�ɑ΂���ΏۃT�u�V�X�e���̏o�͐M����`��
% * SignalBuilder�u���b�N�̊e�M���O���[�v�ɑ΂���ΏۃT�u�V�X�e���̃A�T�[�V�����M����`��
% * SignalBuilder�u���b�N�̊e�M���O���[�v�ɑ΂��ăA�T�[�V�����M�������ׂĔ�[���̏ꍇ�� *���i* ����B
% 1�X�e�b�v�ł��A�T�[�V�����M���Ƀ[�����܂܂��ꍇ�ɂ� *�s���i* ������s�� 
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic08.png>>
%

%% ���|�[�g�̃J�X�^�}�C�Y
% �{���|�[�g�̋@�\�́A���|�[�g�W�F�l���[�^�̋@�\�𗘗p����
% �e���v���[�g���쐬���邱�Ƃɂ���čs���Ă��܂��B
% ���|�[�g�̃e���v���[�g�t�@�C���́Acmtdtool�̃C���X�g�[���t�H���_��
% �܂܂��ȉ��̃t�@�C���ł��B
%
% |runCMTDreport.rpt| 
%
% ���̃e���v���[�g��ҏW���邽�߂ɂ́A�R�}���h�E�B���h�E�ɂ����Ď������s���A
report 
%%
% ������ |runCMTDreport.rpt| ��I�����܂��B
%
% <<d04_ReportGeneration/cd060_runCMTDReport_pic09.png>>
%

%% �f�����s���@
% # cmtdtool�t�H���_�� cmtdtool_sampleharness.mdl ���J��
% # cmtdtool_sampleharness.mdl
% ���uTestModel�v���N���b�N���A�J�����g�̃u���b�N�Ƃ���
% # cmtdtool ��Łu�e�X�g�Ώۃu���b�N�̑I���v�{�^�����N���b�N����
% # cmtdtool ��Łu�V�~�����[�V�����̈ꊇ���s�v�{�^�����N���b�N����
% # cmtdtool ��Łu���|�[�g�����v�{�^�����N���b�N����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
open_system('cmtdtool_sampleharness')
obj = runCMTDReport('cmtdtool_sampleharness/TestModel');
obj.runSimAll;
obj.runReport;
