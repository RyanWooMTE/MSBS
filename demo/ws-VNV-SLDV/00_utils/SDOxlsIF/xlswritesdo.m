function xlswritesdo(varargin)
%XLSWRITESDO saves Simulink Data Object to Excel spreadsheet
%
%   This function saves data objects from workspace to Microsoft Excel spreadsheet.
%   To fetch each property definition, the Excel file named "<PACKAGE>.xls"
%   or "<PACKAGE>.mat" should be placed on the MATLAB path.
%
%   XLSWRITESDO(FILENAME, PACKAGE)
%   saves data objects to FILENAME using the property definition
%   PACKAGE. All types of data objects('Parameter', 'Signal', 'AliasType',
%   'NumericType', 'StructType', 'StructElement', 'Bus', 'BusElement') are
%   saved. The data is saved to the base workspace implicitly.
%
%   XLSWRITESDO(FILENAME, PACKAGE, CLASSES)
%   saves data objects of the type CLASSES to FILENAME using the property definition
%   PACKAGE. The data is saved to the base workspace implicitly.
%
%   XLSWRITESDO(FILENAME, PACKAGE, CLASSES, WS)
%   saves data objects of the type CLASSES to FILENAME using the property definition
%   PACKAGE. The data is saved to the workspace specified as WS. Specify []
%   for CLASSES if you want to save all types of data objects.
%
%   XLSWRITESDO('-DIVIDE', ...)
%   saves data objects to separate sheets. One sheet is for common properties,
%   and another sheet is for RTW(Custom) information. This option is available
%   only for Parameter/Signal objects.
%
%   Input arguments
%   FILENAME: Excel file name. File extension is '.xls'
%   PACKAGE:  Package name of Simulink Data Object. Package name is case sensitive.
%   CLASSES: The list of the class name which you want to set the information.
%   WS   :    Workspace to save the data objects. WS can be 'base' or
%             Simulink.ModelWorkspace object. To load to the model workspace,
%             specify the model name.
%
%   xlswritesdo('savefile.xls', 'mpt')
%   xlswritesdo('savefile.xls', 'mpt', 'Parameter')
%   xlswritesdo('savefile.xls', 'mpt', {'Parameter'})
%   xlswritesdo('savefile.xls', 'mpt', {'Parameter', 'Signal'})
%   xlswritesdo('savefile.xls', 'mpt', [], 'mymodel')
%   xlswritesdo('savefile.xls', 'mpt', {'Parameter', 'Signal'}, 'mymodel')
%
%   See also XLSSDOINFO, XLSREADSDO

