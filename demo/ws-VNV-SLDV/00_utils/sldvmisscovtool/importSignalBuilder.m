function [simdata,testcasename] = importSignalBuilder(Mode,blk)
% Import function of sldvmisscovtool (Signal Buider)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'SignalBuiderブロックから';
            testcasename = ['[インポート]' 10 ...
                'インポートボタンクリックにより、選択されたSignal Builderブロックからテストケースをインポートします。'];
        else
            simdata = 'From Signal Builder block';
            testcasename = ['[Import]' 10 ...
                'Select a Signal Builder block to import, then click import button'];
        end
    case 'import'
        try
            if ~exist('blk','var')
                blk = gcb;
            end
            [tvec,dvec,siglabels,grplabels]=signalbuilder(blk);
        catch

            ME = lasterror();
            testcasename = ME.message;
            simdata = [];
            return;
        end
        simdata.time=[];
        
        % effective digits
        significant=1e12;
        
        for n=1:length(grplabels) % create simdata one-by-one
            timesteps = []; %sample timesep
            maxtimes = [];

            % At first, obtain minimum step size and end-time
            for m=1:length(siglabels)
                simdata(n).signals(m).values=[]; % will be assigned again later.
                simdata(n).signals(m).label=siglabels{m};
                simdata(n).signals(m).dimensions=1; % Signal builder only have a single dimention
            end
            % resolving timestep and maxtime
            timemat = [];
            for m=1:size(tvec,1)                
                timemat = [timemat tvec{m,n}(1:end)];
            end
            timemat = sort(timemat);
            timemat(isnan(timemat))=[]; % remove NaN;
            maxtime = max(timemat);

            % resolve fixed timestep value
            dtime = diff(timemat); % time difference
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

            ttime = 0:timestep:maxtime;
            ttime = round(ttime*significant)/significant;

            simdata(n).time = ttime';

            % set to have continueous time-step from
            % descrete variable with inhomogeneous step size
            for m=1:length(siglabels)
                
                dsig = [];
                sbt = tvec{m,n};
                for l=1:length(ttime)
                    % make serial time data from data given by SignalBuilder 
                    ind = abs(ttime(l)-sbt) < eps*10;
                    switch sum(ind);
                        case 1
                            % Single value is found in ttime
                            dsig(l,1) = dvec{m,n}(ind); %#ok
                        case 2
                            % Latter value is taken if two values on a time
                            tmp = dvec{m,n}(ind);
                            dsig(l,1) = tmp(end); %#ok
                        case 0
                            if l~=1
                                % Previous value is kept if no value is found
                                dsig(l,1) = dsig(l-1,1); %#ok
                            else
                                % Use first value if t=0 is not found
                                dsig(l,1) = dvec{m,n}(1); %#ok
                            end
                    end
                end
                simdata(n).signals(m).values = dsig;
            end
        end
        testcasename = grplabels;
end

