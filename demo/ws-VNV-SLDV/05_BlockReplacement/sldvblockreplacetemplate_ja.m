function rule = sldvblockreplacetemplate_ja
%SLDVBLOCKREPLACETEMPLATE Template for a Simulink Design Verifier block
%replacement rule
%   
%   A Simulink Design Verifier block replacement rule is written as a 
%   MATLAB function with the same name as your rule. Replace 
%   'sldvblockreplacetemplate' with the name of your rule. 
%
%
%   Copyright 2007-2012 The MathWorks, Inc.

%% Registration
% SLDVのBlockReplacement機能を利用するために必要な rule オブジェクトの定義
% 次の2行は変更しないでください。

rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% Target Block Type
% 置き換え(置き換えられる)元のブロックタイプ(BlockType)を指定します。
% 例えば「Trigonometryブロック」を置き換えるルールを指定する場合は、
% 置き換え対象のブロックを選択し
% get_param(gcb,'BlockType') 
% を実行することで ブロックタイプを取得することが可能です。

rule.blockType = 'Lookup';

%% Replacement Library 
% 置き換え後にコピーされるブロックを指定します。
% ユーザのカスタム置換ルールを設定する場合には、新たなライブラリを作成する必要があります。
% このブロックは、ライブラリ中のマスクサブシステムでなければなりません。

rule.replacementPath = sprintf('sldvblockreplacementlib/Lookup Table TO');  

%% Replacement Mode
% 次の2つのどちらかを指定します。
% 'Normal' : 通常はこちらを指定します。置換後にはライブラリリンクが無効化されます。
% 'ConfigurableSubSystem': 置換後のブロックがConfigurable SubSystemの場合はこちらを指定します。

rule.replacementMode = 'Normal';

%% Parameter Handling パラメータ操作
% 置換されるブロックから継承されるパラメータをここで指定します。
% 元のブロックから置き換え後のブロックへのパラメータ名がマップされた構造体を定義します。
% 構造体のフィールドは置換後のブロックのパラメータ名に対応し、フィールド値は
% 継承されるパラメータ値となります。
% 識別子 $original.parameter$ によって構造体のフィールド値を指定します。
% ここで、'parameter'は元のブロックのパラメータ名です。

% 例: ここでは、ブロック置換ルールとして、Lookup Tableブロックを、
% マスクサブシステムに置き換える例をしめします。ここで、マスクサブシステム内では
% Test Objectiveが入力ポートに接続されたLookup Tableが配置されています。
% 次のコードは、元のLookupTableブロックからいくつかのパラメータを置換ブロックに
% 継承しています。
% また、Test Objectiveブロックの値を、LookupTableの全てのテーブル値を使用するよう
% 設定しています。

parameter.XLookUpData = '$original.InputValues$';
parameter.YLookUpData = '$original.OutputValues$';
parameter.LookUpMeth = '$original.LookUpMeth$';     

parameter.OutDataTypeMode = '$original.OutDataTypeMode$';    
parameter.RndMeth = '$original.RndMeth$';
parameter.SaturateOnIntegerOverflow = '$original.SaturateOnIntegerOverflow$';

parameter.intervals = 'mdl_blockreplacement_maskutil(''vec2ranges'',$original.InputValues$)';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% Replacement Test Callback
% サブ関数 replacementTestFunction は、Simulink Design Verifierによる
% ここで指定されたルールによってブロック置換が行われる条件を指定します。

rule.isReplaceableCallBack = @replacementTestFunction;

%% Post Replacement Callback
% サブ関数 postReplacementFunction はブロックが置換された後に実行される
% 処理を記述します。
% この関数の使用は必須ではありませんので、関数が定義されていなくても問題ありません。

rule.postReplacementCallBack = @postReplacementFunction;

%%
function out = replacementTestFunction(blockH)
% Simulink Design Verifierによって置換を行う条件を記述します。
% たとえば、ブロックのパラメータがある値を持つときにのみ置換を実行する場合など
% に利用されます。

acceptedOutDataTypeModes = {'double','single',...
                            'Inherit via back propagation',...
                            'Same as input'};

out = true;  
I = strmatch(get_param(blockH,'OutDataTypeMode'),acceptedOutDataTypeModes,'exact');
if isempty(I),
    out = false;
end      

%%
function postReplacementFunction(blockH, preReplacementCompiledInfo)
%
%                     blockH = 置換されたブロックのハンドル番号
%
% preReplacementCompiledInfo = ブロック置換される前のモデルに対するコンパイル時情報
%                              この構造体は次のようになります。
% 
%   preReplacementCompiledInfo = 
%
%             numOfInports: 1
%            numOfOutports: 1
%         numOfEnablePorts: 0
%        numOfTriggerPorts: 0
%                 Ifaction: []
%                   Inport: {[1x1 struct]}
%                  Outport: {[1x1 struct]}
%
% 
%   preReplacementCompiledInfo.Inport{1}.compiledAttributes = 
% 
%                  DataType: 'double'
%         AliasThruDataType: 'double'
%                Dimensions: 1
%              DimensionStr: '1'
%              SamplingMode: 'Sample based'
%                Complexity: 'real'
%                SampleTime: [0.1000 0]
%             SampleTimeStr: '[0.10000000000000001,0]'
%               IsTriggered: 0
%               IsStructBus: 0
%
% このコールバック関数の使用例に関しては以下のM-ファイルをご覧ください。
% matlabroot/toolbox/sldv/sldv/private/blkrep_rule_selectorIndexVecPort_normal.m