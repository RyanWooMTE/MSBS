%% �f����?���?ݒ�

orgdir = pwd;
addpath(fullfile(pwd,'Utils'))
thispath = fileparts(which(mfilename));
cd(fullfile(thispath,'../00_utils'))
setup_utils_en
cd(orgdir)

% if ~verLessThan('matlab','7.13')
%     p = Simulink.ModelManagement.Project.CurrentProject();
%     if ~p.isProjectLoaded
%         % Simulink�v�?�W�F�N�g���??[�h����Ă��Ȃ���΃??[�h����
%         p.loadProject(pwd)
%     end
% end

clear orgdir thispath

%% �f����?s�pHTML��\��
web('ModelVerificationDemo.html')
