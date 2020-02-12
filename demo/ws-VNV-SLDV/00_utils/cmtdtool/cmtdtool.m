function varargout = cmtdtool(varargin)
% CMTDTOOL A GUI tool for model-based testing
%  
% [Overview]
% cmtdtool is an assistant tool for model-based testing in MBD processes. 
% Initially, this tool is developed for JMAAB-CMTD-WS (JMAAB: Japan MBD Automotive Advisory Board, 
% CMTD-WS: Control Model Test Design Working Group). After several improvements upon feedback from 
% the JMAAB-CMTD-WG members, it is published to MATLAB Central.
% Test design, composing test model, test execution, and reporting are performed 
% when you run tests for a controller model. This tool helps you to reduce and automate 
% manual operations required to perform them.
% 
% 
% [Installation and execution]
% (1) Extract cmtdtool.zip at a folder
% (2) Add the (1) folder to MATLAB path
% (3) Run the following command at MATLAB Command Window so that you can refer help document using MATLAB Help browser.
%  >> cmtdtool_setup
% (4)  Run the following command at MATLAB Command Window to invoke cmtdtool:
%  >> cmtdtool
% 
% [Change Log]
% * 2010/06/29 Delivered to JMAAB-CMTD-WG (JMAAB Control Model Test Design Working Group).
% * 2010/08/04 Bug fixed version had sent to JMAAB-CMTD-WS.
% * 2010/11/02 Ver0.8 had sent to JMAAB-CMTD-WS.
% * 2011/02/14 Ver0.9 had sent to JMAAB-CMTD-WS.
% * 2011/05/27 Ver1.0 has been uploaded to MATLAB Central.
% * 2011/12/28 Ver1.1 has been uploaded to MATLAB Central.

%   Copyright 2010-2011 The MathWorks, Inc. 

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @cmtdtool_OpeningFcn, ...
    'gui_OutputFcn',  @cmtdtool_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before cmtdtool is made visible.
function cmtdtool_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to cmtdtool (see VARARGIN)

handles = create_localized_messages(handles);
if isJapaneseEnv
    set(handles. japanese_mn,'Checked','on')
    set(handles. english_mn,'Checked','off')
else
    set(handles. japanese_mn,'Checked','off')
    set(handles. english_mn,'Checked','on')
end

set_GUI_strings(hObject, eventdata, handles);
handles.docpath = setDocPath(handles);

if ~isSlVnVInstalled()
    set(handles.setReqLink,'Enable','off')
end
% Choose default command line output for cmtdtool
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes cmtdtool wait for user response (see UIRESUME)
% uiwait(handles.figure1);


function handles=create_localized_messages(handles)

ja.string.SignalBuilderGen_pb = 'Excel選択からSignalBuilderを作成';
en.string.SignalBuilderGen_pb = 'Excel selection to SignalBuilder';
ja.string.xls2SignalBuilder_multipl_pb = 'ExcelからSignalBuilderを作成(一括)';
en.string.xls2SignalBuilder_multipl_pb = 'Excel sheet to SignalBuilder';
ja.string.new_sigbuil_rb = '新規';
en.string.new_sigbuil_rb = 'New';
ja.string.add_signalbuil_rb = '追加';
en.string.add_signalbuil_rb = 'Add';
ja.string.replace_sigbuil_rb = '置換';
en.string.replace_sigbuil_rb = 'Replace';
ja.string.truthtable_pb = '真理値表を作成';
en.string.truthtable_pb = 'Generate TruthTable';
ja.string.verification_table_pb = '検証用真理値表を作成';
en.string.verification_table_pb = 'TruthTable for Verification';
ja.string.create_harness = 'ハーネスモデル作成';
en.string.create_harness = 'Generate Harness';
ja.string.harness_withexpecedout = '期待出力一致確認用ハーネスモデル';
en.string.harness_withexpecedout = 'Harness with expected output';
ja.string.select_testblock_pb = 'テスト対象ブロック選択';
en.string.select_testblock_pb = 'Select a block for testing';
ja.string.run_simall_pb = 'シミュレーション一括実行';
en.string.run_simall_pb = 'Run all simulations';
ja.string.create_report_pb = 'レポート生成';
en.string.create_report_pb = 'Generate report';
ja.string.userdefinedtest_pb = 'ユーザ定義テスト';
en.string.userdefinedtest_pb = 'User defined test';
ja.string.requrement_based_pb = '要件ベーステスト';
en.string.requrement_based_pb = 'Requirement-based testing';
ja.string.autowire_pb = '自動結線';
en.string.autowire_pb = 'Automatic Wiring';

