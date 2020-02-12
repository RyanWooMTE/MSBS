%% モデル検証デモ
%

%% デモファイル構成
% 本デモは以下のファイルで構成されています。
%
% *デモ実行ユーティリティ*
%
% * |ModelVerificationDemo.html| デモ実行用HTMLファイル
% * |startup_demo.m|: デモ実行環境設定ファイル
%
%
% *モデル*
%
% * |cruise_control_top.mdl| : トップレベルモデル
% * |cruise_control_top_fixpt.mdl| : トップレベルモデル(クルーズコントロールモデルに固定小数点モデルを利用)
% * |controller.mdl| : コントローラ親モデル
% * |cruise_control.mdl| : クルーズコントロールモデル
% * |cruise_control_sdo.mdl| : 実装用クルーズコントロールモデル(固定小数点、浮動小数点(single)双方に対応)
% * |cruise_control_prop.mdl| : プロパティ検証用デモモデル (不具合なし)
% * |cruise_control_prop_error.mdl| : プロパティ検証用デモモデル (不具合あり)
% * |cruise_control_MILSIL.mdl| : Model-In-the-Loop Simulation と Software-In-the-Loop Simuation (C-code)とのBack-to-backテストを実行するモデル。

%%
% *データファイル*
%
% * |cruise_control_data.m| : クルーズコントロールモデルデータファイル
% * |transmission_data.m| : トランスミッションデータファイル
% * |cruise_control_flp.xls| : 実装用クルーズコントロールモデルで利用される浮動小数点(single)データディクショナリ (SDOxlsIFを利用)
% * |cruise_control_fxp.xls| : 実装用クルーズコントロールモデルで利用される固定小数点データディクショナリ(SDOxlsIFを利用)
% * |load_float_data.m| 浮動小数点データディクショナリの読み込み
% * |load_fxpt_data.m| 固定小数点データディクショナリの読み込み
%
% *テスト入力*
%
% * |TestSenario.xls| : トップレベルモデルのSignalBuilderに読み込み可能なテスト入力記述用Excelファイル
%
% *要求仕様書・検証仕様書*
%
% * |CruiseControl_spec.xls|: クルーズコントロールモデルの要求仕様書兼検証仕様書
% * |CruiseControl_spec_q02.xls| : クルーズコントロールモデルの要求仕様書兼検証仕様書(検証仕様未記入)
% * |CruiseControl_spec_ref.xls| : クルーズコントロールモデルの要求仕様書兼検証仕様書(|cruise_control_prop.mdl|で利用)

%% 外部ユーティリティ
% 本デモはMathWorks製品そのものの機能のほかに、MATLAB Centralからダウンロード可能な次の機能を利用しています。
%
% * <http://www.mathworks.com/matlabcentral/fileexchange/31609-cmtdtool/content/cmtdtool/doc_ja/description.html cmtdtool> JMAAB 制御モデル検証設計WGの活動から派生したモデルベース検証補助ツール
% * <http://www.mathworks.com/matlabcentral/fileexchange/20316-sdoxlsif-excel-interface-api-for-simulink-data-object SDOxlsIF> Excelで記述されたデータディクショナリをSimulink Data Objectとして読み込むツール
%

%% 準備
% 本デモを実行する前に、以下のクリックを実行して必要なパスなどを設定します。
%
% <matlab:startup_demo スタートアップスクリプトを実行>

%%
% デモ関連ファイルをクリーンアップする場合には以下をクリックします。
%
% <matlab:clear_demo 不要なファイルを削除>

%% トップレベルモデルの表示
% 
% <matlab:rundemo_helper('openTopModel') クリックで実行>

%% コントローラ親モデルの表示
% コントローラの親モデルを表示します。この親モデルは複数のモジュールから構成される
% コントローラ全体の簡易的な構造レイヤに対応します。
%
% <matlab:rundemo_helper('openCtrlModel') クリックで実行>

%% コントローラ子モデルの表示
% コントローラの子モデルである「クルーズコントロールモデル」を表示します。本デモの実装・検証対象であり、データフローレイヤに相当します。
%
% <matlab:rundemo_helper('openCtrlChildMdl') クリックで実行>

%% トップレベルモデルのシミュレーションを実行しカバレッジを測定
% トップレベルモデル(コントローラ＋プラント)に対するシミュレーションを実行し、
% そのテストシナリオが網羅するモデルカバレッジを、コントローラ全体および
% クルーズコントロールモデルに対して測定します。
%
% <matlab:rundemo_helper('runSimMesureCov') クリックで実行>

%% シミュレーションで不足した未到達要素を満たすテストを自動生成(ユニット:クルーズコントロール)
% トップレベルモデルで測定されたカバレッジで不足したカバレッジ要素を実行するテストベクタをSLDVを用いて自動生成します。
% この例は、実験・計測データを流用し、足りない部分を自動テストで補完する方法と同様です。
% このテスト生成の実行の前には、「トップレベルモデルのシミュレーションを実行しカバレッジを測定」が実行されている必要があります。
%
% <matlab:rundemo_helper('getGenCovChild') クリックで実行>

