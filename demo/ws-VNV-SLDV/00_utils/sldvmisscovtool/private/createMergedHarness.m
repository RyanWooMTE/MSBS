function createMergedHarness(sldvHarness,existTestCase)

[fname,dirname]=uiputfile('*.mdl');
HarnessModel = fullfile(dirname,fname);
copyfile(sldvHarness,HarnessModel)
open_system(HarnessModel)

sigblock = find_system(bdroot,'MaskType','Sigbuilder block');
sigblock=sigblock{1};

% obtain signal labels
 [timev,datav,siglabels]=signalbuilder(sigblock);
% 
% data=cell(0);
StopTime = str2double(get_param(bdroot,'StopTime'));
FixedStep = simget(bdroot,'FixedStep');

for n=1:length(existTestCase)
    deltaT  = min(diff(existTestCase(n).time));
    endT = existTestCase(n).time(end) + deltaT;
    if StopTime <  endT
        StopTime = endT;
    end
    if FixedStep > deltaT
        FixedStep = deltaT;
    end
end

[tvec,dvec,siglabelss,grplabels]=createSignalBuilderData(existTestCase);

signalbuilder(sigblock,'append',tvec,dvec,siglabels,grplabels);

% Set simulation stop time for a mearged model.
set_param(bdroot,'StopTime',num2str(StopTime));
set_param(bdroot,'FixedStep',num2str(FixedStep));
