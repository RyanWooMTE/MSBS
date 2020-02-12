function result = hisl_0015_fix(taskobj)

modelAdvisorObject = taskobj.MAObj;
checkID = 'mathworks.example.hisl_0015';

% Unset the option: "Allow Unequal Input Port Widths" for the deviant
% blocks
deviantBlocks = modelAdvisorObject.getCheckResultData(checkID);
for i = 1:length(deviantBlocks)
    set_param(deviantBlocks{i},'AllowUnequalInputPortWidths','off');
end

result = ModelAdvisor.Text('Allow Unequal Width Ports setting has been disabled for all merge blocks.');
modelAdvisorObject.setActionEnable(false);