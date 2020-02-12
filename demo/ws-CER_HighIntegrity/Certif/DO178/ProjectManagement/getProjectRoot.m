function p = getProjectRoot()
%GETPROJECTROOT returns the project root
%   Simulink projects independent function to get the project root 

CurrentRelease = version('-release');
try
    proj = Simulink.ModelManagement.Project.CurrentProject();
    if eval(CurrentRelease(1:end-1))<2012
        p = proj.getRootDirectory();
    else
        p = proj.getRootFolder();
    end
catch
    p = fullfile(fileparts(mfilename('fullpath'),'..'));
end
