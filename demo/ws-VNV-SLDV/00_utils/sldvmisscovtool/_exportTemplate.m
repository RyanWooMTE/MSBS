function [stat,msg] = _exportTemplate(Mode,selected)
% sldvmisscovtool�p �G�N�X�|�[�g�֐� (�e���v���[�g)
% export function template for sldvmisscovtool
%
% ���̃t�@�C���� export ����n�܂�t�@�C�����Ƃ��ĕۑ������
% sldvmisscovtool GUI��́u�G�N�X�|�[�g�v���ɓǂݍ��܂�܂��B
% (sldvmisscovtool�̍ċN�����K�v�ƂȂ�܂�)
%
% By saving as a function M-file begining with "export", this function will
% be listed as [Export] function in sldvmisscovtool GUI.
% Re-run of sldvmisscovtool is needed.

%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
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
%% export
    case 'export'
        % �x�[�X���[�N�X�y�[�X���� simdata ��ǂݍ���
        % load simdata variable in base WorkSpace
        simdata_tmp = evalin('base','simdata');

        % GUI��̃e�X�g�P�[�X���X�g�{�b�N�X�őI�����ꂽ���݂̂̂𒊏o
        % pick only selected data in TestCase listbox in the GUI
        simdata = simdata_tmp(selected);

        % ����ȉ��ɁA���ԕt���\���̃t�H�[�}�b�g�� simdata ��C�ӂ̃t�H�[�}�b�g
        % �ɕϊ�����X�N���v�g���L�q���Ă��������B
        % put script here to convert your own data format from simdata which is 
        % defined as structure with time format.
end
