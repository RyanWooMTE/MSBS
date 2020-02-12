function rundemo_helper(demoname)

opts.CtrlMdl = 'controller';
opts.TopMdl = 'cruise_control_top';
opts.CtrlChildRefMdl = [opts.CtrlMdl '/cuise_control'];
opts.CtrlChildMdl = 'cruise_control';
opts.CtrlChildImplMdl = 'cruise_control_sdo';
opts.DataFile = {'cruise_control_data','transmission_data'};
opts.FloatDataFile = {'cruise_control_data','transmission_data','load_float_data'};
opts.FixptDataFile = {'cruise_control_data','transmission_data','load_fxpt_data'};
opts.SignalBuilder = [opts.TopMdl '/TestCases'];
opts.ReqSpec = 'CruiseControl_spec.xls';
opts.ReportFolder = 'report';
opts.PropModel = 'cruise_control_prop';
opts.PropModelError = 'cruise_control_prop_error';
opts.CustomCheckFolder = '../00_utils/CustomModelAdvisorChecks';
initEnvironment(opts)

feval(demoname,opts)

function initEnvironment(opts)
if ~exist(opts.ReportFolder,'dir')
    mkdir(opts.ReportFolder);
end

function openCtrlModel(opts)  %#ok
% コントローラモデルを開く
open_system(opts.CtrlMdl)
loadDataFile(opts)

function openCtrlChildMdl(opts)  %#ok
% コントローラ子モデルを開く
open_system(opts.CtrlChildMdl)
loadDataFile(opts)

function loadDataFile(opts)
% データファイルをロードする
for n=1:length(opts.DataFile)
    evalin('base',opts.DataFile{n})
end

function loadFloatDataFile(opts)
% データファイルをロードする(float)
for n=1:length(opts.FloatDataFile)
    evalin('base',opts.FloatDataFile{n})
end

function loadFixedDataFile(opts)
% データファイルをロードする(fixed)
for n=1:length(opts.FixptDataFile)
    evalin('base',opts.FixptDataFile{n})
end

function openTopModel(opts) %#ok
% システムレベルモデルを開く
open_system(opts.TopMdl)
loadDataFile(opts)

function runSimMesureCov(opts) %#ok
% シミュレーションを実行しカバレッジを測定
open_system(opts.TopMdl);
open_system(opts.CtrlMdl);
open_system(opts.CtrlChildMdl);
open_system(opts.SignalBuilder);

loadDataFile(opts)

[timev,~,~,grp] = signalbuilder(opts.SignalBuilder);

cvtoController = cvtest(opts.CtrlMdl);
cvtoController = setcvtestSetting(cvtoController);
cvtoChild = cvtest(opts.CtrlChildMdl);
cvtoChild = setcvtestSetting(cvtoChild);

cvtg = cv.cvtestgroup(cvtoController,cvtoChild);

covRef = [];
for nSig=1:length(grp)
    signalbuilder(opts.SignalBuilder,'ACTIVEGROUP',nSig);
    cvdg = cvsimref(opts.TopMdl,cvtg,[min([timev{:,nSig}]) max([timev{:,nSig}])]);
    if isempty(covRef)
        covRef = cvdg;
    else
        covRef = covRef+cvdg;
    end    
end
orgdir = pwd;
cd(opts.ReportFolder)
cvhtml(sprintf('%s_cov.html',opts.CtrlMdl),covRef)
cd(orgdir)
assignin('base','covRef',covRef);


function cvto = setcvtestSetting(cvto)
cvto.settings.decision=1;
cvto.settings.condition=1;
cvto.settings.mcdc=1;
cvto.modelRefSettings.enable='on';


function getGenCovParent(opts) %#ok
% シミュレーションで不足した未到達要素を満たすテストを自動生成(制御モデル全体)
if ~evalin('base','exist(''covRef'',''var'')')
    warndlg(sprintf('covRefがワークスペースに見つかりません。%sのシミュレーションを先に実行する必要があります',opts.TopMdl))
    return;
