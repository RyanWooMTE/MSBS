function refreshAllLines(sys)

%   Copyright 2012 The MathWorks, Inc. 

allblks = find_system(sys,'SearchDepth',1,'LookUnderMasks','on','FollowLinks','on');
allblks(strcmp(allblks,sys))=[];


%% delete all lines and reconnect them
iStr={};
oStr={};
nLine = 1;
if isempty(allblks)
    return;
end
for n=1:length(allblks)
    
    lh = get_param(allblks{n},'LineHandles');
    for k=1:length(lh.Inport)
        srcPH = get(lh.Inport(k),'SrcPortHandle');
        srcBH = get(lh.Inport(k),'SrcBlockHandle');
        dstPH = get(lh.Inport(k),'DstPortHandle');
        dstBH = get(lh.Inport(k),'DstBlockHandle');
        iStr{nLine} = sprintf('%s/%d',get(srcBH,'Name'),get(srcPH,'PortNumber'));
        oStr{nLine} = sprintf('%s/%d',get(dstBH,'Name'),get(dstPH,'PortNumber'));
        Pnts = get(lh.Inport(k),'Points');

        sPortPos = get(srcPH,'Position');
        dPortPos = get(dstPH,'Position');
        LineLength(nLine) = (sPortPos(1)-dPortPos(1)).^2 + (sPortPos(2)-dPortPos(2)).^2;
        nLine = nLine+1;
    end
    %fprintf('%s : %s\n',iStr,oStr)
end


for n=1:length(allblks)
    lh = get_param(allblks{n},'LineHandles');
    delete_line(lh.Inport)
    ShowNameSetting{n} = get_param(allblks{n},'ShowName');
    set_param(allblks{n},'ShowName','off')
end
[~,idx]=sort(LineLength);
for n=1:length(iStr)
    add_line(sys,iStr{idx(n)},oStr{idx(n)}, 'autorouting','on')
end

for n=1:length(allblks)
    set_param(allblks{n},'ShowName',ShowNameSetting{n})
end
