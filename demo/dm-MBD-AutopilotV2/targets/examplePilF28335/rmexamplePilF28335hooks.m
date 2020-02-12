function rmexamplePilF28335hooks
%RMEXAMPLEPILF28335HOOKS Removes the hook registered for the demo in sl_customization

%   Copyright 2011 The MathWorks, Inc.

% Get default (factory) customizations
cm = DAStudio.CustomizationManager;
hObj = cm.RTWBuildCustomizer;

% UnRegister build process hooks
hObj.removeUserHook('before_make');