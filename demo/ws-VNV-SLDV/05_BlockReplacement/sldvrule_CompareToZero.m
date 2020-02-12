function rule = sldvrule_CompareToZero
% sldv_boundarytest_compare_rule Compare�u���b�N�̃u���b�N�u���T���v��
%
% Compare�u���b�N��萔�l�Ɣ�r���Ă���ꍇ�ɁA���̏㉺+-1����ѓ��l��
% ���͂Ƃ��ė^����u���b�N�u�����[���̃T���v��

%   Copyright 2012 The MathWorks, Inc. 

%% ���[���̓o�^
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% �ΏۂƂȂ�u���b�N��BlockType
rule.blockType = 'SubSystem';

%% �u���p���C�u����
rule.replacementPath = sprintf('sldvdemolib_boundarytest/CTZ');  

%% �u�����[�h
rule.replacementMode = 'Normal';

%% �p�����[�^�̎󂯓n��
% Compare�u���b�N�̔�r���Z�q(relop�p�����[�^)��u����̃u���b�N�ɐݒ肷��
parameter.relop = '$original.relop$';
if verLessThan('SLDV','2.1')
    parameter.OutDataTypeStr = '$original.LogicOutDataTypeMode$';
else
    parameter.OutDataTypeStr = '$original.OutDataTypeStr$';
end
parameter.ZeroCross = '$original.ZeroCross$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% �u���b�N�u�����s�����ۂ����e�X�g����R�[���o�b�N�֐�
rule.isReplaceableCallBack = @replacementTestFunction;

%% �u���b�N�u���ɌĂяo�����R�[���o�b�N�֐�
rule.postReplacementCallBack = @postReplacementFunction;

%%
function out = replacementTestFunction(blockH)
% �u�����s���ꍇ�� true ���o��
if strcmp(get_param(blockH,'MaskType'),'Compare To Zero')
    out = true;
else
    out = false;
end


%%
function postReplacementFunction(blockH, preReplacementCompiledInfo)  %#ok<INUSD>
