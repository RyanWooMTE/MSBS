%% cmtdtool
 
%% Overview
%
% cmtdtool is an assistant tool for model-based testing in MBD processes.
% Initially, this tool is developed for JMAAB-CMTD-WG 
% (JMAAB: Japan MBD Automotive Advisory Board, CMTD-WG: Control Model Test
% Design Working Group). After several improvements upon feedback from the
% JMAAB-CMTD-WG members, it is published to MATLAB Central.
%
% Test design, composing test model, test execution, and reporting are
% performed when you run tests for a controller model. This tool helps you 
% to reduce and automate manual operations required to perform them.
%
%% (1) Excel to SignalBuilder conversion
%
% * <cd010_xls2SignalBuilder.html Create SignalBuilder block from Excel selection>
% Import, add, and replace time-dependent signals selected region in a
% Excel sheet into SignalBuilder block.
% * <cd015_xls2SignalBuilder_multiple.html Import test vectors in Excel sheet to SignalBuilder block at once> 
% Import multiple time-dependent signals into a Excel sheet to a
% SignalBuilder block at once.
%
%% (2) Excel to Truth Table block conversion
%
% * <cd020_xls2TruthTable.html Generate Truth Table block from Excel>
% Import a truth table represented in an Excel sheet to a Truth Table block. 
% * <cd030_xls2VerificationTruthTable.html Generate TruthTable for assertion verification>
% Import verification equations represented in a Excel sheet to a
% Truth Table block. 
% * <cd035_xls2TestObjective.html User defined test> 
% Generate a block which enables to check relations between inputs and
% expected outputs represented in an Excel sheet.
% * <cd040_xls2RequirementBaseTestTruthTable.html Requirement-based Testing> 
% Generate a Truth Table block which can be used to requirement-based testing.
% If you specify P implies Q in the Excel with given format, this feature
% generates a TruthTable block to generate test cases to achive P condition
% and generate another TruthTable block to throw assersion when P implies Q
% is falsified.
 
%% (3) Test Harness
%
% * <cd040_makeharness.html Generate test harness> Generate a test harness
% model which is composed by SignalBuilder + Data Conversions + Controller
% model from a controller model.
% * <cd050_makeharness_compareresults.html Generate harness to compare with expected output>
% Generate a test harness model to compare outputs from a model with expected
% outputs for given test signals.
 
%% (4) Reporting
%
% * <cd060_runCMTDReport.html Automatic test report generation>
% Run each set of signals in a SignalBuilder block in a test harness model
% and generate test report automatically.
%
% <<description_pic00.PNG>> 
%
 
%% Change Log
%
% * 2010/06/29 Delivered to JMAAB-CMTD-WS (JMAAB Control Model Test Design
% Workshop).
% * 2010/08/04 Bug fixed version had sent to JMAAB-CMTD-WS.
% * 2010/11/02 Ver0.8 had sent to JMAAB-CMTD-WS.
% * 2011/02/14 Ver0.9 had sent to JMAAB-CMTD-WS.
% * 2011/05/27 Ver1.0 has been uploaded to MATLAB Central.
% * 2011/12/28 Ver1.1 has been uploaded to MATLAB Central.
