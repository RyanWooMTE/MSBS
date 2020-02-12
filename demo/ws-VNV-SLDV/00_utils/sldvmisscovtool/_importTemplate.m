function [simdata,testcasename] = _importTemplate(Mode)
% sldvmisscovtool�p �C���|�[�g�֐� (�e���v���[�g)
% Import function template for sldvmisscovtool
%
% ���̃t�@�C���� import ����n�܂�t�@�C�����Ƃ��ĕۑ������
% sldvmisscovtool GUI��́u�C���|�[�g�v���ɓǂݍ��܂�܂��B
% (sldvmisscovtool�̍ċN�����K�v�ƂȂ�܂�)
%
% By saving as a function M-file begining with "import", this function will
% be listed as [Import] function in sldvmisscovtool GUI.
% Re-run of sldvmisscovtool is needed.

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
%% description
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            % ���{�ꃂ�[�h�̏ꍇ�ɕ\������
            simdata = '�v���_�E�����X�g�ɕ\�����镶����';
            testcasename = '[Import] Descriptions of this feature. This shown in the information window.';
        else
            % Shown in non-Japanese mode
            simdata = 'Strings shown pull-down list blox in GUI';
            testcasename = ['[Import] Descriptions of this feature. This shown in the information window.'];
        end
%% import
    case 'import'
        
        % �C���|�[�g���������s���A�M���f�[�^�Ƃ��ĕϐ��� simdata �����ԕt���\���̂̌`���ō쐬����
        % Imported data needs to be expressed as structure with time format
        % with variable name simdata.
        simdata(1).time = 0:0.1:1;
        simdata(1).signals(1).values=[1 2];
        simdata(1).signals(1).label='signal1';
        simdata(1).signals(1).dimensions=1;
        % �e�X�g�P�[�X���X�g�{�b�N�X�ɕ\�������e�X�g�P�[�X�����w�肵�܂��B
        % Specify name of the test case which will be shown in TestCase
        % list box in GUI
        testcasename{1} = 'TestCase01';
end


