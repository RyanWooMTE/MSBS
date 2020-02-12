%% Model-Based Design for ARP-4754A, DO-178C and DO-331
%
% This demo provides an example of how to apply Model-Based Design to an
% ARP-4754A/DO-178C/DO-331 project using The MathWorks tools.  The demo
% includes many of the development and verification lifecycle stages called
% out by ARP-4754A, DO-178C and DO-331.
%

%% System Requirements
% The system requirements for the roll axis of the autopilot
%
% <matlab:winopen('..\requirements\do178b_autopilot_requirements.docx'); Open *do178b_autopilot_requirements.docx*>
%

%% System Requirements Validation
% Requirements validation is defined as showing that the *requirements are complete and correct*. 
%

%% System Design
%
% <matlab:configure_model_for_Normal; Open system model *do178b_dhc2.slx*>
%
% <matlab:configure_model_with_FlightGear; Open system model *do178b_dhc2_FlightGear.slx*>
%

%% Software Requirements
% *1. Functional Requirement*
%
% <matlab:winopen('..\requirements\do178b_autopilot_requirements.docx'); Open *do178b_autopilot_requirements.docx*>
%

%% Software Design and Architecture
% *1. Model Dependency Viewer*
%
% <matlab:view_mdlrefs('..\models\Autopilot'); Open *Model Dependency Viewer* for *Autopilot*>
%
% *2. Control Model*
% 
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('..\models\Autopilot'); Open *Autopilot.slx*> 
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('..\models\roll_ap.slx'); Open *roll_ap.slx*>


%% Software Design Review
% *1. System Design Description*
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('..\models\roll_ap');rptcfg=StdRpt.SDD(bdroot);rptcfg.outputDir='..\reports';rptcfg.run(); Generate *System Design Description* report>
%
% <matlab:open('..\reports\roll_ap.pdf'); Open *System Design Description report* for *roll_ap* model>
%
% *2. Web View*
%
% <matlab:winopen('..\reports\roll_ap_slwebview.html'); Open *Web View report* for *roll_ap* model>
%
% *3. Modeling Guidelines*
%
% <matlab:web([docroot,'/simulink/high-integrity-systems.html']); Open
% *Documetation about Modeling Guidelines*>
%
% *4. Model Advisor Checks*
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('roll_ap');ma=Simulink.ModelAdvisor.getModelAdvisor('roll_ap');IDs=ma.getCheckForGroup('Simulink%20Verification%20and%20Validation|Modeling%20Standards|DO-178C/DO-331%20Checks');marpt=ModelAdvisor.run('roll_ap',IDs);marpt{1}.viewReport;
% Generate *roll_ap* model advisor report>
%
% <matlab:winopen([pwd%20'\slprj\modeladvisor\roll__ap\report.html']);
% Open *Model Advisor Report* for *roll_ap* model>
%

%% Software Requirements Verification
%
% *1. Module Test*
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('roll_ap_testharness'); Open *roll_ap_testharness*>
%
% *2. Test Generation for Missing Coverage*
%
% <matlab:open('..\utilities\Achieving_Missing_Coverage.m'); Open *Achieving_Missing_Coverage.m*>
%

%% System Design Verification
% For DO-331 it is necessary to have requirements verification artifacts
% with respect to compliance to the system requirements, accuracy and consistency, verifiability and algorithm accuracy.
%
% For ARP-4754A, DO-178C and DO-331, it is necessary to have an artifact
% that shows traceability between System Requirements and Software Requirements.
%
% *1. Verification Blocks*
%
% <matlab:bdclose('all');configure_model_for_Normal;open_system('do178b_dhc2/Verification_Blocks'); Open *Verification_Blocks* subsystem>
%
% *2. Test Automation with Simulink Report Generator*
%
% <matlab:setedit('..\reports\rpt_files\Roll_AP_Tests_loop_sim'); Open *Report Generator* for this demo>
%
% <matlab:report('..\reports\rpt_files\Roll_AP_Tests_loop_sim.rpt'); Generate *Simulation Report*>
%
% <matlab:winopen('..\reports\Roll_AP_Tests_loop_sim.html'); Open the *Simulation Report* for *roll_ap*>

%% Source Code
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('..\models\roll_ap'); Open *roll_ap* model>
%
% <matlab:slbuild('roll_ap');
% Generate code and open *code generation report* for *roll_ap*>
%

%% Source Code Verification
%
% *1. Simulink Code Inspector*
%
% Simulink Code Inspector verifies that the source code structurally and functionally matches the model.
%
% <matlab:config=slci.Configuration('roll_ap');config.setTopModel(true);config.setGenerateCode(false);config.setFollowModelLinks(true);config.inspect;open([pwd%20'\slprj\slci\roll_ap_summaryReport.html']);
% Inspect *roll_ap* and reference model code and generate summary report>
%
% <matlab:winopen([pwd%20'\slprj\slci\roll_ap_summaryReport.html']);
% Open *Code Inspection Report*>
% 
% *2. Polyspace Code Verification*
%
% PolySpace Products perform verification activities on the source code.
% This includes a MISRA-AC-ACG checker that can verify the code conforms to standards. A static analysis tool performs checks on the code to look for potential run time errors, unreachable code, un-initialized variables or data coupling issues.
%
% <matlab:load('..\data\DO178ConfigSetNormal.mat');open_system('..\models\roll_ap');psopts=pslinkoptions('roll_ap');resultsFolder=pslinkrun('roll_ap',psopts);
% Analyze *roll_ap* code and generate *Developer Report*>
%
% <matlab:open([pwd%20'\results_roll_ap\roll_ap\Polyspace-Doc\roll_ap_Developer.pdf']);
% Open *Developer Report*>
%
% *3. Code Coverage in SIL with LDRA*
%
% During requirements based testing it is also necessary to perform
% structural coverage analysis on the code to measure statement (Levels A,
% B and C), decision (Levels A and B) and modified condition/decision coverage (Level A).
%
% <matlab:configure_model_for_SIL; Open *do178b_dhc2.slx* with SIL configuration>
%

%% Executable Object Code Verification
% *1. Processor-In-the-Loop*
%
% %<matlab:configure_model_for_PIL; Open *do178b_dhc2.slx* with PIL configuration>
%

