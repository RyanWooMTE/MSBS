% �n�[�l�X���f���̍쐬

% ���f�����J��
open_system('m_modelcov02')

% �n�[�l�X�����I�v�V�����̐ݒ�
hopts = slvnvharnessopts;
hopts.modelRefHarness = 0;

% �n�[�l�X���f���̍쐬
slvnvmakeharness(bdroot,[],hopts)

