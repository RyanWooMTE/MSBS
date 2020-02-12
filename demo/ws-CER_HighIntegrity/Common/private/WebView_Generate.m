function [] = WebView_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag)
% Web View generation

if Flag.Toc,tic;end
if Flag.Echo
    disp(['Source model = ',SrcModelName]);
    fprintf(1,'Web View generation in progress... ');
end

load_system(SrcModelName);


%% Use slwebview to create the webview of the model.
pushdir(ReportLocation);
try
    WebFileName = slwebview( SrcSubPath, ...
        'LookUnderMasks', 'All', ...
        'FollowLinks', 'Off', ...
        'FollowModelReference', 'On', ...
        'ViewFile', false );
catch
    keyboard;
end
popdir;

if Flag.Echo
    disp('Done');

    [res,txt] = system('firefox -v');
    if(res==0)
        % Firefox is installed and in the path.
        HLink = disp_firefox_hlink([SrcModelName,'_slwebview.html'],WebFileName);
    else
        % Firefox is not installed, default to webview instead.
        HLink = disp_hlink([SrcModelName,'_slwebview.html'],WebFileName);
    end
    disp(['=> Web View stored in ',HLink]);
end
if Flag.Toc,toc;end
if Flag.Echo,Flag.Line();end

% Optionally add to the work prducts in the Simulink Project
if Flag.AddProduct 
    addWorkProduct(WebFileName,{certifname,'Classification'},{'Report','Artifact'})
end

end
