function [InputVal, ParameterVal] = getInputAndParameterVariables(text)
% getInputAndParameterVariables  Parse a text and get variable names

%   Copyright 2010-2012 The MathWorks, Inc. 

% TODO: To support Data Objects.

ParameterVal = {};
InputVal = {};
vars = {};

% obtain strings that can be variable name
for n=1:length(text)
    varname = regexp(text{n},'[a-zA-Z][a-zA-Z0-9_]*','match');
    vars = [vars varname]; %#ok
end

% get base workspace variables
bw_vars = evalin('base','who');

% make it unique list
vars = unique(vars);

for n=1:length(vars)
    if any(strcmp(vars{n},{'logical','int8','int16','int32','uint8','uint16','uint32','double','single'}))
        % skip if it is keyword
    elseif any(strcmp(bw_vars, vars{n}))        
        cls = evalin('base',sprintf('class(%s);',vars{n}));
        if ~isempty(regexp(cls,'\.Parameter','once')) ...
                || any(strcmp(cls,{'logical','int8','int16','int32','uint8','uint16','uint32','double','single'}))
        % treat it as a parameter if defined in base workspace
        ParameterVal{end+1} = vars{n}; %#ok
        elseif isvarname(vars{n})
            InputVal{end+1} = vars{n}; %#ok
        end                       
    elseif isvarname(vars{n})
        InputVal{end+1} = vars{n}; %#ok
    end
end

