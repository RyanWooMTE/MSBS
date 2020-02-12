function readSDOInfo(workbook, package, ws, propDef)
%private function: to read Simulink Data Object information from a file
%   Input arguments
%   WORKBOOK: Workbook object of Excel.
%   PACKAGE: Package which the data is to be loaded to.
%   WS:      Workspace name
%   PROPDEF: A Struct of property definition information
%
%   Output arguments
%   NONE

%   History:
%   2008/03/07 V1.00        Internally distributed

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================
    % get Sheets collection of Excel Aplication
    wk_sheets = workbook.Worksheets;
    for k = 1:wk_sheets.Count
        wk_sheet = wk_sheets.Item(k);
        sheetName = wk_sheet.Name;
        % Activate the sheet
        wk_sheet.Activate;
        className = convertLocalizedSheetName(propDef, sheetName);
        % Do not load the sheet which does not have definition information.
        if isfield(propDef, className) || ...
                strcmp(className, 'ParameterRTWInfo') || ...
                strcmp(className, 'SignalRTWInfo')
            switch className
            %% Each class has its own function. This seems to be redundant,
            %% but may be easy to extend the functionality in the future.
            %%
            %% In case of 'Parameter' and 'Signal', the data can be sometimes
            %% read from two sheets. One sheet is for common properties, and
            %% another sheet is for RTW(Custom) information.
            %% If the second sheet is not found, we read all properties
            %% from one sheet.
                case 'Parameter'
                    readParameter(wk_sheet, package, ws, propDef.Parameter);
                case 'ParameterRTWInfo'
                    % Do not load the sheet 'ParameterRTWInfo' with
                    % no Parameter definition information.
                    if isfield(propDef, 'Parameter')
                        readParameterRTWInfo(wk_sheet, package, ws, propDef.Parameter);
                    end
                case 'Signal'
                    readSignal(wk_sheet, package, ws, propDef.Signal);
                case 'SignalRTWInfo'
                    % Do not load the sheet 'SignalRTWInfo' with
                    % no Signal definition information.
                    if isfield(propDef, 'Signal')
                        readSignalRTWInfo(wk_sheet, package, ws, propDef.Signal);
                    end
                case 'AliasType'
                    readAliasType(wk_sheet, propDef.AliasType);
                case 'NumericType'
                    readNumericType(wk_sheet, propDef.NumericType);
                case 'StructType'
                    readStructType(wk_sheet, propDef.StructType);
                case 'StructElement'
                    readStructElement(wk_sheet, propDef.StructElement);
                case 'Bus'
                    readBus(wk_sheet, propDef.Bus);
                case 'BusElement'
                    readBusElement(wk_sheet, propDef.BusElement);
            end
        else
            % warning('SDOxlsIF:readSDOInfo:UndefinedSheetName', 'Unknown Sheet name for ''%s'': %s', workbook.Name, sheetName)
            disp(['Skipped Sheet name for ''', workbook.Name, ''': ', sheetName, ''''])
        end
    end
end
% -------------------------------------------------------------------------

% sub function for reading PARAMETER object
% -------------------------------------------------------------------------
function data = readParameter(wk_sheet, package, ws, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    indRTWInfotype = false(size(allHeadNames));
    indAllCustomAttrtype = false(size(allHeadNames));
    
    % <<<Properties>>>
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable', 'RTWInfo'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        switch fieldNames{k}
            case {'Dimensions', 'Complexity'}
                % Ignore these properties.
                % We cannot specify these properties.
                % These properties are automatically set by MATLAB.
            otherwise
                indCommontype = indCommontype | indv_Column;
        end
    end
    
    % <<<Properties(RTW Information)>>>
    fieldNames = fieldnames(defInfo.RTWInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.', fieldNames{k}];
            end
        catch
            % Skip the field 'CustomAttributes'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indRTWInfotype = indRTWInfotype | indv_Column;
    end
    
    % <<<Properties(RTW Information(Custom Attributes))>>>
    fieldNames = fieldnames(defInfo.RTWInfo.CustomAttributes);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
            end
        catch
            % Actually, skip no field
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indAllCustomAttrtype = indAllCustomAttrtype | indv_Column;
    end
    
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    % Do not include 'Variable' for RTWInfo
    indRTWInfotype(1) = false;
    % Do not include 'Variable' for RTWInfo.CustomAttributes
    indAllCustomAttrtype(1) = false;
    
    % Sort the column. <Commmon> --> <RTWInfo> --> <RTWInfo.CustomAttributes>
    indv_Tmp = indCommontype;
    data = [data(:, indv_Tmp), data(:, ~indv_Tmp)];
    allHeadNames = [allHeadNames(indv_Tmp), allHeadNames(~indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(indv_Tmp), indRTWInfotype(~indv_Tmp)];
    indAllCustomAttrtype = [indAllCustomAttrtype(indv_Tmp), indAllCustomAttrtype(~indv_Tmp)];
    indCommontype = [indCommontype(indv_Tmp), indCommontype(~indv_Tmp)];
    
    indv_Tmp = indAllCustomAttrtype;
    data = [data(:, ~indv_Tmp), data(:, indv_Tmp)];
    allHeadNames = [allHeadNames(~indv_Tmp), allHeadNames(indv_Tmp)];
    indCommontype = [indCommontype(~indv_Tmp), indCommontype(indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(~indv_Tmp), indRTWInfotype(indv_Tmp)];
    % indAllCustomAttrtype = [indAllCustomAttrtype(~indv_Tmp), indAllCustomAttrtype(indv_Tmp)];
    
    % go through each row
    for row = 2:m
        try
            % create Simulink Data Object as a local variable
            hObj = eval([package, '.Parameter']);
        catch
            warning('SDOxlsIF:readSDOInfo:CreateObject', ...
                'Unable to create %s.Parameter object. Skip the sheet: %s', package, wk_sheet.Name)
            break;
        end
        %%%%%% FIRST, set the common properties with RTWInfo. %%%%%%
        rowData = data(row, indCommontype | indRTWInfotype);
        headNames = allHeadNames(indCommontype | indRTWInfotype);
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Parameter>> / <<Parameter.RTWInfo>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Parameter: ''%s''', propName, package, rowData{1})
                end
            end
        end
        
        %%%%%% SECOND, what porperty does hObj own ? %%%%%%
        indCustomAttrtype = false(size(allHeadNames));
        % Do not include 'Variable' for RTWInfo.CustomAttributes
        indCustomAttrtype(1) = false;
        fieldNames = fieldnames(hObj.RTWInfo.CustomAttributes);
        for k = 1:length(fieldNames)
            try
                % Localization strings of property names
                lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
                end
            catch
                % Skip unnecessary fields for this storage class
                continue;
            end
            indv_Column = strcmp(allHeadNames, lpName);
            % Generate Logical array for filtering the valid columns
            indCustomAttrtype = indCustomAttrtype | indv_Column;
        end
        
        %%%%%% THIRD, set the CustomAttributes %%%%%%
        rowDataCA = data(row, indCustomAttrtype);
        headNames = allHeadNames(indCustomAttrtype);
        for col = 1:length(rowDataCA)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowDataCA{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Parameter>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Parameter: ''%s''', propName, package, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin(ws, rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of %s.Parameter object.', rowData{1}, package)
        end
    end
    disp(['Load Process <', package, '.Parameter> Finished.'])
end
% -------------------------------------------------------------------------

% sub function for setting PARAMETER RTWINFO
% -------------------------------------------------------------------------
function data = readParameterRTWInfo(wk_sheet, package, ws, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indRTWInfotype = false(size(allHeadNames));
    
    % <<<Properties(RTW Information)>>>
    fieldNames = fieldnames(defInfo.RTWInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.', fieldNames{k}];
            end
        catch
            % Skip the field 'CustomAttributes'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indRTWInfotype = indRTWInfotype | indv_Column;
    end
    
    % 'Variable' must be selected by default
    indRTWInfotype(1) = true;
    
    % Sort the column. <RTWInfo> --> <RTWInfo.CustomAttributes>
    indv_Tmp = indRTWInfotype;
    data = [data(:, indv_Tmp), data(:, ~indv_Tmp)];
    allHeadNames = [allHeadNames(indv_Tmp), allHeadNames(~indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(indv_Tmp), indRTWInfotype(~indv_Tmp)];
    
    % go through each row
    for row = 2:m
        %%%%%% FIRST, set the common properties with RTWInfo. %%%%%%
        rowData = data(row, indRTWInfotype);
        headNames = allHeadNames(indRTWInfotype);
        try
            % get Simulink Data Object from specified workspace.
            hObj = evalin(ws, rowData{1});
        catch
            warning('SDOxlsIF:readSDOInfo:TransferObject', ...
                'Unable to transfer %s.Parameter object. Skip the variable: %s', package, rowData{1})
            continue;
        end
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Parameter.RTWInfo>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Parameter: ''%s''', propName, package, rowData{1})
                end
            end
        end
        
        %%%%%% SECOND, what porperty does hObj own ? %%%%%%
        indCustomAttrtype = false(size(allHeadNames));
        % Do not include 'Variable' for RTWInfo.CustomAttributes
        indCustomAttrtype(1) = false;
        fieldNames = fieldnames(hObj.RTWInfo.CustomAttributes);
        for k = 1:length(fieldNames)
            try
                % Localization strings of property names
                lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
                end
            catch
                % Skip unnecessary fields for this storage class
                continue;
            end
            indv_Column = strcmp(allHeadNames, lpName);
            % Generate Logical array for filtering the valid columns
            indCustomAttrtype = indCustomAttrtype | indv_Column;
        end
        
        %%%%%% THIRD, set the CustomAttributes %%%%%%
        rowDataCA = data(row, indCustomAttrtype);
        headNames = allHeadNames(indCustomAttrtype);
        for col = 1:length(rowDataCA)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowDataCA{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Parameter.RTWInfo.CustomAttributes>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Parameter: ''%s''', propName, package, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin(ws, rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of %s.Parameter object.', rowData{1}, package)
        end
    end
    disp(['Load Process <', package, '.Parameter.RTWInfo> Finished.'])
end
% -------------------------------------------------------------------------

% sub function for reading SIGNAL object
% -------------------------------------------------------------------------
function data = readSignal(wk_sheet, package, ws, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    indRTWInfotype = false(size(allHeadNames));
    indAllCustomAttrtype = false(size(allHeadNames));
    
    % <<<Properties>>>
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable', 'RTWInfo'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    
    % <<<Properties(RTW Information)>>>
    fieldNames = fieldnames(defInfo.RTWInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.', fieldNames{k}];
            end
        catch
            % Skip the field 'CustomAttributes'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indRTWInfotype = indRTWInfotype | indv_Column;
    end
    
    % <<<Properties(RTW Information(Custom Attributes))>>>
    fieldNames = fieldnames(defInfo.RTWInfo.CustomAttributes);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
            end
        catch
            % Actually, skip no field
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indAllCustomAttrtype = indAllCustomAttrtype | indv_Column;
    end
    
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    % Do not include 'Variable' for RTWInfo
    indRTWInfotype(1) = false;
    % Do not include 'Variable' for RTWInfo.CustomAttributes
    indAllCustomAttrtype(1) = false;
    
    % Sort the column. <Commmon> --> <RTWInfo> --> <RTWInfo.CustomAttributes>
    indv_Tmp = indCommontype;
    data = [data(:, indv_Tmp), data(:, ~indv_Tmp)];
    allHeadNames = [allHeadNames(indv_Tmp), allHeadNames(~indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(indv_Tmp), indRTWInfotype(~indv_Tmp)];
    indAllCustomAttrtype = [indAllCustomAttrtype(indv_Tmp), indAllCustomAttrtype(~indv_Tmp)];
    indCommontype = [indCommontype(indv_Tmp), indCommontype(~indv_Tmp)];
    
    indv_Tmp = indAllCustomAttrtype;
    data = [data(:, ~indv_Tmp), data(:, indv_Tmp)];
    allHeadNames = [allHeadNames(~indv_Tmp), allHeadNames(indv_Tmp)];
    indCommontype = [indCommontype(~indv_Tmp), indCommontype(indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(~indv_Tmp), indRTWInfotype(indv_Tmp)];
    % indAllCustomAttrtype = [indAllCustomAttrtype(~indv_Tmp), indAllCustomAttrtype(indv_Tmp)];
    
    % go through each row
    for row = 2:m
        try
            % create Simulink Data Object as a local variable
            hObj = eval([package, '.Signal']);
        catch
            warning('SDOxlsIF:readSDOInfo:CreateObject', ...
                'Unable to create %s.Signal object. Skip the sheet: %s', package, wk_sheet.Name)
            break;
        end
        %%%%%% FIRST, set the common properties with RTWInfo. %%%%%%
        rowData = data(row, indCommontype | indRTWInfotype);
        headNames = allHeadNames(indCommontype | indRTWInfotype);
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Signal>> / <<Signal.RTWInfo>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Signal: ''%s''', propName, package, rowData{1})
                end
            end
        end
        
        %%%%%% SECOND, what porperty does hObj own ? %%%%%%
        indCustomAttrtype = false(size(allHeadNames));
        % Do not include 'Variable' for RTWInfo.CustomAttributes
        indCustomAttrtype(1) = false;
        fieldNames = fieldnames(hObj.RTWInfo.CustomAttributes);
        for k = 1:length(fieldNames)
            try
                % Localization strings of property names
                lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
                end
            catch
                % Skip unnecessary fields for this storage class
                continue;
            end
            indv_Column = strcmp(allHeadNames, lpName);
            % Generate Logical array for filtering the valid columns
            indCustomAttrtype = indCustomAttrtype | indv_Column;
        end
        
        %%%%%% THIRD, set the CustomAttributes %%%%%%
        rowDataCA = data(row, indCustomAttrtype);
        headNames = allHeadNames(indCustomAttrtype);
        for col = 1:length(rowDataCA)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowDataCA{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Signal>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Signal: ''%s''', propName, package, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin(ws, rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of %s.Signal object.', rowData{1}, package)
        end
    end
    disp(['Load Process <', package, '.Signal> Finished.'])
end
% -------------------------------------------------------------------------

% sub function for setting SIGNAL RTWINFO
% -------------------------------------------------------------------------
function data = readSignalRTWInfo(wk_sheet, package, ws, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indRTWInfotype = false(size(allHeadNames));
    
    % <<<Properties(RTW Information)>>>
    fieldNames = fieldnames(defInfo.RTWInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.RTWInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = ['RTWInfo.', fieldNames{k}];
            end
        catch
            % Skip the field 'CustomAttributes'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indRTWInfotype = indRTWInfotype | indv_Column;
    end
    
    % 'Variable' must be selected by default
    indRTWInfotype(1) = true;
    
    % Sort the column. <RTWInfo> --> <RTWInfo.CustomAttributes>
    indv_Tmp = indRTWInfotype;
    data = [data(:, indv_Tmp), data(:, ~indv_Tmp)];
    allHeadNames = [allHeadNames(indv_Tmp), allHeadNames(~indv_Tmp)];
    indRTWInfotype = [indRTWInfotype(indv_Tmp), indRTWInfotype(~indv_Tmp)];
    
    % go through each row
    for row = 2:m
        %%%%%% FIRST, set the common properties with RTWInfo. %%%%%%
        rowData = data(row, indRTWInfotype);
        headNames = allHeadNames(indRTWInfotype);
        try
            % get Simulink Data Object from specified workspace.
            hObj = evalin(ws, rowData{1});
        catch
            warning('SDOxlsIF:readSDOInfo:TransferObject', ...
                'Unable to transfer %s.Signal object. Skip the variable: %s', package, rowData{1})
            continue;
        end
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Signal.RTWInfo>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Signal: ''%s''', propName, package, rowData{1})
                end
            end
        end
        
        %%%%%% SECOND, what porperty does hObj own ? %%%%%%
        indCustomAttrtype = false(size(allHeadNames));
        % Do not include 'Variable' for RTWInfo.CustomAttributes
        indCustomAttrtype(1) = false;
        fieldNames = fieldnames(hObj.RTWInfo.CustomAttributes);
        for k = 1:length(fieldNames)
            try
                % Localization strings of property names
                lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
                end
            catch
                % Skip unnecessary fields for this storage class
                continue;
            end
            indv_Column = strcmp(allHeadNames, lpName);
            % Generate Logical array for filtering the valid columns
            indCustomAttrtype = indCustomAttrtype | indv_Column;
        end
        
        %%%%%% THIRD, set the CustomAttributes %%%%%%
        rowDataCA = data(row, indCustomAttrtype);
        headNames = allHeadNames(indCustomAttrtype);
        for col = 1:length(rowDataCA)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowDataCA{col};
            try
                defaultVal = eval(sprintf('defInfo.%s.DefaultValue;', propName));
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<Signal.RTWInfo.CustomAttributes>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for %s.Signal: ''%s''', propName, package, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin(ws, rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of %s.Signal object.', rowData{1}, package)
        end
    end
    disp(['Load Process <', package, '.Signal.RTWInfo> Finished.'])
end
% -------------------------------------------------------------------------

% sub function for reading ALIASTYPE object
% -------------------------------------------------------------------------
function readAliasType(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    
    % go through each row
    for row = 2:m
        % create Simulink Data Object as a local variable
        hObj = Simulink.AliasType;
        % go through each column
        rowData = data(row, indCommontype);
        headNames = allHeadNames(indCommontype);
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<AliasType>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.AliasType object ''%s''', propName, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.AliasType object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.AliasType> Finished.')
end
% -------------------------------------------------------------------------

% sub function for reading NUMERICTYPE object
% -------------------------------------------------------------------------
function readNumericType(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    indFxptUnspecifiedScalingtype = false(size(allHeadNames));
    indFxptBinaryPointScalingtype = false(size(allHeadNames));
    indFxptSlopeBiasScalingtype = false(size(allHeadNames));
    indv_DataTypeMode = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        switch fieldNames{k}
            case 'DataTypeMode'
                indCommontype = indCommontype | indv_Column;
                indFxptUnspecifiedScalingtype = indFxptUnspecifiedScalingtype | indv_Column;
                indFxptBinaryPointScalingtype = indFxptBinaryPointScalingtype | indv_Column;
                indFxptSlopeBiasScalingtype = indFxptSlopeBiasScalingtype | indv_Column;
                indv_DataTypeMode = indv_DataTypeMode | indv_Column;
            case {'IsAlias', 'HeaderFile', 'Description'}
                indCommontype = indCommontype | indv_Column;
                indFxptUnspecifiedScalingtype = indFxptUnspecifiedScalingtype | indv_Column;
                indFxptBinaryPointScalingtype = indFxptBinaryPointScalingtype | indv_Column;
                indFxptSlopeBiasScalingtype = indFxptSlopeBiasScalingtype | indv_Column;
            case {'WordLength', 'Signed'}
                indFxptUnspecifiedScalingtype = indFxptUnspecifiedScalingtype | indv_Column;
                indFxptBinaryPointScalingtype = indFxptBinaryPointScalingtype | indv_Column;
                indFxptSlopeBiasScalingtype = indFxptSlopeBiasScalingtype | indv_Column;
            case 'FractionLength'
                indFxptBinaryPointScalingtype = indFxptBinaryPointScalingtype | indv_Column;
            case {'Slope', 'Bias'}
                indFxptSlopeBiasScalingtype = indFxptSlopeBiasScalingtype | indv_Column;
        end
    end
    
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    indFxptUnspecifiedScalingtype(1) = true;
    indFxptBinaryPointScalingtype(1) = true;
    indFxptSlopeBiasScalingtype(1) = true;
    % Select both 'Variable' and 'DataTypeMode'
    indv_Tmp = indv_DataTypeMode;
    indv_Tmp(1) = true;
    
    % move 'DataMode' column to the the 2nd column.
    % 'Variable' remains the 1st.
    data = [data(:, indv_Tmp), data(:, ~indv_Tmp)];
    allHeadNames = [allHeadNames(indv_Tmp), allHeadNames(~indv_Tmp)];
    indCommontype = [indCommontype(indv_Tmp), indCommontype(~indv_Tmp)];
    indFxptUnspecifiedScalingtype = [indFxptUnspecifiedScalingtype(indv_Tmp), indFxptUnspecifiedScalingtype(~indv_Tmp)];
    indFxptBinaryPointScalingtype = [indFxptBinaryPointScalingtype(indv_Tmp), indFxptBinaryPointScalingtype(~indv_Tmp)];
    indFxptSlopeBiasScalingtype = [indFxptSlopeBiasScalingtype(indv_Tmp), indFxptSlopeBiasScalingtype(~indv_Tmp)];
    
    % go through each row
    for row = 2:m
        % create Simulink Data Object as a local variable
        hObj = Simulink.NumericType;
        if ~isempty(allHeadNames(indv_DataTypeMode))
            dataTypeMode = data{row, 2};
            if isempty(dataTypeMode)
                % If DataTypeMode is not specified, set 'Double'
                dataTypeMode = 'Double';
            end
        else
            % If DataTypeMode column is not found, set 'Double'
            dataTypeMode = 'Double';
        end
        % Selection of the columns depends on the DataTypeMode
        switch dataTypeMode
            case {'Boolean', 'Double', 'Single'}
                rowData = data(row, indCommontype);
                headNames = allHeadNames(indCommontype);
            case {'Fixed-point: unspecified scaling'}
                rowData = data(row, indFxptUnspecifiedScalingtype);
                headNames = allHeadNames(indFxptUnspecifiedScalingtype);
            case {'Fixed-point: binary point scaling'}
                rowData = data(row, indFxptBinaryPointScalingtype);
                headNames = allHeadNames(indFxptBinaryPointScalingtype);
            case {'Fixed-point: slope and bias scaling'}
                rowData = data(row, indFxptSlopeBiasScalingtype);
                headNames = allHeadNames(indFxptSlopeBiasScalingtype);
        end
        % go through each column
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<NumericType>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.NumericType object ''%s''', propName, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.NumericType object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.NumericType> Finished.')
end
% -------------------------------------------------------------------------

% sub function for reading STRUCTTYPE object
% -------------------------------------------------------------------------
function readStructType(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    
    % go through each row
    for row = 2:m
        % create Simulink Data Object as a local variable
        hObj = Simulink.StructType;
        % go through each column
        rowData = data(row, indCommontype);
        headNames = allHeadNames(indCommontype);
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal) && ~strcmp(propName, 'Elements')
                % Ignore 'Elements'.
                % DataType Conversion for <<StructType>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.StructType object ''%s''', propName, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.StructType object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.StructType> Finished.')
end
% -------------------------------------------------------------------------

% sub function for reading STRUCTELEMENT object
% -------------------------------------------------------------------------
function readStructElement(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    
    % go through each row
    for row = 2:m
        % go through each column
        rowData = data(row, indCommontype);
        headNames = allHeadNames(indCommontype);
        try
            % get Simulink.StructType Object from specified workspace.
            hPobj = evalin('base', rowData{1});
        catch
            warning('SDOxlsIF:readSDOInfo:TransferObject', ...
                'Unable to transfer Simulink.StructType object. Skip associating elements for : %s', rowData{1})
            continue;
        end
        if ~strcmp(class(hPobj), 'Simulink.StructType')
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Variable ''%s'' is not Simulink.StructType object.', rowData{1})
        end
        % create Simulink Data Object as a local variable
        hObj = Simulink.StructElement;
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<StructElement>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.StructElement object ''%s''', propName, rowData{1})
                end
            end
        end
        try
            if isempty(hPobj.Elements)
                hPobj.Elements = hObj;
            else
                hPobj.Elements(end + 1) = hObj;
            end
        catch
            warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                'Unable to associate an element with ''%s''', rowData{1})
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hPobj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.StructType object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.StructElement> Finished.')
end
% -------------------------------------------------------------------------

% sub function for reading BUS object
% -------------------------------------------------------------------------
function readBus(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    
    % go through each row
    for row = 2:m
        % create Simulink Data Object as a local variable
        hObj = Simulink.Bus;
        % go through each column
        rowData = data(row, indCommontype);
        headNames = allHeadNames(indCommontype);
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal) && ~strcmp(propName, 'Elements')
                % Ignore 'Elements'.
                % DataType Conversion for <<Bus>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.Bus object ''%s''', propName, rowData{1})
                end
            end
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hObj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.Bus object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.Bus> Finished.')
end
% -------------------------------------------------------------------------

% sub function for reading BUSELEMENT object
% -------------------------------------------------------------------------
function readBusElement(wk_sheet, defInfo)
    datarange = wk_sheet.UsedRange;
    data = getCellValue(datarange);
    [m n] = size(data);
    if m < 1 || n < 1 || isempty(data{1, n}) || isempty(data{m, 1})
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Unknown data found. Skip the sheet: %s', wk_sheet.Name)
        return;
    end
    if isempty(strmatch(data{1,1}, {defInfo.Variable, 'Variable'}, 'exact'))
        warning('SDOxlsIF:readSDOInfo:UnknownData', 'Cell "A1" must be ''Variable'' or ''%s''. Skip the sheet: %s', defInfo.Variable, wk_sheet.Name)
        return;
    end
    
    % 1st row is a header
    allHeadNames = data(1, :);
    
    indCommontype = false(size(allHeadNames));
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Localization strings of property names
            lpName = defInfo.(fieldNames{k}).Localization;
            if isempty(lpName)
                % This property is not localized
                lpName = fieldNames{k};
            end
        catch
            % Skip the field 'SheetName', 'Variable'
            continue;
        end
        indv_Column = strcmp(allHeadNames, lpName);
        % Generate Logical array for filtering the valid columns
        indCommontype = indCommontype | indv_Column;
    end
    % 'Variable' must be selected by default
    indCommontype(1) = true;
    
    % go through each row
    for row = 2:m
        % go through each column
        rowData = data(row, indCommontype);
        headNames = allHeadNames(indCommontype);
        try
            % get Simulink.Bus Object from specified workspace.
            hPobj = evalin('base', rowData{1});
        catch
            warning('SDOxlsIF:readSDOInfo:TransferObject', ...
                'Unable to transfer Simulink.Bus object. Skip associating elements for : %s', rowData{1})
            continue;
        end
        if ~strcmp(class(hPobj), 'Simulink.Bus')
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Variable ''%s'' is not Simulink.Bus object.', rowData{1})
        end
        % create Simulink Data Object as a local variable
        hObj = Simulink.BusElement;
        for col = 2:length(rowData)
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, headNames{col}, '');
            propVal = rowData{col};
            try
                defaultVal = defInfo.(propName).DefaultValue;
            catch
                warning('SDOxlsIF:readSDOInfo:GetDefaultValue', 'Unknown field ''%s''', propName)
                defaultVal = [];
            end
            if isempty(propVal) && ~isempty(defaultVal)
                propVal = defaultVal;
            end
            if ~isempty(propVal)
                % DataType Conversion for <<BusElement>>
                propVal = convertMLDataType(hObj, propName, propVal);
                try
                    eval(sprintf('hObj.%s = propVal;', propName));
                catch
                    warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                        'Unable to set ''%s'' for Simulink.BusElement object ''%s''', propName, rowData{1})
                end
            end
        end
        try
            if isempty(hPobj.Elements)
                hPobj.Elements = hObj;
            else
                hPobj.Elements(end + 1) = hObj;
            end
        catch
            warning('SDOxlsIF:readSDOInfo:SetProperty', ...
                'Unable to associate an element with ''%s''', rowData{1})
        end
        if isvarname(rowData{1})
            % assignin method for either Simulink.ModelWorkspace or Simulink.Workspace
            assignin('base', rowData{1}, hPobj)
        else
            warning('SDOxlsIF:readSDOInfo:InvalidVariable', ...
                'Unable to create variable ''%s'' of Simulink.Bus object.', rowData{1})
        end
    end
    disp('Load Process <Simulink.BusElement> Finished.')
end
% -------------------------------------------------------------------------
