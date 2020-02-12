%% Inspect code for models in the current directory 
% Assumes that the code has been generatd previously by step s6_generateCode.
% Uses the code inspector API To check the equivalence between the code and the model.

bdclose all

ModelList = getModelList();
if isempty(ModelList)
    error('There are no models to inspect');
end

[~,currDir] = fileparts(pwd); 

basecodepath = fullfile(getWorkProducts(),'Code');

%% Generate the code for each Function is that directory.
for idx = 1:length(ModelList)
    [~,mdl] = fileparts(ModelList(idx).name);
    config = slci.Configuration(mdl);
       config.setTopModel(false);
    result = config.inspect;
    fprintf('Model %s status: %s\n',result.ModelName, result.Status);
end
