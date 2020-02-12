function sigbuil = xls2SignalBuilder(xlsfile,sheet,SignalRange,blk,Mode,opts)
% xls2SignalBuilder  Create SignalBuilder block from Excel selection

%   Copyright 2010-2011 The MathWorks, Inc. 

[data,text]= xlsread(xlsfile,sheet,SignalRange);

% Testcase name is shown at top-left cell. This will be used by GroupLabel
% of SignalBuilder block
TestCaseName = text(1,1);

% Define rows of label and data types
NlabelRow = 2;
NdtRow = 3;

% Define as time with structure data format
simdata.time = data(:,1);
for n=1:size(data,2)-1
    simdata.signals(n).label = text{NlabelRow,n+1};
    if strcmp(text{NdtRow,n+1},'boolean')
        dType = 'logical';
    else
        dType = text{NdtRow,n+1};
    end
    simdata.signals(n).values = cast(data(:,n+1),dType);
    simdata.signals(n).dimensions = 1;
end

assignin('base','simdata',simdata)

% convert simdata to SignalBuilder block
[stat,sigbuil] = simdata2SignalBuilder(simdata,TestCaseName,blk,Mode);
[tt,dd,sig,nGrp]=signalbuilder(sigbuil);
if exist('opts','var') && isfield(opts,'isReqLink') && opts.isReqLink
    setSignalBuilderReqLink(sigbuil,length(nGrp),xlsfile,sheet,SignalRange,TestCaseName{1});
end