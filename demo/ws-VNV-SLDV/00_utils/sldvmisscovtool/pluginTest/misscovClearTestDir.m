function misscovClearTestDir(TestDir,ext)
% helper function for plugin testing of sldvmisscovtool
% misscovClearTestDir clears all files with given extension stored in
% TestDir directories.
% $Id:$

for m=1:length(TestDir)
    if ~isdir(TestDir{m})
        mkdir(TestDir{m})
    else
        files=dir(TestDir{m});
        for n=1:length(files)
            if ~isempty(strfind(files(n).name,ext))
                delete(fullfile(TestDir{m},files(n).name))
            end
        end
    end
    fprintf('All %s files in %s have been removed\n',ext,TestDir{m})
end
