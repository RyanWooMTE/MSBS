function sys = xls2RequirementBaseTestTruthTable(xlsfile, sheet, TableRange)
% xls2RequirementBaseTestTruthTable  Create TruthTable for Verification from Excel
% xlsfile : Name of Excel file
% sheet: SheetName
% TableRange: Selected Excel range of Verification Table

%   Copyright 2010-2012 The MathWorks, Inc.

% Read from Excel sheet
[~,text]= xlsread(xlsfile,sheet,TableRange);

% Generate outer subsystem block
sys = utilPreparXLS2TT();

% Generate TruthTable blocks inside sys
[testObjTT,proofObjTT,InputVal,OutValA]=makeTruthTablesForRequirementTest(text,sys);

% Compose and place inport blocks with the TT blocks
composeTruthTableBlocks(sys,testObjTT,proofObjTT,InputVal,OutValA);

 
end
