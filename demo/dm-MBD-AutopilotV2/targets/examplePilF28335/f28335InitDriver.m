function f28335InitDriver()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    % Get path information from MATLAB Preferences
    CCSRootDir          = getpref('examplePilF28335','CCSRootDir');
    examplePilF28335Dir = getpref('examplePilF28335','examplePilF28335Dir');
    targetConfigFile    = getpref('examplePilF28335','targetConfigFile');

    % Create strings to call dss
    dss              = fullfile(CCSRootDir,'scripting','bin','dss.bat');
    loadAndRunScript = fullfile(examplePilF28335Dir,'initDriver_CCSv4.js');
    
    successFileName = 'SomeFile.txt';
    
    commandString = sprintf('"%s" ', dss);
    argString = sprintf('"%s" "%s" "%s"', loadAndRunScript, targetConfigFile, successFileName);

    [stat, ret] = system([commandString argString]);
    disp(ret);
    if (stat ~= 0)|| (~isempty(strfind(ret,'SEVERE')))|| (~isempty(strfind(ret,'ERROR')))
        error('examplePILF28335:InitDriver','Error initializing driver');
    end
    
end

