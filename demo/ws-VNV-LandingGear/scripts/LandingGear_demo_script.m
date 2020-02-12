%% Landing Gear Warning Demo
%
% This demo is designed to demonstrate entire model-based SW verification process
%
% Written by Sang-Ho Yoon
% 

%% Overveiw of Landing Gear
%
% <matlab:open('wing_landing_gear.slx') Open *wing_landing_gear.slx*>
%

%% Design Review
%
% *1. Functional Requirement*
%
% <matlab:winopen('..\requirements\DisplaySystemRequirements.docx'); Open *DisplaySystemRequirements.docx*>
%
% *2. Control Model*
%
% <matlab:open('LandingGearMode.slx') Open *LandingGearMode.slx*>
%
% *3. System Design Description*
%
% <matlab:open_system('LandingGearMode.slx');rptcfg=StdRpt.SDD(bdroot);rptcfg.outputDir='..\reports';rptcfg.run(); Generate *System Design Description* report>
%
% <matlab:open('..\reports\LandingGearMode.pdf'); Open *System Design Description report* for *LandingGearMode* model>
%
% *4. Web View*
%
% <matlab:winopen('..\reports\LandingGearMode\webview.html'); Open *Web View report* for *LandingGearMode* model>
%

%% Static Analysis in Design Phase
%
% *1. Modeling Guidelines*
%
% <matlab:web([docroot,'/simulink/high-integrity-systems.html']); Open
% *Documetation about Modeling Guidelines*>
%
% *2. Property Proving*
%
% Test Harness is attached to "LandingGearModes" chart
%
% Execution Order is mistaken between outer transitions of "BothUnLocked" state
%

%% Dynamic Test with Model
%
% *1. Requirement-based Test*
%
% Test Harness is attached to "LandingGearMode" model
%
% *2. Test Generation for Missing Coverage*
%
% <matlab:open('..\utilities\Achieving_Missing_Coverage.m'); Open *Achieving_Missing_Coverage.m*>
%
% *3. Test Manager*
%
% <matlab:open('..\tests\LandingGearMode_Test.mldatx'); Open *LandingGearMode_Test.mldatx*>
%
% *4. Integrating Legacy Code with Simulink*
%
% <matlab:open('..\src\LGMode_lct.c'); Open *LGMode_lct.c*>
%
% <matlab:open('..\src\LGMode_lct.h'); Open *LGMode_lct.h*>
%
% <matlab:open('..\utilities\LGMode_lct.m'); Open *LGMode_lct.m*>
%
% *5. S-function Coverage for Legacy Code*
%
% Test Harness is attached to "LandingGearMode_sfunction" model
%
% <matlab:open_system('LandingGearMode_sfunction.slx'); Open *LandingGearMode_sfunction.slx*>
%

%% Code Generation and Review
%
% *1. Generate Codes from Model*
%
% <matlab:open('LandingGearMode.slx') Open *LandingGearMode.slx*>
%
% *2. Code Generation Report*
%
% Code Interface Report
%
% Traceability Report
%
% Static code Metrics Report
%
% *3. Simulink Code Inspector*
%
% <matlab:if(exist('LandingGearMode_optim_ert_rtw','dir'));rmdir('LandingGearMode_optim_ert_rtw','s');end;bdclose('all');open('LandingGearMode_optim.slx') Open *LandingGearMode_optim.slx*>
%

%% Static Analysis
%
% *1. Formal Verification with Polyspace*
%
% <matlab:winopen('.\results_LandingGearMode\LandingGearMode\Polyspace-Doc\LandingGearMode_Developer.pdf'); Open *Polyspace Developer Report*>
%

%% Equivalence Test
%
% *1. Software-in-the-loop*
%
% Test Harness is attached to "LandingGearMode" model
%
% *2. Processor-in-the-loop*
%

