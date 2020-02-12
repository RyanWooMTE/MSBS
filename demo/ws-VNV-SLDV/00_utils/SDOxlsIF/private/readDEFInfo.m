function propDef = readDEFInfo(varargin)
%private function: to read property definition information from a definition file
%   Input arguments
%   WORKBOOK: Workbook object of Excel.
%   CLS: The list of the class name which you want to get the information.
%   WS:  Workspace name
%        (Specified only if this function is called from XLSSDOREAD)
%
%   Output arguments
%   PROPDEF:       A Struct of property definition information

%   History:
%   2008/03/07 V1.00        Internally distributed

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================
    workbook = varargin{1};
    cls = varargin{2};
    switch nargin
        case 2
            % called from XLSSDOINFO
            ws = 'none';
        case 3
            % called from XLSSDOREAD
            ws = varargin{3};
    end
    propDef = struct;
    % get Sheets collection of Excel Aplication
    wk_sheets = workbook.Worksheets;
    % get the package name
    package = workbook.Name;
    package = package(1:end - 4);
    allCls = {'Parameter', 'Signal', 'AliasType', ...
        'NumericType', 'StructType', 'StructElement', 'Bus', 'BusElement'};
    for k = 1:wk_sheets.Count
        wk_sheet = wk_sheets.Item(k);
        sheetName = wk_sheet.Name;
        % Activate the sheet
        wk_sheet.Activate;
        if ~isempty(strmatch(sheetName, cls, 'exact'))
            switch sheetName
                case {'Parameter', 'Signal'}
                    propDef.(sheetName) = getRTWInfoFromSheet(wk_sheet);
                case {'AliasType', 'NumericType', 'StructType', ...
                        'StructElement', 'Bus', 'BusElement'}
                    % Only for the base workspace, and the Simulink package.
                    if strcmp(package, 'Simulink')
                        if ~isa(ws, 'Simulink.ModelWorkspace')
                            propDef.(sheetName) = getInfoFromSheet(wk_sheet);
                        else
                            warning('SDOxlsIF:readDefInfo:WorkSpaceUnknown', ...
                                '%s object can be defined only in the base workspace.', sheetName)
                        end
                    else
                        warning('SDOxlsIF:readDefInfo:PackageUnknown', ...
                            '%s object can be defined only for the Simulink package.', sheetName)
                    end
            end
        else
            if isempty(strmatch(sheetName, allCls, 'exact'))
                warning('SDOxlsIF:readDefInfo:UndefinedSheetName', 'Unknown Sheet name for ''%s'': %s', package, sheetName)
            end
        end
    end
end
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
function data = getInfoFromSheet(wk_sheet)
    data = [];
    % Get Sheet Name
    data.SheetName = getCellValue(wk_sheet, 'B2');
    % Get Variable Name
    data.Variable = getCellValue(wk_sheet, 'B4');
    
    % Get Property Definition
    col = 3;
    while 1
        colLetter = dec2base27(col);
        colData = getCellValue(wk_sheet, [colLetter, '3:', colLetter, '6']);
        % get ALL PROPERTIES. This will be a field name.
        propName = colData{1}; % C3
        if isempty(propName)
            break;
        end
        localization = colData{2}; % C4
        saveProp = colData{3}; % C5
        defaultValue = colData{4}; % C6
        % create a struct for each proerty information
        s = struct('Localization', localization, 'SaveProperty', saveProp,  'DefaultValue', defaultValue);
        if isvarname(propName)
            % The field name is its property name
            data.(propName) = s;
        else
            warning('SDOxlsIF:readDefInfo:InvalidPropertyName', ...
                'Invalid property name skipped: ''%s'' at Sheet ''%s''', propName, wk_sheet.Name)
            col = col + 1;
            continue;
        end
        % go to the next column
        col = col + 1;
    end
    disp(['Loading Definition for [', wk_sheet.Name, '] Finished.'])
end
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
function data = getRTWInfoFromSheet(wk_sheet)
    % This function is for Parameter and Signal information
    data = [];
    % Get Sheet Name
    data.SheetName1 = getCellValue(wk_sheet, 'B2');
    % Get Variable Name
    data.Variable = getCellValue(wk_sheet, 'B4');
    % Get Sheet Name for RTW Information
    data.SheetName2 = getCellValue(wk_sheet, 'B8');
    
    % Get Property Definition
    col = 3;
    while 1
        colLetter = dec2base27(col);
        colData = getCellValue(wk_sheet, [colLetter, '3:', colLetter, '6']);
        % get ALL PROPERTIES. This will be a field name.
        propName = colData{1}; % C3
        if isempty(propName)
            break;
        end
        localization = colData{2}; % C4
        saveProp = colData{3}; % C5
        defaultValue = colData{4}; % C6
        % create a struct for each proerty information
        s = struct('Localization', localization, 'SaveProperty', saveProp,  'DefaultValue', defaultValue);
        if isvarname(propName)
            % The field name is its property name
            data.(propName) = s;
        else
            warning('SDOxlsIF:readDefInfo:InvalidPropertyName', ...
                'Invalid property name skipped: ''%s'' at Sheet ''%s''', propName, wk_sheet.Name)
            col = col + 1;
            continue;
        end
        % go to the next column
        col = col + 1;
    end
    
    % Get Property Definition(RTW Information)
    data.RTWInfo.CustomAttributes = [];
    col = 2;
    while 1
        colLetter = dec2base27(col);
        colData = getCellValue(wk_sheet, [colLetter, '9:', colLetter, '12']);
        % get ALL PROPERTIES. This will be a field name.
        propName = colData{1}; % B9
        if isempty(propName)
            break;
        end
        localization = colData{2}; % B10
        saveProp = colData{3}; % B11
        defaultValue = colData{4}; % B12
        % create a struct for each proerty information
        s = struct('Localization', localization, 'SaveProperty', saveProp,  'DefaultValue', defaultValue);
        if isvarname(propName)
            switch propName
                case {'StorageClass', 'CustomStorageClass', 'Alias'}
                    % The field name is its property name
                    data.RTWInfo.(propName) = s;
                otherwise
                    % The field name is its property name
                    data.RTWInfo.CustomAttributes.(propName) = s;
            end
        else
            warning('SDOxlsIF:readDefInfo:InvalidPropertyName', ...
                'Invalid property name skipped: ''%s'' at Sheet ''%s''', propName, wk_sheet.Name)
            col = col + 1;
            continue;
        end
        
        % go to the next column
        col = col + 1;
    end
    disp(['Loading Definition for [', wk_sheet.Name, '] Finished.'])
end
% -------------------------------------------------------------------------
