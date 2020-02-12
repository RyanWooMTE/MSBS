function [impFunc,impCmd,expFunc,expCmd] = getPlugInFunction()

[Path,Name,Ext]=fileparts(which('sldvmisscovtool')); %#ok

% get function list of Plug-in import function
files = dir(fullfile(Path,'import*.m'));
incmd = cell(size(files));
strs = incmd;
impFunc = {};
impCmd = {};
for n=1:length(files)
    cmdname = files(n).name(1:end-2);
    try % Get descriptions of the import function
        str = eval(sprintf('%s(''description'')',cmdname));
        impFunc{end+1} = str;
        impCmd{end+1} = cmdname;
    catch
        ME = lasterror();
        warndlg([cmdname ':' ME.message]);
        % do nothing
    end
end

% get function list of Plug-in export function
files = dir(fullfile(Path,'export*.m'));
excmd = cell(size(files));
strs = excmd;
expFunc = {};
expCmd = {};
for n=1:length(files)
    cmdname = files(n).name(1:end-2);
    try % Get descriptions of the import function
        str = eval(sprintf('%s(''description'')',cmdname));
        expFunc{n} = str;
        expCmd{n} = cmdname;
    catch
        % do nothing
    end
end
