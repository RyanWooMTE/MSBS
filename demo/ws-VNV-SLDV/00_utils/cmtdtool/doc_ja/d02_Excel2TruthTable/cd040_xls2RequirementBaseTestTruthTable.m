%% �v���x�[�X�e�X�g�pTruthTable�u���b�N�쐬
%
% * Simulink Verification and Validation(TM) �K�v
% * Simulink Design Verifier(TM) �K�v
% * Simulink(R) ����� Stateflow(R)�K�v
%

%% �@�\�ڍ�
% ���̋@�\�́ASimulink Design Verifier�̋@�\�𗘗p���āA
% �v���x�[�X�e�X�g�����{���邽�߂̗v�����f�����쐬���܂��B
%
% *(1) Excel�ɁA�������Ƃ��̑g�ݍ��킹���L�q���A���̋L�q�͈͂�I������B*
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic01.png>>
%
% *(2) �u�v���x�[�X�e�X�g�v���N���b�N����*
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic02.png>>
%
% *(3)���L�̂悤�ȃ��f�����쐬�����*
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic03.png>>
%
% *��}��(A)�����F*
%
% ��}��(A)�����́A���}�̂悤��TruthTable�u���b�N�𐶐����܂��B
% ����(A)�����́A�������ɋL�q���ꂽ�uP -> Q�v�ŕ\�����P�Ȃ��Q�̏����ɑ΂��āA
% P�𐬗�������e�X�g���͂��ASimulink Design Verifier�̋@�\��p���Ď�������������
% ���߂̕����ł��B�u�A�N�V�����e�[�u���v���u�A�N�V�����v��ɂ���usldv.test(1)�v��
% �L�q�ɂ��A�u�����e�[�u���v���́u�����v�̊e��𐬗������܂��B
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic05.png>>
%
% *��}��(B)�����F*
%
% ��}��(B)�����́A���}�̂悤��TruthTable�u���b�N�𐶐����܂��B
% ����(B)�����́A���������������邱�Ƃ��m�F���邽�߂̃u���b�N�ł��B
% ���������������Ȃ��ꍇ�ɂ́A�e�s�ԍ���TruthTable�u���b�N����o�͂���A 
% TruthTable�̌�i�ɐڑ������u==0�v�����Assertion�u���b�N�ɂ��
% �ᔽ�����o����܂��B
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic06.png>>
%
% �쐬���ꂽ"VerificationSubsystem"�u���b�N�����f�����ɔz�u���A
% Excel��ɋL�q�������҂������͒l�Ƃ��̊��ҏo�͂�
% �Y������M�����Ɍ������܂��B
%
% <<d02_Excel2TruthTable/cd040_xls2RequirementBaseTestTruthTable_pic07.png>>
%

%% �{�@�\�̗��p���@
% �{�@�\�ɂ�2�̗��p���@������܂��B
%
% * *�e�X�g����+�V�~�����[�V����* 
% Simulink Design Verifier�̎����e�X�g�����@�\�����s�����
% �������ɋL�q�����uP -> Q�v�ŕ\�����P�Ȃ��Q�̏����ɑ΂��āA
% P�𐬗�������e�X�g�x�N�^����������܂�(��}(A)����)�B
% �������ꂽ�e�X�g�n�[�l�X�ɑ΂��ăV�~�����[�V���������{���邱�ƂŁA
% ���ҏo�͂ƈ�v���邱�Ƃ��A��}(B)�����ɂ����Ċm�F���邱�Ƃ��ł��܂��B
% �����ᔽ����������ꍇ�ɂ́AAssertion�u���b�N�ɂ����Č��m����܂��B
%
% * *�v���p�e�B���؂𗘗p* Simulink Design Verifier�̃v���p�e�B���؂�
% ���̋@�\����񋟂����u���b�N���܂ރ��f���ɑ΂��Ď��s����ƁA
% �������ɂɑ΂��Č`�����؂ɂ��ؖ����s���܂��B
% �e�������ɂɑ΂��Ĉᔽ������̓p�^�[�������݂���̂ł���΁A
% ���̏؋��ƂȂ锽����͂��܂ރe�X�g�n�[�l�X�𐶐����܂��B

%% �������L�q���[��
% * ��1��u�����v�F ���f�����̃R�����g�Ƃ��ė��p����܂��B�V�~�����[�V�����ɂ͒��ډe����^���܂���B
% * ��2��u�������v�F  ��1��ɑΉ�������������L�q���܂��B�Z�p���Z�q�A�_�����Z�q�A��r���Z�q���܂�MATLAB���ŋL�q���܂��B�Ȃ��A���̃c�[���Ǝ��̋@�\�Ƃ��āAimplies �u->�v �����p�\�ł��B �������Ƃ��� �uA  -> B �v�ƋL�q�����ꍇ�A����͎����I�� ~A || B �ɕϊ�����܂��B(�L�q�̊ȑf���̂���)
% 
% *���ӎ���*
%
% * ���������ł͎����_���𒼐ڈ������Ƃ��ł��܂���B���̏ꍇ�ɂ́A���ԂɊւ�镔�������[�U���쐬����K�v������܂��B�i�Ⴆ�΁Aup_sw_old  �ϐ������������Ŏg���A Unit delay �u���b�N��p����1�T���v���ߋ���up_sw�l�� up_sw_old �|�[�g�ɐڑ�����ȂǁB�j

%% �f�����s��
% # cmtdtool\demo�t�H���_�� cmtdtool_sampledata.xls ���J��
% # �u�v���x�[�X�e�X�g�v�^�u�� B2:C6��I������
% # cmtdtool ��Łu�v���x�[�X�e�X�g�v�{�^�����N���b�N����
% # �V�K���f����ɁuVerificationSubsystem�v�u���b�N���쐬����Ă��邱�Ƃ��m�F����
% # �R�}���h�E�B���h�E����ȉ������s���邱�Ƃ�GUI�Ɠ��l�ȑ��삪���s�\�ł��邱�Ƃ��m�F����
xls2RequirementBaseTestTruthTable('cmtdtool_sampledata.xls','�v���x�[�X�e�X�g','B2:C6');
