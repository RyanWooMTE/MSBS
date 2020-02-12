function makeharness_compareresults(mdl,data,opts)
% makeharness_compareresults: Generate a harness model to compare with
% expected outputs.

%   Copyright 2010-2011 The MathWorks, Inc. 

load_system('simulink')

if ~exist('data','var')
    data = [];
end
if verLessThan('matlab','7.11')
    % sldvharnessopts is supported with R2010b or later.
    if ~exist('opts','var')
        opts.modelRefHarness = false;
    end
    % this is old format
    [~,harnessModel] = sldvmakeharness(mdl,data,[],opts.modelRefHarness);
else
    if ~exist('opts','var')
        % use default setting
        opts = sldvharnessopts();
    end
    [~,harnessModel] = sldvmakeharness(mdl,data,opts);
end
open_system(harnessModel);
modelName = get_param(bdroot,'Name');
TestUnitN = find_system(modelName,'RegExp','on','Name','Test Unit.*');
TestUnitN=TestUnitN{1};
TestUnitH=get_param(TestUnitN,'Handle');

sigBuilN = find_system(modelName,'MaskType','Sigbuilder block');
sigBuilN = sigBuilN{1};

SizeTypeN = find_system(modelName,'Name','Size-Type');
SizeTypeN = SizeTypeN{1};

%% Setting for outport
OutPortBlkN= find_system(modelName,'SearchDepth',1,'BlockType','Outport');
OutPortBlkH=cell2mat(get_param(OutPortBlkN,'Handle'));

for n=1:length(OutPortBlkN)
    ExpectedOutput{n} = sprintf('Exp_%s',get(OutPortBlkH(n),'Name')); %#ok
end


%% Adds expected outputs into SignalBuilder

% memorize number of inputs of the SB
phSigBuil = get_param(sigBuilN,'PortHandles');
Ninput = length(phSigBuil.Outport);

addExpectedOutputToSignalBuilder(sigBuilN,ExpectedOutput);

% [inP,outP]=getPortNumRelation(TestUnitN,sfnblockN);

% Delete lines of outport signals of Test Harness Unit
for n=1:length(OutPortBlkN)
    delete_line(modelName,sprintf('%s/%d',get(TestUnitH,'Name'),n),[get(OutPortBlkH(n),'Name') '/1'])
end

% Outport handles of the TestUnit
phSimtmp = get(TestUnitH,'PortHandles');
phSim = phSimtmp.Outport;
% Outport handles of the expected outputs in SignalBuilder block
phExptmp = get_param(sigBuilN,'PortHandles');
phExp = phExptmp.Outport(Ninput+1:end);

for n=1:length(OutPortBlkN)
    % force to set PortName to store names of the Outport blocks.
    % The name will be used in createComparingResults to set Assertion signal name.
    set(phSim(n),'Name',get_param(OutPortBlkN{n},'Name'));
    delete_block(OutPortBlkN{n});
end

% set SignalBuilder's port name as ExpectedOutput Name
for n=1:length(phExp)
    set(phExp(n),'Name',ExpectedOutput{n})
end

[time,data,signame]=signalbuilder(sigBuilN); %#ok
% copy name of SignalBuilder to output line names of SizeType
phSizeType = get_param(SizeTypeN,'PortHandles');
for n=1:length(phSizeType.Outport)
    set(phSizeType.Outport(n),'Name',signame{n})    
end


createComparingResults(modelName,phSim,phExp)


%    replaceLineToFromGoto(lineH,ExpectedOutput{n});
