function writeSDOInfo(workbook, package, ws, propDef, divideFlag)
%private function: to read Simulink Data Object information from a file
%   Input arguments
%   WORKBOOK: Workbook object of Excel.
%   PACKAGE: Package which the data is to be loaded to.
%   WS:      Workspace name
%   PROPDEF: A Struct of property definition information
%   DIVIDEFLAG: A flag which indicates whether we write Parameter/Signal information to two sheets or not
%
%   Output arguments
%   NONE

%   History:
%   2008/03/07 V1.00        Internally distributed

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================
    wbData = struct;
    fieldNames = fieldnames(propDef);
    
    % Write headers for all object types
    for k = 1:length(fieldNames)
        wbData.(fieldNames{k}) = writeHeader(propDef.(fieldNames{k}));
        switch fieldNames{k}
            case {'Parameter', 'Signal'}
                wbData.([fieldNames{k}, 'RTWInfo']) = writeRTWInfoHeader(propDef.(fieldNames{k}));
        end
    end
    
    % Loop through variables to find objects in specified workspace
    vars = evalin(ws, 'whos');
    for k = 1:length(vars)
        % get class name from the variable if its package name matched
        className = sscanf(vars(k).class, [package, '.%s']);
        % Do not save the sheet which does not have definition information.
        if isfield(propDef, className)
            switch className
                 case 'Parameter'
                     wbData.Parameter = writeParameter(vars(k).name, package, ws, wbData.Parameter, propDef.Parameter);
                     wbData.ParameterRTWInfo = writeParameterRTWInfo(vars(k).name, package, ws, wbData.ParameterRTWInfo, propDef.Parameter);
                 case 'Signal'
                     wbData.Signal = writeSignal(vars(k).name, package, ws, wbData.Signal, propDef.Signal);
                     wbData.SignalRTWInfo = writeSignalRTWInfo(vars(k).name, package, ws, wbData.SignalRTWInfo, propDef.Signal);
                 case 'AliasType'
                     wbData.AliasType = writeAliasType(vars(k).name, package, ws, wbData.AliasType, propDef.AliasType);
                 case 'NumericType'
                     wbData.NumericType = writeNumericType(vars(k).name, package, ws, wbData.NumericType, propDef.NumericType);
                 case 'StructType'
                     wbData.StructType = writeStructType(vars(k).name, package, ws, wbData.StructType, propDef.StructType);
                     % write element information for this variable
                     wbData.StructElement = writeStructElement(vars(k).name, package, ws, wbData.StructElement, propDef.StructElement);
                 case 'Bus'
                     wbData.Bus = writeBus(vars(k).name, package, ws, wbData.Bus, propDef.Bus);
                     % write element information for this variable
                     wbData.BusElement = writeBusElement(vars(k).name, package, ws, wbData.BusElement, propDef.BusElement);
                otherwise
                    % Ignore 'StructElement' and 'BusElement'. Because these elements
                    % are accessed by 'Elements' property of 'StructType' and 'Bus'.
                    disp(['Ignore Variable ''', vars(k).name, ''''])
            end
        end
    end
    
    % Throw away Line 2 to Line 5 from NumericType sheet Information
    if isfield(wbData, 'NumericType')
        [m, n] = size(wbData.NumericType);
        if m > 4
            data = wbData.NumericType;
            wbData.NumericType = [data(1, :); data(6:end, :)];
        end
    end
    
    % Add RTWInfo sheet or not
    if ~divideFlag
        fieldNames = fieldnames(wbData);
        for k = 1:length(fieldNames)
            switch fieldNames{k}
                case {'Parameter', 'Signal'}
                    rightData = wbData.(fieldNames{k});
                    leftData = wbData.([fieldNames{k}, 'RTWInfo']);
                    wbData.(fieldNames{k}) = [rightData, leftData(:, 2:end)];
                    % Remove the fields for RTWInfo
                    wbData = rmfield(wbData, [fieldNames{k}, 'RTWInfo']);
            end
        end
    end
    
    % Find the sheet to write data. If no sheet is found, add a new sheet.
    fieldNames = fieldnames(wbData);
    for k = 1:length(fieldNames)
        wk_sheet = findSheet(workbook, fieldNames{k}, propDef);
        writeSheet(wk_sheet, wbData.(fieldNames{k}));
    end
    % Clean up unknown sheets.
    cleanSheet(workbook);
end
% -------------------------------------------------------------------------

% sub function for writing sheet
% -------------------------------------------------------------------------
function writeSheet(wk_sheet, sheetInfo)
    [m, n] = size(sheetInfo);
    % Calculate full target range, in Excel A1 notation,
    % to include array of size m x n
    all_range = ['A1:', dec2base27(n), num2str(m)];
    % Select range in worksheet.
    Rall_range = wk_sheet.Range(all_range);
    %Rall_range.Select;
    % cell array for large data
    largeData = cell(m, n);
    % Flag to indicate Bulk Save writing
    blkFlag = false;
    % Flag to indicate Individual Save writing
    indFlag = false;
    loopIdx = 0;
    while loopIdx < m * n + 1
        loopIdx = loopIdx + 1;
        try
            Rall_range.Value = sheetInfo;
            blkFlag = true;
            break;
        catch
            for row = 1:m
                for col = 1:n
                    data = sheetInfo{row, col};
                    if length(data) > 1000
                        sheetInfo{row, col} = '';
                        largeData{row, col} = data;
                        indFlag = true;
                        continue;
                    end
                end
            end
        end
    end
    if blkFlag
        disp(['Bulk Save Process Finished. Sheet: <', wk_sheet.Name, '>'])
    else
        warning('SDOxlsIF:writeSDOInfo:BulkSaveFailed', 'Bulk Save Failed. Sheet: <%s>.', wk_sheet.Name)
    end
    if indFlag
        % Large data was found. Write each large data individually
        for row = 1:m
            for col = 1:n
                data = largeData{row, col};
                if ~isempty(data)
                    colLetter = dec2base27(col);
                    rowLetter = num2str(row);
                    % range = [colLetter, rowLetter, ':', colLetter, rowLetter];
                    range = [colLetter, rowLetter];
                    Rrange = wk_sheet.Range(range);
                    Rrange.Activate;
                    try
                        Rrange.Value = {data};
                        disp(['Individual Save Process Finished. Sheet: <', wk_sheet.Name, '>. Address: [', range, '].'])
                    catch
                        warning('SDOxlsIF:writeSDOInfo:WriteLargeDataFailed', ...
                            'Failed to write large data. Sheet: <%s>. Address: [%s].', wk_sheet.Name, range)
                    end
                end
            end
        end
    end
    % Styling sheet
    Rall_range.Borders.LineStyle = 1;          % XlLineStyle.xlContinuous
    Rall_range.Columns.AutoFit;                % Auto Fitting
    for k = 1:n
        Reach_range = wk_sheet.Range([dec2base27(k), '1']);
        if Reach_range.ColumnWidth > 50
            Reach_range.ColumnWidth = 50;      % Max Column Width = 50
        end
    end
end
% -------------------------------------------------------------------------

% sub function for finding sheet
% -------------------------------------------------------------------------
function wk_sheet = findSheet(workbook, thisClassName, propDef)
    % get Sheets collection of Excel Aplication
    wk_sheets = workbook.Worksheets;
    for k = 1:wk_sheets.Count
        wk_sheet = wk_sheets.Item(k);
        sheetName = wk_sheet.Name;
        className = convertLocalizedSheetName(propDef, sheetName);
        switch className
            case thisClassName
            % Activate the sheet
            wk_sheet.Activate;
            return;
        end
    end
    % Add new sheet and activate
    lastsheet = wk_sheets.Item(wk_sheets.Count);
    wk_sheet = wk_sheets.Add([], lastsheet);
    switch thisClassName
        case {'Parameter', 'Signal'}
            sheetName = propDef.(thisClassName).SheetName1;
        case {'ParameterRTWInfo', 'SignalRTWInfo'}
            sheetName = propDef.(thisClassName(1:end - 7)).SheetName2;
        case {'AliasType', 'NumericType', 'StructType', ...
                'StructElement', 'Bus', 'BusElement'}
            sheetName = propDef.(thisClassName).SheetName;
    end
    if isempty(sheetName)
        wk_sheet.Name = thisClassName;
    else
        wk_sheet.Name = sheetName;
    end
end
% -------------------------------------------------------------------------

% sub function for cleaning sheet
% -------------------------------------------------------------------------
function cleanSheet(workbook)
    wk_sheets = workbook.Worksheets;
    for k = 3:-1:1
        try
            wk_sheet = wk_sheets.Item(['Sheet', num2str(k)]);
            usedrange = wk_sheet.UsedRange;
            if isnan(usedrange.Value)
                % We do not use Sheet1/Sheet2/Sheet3 provided by default.
                % Delete these sheets if they are empty.
                wk_sheet.Delete;
            end
        catch
            continue;
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing PARAMETER object
% -------------------------------------------------------------------------
function sheetInfo = writeParameter(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.Parameter object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        try
            propVal = eval(sprintf('hObj.%s', propName));
        catch
            warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                'Unable to get ''%s'' for %s.Parameter: ''%s''', propName, package, varName)
            continue;
        end
        % set values for each property
        sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
    end
end
% -------------------------------------------------------------------------

% sub function for writing PARAMETERRTWINFO object
% -------------------------------------------------------------------------
function sheetInfo = writeParameterRTWInfo(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.Parameter object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    
    % 1st row is a header
    allHeadNames = sheetInfo(1, :);
    
    %%%%%% FIRST, be sure which column is for RTWInfo %%%%%%
    % <<<Properties(RTW Information)>>>
    indRTWInfotype = false(size(allHeadNames));
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
    
    %%%%%% SECOND, what porperty does hObj own ? %%%%%%
    % <<<Properties(RTW Information(Custom Attributes))>>>
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
    
    %%%%%% THIRD, be sure which column is for RTWInfo / RTWInfo.CustomAttributes %%%%%%
    indRTWInfoCustomtype = indRTWInfotype | indCustomAttrtype;
    
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        if indRTWInfoCustomtype(col)
            try
                propVal = eval(sprintf('hObj.%s', propName));
            catch
                warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                    'Unable to get ''%s'' for %s.Parameter: ''%s''', propName, package, varName)
                continue;
            end
            % set values for each property
            sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing SIGNAL object
% -------------------------------------------------------------------------
function sheetInfo = writeSignal(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.Signal object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        try
            propVal = eval(sprintf('hObj.%s', propName));
        catch
            warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                'Unable to get ''%s'' for %s.Signal: ''%s''', propName, package, varName)
            continue;
        end
        % set values for each property
        sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
    end
end
% -------------------------------------------------------------------------

% sub function for writing SIGNALRTWINFO object
% -------------------------------------------------------------------------
function sheetInfo = writeSignalRTWInfo(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.Signal object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    
    % 1st row is a header
    allHeadNames = sheetInfo(1, :);
    
    %%%%%% FIRST, be sure which column is for RTWInfo %%%%%%
    % <<<Properties(RTW Information)>>>
    indRTWInfotype = false(size(allHeadNames));
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
    
    %%%%%% SECOND, what porperty does hObj own ? %%%%%%
    % <<<Properties(RTW Information(Custom Attributes))>>>
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
    
    %%%%%% THIRD, be sure which column is for RTWInfo / RTWInfo.CustomAttributes %%%%%%
    indRTWInfoCustomtype = indRTWInfotype | indCustomAttrtype;
    
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        if indRTWInfoCustomtype(col)
            try
                propVal = eval(sprintf('hObj.%s', propName));
            catch
                warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                    'Unable to get ''%s'' for %s.Signal: ''%s''', propName, package, varName)
                continue;
            end
            % set values for each property
            sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing ALIASTYPE object
% -------------------------------------------------------------------------
function sheetInfo = writeAliasType(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.AliasType object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        try
            propVal = eval(sprintf('hObj.%s', propName));
        catch
            warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                'Unable to get ''%s'' for %s.AliasType: ''%s''', propName, package, varName)
            continue;
        end
        % set values for each property
        sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
    end
end
% -------------------------------------------------------------------------

% sub function for writing NUMERICTYPE object
% -------------------------------------------------------------------------
function sheetInfo = writeNumericType(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.NumericType object. Skip the variable: %s', package, varName)
        return;
    end
    
    dataTypeMode = hObj.DataTypeMode;
    
    [rowSize, colSize] = size(sheetInfo);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Logical arrays are generated only for the first call
    if rowSize < 2
        % 1st row is a header
        allHeadNames = sheetInfo(1, :);

        indCommontype = false(size(allHeadNames));
        indFxptUnspecifiedScalingtype = false(size(allHeadNames));
        indFxptBinaryPointScalingtype = false(size(allHeadNames));
        indFxptSlopeBiasScalingtype = false(size(allHeadNames));
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
        % Line 2 ---> Logical array
        sheetInfo(2, :) = num2cell(indCommontype);
        % Line 3 ---> Logical array
        sheetInfo(3, :) = num2cell(indFxptUnspecifiedScalingtype);
        % Line 4 ---> Logical array
        sheetInfo(4, :) = num2cell(indFxptBinaryPointScalingtype);
        % Line 5 ---> Logical array
        sheetInfo(5, :) = num2cell(indFxptSlopeBiasScalingtype);
        rowSize = 5;
    end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        needWrite = false;
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        switch dataTypeMode
            case {'Boolean', 'Double', 'Single'}
                if sheetInfo{2, col}
                    needWrite = true;
                end
            case {'Fixed-point: unspecified scaling'}
                if sheetInfo{3, col}
                    needWrite = true;
                end
            case {'Fixed-point: binary point scaling'}
                if sheetInfo{4, col}
                    needWrite = true;
                end
            case {'Fixed-point: slope and bias scaling'}
                if sheetInfo{5, col}
                    needWrite = true;
                end
        end
        if needWrite
            try
                propVal = eval(sprintf('hObj.%s', propName));
            catch
                warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                    'Unable to get ''%s'' for %s.NumericType: ''%s''', propName, package, varName)
                continue;
            end
            % set values for each property
            sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing STRUCTTYPE object
% -------------------------------------------------------------------------
function sheetInfo = writeStructType(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.StructType object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        try
            propVal = eval(sprintf('hObj.%s', propName));
        catch
            warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                'Unable to get ''%s'' for %s.StructType: ''%s''', propName, package, varName)
            continue;
        end
        % set values for each property
        sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
    end
end
% -------------------------------------------------------------------------

% sub function for writing STRUCTELEMENT object
% -------------------------------------------------------------------------
function sheetInfo = writeStructElement(varName, package, ws, sheetInfo, defInfo)
    try
        % get value of 'Elements' property of this Simulink Data Object from specified workspace.
        elemsVal = evalin(ws, sprintf('%s.Elements', varName));
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.StructElement object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    for k = 1:length(elemsVal)
        % get StructElement object
        hObj = elemsVal(k);
        % 1st column is variable name
        sheetInfo{end + 1, 1} = varName;
        for col = 2:colSize
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
            try
                propVal = eval(sprintf('hObj.%s', propName));
            catch
                warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                    'Unable to get ''%s'' for %s.StructElement: ''%s''', propName, package, varName)
                continue;
            end
            % set values for each property
            sheetInfo{rowSize + k, col} = convertXLSDataType(hObj, propName, propVal);
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing BUS object
% -------------------------------------------------------------------------
function sheetInfo = writeBus(varName, package, ws, sheetInfo, defInfo)
    try
        % get Simulink Data Object from specified workspace.
        hObj = evalin(ws, varName);
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.Bus object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    % 1st column is variable name
    sheetInfo{end + 1, 1} = varName;
    for col = 2:colSize
        % convert a local string to a property name
        propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
        try
            propVal = eval(sprintf('hObj.%s', propName));
        catch
            warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                'Unable to get ''%s'' for %s.Bus: ''%s''', propName, package, varName)
            continue;
        end
        % set values for each property
        sheetInfo{rowSize + 1, col} = convertXLSDataType(hObj, propName, propVal);
    end
