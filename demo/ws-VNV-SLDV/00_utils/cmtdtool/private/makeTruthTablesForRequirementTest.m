function [testObjTT,proofObjTT,InputVal,OutValA]=makeTruthTablesForRequirementTest(text,sys)
% Define the number of column that means Expected output
%  i.e. text(1,end-Nout:end) : Combination of expected outputs
%       text(1,1:end-Nout-1) : Combination of Inputs

Ncnd = size(text,1)-1;
% initialization
cndmatA = cell(Ncnd,2);
cndmatB = cell(Ncnd,2);
tftblA = cell(Ncnd,Ncnd+1);
tftblB = cell(Ncnd,Ncnd+1);
for n=1:Ncnd
    for m=1:Ncnd+1
        if n==m
            tftblA{n,m} = 'T';
            tftblB{n,m} = 'F';
        else
            tftblA{n,m} = '-';
            tftblB{n,m} = '-';
        end
    end
end


for n=2:size(text,1)
    [cndstr,lhs] = evalImpies(text{n,2});
    cndmatA{n-1,2} = lhs;
    cndmatB{n-1,2} = cndstr;
end

cndmatA = [cndmatA tftblA];
cndmatB = [cndmatB tftblB];
%

Nact = Ncnd+1;
if isJapaneseEnv()
    NoException = '—áŠO';
    Violation = 'ˆá”½';
else
    NoException = 'Exeption';
    Violation = 'Violation';
end
% define an action for Exception
actA{Nact,1} = 'Do nothing';
actB{Nact,1} = NoException;
actA{Nact,2} = '1;';
actB{Nact,2} = 'out=uint32(0);';

% define actions for corresponding conditions
for n=1:Nact-1
    actA{n,1} = text{n+1,1};
    actB{n,1} = [Violation ':' text{n+1,1}];
    actstr = 'sldv.test(1);';
    %     for m=Nexpectedout:-1:1
    %         actstr = [actstr sprintf('%s=%s(%g);',OutVal{m},OutDT{m},data(n,end-m+1))]; %#ok
    %     end
    actA{n,2} = actstr;
    actB{n,2} = sprintf('out=uint32(%d)',n);
end
[InputVarA, ParameterVarA] = getInputAndParameterVariables(cndmatA(:,2));
[InputVarB, ParameterVarB] = getInputAndParameterVariables(cndmatB(:,2));
testObjTT = makeEMLTruthTableName(cndmatA,actA,InputVarA,{},ParameterVarA,{},{},sys);
proofObjTT = makeEMLTruthTableName(cndmatB,actB,InputVarB,{'out'},ParameterVarB,{},{},sys);
InputVal = InputVarA;
OutValA = setdiff(InputVarB,InputVarA);
set_param(testObjTT,'DisableCoverage','on')
set_param(testObjTT,'Name','TestObjectives')
set_param(proofObjTT,'DisableCoverage','on')
set_param(proofObjTT,'Name','Compare_ExpectedOutputs')
end

