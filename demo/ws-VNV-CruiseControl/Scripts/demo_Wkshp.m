%% ========================================================================
%       M O D E L    V E R I F I C A T I O N
%  ========================================================================

%% ========================================================================
%       Ad-hoc Testing
%  ========================================================================
%  0)  Change to "Work" directory
%  1)  Introduce Cruise Control module operation
%  2)  Use harness with constant inputs and boolean
%      Show tspeed value while running panel
%  3)  Find that it will occasionally create a runaway condition
CruiseControl_dd_RP;
CruiseControl_RP_harness
%  4)  Open "CruiseControl_RP", load "adhoc.mldatx" in port mapping
%      Look at tspeed and AccelResSw
%  5)  Set "Simulation/Stepping Options" to stop at 12.3 secs
%  6)  After 12 secs, set breakpoint when AccelResSw is false
%  7)  Continue stepping, missed "hasChangedTo" condition
%%  Open harness with "level exit" fix
CruiseControl_RP_level_harness

%% 
%% close
bdclose all
clear all

%% ========================================================================
%       Design Error Detection
%  ========================================================================
%  Open Cruise Control Algo Module
%  1)  Converted to integer cals and integer signals
%  2)  Checking for design errors before functional verification testing
CruiseControl_IntCalc
%  1)  Open "Design Verifier-->Options..."
%      -- show Design Error Detection options (Dead logic, Identify active)
%% 2)  Run "Dead Logic" detection, "Design Verfier-->Detect Design Errors
sldvhighlight('CruiseControl_IntCalc', ...
    '.\sldv_output\CruiseControl_IntCalc\CruiseControl_IntCalc_sldvdata_DeadLogic.mat');
%      -- run until transition is being continuously exercised
%      -- add breakpoint to transition when tested
%      -- in command window, show incdec/holdrate = 0, due to integer math
%% Debug dead logic
CruiseControl_IntCalc_harness
%  1)  Run with breakpoint on transition
%  2)  Order of integer operations will lead to dead logic, fix in both
%      decisions => move 10 to beginning of calc
%% Load the Fix 
CruiseControl_IntCalc_Fix
%% And load results
sldvhighlight('CruiseControl_IntCalc_Fix', ...
    '.\sldv_output\CruiseControl_IntCalc_Fix\CruiseControl_IntCalc_Fix_sldvdata_Archive.mat');

%% close
bdclose all

%% ========================================================================
%       Requirements Based Functional Testing
%  ========================================================================
%%  Open requirements word doc
winopen('cruise_control_reqs_SLT.docx');
%%  Open test cases based on reqs
winopen('CruiseControlTests.xlsx');
%%  *****  SIMULINK TEST VERSION  *****
% open SL Test
p = slproject.getCurrentProject;
copyfile(fullfile(p.RootFolder,'Models','CruiseControl_SLT_0.slx'), ...
    fullfile(p.RootFolder,'Models','CruiseControl.slx'));
if exist('cumcov_SLT.cvt','file')==2
    delete(which('cumcov_SLT.cvt'));
end
sltest.testmanager.load('CruiseControlTests_SLT_MC.mldatx');
sltest.testmanager.view;
%%  Open harness with partial coverage test vectors
%
%  ** navigate to "01_Functional_Baseline_Excel"
%  ** open harness 
%  ** simulation with expected values
%  ** evaluation with assert blocks
% 1)  Link back to reqs
% 2)  Open Coverage settings --  discuss settings
%
%  1)  Highlight use of Excel for direct input
%  2)  Show baseline criteria entry, no assertion blocks
%  3)  Run "Baseline_Regression_Normal_Excel" from SL Test to show full coverage
%  4)  Show Criteria result ans Sim Output result for "Disengage with
%  Brake"
%
% 3)  Run "Functional_PartialCov_SigBldr" from SL Test
% 4)  Show model coloring with results
% 5)  Lack of coverage
%     a)  Gap in requirements
%     b)  Missing test cases
%     c)  Incorrect or non-req based functionality

