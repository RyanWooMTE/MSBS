function [bhA,bhB,InputVal,OutValA]=makeTruthTableForTestObjective(text,sys,data)
% Define the number of column that means Expected output
%  i.e. text(1,end-Nout:end) : Combination of expected outputs
%       text(1,1:end-Nout-1) : Combination of Inputs

Nexpectedout = parseNexpectedout(text(2,:));
Ninputs = size(text,2)-1-Nexpectedout;
Ncnd = size(text,1)-3;
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

for n=1:Ninputs
    InputVal{n} = text{1,n+1};
    InputDT{n} =text{3,n+1};
end

for n=Nexpectedout:-1:1
    OutValA{n} = text{1,end-n+1};
    OutDTA{n} = text{3,end-n+1};
end
OutValB{1}='out';
OutDTB{1} = 'uint32';

for n=1:Ncnd
    cndmatA{n,1} = text{n+3,1}; % the test case name
    cndmatB{n,1} = text{n+3,1}; % the test case name
    if strcmp(InputDT{1},'boolean')
        dType = 'logical';
    else
        dType = InputDT{1};
    end
    cndstr = sprintf('%s==%s(%g) ',InputVal{1},dType,data(n,1));
    for m=2:Ninputs
        if strcmp(InputDT{m},'boolean')
            dType = 'logical';
        else
            dType = InputDT{m};
        end
        cndstr = [cndstr sprintf('&& %s==%s(%g) ',InputVal{m},dType,data(n,m))]; %#ok
    end
    cndmatA{n,2} = cndstr;
    actstr = '';
    for m=Nexpectedout:-1:1
        actstr = [actstr sprintf('abs(%s-%s(%g))<=%g',OutValA{m},OutDTA{m},data(n,end-m+1),0)]; %#ok
        if m~=1
            actstr = [actstr '&&'];
        end
    end
    cndmatB{n,2} = sprintf('~(%s)||(%s)',cndstr,actstr);
end

cndmatA = [cndmatA tftblA];
cndmatB = [cndmatB tftblB];
%

Nact = Ncnd+1;
if isJapaneseEnv()
    NoException = 'ˆá”½–³';
    Violation = 'ˆá”½';
else
    NoException = 'No Exeption';
    Violation = 'Violation';
end
% define an action for Exception
actA{Nact,1} = 'Do nothing';
actB{Nact,1} = NoException;
actA{Nact,2} = '1;';
actB{Nact,2} = 'out=uint32(0);';

% define actions for corresponding conditions
for n=1:Nact-1
    actA{n,1} = text{n+3,1};
    actB{n,1} = [Violation ':' text{n+3,1}];
    actstr = 'sldv.test(1);';
%     for m=Nexpectedout:-1:1
%         actstr = [actstr sprintf('%s=%s(%g);',OutVal{m},OutDT{m},data(n,end-m+1))]; %#ok
%     end
    actA{n,2} = actstr;
    actB{n,2} = sprintf('out=uint16(%d)',n);
end
ParameterVal={};
bhA = makeEMLTruthTableName(cndmatA,actA,InputVal          ,{}     ,ParameterVal,InputDT         ,{}    ,sys);
bhB = makeEMLTruthTableName(cndmatB,actB,[InputVal,OutValA],OutValB,ParameterVal,[InputDT,OutDTA],OutDTB,sys);

set_param(bhA,'DisableCoverage','on')
set_param(bhA,'Name','TestObjectives')
set_param(bhB,'DisableCoverage','on')
set_param(bhB,'Name','Compare_ExpectedOutputs')
end
function Nexpectedout = parseNexpectedout(str)
[tmp,Ncol]=size(str);
Ninputs = 0;
Nexpectedout = 0;
for n=2:Ncol
    if ~isempty(regexp(str{n},'^u\d+$','match','once'))
        Ninputs = Ninputs+1;
    elseif ~isempty(regexp(str{n},'^e\d+$','match','once'))
        Nexpectedout = Nexpectedout+1;
    else
        error('Unexpected character: "%s" has been found. The character must be one of following: u, e.',str{n})
    end
end
end
