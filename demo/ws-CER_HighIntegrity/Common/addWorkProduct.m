function addWorkProduct(filepath,classification,label,op)

persistent FILELIST

switch nargin
    case 0
        op = 'emit';
    case 1
        classification = {};
        label = {};
    case {3,4}
        if nargin == 3
            op = 'cache';
        end
        if ~iscell(classification)
            classification = {classification};
        end
        if ~iscell(label)
            label = {label};
        end
        if length(classification) ~= length(label)
            error('addWorkProduct: arguments CLASSIFICATION and LABEL must be same length cell array or both given as character arrays.')
        end
    otherwise
        error('addWorkProduct: arguments must be FILEPATH and optionally same length CLASSIFICATION and LABEL');
end

switch op
    case 'cache'
%         if isempty(FILELIST)
            FILELIST(end+1).filepath = filepath;
            FILELIST(end).classification = classification;
            FILELIST(end).label = label;
            
%         else
%             FILELIST(end+1) = struct('filepath',filepath,...
%                 'classification',classification,...
%                 'label',label);
%         end
    case 'emit'
        p = Simulink.ModelManagement.Project.CurrentProject();
        projFiles = p.getFilesInProject(false);
        for idx = 1:length(FILELIST)
            filepath = FILELIST(idx).filepath;
            classification = FILELIST(idx).classification;
            label = FILELIST(idx).label;
            try
                if ~any(strcmp(filepath,projFiles))
                    % only add if not there, since this takes time
                    p.addFileToProject(filepath)
                    % add the labels 
                    for i = 1:length(classification)
                        labelObj = Simulink.ModelManagement.Project.Label(classification{i},label{i});
                        p.attachLabelToFile(filepath,labelObj);
                    end
                end
            catch ME
                warning('Could not add %s to Simulink Project\n',filepath,ME.getReport);
            end
        end
        FILELIST = [];
end





