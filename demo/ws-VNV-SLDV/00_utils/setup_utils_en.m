
thispath = fileparts(which(mfilename));
addpath(fullfile(thispath,'Tools'))
addpath(fullfile(thispath,'SDOxlsIF'))
addpath(fullfile(thispath,'SDOxlsIF','ENG'))
addpath(fullfile(thispath,'CustomModelAdvisorChecks'))
addpath(fullfile(thispath,'cmtdtool'))
addpath(fullfile(thispath,'sldvmisscovtool'))
addpath(fullfile(thispath,'PropertySpecificationUI'))
setup_PropertySpecificationUI

clear thispath
