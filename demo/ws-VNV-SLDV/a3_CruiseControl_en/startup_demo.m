%% ƒfƒ‚‚Ì?‰Šú?Ý’è

orgdir = pwd;
addpath(fullfile(pwd,'Utils'))
thispath = fileparts(which(mfilename));
cd(fullfile(thispath,'../00_utils'))
setup_utils_en
cd(orgdir)

% if ~verLessThan('matlab','7.13')
%     p = Simulink.ModelManagement.Project.CurrentProject();
%     if ~p.isProjectLoaded
%         % Simulinkƒvƒ?ƒWƒFƒNƒg‚ªƒ??[ƒh‚³‚ê‚Ä‚¢‚È‚¯‚ê‚Îƒ??[ƒh‚·‚é
%         p.loadProject(pwd)
%     end
% end

clear orgdir thispath

%% ƒfƒ‚ŽÀ?s—pHTML‚ð•\Ž¦
web('ModelVerificationDemo.html')
