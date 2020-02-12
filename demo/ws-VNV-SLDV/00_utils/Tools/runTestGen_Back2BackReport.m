%% 指定モデルに対して、自動テスト生成、カバレッジ測定、MIL-SIL Back-to-back testの自動レポートを作成

% 初期化
clear all
bdclose all

mdl = 'cruise_control';

open_system(mdl);
cruise_control_data
% xlsreadsdo('cruise_control_flp.xls','mpt')
% xlsreadsdo('cruise_control_flp.xls','Simulink',{'NumericType'})
xlsreadsdo('cruise_control_fxp.xls','mpt')
xlsreadsdo('cruise_control_fxp.xls','Simulink',{'NumericType'})



%% 自動テスト生成

opts = sldvoptions();
opts.ModelReferenceHarness='on';
run_SLDV_testgen(mdl,opts)

%% モデルカバレッジ測定
HarnessModel = [mdl '_harness'];
run_Sim_GetCov(HarnessModel)

harnssblk = [HarnessModel '/Test Unit (copied from ' mdl ')'];

%% MIL-SIL back-to-back test モデル作成
makeMILSILharness(HarnessModel)
MILSILModel = [mdl '_MILSIL'];
save_system(HarnessModel,MILSILModel)

%% テスト自動実行とレポート自動生成
obj = runCMTDReport([MILSILModel '/S_Function_Block']);
obj.runSimAll;
obj.runReport
