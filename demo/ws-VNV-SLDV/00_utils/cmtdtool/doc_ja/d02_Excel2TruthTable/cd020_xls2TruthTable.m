%% Excel上の真理値表からTruth Tableブロックを作成
%
% * MATLAB R2007a以降対応
% * Stateflow必要

%% 概要
% (1) Excel上で真理値表を作成し範囲を選択
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic01.png>>
%
% (2) *真理値表を作成*ボタンをクリック
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic02.png>>
%
% (3) TruthTableブロックが作成される (Stateflow)
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic03.png>>
%
% (4) Excel上の真理値表がTruthTableブロックで表現される
% 
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic04.png>>
%

%% Excel記述例
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic05.png>>
%
% * 入力条件、出力条件の組み合わせに該当するパターン(p1,p2,..)を指定する。
% 
% * MATLAB上では、入力条件に合致する入力パターンを与えた場合に、
% シミュレーション結果から得られる信号値が出力条件に一致することを
% 確認する。
% 

%% TruthTableブロック詳細
%
% * 条件式中の変数をブロック入力とする(WSで定義済みの変数はParameterとする)
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic06.png>>
%
% * *条件式*
% D1列から順番に評価し、列の全ての条件に合致した場合、その番号のアクションを実行
% ブロック出力は合致した条件列の番号
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic07.png>>
%
% 
 
%% モデルイメージ
%
% <<d02_Excel2TruthTable/cd020_xls2TruthTable_pic08.png>>
%

%% 真理値表記述ルール詳細
% * 第1列「説明」： モデル中のコメントとして利用されます。シミュレーションには直接影響を与えません。
% * 第2列「条件式」：  第1列に対応する条件式を記述します。算術演算子、論理演算子、比較演算子を含むMATLAB式で記述します。
% * 第3列以降： 各条件式に対する真(T), 偽(F), どちらでも(-) を記述します。第3列目から右方向に 全ての行に対して合致するかどうかを判定し、合致した場合には、その列数(p1列ならば1、p6列ならば6、など)を返すTruthTable ブロックが作成されます。
% * 最終列： 第3列～最終-1列までの条件に合致しないケースとして、「例外」列を記述します。全ての列が 「-」で表記されます。例外に該当した場合、TruthTableは0を返します。
% * 必要に応じて行、列を追加してください。
% 
% *注意事項*
%
% * 条件式内のMATLAB変数として許容される文字列は自動的にTruthTableブロックの入力として設定されます。
% * 条件式に、MATLAB ベースワークスペース上で定義済みの変数が利用されている場合、TruthTable ブロック内でパラメータとして利用され、ブロック入力にななりません。


%% デモ実行方法
% # cmtdtool\demoフォルダ内 cmtdtool_sampledata.xls を開く
% # 「真理値表」タブ内 E3:M10を選択する
% # cmtdtool 上で「真理値表を作成」ボタンをクリックする
% # 新規モデル上にTruth Table ブロックが作成されていることを確認する
% # コマンドウィンドウから以下を実行することでGUIと同様な操作が実行可能であることを確認する
xls2TruthTable('cmtdtool_sampledata.xls','真理値表','E3:M10');
