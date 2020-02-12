function reqs = findWordReqs(filename)
    
    [hWord,hDoc] = reqOpenWordDoc(filename,0);
    reqs = findReqs(hWord,hDoc);
    
end

function [hWord,hDoc] = reqOpenWordDoc(fname,check)
    hWord = []; hDoc = []; 
    p = pwd;
    try
        cd(fullfile(matlabroot,'toolbox','slvnv','reqmgt','private'));
        [hWord,hDoc] = openWordDoc(fname,check);
        cd(p)
    catch 
       % do nothing 
       cd(p)
    end
end


% Opens the document [filename] in Word if needed.
% If [make_visible] is true, Word is brought to the front, showing the
% document. 
% Returns a handle on word, and a handle on the document.
% Raises an exception if the document cannot be opened.
function [hWord, thisDoc] = openWordDoc(filename, check)
    if check
        % We are called from RMI consistency check.
        % Our action depends on weather this is an on-going batch check,
        % or if this is the very first check action that needs MS Word.
        word_state = rmi.mdlAdvState('word');
        if word_state == 0
            hWord = com_word_check_app('init');
        elseif word_state == 1
            hWord = com_word_check_app('get');
        else % word_state == -1
            error(message('Slvnv:reqmgt:linktype_rmi_word:ExternalSessionDetected'));
        end
        make_visible = false;
    else
        hWord = com_word_app;
        make_visible = true;
    end
    
    if ~hWord.visible       % This silly 'if' is required because of the bug in MSWord
        hWord.visible = 1;  % Without it, multiple windows may open
    end
    
    % See if the document is already open
    hDocs = hWord.documents;
    openCount = hDocs.count;
    
    found = 0;
    for i=1:openCount;
        thisDoc = hDocs.Item(i);
        if ~isempty(thisDoc)
            try
                name = thisDoc.FullName;
                if strcmpi(name, filename)
                    found = i;
                    break;
                end
            catch Mex
                % still not found
                warning(message('Slvnv:reqmgt:linktype_rmi_word:CommunicatingError', filename, Mex.identifier));
            end
        end
    end
    
    if found == 0
        try
            thisDoc = hDocs.Open(filename, [], 0);
        catch Mex
            error(message('Slvnv:reqmgt:linktype_rmi_word:DocumentNotFound', filename, Mex.message));
        end
    else
        % Bring window to the front
        if make_visible
            if (strcmpi(hDocs.Parent.WindowState, 'wdWindowStateMinimize'))
                hDocs.Parent.WindowState = 'wdWindowStateNormal';
            end
            hWord.Activate;
            hWord.Documents.Item(found).Activate;
        else
            hDocs.Parent.WindowState = 'wdWindowStateMinimize';
        end        
    end
    removeWordSelection(hWord);
end

% Removes the current selection in Word
function removeWordSelection(hWord)
    if ~isempty(hWord.Selection)
        hWord.Selection.Start = 1;
        hWord.Selection.End = hWord.Selection.Start;
        hWord.Selection.HomeKey;
    end
end

% Finds identifiers in a Word document
function reqs = findReqs(hWord, hDoc, locationStr)
    removeWordSelection(hWord);
    hWord.Selection.Find.Text = 'REQ***';
    hWord.Selection.Find.MatchWildcards = 1;
    
    reqs = {}; 
    if ~hWord.Selection.Find.Execute;
        return 
    end
    item = hWord.Selection.Range.Paragraphs.Item(1);
    while ~isempty(item)
        text = item.Range.Text; 
        if strncmp(text,'REQ',3)
           reqs{end+1} = text(1:6);
        end
        
        item = item.Next;
    end
    
end
