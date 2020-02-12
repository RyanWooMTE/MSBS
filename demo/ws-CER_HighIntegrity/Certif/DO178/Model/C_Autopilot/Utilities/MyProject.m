classdef MyProject < handle
    % MyProject class parse project files labels to filter and perform file
    % specific actions.
    % This class highly depends on the project labels that are defined and how
    % they are attached to files
    
    properties
    end
    
    methods(Static)
        %------------------------------------------------------------------
        function myCat = getCategories()
            p = Simulink.ModelManagement.Project.CurrentProject();            
            myCat = p.getCategories();
            for idx = 1:numel(myCat)
                myCat{2,idx} = {p.getLabels(myCat{1,idx}).Name}';
            end
        end
        
        %------------------------------------------------------------------
        function myLabel = getLabel(category)
            myLabel = {};
            p = Simulink.ModelManagement.Project.CurrentProject();            
            myCat = p.getCategories();
            for idx = 1:numel(myCat)
                if strcmp(category, myCat{idx})
                    myLabel = {p.getLabels(myCat{idx}).Name}';
                end
            end
        end
        %------------------------------------------------------------------
        function  file = getFile(category,label)
            file = {};
            p = Simulink.ModelManagement.Project.CurrentProject();
            prjFile = p.getFilesInProject();
            for idx = 1:numel(prjFile)
                fileLabel = p.getAttachedLabels(prjFile{idx});
                for lidx = 1:numel(fileLabel)
                    if strcmp(category,fileLabel(lidx).CategoryName) && ...
                       ismember(fileLabel(lidx).Name,cellstr(label))
                        file{end+1} = prjFile{idx}; %#ok<AGROW>
                    end
                end
            end
        end
        
    end
end