function [stat,msg] = exportCSVfile(Mode,selected,dirname,basename)
% Export function of sldvmisscovtool (MAT-file)
%
% This function creates MAT-file from simdata stored in base workspace.

%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
switch Mode
%% description
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            stat = 'CSV-�t�@�C��(���ԋ���)��';
            msg = ['[�G�N�X�|�[�g]' 10 ...
                '�f�[�^��CSV-�t�@�C���֏����o���܂��B���ԃf�[�^�͊e�M���ɋ��ʂƂȂ�܂��B'];
        else
            stat = 'To CSV-file';
            msg = ['[Export]' 10 ...
                'Export simdata in base workspace to CSV-files where time data is common to all signals.'];
        end
%% export
    case 'export'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            sel_str = 'CVS�t�@�C���������o���t�H���_��I�����ĉ�����';
            qstr={'CSV�t�@�C���ɕt���鋤�ʖ����w�肵�ĉ�����'};
            titlestr='�t�@�C�����̎w��';
        else
            sel_str = 'Pick a directory to export CVS files';
            qstr={'Specify common name of CSV-files.'};
            titlestr='CSV-file name';
        end
        
        % call uigetdir if dirname is not defined
        %  note: dirname is given in case of debugging
        if ~exist('dirname','var')
            dirname = uigetdir(pwd,sel_str);
        end
        
        if dirname==0 % Cancel button 
            stat = false;
            msg = '';
            return;
        end
        simdata = evalin('base','simdata');

        % call uigetdir if basename is not defined
        %  note: basename is given in case of debugging
        if ~exist('basename','var')
            defaultanswer={'TestCase'};
            basename=inputdlg(qstr,titlestr,1,defaultanswer);
        end


        for n=selected % �e�X�g�P�[�X�̐�
            flname = fullfile(dirname,[basename{1} sprintf('%03d',n) '.csv']);
             numSig = length(simdata(n).signals);
             fid = fopen(flname,'w');
             fprintf(fid,'TestCase%03d%s\n',n,char(','*ones(1,numSig)));
             sigstr = 'time,';
             D = simdata(n).time;
             for m=1:numSig
                 sigstr = [sigstr simdata(n).signals(m).label ','];
                 %D = [D simdata(n).signals(m).values];
                 D = [D double(simdata(n).signals(m).values)];
             end
             %remove last comma
             fprintf(fid,'%s\n',sigstr(1:end-1));
             fclose(fid);
             dlmwrite(flname,D,'precision',12,'-append')
        end        
end