% ja.string. = '';
% en.string. = '';
ja.title.xls2sigbuil_tag = 'ExcelからSignalBuilder';
en.title.xls2sigbuil_tag = 'Excel to SignalBuilder';
ja.title.xls2tt_tag = 'Excelから真理値表';
en.title.xls2tt_tag = 'Excel to TruthTable';
ja.title.report_gen_tag = 'レポート';
en.title.report_gen_tag = 'Report';
% ja.title. = '';
% en.title. = '';
ja.label.settings_menu = '設定';
en.label.settings_menu = 'Settings';
ja.label.show_command = 'コマンドによる実行方法を表示';
en.label.show_command = 'Show command on Command Window';
ja.label.help_mn= 'ヘルプ';
en.label.help_mn = 'Help';
ja.label.helpdoc_mn= 'ヘルプを見る';
en.label.helpdoc_mn = 'View Help';
ja.label.modelrefharness = 'ハーネスモデルでモデルリファレンスを用いる';
en.label.modelrefharness = 'Use model reference block for harness model';
ja.label.setReqLink = 'Excelへのリンクを自動的に設定';
en.label.setReqLink = 'Automatically set a link to Excel';

ja.message.reftodoc = 'ドキュメントを参照';
en.message.reftodoc = 'Refer to Documentation';
ja.message.invalidformat = 'フォーマットが異なります。';
en.message.invalidformat = 'Invalid format';
ja.message.reporting_error = 'エラーが発生しました。';
en.message.reporting_error = 'An error occured.';
ja.message.showerror = 'エラーを表示';
en.message.showerror = 'Show error on Command Window';
ja.message.error_makeharness = 'ハーネスモデルの作成に失敗しました';
en.message.error_makeharness = 'Failed to make harness model';
ja.message.version_error_R09b = 'この機能はMATLAB R2009b以降で対応しており、ご利用のMATLABでは対応しておりません。';
en.message.version_error_R09b = 'This feature is not supported on your version of MATLAB. User R2009b or later.';
% ja.message. = '';
% en.message. = '';


% ja.label. = '';
% en.label. = '';
% ja.warndlg{1} = '';
% en.warndlg{1} = '';

guistr_ja = ja;
guistr_en = en;

% Language setting is refers to MATLAB desktop language.
if isJapaneseEnv()
    handles.guistr = guistr_ja;
    changeFontName(handles,'Monospaced')
else
    handles.guistr = guistr_en;
    changeFontName(handles,'Arial')
end
handles.guistr_ja = guistr_ja;
handles.guistr_en = guistr_en;

%% set GUI strings
function set_GUI_strings(hObject, eventdata, handles) %#ok

% set String properties
flnames=fieldnames(handles.guistr.string);
for n=1:length(flnames)
    set(handles.(flnames{n}),'String',handles.guistr.string.(flnames{n}));
end

% set Title properties
flnames=fieldnames(handles.guistr.title);
for n=1:length(flnames)
    set(handles.(flnames{n}),'Title',handles.guistr.title.(flnames{n}));
end

% set label properties
flnames=fieldnames(handles.guistr.label);
for n=1:length(flnames)
    set(handles.(flnames{n}),'Label',handles.guistr.label.(flnames{n}));
end

% set tooltips properties
% flnames=fieldnames(handles.guistr.tooltips);
% for n=1:length(flnames)
%     set(handles.(flnames{n}),'TooltipString',handles.guistr.tooltips.(flnames{n}));
% end

