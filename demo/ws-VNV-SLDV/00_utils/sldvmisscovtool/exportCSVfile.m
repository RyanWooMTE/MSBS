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
            stat = 'CSV-ファイル(時間共通)へ';
            msg = ['[エクスポート]' 10 ...
                'データをCSV-ファイルへ書き出します。時間データは各信号に共通となります。'];
        else
            stat = 'To CSV-file';
            msg = ['[Export]' 10 ...
                'Export simdata in base workspace to CSV-files where time data is common to all signals.'];
        end
%% export
    case 'export'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            sel_str = 'CVSファイルを書き出すフォルダを選択して下さい';
            qstr={'CSVファイルに付ける共通名を指定して下さい'};
            titlestr='ファイル名の指定';
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


        for n=selected % テストケースの数
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
