%%%%%%%%%%%%%%%%%%%% How to use SDOxlsIF %%%%%%%%%%%%%%%%%%%%

% Both the provided commands(xlssdoinfo/xlsreadsdo/xlswritesdo)
% and the definition files(Simulink.xls, mpt.xls, e.t.c)
% that you wish to use should be on the MATLAB path.

% <<Install directory of SDOxlsIF>>            example:C:\foo\SDOxlsIF
% <<Directory which stores definition files>>  example:C:\foo\SDOxlsIF\ENG

% Load data objects as 'Simulink' package from TestFile_JPN.xls
xlsreadsdo('TestFile_ENG.xls', 'Simulink')

% Save 'Simulink' package data objects to TestFile_JPN_Simulink.xls
% CAUTION: An exist file will be overwritten.
xlswritesdo('TestFile_ENG_Simulink.xls', 'Simulink')

% Load data objects as 'mpt' package from TestFile_JPN.xls
xlsreadsdo('TestFile_ENG.xls', 'mpt')

% Save 'mpt' package data objects to TestFile_JPN_mpt.xls
% CAUTION: An exist file will be overwritten.
xlswritesdo('TestFile_ENG_mpt.xls', 'mpt')



%%%%%%%%%%%%%%%%%%%% Working with MAT definition files %%%%%%%%%%%%%%%%%%%%

% Definition information is originally loaded from XLS definition file.
% This information can be loaded to the MATLAB Workspace
% using XLSSDOINFO command.

% Definition information of 'Simulink' package
Simulink = xlssdoinfo('Simulink');
% Definition information of 'mpt' package
mpt = xlssdoinfo('mpt');

% Try to save the returned value from XLSSDOINFO as MAT file format.
% (The variable name must be the package name, and
% the MAT-file name must be the package name.)
% Next, put this file on the MATLAB path, just as
% your original XLS definition file.

% Definition information will be loaded from this MAT definition file
% instead of the original XLS definition file.
% In general, Using MAT definition files enables you to
% run XLSREADSDO and XLSWRITESDO much faster than
% using XLS definition files.

% Create MAT definition file of 'Simulink' package under JPN directory
save('..\ENG\Simulink', 'Simulink')

% Create MAT definition file of 'mpt' package under JPN directory
save('..\ENG\mpt', 'mpt')

% CAUTION: If the file extension is explicitly specified, the definition file of its name is used.
% Use XLS definition file
xlsreadsdo('TestFile_ENG.xls', 'Simulink.xls')
% Use MAT definition file
xlswritesdo('TestFile_ENG_Simulink.xls', 'Simulink.mat')

% You can pass many types of arguments to XLSSDOINFO/XLSREADSDO/XLSWRITESDO.
% Please refer to the document for details.
% Also, please refer to the following template files to know about XLS definition files

% ENG\Simulink.xls (English Template XLS definition file for 'Simulink' package)
% ENG\mpt.xls (English Template XLS definition file for 'mpt' package)
