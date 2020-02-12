%% Model-Based Design for ARP-4754A, DO-178C and DO-331
% This demo provides an example of how to apply Model-Based Design to an
% ARP-4754A/DO-178C/DO-331 project using The MathWorks tools.  The demo includes
% many of the development and verification lifecycle stages called out by
% ARP-4754A, DO-178C and DO-331.
%
% The following product licenses are used in portions of this
% demonstration:
%
% * <matlab:web('http://www.mathworks.com/products/matlab/','-browser');
% MATLAB>
% * <matlab:web('http://www.mathworks.com/products/ML_reportgenerator/','-browser');
% MATLAB Report Generator>
% * <matlab:web('http://www.mathworks.com/products/simulink/','-browser');
% Simulink>
% * <matlab:web('http://www.mathworks.com/products/SL_reportgenerator/','-browser');
% Simulink Report Generator>
% * <matlab:web('http://www.mathworks.com/products/simverification/','-browser');
% Simulink Verification and Validation>
% * <matlab:web('http://www.mathworks.com/products/aeroblks/','-browser');
% Aerospace Blockset>
% * <matlab:web('http://www.mathworks.com/products/matlab-coder/','-browser');
% MATLAB Coder>
% * <matlab:web('http://www.mathworks.com/products/simulink-coder/','-browser');
% Simulink Coder>
% * <matlab:web('http://www.mathworks.com/products/embedded-coder/','-browser');
% Embedded Coder>
% * <matlab:web('http://www.mathworks.com/products/simulink-code-inspector/','-browser');
% Simulink Code Inspector>
% * <matlab:web('http://www.mathworks.com/products/polyspaceserverc/','-browser');
% PolySpace Server for C/C++>
% * <matlab:web('http://www.mathworks.com/products/polyspaceclientc/','-browser');
% PolySpace Client for C/C++>
% * <matlab:web('http://www.mathworks.com/products/polyspacemodelsl/','-browser');
% PolySpace Model Link SL>
%
% The demo, which is based on a very simple autopilot implementation, has
% been fully tested in Release R2012b, but may work with newer releases.
% The autopilot in this demo is controlling a DeHavilland Beaver airframe.
%
% This document also contains macros, so if macros were disabled when
% opening this document, links within the document will not work properly.
% The links to help for the various products assume that the help
% documentation has been installed along with the product.  Those links
% will not work properly if only web based help is used for your MATLAB
% installation.
%% Lifecycle Overview
% The following lifecycle stages defined in ARP-4754A, DO-178C and DO-331 
% are covered in this demonstration:
%
% * ARP-4754A Section 5.3 Requirements Capture
% * ARP-4754A Section 5.4 Requirements Validation
% * ARP-4754A Section 5.5 Implementation Verification
% * DO-178C Section 2.1 System Requirements Allocated to Software
% * DO-331 Section MB.5.1 Software Requirements Process
% * DO-331 Section MB.5.2 Software Design Process
% * DO-178C Section 5.3 Software Coding Process
% * DO-331 Section MB.5.5 Software Development Process Traceability
% * DO-331 Section MB.6.3.1 Reviews and Analyses of High-Level Requirements
% * DO-331 Section MB.6.3.2 Reviews and Analyses of Low-Level Requirements
% * DO-331 Section MB.6.3.3 Reviews and Analyses of Software Architecture
% * DO-331 Section MB.6.3.4 Reviews and Analyses of Source Code
% * DO-331 Section MB.6.5 Software Verification Process Traceability
% * DO-331 Section MB.6.7 Model Coverage Analysis for Design Models
% * DO-331 Section MB.6.8.1 Model Simulation for Verificaiton of the Model
% * DO-331 Section MB.6.8.3 Simulation Cases, Proceddures and Results
%% System Requirements
% The system requirements for the roll axis of the autopilot are provided 
% in a Microsoft Word document.  Each requirement is implemented in a
% section of the document which also contains rationale for the
% requirement.  The requirements are traced to the design model via
% electronic hyperlinks using Simulink Verification and Validation.
%
% <matlab:winopen('do178b_autopilot_requirements.docx'); Open the
% requirements document>
%
% To view a block in the model that traces to a requirement, double click
% on one of the hyperlinks to the right of the section heading.  The
% *roll_ap* model will open and the block linked to the requirement will be
% highlighted in the model.
%
% For more information about the *Requirements Management Interface* see
% the *Help for Simulink Verification and Validation*.  This describes how
% to interface to various document formats, including Word, as well as how
% to interface to DOORS.
%
% <matlab:doc('slvnv'); Help for Simulink Verification and Validation>
%
%% System Requirements Validation
%
% Requirements validation is defined as showing that the requirements are
% complete and correct.  Requirements validation is typically performed by
% reviewing the requirements using a checklist, or similar means, based on
% requirements standards for the project.  
%
% ARP-4754A also calls out modeling, simulation and prototyping as methods 
% of validating requirements.  As the system design is developed, as 
% described in the following section on system design, simulation of the 
% model may be used to ensure completeness and correctness of the
% requirements.  This simulation may uncover undesirable behavior that was
% not considered in the requirements or it may be determined that the
% requirements are not verifiable.  Hardware prototyping may also be used
% to validate requirements.  Simulink, Real-Time Workshop and xPC Target 
% allow hardware in the loop prototyping that can be used as a part of
% requirements validation. Hardware prototyping is not covered in this
% demo.
%% System Design
% The system design is implemented in the Simulink model *do178b_dhc2*. 
% 
% <matlab:open_system('do178b_dhc2'); Open the system model> 
%
% The top level of the model consists of the following subsystems:
% 
% * DeHavilland Beaver Airframe (plant model)
% * Environment (atmosphere, gravity and wind models)
% * Signal Conditioning (electrical to mechanical interfaces)
% * Air Data Sensor (sensor feedback model)
% * Inertial Data Sensor (sensor feedback model)
% * Cockpit Controls (pilot interface)
% * Engage and Mode Panel (autopilot interface/test stimulus)
% * Reference Signals (autopilot interface/test stimulus)
% * Verification_Blocks(requirements based test verification)
% 
% The top level of the model also contians the following model reference
% block:
%
% * Autopilot (controller model)
% 
% <matlab:open_system('Autopilot'); Open the Autopilot model> 
%
% The layout of the top level illustrates a basic system architecture that
% not only represents the system design, but also provides the capability
% to verify that the system design satisfies the system requirements.
%
% The top level of the model includes a model information block showing the
% model version and date that the model was last saved.
%
% The use of this model will be discussed in the following sections in more
% detail.
%% System Design Verification
%
% With the system design implemented in the Simulink model *do178b_dhc2*,
% it is possible to verify the design against the system requirements
% without having to first implement that design in actual hardware and
% software.  This is the advantage of Model-Based Design.  
%
% At the top level of the model *do178B_dhc2*, there are three signal 
% builder blocks provided to conduct specific tests during simulation.  
% These blocks are:
%
% * Engage and Mode Panel (autopilot interface/test stimulus)
% * Reference Signals (autopilot interface/test stimulus)
% * Cockpit Controls (pilot interface)
%
% Each of these blocks can be opened in the model by double clicking them
% to see the definition of the test signals and test groups within the
% signal builder blocks.  These blocks also contain traceability back to
% the system requirements document for the requirements that will be tested
% using each group of signals.  For more detailed information about how to
% use the signal builder blocks, see the help section for that block in
% Simulink Help.
%
% <matlab:doc('simulink/signalbuilder'); Help for Signal Builder block>
%
% Signal stimulation can also be accomplished via other means, such as
% using other Simulink source blocks or by using From Workspace blocks in
% conjunction with MATLAB scripts or MAT files that load data to the 
% workspace.  It is also possible to use the Data Import/Export 
% Configuration Parameters dialogue to get data from the MATLAB workspace.
%
% Of course test stimulus alone is not enough to verify the system design
% is satisfying the requirements.  Assertion blocks, which are contained in
% the subsystem *Verification_Blocks*, can be used to determine whether or
% not the system requirements are satisfied by the design during
% simulation.  To see the verification blocks open this subsystem.
%
% <matlab:open_system('do178b_dhc2');open_system('do178b_dhc2/Verification_Blocks');
% Open Verification_Blocks subsystem>
%
% The following four Assertion Blocks can be found in this subsystem
%
% * Check Dynamic Roll
% * Check Roll Range
% * Check Roll Rate Range
% * Check Aileron Range
%
% The assertions *Check Roll Range*, *Check Roll Rate Range* and *Check
% Aileron Range* provide minimum and maximum values for roll angle, roll
% rate and aileron angle respectively.  These assertions are enabled during
% all test cases and the values are based on the *Autopilot Requirements
% Document*, including tolerances.  For example, the requirement for the
% maximum roll angle is 30 degrees +/-10%, which means the allowable roll
% angle is from -33 degrees to +33 degrees.
%
% The assertion *Check Dynamic Roll* provides a window between minimum and
% maximum values that is dependent upon the test case being executed.  The
% signal builder block *Roll References* is used to provide the minimum and
% maximum values for each test case using signal groups. This block can be 
% opened in the model by double clicking it to see the definition of the
% test signals and test groups within the signal builder block.  This block
% also contains traceability back to the system requirements document for
% the requirements that will be tested using each group of signals.
%
% The use of three signal builder blocks for test stimulation and one
% signal builder block for assertion control requires that the selected
% groups of each of these blocks be coordinated.  *MATLAB Report Generator*
% is used for this coordination of the test cases and also to provide
% automated test case execution.  
%
% <matlab:setedit('Roll_AP_Tests_loop_sim'); Open Report Generator for this demo>
%
% MATLAB Report Generator provides a framework for setting up simulations, 
% executing them, and finally generating a test report.  For more 
% information about MATLAB Report Generator, see the help.
%
% <matlab:doc('rptgen'); Help for Report Generator>
%
% The report file *Roll_AP_Tests_loop_sim.rpt* perfoms the following
% sequence to run the simulation cases and procedures, as well as verifying
% the results:
%
% * Opens the test harness model and inserts a snapshot into the report
% * Opens the autopilot model and inserts a snapshot into the report
% * Opens the verification subsystem in the test harness model and inserts
% a snapshot into the report
% * Sets up arrays for Signal Builder block cases, initial Roll Angles,
% Test Descriptions and Test Criterias for 20 different tests
% * Executes a loop of 20 simulation cases that include the following:
%
% # Lists the requirements being verified for each individual iteration
% # Lists a description of the test for each individual iteration
% # Lists the test results criteria for each individual iteration
% # Sets the initial roll angle for each individual iteration
% # Sets the Signal Builder blocks cases for each individual iteration
% # Runs the simulation of the test harness for each individual iteration
% # Generates a plot of the simualtion results for each individual iteration
% # Generates a pass or fail indication of the  results for each individual
% iteration
%
% * Inserts a link to the model coverage cummulative summary report
% * Provides a summary pass or fail indication for the cumulative results
%
% To run the simulations, clidk on the link below, this will take a few
% minutes to execute.
%
% <matlab:report('Roll_AP_Tests_loop_sim.rpt'); Generate Simulation Report>
%
% A Model Coverage report is also generated during testing. To view this
% report click on the link below.
%
% <matlab:open('roll_ap_cov.html'); Open the Model Coverage report for roll_ap>
%
%% Software Requirements
% From the system design, specific functions are allocated to software in
% order to form the software requirements.  For this system design, the
% *Autopilot* subsystem in *do178b_dhc2* is being allocated to software,
% and therefore becomes the high level software requirements.
%
% <matlab:open_system('Autopilot'); Open Autopilot model>
%
% It can be seen within the *Autopilot* model that the architecture is
% further broken down into *Roll_Autopilot*, *Pitch_Autopilot* and
% *Yaw_Damper*.  This provides several important features in the design:
%
% * The roll, pitch and yaw axes of the autopilot are all configured as
% separate files which can be reviewed and tested independently
% * The source code for the roll, pitch and yaw axes are all configured as
% separate files which can be reviewed separately
% * The test harness is configured in a completely separate file and
% changes to the test harness do not affect the models used for embedded
% code generation
%
% We can now open the separate *roll_ap* model to see the actual
% functionality that is allocated to software.
%
% <matlab:open_system('roll_ap'); Open roll_ap model> 
%
% It can be seen within the *roll_ap* model that the architecture is
% further broken down into *Heading Mode*, *Roll Reference* and
% *Basic Roll Mode* systems.  *Heading Mode* and *Basic Roll Mode* are 
% separate reference models, while *Roll Reference* is a subsystem. Either 
% of these reference models or the subsystem can be opened, and the basic
% functionality comprised of Simulink blocks will be found.
%
% The top level of the model includes a model information block showing the
% model version and date that the model was last saved.
%
% To view a requirement associated with a block in the model, right click
% on the Mode Switch block, go to Requirements on the tab and then select 
% "1.2. Roll Hold Mode" and the Autopilot Requirements document will open
% With section 1.2 Roll hold Mode highlighted. 
%% Software Requirements Verification
% For DO-331 it is necessary to have requirements verification artifacts
% with respect to compliance to the system requirements, accuracy and
% consistency, verifiability and algorithm accuracy.  The simulation
% activities described in the previous section can be used to cover these 
% objectives in DO-331.  
%
% For ARP-4754A, DO-178C and DO-331, it is necessary to have an artifact
% that shows traceability between System Requirements and Software
% Requirements.  A *System Design Description* report can be generated
% using the *Simulink Report Generator* and this document contains a
% section that includes the traceability information from the model to the
% requirements document.  This report may take a few minutes to complete.
%
% <matlab:open_system('roll_ap');rptcfg=StdRpt.SDD(gcs);rptcfg.run();
% Generate the System Design Description report>
%
% This report provides a complete description of the model, including:
%
% * Snapshots of the top level model and all subsystems
% * Interfaces for the top model and all subsystems
% * Block execution order
% * Details of all block dialogue settings
% * Details of all parameters and signals used in the model
% * Traceability from the model objects to the requirements document
% * Details of all the model configuration settings
% * Glossary and report explanation
%
% For more information about the *Requirements Management Interface* see
% the *Help for Simulink Verification and Validation*.  This describes how
% to interface to various document formats, including Word, as well as how
% to interface to DOORS.
%
% <matlab:doc('slvnv'); Help for Simulink Verification and Validation>
%
% As a part of the DO-178C lifecycle, the high and low level requirements
% must be verified to comply with standards and it must also be shown that
% the requirements are compatible with the target computer.  The Model
% Advisor provides the capability to perform static checks on the model in
% order to verify many standards automatically and to verify certain code
% generator option settings related to hardware compatibility.  To generate
% the Model Advisor report for the roll_ap model, select the link below.
% This may take a few minutes to complete.
%
% <matlab:open_system('roll_ap');ma=Simulink.ModelAdvisor.getModelAdvisor('roll_ap');IDs=ma.getCheckForGroup('Simulink%20Verification%20and%20Validation|Modeling%20Standards|DO-178C/DO-331%20Checks');marpt=ModelAdvisor.run('roll_ap',IDs);marpt{1}.viewReport;
% Generate roll_ap model advisor report>
%
%% Software Design and Architecture
% The software design and architecture is defined within the roll_ap model
% and the Heading_Mode and attitude_controller reference models for the
% control portion of the roll autopilot function.  For this function the
% code will be generated directly from the high level software
% requirements, therefore the model satisfies both the high and low level
% software requirements.
% 
% To view the architecture of the roll_ap model and it's referenced models
% open the following:
%
% <matlab:view_mdlrefs('roll_ap'); Open Model Dependency Viewer for roll_ap>
%
% To view the architecture of the entire autopilot model and it's
% referenced models open the following:
%
% <matlab:view_mdlrefs('Autopilot'); Open Model Dependency Viewer for Autopilot>
%
% There will be additional design and architecture activities that will be
% required beyond just the model in order to fully define the high and low
% level software requirements.  For example, there will be requirements and
% design associated with processing the inertial reference and air data
% sensor inputs, passing those inputs to the model inputs, and scheduling
% these two task in the proper order.  These activities are not included as
% a part of this demo.
%% Software Design Verification
% Because the high and low level software requirements have been combined 
% for this demo, the software requirements verification activities 
% previously discussed are being used to also cover the software design
% verification activities.
%% Source Code
% The source code is generated from the roll_ap model using Embedded Coder.
% The *ert.tlc* target is used for this demo.  The use of this target
% provides a good baseline for generating traceable and MISRA compliant
% code.  The Model Advisor for this demo is using configuration settings
% necessary for MISRA compliance and high integrity code.  
%
% The code for the roll_ap model and it's referenced modesl can be 
% generated and an HTML report can be viewed by clicking the following link.
%
% <matlab:slbuild('roll_ap','ModelReferenceRTWTargetOnly');
% Generate code and open code generation report for roll_ap>
%
% The C code file  can be opened from the HTML report by clicking
% roll_ap.c.  To see how the code traces to the model go to line 93 and
% click on the link '<S3>/FixPt Unit Delay1'.  This will open the roll_ap
% model and highlight the Unit Delay block in the subsystem *Roll
% Reference* of roll_ap model.  Other trace links can be found in the code
% and examined if desired.  It can also be seen that code within the atomic
% subsystem, *Roll Reference* is clearly commented in the code file and
% contained on contiguous lines. 
%
%% Source Code Verification
% Source code verification is performed using *Simulink Code Inspector* and
% *Polyspace*.  Simulink Code Inspector verifies that the source code
% structurally and functionally matches the model.  The Simulink Code
% Inspector also verifies that the model and code trace to each other. To
% run the code inspection on roll_ap, click on the link below.
%
% <matlab:config=slci.Configuration('roll_ap');config.setTopModel(false);config.setGenerateCode(false);config.setFollowModelLinks(true);config.inspect;open([pwd%20'\slprj\slci\roll_ap_summaryReport.html']);
% Inspect roll_ap and reference model code and generate summary report>
%
% PolySpace Products perform verification activities on the source code.
% This includes a MISRA-AC-ACG checker that can verify the code conforms to 
% standards.  A static analysis tool performs checks on the code to look 
% for potential run time errors, unreachable code, un-initialized variables
% or data coupling issues.  
%
% Polyspace is not currently part of this demo.
%% Executable Object Code
% The executable object code will be generated from the source code using
% third party compilers/linkers.  Embedded Coder can assist in the
% generation of make files for the software build process or this can be
% done manually.  See the Embedded Coder Help for more information about
% this capability.
%
% <matlab:doc('ecoder'); Help for Embedded Coder>
%% Executable Object Code Verification
% The executable object code may be verified using the
% Processor-In-The_Loop mode (PIL) availble with Embedded Coder.  This
% allows the simulation cases run using the report generator to be re-run
% easily on a traget board connected to Simulink via a serial bus.  For
% more informaiton about PIL mode, see the Embedded Coder help:
%
% <matlab:doc('ecoder'); Help for Embedded Coder>
%
% PIL mode is not currently part of this demo.
%
% During requirements based testing it is also necessary to perform
% structural coverage analysis on the code to measure statement (Levels A,
% B and C), decision (Levels A and B) and modified condition/decision
% coverage (Level A).  This is normally considered to be one of the most
% expensive and time consuming aspects of DO-178C objectives.  
% 
% During execution of the tests on the object code using the PIL mode, it
% is recommended to use a code coverage tool to evaluate the structural 
% coverage of the code.  There are many third party coverage tools
% available for analyzing code coverage.  Some of these tools instrument
% the code, in which case the tests need to be run on instrumented and
% un-instrumented versions of the object code.  Embedded Coder provides
% integration with Bullseye and LDRA code coverage tools.
%% Conclusion
% The purpose of this demo was to provide a possible approach to satisfying
% many of the objectives of DO-178C when using a Model-Based Design
% process.  Other approaches and variations to the approach in this demo
% are also possible.
%
% Here is a list of potential advantages when using Model-Based Design with
% The MathWorks tools:
% 
% * Early requirements validation as the design process starts
% * Verification of the design and elimination of errors early in
% development
% * Test case and procedure development early in the project, not as an
% afterthought
% * Coverage metrics early in the project, no surprises or extra work at
% the end
% * Improved code quality via automatic code generation
% * Automated source code analysis and standards compliance checking
% * Automated test execution provides simplified but thorough regression
% testing
% * Complete traceability between requirements, design, code and test cases
% 