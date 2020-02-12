%% Model Verification and Validation Demonstration
%

%% Contents of flies
% This demo consists from the following files:
%
% *Utility for running demos*
%
% * |ModelVerificationDemo_en.html| A HTML file for running demos
% * |startup_demo.m|: A start up file for setting up an environment.
%
%
% *Models*
%
% * |cruise_control_top.mdl| : Top-level model.
% * |cruise_control_top_fixpt.mdl| : Top-level model where the cruise controller is fixed-point.)
% * |controller.mdl| : Top controller model.
% * |cruise_control.mdl| : Cruise controller model
% * |cruise_control_sdo.mdl| : Implementation model for the cruise controller both for floating- and fixed-point model.
% * |cruise_control_prop.mdl| : An example model for property proving without errors.
% * |cruise_control_prop_error.mdl| : An example model for property proving with errors.
% * |cruise_control_MILSIL.mdl| : Back-to-back testing model between Model-In-the-Loop Simulation and Software-In-the-Loop Simulation (C-code)

%%
% *Data files*
%
% * |cruise_control_data.m| : A data file for the cruise controller.
% * |transmission_data.m| : A data file for the transmission controller.
% * |cruise_control_flp.xls| : A data dictionary for floating-point (single) cruise controller implementation model.
% * |cruise_control_fxp.xls| : A data dictionary for fixed-point cruise controller implementation model.
% * |load_float_data.m| : To load floating-point data dictionary.
% * |load_fxpt_data.m| : To load fixed-point data dictionary.
%
% *Test inputs*
%
% * |TestSenario.xls| : An Excel spread sheet with test inputs that can be imported from the Signal Builder block in the top model.
%
% *Requirement specification and Verification specification*
%
% * |CruiseControl_spec.xls|: Requirement specification and Verification specification for the cruise controller model.
% * |CruiseControl_spec_q02.xls| : Requirement specification and Verification specification for the cruise controller model for exercise.
% * |CruiseControl_spec_ref.xls| : Requirement specification and Verification specification for the cruise controller

%% External utilities
% This demonstration uses the following external tools that can be downloaded from File Exchange in MATLAB Central.
%
% * <http://www.mathworks.com/matlabcentral/fileexchange/31609-cmtdtool/content/cmtdtool/doc_ja/description.html cmtdtool> An utility for model-based verification derived from JMAAB.
% * <http://www.mathworks.com/matlabcentral/fileexchange/20316-sdoxlsif-excel-interface-api-for-simulink-data-object SDOxlsIF> An utility for importing Data Dictionarydefined in an Excel as Simulink Data Objects
%

%% Preparation
% Before running this demo, run a script to set up the environment by clicking the following link.
%
% <matlab:startup_demo Run starting up script>

%%
% Click below to clean up unnecessary files.
%
% <matlab:clear_demo Delete unnecessary files>

%% View Top-level model
% 
% <matlab:rundemo_helper('openTopModel') Click to run>

%% View top model of the controller
% This displays the top layer of the controller model consists from multiple modules.
% This corresponds to a simple structure layer. 
%
% <matlab:rundemo_helper('openCtrlModel') Click to run>

%% View a child model of the controller
% This displays "Cruise Controller model" as a child model of the controller model.
% This is an objective of this demo for implementation and verification. This model also corresponds to a dataflow layer.
%
% <matlab:rundemo_helper('openCtrlChildMdl') Click to run>

%% Running simulation and record model coverage for the top-level model
% Running simulation for system-level model which is Controller + Plant and record model coverage for the whole controller model including the cruise controller model satisfied by test scenario defined in the Signal Builder block on the top.
%
% <matlab:rundemo_helper('runSimMesureCov') Click to run>

%% Test generation for missing coverage objectives by simulations for the cruise controller model
% 100% coverage could not be satisfied by top-level model simulations for given test scenarios. 
% By this demo, SLDV generates test cases reaching only for uncovered coverage objectives.
% This example corresponds to use experimental data or manually created test cases 
% as the first step of model coverage measurement and use SLDV for complementing given test cases.
%
% For running this demo, you need to record model coverage by running simulation for the top-level model.
%
% <matlab:rundemo_helper('getGenCovChild') Click to run>

