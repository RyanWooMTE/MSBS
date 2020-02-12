function [simdata,testcasename] = _importTemplate(Mode)
% sldvmisscovtool用 インポート関数 (テンプレート)
% Import function template for sldvmisscovtool
%
% このファイルを import から始まるファイル名として保存すると
% sldvmisscovtool GUI上の「インポート」欄に読み込まれます。
% (sldvmisscovtoolの再起動が必要となります)
%
% By saving as a function M-file begining with "import", this function will
% be listed as [Import] function in sldvmisscovtool GUI.
% Re-run of sldvmisscovtool is needed.

%   Copyright 2010-2011 The MathWorks, Inc. 

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
%% import
    case 'import'
        
        % インポート処理を実行し、信号データとして変数名 simdata を時間付き構造体の形式で作成する
        % Imported data needs to be expressed as structure with time format
        % with variable name simdata.
        simdata(1).time = 0:0.1:1;
        simdata(1).signals(1).values=[1 2];
        simdata(1).signals(1).label='signal1';
        simdata(1).signals(1).dimensions=1;
        % テストケースリストボックスに表示されるテストケース名を指定します。
        % Specify name of the test case which will be shown in TestCase
        % list box in GUI
        testcasename{1} = 'TestCase01';
end


