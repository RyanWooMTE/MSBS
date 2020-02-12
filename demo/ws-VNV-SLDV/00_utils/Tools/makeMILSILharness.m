function SigNames=makeMILSILharness(harnmdl)
% SLDVのテストハーネスを用いてMILS/SILSの一致性検証を行うハーネスモデルを作成
% Usage:
% makeMILSILharness(modelName) : 
%    modelNameに対して検証モデルを作成

%   Copyright 2012 The MathWorks, Inc. 

%% 入力引数の処理

isSLDVHarness=false;
isModelRefHarness = false;

load_system(harnmdl)
% モデルが指定された場合はSLDVのテストハーネスなのでテストユニットを特定する
TestUnitN = find_system(harnmdl,'RegExp','on','Name','Test Unit.*');
if isempty(TestUnitN)
    errordlg('Simulink Design Verifier で作成されたテストハーネスを指定してください。')
    return;
end
TestUnitN=TestUnitN{1};
if strcmp(get_param(TestUnitN,'BlockType'),'ModelReference')
    targetModel = get_param(TestUnitN,'ModelName');
    load_system(targetModel);
    isModelRefHarness = true;
else
    % 書き込み可能に
    set_param(TestUnitN,'Permissions','ReadWrite');
    isSLDVHarness=true;
    targetModel = bdroot(harnmdl);
end

TestUnitH=get_param(TestUnitN,'Handle');


%% Configuration ParametersをS-function生成用に設定

% ERTに変更
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
                btn = questdlg('もう一度コードを生成しますか？','コード生成再実行','Yes','No');
                switch btn
                    case 'Yes'
                        repblockH=rtwbuild(targetModel);
                    otherwise
                        return;
                end
            case 'RTW:buildProcess:slprjVerIncompatibleCmdLine'
                btn = questdlg('slprjフォルダを削除しもう一度コードを生成しますか？','コード生成再実行','Yes','No');
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
%% Sfunctionブロックを追加

opos = get_param(TestUnitN,'Position');
Height = abs(opos(4)-opos(2));

sfnblockH = add_block(getfullname(repblockN),[harnmdl '/S_Function_Block'],...
    'Position',[opos(1) opos(4)+30 opos(3) opos(4)+30+Height]);
sfnblockN = getfullname(sfnblockH);
phandlessfn=get(sfnblockH,'PortHandles');
OutPortHsfn=phandlessfn.Outport;
close_system(bdroot(repblockN),0); % SFcnブロックを消去

%% 出力に関する設定
phandles=get_param(TestUnitN,'PortHandles');
OutPortHmdl=phandles.Outport;
if isModelRefHarness
    [inP,outP]=getPortNumRelation(targetModel,sfnblockN);
else
    [inP,outP]=getPortNumRelation(TestUnitN,sfnblockN);
end
for n=1:length(OutPortHmdl)
    % Addブロックを配置
    substblkH{n} = add_block('built-in/Sum',[harnmdl '/Add' num2str(n)],...
        'Inputs','-+','OutDataTypeStr','double','AccumDataTypeStr','double');
    addpos=(get(OutPortHmdl(n),'Position')+get(OutPortHsfn(n),'Position'))/2 ;
    set_param(substblkH{n},'Position',[addpos addpos+[20 20]]+ [50 0 50 0]);
    substblkN{n}=getfullname(substblkH{n});
    
    % モデルからの出力をAddブロックの1番目に接続
    add_line(harnmdl,sprintf('%s/%d',get(TestUnitH,'Name'),outP(n).Model),[get(substblkH{n},'Name') '/1'],'autorouting','on')
    SigNames.ModelOut{n}=setSigNameandLogSig(TestUnitN,n,sprintf('Exp_%s_Model',outP(n).Name),'Outport');
    
    % SFcnからの出力をAddブロックの2番目に接続
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
    % Outportブロックから差分を出力する(オリジナルを移動して再利用)
   set_param(AssertopmBlkN{n},'Position',get_param(substblkH{n},'Position')+[100 0 100 0])
    add_line(harnmdl,[get_param(CTZBlkN{n},'Name') '/1'],sprintf('%s/%d',get(AssertionPortBlkH(n),'Name'),1),'autorouting','on')
    SigNames.Diff{n}=setSigNameandLogSig(AssertopmBlkN{n},1,sprintf('Assertion_%s',outP(n).Name),'Inport');
end

%% 入力に関する設定
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
% 別名で保存
if exist('harnessmodel','var')
    save_system(harnmdl,harnessmodel)
end

% end of function

function SigName=setSigNameandLogSig(blkN,NumSig,SigName,blockType)
% 信号名を付け信号ロギングをONに設定する
% blkNがサブシステムの場合には、サブシステム内のblockTypeで指定されたブロック名
% を信号名に設定する。Outportブロックの場合はそのブロック名が信号名となる

LineH=getfield(get_param(blkN,'LineHandles'),blockType);

set(LineH(NumSig),'Name',SigName)

      
function [inP,outP]=getPortNumRelation(TestUnitN,sfnblockN)
% モデルとS-functionのInport,Outportの対応関係を調べる
% RTW-ECで作成されるS-Functionブロックは必ずしも、元のモデルのポート番号の順に
% ポートが割り振られるわけではないため、それを修正する

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
