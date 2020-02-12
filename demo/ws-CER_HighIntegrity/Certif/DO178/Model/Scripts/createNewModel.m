function createNewModel( modelName, isComponent )
%CREATEMODEL Summary of this function goes here
%   Detailed explanation goes here

% Check if model already exists in project
p = Simulink.ModelManagement.Project.CurrentProject();
prjFile = MyProject.getFile('File Type',{'Design Model', 'Top Level Design Model'});

for idx = 1:numel(prjFile)
    [~, name] = fileparts(prjFile{idx});
    if strcmp(name,modelName)
        errordlg('Component with identical name already exists');
    end
end

% Create files (component directory, model init file, model file) and apply
% appropriate labels
if isComponent
    modelDir = fullfile(p.getRootDirectory,'Data','Components',sprintf('%s_Cmp',modelName));
else
    modelDir = fullfile(p.getRootDirectory,'Data','System');
end
modelFile = fullfile(modelDir,[modelName, '.mdl']);
mkdir(modelDir);
new_system(modelName);
save_system(modelName,modelFile);


% Apply model standard default configuration

% Add all new files to project
p.addFileToProject(modelDir);
p.addFileToProject(modelFile);
if isComponent
    fileType = 'Design Model';
else
    fileType = 'Top Level Design Model';
end
labelObj = Simulink.ModelManagement.Project.Label('File Type',fileType);
p.attachLabelToFile(modelFile,labelObj);
labelObj = Simulink.ModelManagement.Project.Label('Model Life Cycle Status','Model In Progress');
p.attachLabelToFile(modelDir,labelObj);
% Set current dir to newly create component directory

% Open model
open_system(modelName)
end

