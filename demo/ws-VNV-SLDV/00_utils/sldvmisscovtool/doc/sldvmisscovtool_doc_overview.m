%% Simulink Design Verifierによる未達カバレッジ解析ツール
%
%% 対応バージョン
% 
% * MATLAB R2007a+ 以降

%% 使用製品
% 
% * MATLAB
% * Simulink
% * Stateflow (対象モデルにStateflowが含まれる場合)
% * Simulink Verification and Validation
% * Simulink Design Verifier (未達成のカバレッジを補うテストベクタを自動生成する場合)
 
%% インストール方法
% 
% 
% # sldvmisscovtool.zip を適当なフォルダに展開します。
% # MATLAB デスクトップ環境より
%    「ファイル」→「パス設定」
%    を開き、(1)で展開したフォルダをMATLABパスに追加します。
% 
%% 起動方法
% 
% 
% MATLAB Command Windowより
% 
sldvmisscovtool
 
%% 
% を実行します。


%% その他
% 
% * *固定小数点対応*
% このツールは、MATLAB R2009a以降でご利用の場合、固定小数点モデルに対する利用が対応しています。

%% 更新履歴
% * 2008/02/13 : 初版リリース
% * 2008/06/23 : ルートレベルInportのデータタイプが「継承」の場合に対応
% * 2008/10/31 : MATLAB Centralで公開
% * 2009/01/07 : エラー回避などの小修正の実施
% * 2009/06/28 : 第2版をMATLAB Centralでリリース。プラグインインポート・エクスポートに対応
% * 2010/05/06 : 第3版をMATLAB Centralでリリース。Signal Viewer機能を追加。固定小数点(R2009a以降)に対応。
% * 2011/12/28 : 第4版をMATLAB Centralでリリース。MATLAB Helpにヘルプドキュメントを追加。R2010b以降での日本語環境検出をサポート。
