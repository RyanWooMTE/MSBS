%% ========================================================================
%       Ad-hoc Testing with Dashboard
%  ========================================================================
%% close
bdclose all
clear all
%
%  0)  Change to "Work" directory
%  1)  Introduce Cruise Control module operation
%  2)  Use harness with constant inputs and boolean
%      Show tspeed value while running panel
%
CruiseControl_dd_RP;
load_system('CruiseControl_RP_harness');
open_system('CruiseControl_RP_harness/Dashboard');
open_system('CruiseControl_RP_harness','window');
load_system('CruiseControl_RP');
open_system('CruiseControl_RP/Compute target speed','window');