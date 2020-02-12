function [ ] = f28335BeforeMakeHook( modelName )
% F28335BEFOREMAKEHOOK Generates makefile to specify paths for examplePilF28335
%   This hook file is registered in the sl_customization.m file for
%   the example PIL implementation: examplePilF28335. 
%   It generates a target_paths.mk makefile which specifies variables 
%   for paths to the Code Composer Studio v4 installation directory and for 
%   the files which make up the PIL implementation

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Copyright 2011 MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Check the model if a target_paths.mk should be created
if (strcmp(get_param(modelName,'SystemTargetFile')  ,'ert.tlc') && ...
    strcmp(get_param(modelName,'TemplateMakefile')  ,'ec_target.tmf') && ...
    strcmp(get_param(modelName,'TargetHWDeviceType'),'Texas Instruments->C2000'))

    % Only initiate replacement for f28335 PIL target
    disp(['Executing ' mfilename ' for ' modelName]);
    
    % Warn if internal states will not be initialized
    if strcmp(get_param(modelName,'ZeroInternalMemoryAtStartup'),'off')
        warning('EXAMPLEPIL:internalDataNotInitialized', ...
            ['The optimization for "Remove internal data zero initialization" is enabled. '...
             'This many result in unexpected outputs since states are not reset between PIL simulation runs. '...
             'It is recommended to disable this optimization for PIL testing.']);
    end
    
    % Get paths from MATLAB preferences
    examplePilF28335Dir = getpref('examplePilF28335','examplePilF28335Dir');
    CCSRootDir          = getpref('examplePilF28335','CCSRootDir');
    TI_F28xxx_SysSWDir  = getpref('examplePilF28335','TI_F28xxx_SysSWDir');
%     C28xFPUfastRTSDir   = getpref('examplePilF28335','C28xFPUfastRTSDir');
    
    % Transform to short path names
    CCSRootDir          = RTW.transformPaths(CCSRootDir,'pathType','alternate');
    examplePilF28335Dir = RTW.transformPaths(examplePilF28335Dir,'pathType','alternate');
    TI_F28xxx_SysSWDir  = RTW.transformPaths(TI_F28xxx_SysSWDir,'pathType','alternate');
%     C28xFPUfastRTSDir   = RTW.transformPaths(C28xFPUfastRTSDir,'pathType','alternate');
    
    % Create the target paths makefile
    makefileName = 'target_paths.mk';
    fid = fopen(makefileName,'w');
    fwrite(fid, sprintf('%s\n\n', '# examplePilF28335 paths'));
    fwrite(fid, sprintf('TARGETTOOLSMKDIR    = %s\n', examplePilF28335Dir));
    fwrite(fid, sprintf('EXAMPLEPILF28335DIR = %s\n', examplePilF28335Dir));
    fwrite(fid, sprintf('CCSROOTDIR          = %s\n', CCSRootDir));
    fwrite(fid, sprintf('TIF28XXXSYSSWDIR    = %s\n', TI_F28xxx_SysSWDir));
%     fwrite(fid, sprintf('C28XFPUFASTRTSDIR   = %s\n', C28xFPUfastRTSDir));
    fclose(fid);

end

