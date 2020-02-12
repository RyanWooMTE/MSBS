%% テストハーネス自動作成
%
% * MATLAB R2009b以降対応
% * Simulink Veirification and ValidationおよびSimulink Design Verifierが必要(R2009b, R2010a) 
% * Simulink Veirification and Validationが必要 (R2010b以降)
%

%% 概要
% <<d03_TestHarness/cd040_makeharness_pic01.png>>

%% 実行方法
% # cmtdtool\demoフォルダ内 cmtdtool_samplemodel.mdl を開く
% # cmtdtool 上で「ハーネスモデル作成」ボタンをクリックする
% # 新規モデル上にcmtdtool_samplemode.mdl のテストハーネスモデルが作成されていることを確認する。
% # コマンドウィンドウから以下を実行することでGUIと同様な操作が実行可能であることを確認する
open_system('cmtdtool_sample')
sldvmakeharness('cmtdtool_sample');
