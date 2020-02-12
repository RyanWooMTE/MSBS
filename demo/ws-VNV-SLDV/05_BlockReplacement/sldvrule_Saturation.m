function rule = sldvrule_Saturation
% sldvrule_saturation_bound Saturation�u���b�N�̃u���b�N�u���T���v��
%
% Saturation�u���b�N�ɂ���ď㉺���l��ݒ肵�Ă���ꍇ�ɁA���ꂼ��̏㉺+-1
% ����ѓ��l(�v6��)����͂Ƃ��ė^����u���b�N�u�����[���̃T���v��

%   Copyright 2012 The MathWorks, Inc. 

%% ���[���̓o�^
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% �ΏۂƂȂ�u���b�N��BlockType
rule.blockType = 'Saturate';

%% �u���p���C�u����
rule.replacementPath = sprintf('sldvdemolib_boundarytest/boundarytest_saturation');  

%% �u�����[�h
rule.replacementMode = 'Normal';

%% �p�����[�^�̎󂯓n��
% Saturation�u���b�N�̏㉺���l��u����̃u���b�N�ɐݒ肷��
%
parameter.LowerLimit = '$original.LowerLimit$';
parameter.UpperLimit = '$original.UpperLimit$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% �u���b�N�u�����s�����ۂ����e�X�g����R�[���o�b�N�֐�
rule.isReplaceableCallBack = @replacementTestFunction;

%% �u���b�N�u���ɌĂяo�����R�[���o�b�N�֐�
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


% �O�a�͈̔͂�int32�ŕ\���ł��鐮���͈͓̔��ł��邱��
if (LowerLimit > double(intmin('int32')) && ...
        UpperLimit < double(intmax('int32')))
    out = true;  
else
    out = false;
end

%%
function postReplacementFunction(blockH, preReplacementCompiledInfo)  %#ok<INUSD>