%%
% The coverage report created by this demo includes three parts: 1) the coverage report for the top-level simulation,
% 2) the coverage report for test cases for the missing objectives, 
% and 3) total coverage report accumulating 1) and 2) that ideally be 100%.

%% Test generation for the cruise controller model as a unit-level test generation
% This example simply generates test cases to achieve 100% model coverage without any given test cases.
%
% <matlab:rundemo_helper('runTestGenerationChild') Click to run>

%%
% There are two usages for automatic test generation as follows:
%
% * *White-box-testing*: To achieve that your test cases obtained by system-level simulations 
% or manual creation satisfy given coverage criteria. 
% If there are missing test cases, you can use automatic test generation to assist creating hitting to corner cases.
%
% * *Black-box-testing*: To verify that two different model parts outputs the same results for the same input time series signals which is called back-to-back testing. 
% The "two different model parts" means, for example, comparing between float- and fixed-point models, MILS and SILS, MILS and PILS.
%
%% 
%% Test generation for the cruise controller model as a unit-level test generation (Fixed-point model)
%  SLDV supports both floating- and fixed-point models.
%
% <matlab:rundemo_helper('runTestGenerationChildFixpt') Click to run>

%% Display requirement specification
% In this example, the requirement specification is written in Excel.
%
% <matlab:rundemo_helper('openReqSpec') Click to run>

%% Reporting requirement traceability report
% Traceability setting has been configured between the requirement document and the model.
% This demo generates requirement traceability report
%
% <matlab:rundemo_helper('makeTraceabilityReport') Click to run>


%% Opening Model Advisor GUI
% Opening model advisor GUI to check complying with modeling guideline standards. 
%
% <matlab:rundemo_helper('openModelAdvisor') Click to run>

%% Automatic execution of MAAB rules in the Model Advisor
%
% <matlab:rundemo_helper('runMAABCheck') Click to run>

%% Open examples of Model Advisor Customization
% Using Model Advisor Customization API, you can create your own Model Advisor Checks.
% You can refer the following examples as a baseline of the customization.
%
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/sl_customization.m') sl_customization.m>: Model Advisor registration 
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/define_ModelAdvisorChecks.m') define_ModelAdvisorChecks.m> : Registration of the contents and callback functions
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_callback.m') mycheck1_callback.m>: The callback for check 1.
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck1_body.m') mycheck1_body.m>: Detection of deviations for check 1.
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_callback.m') mycheck2_callback.m>: The callback for check 2.
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_body.m') mycheck2_body.m>: Detection of deviations for check 2.
% * <matlab:edit('../00_utils/CustomModelAdvisorChecks/mycheck2_action.m') mycheck2_action.m>: Automatic correction for check 2.

%% Property Proving
% The verification formula written in E column in the requirement and verification specification
% can be verified by property proving of Simulink Design Verifier.
% 
%
% * <matlab:rundemo_helper('openPropModelError') Open Property proving model with errors>
% * <matlab:rundemo_helper('runPropProveError') Run Property proving with errors>
% * <matlab:rundemo_helper('openPropModel') Open Property proving model without errors>
% * <matlab:rundemo_helper('runPropProve') Run Property proving without errors>

%%
% These demos are for single data type but fixed-point data type is also supported for property proving.


%% Automatic code generation for the cruise controller model (Floating-point model)
%
% <matlab:rundemo_helper('genCodeGenFloatModel') Click to run>

%% Automatic code generation for the cruise controller model (Fixed-point model)
%
% <matlab:rundemo_helper('genCodeGenFixedModel') Click to run>

%% Automatic Back-to-back testing execution and reporting
%
% <matlab:rundemo_helper('runTestGen_MILSIL_Back2BackReport_Fixed') Click to run>

%% Open Report Explorer
% The contents of automatic report generation can be configured by Report Explorer
%
% <matlab:report Click to run>
