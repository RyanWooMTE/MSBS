%% setup file for cmtdtool
%  This file modifies help files so that you can see Help documents on your
%  MALTAB help browser on any version.

%   Copyright 2010-2011 The MathWorks, Inc. 
% 
dirname=fileparts(which('cmtdtool'));
orgpath = pwd;
cd(dirname)

% サンプルのディレクトリを取得
verstr = version('-release');
helpdirname_en = 'doc_en';
helpdirname_ja = 'doc_ja';

%% Generate info.xml
helpdir_en = regexprep(fullfile(dirname,helpdirname_en),'\\','\\/');
helpdir_ja = regexprep(fullfile(dirname,helpdirname_ja),'\\','\\/');
fidr = fopen('info_template.xml','r');
fidw_en = fopen('info.xml','w');
fidw_ja = fopen('ja/info.xml','w');

tline = fgets(fidr);
while ischar(tline)
    fprintf(fidw_en,'%s',regexprep(tline,'_DIR_',helpdir_en));
    fprintf(fidw_ja,'%s',regexprep(tline,'_DIR_',helpdir_ja));
    tline = fgets(fidr);
end
fclose(fidr);
fclose(fidw_en);
fclose(fidw_ja);
fprintf('%s is generated.\n',fullfile(dirname,'info.xml'))
fprintf('%s is generated.\n',fullfile(dirname,'ja','info.xml'))

%% helptoc.xmlの文字コード合わせ
% R2010a 以降のバージョンはUTF-8
% それ以前のバージョンはSJISのhelptoc.xmlを利用する
helptoc = fullfile(dirname,helpdirname_ja,'helptoc.xml');
if str2double(verstr(1:end-1)) >= 2010
    orgfile = fullfile(dirname,helpdirname_ja,'helptoc_afterR2010a.xml');
    delete(helptoc)
    copyfile(orgfile,helptoc)
else
    orgfile = fullfile(dirname,helpdirname_ja,'helptoc_untilR2009b.xml');
    delete(helptoc)
    copyfile(orgfile,helptoc)
end
fprintf('%s を作成しました\n',helptoc)

% ヘルプをリセットし表示
docroot(docroot);
doc

% 元のフォルダに戻る
cd(orgpath)
