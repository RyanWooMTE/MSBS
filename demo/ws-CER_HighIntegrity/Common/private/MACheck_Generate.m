function [] = MACheck_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag)
% ModelAdvisor static checks report generation

% list of checks to run stored in a Model Advisor configuration file
MAConfFileName = ['MAConfFile_', Flag.CurrentRelease, Flag.MACheckExt, '.mat'];

CheckFileName = [SrcModelName,'_check'];

if Flag.Toc,tic;end
if Flag.Echo
    disp(['Source model = ',SrcModelName]);
    fprintf(1,'Model Advisor static checks in progress... ');
end

% diary('test.html');

load_system(SrcModelName);
    
switch Flag.CurrentRelease
    case 'R2012b'
        SysResultCell = ModelAdvisor.run(SrcSubPath,...
            'Configuration',MAConfFileName,...
            'DisplayResults','None',...
            'Force','On',...
            'ShowExclusions','Off');
    case 'R2012a'
        SysResultCell = ModelAdvisor.run(SrcSubPath,...
            'Configuration',MAConfFileName,...
            'DisplayResults','None',...
            'Force','On',...
            'ShowExclusions','Off');
    case 'R2011b'
        SysResultCell = ModelAdvisor.run(SrcSubPath,...
            'Configuration',MAConfFileName,...
            'DisplayResults','None',...
            'Force','On');
    otherwise
        diary off
        error('ModelAdvisor static checks is validated for the following MATLAB releases only: R2011b, R2012a and R2012b');
end

% diary off

SysResult = SysResultCell{1};
save(fullfile(ReportLocation,CheckFileName),'SysResult');
% save(fullfile(ReportLocation,CheckFileName),'SysResultCell');

if Flag.Echo
    disp('Done');
    disp(['=> Static check stored in ',CheckFileName,'.mat']);

    % Get the current project:
    projectRoot = getProjectRoot();

    HLink = disp_hlink('Report', [projectRoot '\work\slprj\modeladvisor\', strrep(SrcModelName, '_', '__'), '\report.html']);
    disp(['=> HTML report stored in ',HLink]);
end

if Flag.Toc,toc;end
if Flag.Echo,Flag.Line();end

% Optionally add to the work prducts in the Simulink Project
if Flag.AddProduct 
    %viewReport(SysResult);
    addWorkProduct(fullfile(ReportLocation,[CheckFileName,'.mat']),{certifname,'Classification'},{'Data','Artifact'})
end

end