%   History:
%   2008/03/07 beta release(Internally distributed)
%   2008/05/12 Ver. 1.00 release

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================

    % Process input arguments
    error(nargchk(2, 5, nargin))
    
    divideFlag = false;
    str = varargin{1};
    
    if ~ischar(str)
      error('SDOxlsIF:xlswritesdo:UndefinedInput', 'First argument must be a string.')
    end
    
    if strcmp(upper(str), '-DIVIDE')
        if nargin < 3
            error('SDOxlsIF:xlswritesdo:UndefinedInput', 'Not enough input arguments.')
        else
            % '-DIVIDE' option is specified
            divideFlag = true;
            fileName = varargin{2};
            package = varargin{3};
        end
    else
        fileName = str; % = varargin{1}
        package = varargin{2};
    end
    
    if ~ischar(package)
      error('SDOxlsIF:xlswritesdo:UndefinedInput', 'Second argument must be a string.')
    end
    
    % Check validity of file name provided.
    ext = getFileExt(package);
    switch ext
        case {'xls', 'mat'}
            if exist(package, 'file') == 2
                defFileName = package;
            else
                error('SDOxlsIF:xlswritesdo:FileNotFound', 'Definition File ''%s'' not found.', package)
            end
        otherwise
            % no file extension found
            if exist([package, '.mat'], 'file') == 2
                ext = 'mat';
                defFileName = [package, '.mat'];
            elseif exist([package, '.xls'], 'file') == 2
                ext = 'xls';
                defFileName = [package, '.xls'];
            else
                error('SDOxlsIF:xlswritesdo:FileNotFound', 'Definition File for ''%s'' not found.', package)
            end
    end
    
    % handle requested Excel workbook filename.
    if ~isempty(fileName)
        if ~ischar(fileName)
            error('SDOxlsIF:xlswritesdo:InputClass','Filename must be a string.');
        end
        % check for wildcards in filename
        if any(findstr('*', fileName))
            error('SDOxlsIF:xlswritesdo:FileName', 'Filename must not contain ''*''.');
        end
        % get file parts
        [Directory, fileName, sfileExt] = fileparts(fileName);
        % Add file extension if needed
        fileName = addExtIfNeeded(fileName);
        fileFullName = abspath(fullfile(Directory, fileName));
        [success, msg, msgid] = fileattrib(fileFullName);
        if success && ~(msg.UserWrite == 1)
            error('SDOxlsIF:xlswritesdo:FileReadOnly', 'File can not be read only.')
        end
    else % get workbook filename.
        error('SDOxlsIF:xlswritesdo:FileNotFound', 'Filename is empty.')
    end
    
    cls = {'Parameter', 'Signal', 'AliasType', 'NumericType', 'StructType', 'Bus'};
    ws = 'base';
    
    if divideFlag && nargin > 3
        % '-DIVIDE' option is specified
        value = varargin{4};
        if ~isempty(value)
            cls = value;
            if ischar(cls)
                cls = {cls};
            end
            if ~iscellstr(cls)
              error('SDOxlsIF:xlssdoread:UndefinedInput', 'Class name must be a (cell) string.')
            end
            if ~isValidClassName(cls)
                error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Class name includes an invalid Simulink class name.')
            end
        end
        if nargin == 5
            value = varargin{5};
            if ~ischar(value) || isempty(value)
                error('SDOxlsIF:xlssdoread:UndefinedInput', 'Workspace name must be a string.')
            end
            ws = value;
%             if ~strcmp(ws, 'base')
                % try to load the model
                % load_system(ws)
                % Simulink.ModelWorkspace
                pval = get_param(ws, 'ModelWorkspace');
                if isempty(pval)
                    error('SDOxlsIF:xlssdoread:ModelWorkSpaceAccess', 'Cannot access to the model workspace %s.', ws)
                else
                    ws = pval;
                end
%             end
        end
    elseif ~divideFlag && nargin > 2
        % '-DIVIDE' option is not specified
        value = varargin{3};
        if ~isempty(value)
            cls = value;
            if ischar(cls)
                cls = {cls};
            end
            if ~iscellstr(cls)
              error('SDOxlsIF:xlssdoread:UndefinedInput', 'Class name must be a (cell) string.')
            end
            if ~isValidClassName(cls)
                error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Class name includes an invalid Simulink class name.')
            end
        end
        if nargin == 4
            value = varargin{4};
            if ~ischar(value) || isempty(value)
                error('SDOxlsIF:xlssdoread:UndefinedInput', 'Workspace name must be a string.')
            end
            ws = value;
%             if ~strcmp(ws, 'base')
                % try to load the model
                % load_system(ws)
                % Simulink.ModelWorkspace
                pval = get_param(ws, 'ModelWorkspace');
                if isempty(pval)
                    error('SDOxlsIF:xlssdoread:ModelWorkSpaceAccess', 'Cannot access to the model workspace %s.', ws)
                else
                    ws = pval;
                end
