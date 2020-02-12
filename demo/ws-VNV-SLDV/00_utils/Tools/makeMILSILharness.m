function SigNames=makeMILSILharness(harnmdl)
% SLDV�̃e�X�g�n�[�l�X��p����MILS/SILS�̈�v�����؂��s���n�[�l�X���f�����쐬
% Usage:
% makeMILSILharness(modelName) : 
%    modelName�ɑ΂��Č��؃��f�����쐬

%   Copyright 2012 The MathWorks, Inc. 

%% ���͈����̏���

isSLDVHarness=false;
isModelRefHarness = false;

load_system(harnmdl)
% ���f�����w�肳�ꂽ�ꍇ��SLDV�̃e�X�g�n�[�l�X�Ȃ̂Ńe�X�g���j�b�g����肷��
TestUnitN = find_system(harnmdl,'RegExp','on','Name','Test Unit.*');
if isempty(TestUnitN)
    errordlg('Simulink Design Verifier �ō쐬���ꂽ�e�X�g�n�[�l�X���w�肵�Ă��������B')
    return;
end
TestUnitN=TestUnitN{1};
if strcmp(get_param(TestUnitN,'BlockType'),'ModelReference')
    targetModel = get_param(TestUnitN,'ModelName');
    load_system(targetModel);
    isModelRefHarness = true;
else
    % �������݉\��
    set_param(TestUnitN,'Permissions','ReadWrite');
    isSLDVHarness=true;
    targetModel = bdroot(harnmdl);
end

TestUnitH=get_param(TestUnitN,'Handle');


%% Configuration Parameters��S-function�����p�ɐݒ�

% ERT�ɕύX
set_param(targetModel,'SystemTargetFile','ert.tlc')
set_param(targetModel,'InitFcn','')
set_param(targetModel,'EnableUserReplacementTypes','off')
set_param(targetModel,'GenerateMakefile','on')
set_param(targetModel,'RTWGenerateCodeOnly','off')
set_param(targetModel,'GenerateErtSFunction','on')
set_param(targetModel,'RTWVerbose','on')
InitScr=get_param(harnmdl,'InitFcn');

if isSLDVHarness
    trg_m=find_system(TestUnitN,'SearchDepth',1,'blockType','SubSystem');
    repblockH=rtwbuild(trg_m{2});
elseif isModelRefHarness
    try
        repblockH=rtwbuild(targetModel);
    catch ME
        switch ME.identifier
            case  'RTW:buildProcess:rtwinfomatmanBuildProcessStop'
                btn = questdlg('������x�R�[�h�𐶐����܂����H','�R�[�h�����Ď��s','Yes','No');
                switch btn
                    case 'Yes'
                        repblockH=rtwbuild(targetModel);
                    otherwise
                        return;
                end
            case 'RTW:buildProcess:slprjVerIncompatibleCmdLine'
                btn = questdlg('slprj�t�H���_���폜��������x�R�[�h�𐶐����܂����H','�R�[�h�����Ď��s','Yes','No');
                switch btn
                    case 'Yes'
                        rmdir('slprj','s')
                        repblockH=rtwbuild(targetModel);
                    otherwise
                        return;
                end
            otherwise
                rethrow(ME)
        end
    end

else
  repblockH=rtwbuild(TestUnitN);
end
 repblockN=getfullname(repblockH);


if isempty(repblockN)
    blks=find_system('BlockType','S-Function');
    blki=strfind(blks,'untitled');
    for n=1:length(blki)
        if ~isempty(blki{n})
            repblockN=blks{n};
        end
    end            
end
%% Sfunction�u���b�N��ǉ�

opos = get_param(TestUnitN,'Position');
Height = abs(opos(4)-opos(2));

sfnblockH = add_block(getfullname(repblockN),[harnmdl '/S_Function_Block'],...
    'Position',[opos(1) opos(4)+30 opos(3) opos(4)+30+Height]);
sfnblockN = getfullname(sfnblockH);
phandlessfn=get(sfnblockH,'PortHandles');
OutPortHsfn=phandlessfn.Outport;
close_system(bdroot(repblockN),0); % SFcn�u���b�N������

%% �o�͂Ɋւ���ݒ�
phandles=get_param(TestUnitN,'PortHandles');
OutPortHmdl=phandles.Outport;
if isModelRefHarness
    [inP,outP]=getPortNumRelation(targetModel,sfnblockN);
else
    [inP,outP]=getPortNumRelation(TestUnitN,sfnblockN);
end
for n=1:length(OutPortHmdl)
    % Add�u���b�N��z�u
    substblkH{n} = add_block('built-in/Sum',[harnmdl '/Add' num2str(n)],...
        'Inputs','-+','OutDataTypeStr','double','AccumDataTypeStr','double');
    addpos=(get(OutPortHmdl(n),'Position')+get(OutPortHsfn(n),'Position'))/2 ;
    set_param(substblkH{n},'Position',[addpos addpos+[20 20]]+ [50 0 50 0]);
    substblkN{n}=getfullname(substblkH{n});
    
    % ���f������̏o�͂�Add�u���b�N��1�Ԗڂɐڑ�
    add_line(harnmdl,sprintf('%s/%d',get(TestUnitH,'Name'),outP(n).Model),[get(substblkH{n},'Name') '/1'],'autorouting','on')
    SigNames.ModelOut{n}=setSigNameandLogSig(TestUnitN,n,sprintf('Exp_%s_Model',outP(n).Name),'Outport');
    
    % SFcn����̏o�͂�Add�u���b�N��2�Ԗڂɐڑ�
    add_line(harnmdl,sprintf('%s/%d',get(sfnblockH,'Name'),outP(n).SFcn),[get(substblkH{n},'Name') '/2'],'autorouting','on')
    SigNames.SfcnOut{n}=setSigNameandLogSig(sfnblockN,outP(n).SFcn,sprintf('%s_SFcn',outP(n).Name),'Outport');

    % Compare To Zero
    CTZBlkN{n}= add_block(sprintf('simulink/Logic and Bit\nOperations/Compare\nTo Zero'),[harnmdl '/CTZ' num2str(n)],'MAKENAMEUNIQUE','ON');
    set_param(CTZBlkN{n},'relop','==')
    set_param(CTZBlkN{n},'Position',get_param(substblkH{n},'Position')+[50 0 50 0])
    add_line(harnmdl,[get(substblkH{n},'Name') '/1'],sprintf('%s/%d',get_param(CTZBlkN{n},'Name'),1),'autorouting','on')

    % Assertion block
    AssertopmBlkN{n}=add_block('built-in/Assertion',[harnmdl '/Assertion' num2str(n)],'MAKENAMEUNIQUE','ON');
    set_param(AssertopmBlkN{n},'StopWhenAssertionFail','off')
    AssertionPortBlkH(n)=get_param(AssertopmBlkN{n},'Handle');
    % Outport�u���b�N���獷�����o�͂���(�I���W�i�����ړ����čė��p)
   set_param(AssertopmBlkN{n},'Position',get_param(substblkH{n},'Position')+[100 0 100 0])
    add_line(harnmdl,[get_param(CTZBlkN{n},'Name') '/1'],sprintf('%s/%d',get(AssertionPortBlkH(n),'Name'),1),'autorouting','on')
    SigNames.Diff{n}=setSigNameandLogSig(AssertopmBlkN{n},1,sprintf('Assertion_%s',outP(n).Name),'Inport');
end

%% ���͂Ɋւ���ݒ�
if isSLDVHarness
SizeTypeblkN = find_system(harnmdl,'SearchDepth',1,'Name','Size-Type');
    SizeTypeblkN = SizeTypeblkN{1};
    LineH=get_param(SizeTypeblkN,'LineHandles');
    for n=1:length(LineH.Outport)
        add_line(harnmdl,sprintf('%s/%d',get_param(SizeTypeblkN,'Name'),n),...
            sprintf('%s/%d',get_param(sfnblockN,'Name'),inP(n).SFcn),'autorouting','on')
        SigNames.In{n}=setSigNameandLogSig(TestUnitN,n,sprintf('%s',inP(n).Name),'Inport');
    end
else
    LineH=get_param(TestUnitN,'LineHandles');
    PortH=get_param(TestUnitN,'PortHandles');
    for n=1:length(LineH.Inport)
        srcBlckH = get(LineH.Inport(n),'SrcBlockHandle');
        add_line(harnmdl,...
        sprintf('%s/%d',get(srcBlckH,'Name'),...
        get(PortH.Inport(n),'PortNumber')),...
            sprintf('%s/%d',get_param(sfnblockN,'Name'),inP(n).SFcn),'autorouting','on')
        SigNames.In{n}=setSigNameandLogSig(TestUnitN,n,sprintf('%s',inP(n).Name),'Inport');
    end 
end
set_param(harnmdl,'InitFcn',InitScr);
set_param(harnmdl,'AssertionControl','EnableAll')
% �ʖ��ŕۑ�
if exist('harnessmodel','var')
    save_system(harnmdl,harnessmodel)
end

% end of function

function SigName=setSigNameandLogSig(blkN,NumSig,SigName,blockType)
% �M������t���M�����M���O��ON�ɐݒ肷��
% blkN���T�u�V�X�e���̏ꍇ�ɂ́A�T�u�V�X�e������blockType�Ŏw�肳�ꂽ�u���b�N��
% ��M�����ɐݒ肷��BOutport�u���b�N�̏ꍇ�͂��̃u���b�N�����M�����ƂȂ�

LineH=getfield(get_param(blkN,'LineHandles'),blockType);

set(LineH(NumSig),'Name',SigName)

      
function [inP,outP]=getPortNumRelation(TestUnitN,sfnblockN)
% ���f����S-function��Inport,Outport�̑Ή��֌W�𒲂ׂ�
% RTW-EC�ō쐬�����S-Function�u���b�N�͕K�������A���̃��f���̃|�[�g�ԍ��̏���
% �|�[�g������U����킯�ł͂Ȃ����߁A������C������

if ishandle(TestUnitN)
    TestUnitN=getfullname(TestUnitN);
end 
if ishandle(sfnblockN)
    sfnblockN=getfullname(sfnblockN);
end 
inblksM = find_system(TestUnitN,'SearchDepth',1,'LookUnderMasks','all','blockType','Inport');
inblksS = find_system(sfnblockN,'SearchDepth',1,'LookUnderMasks','all','blockType','Inport');

for n=1:length(inblksM)
    pnumM = str2double(get_param(inblksM{n},'Port'));
    pnumS=pnumM;
    for m=1:length(inblksS)
        if strcmp(get_param(inblksM{n},'Name'),get_param(inblksS{m},'Name'))
            pnumS = m;
        end
    end
    inP(n).Name = get_param(inblksM{n},'Name');
    inP(n).Model = pnumM;
    inP(n).SFcn = pnumS;
end

outblksM = find_system(TestUnitN,'SearchDepth',1,'LookUnderMasks','all','blockType','Outport');
outblksS = find_system(sfnblockN,'SearchDepth',1,'LookUnderMasks','all','blockType','Outport');

for n=1:length(outblksM)
    pnumM = str2double(get_param(outblksM{n},'Port'));
    pnumS = pnumM;
    for m=1:length(outblksS)
        if strcmp(get_param(outblksM{n},'Name'),get_param(outblksS{m},'Name'))
            pnumS = m;
        end
    end
    outP(n).Name = get_param(outblksM{n},'Name');
    outP(n).Model = pnumM;
    outP(n).SFcn = pnumS;
end
