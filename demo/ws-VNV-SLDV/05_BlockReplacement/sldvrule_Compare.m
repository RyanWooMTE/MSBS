function rule = sldvrule_Compare
% sldvrule_Compare Compare�u���b�N�̃u���b�N�u���T���v��
%
% Compare�u���b�N��萔�l�Ɣ�r���Ă���ꍇ�ɁA���̏㉺+-1����ѓ��l��
% ���͂Ƃ��ė^����u���b�N�u�����[���̃T���v��

%   Copyright 2012 The MathWorks, Inc. 

%% ���[���̓o�^
rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% �ΏۂƂȂ�u���b�N��BlockType
rule.blockType = 'RelationalOperator';

%% �u���p���C�u����
rule.replacementPath = sprintf('sldvdemolib_boundarytest/RelationalOperator');  

%% �u�����[�h
rule.replacementMode = 'Normal';

%% �p�����[�^�̎󂯓n��
% Compare�u���b�N�̔�r���Z�q(relop�p�����[�^)��u����̃u���b�N�ɐݒ肷��
parameter.relop = '$original.relop$';

% Register the parameter mapping associated with this rule
rule.parameterMap = parameter;

%% �u���b�N�u�����s�����ۂ����e�X�g����R�[���o�b�N�֐�
rule.isReplaceableCallBack = @replacementTestFunction;

%% �u���b�N�u���ɌĂяo�����R�[���o�b�N�֐�
rule.postReplacementCallBack = @postReplacementFunction;

%% �e�X�g�֐�
function out = replacementTestFunction(blockH)
% �u�����s���ꍇ�� true ���o��
lh=get_param(blockH,'LineHandles');
const_found=false;
for n=1:length(lh.Inport)
    SrcBlock = get(lh.Inport(n),'SrcBlockHandle');
    if strcmp(get_param(SrcBlock,'BlockType'),'Constant')
        const_found=true;
    end    
end

% �ǂ��炩�̓��͂�Constant�u���b�N���ڑ�����Ă���ꍇ�̂ݎ��s
out = const_found;

%%
function postReplacementFunction(blockH, preReplacementCompiledInfo) 

% ���͂̃f�[�^�^���������Ȃ����TestObjective�𖳌�������
dt1 = preReplacementCompiledInfo.Inport{1}.compiledAttributes.AliasThruDataType;
dt2 = preReplacementCompiledInfo.Inport{2}.compiledAttributes.AliasThruDataType;

if ~strcmp(dt1,dt2)
    set_param(sprintf('%s/Test Objective',getfullname(blockH)),'Enabled','off')
end
