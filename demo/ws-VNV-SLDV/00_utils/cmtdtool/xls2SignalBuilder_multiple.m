function sigbuil = xls2SignalBuilder_multiple(xlsfile,sheet,UsedRange,blk,Mode,opts)
% xls2SignalBuilder  Create SignalBuilder block from Excel selection

%   Copyright 2010-2011 The MathWorks, Inc. 

[tmp1,tmp2,raw]= xlsread(xlsfile,sheet);

% Regular expression keywd defines the beggining of signal
keywd = '^<TV>';

sigrawdata = getSignalFromRaw(raw,keywd);

%simdata = zeros(1,length(sigrawdata));
for p=1:length(sigrawdata)
    TestCaseName{p} = sigrawdata(p).name;
    % Define as time with structure data format
    simdata(p).time = sigrawdata(p).numericdata(:,1);
    for n=1:length(sigrawdata(p).labels)
        simdata(p).signals(n).label = sigrawdata(p).labels{n};
        if strcmp(sigrawdata(p).datatypes{n},'boolean')
            dType = 'logical';
        else
            dType = sigrawdata(p).datatypes{n};
        end
        simdata(p).signals(n).values = cast(sigrawdata(p).numericdata(:,n+1),dType);
        simdata(p).signals(n).dimensions = 1;
    end
end
% convert simdata to SignalBuilder block
[stat,sigbuil]=simdata2SignalBuilder(simdata,TestCaseName,blk,Mode);

if ~isempty(UsedRange)
    for p=1:length(sigrawdata)
        StartCell = UsedRange(1:strfind(UsedRange,':')-1);
        Col = regexp(StartCell,'[A-Z]','match','once');
        Row = str2double(regexp(StartCell,'[0-9]','match','once'));
        Range = sprintf('%s%d:%s%d',...
            Col,Row+sigrawdata(p).row-1,...
            char(Col+length(sigrawdata(p).labels)),...
            Row+sigrawdata(p).row+size(sigrawdata(p).numericdata,1)+1);
        if exist('opts','var') && isfield(opts,'isReqLink') && opts.isReqLink
            setSignalBuilderReqLink(sigbuil,p,xlsfile,sheet,Range,TestCaseName{p});
        end
    end
end

function sigrawdata = getSignalFromRaw(raw,keywd)
% getSignalFromRaw extract signal names, data types, and numeric data from
% raw data obtained by Excel read.

%% find positions of beggining of each signals
sign = 1;
sigrawdata = [];
for n=1:size(raw,1)
    if ischar(raw{n,1}) && ~isempty(regexp(raw{n,1},keywd,'once'))
        sigrawdata(sign).name = regexprep(raw{n,1},keywd,''); %#ok
        sigrawdata(sign).row =n; %#ok
        sign=sign+1;
    end
end
if isempty(sigrawdata)
    error('No Keyword %s found in Excel.',keywd)
end
%% store raw data for corresponding signals
for n=1:length(sigrawdata)
    if n==length(sigrawdata)
        sigrawdata(n).data = raw(sigrawdata(n).row+1:end,:); %#ok
    else
        sigrawdata(n).data = raw(sigrawdata(n).row+1:sigrawdata(n+1).row-1,:);%#ok
    end
end

%% parse each raw data and assign signal names, data types, and numeric data
for n=1:length(sigrawdata)
    sigrawdata(n).labels = sigrawdata(n).data(1,2:end);%#ok
    sigrawdata(n).datatypes = sigrawdata(n).data(2,2:end);%#ok
    ndata = [];
    for m=1:size(sigrawdata(n).data,1)
        try
            tmp = cell2mat(sigrawdata(n).data(2+m,:));
            if ~any(isnan(tmp))
                ndata(m,:) = tmp;%#ok
            end
        catch %#ok
            continue;
        end
    end
    sigrawdata(n).numericdata = ndata;%#ok
end
