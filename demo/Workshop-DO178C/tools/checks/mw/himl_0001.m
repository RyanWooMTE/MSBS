%Limitations:
% 1. Do not handle MATLAB Function in Stateflow charts.
function resultDescription = himl_0001(system)

    resultDescription = {};
    deviantElems = {};
    modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
    
    mFcnBlocks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'SFBlockType', 'MATLAB Function');
    for ii=1:numel(mFcnBlocks)
        linkStatus = get_param(mFcnBlocks{ii}, 'LinkStatus');
        if strcmp(linkStatus, 'resolved') || strcmp(linkStatus, 'implicit')
            refBlock = get_param(mFcnBlocks{ii}, 'ReferenceBlock');
            names = strsplit(refBlock, '/');
            load_system(names{1}); % In case the library is not yet loaded.
            refBlockObj = get_param(refBlock, 'Object');
        else
            refBlockObj = get_param(mFcnBlocks{ii}, 'Object');
        end
        mFcn = refBlockObj.find('-isa', 'Stateflow.EMChart');
        err = hasValidFunctionHeader(mFcn);
        if ~isempty(err)
            node.elemHandle = mFcnBlocks{ii}; % Use mFcnBlocks{ii} instead of mFcn so it is always the block in the model (not the block in library).
            node.data = err;
            deviantElems{end+1} = node;
        end
    end
    
    if ~isempty(deviantElems)        
        ft = ModelAdvisor.FormatTemplate('TableTemplate');
        ft.setSubResultStatus('Warn');
        ft.setSubResultStatusText('Found following Matlab Function block(s) with one or more sections missing from Function Header:');
        setColTitles(ft, {'MATLAB Function', 'Missing Function Header Section(s)'});
        for ii=1:numel(deviantElems)
            % Add information to the table
            addRow(ft, {deviantElems{ii}.elemHandle, deviantElems{ii}.data});
        end
        setRecAction(ft, ['Consider adding a standard function header with description of the Function, Inputs and Outputs when using MATLAB functions.',...
                        'The function header should immediately follow the function signature.']);
        resultDescription{end+1} = ft;
    else
        % There are no subsystems or this was a
        % model reference, so the test passed. 
        modelAdvisorObject.setCheckResultStatus(true);
        resultDescription{end+1} = ModelAdvisor.Text('Passed.', {'bold', 'pass'});
    end
end

%% This function checks if a function header has the following format:
% <Function Name> - <Description>
% <Input1> - <Description>
% ...
% <InputN> - <Description>
% <Output1> - <Description>
% ...
% <OutputN> - <Description>
function err = hasValidFunctionHeader(mFcn)
    err = {};
    
    mFcnScript = mFcn.Script;
    mFcnName = extractMFunctionNameFromScript(mFcnScript);
    mFcnHeader = extractMFunctionHeaderFromScript(mFcnScript);
    if isempty(mFcnHeader)
        err = {'Function Description', 'Input Description', 'Output Description'};
        return;
    end
    
    % Check if header has Function Description 
    pattern = cell2mat(strcat('%\s*', mFcnName, '[^%]+'));
    if isempty(regexp(mFcnHeader, pattern, 'match'))
        err{end+1} = 'Function Description';
    end
    
    inputs = mFcn.Inputs;
    for idx=1:numel(inputs)
        inputName = inputs(idx).Name;
        pattern = strcat('%\s*', inputName, '\s+[^%]+');
        start = regexp(mFcnHeader, pattern, 'once');
        if isempty(start)
            err{end+1} = 'Input Description';
            break;
        end
    end
    
    outputs = mFcn.Outputs;
    for idx=1:numel(outputs)
        outputName = outputs(idx).Name;
        pattern = strcat('%\s*', outputName, '\s+[^%]+');
        if isempty(regexp(mFcnHeader, pattern, 'match'))
            err{end+1} = 'Output Description';
            break;
        end
    end
    
end

function out = extractMFunctionNameFromScript(mFcnScript)
    % Get the first line of the function
    match = regexp(mFcnScript, '.*?\n', 'match', 'once');
    if contains(match, '(')
        out = regexp(match, '(\w)+(', 'tokens', 'once');
    else
        % Functions can have no arguments.
        tokens = regexp(match, '(\w)+', 'tokens');
        out = tokens{end};
    end
end

function out = extractMFunctionHeaderFromScript(mFcnScript)
    % Get the first line of the function
    match = regexp(mFcnScript, '.*?\n', 'match', 'once');
    % If the first line ends with '...', the function signature runs over to next lines.
    if contains(match, '...')
        % Find the end of function signature with ')'
        endIdx = regexp(mFcnScript, '.*?)', 'end', 'once');
    else
        endIdx = length(match);
    end
    % Strip the function signature
    mFcnBody = mFcnScript(endIdx+1:end);
    
    % Get the first block of comments
    out = regexp(mFcnBody, '^\n*(%[^\n]*\n)+', 'match', 'once');
    out = strtrim(out);
end