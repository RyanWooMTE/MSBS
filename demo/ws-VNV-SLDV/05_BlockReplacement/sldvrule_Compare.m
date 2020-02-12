function rule = sldvrule_Compare
% sldvrule_Compare Compareブロックのブロック置換サンプル
%
% Compareブロックを定数値と比較している場合に、その上下+-1および同値を
% 入力として与えるブロック置換ルールのサンプル

%   Copyright 2012 The MathWorks, Inc. 

%% ルールの登録
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% 対象となるブロックのBlockType
rule.blockType = 'RelationalOperator';

%% 置換用ライブラリ
rule.replacementPath = sprintf('sldvdemolib_boundarytest/RelationalOperator');  

%% 置換モード
rule.replacementMode = 'Normal';

%% パラメータの受け渡し
% Compareブロックの比較演算子(relopパラメータ)を置換後のブロックに設定する
parameter.relop = '$original.relop$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% ブロック置換を行うか否かをテストするコールバック関数
rule.isReplaceableCallBack = @replacementTestFunction;

%% ブロック置換に呼び出されるコールバック関数
rule.postReplacementCallBack = @postReplacementFunction;

%% テスト関数
function out = replacementTestFunction(blockH)
% 置換を行う場合は true を出力
lh=get_param(blockH,'LineHandles');
const_found=false;
for n=1:length(lh.Inport)
    SrcBlock = get(lh.Inport(n),'SrcBlockHandle');
    if strcmp(get_param(SrcBlock,'BlockType'),'Constant')
        const_found=true;
    end    
end

% どちらかの入力にConstantブロックが接続されている場合のみ実行
out = const_found;

%%
function postReplacementFunction(blockH, preReplacementCompiledInfo) 

% 入力のデータ型が等しくなければTestObjectiveを無効化する
dt1 = preReplacementCompiledInfo.Inport{1}.compiledAttributes.AliasThruDataType;
dt2 = preReplacementCompiledInfo.Inport{2}.compiledAttributes.AliasThruDataType;

if ~strcmp(dt1,dt2)
    set_param(sprintf('%s/Test Objective',getfullname(blockH)),'Enabled','off')
end
