%% ========================================================================
%       Reproducing Field Issues - Property Proving
%  ========================================================================
%% close
bdclose all
clear all
%  Open property proving model with
CruiseControl_pp
%  1)  Show architecture:  input assumptions, property models
%  2)  Show temporal library, constraints/assumptions/proofs/objectives
%
%  Option #1  -- Field Issue
%             -- Increase tspeed with CoastSetSw (reduce speed button)
% -------------------------------------------------------------------------

%% 0) Select version with fix, "CtrlC_ExecOrder_fix"
set_param('CruiseControl_pp/ComponentVersion','compVer', ...
    'Execution Order Fix');
%% 1)  Reset holdrate to (5) in Parameters, and incdec to (1)
%% 2)  Select "CoastSet pulse with tspeed decrease" property
set_param('CruiseControl_pp/SelectProperty','property2prove', ...
    'CoastSet pulse with tspeed decrease');
save_system('CruiseControl_pp');