%             end
        end
    end
    % Select element information for StructType
    if ~isempty(strmatch('StructType', cls, 'exact'))
        cls{end + 1} = 'StructElement';
    end
    % Select element information for Bus
    if ~isempty(strmatch('Bus', cls, 'exact'))
        cls{end + 1} = 'BusElement';
    end
    
    % Attempt to start Excel as ActiveX server
    Excel = startExcel;
    workbooks = Excel.workbooks;
    switch ext
        case 'xls' %%%%% from XLS file
            disp('### Loading Definition from XLS file')
            try
                % Open Excel workbook(Definition File).
                wbk1 = workbooks.Open(which(defFileName));
            catch
                Excel.Quit;
                delete(Excel);
                error('SDOxlsIF:xlssdoread:FileOpen', 'Cannot open Excel file  ''%s''.', defFileName)
            end
            try
                % Read property definition information from a definition file
                propDef = readDEFInfo(wbk1, cls, ws);
            catch
                wbk1.Close(false);
                Excel.Quit;
                delete(Excel);
                rethrow(lasterror)
            end
            % close the workbook without saving any changes.
            wbk1.Close(false);
        case 'mat' %%%%% from MAT file
            disp('### Loading Definition from MAT file')
            try
                % Read property definition information from a definition file
                varName = defFileName(1:end - 4);
                load(which(defFileName))
                if exist(varName, 'var') == 1
                    propDef = eval(varName);
                    fieldNames = fieldnames(propDef);
                    removeSet = setxor(fieldNames, cls);
                    removeSet = intersect(removeSet, fieldNames);
                    % remove unnecessary class information
                    propDef = rmfield(propDef, removeSet);
                else
                    error('SDOxlsIF:xlswritesdo:MATFileRead', 'Failed to load Variable ''%s'' from MAT-file ''%s''.', varName, defFileName)
                end
            catch
                Excel.Quit;
                delete(Excel);
                rethrow(lasterror)
            end
    end
    
    try
        % Check validity of file name provided.
        if exist(fileFullName, 'file') ~= 2
            disp(['### Create ''', fileName, ''''])
            wbk2 = workbooks.Add;
            % This workbook contains 'Sheet1'/'Sheet2'/'Sheet3'.
            % These sheets will be deleted after.
            wbk2.SaveAs(fileFullName, 1);
            wbk2.Close(false);
        else
            disp(['### Overwrite ''', fileName, ''''])
        end
        % Open Excel workbook(Save File).
        wbk2 = workbooks.Open(fileFullName);
    catch
        Excel.Quit;
        delete(Excel);
        error('SDOxlsIF:xlssdoread:FileOpen', 'Cannot open Excel file  ''%s''.', fileFullName)
    end
    try
        % walk through sheets in workbook.
        package = defFileName(1:end - 4);
        writeSDOInfo(wbk2, package, ws, propDef, divideFlag);
        % save and close the workbook.
        wbk2.Close(true, fileFullName);
    catch
        wbk2.Close(false);
        Excel.Quit;
        delete(Excel);
        rethrow(lasterror)
    end
    % quit Excel
    Excel.Quit;
    % delete COM server
    delete(Excel);
    disp(['### Successful completion of saving Simuink data object info to ''', fileName, ''''])
end
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
function absolutepath = abspath(partialpath)
    % parse partial path into path parts
    [pathname, filename, sfileExt] = fileparts(partialpath);
    % no path qualification is present in partial path; assume parent is pwd, except
    % when path string starts with '~' or is identical to '~'.
    if isempty(pathname) && isempty(strmatch('~', partialpath))
        Directory = pwd;
    elseif isempty(regexp(partialpath, '(.:|\\\\)')) && ...
            isempty(strmatch('/', partialpath)) && ...
            isempty(strmatch('~', partialpath));
        % path did not start with any of drive name, UNC path or '~'.
        Directory = [pwd, filesep, pathname];
    else
        % path content present in partial path; assume relative to current directory,
        % or absolute.
        Directory = pathname;
    end
    
    % construct absulute filename
    absolutepath = fullfile(Directory,[filename, sfileExt]);
end
% -------------------------------------------------------------------------
