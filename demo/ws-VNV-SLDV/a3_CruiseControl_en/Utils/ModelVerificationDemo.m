%% ���f�����؃f��
%

%% �f���t�@�C���\��
% �{�f���͈ȉ��̃t�@�C���ō\������Ă��܂��B
%
% *�f�����s���[�e�B���e�B*
%
% * |ModelVerificationDemo.html| �f�����s�pHTML�t�@�C��
% * |startup_demo.m|: �f�����s���ݒ�t�@�C��
%
%
% *���f��*
%
% * |cruise_control_top.mdl| : �g�b�v���x�����f��
% * |cruise_control_top_fixpt.mdl| : �g�b�v���x�����f��(�N���[�Y�R���g���[�����f���ɌŒ菬���_���f���𗘗p)
% * |controller.mdl| : �R���g���[���e���f��
% * |cruise_control.mdl| : �N���[�Y�R���g���[�����f��
% * |cruise_control_sdo.mdl| : �����p�N���[�Y�R���g���[�����f��(�Œ菬���_�A���������_(single)�o���ɑΉ�)
% * |cruise_control_prop.mdl| : �v���p�e�B���ؗp�f�����f�� (�s��Ȃ�)
% * |cruise_control_prop_error.mdl| : �v���p�e�B���ؗp�f�����f�� (�s�����)
% * |cruise_control_MILSIL.mdl| : Model-In-the-Loop Simulation �� Software-In-the-Loop Simuation (C-code)�Ƃ�Back-to-back�e�X�g�����s���郂�f���B

%%
% *�f�[�^�t�@�C��*
%
% * |cruise_control_data.m| : �N���[�Y�R���g���[�����f���f�[�^�t�@�C��
% * |transmission_data.m| : �g�����X�~�b�V�����f�[�^�t�@�C��
% * |cruise_control_flp.xls| : �����p�N���[�Y�R���g���[�����f���ŗ��p����镂�������_(single)�f�[�^�f�B�N�V���i�� (SDOxlsIF�𗘗p)
% * |cruise_control_fxp.xls| : �����p�N���[�Y�R���g���[�����f���ŗ��p�����Œ菬���_�f�[�^�f�B�N�V���i��(SDOxlsIF�𗘗p)
% * |load_float_data.m| ���������_�f�[�^�f�B�N�V���i���̓ǂݍ���
% * |load_fxpt_data.m| �Œ菬���_�f�[�^�f�B�N�V���i���̓ǂݍ���
%
% *�e�X�g����*
%
% * |TestSenario.xls| : �g�b�v���x�����f����SignalBuilder�ɓǂݍ��݉\�ȃe�X�g���͋L�q�pExcel�t�@�C��
%
% *�v���d�l���E���؎d�l��*
%
% * |CruiseControl_spec.xls|: �N���[�Y�R���g���[�����f���̗v���d�l�������؎d�l��
% * |CruiseControl_spec_q02.xls| : �N���[�Y�R���g���[�����f���̗v���d�l�������؎d�l��(���؎d�l���L��)
% * |CruiseControl_spec_ref.xls| : �N���[�Y�R���g���[�����f���̗v���d�l�������؎d�l��(|cruise_control_prop.mdl|�ŗ��p)

%% �O�����[�e�B���e�B
% �{�f����MathWorks���i���̂��̂̋@�\�̂ق��ɁAMATLAB Central����_�E�����[�h�\�Ȏ��̋@�\�𗘗p���Ă��܂��B
%
% * <http://www.mathworks.com/matlabcentral/fileexchange/31609-cmtdtool/content/cmtdtool/doc_ja/description.html cmtdtool> JMAAB ���䃂�f�����ؐ݌vWG�̊�������h���������f���x�[�X���ؕ⏕�c�[��
% * <http://www.mathworks.com/matlabcentral/fileexchange/20316-sdoxlsif-excel-interface-api-for-simulink-data-object SDOxlsIF> Excel�ŋL�q���ꂽ�f�[�^�f�B�N�V���i����Simulink Data Object�Ƃ��ēǂݍ��ރc�[��
%

%% ����
% �{�f�������s����O�ɁA�ȉ��̃N���b�N�����s���ĕK�v�ȃp�X�Ȃǂ�ݒ肵�܂��B
%
% <matlab:startup_demo �X�^�[�g�A�b�v�X�N���v�g�����s>

%%
% �f���֘A�t�@�C�����N���[���A�b�v����ꍇ�ɂ͈ȉ����N���b�N���܂��B
%
% <matlab:clear_demo �s�v�ȃt�@�C�����폜>

%% �g�b�v���x�����f���̕\��
% 
% <matlab:rundemo_helper('openTopModel') �N���b�N�Ŏ��s>

%% �R���g���[���e���f���̕\��
% �R���g���[���̐e���f����\�����܂��B���̐e���f���͕����̃��W���[������\�������
% �R���g���[���S�̂̊ȈՓI�ȍ\�����C���ɑΉ����܂��B
%
% <matlab:rundemo_helper('openCtrlModel') �N���b�N�Ŏ��s>

%% �R���g���[���q���f���̕\��
% �R���g���[���̎q���f���ł���u�N���[�Y�R���g���[�����f���v��\�����܂��B�{�f���̎����E���ؑΏۂł���A�f�[�^�t���[���C���ɑ������܂��B
%
% <matlab:rundemo_helper('openCtrlChildMdl') �N���b�N�Ŏ��s>

%% �g�b�v���x�����f���̃V�~�����[�V���������s���J�o���b�W�𑪒�
% �g�b�v���x�����f��(�R���g���[���{�v�����g)�ɑ΂���V�~�����[�V���������s���A
% ���̃e�X�g�V�i���I���ԗ����郂�f���J�o���b�W���A�R���g���[���S�̂����
% �N���[�Y�R���g���[�����f���ɑ΂��đ��肵�܂��B
%
% <matlab:rundemo_helper('runSimMesureCov') �N���b�N�Ŏ��s>

%% �V�~�����[�V�����ŕs�����������B�v�f�𖞂����e�X�g����������(���j�b�g:�N���[�Y�R���g���[��)
% �g�b�v���x�����f���ő��肳�ꂽ�J�o���b�W�ŕs�������J�o���b�W�v�f�����s����e�X�g�x�N�^��SLDV��p���Ď����������܂��B
% ���̗�́A�����E�v���f�[�^�𗬗p���A����Ȃ������������e�X�g�ŕ⊮������@�Ɠ��l�ł��B
% ���̃e�X�g�����̎��s�̑O�ɂ́A�u�g�b�v���x�����f���̃V�~�����[�V���������s���J�o���b�W�𑪒�v�����s����Ă���K�v������܂��B
%
% <matlab:rundemo_helper('getGenCovChild') �N���b�N�Ŏ��s>

%%
% ���s��ɐ��������J�o���b�W���|�[�g�́A�g�b�v���x���V�~�����[�V�����ő��肳�ꂽ���f���J�o���b�W�A
% SLDV�Ŏ����������ꂽ�e�X�g�ɑ΂��郂�f���J�o���b�W�A���҂̍��Z�J�o���b�W(==100%)�A�̍��v3�̓��e���܂܂�܂�

%% �N���[�Y�R���g���[�����f��(1���j�b�g)�ɑ΂��ăe�X�g�x�N�^����������
% �u�V�~�����[�V�����ŕs�����������B�v�f�𖞂����e�X�g�����������v�ł́A
% �V�X�e�����x���V�~�����[�V�����ł̃e�X�g�𗬗p���A�s��������SLDV�Ŏ����������܂������A
% ������̗�ł́A�����Ƀ��j�b�g���f����100%�J�o���b�W�𖞑�����e�X�g�x�N�^�������������܂��B
%
% <matlab:rundemo_helper('runTestGenerationChild') �N���b�N�Ŏ��s>

%%
% �����e�X�g�̗��p���@�ɂ́A��L�̗�̂悤��2�_�l�����܂��B
%
% * �S�̃��f���̃V�~�����[�V������A�����E�v���f�[�^����͂��邱�ƂŁA���ؑΏۂ̃��f���̋��������Ғʂ�ł��邱�Ƃ��m�F����B���̓��͂��ԗ����Ă��Ȃ�������SLDV�Ŏ����e�X�g�������s���A���̓��������Ғʂ�ł��邱�Ƃ��m�F����B
% * SLDV��p���ă��f����100%�ԗ�����e�X�g�������������A���̃e�X�g�ɑ΂��郂�f���̋��������Ғʂ�ł��邱�Ƃ��m�F����B

%% �N���[�Y�R���g���[�����f��(1���j�b�g)�ɑ΂��ăe�X�g�x�N�^����������(�Œ菬���_)
% SLDV�͕��������_�E�Œ菬���_�̑o���ɑΉ����Ă��܂��B
%
% <matlab:rundemo_helper('runTestGenerationChildFixpt') �N���b�N�Ŏ��s>

%% �v���d�l��\��
% �{�f���ł́A�v���d�l��Excel�`���ŋL�q����Ă��܂��B
% <matlab:rundemo_helper('openReqSpec') �N���b�N�Ŏ��s>

%% �g���[�T�r���e�B���|�[�g�̐���
% �{�f���ł́A�v���d�l�ƃ��f���̊Ԃɗv���g���[�T�r���e�B�ݒ肪�s���Ă��܂��B
% �ȉ������s���邱�ƂŁA���̃g���[�T�r���e�B���Ɋւ��ă��|�[�g�𐶐����܂��B
%
% <matlab:rundemo_helper('makeTraceabilityReport') �N���b�N�Ŏ��s>


%% ���f���A�h�o�C�U���J��
% ���f���K�C�h���C���`�F�b�J�[�ł��郂�f���A�h�o�C�U���J���܂��B
%
% <matlab:rundemo_helper('openModelAdvisor') �N���b�N�Ŏ��s>

%% ���f���A�h�o�C�U�`�F�b�N(MAAB���[��)�̎������s
%
% <matlab:rundemo_helper('runMAABCheck') �N���b�N�Ŏ��s>

%% ���f���A�h�o�C�U�̃J�X�^�}�C�Y�t�@�C�����J��
% ���f���A�h�o�C�U�̃`�F�b�N�́A��pAPI��p���邱�ƂŃJ�X�^�����[�����쐻���邱�Ƃ��ł��܂��B
% �ȉ����N���b�N���ĕ\�������t�H���_�ɂ́A�J�X�^�}�C�Y�̃T���v����p�ӂ��Ă��܂��B
%
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/sl_customization.m') sl_customization.m>:���f���A�h�o�C�U�̓o�^ 
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/define_ModelAdvisorChecks.m') define_ModelAdvisorChecks.m>:�o�^���e�ƃR�[���o�b�N�֐��̓o�^
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_callback.m') mycheck1_callback.m>:�`�F�b�N1�̓o�^
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_body.m') mycheck1_body.m>:�`�F�b�N1�ᔽ��API����
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_callback.m') mycheck2_callback.m>:�`�F�b�N2�̓o�^
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_body.m') mycheck2_body.m>:�`�F�b�N2�ᔽ��API����
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_action.m') mycheck2_action.m>:�`�F�b�N2�ᔽ�̎����C��

%% �v���p�e�B����
% �d�l��(���؎d�l��)�́u�������v(E��)���u���b�N�\���ŕ\�������f���ɑ΂��A�v���p�e�B���؂����{���܂��B
% �u�s�����v���f���̃v���p�e�B���؂����{����ƁA���Ⴊ���o����܂��B
% ����ƂȂ���͂��܂ރn�[�l�X���f�����V�~�����[�V�������f�o�b�O���邱�ƂŃ��r���[���܂��B
%
% * <matlab:rundemo_helper('openPropModelError') �v���p�e�B���؃��f��(�s�����)���J��>
% * <matlab:rundemo_helper('runPropProveError') �v���p�e�B���؂����s(�s�����)>
% * <matlab:rundemo_helper('openPropModel') �v���p�e�B���؃��f��(�s��Ȃ�)���J��>
% * <matlab:rundemo_helper('runPropProve') �v���p�e�B���؂����s(�s��Ȃ�)>

%%
% �f���p�̃��f����single�^�ł����A�Œ菬���_���f���ɑ΂��Ă��v���p�e�B���؂����s�\�ł��B

%% �N���[�Y�R���g���[�����f�����玩���R�[�h����(���������_)
%
% <matlab:rundemo_helper('genCodeGenFloatModel') �N���b�N�Ŏ��s>

%% �N���[�Y�R���g���[�����f�����玩���R�[�h����(�Œ菬���_)
%
% <matlab:rundemo_helper('genCodeGenFixedModel') �N���b�N�Ŏ��s>

%% �N���[�Y�R���g���[�����f���ɑ΂��鎩��Back-to-back�e�X�g���s�ƃ��|�[�g
%
% <matlab:rundemo_helper('runTestGen_MILSIL_Back2BackReport_Fixed') �N���b�N�Ŏ��s>

%% ���|�[�g�G�N�X�v���[�����J��
% MATLAB Report Generator, Simulink Report Generator �ɂ�郌�|�[�g���e��
% ���|�[�g�G�N�X�v���[���ɂ���Đݒ肳��܂��B
%
% <matlab:report �N���b�N�Ŏ��s>
