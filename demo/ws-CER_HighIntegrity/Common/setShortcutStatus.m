function setShortcutStatus(file, enabled)
% setShortcutStatus
% This function takes a file in the project and sets its shortcut status.
%
% Usage:
% 
%     setShortcutStatus(file, enabled)
%
% Where: 
%
%     file - string - the project file whose shortcut status is to be set.
%     enabled - logical - true if setting as a shortcut, false if clearing
%                         the files shortcut status.

% Copyright 2012 The MathWorks, Inc.

import com.mathworks.toolbox.slproject.project.container.SingletonProjectContainer;
import com.mathworks.toolbox.slproject.project.entrypoint.EntryPointType;

projectContainer =SingletonProjectContainer.getInstance();

project = projectContainer.getProjectManager();
projectRoot = getProjectRoot;

if isempty(project)
    error('A project must be loaded to use this function')
end

jFile = iresolveFileFromString(projectRoot, file);
type = EntryPointType.BASIC;

if enabled
    project.setEntryPoint(jFile, type);
else
    project.removeEntryPoint(jFile);
end

end

function jFile = iresolveFileFromString(projectRoot, file)

fileResolved = which (file,'file');
if ~isempty(fileResolved)
    file = fileResolved;
end

if ~exist(file,'file')
    file = fullfile(projectRoot,file);
    if ~exist(file,'file')
        error('The file %s does not exist.', file);
    end
end

jFile = java.io.File(file);

end