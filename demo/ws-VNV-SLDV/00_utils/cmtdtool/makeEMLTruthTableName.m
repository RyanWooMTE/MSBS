function ttblkh = makeEMLTruthTableName(ConditionTable,ActionTable,InputVar,OutputVar,ParamVar,InputDT,OutputDT,sys)
% makeEMLTruthTableName create TruthTable block
%
% Input:
%  ConditionTable: A cell array of Conditions
%  ActionTable: A cell array of ActionTable
%  InputVar: A cell array of InputVar
%  OutputVar: A cell array of OutputVar
%  ParamVar: A cell array of ParamVar

%   Copyright 2010-2011 The MathWorks, Inc. 

load_system('sflib')
%% Create new model
if ~exist('sys','var')
    new_system();
    mdl = bdroot;
    open_system(mdl); 
else
    if ishandle(sys)
        mdl = getfullname(sys);
    else
        mdl = sys;
    end
end
%% place TruthTable and find its object

ttblkh = add_block('sflib/Truth Table',[mdl '/Truth Table'], 'MakeNameUnique', 'on');
rt = sfroot;
ttobj = rt.find('-isa', 'Stateflow.TruthTableChart', 'Path', getfullname(ttblkh));
for n=1:length(ttobj)
    if strfind(ttobj(n).Path,[bdroot '/'])
        tt = ttobj(n);
    end
end

%% Condition Table
n_row = size(ConditionTable,1)+1;
n_clm = size(ConditionTable,2);
c_tbl = cell(n_row,n_clm);
c_tbl(1:end-1,:) = ConditionTable;

c_tbl(n_row, 1) = {''};
c_tbl(n_row, 2) = {'Actions'};

for jj=1:size(c_tbl,2)-2
    c_tbl(n_row, jj+2) = {num2str(jj)};
end

tt.ConditionTable = c_tbl;

%% Action Table
tt.ActionTable = ActionTable;

%% delete pre-defined variables
dt = ttobj.find('-isa', 'Stateflow.Data','Path',getfullname(ttblkh));
for n=1:length(dt)
    delete(dt(n));
end

%% define input variables
for n=1:length(InputVar)
    dt = Stateflow.Data(tt);
    dt.Name = InputVar{n};
    dt.Scope = 'Input';
    if ~exist('InputDT','var') || isempty(InputDT)
        dt.DataType = 'Inherit: Same as Simulink';
    else
        dt.DataType = InputDT{n};
    end
end
%% define input variables
for n=1:length(OutputVar)
    dt = Stateflow.Data(tt);
    dt.Name = OutputVar{n};
    dt.Scope = 'Output';
    if ~exist('OutputDT','var') || isempty(OutputDT)
        dt.DataType = 'uint32';
    else
        dt.DataType = OutputDT{n};
    end
end

%% define input variables
for n=1:length(ParamVar)
    dt = Stateflow.Data(tt);
    dt.Name = ParamVar{n};
    dt.Scope = 'Parameter';
    dt.DataType = 'Inherit: Same as Simulink';
end
