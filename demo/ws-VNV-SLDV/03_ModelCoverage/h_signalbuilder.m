% ���f�����J��
open_system('m_modelcov02_harness')
% SignalBuilder�u���b�N
blk = 'm_modelcov02_harness/Inputs';

% ���݊i�[����Ă���S�M�����擾
[time,data,sig,grp] = signalbuilder(blk);

% �V�����쐬�����f�[�^��ǉ�
newtime = [0 1 2];
newdata = {[0 1 0];[0 1 0];[0 1 0];[0 1 0];[0 1 0]};
signalbuilder(blk,'append',newtime,newdata)
