%% ========================================================================
%       Requirements Based Functional Testing with Coverage
%  ========================================================================
%% close
bdclose all
clear all
%%  Copy Cruise Control version for test

if exist('CruiseControl_VS_harness.slx','file')
    delete(which('CruiseControl_VS_harness.slx'));
end
if exist('CruiseControl_VS.slx','file')
    delete(which('CruiseControl_VS.slx'));
end

p = slproject.getCurrentProject;
copyfile(fullfile(p.RootFolder,'Models','TestGenHarnesses','Coverage', ...
    'CruiseControl_IDE_harness.slx'), ...
    fullfile(p.RootFolder,'Models','TestGenHarnesses','Coverage', ...
    'CruiseControl_VS_harness.slx'));
copyfile(fullfile(p.RootFolder,'Models','TestGenHarnesses','Coverage', ...
    'CruiseControl_IDE.slx'), ...
    fullfile(p.RootFolder,'Models','TestGenHarnesses','Coverage', ...
    'CruiseControl_VS.slx'));
clear p;
% open the model
open_system('CruiseControl_VS_harness.slx');
set_param('CruiseControl_VS_harness/Test Unit','ModelName', ...
    'CruiseControl_VS');

