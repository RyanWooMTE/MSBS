
bdclose all

[~,thisFolderName] = fileparts(pwd);
% if we are in Composition
if strncmp('C_',thisFolderName,2)
    DirList = dir('F_*');
    if isempty(DirList)
       error('There are no functions to test') 
    end
    ModelList = [];
    for idx =1:length(DirList)
        ModelList = [ModelList; dir(fullfile(DirList(idx).name,'*.mdl'))];
        ModelList = [ModelList; dir(fullfile(DirList(idx).name,'*.slx'))];
    end    
        
else
    % in a F_ directory, this should contain models and a Tests directory 
    ModelList = getModelList(); %dir('*.mdl');
    if isempty(ModelList)
        error('There are no models to test');
    end
    if ~isdir('./Tests')
        error('There must be a ./Tests directory containing test harnesses');
    end
end


for idx = 1:length(ModelList)
    [mdlPath,mdl] = fileparts(which(ModelList(idx).name)); 
    if and(~exist(fullfile(mdlPath,'Tests',[mdl,'_testHarness.mdl']),'file'), ...
           ~exist(fullfile(mdlPath,'Tests',[mdl,'_testHarness.slx']),'file'))
        warning('There is no test harness for model %s, Skipping this model',mdl);
        continue
    end
    
    open_system( fullfile(mdlPath,'Tests',[mdl, '_testHarness']) );
    
end

testsPath = fullfile(getWorkProducts(),'ModelTest');
rName = [thisFolderName(3:end) '_ReqTestReport'];
rFull = report('ReqTestReport',['-o',fullfile(testsPath,rName)],'-quiet','-noview');
[rPath,rName,rExt] = fileparts(rFull);

fprintf(1,'View Requirements Test Report <a href = "matlab: web(''%s'')">%s%s</a>\n',rFull,rName,rExt);

for idx = 1:length(ModelList)
    [~,mdl] = fileparts(ModelList(idx).name); 
    try 
        close_system( [mdl '_testHarness'] , 0);
    catch
    end
end