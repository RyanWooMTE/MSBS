function xls2VerificationTruthTable(xlsfile, sheet, TableRange)
% xls2VerificationTruthTable  Create TruthTable for Verification from Excel
% xlsfile : Name of Excel file
% sheet: SheetName
% TableRange: Selected Excel range of Verification Table

%   Copyright 2010-2011 The MathWorks, Inc. 

[tmp,text]= xlsread(xlsfile,sheet,TableRange);

cndmat = text(2:end,:);
Ncnd = size(text,1)-1;
tftbl = cell(Ncnd,Ncnd+1);
for n=1:Ncnd
    for m=1:Ncnd+1
        if n==m
            tftbl{n,m} = 'F';
        else
            tftbl{n,m} = '-';
        end
    end
end
cndmat = [cndmat tftbl];
for n=1:Ncnd
    cndmat{n,2} = evalImpies(cndmat{n,2});
end

[InputVal, ParameterVal] = getInputAndParameterVariables(text(2:end,2));

OutputVal = {'out'};
Nact = Ncnd+1;
if isJapaneseEnv()
    NoException = '—áŠO‚È‚µ';
    Violation = '[ˆá”½] ';
else
    NoException = 'No exception found';
    Violation = '[Violation] ';
end

act{Nact,1} = NoException;

act{Nact,2} = 'out = uint32(0);';
for n=1:Nact-1
    act{n,1} = [Violation text{n+1,1}];
    act{n,2} = sprintf('out = uint32(%d);',n);
end

makeEMLTruthTableName(cndmat,act,InputVal,OutputVal,ParameterVal);

function cndstr = evalImpies(str)
npos = findstr(str,'->');
if isempty(npos)
    cndstr = str;
    return;
elseif length(npos) ~= 1
    error(' Two or more -> (Implies) operators are found. Invalid format!')
end
A=str(1:npos-1);
B=str(npos+2:end);
cndstr = sprintf('~(%s)||(%s)', A,B);