%% Change FontName to use differenct fonts in JA and EN
function changeFontName(handles,FontName)
flnames = fieldnames(handles);
for n=1:length(flnames)
    hn = handles.(flnames{n});
    if ishandle(hn)
        if any(strcmp(get(hn,'Type'),{'uicontrol','uipanel'}))
            set(hn,'FontName',FontName)
        end
    end
end


% --- Outputs from this function are returned to the command line.
function varargout = cmtdtool_OutputFcn(hObject, eventdata, handles) %#ok

% Get default command line output from handles structure
varargout{1} = handles.output;


%% ExcelSelection2SignalBuilder
function SignalBuilderGen_pb_Callback(hObject, eventdata, handles) %#ok

[xlsfile,sheet,Range] = getActiveExcelSheetRange();
if isempty(xlsfile)
    return;
end
if get(handles.add_signalbuil_rb,'Value')
    Mode = 'append';
    blk  = gcb;
elseif get(handles.replace_sigbuil_rb,'Value');
    Mode = 'replace';
    blk = gcb;
else
    Mode = 'new';
    blk = '';
end
if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2SignalBuilder(''%s'',''%s'',''%s'',''%s'',''%s'');\n',xlsfile,sheet,Range,blk,Mode);
end
if strcmp(get(handles.setReqLink,'Checked'),'on')
    opts.isReqLink = true;
else
    opts.isReqLink = false;
end
try
    sigbuil = xls2SignalBuilder(xlsfile,sheet,Range,blk,Mode,opts); %#ok
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd010_xls2SignalBuilder.html')
end
%% ExcelSheet2SignalBuilder
function xls2SignalBuilder_multipl_pb_Callback(hObject, eventdata, handles) %#ok

[xlsfile,sheet,Range,UsedRange] = getActiveExcelSheetRange(); %#ok
if isempty(xlsfile)
    return;
end
if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2SignalBuilder_multiple(''%s'',''%s'',''%s'',[],[]);\n',xlsfile,sheet,UsedRange);
end
if strcmp(get(handles.setReqLink,'Checked'),'on')
    opts.isReqLink = true;
else
    opts.isReqLink = false;
end

try
    xls2SignalBuilder_multiple(xlsfile,sheet,UsedRange,[],[],opts);
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd015_xls2SignalBuilder_multiple.html')
end


%% Excel2TruthTable
function truthtable_pb_Callback(hObject, eventdata, handles) %#ok

[xlsfile,sheet,Range] = getActiveExcelSheetRange();
if isempty(xlsfile)
    return;
end
if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2TruthTable(''%s'',''%s'',''%s'');\n',xlsfile, sheet, Range);
end
try
    xls2TruthTable(xlsfile, sheet, Range);
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd020_xls2TruthTable.html')
end

%% Excel2VerificationTruthTable
function verification_table_pb_Callback(hObject, eventdata, handles) %#ok

[xlsfile,sheet,Range] = getActiveExcelSheetRange();
if isempty(xlsfile)
    return;
end

if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2VerificationTruthTable(''%s'',''%s'',''%s'');\n',xlsfile,sheet,Range);
end
try
    xls2VerificationTruthTable(xlsfile,sheet,Range);
    %xls2VerificationTruthTable(xlsfile,sheet,Range);
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd030_xls2VerificationTruthTable.html')
end

%%
% --- Executes on button press in requrement_based_pb.
function requrement_based_pb_Callback(hObject, eventdata, handles) %#ok
% hObject    handle to requrement_based_pb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[xlsfile,sheet,Range] = getActiveExcelSheetRange();
if isempty(xlsfile)
    return;
end

if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2RequirementBaseTestTruthTable(''%s'',''%s'',''%s'');\n',xlsfile,sheet,Range);
end
try
    xls2RequirementBaseTestTruthTable(xlsfile, sheet, Range)
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd030_xls2RequirementBaseTestTruthTable.html')
end

%% TestHarness
function create_harness_Callback(hObject, eventdata, handles) %#ok
relstr = version('-release');
relyear = str2double(relstr(1:end-1));
if relyear < 2009 || strcmp(relstr,'2009a')
    warndlg(handles.guistr.message.version_error_R09b,'Warning')
    return;
end

