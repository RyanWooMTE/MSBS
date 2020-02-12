function [] = SDD_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag)
% System Design Description generation

ReportFileName = [SrcModelName,'_sdd'];
ReportTitle = SrcModelName;

if Flag.Toc,tic;end
if Flag.Echo
    disp(['Source model = ',SrcModelName]);
    fprintf(1,'System Design Description generation in progress... ');
end

load_system(SrcModelName);

% Variables used in the rpt definition file:
% ReportLocation
% ReportFileName
% SrcModelName
% SrcSubPath
% ReportTitle
assignin('base','ReportLocation',ReportLocation);
assignin('base','ReportFileName',ReportFileName);
assignin('base','SrcModelName',SrcModelName);
assignin('base','SrcSubPath',SrcSubPath);
assignin('base','ReportTitle',ReportTitle);

%% Use the report generator to generate the SDD.
report('mySDD','-quiet');

evalin('base','clear ReportLocation ReportFileName SrcModelName SrcSubPath ReportTitle');

if Flag.Echo
    disp('Done');
    HLink = disp_hlink([ReportFileName,'.pdf'],[ReportLocation,filesep,ReportFileName,'.pdf']);
    disp(['=> System Design Description stored in ',HLink]);
end
if Flag.Toc,toc;end
if Flag.Echo,Flag.Line();end

% Optionally add to the work prducts in the Simulink Project
if Flag.AddProduct 
    addWorkProduct(fullfile(ReportLocation,[ReportFileName,'.pdf']),{certifname,'Classification'},{'Report','Artifact'})
end

end
