function [cndstr,lhs,rhs] = evalImpies(str)
% evalImpies finds implies operator from string

%   Copyright 2012 The MathWorks, Inc.

npos = strfind(str,'->');
if isempty(npos)
    cndstr = str;
    return;
elseif length(npos) ~= 1
    error(' Two or more -> (Implies) operators are found. Invalid format!')
end
lhs=str(1:npos-1);
rhs=str(npos+2:end);
cndstr = sprintf('~(%s)||(%s)',lhs,rhs);
end