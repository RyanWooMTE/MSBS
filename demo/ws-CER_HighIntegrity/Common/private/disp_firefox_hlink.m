function [LinkString] = disp_firefox_hlink(StringToDisplay,ObjectToShow)
% Hyperlink display using FireFox

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
    
    if strcmpi(Extension,'.pdf')
        ObjectType = 'PDF_FILE';
        break;
    end
    
    if strcmpi(Extension,'.html')
        ObjectType = 'HTML_FILE';
        break;
    end
    
    ObjectType = 'FILE';
    
end

% ==========================================================================
switch ObjectType
    case 'PDF_FILE'
        LinkString = ['<a href="matlab:system(''firefox',ObjectToShow,''')">',StringToDisplay,'</a>'];

    case 'HTML_FILE'
        LinkString = ['<a href="matlab:system(''firefox ',ObjectToShow,''')">',StringToDisplay,'</a>'];

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
