% A setup script for PropertySpecificationUI

%   Copyright 2012 The MathWorks, Inc. 

% Get a directory path of this file.
path = fileparts(which(mfilename));

% adding the directory to MATLAB PATH.
addpath(path)
% adding to JAVA path.
javaaddpath(fullfile(path,'LiteralEqParser'))

load_system propertySpecificationLib
load_system propertySpecificationOperatorLib

clear path