try
    if strcmp(get_param(gcb,'selected'),'on') && strcmp(get_param(gcb,'blockType'),'SubSystem')
        obj = gcb;
    else
        obj = bdroot;
    end
    opts = sldvharnessopts();
    if strcmp(get(handles.modelrefharness,'Checked'),'on')
        opts.modelRefHarness = true;
    else
        opts.modelRefHarness = false;
    end        
    if strcmp(get(handles.show_command,'Checked'),'on')
        fprintf('opts = sldvharnessopts();');
        if strcmp(get(handles.modelrefharness,'Checked'),'on')
            fprintf('opts.modelRefHarness = true;')
        else
            fprintf('opts.modelRefHarness = false;')
        end
        fprintf('sldvmakeharness(''%s'',[],opts)\n',obj);
    end
    sldvmakeharness(obj,[],opts);
catch %#ok
    showErrorWindow(handles,'error_makeharness','/cd040_makeharness.html')
end

%% HarnessComparingExpectedOutputs
function harness_withexpecedout_Callback(hObject, eventdata, handles) %#ok
relstr = version('-release');
relyear = str2double(relstr(1:end-1));
if relyear < 2009 || strcmp(relstr,'2009a')
    warndlg(handles.guistr.message.version_error_R09b,'Warning')
    return;
end
try
    if strcmp(get_param(gcb,'selected'),'on') && strcmp(get_param(gcb,'blockType'),'SubSystem')
        obj = gcb;
    else
        obj = bdroot;
    end
    
    if relyear < 2011 || strcmp(relstr,'2010a')
        opts.modelRefHarness = [];
    else
        opts = sldvharnessopts();
    end
    if strcmp(get(handles.modelrefharness,'Checked'),'on')
        opts.modelRefHarness = true;
    else
        opts.modelRefHarness = false;
    end        
    if strcmp(get(handles.show_command,'Checked'),'on')
        if relyear < 2011 || strcmp(relstr,'2010a')
            % sldvharnessopts is supported with R2010b or later.
            if strcmp(get(handles.modelrefharness,'Checked'),'on')
                fprintf('opts.modelRefHarness = true;')
            else
                fprintf('opts.modelRefHarness = false;')
            end
        else
            fprintf('opts = sldvharnessopts();');
            if strcmp(get(handles.modelrefharness,'Checked'),'on')
                fprintf('opts.modelRefHarness = true;')
            else
                fprintf('opts.modelRefHarness = false;')
            end
            fprintf('makeharness_compareresults(''%s'',[],opts)\n',obj);
        end
    end
    makeharness_compareresults(obj,[],opts);
catch %#ok
    showErrorWindow(handles,'error_makeharness','/cd050_makeharness_compareresults.html')
end

function replace_sigbuil_rb_Callback(hObject, eventdata, handles) %#ok

function new_sigbuil_rb_Callback(hObject, eventdata, handles) %#ok

function settings_menu_Callback(hObject, eventdata, handles) %#ok

function lang_mn_Callback(hObject, eventdata, handles) %#ok

function japanese_mn_Callback(hObject, eventdata, handles) %#ok
handles.guistr = handles.guistr_ja;
set_GUI_strings(hObject, eventdata, handles);
changeFontName(handles,'Monospaced')
set(handles.japanese_mn,'Checked','on')
set(handles.english_mn,'Checked','off')
handles.docpath = setDocPath(handles);
handles.output = hObject;
guidata(hObject, handles);

function english_mn_Callback(hObject, eventdata, handles) %#ok
handles.guistr = handles.guistr_en;
set(handles.japanese_mn,'Checked','off')
set(handles.english_mn,'Checked','on')
set_GUI_strings(hObject, eventdata, handles);
handles.docpath = setDocPath(handles);
changeFontName(handles,'Arial')
handles.output = hObject;
guidata(hObject, handles);

function show_command_Callback(hObject, eventdata, handles) %#ok
switch get(hObject,'Checked')
    case 'on'
        set(hObject,'Checked','off')
    case 'off'
        set(hObject,'Checked','on')
end

