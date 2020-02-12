function xls2TruthTable(xlsfile, sheet, TableRange)
% XLS2TRUTHTABLE create TruthTable block from Excel
% xlsfile : Name of Excel file
% sheet: SheetName
% ConditionTable: Cell region of the condition
% ActionTable: Cell region of the Action
% InputValue: Cell region of input variables
% ActionDescription: Cell region of descriptions for action table

%   Copyright 2010-2011 The MathWorks, Inc. 


[tmp,text]= xlsread(xlsfile,sheet,TableRange);

cndmat = text(2:end,:);


[InputVal, ParameterVal] = getInputAndParameterVariables(text(2:end,2));

OutputVal = {'out'};
Nact = size(text,2)-2;

act{Nact,1} = text{1,Nact+2};
act{Nact,2} = 'out = uint8(0);';
for n=1:Nact-1
    act{n,1} = text{1,n+2};
    act{n,2} = sprintf('out = uint8(%d);',n);
end

makeEMLTruthTableName(cndmat,act,InputVal,OutputVal,ParameterVal);

