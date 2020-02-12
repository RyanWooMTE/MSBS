function set_up_project()
%set_up_project  Configure the environment for this project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

%   Copyright 2011-2014 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
project = simulinkproject;
projectRoot = project.RootFolder;

% Set the location of slprj to be the "work" folder of the current project:
myCacheFolder = fullfile(projectRoot, 'work');
if ~exist(myCacheFolder, 'dir')
    mkdir(myCacheFolder)
end
Simulink.fileGenControl('set', 'CacheFolder', myCacheFolder, ...
   'CodeGenFolder', myCacheFolder);

% Set the path for this project:
folders = project_paths;
for jj=1:numel(folders)
    addpath( genpath(fullfile(projectRoot, folders{jj})) );
end
% Copy all test files to the "work" folder:
copyfile(fullfile(projectRoot, 'models'), myCacheFolder);
copyfile(fullfile(projectRoot, 'documents'), myCacheFolder);
% Change working folder to the "work" folder:
cd(myCacheFolder);
% Set the path for this project:
folders = project_paths;
for jj=1:numel(folders)
    addpath( genpath(fullfile(projectRoot, folders{jj})) );
end

end

