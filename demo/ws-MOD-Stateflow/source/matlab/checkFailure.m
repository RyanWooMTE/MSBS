% This function returns a flag specifying whether or not hardware is broken.
% It checks for persistent inactivity on the sensor when the hardware is 
% supposed to be on.
function failure_flag = checkFailure(setting,sensor,time) %#eml

persistent tChange oldSetting

% Define initial value of tChange
if isempty(tChange)
    tChange=0;
end

% Define initial value of oldSetting
if isempty(oldSetting)
    oldSetting=setting;
end

if setting == oldSetting %setting hasn't changed
    if setting == 0 %supposed to be stopped
        failure_flag=0;
    elseif setting ~=0 && sensor == 0 && time-tChange>3 %supposed to be active but isn't
        failure_flag=1;
    else
        failure_flag=0;
    end

else %the setting has changed
    tChange=time;
    failure_flag=0; %the mode has changed
end

oldSetting=setting;