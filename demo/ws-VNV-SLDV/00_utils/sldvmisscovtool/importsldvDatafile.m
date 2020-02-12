function [simdata,testcasename] = importsldvDatafile(Mode)
% sldvData import function for sldvmisscovtool

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'sldvDataファイルから';
            testcasename = ['[インポート]' 10 ...
                'インポートボタンクリックにより、sldvDataファイルを選択し、テストケースをインポートします。'];
        else
            simdata = 'From sldvData';
            testcasename = ['[Import]' 10 ...
                'Import testcases from sldvData.'];
        end
    case 'import'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            warndlgstr = '指定されたMATファイルはSLDVのデータ形式ではありません';
            cancelstr='キャンセルしました';
        else
            warndlgstr = 'Selected MAT file is not created by SLDV';
            cancelstr='Canceled';
        end
        [flname,dirname]=uigetfile('*.mat');
        if flname==0
            simdata=[];
            testcasename=cancelstr;
            return;
        end
        load(fullfile(dirname,flname));
        if ~exist('sldvData','var')
            simdata = [];
            testcasename = warndlgstr;
            return;
        end
        simdata = sldvsimdata2(fullfile(dirname,flname));
        for n=1:length(simdata)
            testcasename{n} = 'TestCase%03d';
        end
    otherwise
        simdata = '';
end

%% sldvsimdata2
function out = sldvsimdata2(filename)
% This is a modified version of sldvsimdata.
% sldvsimdata is not suitable for simplot becase of lacking of label
% property.

rawtc = load(filename);
out = [];
numTestCases = length(rawtc.sldvData.TestCases);

if numTestCases >0
    for idx=1:numTestCases
        out(idx).time = rawtc.sldvData.TestCases(idx).timeValues'; %#ok<AGROW>
        numInports = length(rawtc.sldvData.TestCases(idx).dataValues);
        for i=1:numInports
            if isfield(rawtc.sldvData.TestCases(idx),'portDimensions')
                inportDim = rawtc.sldvData.TestCases(idx).portDimensions{i};
            else % R08b
                inportDim = size(rawtc.sldvData.TestCases(idx).dataValues{i},1);
            end
            data = rawtc.sldvData.TestCases(idx).dataValues{i};
            if numel(inportDim) > 1
                rows=inportDim(1);
                cols=inportDim(2);
                data = reshape(data, rows, cols, size(data,2));
            else
                data = data';
            end

            data(isnan(data)) = 0;
            out(idx).signals(i).values = data; %#ok<AGROW> % changed to column based.
            if isfield(rawtc.sldvData.TestCases(idx),'signalLabels')
                out(idx).signals(i).label = rawtc.sldvData.TestCases(idx).signalLabels{i}; %#ok<AGROW>
            else % R08b
                out(idx).signals(i).label = rawtc.sldvData.AnalysisInformation.InputPortInfo{i}.SignalLabels;
            end
            out(idx).signals(i).dimensions = inportDim; %#ok<AGROW>
        end
    end
end
