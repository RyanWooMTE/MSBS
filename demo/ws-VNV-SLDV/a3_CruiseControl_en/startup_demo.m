%% fΜ?ϊ?έθ

orgdir = pwd;
addpath(fullfile(pwd,'Utils'))
thispath = fileparts(which(mfilename));
cd(fullfile(thispath,'../00_utils'))
setup_utils_en
cd(orgdir)

% if ~verLessThan('matlab','7.13')
%     p = Simulink.ModelManagement.Project.CurrentProject();
%     if ~p.isProjectLoaded
%         % Simulinkv?WFNgͺ??[h³κΔ’Θ―κΞ??[h·ι
%         p.loadProject(pwd)
%     end
% end

clear orgdir thispath

%% fΐ?spHTMLπ\¦
web('ModelVerificationDemo.html')
