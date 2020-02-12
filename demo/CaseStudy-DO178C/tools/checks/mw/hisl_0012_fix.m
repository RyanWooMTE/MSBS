function result = hisl_0012_fix(taskobj)

modelAdvisorObject = taskobj.MAObj;
checkID = 'mathworks.example.hisl_0012';

% Set the Sample Time of the deviant blocks to Inherited(-1).
deviantBlocks = modelAdvisorObject.getCheckResultData(checkID);
for i=1:length(deviantBlocks)
    set_param(deviantBlocks{i},'SampleTime','-1');
end

result = ModelAdvisor.Text('Sample time of blocks used in conditionally executed subsystems set to -1.');
modelAdvisorObject.setActionEnable(false);