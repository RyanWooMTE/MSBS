function [stat,ModelName] = loadModel(isViewModel)

[ModelFileName, pathname] =uigetfile('*.mdl');
fullModelName = fullfile(pathname,ModelFileName);
if ModelFileName==0 | exist(fullModelName,'file')~=4 %#ok
    stat = false;
    ModelName = [];
    return;
end

ModelName = ModelFileName(1:end-4); % eliminate the extension ".mdl"

try
    if isViewModel
        open_system(fullModelName)
    else
        load_system(fullModelName)
    end
    stat = true;
catch %#ok
    stat = false;
end