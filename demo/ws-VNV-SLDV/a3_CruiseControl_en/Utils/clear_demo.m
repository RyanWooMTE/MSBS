%% デモに不要なファイルを削除しデモのスタートアップを行う

close all
bdclose all
% 
delete *.mexw64
delete *.mexw32

delete *.asv

% deleting folders
deldirs = {'slprj','sldv_output','scv_images','rtwgen_tlc','figs','*rtw','*html_files'};
for n=1:length(deldirs)
    if exist(deldirs{n},'dir')
        rmdir(deldirs{n},'s')
    elseif strfind(deldirs{n},'*')
        try
        rmdir(deldirs{n},'s')       
        catch
        end
    end
end

files = dir('*.html');
for n=1:length(files)
    if ~strcmp(files(n).name,'ModelVerificationDemo.html')
        delete(files(n).name);
    end
end

clear all
clc

startup_demo
