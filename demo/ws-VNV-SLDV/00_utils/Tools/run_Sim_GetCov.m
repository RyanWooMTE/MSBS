function run_Sim_GetCov(mdl)
% run_Sim_GetCov SLDVで生成されたハーネスモデルのカバレッジを測定する

%   Copyright 2012 The MathWorks, Inc. 

sigbuil = [mdl '/Inputs'];

[~,~,~,grpname] = signalbuilder(sigbuil);
%set_param(mdl,'CovMetricSettings','dcms');


for m=1:length(grpname)

    signalbuilder(sigbuil,'ACTIVEGROUP',m);
    cvto = cvtest(mdl);
    if ~exist('covData','var')
        covData = cvsim(cvto);
    else
        covData = covData + cvsim(cvto);
    end
end
cvhtml(sprintf('%s_cov.html',mdl),covData)
