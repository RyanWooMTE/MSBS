%% Excel��̐^���l�\����Truth Table�u���b�N���쐬
%
% * MATLAB R2007a�ȍ~�Ή�
% * Stateflow�K�v

%% �T�v
% (1) Excel��Ő^���l�\���쐬���͈͂�I��
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic01.png>>
%
% (2) *�^���l�\���쐬*�{�^�����N���b�N
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic02.png>>
%
% (3) TruthTable�u���b�N���쐬����� (Stateflow)
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic03.png>>
%
% (4) Excel��̐^���l�\��TruthTable�u���b�N�ŕ\�������
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic04.png>>
%

%% Excel�L�q��
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic05.png>>
%
% * ���͏����A�o�͏����̑g�ݍ��킹�ɊY������p�^�[��(p1,p2,..)���w�肷��B
% 
% * MATLAB��ł́A���͏����ɍ��v������̓p�^�[����^�����ꍇ�ɁA
% �V�~�����[�V�������ʂ��瓾����M���l���o�͏����Ɉ�v���邱�Ƃ�
% �m�F����B
% 

%% TruthTable�u���b�N�ڍ�
%
% * ���������̕ϐ����u���b�N���͂Ƃ���(WS�Œ�`�ς݂̕ϐ���Parameter�Ƃ���)
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic06.png>>
%
% * *������*
% D1�񂩂珇�Ԃɕ]�����A��̑S�Ă̏����ɍ��v�����ꍇ�A���̔ԍ��̃A�N�V���������s
% �u���b�N�o�͍͂��v����������̔ԍ�
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic07.png>>
%
% 
 
%% ���f���C���[�W
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic08.png>>
%

%% �^���l�\�L�q���[���ڍ�
% * ��1��u�����v�F ���f�����̃R�����g�Ƃ��ė��p����܂��B�V�~�����[�V�����ɂ͒��ډe����^���܂���B
% * ��2��u�������v�F  ��1��ɑΉ�������������L�q���܂��B�Z�p���Z�q�A�_�����Z�q�A��r���Z�q���܂�MATLAB���ŋL�q���܂��B
% * ��3��ȍ~�F �e�������ɑ΂���^(T), �U(F), �ǂ���ł�(-) ���L�q���܂��B��3��ڂ���E������ �S�Ă̍s�ɑ΂��č��v���邩�ǂ����𔻒肵�A���v�����ꍇ�ɂ́A���̗�(p1��Ȃ��1�Ap6��Ȃ��6�A�Ȃ�)��Ԃ�TruthTable �u���b�N���쐬����܂��B
% * �ŏI��F ��3��`�ŏI-1��܂ł̏����ɍ��v���Ȃ��P�[�X�Ƃ��āA�u��O�v����L�q���܂��B�S�Ă̗� �u-�v�ŕ\�L����܂��B��O�ɊY�������ꍇ�ATruthTable��0��Ԃ��܂��B
% * �K�v�ɉ����čs�A���ǉ����Ă��������B
% 
% *���ӎ���*
%
% * ����������MATLAB�ϐ��Ƃ��ċ��e����镶����͎����I��TruthTable�u���b�N�̓��͂Ƃ��Đݒ肳��܂��B
% * �������ɁAMATLAB �x�[�X���[�N�X�y�[�X��Œ�`�ς݂̕ϐ������p����Ă���ꍇ�ATruthTable �u���b�N���Ńp�����[�^�Ƃ��ė��p����A�u���b�N���͂ɂȂȂ�܂���B


%% �f�����s���@
% # cmtdtool\demo�t�H���_�� cmtdtool_sampledata.xls ���J��
% # �u�^���l�\�v�^�u�� E3:M10��I������
% # cmtdtool ��Łu�^���l�\���쐬�v�{�^�����N���b�N����
% # �V�K���f�����Truth Table �u���b�N���쐬����Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
xls2TruthTable('cmtdtool_sampledata.xls','�^���l�\','E3:M10');