end
open_system(opts.CtrlMdl)
loadDataFile(opts)
covRef = evalin('base','covRef');

% コントローラ親モデル
dvopts = sldvoptions(opts.CtrlMdl);
covdCtrlMdl = covRef.get(opts.CtrlMdl);
[~,newcovdCtrlMdl,filenames] = sldvgencov(opts.CtrlMdl,dvopts,true,covdCtrlMdl);
cvhtml(sprintf('%s/%s_totalcov.html',opts.ReportFolder,opts.CtrlMdl),covdCtrlMdl,newcovdCtrlMdl)

function getGenCovChild(opts) %#ok
% シミュレーションで不足した未到達要素を満たすテストを自動生成(ユニット:クルーズコントロール)

if ~evalin('base','exist(''covRef'',''var'')')
    warndlg(sprintf('covRefがワークスペースに見つかりません。%sのシミュレーションを先に実行する必要があります',opts.TopMdl))
    return;
end
open_system(opts.CtrlMdl)
loadDataFile(opts)
covRef = evalin('base','covRef');

% コントローラ子モデル
open_system(opts.CtrlChildMdl)
dvopts = sldvoptions(opts.CtrlChildMdl);
covdChildMdl = covRef.get(opts.CtrlChildMdl);
[~,newcovdChildMdl,filenames] = sldvgencov(opts.CtrlChildMdl,dvopts,true,covdChildMdl);
cvhtml(sprintf('%s_totalcov_child.html',opts.CtrlChildMdl),covdChildMdl,newcovdChildMdl)

function runTestGenerationParent(opts) %#ok
% 制御モデル全体に対してテストベクタを自動生成
 open_system(opts.CtrlMdl)
loadDataFile(opts)
dvopts = sldvoptions(opts.CtrlMdl);
sldvrun(opts.CtrlMdl,dvopts,true);

function runTestGenerationChild(opts) %#ok
% クルーズコントロールモデル(1ユニット)に対してテストベクタを自動生成(浮動小数点)
open_system(opts.CtrlChildMdl)
loadDataFile(opts)
dvopts = sldvoptions(opts.CtrlChildMdl);
sldvrun(opts.CtrlChildMdl,dvopts,true);

function runTestGenerationChildFixpt(opts) %#ok
% クルーズコントロールモデル(1ユニット)に対してテストベクタを自動生成(固定小数点)
open_system(opts.CtrlChildImplMdl)
loadFixedDataFile(opts)
dvopts = sldvoptions(opts.CtrlChildImplMdl);
sldvrun(opts.CtrlChildImplMdl,dvopts,true);

function makeTraceabilityReport(opts) %#ok
% トレーサビリティレポートの生成
open_system(opts.CtrlChildMdl)
loadDataFile(opts)
orgdir = pwd;
cd(opts.ReportFolder)
rmi('report', opts.CtrlChildMdl)
drawnow;
cd(orgdir)

function openReqSpec(opts) %#ok
% 要求仕様書を開く
system(['start ' opts.ReqSpec]);

function openModelAdvisor(opts) %#ok
% モデルアドバイザを開く
open_system(opts.CtrlMdl)
loadDataFile(opts)
modeladvisor(opts.CtrlMdl)

function runMAABCheck(opts)  %#ok
% モデルアドバイザチェック(MAABルール)の自動実行
open_system(opts.CtrlChildMdl)
loadDataFile(opts)

MdlAdvHandle = Simulink.ModelAdvisor.getModelAdvisor(opts.CtrlChildMdl,'new');
MdlAdvHandle.deselectCheckAll;
MdlAdvHandle.selectCheckForGroup('Simulink Verification and Validation|モデリング標準|MathWorks Automotive Advisory Board チェック');
MdlAdvHandle.runCheck;
reportfile = sprintf('%s/%s_modeladv.html',opts.ReportFolder,opts.CtrlMdl);
MdlAdvHandle.exportReport(reportfile);
web(reportfile)