%% From the model coloring results, additional test cases were created
%  -- shown in spreadsheet with a green background 
winopen('CruiseControlTestsFullCov.xlsx');
%  ** navigate to "Baseline_type/Baseline_Regression_Normal_Excel"
%  ** open harness "CruiseControl_harness_Normal" from SLT
%  1)  Highlight use of Excel for direct input
%  2)  Show baseline criteria entry, no assertion blocks
%  3)  Run "Baseline_Regression_Normal_Excel" from SL Test to show full coverage
%  4)  Show Criteria result ans Sim Output result for "Disengage with
%  Brake"
%  Full coverage with all test cases passing, ready for product build
%% close
bdclose all
sltest.testmanager.close;
%%  Generate test cases for "top-it-off" full coverage
%  -- save cumulative coverage
cvsave('CruiseControlCovManual',covCumulativeData);
%  -- generate test cases, disable parameter table
%%  Merge and run full coverage harness
sldvmergeharness('CruiseControl_harness_FullCov_SLDV', ...
    {'CruiseControl_harness',...
    '.\sldv_output\CruiseControl\CruiseControl_harness_SLDV'}); 
%  -- disable assertions, no expected outputs for SLDV test cases
%  -- "Run all" to show 100% coverage results
%% close
bdclose all
%% From the model coloring results, additional test cases were created
%  -- shown in spreadsheet with a green background 
winopen('CruiseControlTestsFullCov.xlsx');
%%  Open harness with full coverage
CruiseControl_harness_FullCov
%  1)  Make model coverage is enable for referenced subsystems
%  2)  "Run All" to show full coverage
%  Full coverage with all test cases passing, ready for product build
%% close
bdclose all
%% ========================================================================
%       Equivalence Testing
%  ========================================================================
%%  *****  SIMULINK TEST VERSION  *****
% open SL Test
p = slproject.getCurrentProject;
copyfile(fullfile(p.RootFolder,'Models','CruiseControl_SLT_1.slx'), ...
    fullfile(p.RootFolder,'Models','CruiseControl.slx'));
if exist('cumcov_SLT.cvt','file')==2
    delete(which('cumcov_SLT.cvt'));
end
sltest.testmanager.load('CruiseControlTests_SLT_MC.mldatx');
sltest.testmanager.view;
%%  Open harness with partial coverage test vectors
%  ** navigate to "Evaluation_type/Equivalence_Normal_SIL_SigBldr"
%  ** show now there are (2) simulations, with INPUTS and EQUIVALENCE
%     CRITERIA
%  ** open "internal" harness "CruiseControl_Harness_SB_Normal" from SLT
%  ** navigate to "CruiseControl" show harnesses
%  ** close harnesses & model
%  ** back to SLT, show "Equivalence_Normal_SIL_Excel", with Excel inputs
%  ** open "CruiseControl_Harness_SIL" from SLT, show code cov settings
%  ** close models, run "Equivalence_Normal_SIL_Excel" or select a few
%     tests to show it
%  ** show codegen report to show links between model and code
%  ** show code coverage results  
%% reopen code gen report with code coverage (if necessary)
targets_hyperlink_manager('run',133);
%% close
bdclose all
sltest.testmanager.close;
%% close
bdclose all

%
%% ========================================================================
%       Reproducing Field Issues - Property Proving
%  ========================================================================
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
% %% 0)  For the Controls block, use the "CtrlA_Original" version
% set_param('CruiseControl_pp/ComponentVersion','compVer','Original');
%% 1)  Reset holdrate to (5) in Parameters, and incdec to (1)
%% 2)  Select "CoastSet pulse with tspeed decrease" property
set_param('CruiseControl_pp/SelectProperty','property2prove', ...
    'CoastSet pulse with tspeed decrease');
