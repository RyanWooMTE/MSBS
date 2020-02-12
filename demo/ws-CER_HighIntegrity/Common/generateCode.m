function generateCode()
%% Batch generate code for the current directory Functions 
% slbuild is invoked on each model in the current directory.

bdclose all

topModelList = findit('Type', 'TopModel', [getProjectRoot() '\Model']);

if isempty(topModelList)
    error('There are no models to generate code');
end

% Memorise current directory
curdir = cd;


%% Generate the code for each Function is that directory.
for idx = 1:length(topModelList)
    [mpath,mdl] = fileparts(topModelList{idx});
    disp(['***** Building for top model: ' mdl ' (in ' mpath ')']);
    cd(mpath)
    rtwbuild(mdl);

    % Display a link to the code gen report.
    rFull = fullfile([getWorkProducts(), '\Code\', mdl,  '_ert_rtw\html\'],[mdl,'_codegen_rpt.html']);
    [rPath,rName,rExt] = fileparts(rFull);
    fprintf(1,'View CodeGen Report <a href = "matlab: web(''%s'')">%s%s</a>\n',rFull,rName,rExt);

end

% Return to original directory
cd(curdir)
end
