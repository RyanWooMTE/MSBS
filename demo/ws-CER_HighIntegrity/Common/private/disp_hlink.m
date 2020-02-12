function [LinkString] = disp_hlink(StringToDisplay,ObjectToShow)
% Hyperlink display

if nargin==1
    ObjectToShow = StringToDisplay;
end

if ~ischar(ObjectToShow)
    try
        ObjectToShow = get_param(ObjectToShow,'Name');
    catch
        disp(['ERROR ',mfilename]);
        return;
    end
end

% ==========================================================================
% StringToDisplay carriage return filter

StringToDisplay = strrep(StringToDisplay,char(10),'(CR)');

% ==========================================================================

[~,~,Extension] = fileparts(ObjectToShow);

ObjectType = [];

while isempty(ObjectType)
    
    if strcmpi(Extension,'.mdl')
        ObjectType = 'MDL_FILE';
        break;
    end
    
    if strcmpi(Extension,'.m')
        ObjectType = 'M_FILE';
        break;
    end
    
    if strcmpi(Extension,'.pdf')
        ObjectType = 'PDF_FILE';
        break;
    end
    
    if strcmpi(Extension,'.html')
        ObjectType = 'HTML_FILE';
        break;
    end
    
    if exist(ObjectToShow,'file')==4
        ObjectType = 'MDL_FILE';
        break;
    end
    
    if exist(ObjectToShow,'file')==2
        ObjectType = 'M_FILE';
        break;
    end
    
    try
        get_param(ObjectToShow,'ObjectParameters');
        ObjectType = 'SIMULINK_BLOCK';
        break;
    end
    
    ObjectType = 'FILE';
    
end

% ==========================================================================

switch ObjectType
    case 'MDL_FILE'
        LinkString = ['<a href="matlab:open_system(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
    case 'SIMULINK_BLOCK'
        ObjectToShow = get_param(ObjectToShow,'Parent');
        LinkString = ['<a href="matlab:open_system(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
    case {'M_FILE','FILE'}
        LinkString = ['<a href="matlab:edit(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
    case 'PDF_FILE'
        % LinkString = ['<a href="matlab:system(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        LinkString = ['<a href="matlab:winopen(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
    case 'HTML_FILE'
        LinkString = ['<a href="matlab:web(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        % LinkString = ['<a href="matlab:winopen(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
    otherwise
        % LinkString = '';
        LinkString = ['<a href="matlab:winopen(''',ObjectToShow,''')">',StringToDisplay,'</a>'];
        
end

% ==========================================================================

if ~usejava('jvm')
    LinkString = StringToDisplay;
end

% ==========================================================================

if ~nargout
    fprintf(1,LinkString);
end

% ==========================================================================
% ==========================================================================
