function rule = sldvrule_Saturation
% sldvrule_saturation_bound Saturationブロックのブロック置換サンプル
%
% Saturationブロックによって上下限値を設定している場合に、それぞれの上下+-1
% および同値(計6個)を入力として与えるブロック置換ルールのサンプル

%   Copyright 2012 The MathWorks, Inc. 

%% ルールの登録
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% 対象となるブロックのBlockType
rule.blockType = 'Saturate';

%% 置換用ライブラリ
rule.replacementPath = sprintf('sldvdemolib_boundarytest/boundarytest_saturation');  

%% 置換モード
rule.replacementMode = 'Normal';

%% パラメータの受け渡し
% Saturationブロックの上下限値を置換後のブロックに設定する
%
parameter.LowerLimit = '$original.LowerLimit$';
parameter.UpperLimit = '$original.UpperLimit$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% ブロック置換を行うか否かをテストするコールバック関数
rule.isReplaceableCallBack = @replacementTestFunction;

%% ブロック置換に呼び出されるコールバック関数
rule.postReplacementCallBack = @postReplacementFunction;

%%
function out = replacementTestFunction(blockH)

LowerLimit = evalin('base',get_param(blockH,'LowerLimit'));
UpperLimit = evalin('base',get_param(blockH,'UpperLimit'));

if ~isempty(regexp(class(LowerLimit),'\.Parameter','once'))
    LowerLimit = LowerLimit.Value;    
end
if ~isempty(regexp(class(UpperLimit),'\.Parameter','once'))
    UpperLimit = UpperLimit.Value;    
end


% 飽和の範囲がint32で表現できる整数の範囲内であること
if (LowerLimit > double(intmin('int32')) && ...
        UpperLimit < double(intmax('int32')))
    out = true;  
else
    out = false;
end

%%
function postReplacementFunction(blockH, preReplacementCompiledInfo)  %#ok<INUSD>

