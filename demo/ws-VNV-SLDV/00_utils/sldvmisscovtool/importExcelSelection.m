function [simdata,testcasename] = importExcelSelection(Mode)
% sldvmisscovtool�p ���͊֐� (Excel�I������C���|�[�g)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'Excel�I������';
            testcasename = ['[�C���|�[�g]' 10 ...
                '�C���|�[�g�{�^���N���b�N�ɂ��AExcel��̑I�����ꂽ�Z�����f�[�^���C���|�[�g���܂��B'];
        else
            simdata = 'From WorkSpace';
            testcasename = ['[Import]' 10 ...
                'Import test cases from selected Excel cell.'];
        end
    case 'import'
        [xlsfile,sheet,Range] = getActiveExcelSheetRange();
        [simdata,testcasename] = xls2simdata(xlsfile,sheet,Range);
    otherwise
        simdata = [];
end


function [simdata,TestCaseName] = xls2simdata(xlsfile,sheet,SignalRange)
% xls2SignalBuilder  Create SignalBuilder block from Excel selection

[data,text]= xlsread(xlsfile,sheet,SignalRange);

if strcmp(text{1,1},'<�e�X�g�P�[�X>')
    TestCaseName = text(1,2);
    NlabelCol = 2;
    NdtCol = 3;
else
    TestCaseName = '';
    NlabelCol = 1;
    NdtCol = 2;
end
simdata.time = data(:,1);

for n=1:size(data,2)-1
    simdata.signals(n).label = text{NlabelCol,n+1};
    simdata.signals(n).values = cast(data(:,n+1),text{NdtCol,n+1});
    simdata.signals(n).dimensions = 1;
end