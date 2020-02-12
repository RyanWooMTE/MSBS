function [stat,sigbul] = simdata2SignalBuilder(simdata,GroupLabel,sigbul,Mode)
% SIMDATA2SIGNALBUILDER convert Structure with time data to Signal Builder
% Inputs:
%  simdata: a struct array with structure with time format
%  GroupLabel: Group label for SignalBuilder block. "Test Case xx" will be
%     used if this value is emtpy.
%  blk: Existing SignalBuilder block. New SignalBuilder block will created if this value is empty.
%

%   Copyright 2010-2011 The MathWorks, Inc. 

stat = true;

Nsig = length(simdata(1).signals); % number of signals
Ntc = length(simdata); % number of test cases

tvec = cell(Nsig,Ntc);
dvec = cell(Nsig,Ntc);
siglabels = cell(1,Nsig);
grplabels = cell(1,Ntc);

%% Obtaining signal names
for n=1:Nsig
    str = simdata(1).signals(n).label;
    
    if isempty(str) % defalt signal name
        str = sprintf('Signal%02d',n);
    end
    siglabels{n} = str;
    if ~all(simdata(1).signals(n).dimensions == 1)
        if isJapaneseEnv()
            warndlgstr = '2次元以上のデータのエクスポートはサポートされていません';
        else
            warndlgstr = 'Exporting more than 2 dimensional data is not supported by simdata2SignalBuilder.m';
        end
        stat = false;
        warndlg(warndlgstr)
        return;
    end
end

%% Add additional values if data varies at the end of time
for n=1:Ntc
    if length(simdata(n).time) == 1
        continue;
    end
    tstep = min(diff(simdata(n).time));
    isvaried = false;
    % check if there are signal(s) which last data varies
    for m=1:Nsig 
        if simdata(n).signals(m).values(end)~=simdata(n).signals(m).values(end-1)
            isvaried = true;
        end
    end
    % if it is varied, add additional data at the end
    if isvaried
        simdata(n).time = [simdata(n).time;  simdata(n).time(end)+tstep;];
        for m=1:Nsig
            simdata(n).signals(m).values = [simdata(n).signals(m).values; simdata(n).signals(m).values(end)];
        end
        if isJapaneseEnv()
            warndlgstr = sprintf('入力データが最終値で変化していたため、t=%fまでデータが保持されるよう変更しました',simdata(n).time(end));
        else
            warndlgstr = sprintf('Because input signals were varied at the end time, this tool added a data to keep the value until t=%f',simdata(n).time(end));
        end
        warning(warndlgstr)

    end
end

%% making time and data vectors to be fed to signalbuilder command.
for n=1:Ntc
    for m=1:Nsig
        tvec{m,n} = simdata(n).time';
        dvec{m,n} = double(simdata(n).signals(m).values');
        % sldvData file sometimes include single time testcase
        % In that case, because Signal builder must have more
        % then two time steps, we add data point at 0.2 sec
        if length(simdata(n).time) == 1
            tvec{m,n} = [simdata(n).time 0.2];
            dvec{m,n} = double([simdata(n).signals(m).values simdata(n).signals(m).values]);
        end
    end
    if isempty(GroupLabel)
        grplabels{n} = sprintf('Test Case %02d',n);
    else
        grplabels{n} = GroupLabel{n};
    end
end

% redefine so that value changes are made within a single step
% rigidly in order to prevent interpolation between values.
for n=1:Ntc
    for m=1:Nsig
        tt = tvec{m,n};
        dd = dvec{m,n};
        
        % create double sized vectors
        % t1x1 t2x1 t2x2 t3x2 t3x3 ...
        dnew = reshape([dd;dd],[1 2*numel(dd)]);
        dnew = dnew(1:end-1);
        tnew = reshape([tt;tt],[1 2*numel(tt)]);
        tnew = tnew(2:end);
        
        % obtain both time and value is not different from previous
        % time step (The first step is always effective)
        effectiveElement=[true (diff(dnew)|diff(tnew))];
        
        tvec{m,n} = tnew(effectiveElement);
        dvec{m,n} = dnew(effectiveElement);
        
    end
end


if isempty(sigbul)
    new_system();
    open_system(bdroot);
    sigbul = [bdroot '/TestCases'];
    signalbuilder(sigbul,'CREATE',tvec,dvec,siglabels,grplabels);
elseif exist('Mode','var') && strcmp(Mode,'replace')
    idx = signalbuilder(sigbul,'ACTIVEGROUP');
    signalbuilder(sigbul,'set',1:length(siglabels),idx,tvec,dvec);
    %signalbuilder(sigbul,'APPEND',tvec,dvec,siglabels,grplabels);
    %signalbuilder(sigbul, 'ACTIVEGROUP',idx);
else    
    signalbuilder(sigbul,'APPEND',tvec,dvec,siglabels,grplabels);

end

% resize the size of the SignalBuilder block
pos = get_param(sigbul,'Position');
set_param(sigbul,'Position',[pos(1) pos(2) pos(3) pos(2)+Nsig*50]);
