function addMLBE_OtoPath

% Get the current course folder
rootDir = fileparts(mfilename('fullpath'));

% Populate list of folders to add to path
path2add = {};
path2add{end+1} = rootDir;
path2add{end+1} = fullfile(rootDir,'electricity');
path2add{end+1} = fullfile(rootDir,'epl');
path2add{end+1} = fullfile(rootDir,'gasoline');
path2add{end+1} = fullfile(rootDir,'programming');
path2add{end+1} = fullfile(rootDir,'supplemental','analysis');
path2add{end+1} = fullfile(rootDir,'exercises');
path2add{end+1} = fullfile(rootDir,'exercises','747');
path2add{end+1} = fullfile(rootDir,'exercises','atmosphere');
path2add{end+1} = fullfile(rootDir,'exercises','cassini');
path2add{end+1} = fullfile(rootDir,'exercises','deltav');
path2add{end+1} = fullfile(rootDir,'exercises','escapevelocity');
path2add{end+1} = fullfile(rootDir,'exercises','flight');
path2add{end+1} = fullfile(rootDir,'exercises','hl20');
path2add{end+1} = fullfile(rootDir,'exercises','hurricanes');
path2add{end+1} = fullfile(rootDir,'exercises','satellite');
path2add{end+1} = fullfile(rootDir,'exercises','solarradiation');
path2add{end+1} = fullfile(rootDir,'exercises','stellarspectra');
path2add{end+1} = fullfile(rootDir,'exercises','uav');
path2add{end+1} = fullfile(rootDir,'exercises','wingloading');
path2add{end+1} = fullfile(rootDir,'exercises','wrightflyer');

% Add folders to the path
addpath(path2add{:},'-end');
