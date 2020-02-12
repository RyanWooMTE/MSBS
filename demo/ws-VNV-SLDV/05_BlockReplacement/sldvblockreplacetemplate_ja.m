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
% SLDV��BlockReplacement�@�\�𗘗p���邽�߂ɕK�v�� rule �I�u�W�F�N�g�̒�`
% ����2�s�͕ύX���Ȃ��ł��������B

rule = SldvBlockReplacement.blockreprule; 
rule.fileName = mfilename;

%% Target Block Type
% �u������(�u����������)���̃u���b�N�^�C�v(BlockType)���w�肵�܂��B
% �Ⴆ�΁uTrigonometry�u���b�N�v��u�������郋�[�����w�肷��ꍇ�́A
% �u�������Ώۂ̃u���b�N��I����
% get_param(gcb,'BlockType') 
% �����s���邱�Ƃ� �u���b�N�^�C�v���擾���邱�Ƃ��\�ł��B

rule.blockType = 'Lookup';

%% Replacement Library 
% �u��������ɃR�s�[�����u���b�N���w�肵�܂��B
% ���[�U�̃J�X�^���u�����[����ݒ肷��ꍇ�ɂ́A�V���ȃ��C�u�������쐬����K�v������܂��B
% ���̃u���b�N�́A���C�u�������̃}�X�N�T�u�V�X�e���łȂ���΂Ȃ�܂���B

rule.replacementPath = sprintf('sldvblockreplacementlib/Lookup Table TO');  

%% Replacement Mode
% ����2�̂ǂ��炩���w�肵�܂��B
% 'Normal' : �ʏ�͂�������w�肵�܂��B�u����ɂ̓��C�u���������N������������܂��B
% 'ConfigurableSubSystem': �u����̃u���b�N��Configurable SubSystem�̏ꍇ�͂�������w�肵�܂��B

rule.replacementMode = 'Normal';

%% Parameter Handling �p�����[�^����
% �u�������u���b�N����p�������p�����[�^�������Ŏw�肵�܂��B
% ���̃u���b�N����u��������̃u���b�N�ւ̃p�����[�^�����}�b�v���ꂽ�\���̂��`���܂��B
% �\���̂̃t�B�[���h�͒u����̃u���b�N�̃p�����[�^���ɑΉ����A�t�B�[���h�l��
% �p�������p�����[�^�l�ƂȂ�܂��B
% ���ʎq $original.parameter$ �ɂ���č\���̂̃t�B�[���h�l���w�肵�܂��B
% �����ŁA'parameter'�͌��̃u���b�N�̃p�����[�^���ł��B

% ��: �����ł́A�u���b�N�u�����[���Ƃ��āALookup Table�u���b�N���A
% �}�X�N�T�u�V�X�e���ɒu�������������߂��܂��B�����ŁA�}�X�N�T�u�V�X�e�����ł�
% Test Objective�����̓|�[�g�ɐڑ����ꂽLookup Table���z�u����Ă��܂��B
% ���̃R�[�h�́A����LookupTable�u���b�N���炢�����̃p�����[�^��u���u���b�N��
% �p�����Ă��܂��B
% �܂��ATest Objective�u���b�N�̒l���ALookupTable�̑S�Ẵe�[�u���l���g�p����悤
% �ݒ肵�Ă��܂��B

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
% �T�u�֐� replacementTestFunction �́ASimulink Design Verifier�ɂ��
% �����Ŏw�肳�ꂽ���[���ɂ���ău���b�N�u�����s����������w�肵�܂��B

rule.isReplaceableCallBack = @replacementTestFunction;

%% Post Replacement Callback
% �T�u�֐� postReplacementFunction �̓u���b�N���u�����ꂽ��Ɏ��s�����
% �������L�q���܂��B
% ���̊֐��̎g�p�͕K�{�ł͂���܂���̂ŁA�֐�����`����Ă��Ȃ��Ă���肠��܂���B

rule.postReplacementCallBack = @postReplacementFunction;

%%
function out = replacementTestFunction(blockH)
% Simulink Design Verifier�ɂ���Ēu�����s���������L�q���܂��B
% ���Ƃ��΁A�u���b�N�̃p�����[�^������l�����Ƃ��ɂ̂ݒu�������s����ꍇ�Ȃ�
% �ɗ��p����܂��B

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
%                     blockH = �u�����ꂽ�u���b�N�̃n���h���ԍ�
%
% preReplacementCompiledInfo = �u���b�N�u�������O�̃��f���ɑ΂���R���p�C�������
%                              ���̍\���͎̂��̂悤�ɂȂ�܂��B
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
% ���̃R�[���o�b�N�֐��̎g�p��Ɋւ��Ă͈ȉ���M-�t�@�C�����������������B
% matlabroot/toolbox/sldv/sldv/private/blkrep_rule_selectorIndexVecPort_normal.m