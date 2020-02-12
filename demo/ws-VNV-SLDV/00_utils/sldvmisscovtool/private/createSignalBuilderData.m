%% createSignalBuilderData
function [tvec,dvec,siglabels,grplabels]=createSignalBuilderData(simdata)

Nsig = length(simdata(1).signals); % number of signals
Ntc = length(simdata);

tvec = cell(Nsig,Ntc);
dvec = cell(Nsig,Ntc);
siglabels = cell(1,Nsig);
grplabels = cell(1,Ntc);

% obtaining signal names
for n=1:Nsig
    str = simdata(1).signals(n).label;

    if isempty(str) % defalt signal name
        str = sprintf('Signal%02d',n);
    end
    siglabels{n} = str;
end
for n=1:Ntc
    for m=1:Nsig
        tvec{m,n} = simdata(n).time';
        dvec{m,n} = double(simdata(n).signals(m).values');
    end
    if ~isfield(simdata(n),'signalName') || isempty(simdata(n).signalName)
        grplabels{n} = sprintf('exTestCase%02d',n);
    else
        grplabels{n} = simdata(n).signalName; 
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
