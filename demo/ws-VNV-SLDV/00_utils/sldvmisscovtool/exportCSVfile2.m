function [stat,msg] = exportCSVfile2(Mode,selected,dirname,basename)
% Export function of sldvmisscovtool (CSV-file)
%
% This function creates MAT-file from simdata stored in base workspace.
 
%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
switch Mode
    case 'description'
                if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))                    
                    stat = 'CSV-�t�@�C��(���Ԋe�g)��';
                    msg = ['[�G�N�X�|�[�g]' 10 ...
                        'CSV-�t�@�C��(���Ԋe�g)��'];
                else
                    stat = 'To CSV-file with individual time steps';
                    msg = ['[Export]' 10 ...
                        'Export to CSV-file with individual time steps.'];
                end
    case 'export'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            sel_str = 'CVS�t�@�C���������o���f�B���N�g����I�����ĉ�����';
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

        if dirname==0
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


        for n=selected % �I�����ꂽ�e�X�g�P�[�X�̃C���f�b�N�X�̃��[�v
            flname = fullfile(dirname,[basename{1} sprintf('%03d',n) '.csv']);
             numSig = length(simdata(n).signals);
             fid = fopen(flname,'w');
             fprintf(fid,'TestCase%03d%s\n',n,char(','*ones(1,numSig*2)));
             D = [];
             sigstr = '';
             for m=1:numSig
                 sigstr = [sigstr 'time,' simdata(n).signals(m).label ','];
                 D = [D simdata(n).time double(simdata(n).signals(m).values)];
             end
             %remove last comma
             fprintf(fid,'%s\n',sigstr(1:end-1));
             fclose(fid);
             dlmwrite(flname,D,'precision',12,'-append')
        end

%         %�w�b�_�A�M�����̏����o��
%             fid=fopen(flname,'w');
%             fprintf(fid,'TestCase%3d\n',n);
%             str = '';
%             for m=1:length(simdata(n).signals)
%                 str=sprintf('%sTime,%s,',str,simdata(n).signals(m).label);
%             end
%             fprintf(fid,'%s\n',str(1:end-1));            
%             fclose(fid);
% 
%             % �l�̏����o��
%             D=[];
%             for m=1:length(simdata(n).signals)
%                 D(:,2*m-1:2*m) = [simdata(n).time simdata(n).signals(m).values];
%             end
%             dlmwrite(flname,D,'delimiter',',','-append');
%         end
        
end