end
% -------------------------------------------------------------------------

% sub function for writing BUSELEMENT object
% -------------------------------------------------------------------------
function sheetInfo = writeBusElement(varName, package, ws, sheetInfo, defInfo)
    try
        % get value of 'Elements' property of this Simulink Data Object from specified workspace.
        elemsVal = evalin(ws, sprintf('%s.Elements', varName));
    catch
        warning('SDOxlsIF:writeSDOInfo:TransferObject', ...
            'Unable to transfer %s.BusElement object. Skip the variable: %s', package, varName)
        return;
    end
    
    [rowSize, colSize] = size(sheetInfo);
    for k = 1:length(elemsVal)
        % get StructElement object
        hObj = elemsVal(k);
        % 1st column is variable name
        sheetInfo{end + 1, 1} = varName;
        for col = 2:colSize
            % convert a local string to a property name
            propName = convertLocalizedPropName(defInfo, sheetInfo{1, col}, '');
            try
                propVal = eval(sprintf('hObj.%s', propName));
            catch
                warning('SDOxlsIF:writeSDOInfo:GetProperty', ...
                    'Unable to get ''%s'' for %s.BusElement: ''%s''', propName, package, varName)
                continue;
            end
            % set values for each property
            sheetInfo{rowSize + k, col} = convertXLSDataType(hObj, propName, propVal);
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing only HEADERS
% -------------------------------------------------------------------------
function data = writeHeader(defInfo)
    data = cell(0);
    % for Cell "A1"
    lVName = defInfo.Variable;
    if isempty(lVName)
        data{1, 1} = 'Variable';
    else
        data{1, 1} = lVName;
    end
    % <<<Properties>>>
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        try
            % Check the Save flag
            if strcmp(defInfo.(fieldNames{k}).SaveProperty, 'Y')
                % Localization strings of property names
                lpName = defInfo.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % Skip the field 'SheetName', 'Variable'
                    lpName = fieldNames{k};
                end
                data{1, end + 1} = lpName;
            end
        catch
            % Skip this property
            continue;
        end
    end
