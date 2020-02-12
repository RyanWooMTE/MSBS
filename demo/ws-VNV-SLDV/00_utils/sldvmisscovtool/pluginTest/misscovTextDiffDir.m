function misscovTextDiffDir(TestDir,ext)
% helper function for plugin testing of sldvmisscovtool
% misscovTextDiffDir get diff for all files with given extension using diff
% command in DOS.

files=dir(TestDir{1});
for n=1:length(files)
    if ~isempty(strfind(files(n).name,ext))
        file1 = [TestDir{1},'/',files(n).name];
        file2 = [TestDir{2},'/',files(n).name];
        cmd = sprintf('!diff %s %s',file1,file2);
        str = evalc(cmd);
        if isempty(str)
            fprintf('[Pass] %s and %s is identical\n',file1,file2)
        else
            fprintf('[Alert] Differences are found in %s and %s \n',file1,file2)
            disp(str)
        end
    end
end
