%% Generate harness to compare with expected output
% 
% * Supported MATLAB R2009b or later.
% * Requires Simulink(R) Veirification and Validation(TM) and Simulink(R) Design Verifier(TM) for R2009b and R2010a. 
% * Requires Simulink(R) Veirification and Validation(TM) for R2010b or later.

%% Overview
% (1) Select a model to be tested.
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic01.png>>
%
% (2) Click *Harness with expected output* button
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic02.png>>
%
% (3) A harness model will be created and expected outputs and model's outputs are comapred using Assertion block
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic03.png>>
%
% (4) A signal builder block inside the harness model has a dummy inputs.
%
% <<d03_TestHarness/cd050_makeharness_compareresults_pic04.png>>
%

%% How to run
% # Open cmtdtool_samplemode.mdl  in cmtdtool's install directory.
% # Click " Harness with expected output " button in cmtdtool GUI.
% # Check that a new harness model is created.
% # Run the following commands and you will see that the same operation can be done by API call .
open_system('cmtdtool_samplemode')
makeharness_compareresults('cmtdtool_samplemode');