function openMACustomChecks(opts) %#ok
% モデルアドバイザのカスタマイズファイルを開く
winopen(opts.CustomCheckFolder);

function openPropModelError(opts)  %#ok
% プロパティ検証モデル(不具合ありを開く
open_system(opts.PropModelError)
loadFloatDataFile(opts)

function runPropProveError(opts)  %#ok
% プロパティ検証を実行(不具合あり)

open_system(opts.PropModelError)
loadFloatDataFile(opts)
sldvopts=sldvoptions(opts.PropModelError);
sldvopts.Mode = 'PropertyProving';
sldvrun(opts.PropModelError,sldvopts,true)

function openPropModel(opts)  %#ok
% プロパティ検証モデル(不具合なし)を開く
open_system(opts.PropModel)
loadFloatDataFile(opts)

function runPropProve(opts)  %#ok
% プロパティ検証を実行(不具合なし)

open_system(opts.PropModel)
loadFloatDataFile(opts)
sldvopts=sldvoptions(opts.PropModel);
sldvopts.Mode = 'PropertyProving';
sldvrun(opts.PropModel,sldvopts,true)


function genCodeGenFloatModel(opts) %#ok
open_system(opts.CtrlChildImplMdl)
loadFloatDataFile(opts)
%% コード生成関連設定
% 浮動小数点コード生成
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','off')
% S-Functionの作成をしない
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% コード生成のみ
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')
try
    rtwbuild(opts.CtrlChildImplMdl)
catch ME
    switch ME.identifier
        case  'RTW:buildProcess:rtwinfomatmanBuildProcessStop'
            btn = questdlg('もう一度コードを生成しますか？','コード生成再実行','Yes','No');
            switch btn
                case 'Yes'
                    rtwbuild(opts.CtrlChildImplMdl)
                otherwise
                    return;
            end
    end
end

function genCodeGenFixedModel(opts) %#ok
open_system(opts.CtrlChildImplMdl)
loadFixedDataFile(opts)

%% コード生成関連設定
% 整数コード生成
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','on')
% S-Functionの作成をしない
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% コード生成のみ
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')

try
    rtwbuild(opts.CtrlChildImplMdl)
catch ME
    switch ME.identifier
        case  'RTW:buildProcess:rtwinfomatmanBuildProcessStop'
            btn = questdlg('もう一度コードを生成しますか？','コード生成再実行','Yes','No');
            switch btn
                case 'Yes'
                    rtwbuild(opts.CtrlChildImplMdl)
                otherwise
                    return;
            end
    end
end


function runTestGen_MILSIL_Back2BackReport_Fixed(opts) %#ok
% クルーズコントロールモデルに対する自動Back-to-backテスト実行とレポート
bdclose all
open_system(opts.CtrlChildImplMdl)
loadFixedDataFile(opts)
% 設定変更
% 整数コード生成
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','on')
% S-Functionの作成をしない
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% コード生成のみ
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')

sldvopts = sldvoptions(opts.CtrlChildImplMdl);
sldvopts.ModelReferenceHarness='on';

save_system(opts.CtrlChildImplMdl)
run_SLDV_testgen(opts.CtrlChildImplMdl,sldvopts)

% モデルカバレッジ測定
HarnessModel = [opts.CtrlChildImplMdl '_harness'];
run_Sim_GetCov(HarnessModel)
close_system(opts.CtrlChildImplMdl,0);
load_system(opts.CtrlChildImplMdl);

% MIL-SIL back-to-back test モデル作成
makeMILSILharness(HarnessModel);
MILSILModel = [opts.CtrlChildImplMdl '_MILSIL'];
save_system(HarnessModel,MILSILModel)

% テスト自動実行とレポート自動生成
obj = runCMTDReport([MILSILModel '/S_Function_Block']);
assignin('base','obj',obj)
evalin('base','obj.runSimAll;')
evalin('base','obj.runReport;')
evalin('base','system([obj.Setting.ReportFileName ''.doc''])')
