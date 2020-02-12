%% 対応フォーマット


%% 定数
% 対象の文字列がベースワークスペースに定義されている変数名と同名であり、
% パラメータオブジェクト(*.Parameter)もしくは次のベース型
%
% * logical
% * int8
% * int16
% * int32
% * int8
% * int16
% * int32
% * double
% * single
%
% のいづれかの場合、
% 定数として扱われ、ConstantブロックのValueパラメータに定義されます。
% データ型は「Inherit: Inherit via back propagation」になります。

%% 入力ポート
% 対象の文字列が次の条件に合致する場合には入力ポートとして扱われます。
%
% * 定数ではない
% * 予約語ではない

%% 対応演算子
% 対応演算子とその優先順位は基本的に
% <matlab:web(['jar:file:///',docroot,'/techdoc/help.jar!/matlab_prog/f0-40063.html#bqjivpq'],'-helpbrowser') MATLAB言語>の優先順位に従います。
%
% * カッコ ()
% * 組み込み関数 
% * 単項演算 |+, -|
% * キャスト (|single, double, uint8, uint16, uint32, int8, int16, int32, 固定小数点書式 例:fixdt(1,16,2,0)|)
% * 論理否定 |~|
% * 乗算除算 |* / %(mod)|
% * 加減算 + -
% * 比較演算 |==, <, >, <=, >=, ~=|
% * |AND &&|
% * |OR || |
% * ならば(Implies): |==>|, WithinImplies: |==>>|, Implies with Test Objective: |=@>| 

%% 組み込み関数 
%
% |*abs*([expr])|
% : 絶対値
%
% |*prev*([expr],[Integer])|
% : |[Integer]| ステップ前の値
%
% 例) |prev(A,1)| : Aの前回値
%
% |*init*([expr],[Integer])|
% ステップ0から |[Integer]| ステップ間は |[expr]| が成立する
%
% |*after*([expr],[INTEGER])| 
% : |[expr]| が |[INTEGER]| ステップ以上成立すれば真を出力
%
% |*withinImplies*([expr],[expr])|
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/withinimplies.html'],'-helpbrowser') Simulink Design Verifierで提供されるWithin Impliesブロック>
%
% |*extend*([expr],[INTEGER])|
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/extender.html'],'-helpbrowser') Simulink Design Verifierで提供されるExtenderブロック>
%
% |*detect*([expr],[INTEGER])| 
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/detector.html'],'-helpbrowser') Simulink Design Verifierで提供されるDetectorブロック>

