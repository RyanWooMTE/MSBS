function varargout = xlssdoinfo(varargin)
%XLSSDOINFO loads Simulink Data Object property definition from Excel definition file
%
%   PROPDEF = XLSSDOINFO(PACKAGE)
%   returns property definition information of all classes
%   ('Parameter', 'Signal', 'AliasType', 'NumericType',
%    'StructType', 'StructElement', 'Bus', 'BusElement')
%   in the struct PROPDEF loaded from Microsoft Excel spreadsheet
%   the package is specified as PACKAGE.
%
%   PROPDEF = XLSSDOINFO(PACKAGE, CLASSES)
%   returns property definition information in the struct PROPDEF
%   loaded from Microsoft Excel spreadsheet. The package and
%   the classes are specified as CLASSES and PACKAGE.
%
%   This function assumes certain spreadsheet format
%   to load each property definition. The file name
%   of the Excel file should be "<PACKAGE_NAME>.xls".
%   It should be placed on the MATLAB path.
%
%   Input arguments
%   PACKAGE:  Excel file name. You don not need to specify file extension '.xls'.
%             For example, ex. 'mpt'.
%   CLASSES: The list of the class name which you want to get the information.
%
%   Output arguments
%   PROPDEF:       A Struct of property definition information
%
%   Fileds of sturct PROPDEF
%   <CLASS_NAME> : <PRPOERTY_NAME> : Localization  ---> localized string for property name (optional)
%   <CLASS_NAME> : <PRPOERTY_NAME> : SaveProperty  ---> 'Y' write, 'N' do not write (needed)
%   <CLASS_NAME> : <PRPOERTY_NAME> : DefaultValue  ---> If the loaded data from Excel file is empty,
%                                                       set this value (optional)
%
%   <CLASS_NAME>.VariableName  : localized string for variable name (optional)
%   <CLASS_NAME>.SheetName     : localized string for sheet name (optional)
%   <CLASS_NAME>.SheetName1    : localized string for sheet name (optional) For Parameter/Signal
%   <CLASS_NAME>.SheetName2    : localized string for sheet name (optional) For Parameter/Signal
%
%   xlssdoinfo('mpt')
%   xlssdoinfo('mpt', 'Parameter');
%   xlssdoinfo('mpt', {'Parameter'});
%   xlssdoinfo('mpt', {'Parameter', 'Signal'});
%   xlssdoinfo('mpt', 'Parameter');
%   xlssdoinfo('mpt', 'Parameter');
%   xlssdoinfo('mpt', 'Parameter');
%
%   See also XLSREADSDO, XLSWRITESDO

%   History:
%   2008/03/07 beta release(Internally distributed)
%   2008/05/12 Ver. 1.00 release

%   Copyright 2008 CYBERNET SYSTEMS CO.,LTD.
%   This program is not officially supported.
%   This program can be freely customized.
%=============================================================================

    % Process input arguments
    error(nargchk(1, 2, nargin))
    
    propDef = [];
    package = varargin{1};
    cls = {'Parameter', 'Signal', 'AliasType', 'NumericType', 'StructType', 'Bus'};
    
    if ~ischar(package)
      error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Package name must be a string.')
    end
    
    % Add file extension if needed
    defFileName = addExtIfNeeded(package);
    
    % Check validity of file name provided.
    if exist(defFileName, 'file') ~= 2
        error('SDOxlsIF:xlssdoinfo:FileNotFound', 'File %s not found.', defFileName)
    end
    
    if nargin == 2
        cls = varargin{2};
        if ischar(cls)
          cls = {cls};
        end
        if ~iscellstr(cls)
          error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Class name must be a (cell) string.')
        end
        if ~isValidClassName(cls)
            error('SDOxlsIF:xlssdoinfo:UndefinedInput', 'Class name includes an invalid Simulink class name.')
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
    try
        % Open Excel workbook.
        wbk = workbooks.Open(which(defFileName));
    catch
        Excel.Quit;
        delete(Excel);
        error('SDOxlsIF:xlssdoinfo:FileOpen', 'Cannot open Excel file  ''%s''.', defFileName)
    end
    try
        % Read property definition information from a definition file
        propDef = readDEFInfo(wbk, cls);
    catch
        wbk.Close(false);
        Excel.Quit;
        delete(Excel);
        rethrow(lasterror)
    end
    % close workbook without saving any changes.
    wbk.Close(false);
    % quit Excel
    Excel.Quit;
    % delete COM server
    delete(Excel);
    
    varargout{1} = propDef;
    disp(['### Successful completion of loading definition info from ''', defFileName, ''''])
end
% -------------------------------------------------------------------------
