function [stat,msg] = exportMATfile(varargin)
% Export function of sldvmisscovtool (MAT-file)
%
% This function creates MAT-file from simdata stored in base workspace.
 
%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
switch varargin{1}
    case 'description'
                if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))                    
                    stat = 'MAT-ファイルへ';
                    msg = ['[エクスポート]' 10 ...
                        '選択されているデータを変数simdataとしてMAT-ファイルに保存します。'];
                else
                    stat = 'To MAT-file';
                    msg = ['[Export]' 10 ...
                        'Save simdata as MAT-file.'];
                end
    case 'export'
        selected = varargin{2};
        simdata = evalin('base','simdata');
        simdata = simdata(selected);

        [flname,dirname]=uiputfile('simdata.mat');
        if flname==0
            stat = false;
            msg = '';
            return;
        end
        
        try
            save(fullfile(dirname,flname),'simdata');
        catch
            stat = false;
            msg = lasterror();
            return;
        end
        stat = true;
        fprintf('simdata has been saved as %s\n',fullfile(dirname,flname));
end