save_system('CruiseControl_pp');
%% 3)  Save model, run "Design Verifier-->Prove Properties-->Model"
%  4)  Create harness, show port value labels, configure SDI and 
%      run to show Tspeed increase
%  5)  Single step to show path through "sneak path"
%      -- Enable stepping backward
%% 6)  Select fix in pp harness
set_param('CruiseControl_pp_harness/Test Unit (copied from CruiseControl_pp)',...
    'Permissions','ReadWrite');
set_param('CruiseControl_pp_harness/Test Unit (copied from CruiseControl_pp)/ComponentVersion', ...
    'compVer','Execution Order Sneak Fix');
%% 7)  Go back to  pp harnessFor the Controls block, use "CtrlD_ExecOrderSneak_fix" version
if ~strcmp(get_param('CruiseControl_pp_harness','SimulationStatus'),'stopped')
    set_param('CruiseControl_pp_harness','SimulationCommand','Stop')
end
close_system('CruiseControl_pp_harness',0);
set_param('CruiseControl_pp/ComponentVersion','compVer','Execution Order Sneak Fix');
%% 8)  Re-run "Design Verifier-->Prove Properties-->Model" ==> Valid!!
save_system('CruiseControl_pp');
%% 9)  Show eml version: "CoastSet pulse (eml) with tspeed decrease"
set_param('CruiseControl_pp/SelectProperty','property2prove', ...
    'CoastSet pulse (eml) with tspeed decrease');
%% 10) Run again to show eml version of property (field issue behavior) model
save_system('CruiseControl_pp');
%
%
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
%% 3) Run "Design Verifier-->Prove Properties-->Model"
%     -- Look at report
%  4) Results will show for a speed (??), and incdec (2) --> falsified
%  5) Enable backstepping, show port value labels
%% 6)  Select fix in pp harness
set_param('CruiseControl_pp_harness/Test Unit (copied from CruiseControl_pp)',...
    'Permissions','ReadWrite');
set_param('CruiseControl_pp_harness/Test Unit (copied from CruiseControl_pp)/ComponentVersion', ...
    'compVer','Execution Order Sneak Double Reject Fix');

%% 6) Select version with fix, "CtrlE_ExecOrderSneakDblReject_fix"
if ~strcmp(get_param('CruiseControl_pp_harness','SimulationStatus'),'stopped')
    set_param('CruiseControl_pp_harness','SimulationCommand','Stop')
end
close_system('CruiseControl_pp_harness',0);
set_param('CruiseControl_pp/ComponentVersion','compVer', ...
    'Execution Order Sneak Double Reject Fix');
%% 7) Re-run Prop Proving to show that it can be falsified with incdec=2
save_system('CruiseControl_pp');
%
%% 8) Run "Design Verifier-->Prove Properties-->Model"
%     -- Look at report
%  9) Results will show for a speed (20), and incdec (2) --> falsified
%  10)Enable backstepping, show port value labels
%% 6) Select version with fix, "CtrlG_All_fix"
if ~strcmp(get_param('CruiseControl_pp_harness','SimulationStatus'),'stopped')
    set_param('CruiseControl_pp_harness','SimulationCommand','Stop')
end
close_system('CruiseControl_pp_harness',0);
set_param('CruiseControl_pp/ComponentVersion','compVer', ...
    'All Fix');
%% 7) Re-run Prop Proving to show that it can't be falsified!!
save_system('CruiseControl_pp');
%
%  Incremental improvement:  Sneak path --> limit check --> 
%  double press check
%
%% open SL Test - re-run verification to show all pass after pp changes
bdclose all;
p = slproject.getCurrentProject;
copyfile(fullfile(p.RootFolder,'Models','CruiseControl_SLT_2.slx'), ...
    fullfile(p.RootFolder,'Models','CruiseControl.slx'));
if exist('cumcov_SLT.cvt','file')==2
    delete(which('cumcov_SLT.cvt'));
end
sltest.testmanager.load('CruiseControlTests_SLT_MC.mldatx');
sltest.testmanager.view;
%% close
bdclose all
%