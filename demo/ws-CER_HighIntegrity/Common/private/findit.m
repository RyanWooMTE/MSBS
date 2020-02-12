function modellist = findit(category, label, subpath)
found = 0;
modellist = [];

% Get the list of all files in project
p = Simulink.ModelManagement.Project.CurrentProject();
p.getFilesInProject(false);
l = p.getFilesInProject(false);

% If a path has been supplied, filter now
if nargin == 3
    l = l(strmatch(lower(subpath), lower(l)));
end

% Search in the list for files with matching category and label
for i = 1:length(l)
    filename = l{i};
    labels = p.getAttachedLabels(filename);
    for j=1:length(labels)
        if(strcmp(labels(j).CategoryName, category) && strcmp(labels(j).Name, label))
            found = found + 1;
            modellist{found} = filename;
        end
    end
end
end
