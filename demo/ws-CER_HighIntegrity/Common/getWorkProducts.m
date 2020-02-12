function p = getWorkProducts()
%GETPROJECTROOT returns the project root
%   Simulink projects independent function to get the project root 

p = fullfile(getProjectRoot(), 'Artefacts');
