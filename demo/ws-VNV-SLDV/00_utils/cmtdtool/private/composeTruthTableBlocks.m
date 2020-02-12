function sys = composeTruthTableBlocks(sys,testObjTT,proofObjTT,InputVal,OutValA)
% composeTruthTableBlocks is a utility function used by requirement-based
% test and test objective capabilities.

%   Copyright 2012 The MathWorks, Inc.


% adding inport blocks
mdl = getfullname(sys);
for n=1:length(InputVal)
    inbh(n) = add_block('simulink/Sources/In1',sprintf('%s/%s',mdl,InputVal{n}));
end
for n=1:length(OutValA)
    inbh(end+1) = add_block('simulink/Sources/In1',sprintf('%s/%s',mdl,OutValA{n}));
end
% for n=1:length(inbh)
%     set_param(inbh(n),'Position',[10,20+(n-1)*40,40,35+(n-1)*40]);
% end

% size adjusting
HightA = length(InputVal)*30;
HightB = (length(InputVal)+length(OutValA))*30;
set_param(testObjTT,'Position',[200 30 300 HightA+30+20])
set_param(proofObjTT,'Position',[200 HightA+70 300 HightA+90+HightB])
posSys = get_param(sys,'Position');
set_param(sys,'Position',[posSys(1) posSys(2) posSys(1)+100 posSys(2)+HightB]);

% compare and assertion block
ctcb = add_block(sprintf('simulink/Logic and Bit\nOperations/Compare\nTo Zero'),sprintf('%s/CTD',mdl));
set_param(ctcb,'relop','==');
prfh = add_block(sprintf('simulink/Model\nVerification/Assertion'),sprintf('%s/Proof',mdl));
set_param(prfh,'StopWhenAssertionFail','off');
phb = get_param(proofObjTT,'PortHandles');
posproofObjTT = get(phb.Outport,'Position');
set_param(ctcb,'Position',[330,posproofObjTT(2)-15,360,posproofObjTT(2)+15])
set_param(prfh,'Position',[390,posproofObjTT(2)-15,420,posproofObjTT(2)+15])

ann = find_system(sys,'LookUnderMasks','on','FindAll','on','type','annotation');
delete(ann);

for n=1:length(inbh)
    lh(n) = add_line(mdl,sprintf('%s/1',get_param(inbh(n),'Name')),...
        getInputPortNameTT(proofObjTT,get_param(inbh(n),'Name')),'autorouting','on');
    oPos = get_param(inbh(n),'Position');
    olh = get_param(inbh(n),'LineHandles');
    pPos = get(get(olh.Outport,'DstPortHandle'),'Position');
    set_param(inbh(n),'Position',[oPos(1),pPos(2)-7,oPos(3),pPos(2)+7])
end
for n=1:length(InputVal)
    lh(n) = add_line(mdl,sprintf('%s/1',get_param(inbh(n),'Name')),...
        getInputPortNameTT(testObjTT,get_param(inbh(n),'Name')),'autorouting','on');
end

lh1 = add_line(mdl,sprintf('%s/1',get_param(proofObjTT,'Name')),sprintf('%s/1',get_param(ctcb,'Name')),'autorouting','on');
set(lh1,'Name','Exp_output')
lh2 = add_line(mdl,sprintf('%s/1',get_param(ctcb,'Name')),sprintf('%s/1',get_param(prfh,'Name')),'autorouting','on');
set(lh2,'Name','Assertion_ReqTest')


refreshAllLines(mdl)
fixLineOverlap(mdl)
end

function str = getInputPortNameTT(TruthTableBlockH,PortName)
% a helper function to get port name to use add_line

ttBlockName = get_param(TruthTableBlockH,'Name');
rt = sfroot;
ttobj = rt.find('-isa', 'Stateflow.TruthTableChart', 'Path', getfullname(TruthTableBlockH));
data = ttobj.find('-isa','Stateflow.Data','Name',PortName);
str = sprintf('%s/%d',ttBlockName,data.Port);

end
