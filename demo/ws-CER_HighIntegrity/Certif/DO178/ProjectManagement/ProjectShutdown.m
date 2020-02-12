function ProjectShutdown()
% Clean up the environment for the current project. This function should
% undo the settings applied in "set_up_project". It should be set to Run at
% Shutdown.

% hello!
%   Copyright 2011, 2012 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
p = Simulink.ModelManagement.Project.CurrentProject;

% Get the current project:
projectRoot = getProjectRoot();


% Remove paths added for this project. Get the single definition of the
% folders to add to the path:
folders = getFolders;

% Remove these from the MATLAB path:
for jj=1:numel(folders)
    rmpath( fullfile(projectRoot, folders{jj}) );
end

% Reset the location of slprj.
Simulink.fileGenControl('reset');


