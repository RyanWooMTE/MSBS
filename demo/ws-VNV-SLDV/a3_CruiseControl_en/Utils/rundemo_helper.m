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
% �R���g���[�����f�����J��
open_system(opts.CtrlMdl)
loadDataFile(opts)

function openCtrlChildMdl(opts)  %#ok
% �R���g���[���q���f�����J��
open_system(opts.CtrlChildMdl)
loadDataFile(opts)

function loadDataFile(opts)
% �f�[�^�t�@�C�������[�h����
for n=1:length(opts.DataFile)
    evalin('base',opts.DataFile{n})
end

function loadFloatDataFile(opts)
% �f�[�^�t�@�C�������[�h����(float)
for n=1:length(opts.FloatDataFile)
    evalin('base',opts.FloatDataFile{n})
end

function loadFixedDataFile(opts)
% �f�[�^�t�@�C�������[�h����(fixed)
for n=1:length(opts.FixptDataFile)
    evalin('base',opts.FixptDataFile{n})
end

function openTopModel(opts) %#ok
% �V�X�e�����x�����f�����J��
open_system(opts.TopMdl)
loadDataFile(opts)

function runSimMesureCov(opts) %#ok
% �V�~�����[�V���������s���J�o���b�W�𑪒�
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
% �V�~�����[�V�����ŕs�����������B�v�f�𖞂����e�X�g����������(���䃂�f���S��)
if ~evalin('base','exist(''covRef'',''var'')')
    warndlg(sprintf('covRef�����[�N�X�y�[�X�Ɍ�����܂���B%s�̃V�~�����[�V�������Ɏ��s����K�v������܂�',opts.TopMdl))
    return;
end
open_system(opts.CtrlMdl)
loadDataFile(opts)
covRef = evalin('base','covRef');

% �R���g���[���e���f��
dvopts = sldvoptions(opts.CtrlMdl);
covdCtrlMdl = covRef.get(opts.CtrlMdl);
[~,newcovdCtrlMdl,filenames] = sldvgencov(opts.CtrlMdl,dvopts,true,covdCtrlMdl);
cvhtml(sprintf('%s/%s_totalcov.html',opts.ReportFolder,opts.CtrlMdl),covdCtrlMdl,newcovdCtrlMdl)

function getGenCovChild(opts) %#ok
% �V�~�����[�V�����ŕs�����������B�v�f�𖞂����e�X�g����������(���j�b�g:�N���[�Y�R���g���[��)

if ~evalin('base','exist(''covRef'',''var'')')
    warndlg(sprintf('covRef�����[�N�X�y�[�X�Ɍ�����܂���B%s�̃V�~�����[�V�������Ɏ��s����K�v������܂�',opts.TopMdl))
    return;
end
open_system(opts.CtrlMdl)
loadDataFile(opts)
covRef = evalin('base','covRef');

% �R���g���[���q���f��
open_system(opts.CtrlChildMdl)
dvopts = sldvoptions(opts.CtrlChildMdl);
covdChildMdl = covRef.get(opts.CtrlChildMdl);
[~,newcovdChildMdl,filenames] = sldvgencov(opts.CtrlChildMdl,dvopts,true,covdChildMdl);
cvhtml(sprintf('%s_totalcov_child.html',opts.CtrlChildMdl),covdChildMdl,newcovdChildMdl)

function runTestGenerationParent(opts) %#ok
% ���䃂�f���S�̂ɑ΂��ăe�X�g�x�N�^����������
 open_system(opts.CtrlMdl)
loadDataFile(opts)
dvopts = sldvoptions(opts.CtrlMdl);
sldvrun(opts.CtrlMdl,dvopts,true);

function runTestGenerationChild(opts) %#ok
% �N���[�Y�R���g���[�����f��(1���j�b�g)�ɑ΂��ăe�X�g�x�N�^����������(���������_)
open_system(opts.CtrlChildMdl)
loadDataFile(opts)
dvopts = sldvoptions(opts.CtrlChildMdl);
sldvrun(opts.CtrlChildMdl,dvopts,true);

function runTestGenerationChildFixpt(opts) %#ok
% �N���[�Y�R���g���[�����f��(1���j�b�g)�ɑ΂��ăe�X�g�x�N�^����������(�Œ菬���_)
open_system(opts.CtrlChildImplMdl)
loadFixedDataFile(opts)
dvopts = sldvoptions(opts.CtrlChildImplMdl);
sldvrun(opts.CtrlChildImplMdl,dvopts,true);

function makeTraceabilityReport(opts) %#ok
% �g���[�T�r���e�B���|�[�g�̐���
open_system(opts.CtrlChildMdl)
loadDataFile(opts)
orgdir = pwd;
cd(opts.ReportFolder)
rmi('report', opts.CtrlChildMdl)
drawnow;
cd(orgdir)

function openReqSpec(opts) %#ok
% �v���d�l�����J��
system(['start ' opts.ReqSpec]);

function openModelAdvisor(opts) %#ok
% ���f���A�h�o�C�U���J��
open_system(opts.CtrlMdl)
loadDataFile(opts)
modeladvisor(opts.CtrlMdl)

function runMAABCheck(opts)  %#ok
% ���f���A�h�o�C�U�`�F�b�N(MAAB���[��)�̎������s
open_system(opts.CtrlChildMdl)
loadDataFile(opts)

MdlAdvHandle = Simulink.ModelAdvisor.getModelAdvisor(opts.CtrlChildMdl,'new');
MdlAdvHandle.deselectCheckAll;
MdlAdvHandle.selectCheckForGroup('Simulink Verification and Validation|���f�����O�W��|MathWorks Automotive Advisory Board �`�F�b�N');
MdlAdvHandle.runCheck;
reportfile = sprintf('%s/%s_modeladv.html',opts.ReportFolder,opts.CtrlMdl);
MdlAdvHandle.exportReport(reportfile);
web(reportfile)

function openMACustomChecks(opts) %#ok
% ���f���A�h�o�C�U�̃J�X�^�}�C�Y�t�@�C�����J��
winopen(opts.CustomCheckFolder);

function openPropModelError(opts)  %#ok
% �v���p�e�B���؃��f��(�s�������J��
open_system(opts.PropModelError)
loadFloatDataFile(opts)

function runPropProveError(opts)  %#ok
% �v���p�e�B���؂����s(�s�����)

open_system(opts.PropModelError)
loadFloatDataFile(opts)
sldvopts=sldvoptions(opts.PropModelError);
sldvopts.Mode = 'PropertyProving';
sldvrun(opts.PropModelError,sldvopts,true)

function openPropModel(opts)  %#ok
% �v���p�e�B���؃��f��(�s��Ȃ�)���J��
open_system(opts.PropModel)
loadFloatDataFile(opts)

function runPropProve(opts)  %#ok
% �v���p�e�B���؂����s(�s��Ȃ�)

open_system(opts.PropModel)
loadFloatDataFile(opts)
sldvopts=sldvoptions(opts.PropModel);
sldvopts.Mode = 'PropertyProving';
sldvrun(opts.PropModel,sldvopts,true)


function genCodeGenFloatModel(opts) %#ok
open_system(opts.CtrlChildImplMdl)
loadFloatDataFile(opts)
%% �R�[�h�����֘A�ݒ�
% ���������_�R�[�h����
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','off')
% S-Function�̍쐬�����Ȃ�
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% �R�[�h�����̂�
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')
try
    rtwbuild(opts.CtrlChildImplMdl)
catch ME
    switch ME.identifier
        case  'RTW:buildProcess:rtwinfomatmanBuildProcessStop'
            btn = questdlg('������x�R�[�h�𐶐����܂����H','�R�[�h�����Ď��s','Yes','No');
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

%% �R�[�h�����֘A�ݒ�
% �����R�[�h����
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','on')
% S-Function�̍쐬�����Ȃ�
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% �R�[�h�����̂�
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')

try
    rtwbuild(opts.CtrlChildImplMdl)
catch ME
    switch ME.identifier
        case  'RTW:buildProcess:rtwinfomatmanBuildProcessStop'
            btn = questdlg('������x�R�[�h�𐶐����܂����H','�R�[�h�����Ď��s','Yes','No');
            switch btn
                case 'Yes'
                    rtwbuild(opts.CtrlChildImplMdl)
                otherwise
                    return;
            end
    end
end


function runTestGen_MILSIL_Back2BackReport_Fixed(opts) %#ok
% �N���[�Y�R���g���[�����f���ɑ΂��鎩��Back-to-back�e�X�g���s�ƃ��|�[�g
bdclose all
open_system(opts.CtrlChildImplMdl)
loadFixedDataFile(opts)
% �ݒ�ύX
% �����R�[�h����
set_param(opts.CtrlChildImplMdl,'PurelyIntegerCode','on')
% S-Function�̍쐬�����Ȃ�
set_param(opts.CtrlChildImplMdl,'GenerateErtSFunction','off')
% �R�[�h�����̂�
set_param(opts.CtrlChildImplMdl,'GenCodeOnly','on')

sldvopts = sldvoptions(opts.CtrlChildImplMdl);
sldvopts.ModelReferenceHarness='on';

save_system(opts.CtrlChildImplMdl)
run_SLDV_testgen(opts.CtrlChildImplMdl,sldvopts)

% ���f���J�o���b�W����
HarnessModel = [opts.CtrlChildImplMdl '_harness'];
run_Sim_GetCov(HarnessModel)
close_system(opts.CtrlChildImplMdl,0);
load_system(opts.CtrlChildImplMdl);

% MIL-SIL back-to-back test ���f���쐬
makeMILSILharness(HarnessModel);
MILSILModel = [opts.CtrlChildImplMdl '_MILSIL'];
save_system(HarnessModel,MILSILModel)

% �e�X�g�������s�ƃ��|�[�g��������
obj = runCMTDReport([MILSILModel '/S_Function_Block']);
assignin('base','obj',obj)
evalin('base','obj.runSimAll;')
evalin('base','obj.runReport;')
evalin('base','system([obj.Setting.ReportFileName ''.doc''])')
