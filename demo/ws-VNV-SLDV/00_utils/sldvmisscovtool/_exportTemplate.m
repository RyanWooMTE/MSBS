function [stat,msg] = _exportTemplate(Mode,selected)
% sldvmisscovtool用 エクスポート関数 (テンプレート)
% export function template for sldvmisscovtool
%
% このファイルを export から始まるファイル名として保存すると
% sldvmisscovtool GUI上の「エクスポート」欄に読み込まれます。
% (sldvmisscovtoolの再起動が必要となります)
%
% By saving as a function M-file begining with "export", this function will
% be listed as [Export] function in sldvmisscovtool GUI.
% Re-run of sldvmisscovtool is needed.

%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
switch Mode
%% description
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            % 日本語モードの場合に表示する
            simdata = 'プルダウンリストに表示する文字列';
            testcasename = '[Import] Descriptions of this feature. This shown in the information window.';
        else
            % Shown in non-Japanese mode
            simdata = 'Strings shown pull-down list blox in GUI';
            testcasename = ['[Import] Descriptions of this feature. This shown in the information window.'];
        end
%% export
    case 'export'
        % ベースワークスペースから simdata を読み込む
        % load simdata variable in base WorkSpace
        simdata_tmp = evalin('base','simdata');

        % GUI上のテストケースリストボックスで選択されたもののみを抽出
        % pick only selected data in TestCase listbox in the GUI
        simdata = simdata_tmp(selected);

        % これ以下に、時間付き構造体フォーマットの simdata を任意のフォーマット
        % に変換するスクリプトを記述してください。
        % put script here to convert your own data format from simdata which is 
        % defined as structure with time format.
end
