% make harnesses from log-data in the requirements based testHarness

mdl = 'CompFeatures';

% construct SLDV data object for a test harness 
opts = slvnvharnessopts();
opts.modelRefHarness = 1;
tempharness = slvnvmakeharness(mdl,[],opts);
[~,tempmodel] = fileparts(tempharness);
data = slvnvlogsignals(tempmodel);
bdclose(tempmodel);
delete(tempharness);



% create test harness model
opts = slvnvharnessopts();
opts.harnessFilePath = fullfile(fileparts(which(mdl)),'Tests',[mdl,'_eqHarness_req']);
opts.modelRefHarness = 1;
if exist([opts.harnessFilePath,'.mdl'],'file')
    bdclose([opts.harnessFilePath,'.mdl']);
    delete([opts.harnessFilePath,'.mdl']);
end
if exist([opts.harnessFilePath,'.slx'],'file')
    bdclose([opts.harnessFilePath,'.slx']);
    delete([opts.harnessFilePath,'.slx']);
end


% harnessMdlFullPath = slvnvmakeharness(mdl,'',opts);
% [~,harnessMdl] = fileparts(harnessMdlFullPath);
% 
% % signal builder info
% blk = [harnessMdl,'/Inputs'];
% [~, ~, signames,groupnames] = signalbuilder(blk);

clear logsOut*
reportFolder = fullfile(getWorkProducts(),'ModelTest');
load([fullfile(reportFolder,mdl),'_testdata']);
logs = whos('logsOut*');

% grab log data from test run
data.TestCases = struct('timeValues',[],'dataValues',{},'paramValues',[]); %cell(size(signames));
for logIdx = 1:length(logs)
    logsOut = eval(['logsOut',num2str(logIdx)]);
    for sigIdx=1:length(signames)
        signal = ['INP_',signames{sigIdx}];
        if sigIdx == 1
            data.TestCases(logIdx).timeValues = logsOut.(signal).Time(:)';
        end
        data.TestCases(logIdx).dataValues{sigIdx} = logsOut.(signal).Data(:)';        
    end
    data.TestCases(logIdx).paramValues = [];
end
%     if logIdx == 1
%         signalbuilder(blk,'set',(1:length(signames)),'Test Case 1',time,data);
%     else
%         signalbuilder(blk,'appendgroup',time,data,[],['Test Case ',num2str(logIdx)]);
%     end
save('tempdata','data');
harnessMdlFullPath = slvnvmakeharness(mdl,'tempdata.mat',opts);