%% Excel2UserDefinedTest
function userdefinedtest_pb_Callback(hObject, eventdata, handles) %#ok
[xlsfile,sheet,Range] = getActiveExcelSheetRange();
if isempty(xlsfile)
    return;
end

if strcmp(get(handles.show_command,'Checked'),'on')
    fprintf('xls2TestObjective(''%s'',''%s'',''%s'');\n',xlsfile,sheet,Range);
end
try
    xls2TestObjective(xlsfile,sheet,Range);
catch %#ok
    showErrorWindow(handles,'invalidformat','/cd035_xls2TestObjective.html')
end

%% Automatic Report Generation
function select_testblock_pb_Callback(hObject, eventdata, handles)%#ok

try
    handles.obj = runCMTDReport(gcb);
    if strcmp(get(handles.japanese_mn,'Checked'),'on')
        handles.obj.setLocale('ja');
    else
        handles.obj.setLocale('en');
    end
    if strcmp(get(handles.show_command,'Checked'),'on')
        fprintf('obj = runCMTDReport(''%s'');\n',gcb);
    end
catch %#ok
    showErrorWindow(handles,'reporting_error','/cd060_runCMTDReport.html')
end
set(handles.run_simall_pb,'Enable','on')
assignin('base','obj',handles.obj);
handles.output = hObject;
guidata(hObject, handles);

function run_simall_pb_Callback(hObject, eventdata, handles)%#ok
try
    handles.obj = handles.obj.runSimAll;
    if strcmp(get(handles.show_command,'Checked'),'on')
        fprintf('obj.runSimAll;\n');
    end
catch %#ok
    showErrorWindow(handles,'reporting_error','/cd060_runCMTDReport.html')
end
set(handles.create_report_pb,'Enable','on')
assignin('base','obj',handles.obj);
handles.output = hObject;
guidata(hObject, handles);


function create_report_pb_Callback(hObject, eventdata, handles)%#ok
assignin('base','obj',handles.obj);
try
    handles.obj.runReport
    if strcmp(get(handles.show_command,'Checked'),'on')
        fprintf('obj.runReport;\n');
    end
catch %#ok
    showErrorWindow(handles,'reporting_error','/cd060_runCMTDReport.html')
end
assignin('base','obj',handles.obj);

function showErrorWindow(handles,ErrType,HTMLFile)
RefDoc = handles.guistr.message.reftodoc;
ShowErr = handles.guistr.message.showerror;
ButtonName = questdlg(handles.guistr.message.(ErrType), ...
    'Error', ...
    'OK', RefDoc,ShowErr, 'OK');
switch ButtonName
    case RefDoc
        web([handles.docpath,HTMLFile], '-helpbrowser');
    case ShowErr
        MA = lasterror;%#ok
        rethrow(MA)
end

function help_mn_Callback(hObject, eventdata, handles) %#ok

function docpath = setDocPath(handles)
if strcmp(get(handles. japanese_mn,'Checked'),'on')
    docdir = 'doc_ja';
else
    docdir = 'doc_en';
end
docpath = fullfile(fileparts(which('cmtdtool')),docdir);


function helpdoc_mn_Callback(hObject, eventdata, handles) %#ok

web(fullfile(handles.docpath,'description.html'),'-helpbrowser');


% --------------------------------------------------------------------
function setReqLink_Callback(hObject, eventdata, handles)
% hObject    handle to setReqLink (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
switch get(hObject,'Checked')
    case 'on'
        set(hObject,'Checked','off')
    case 'off'
        set(hObject,'Checked','on')
end

% --------------------------------------------------------------------
function modelrefharness_Callback(hObject, eventdata, handles)
% hObject    handle to modelrefharness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
switch get(hObject,'Checked')
    case 'on'
        set(hObject,'Checked','off')
    case 'off'
        set(hObject,'Checked','on')
end


% --- Executes on button press in autowire_pb.
function autowire_pb_Callback(hObject, eventdata, handles)
% hObject    handle to autowire_pb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if ~isempty(gcb) && strcmp(get_param(gcb,'Selected'),'on')
    automaticWiring(gcb);
    fixLineOverlap(get_param(gcb,'Parent'))
end
