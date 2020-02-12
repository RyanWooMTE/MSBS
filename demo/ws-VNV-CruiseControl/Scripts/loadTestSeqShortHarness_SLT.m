%% ========================================================================
%       Requirements Based Functional Testing
%  ========================================================================
%% close Short or ShortFinal and open ShortAssert system harness 
try
sltest.harness.close('CruiseControl','CruiseControl_Harness_ShortAssert');
end
try
sltest.harness.open('CruiseControl','CruiseControl_Harness_ShortTestSeq');
catch
bdclose all
clear all
open_system('CruiseControl');    
sltest.harness.open('CruiseControl','CruiseControl_Harness_ShortTestSeq');
end
