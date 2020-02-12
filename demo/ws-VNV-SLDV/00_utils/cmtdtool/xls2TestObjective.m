function xls2TestObjective(xlsfile, sheet, TableRange)
% xls2VerificationTruthTable Create TruthTable for Verification from Excel
% xlsfile : Name of Excel file
% sheet: SheetName
% TableRange: Selected Excel range of Test Objectives

%   Copyright 2010-2012 The MathWorks, Inc. 

% Read from Excel sheet
[data,text]= xlsread(xlsfile,sheet,TableRange);

% Generate outer subsystem block
sys = utilPreparXLS2TT();

% Generate TruthTable blocks inside sys
[testObjTT,proofObjTT,InputVal,OutValA]=makeTruthTableForTestObjective(text,sys,data);
 
% Compose and place inport blocks with the TT blocks
composeTruthTableBlocks(sys,testObjTT,proofObjTT,InputVal,OutValA);

end

