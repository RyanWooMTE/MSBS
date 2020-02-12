function coverageMgr(action)
    p = slproject.getCurrentProject;

    switch (action)
        case 'clear'
            if exist(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'),'file')==2
                delete(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'));
            end
        case 'show'
            if exist(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'),'file')==2
                [~, covdata_SLT] = cvload(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'));
                cvmodelview(covdata_SLT{1});
                cvhtml('my_coverage.html',covdata_SLT{1})
            end
        case 'add'
            if exist(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'),'file')==2
                [~, covdata_SLT] = cvload(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'));
                if ~isempty(covdata_SLT)
                    covdata_SLT = covdata_SLT{1} + evalin('base','covdata');
                else  % if model has changed then covdata will be empty
                    covdata_SLT = evalin('base','covdata');
                end
            else
                covdata_SLT = evalin('base','covdata');
            end
            cvsave(fullfile(p.RootFolder,'Work','cumcov_SLT.cvt'),covdata_SLT);
    end
end
