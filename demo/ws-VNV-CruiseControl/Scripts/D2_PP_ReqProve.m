%% ========================================================================
%       Requirement + No Input Constraints - Property Proving
%  ========================================================================
%% close
bdclose all
clear all
%  Open property proving model with
CruiseControl_pp
%%  Option #2 -  With fix, check will all parameters, a "requirement" property
% -------------------------------------------------------------------------
%  0) For the Controls block, select version "CtrlD_ExecOrderSneak_fix"
set_param('CruiseControl_pp/ComponentVersion','compVer', ...
    'Execution Order Sneak Fix');
%% 1) Make sure "CoastSet pulse with tspeed decrease" property has been selected
%     --  Use a "requirement" property
%     --  Let all inputs "float"
set_param('CruiseControl_pp/SelectProperty','property2prove', ...
    'CoastSet with tspeed limit decrease');
%% 2) Open "Design Verifier-->Options...", show Parameter table
%     -- "Clear", "Find in Model", use range for holdrate and incdec
%     -- Use the parameter ranges to open up the proof
save_system('CruiseControl_pp');
