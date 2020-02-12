function [simdata,testcasename] = importMATfile(Mode,filename)
% sldvmisscovtool�p ���͊֐� (MAT-�t�@�C������̃C���|�[�g)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'MAT-�t�@�C������';
            testcasename = ['[�C���|�[�g]' 10 ...
                '�C���|�[�g�{�^���N���b�N�ɂ��A�I������MAT-�t�@�C������e�X�g�P�[�X��ǂݍ��݂܂��BMAT-�t�@�C���ɂ� simdata �ϐ����ۑ�����Ă���K�v������܂��B'];
        else
            simdata = 'From MAT-file';
            testcasename = ['[Import]' 10 ...
                'Import from MAT-file in which simdata variable (time with structure format) is stored.'];
        end
    case 'import'
        testcasename=[];
        if ~exist('filename','var')
            % Read data by MAT-file which contains a simulink structure with time (time, signals)
            [flname,dirname]=uigetfile('*.mat');
            if flname==0
                simdata = [];
                testcasename = 'Canceled';
                return;
            end
            filename = fullfile(dirname,flname);
        end

        load(filename);
        if ~exist('simdata','var')
            simdata =[];
            if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
                testcasename ='�ϐ�simdata��MAT-file�Ɋ܂܂�Ă��܂���B';
            else
                testcasename ='A variable "simdata" is not contained in the specified MAT-file.';
            end
            return;
        end
        testcasename = cell(size(simdata));
        for n=1:length(simdata)
            testcasename{n} = 'TestCase%03d';
        end
    otherwise
        simdata = '';
end

