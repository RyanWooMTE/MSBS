mdl = 'sldvdemo_cruise_control'; 
open_system(mdl);    % ���f�����J��
cvto = cvtest(mdl);  % �e�X�g�I�u�W�F�N�g���`
cvdo1 = cvsim(cvto); % �V�~�����[�V����(�S����==0)���J�o���b�W�f�[�^���쐬
[stat, cvdo2] = sldvgencov(mdl,[],true,cvdo1); % ���B�J�o���b�W�𑪒�

cvhtml('combinedcov.html',cvdo1,cvdo2) % ���Z�J�o���b�W���|�[�g���쐬
