%% cmtdtool

%% 概要
% cmtdtoolは制御モデルの検証に利用可能な補助ツールです。
% 当初、このツールは、JMAAB-CMTD-WG (JMAAB: Japan MBD Automotive Advisory Board, 
% CMTD-WG: 制御モデル検証設計(Contol Model Test Design) Working Group)向けに
% 作成されましたが、数度の改変を経て、MATLAB Centralから一般に公開されました。
%
% 制御モデルのテストを実施する際には、テスト設計、テストモデルの構築、テスト実行、
% レポートが行われますが、このツールは、これらのフェーズにおいて必要となる
% 手作業を可能な限り削減し、自動化します。
% 
%% (1) ExcelからSignalBuilder
%
% * <cd010_xls2SignalBuilder.html Excel選択からSignalBuilderを作成>
% Excel上で選択されている領域の時系列データをSignalBuilder上に取り込み(新規作成、追加、置換)ます。
% * <cd015_xls2SignalBuilder_multiple.html Excel選択からSignalBuilderを作成(一括)> 
% 現在開いているExcelのシートに定義されている複数の時系列信号を一括してSignalBuilder上に取り込みます。
%
%% (2) Excelから真理値表
%
% * <cd020_xls2TruthTable.html 真理値表を作成>
% Excel上に定義された真理値表をTruthTableブロックとして取り込みます。
% * <cd030_xls2VerificationTruthTable.html 検証用真理値表を作成>
% Excel上で記述した検査式をTruthTableブロックとして取り込みます。
% * <cd035_xls2TestObjective.html ユーザ定義テスト作成> 
% Excel上で記述した入力と期待出力値との組み合わせから、その関係を自動チェック可能なブロックを作成します。
% * <cd040_xls2RequirementBaseTestTruthTable.html 要件ベーステスト用サブシステム作成> 
% Excel上で記述した検査式を、要件ベーステスト用に取り込みます。
%
%% (3) テストハーネス自動生成
%
% * <cd040_makeharness.html テストハーネスモデル作成>
% 単体コントローラモデルからテストハーネスモデル(SignalBuilder + データ変換 + コントローラ)を作成します。
% * <cd050_makeharness_compareresults.html 期待出力一致確認用ハーネスモデル自動生成>
% テスト入力と期待値を入力とし、コントローラ出力と期待値との一致性を確認するためのハーネスモデルを作成します。
%
%% (4) テスト自動実行とレポート自動生成
%
% * <cd060_runCMTDReport.html テストレポート自動生成>
% 期待出力一致確認用ハーネスモデルに含まれるSignalBuiderブロックの各信号タブを自動実行し、テストレポートを自動的に作成します。
%
% <<description_pic00.png>> 
%

%% 更新履歴
% * 2010/06/29 JMAAB-CMTD-WG向けに初版公開
% * 2010/08/04 JMAAB-CMTD-WG向けに修正版公開
% * 2010/11/04 JMAAB-CMTD-WG向けにv0.8公開
% * 2011/02/14 JMAAB-CMTD-WG向けにv0.9公開
% * 2011/05/27 MATLAB Centralにv1.0をアップロード.
% * 2011/12/28 MATLAB Centralにv1.1をアップロード.
% * 2012/12/12 v1.2 をリリース