function ProjectSetup()
% Set-up the environment for this demonstration project.
%   Copyright 2011, 2012 The MathWorks, Inc.


% Use Simulink Project API
p = Simulink.ModelManagement.Project.CurrentProject;
% Get the current project:
projectRoot = getProjectRoot();


%% Add the folders for the model
folders = getFolders();
for jj=1:numel(folders)
    addpath( fullfile(projectRoot, folders{jj}) );
end


%% Set-up for DO178 demonstration
certifname('DO-178C');
modelname('autopilot');

% Note: There is currently only one model per kit so I won't ask for the
% model name.
disp(['Demonstrating DO178 with model:' modelname]);



%% Set the location of slprj to be the "work" folder of the current project:
simCacheFolder = fullfile(projectRoot, 'Work');
codeCacheFolder = fullfile(projectRoot, 'Artefacts', 'Code');
Simulink.fileGenControl('set', 'CacheFolder', simCacheFolder, ...
    'CodeGenFolder', codeCacheFolder);


%% Remove R2012b compatiblity warnings
warning('off', 'Simulink:modelReference:slMdlRefSimNormalInMdlRefSimAccelNotSupported');
warning('off', 'Simulink:Logging:LegacyModelDataLogsFormat');
warning('off', 'Simulink:Engine:SfsModelNameRequired');

addCategory(p,certifname,{'Report','Data'});
addCategory(p,'Type',{'DesignModel','EquivalenceTestingModel','PlantModel','TopModel','ValidationModel'});
addCategory(p,'Review',{'Approved','More Information Required','Rejected','To Review'});

% set locale to English language 
java.util.Locale.setDefault(java.util.Locale.US);



%% Load models data
Plant_data
Roll_Ap_init
slbus_Inertial
slBus_AirData

%% Load models configuration set reference object
assignin('base','configSetObj_autopilot', autopilot_codegen_config);




function addCategory(p,newcategory,newlabels)
%% Setup  Category and Labels
categories = p.getCategories();
if isempty(strcmp(newcategory, categories))
    p.createCategory(newcategory)
end
tmp = p.getLabels(newcategory);
if isempty(tmp)
    labels = {};
else
    [labels{1:length(tmp)}] = tmp.Name;
end

for i = 1:length(newlabels)
    % ModelReview
    if isempty(strcmp(newlabels{i},labels))
        labelObj = Simulink.ModelManagement.Project.Label(newcategory, newlabels{i});
        p.createLabel(labelObj);
    end
end