end
% -------------------------------------------------------------------------

% sub function for writing only HEADERS(RTWINFO)
% -------------------------------------------------------------------------
function data = writeRTWInfoHeader(defInfo)
    data = cell(0);
    % for Cell "A1"
    lVName = defInfo.Variable;
    if isempty(lVName)
        data{1, 1} = 'Variable';
    else
        data{1, 1} = lVName;
    end
    % <<<Properties(RTW Information)>>>
    fieldNames = fieldnames(defInfo.RTWInfo);
    for k = 1:length(fieldNames)
        try
            % Check the Save flag
            if strcmp(defInfo.RTWInfo.(fieldNames{k}).SaveProperty, 'Y')
                % Localization strings of property names
                lpName = defInfo.RTWInfo.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.', fieldNames{k}];
                end
                data{1, end + 1} = lpName;
            end
        catch
            % Skip this property
            continue;
        end
    end
    % <<<Properties(RTW Information(Custom Attributes))>>>
    fieldNames = fieldnames(defInfo.RTWInfo.CustomAttributes);
    for k = 1:length(fieldNames)
        try
            % Check the Save flag
            if strcmp(defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).SaveProperty, 'Y')
                % Localization strings of property names
                lpName = defInfo.RTWInfo.CustomAttributes.(fieldNames{k}).Localization;
                if isempty(lpName)
                    % This property is not localized
                    lpName = ['RTWInfo.CustomAttributes.', fieldNames{k}];
                end
                data{1, end + 1} = lpName;
            end
        catch
            % Skip this property
            continue;
        end
    end
end
% -------------------------------------------------------------------------