%%
% 実行後に生成されるカバレッジレポートは、トップレベルシミュレーションで測定されたモデルカバレッジ、
% SLDVで自動生成されたテストに対するモデルカバレッジ、両者の合算カバレッジ(==100%)、の合計3つの内容が含まれます

%% クルーズコントロールモデル(1ユニット)に対してテストベクタを自動生成
% 「シミュレーションで不足した未到達要素を満たすテストを自動生成」では、
% システムレベルシミュレーションでのテストを流用し、不足部分をSLDVで自動生成しましたが、
% こちらの例では、純粋にユニットモデルの100%カバレッジを満足するテストベクタを自動生成します。
%
% <matlab:rundemo_helper('runTestGenerationChild') クリックで実行>

%%
% 自動テストの利用方法には、上記の例のように2点考えられます。
%
% * 全体モデルのシミュレーションや、実験・計測データを入力することで、検証対象のモデルの挙動が期待通りであることを確認する。その入力が網羅していない部分をSLDVで自動テスト生成を行い、その動きが期待通りであることを確認する。
% * SLDVを用いてモデルを100%網羅するテストを自動生成し、そのテストに対するモデルの挙動が期待通りであることを確認する。

%% クルーズコントロールモデル(1ユニット)に対してテストベクタを自動生成(固定小数点)
% SLDVは浮動小数点・固定小数点の双方に対応しています。
%
% <matlab:rundemo_helper('runTestGenerationChildFixpt') クリックで実行>

%% 要求仕様を表示
% 本デモでは、要求仕様がExcel形式で記述されています。
% <matlab:rundemo_helper('openReqSpec') クリックで実行>

%% トレーサビリティレポートの生成
% 本デモでは、要求仕様とモデルの間に要求トレーサビリティ設定が行われています。
% 以下を実行することで、そのトレーサビリティ情報に関してレポートを生成します。
%
% <matlab:rundemo_helper('makeTraceabilityReport') クリックで実行>


%% モデルアドバイザを開く
% モデルガイドラインチェッカーであるモデルアドバイザを開きます。
%
% <matlab:rundemo_helper('openModelAdvisor') クリックで実行>

%% モデルアドバイザチェック(MAABルール)の自動実行
%
% <matlab:rundemo_helper('runMAABCheck') クリックで実行>

%% モデルアドバイザのカスタマイズファイルを開く
% モデルアドバイザのチェックは、専用APIを用いることでカスタムルールを作製することができます。
% 以下をクリックして表示されるフォルダには、カスタマイズのサンプルを用意しています。
%
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/sl_customization.m') sl_customization.m>:モデルアドバイザの登録 
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/define_ModelAdvisorChecks.m') define_ModelAdvisorChecks.m>:登録内容とコールバック関数の登録
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_callback.m') mycheck1_callback.m>:チェック1の登録
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_body.m') mycheck1_body.m>:チェック1違反のAPI検索
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_callback.m') mycheck2_callback.m>:チェック2の登録
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_body.m') mycheck2_body.m>:チェック2違反のAPI検索
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_action.m') mycheck2_action.m>:チェック2違反の自動修正

%% プロパティ検証
% 仕様書(検証仕様書)の「検査式」(E列)をブロック表現で表したモデルに対し、プロパティ検証を実施します。
% 「不具合あり」モデルのプロパティ検証を実施すると、反例が検出されます。
% 反例となる入力を含むハーネスモデルをシミュレーションしデバッグすることでレビューします。
%
% * <matlab:rundemo_helper('openPropModelError') プロパティ検証モデル(不具合あり)を開く>
% * <matlab:rundemo_helper('runPropProveError') プロパティ検証を実行(不具合あり)>
% * <matlab:rundemo_helper('openPropModel') プロパティ検証モデル(不具合なし)を開く>
% * <matlab:rundemo_helper('runPropProve') プロパティ検証を実行(不具合なし)>

%%
% デモ用のモデルはsingle型ですが、固定小数点モデルに対してもプロパティ検証を実行可能です。

%% クルーズコントロールモデルから自動コード生成(浮動小数点)
%
% <matlab:rundemo_helper('genCodeGenFloatModel') クリックで実行>

%% クルーズコントロールモデルから自動コード生成(固定小数点)
%
% <matlab:rundemo_helper('genCodeGenFixedModel') クリックで実行>

%% クルーズコントロールモデルに対する自動Back-to-backテスト実行とレポート
%
% <matlab:rundemo_helper('runTestGen_MILSIL_Back2BackReport_Fixed') クリックで実行>

%% レポートエクスプローラを開く
% MATLAB Report Generator, Simulink Report Generator によるレポート内容は
% レポートエクスプローラによって設定されます。
%
% <matlab:report クリックで実行>
