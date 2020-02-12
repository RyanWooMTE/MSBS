function sl_customization(cm)
% SL_CUSTOMIZATION for examplePilF28335
%  - Specifies the valid configuration parameter settings to enable the
%    examplePilF28335 implementation.
%  - Specifies hook point to call a function which generates
%    target_paths.mk

% Copyright 2011 The MathWorks, Inc.

cm.registerTargetInfo(@loc_createConfig);

% Get default (factory) customizations
hObj = cm.RTWBuildCustomizer;

% Register Real-Time Workshop build process hooks
hObj.addUserHook('before_make','f28335BeforeMakeHook(modelName);');

% Specify settings for valid PIL configuration
function config = loc_createConfig

config = rtw.connectivity.ConfigRegistry;
config.ConfigName  = 'F28335 PIL Example';
config.ConfigClass = 'f28335pil.ConnectivityConfig';

% The following model configuration settings must be matched to be valid
config.SystemTargetFile   = {'ert.tlc'};
config.TemplateMakefile   = {'ec_target.tmf'};
config.TargetHWDeviceType = {'Texas Instruments->C2000'};
