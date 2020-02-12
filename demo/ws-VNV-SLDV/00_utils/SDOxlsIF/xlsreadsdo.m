function xlsreadsdo(varargin)
%XLSREADSDO loads Simulink Data Object from Excel spreadsheet
%
%   This function loads data objects from Microsoft Excel spreadsheet
%   to workspace. To fetch each property definition, the Excel file
%   named "<PACKAGE>.xls" or "<PACKAGE>.mat" should be placed on the MATLAB path.
%
%   XLSREADSDO(FILENAME, PACKAGE)
%   loads data objects from FILENAME using the property definition
%   PACKAGE. All types of data objects('Parameter', 'Signal', 'AliasType',
%   'NumericType', 'StructType', 'StructElement', 'Bus', 'BusElement') are
%   loaded. The data is loaded to the base workspace implicitly.
%
%   XLSREADSDO(FILENAME, PACKAGE, CLASSES)
%   loads data objects of the type CLASSES in FILENAME using the property definition
%   PACKAGE. The data is loaded to the base workspace.
%
%   XLSREADSDO(FILENAME, PACKAGE, CLASSES, WS)
%   loads data objects of the type CLASSES in FILENAME using the property definition
%   PACKAGE. The data is loaded to the workspace specified as WS. Specify []
%   for CLASSES if you want to load all types of data objects.
%
%   Input arguments
%   FILENAME: Excel file name. File extension is '.xls'
%   PACKAGE:  Package name of Simulink Data Object. Package name is case sensitive.
%   CLASSES: The list of the class name which you want to set the information.
%   WS   :    a workspace to load the data objects. WS can be 'base' or
%             Simulink.ModelWorkspace object. To load to the model workspace,
%             specify the model name.
%
%   xlsreadsdo('readfile.xls', 'mpt')
%   xlsreadsdo('readfile.xls', 'mpt', 'Parameter')
%   xlsreadsdo('readfile.xls', 'mpt', {'Parameter'})
%   xlsreadsdo('readfile.xls', 'mpt', {'Parameter', 'Signal'})
%   xlsreadsdo('readfile.xls', 'mpt', [], 'mymodel')
%   xlsreadsdo('readfile.xls', 'mpt', {'Parameter', 'Signal'}, 'mymodel')
%
%   See also XLSSDOINFO, XLSWRITESDO

%   History:
%   2008/03/07 beta release(Internally distributed)
%   2008/05/12 Ver. 1.00 release

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================

    % Process input arguments
    error(nargchk(2, 4, nargin))
    
    fileName = varargin{1};
    package = varargin{2};
    
    if ~ischar(fileName)
      error('SDOxlsIF:xlsreadsdo:UndefinedInput', 'First argument must be a string.')
    end
    
    if ~ischar(package)
      error('SDOxlsIF:xlsreadsdo:UndefinedInput', 'Second argument must be a string.')
    end
    
    % Add file extension if needed
    fileName = addExtIfNeeded(fileName);
    
    % Check validity of file name provided.
    ext = getFileExt(package);
    switch ext
        case {'xls', 'mat'}
            if exist(package, 'file') == 2
                defFileName = package;
            else
                error('SDOxlsIF:xlsreadsdo:FileNotFound', 'Definition File ''%s'' not found.', package)
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
                error('SDOxlsIF:xlsreadsdo:FileNotFound', 'Definition File for ''%s'' not found.', package)
            end
    end
    
    % Check validity of file name provided.
    if exist(fileName, 'file') ~= 2
        error('SDOxlsIF:xlsreadsdo:FileNotFound', 'File ''%s'' not found.', fileName)
    end
    
    cls = {'Parameter', 'Signal', 'AliasType', 'NumericType', 'StructType', 'Bus'};
    ws = 'base';
    
    if nargin > 2
        value = varargin{3};
        if ~isempty(value)
            cls = value;
            if ischar(cls)
                cls = {cls};
            end
            if ~iscellstr(cls)
              error('SDOxlsIF:xlsreadsdo:UndefinedInput', 'Class name must be a (cell) string.')
            end
            if ~isValidClassName(cls)
                error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Class name includes an invalid Simulink class name.')
            end
        end
        if nargin == 4
            value = varargin{4};
            if ~ischar(value) || isempty(value)
                error('SDOxlsIF:xlsreadsdo:UndefinedInput', 'Workspace name must be a string.')
            end
            ws = value;
%             if ~strcmp(ws, 'base')
                % try to load the model
                % load_system(ws)
                % Simulink.ModelWorkspace
                pval = get_param(ws, 'ModelWorkspace');
                if isempty(pval)
                    error('SDOxlsIF:xlsreadsdo:ModelWorkSpaceAccess', 'Cannot access to the model workspace %s.', ws)
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
                error('SDOxlsIF:xlsreadsdo:FileOpen', 'Cannot open Excel file  ''%s''.', defFileName)
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
                    error('SDOxlsIF:xlsreadsdo:MATFileRead', 'Failed to load Variable ''%s'' from MAT-file ''%s''.', varName, defFileName)
                end
            catch
                Excel.Quit;
                delete(Excel);
                rethrow(lasterror)
            end
    end
    
    try
        % Open Excel workbook(Load File).
        wbk2 = workbooks.Open(which(fileName));
    catch
        Excel.Quit;
        delete(Excel);
        error('SDOxlsIF:xlsreadsdo:FileOpen', 'Cannot open Excel file  ''%s''.', fileName)
    end
    try
        % walk through sheets in workbook.
        package = defFileName(1:end - 4);
        readSDOInfo(wbk2, package, ws, propDef);
    catch
        wbk2.Close(false);
        Excel.Quit;
        delete(Excel);
        rethrow(lasterror)
    end
    % close the workbook without saving any changes.
    wbk2.Close(false);
    % quit Excel
    Excel.Quit;
    % delete COM server
    delete(Excel);
    disp(['### Successful completion of loading Simuink data object info from ''', fileName, ''''])
end
% -------------------------------------------------------------------------
