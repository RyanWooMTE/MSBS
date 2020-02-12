function [simdata,testcasename] = importWorkSpace(Mode)
% sldvmisscovtool�p ���͊֐� (WorkSpace����C���|�[�g)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            simdata = 'WorkSpace����';
            testcasename = ['[�C���|�[�g]' 10 ...
                '�C���|�[�g�{�^���N���b�N�ɂ��AWorkSpace��ɃZ�[�u���ꂽ�ϐ����f�[�^���C���|�[�g���܂��B'];
        else
            simdata = 'From WorkSpace';
            testcasename = ['[Import]' 10 ...
                'Import test cases from a specified variable assingned in base workspace.'];
        end
    case 'import'
        [simdata,testcasename] = readWorkSpace();
    otherwise
        simdata = [];
end


function  [simdata,testcasename] = readWorkSpace()

%% Dialog to specify variable name
if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
    qstr={'�ǂݍ��ޕϐ������w�肵�Ă�������','�e�X�g�P�[�X�����w�肵�Ă�������'};
    titlestr='�ϐ����̎w��';
    cancelstr = '�L�����Z�����܂���';
    isnotStructWithTimeStr='�w�肳�ꂽ�ϐ��͎��ԕt���\���̂ł͂���܂���';
    err_zero_size = '��̍\���̂ł�';
else
    qstr={'Specify a variable name to import', 'Specify a name of this test case'};
    titlestr='Variable name';
    cancelstr='Canceled';
    isnotStructWithTimeStr='Specified variable is not Struct with Time format.';
    err_zero_size = 'The struct variable is empty';
end

defaultanswer={'sdata','TestCase%03d'}; % This should not be simdata.
valname=inputdlg(qstr,titlestr,1,defaultanswer);

if isempty(valname)% Cancel button
    simdata = [];
    testcasename = cancelstr;
    return;
end

%% import from work space
try
    simdata = evalin('base',valname{1});
    testcasename =cell(0);
catch
    simdata = [];
    er = lasterror;
    testcasename = er.message;
end
for n=1:length(simdata)
    simdata(n).signalName = valname{2};
    testcasename{n}=valname{2}; 
end

% Check that simdata is a structure with time format
if ~isfield(simdata,'time') || ~isfield(simdata,'signals')
    simdata = [];
    testcasename = isnotStructWithTimeStr;
    return;
end

if isempty(simdata)
    simdata=[];
    testcasename = err_zero_size;
    return;
end
    