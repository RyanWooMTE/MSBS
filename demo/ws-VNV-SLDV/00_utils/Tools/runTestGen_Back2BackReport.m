%% �w�胂�f���ɑ΂��āA�����e�X�g�����A�J�o���b�W����AMIL-SIL Back-to-back test�̎������|�[�g���쐬

% ������
clear all
bdclose all

mdl = 'cruise_control';

open_system(mdl);
cruise_control_data
% xlsreadsdo('cruise_control_flp.xls','mpt')
% xlsreadsdo('cruise_control_flp.xls','Simulink',{'NumericType'})
xlsreadsdo('cruise_control_fxp.xls','mpt')
xlsreadsdo('cruise_control_fxp.xls','Simulink',{'NumericType'})



%% �����e�X�g����

opts = sldvoptions();
opts.ModelReferenceHarness='on';
run_SLDV_testgen(mdl,opts)

%% ���f���J�o���b�W����
HarnessModel = [mdl '_harness'];
run_Sim_GetCov(HarnessModel)

harnssblk = [HarnessModel '/Test Unit (copied from ' mdl ')'];

%% MIL-SIL back-to-back test ���f���쐬
makeMILSILharness(HarnessModel)
MILSILModel = [mdl '_MILSIL'];
save_system(HarnessModel,MILSILModel)

%% �e�X�g�������s�ƃ��|�[�g��������
obj = runCMTDReport([MILSILModel '/S_Function_Block']);
obj.runSimAll;
obj.runReport
