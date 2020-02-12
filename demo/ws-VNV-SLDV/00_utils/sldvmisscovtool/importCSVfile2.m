function [simdata,testcasename] = importCSVfile2(Mode,dirname,csvfiles)
% sldvmisscovtool用 入力関数 (CSV形式時間各組)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
%%  description
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'CSV-ファイル(時間各組)から';
            testcasename = ['[インポート]' 10 ...
                'インポートボタンクリックにより、CSV-ファイル(時間各組)からテストケースをインポートします。'];
        else
            simdata = 'From CSV-file with individual time steps';
            testcasename = ['[Import]' 10 ...
                'Import test cases from CSV-file whose signals' ...
                'have individual time step signals'];
        end
%% import
    case 'import'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            sel_str = 'インポートしたいCVSファイルを選択して下さい(複数選択可)。';
            cancelstr = 'キャンセルしました';
        else
            sel_str = 'Pick CVS file(s) to import';
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
        
        significant = 10^12;
        simdata=struct();
        for n=1:length(csvfiles)
            data = importdata(fullfile(dirname,csvfiles{n}));
            if isfield(data,'colheaders')
                siglabels = data.colheaders(2:2:end);
            else
                siglabels = data.textdata(end,2:2:end);
            end

            simdata(n).time =[];
            % At first, obtain minimum step size and end-time
            for m=1:length(siglabels)
                simdata(n).signals(m).values = []; % values will be assigned later.
                simdata(n).signals(m).label=siglabels{m};
                simdata(n).signals(m).dimensions=1; % Signal builder only have a single dimention
            end
            % resolving timestep and maxtime
            timemat = data.data(:,1:2:end);
            timemat(isnan(timemat))=[]; % remove NaN;
            maxtime = max(timemat);

            % resolve fixed timestep value
            dtime = diff(timemat); % time difference
            dtime(dtime==0)=[]; % we accept plural time values at a time          

            [num,den]=rat(dtime,1/significant); % convert to rational number
            % obtaining the greatest common divisor of denominator
            lmcden = den(1);
            for m=2:numel(den)
                lmcden = lcm(lmcden,den(m));
            end
            % reducing to a common denominator
            numg=num.*(lmcden./den);
            % obtaining the least common multiple of numerator
            gcdnum = numg(1);
            for m=2:numel(numg)
                gcdnum = gcd(gcdnum,numg(m));
            end
            timestep = gcdnum/lmcden;

            % fource timestep precision
            timestep = round(timestep*significant)/significant;

            ttime = 0:timestep:maxtime;
            simdata(n).time = ttime';

            for m=1:length(siglabels)

                dsig = [];
                sbt = data.data(:,2*m-1);
                sbt(isnan(sbt))=[]; %remove NaN
                D=data.data(:,2*m);
                D(isnan(D))=[]; % remove NaN
                for l=1:length(ttime)
                    % obtain equivalent time value exist
                    ind = abs(ttime(l)-sbt) < eps*10;
                    switch sum(ind);
                        case 1
                            % Single value is found in ttime
                            dsig(l,1) = D(ind); %#ok
                        case 2
                            % Latter value is taken if two values on a time
                            tmp = D(ind);
                            dsig(l,1) = tmp(end); %#ok
                        case 0
                            if l~=1
                                % Previous value is kept if no value is found
                                dsig(l,1) = dsig(l-1,1); %#ok
                            else
                                % Use first value if t=0 is not found
                                dsig(l,1) = D(1); %#ok
                            end
                    end
                end
                simdata(n).signals(m).values = dsig;
            end
        end
        testcasename=csvfiles;

        %% otherwise
    otherwise
        simdata = '';
end


