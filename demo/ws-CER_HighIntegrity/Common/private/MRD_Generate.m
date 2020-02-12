function [] = MRD_Generate(ReportLocation,Flag)
% Manual Review Document generation

[~,DirName] = fileparts(pwd);
ReportFileName = [DirName,'_mrd'];
ReportTitle = [DirName ' Manual Review Document'];

if Flag.Toc,tic;end
if Flag.Echo
    fprintf(1,'Manual Review Document generation in progress... ');
end

% Variables used in the rpt definition file:
% ReportLocation
% ReportFileName
% ReportTitle
assignin('base','ReportLocation',ReportLocation);
assignin('base','ReportFileName',ReportFileName);
assignin('base','ReportTitle',ReportTitle);

%% Generate the report using the Simulink reporter and the 'MRD.rpt' template file.
report('MRD','-quiet');

evalin('base','clear ReportLocation ReportFileName ReportTitle');

if Flag.Echo
    disp('Done');
    HLink = disp_hlink([ReportFileName,'.html'],[ReportLocation,filesep,ReportFileName,'.html']);
    disp(['=> Model Review Document stored in ',HLink]);
end
if Flag.Toc,toc;end
if Flag.Echo,Flag.Line();end

% Optionally add to the work products in the Simulink Project
if Flag.AddProduct 
    addWorkProduct(fullfile(ReportLocation,[ReportFileName,'.html']),{certifname,'Classification'},{'Report','Artifact'})
end

end
