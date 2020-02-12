function [simdata,testcasename] = importCSVfile(Mode,dirname)
% sldvmisscovtool用 入力関数 (CSV形式時間共通)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
%% description
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'CSV-ファイル(時間共通)から';
            testcasename = ['[インポート]' 10 ...
                'インポートボタンクリックにより、選択したフォルダに含まれるCSV-ファイル(時間共通)からテストケースをインポートします'];
        else
            simdata = 'From CSV-file';
            testcasename = ['[Import]' 10 ...
                'Import test cases from CSV-files where time data is common to all signals.'];
        end
%% import
    case 'import'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            sel_str = 'インポートしたいCVSファイルを選択して下さい(複数選択可)。';
            cancelstr = 'キャンセルしました';
        else
            sel_str = 'Pick CVS file(s)';
            cancelstr = 'Canceled';
        end

        % call uigetdir if dirname is not defined
        %  note: dirname is given in case of debugging
        if ~exist('dirname','var')
            [csvfiles,dirname] = uigetfile('*.csv',sel_str,'MultiSelect', 'on');
        else
            files = dir(fullfile(dirname,'*.csv'));
            for n=1:length(files)
                csvfiles{n} = files(n).name;
            end
        end

        if dirname == 0 % In case of canceling
            simdata = [];
            testcasename = cancelstr;
            return;
        end
        if ischar(csvfiles)
            tmp = csvfiles;
            csvfiles = cell(1);
            csvfiles{1} = tmp;
        end

        % timestep has 10^12 precision
        significant = 10^12;

        testcasename={};
        for n=1:length(csvfiles)
            D=importdata(fullfile(dirname,csvfiles{n}));
            
            % resolve fixed timestep value 
            timeOrg = D.data(:,1);
            dtime = diff(timeOrg); % time difference
            dtime(dtime==0)=[]; % we accept plural time values at a time          

            [num,den]=rat(dtime,1/significant); % convert to rational number
            % obtaining the greatest common divisor of denominator
            lmcden = den(1);
            for m=2:length(den)
                lmcden = lcm(lmcden,den(m));
            end
            % reducing to a common denominator
            numg=num.*(lmcden./den);
            % obtaining the least common multiple of numerator
            gcdnum = numg(1);
            for m=2:length(numg)
                gcdnum = gcd(gcdnum,numg(m));
            end
            timestep = gcdnum/lmcden;
            timestep = round(timestep*significant)/significant;

            maxtime = max(timeOrg);

            ttime = 0:timestep:maxtime;
            simdata(n).time = ttime';
            dsig = [];

            for l=1:length(ttime)
                % make serial time data from CSV time line
                ind = abs(ttime(l)-timeOrg) < eps*10;
                switch sum(ind);
                    case 1
                        % Single value is found in ttime
                        dsig(l,:) = D.data(ind,:); %#ok
                    case 2
                        % Latter value is taken if two values on a time
                        tmp = D.data(ind,:);
                        dsig(l,:) = tmp(end,:); %#ok
                    case 0
                        if l~=1
                            % Previous value is kept if no value is found
                            dsig(l,:) = dsig(l-1,:); %#ok
                        else
                            % Use first value if t=0 is not found
                            dsig(l,:) = D(1,:); %#ok
                        end
                end
            end
            for m=1:size(D.data,2)-1
                simdata(n).signals(m).values = dsig(:,m+1);
                if isfield(D,'colheaders')
                    simdata(n).signals(m).label = D.colheaders{m+1};
                else
                    simdata(n).signals(m).label = '';
                end
                simdata(n).signals(m).dimensions = 1;
            end
            testcasename{end+1}=csvfiles{n};
        end
end


