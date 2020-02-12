function rule = sldvrule_CompareToZero
% sldv_boundarytest_compare_rule Compareブロックのブロック置換サンプル
%
% Compareブロックを定数値と比較している場合に、その上下+-1および同値を
% 入力として与えるブロック置換ルールのサンプル

%   Copyright 2012 The MathWorks, Inc. 

%% ルールの登録
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% 対象となるブロックのBlockType
rule.blockType = 'SubSystem';

%% 置換用ライブラリ
rule.replacementPath = sprintf('sldvdemolib_boundarytest/CTZ');  

%% 置換モード
rule.replacementMode = 'Normal';

%% パラメータの受け渡し
% Compareブロックの比較演算子(relopパラメータ)を置換後のブロックに設定する
parameter.relop = '$original.relop$';
if verLessThan('SLDV','2.1')
    parameter.OutDataTypeStr = '$original.LogicOutDataTypeMode$';
else
    parameter.OutDataTypeStr = '$original.OutDataTypeStr$';
end
parameter.ZeroCross = '$original.ZeroCross$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% ブロック置換を行うか否かをテストするコールバック関数
rule.isReplaceableCallBack = @replacementTestFunction;

%% ブロック置換に呼び出されるコールバック関数
rule.postReplacementCallBack = @postReplacementFunction;

%%
function out = replacementTestFunction(blockH)
% 置換を行う場合は true を出力
if strcmp(get_param(blockH,'MaskType'),'Compare To Zero')
    out = true;
else
    out = false;
end


%%
function postReplacementFunction(blockH, preReplacementCompiledInfo)  %#ok<INUSD>
