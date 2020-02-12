function BlockAutoAlign(btree,sys)
% BlockAutoAlign moves blocks in Equation2Simulink block based on BlockTree
%

%   Copyright 2012 The MathWorks, Inc. 

HorizSpace = 120;
VertSpace = 70;

orgBlk = find_system(sys,'SearchDepth',1,'LookUnderMasks','on','FollowLinks','on','BlockType','Outport');
orgBlk = orgBlk{1};

maxX = 0;
maxY = 0;

for nBlk=1:length(btree.elem)
    posX = btree.elem(nBlk).depth+1;
    if btree.elem(nBlk).depth == 0 % outport
        posY = 1;
    elseif btree.elem(nBlk).depth == 1 % right-most
        posY = 1;
    elseif btree.elem(nBlk).depth -1 == btree.elem(nBlk-1).depth % prev block is parent
        tmpPosY = btree.elem(nBlk-1).posY;
        while checkSamePos(btree,posX,tmpPosY)
            tmpPosY = tmpPosY + 1;
        end 
        posY = tmpPosY;
    else % parent block is far
        parentBlkPortNum = 0;      
        for n=nBlk-1:-1:1
            if btree.elem(nBlk).depth == btree.elem(n).depth
                parentBlkPortNum = parentBlkPortNum+1;
            end
            if btree.elem(nBlk).depth -1 == btree.elem(n).depth
                parentPosY = btree.elem(btree.elem(nBlk).parentNum).posY;
                tmpPosY = parentPosY + parentBlkPortNum;
                while checkSamePos(btree,posX,tmpPosY)
                    tmpPosY = tmpPosY + 1;
                end
                posY = tmpPosY;
                break;
            end
        end
    end
    
    btree.elem(nBlk).posX = posX;
    btree.elem(nBlk).posY = posY;
    posM(posX,posY) = nBlk;
    if maxX < btree.elem(nBlk).posX
       maxX = btree.elem(nBlk).posX;
    end 
    if maxY < btree.elem(nBlk).posY
       maxY = btree.elem(nBlk).posY;
    end 
    vposX(nBlk) = posX;
end
maxXpos = 0;
maxYpos = 0;
for n=1:length(btree.elem)
    if isempty(btree.elem(n).blockPath)
        continue;
    end
    orgPos = get_param(btree.elem(n).blockPath,'Position');
    Height = abs(orgPos(4) - orgPos(2));
    Width = abs(orgPos(3) - orgPos(1));
    
    xPos = HorizSpace*(maxX-btree.elem(n).posX+1);
    
    yPos = VertSpace*btree.elem(n).posY;
    set_param(btree.elem(n).blockPath,'Position',...
        [xPos yPos-Height/2 xPos+Width yPos+Height/2]);
    newPos = get_param(btree.elem(n).blockPath,'Position');
    if newPos(3) > maxXpos
        maxXpos = newPos(3);
    end
    if newPos(4) > maxYpos
        maxYpos = newPos(4);
    end
end

% 前段のブロックのポート位置をそろえる
% [~,idx] = sort(vposX,'descend');
% 
% for n=idx
%     if btree.elem(n).parentBlkPortNum == 1
%         lh = get_param(btree.elem(n).blockPath,'LineHandles');
%         ph = get_param(btree.elem(n).blockPath,'PortHandles');
%         portPos = get(ph.Outport(1),'Position');
%         parentBlockHandle = get(lh.Outport(1),'DstBlockHandle');
%         parentPortHandle = get(lh.Outport(1),'DstPortHandle');
%         % considering two or more parents
%         parentPortPos = get(parentPortHandle(1),'Position'); 
%         deltaY = portPos(2)-parentPortPos(2);
%         parentPos = get_param(parentBlockHandle(1),'Position');
%         set_param(parentBlockHandle,'Position',...
%             [parentPos(1),parentPos(2)+deltaY,parentPos(3),parentPos(4)+deltaY])
%     end 
% end

% set block location so that all blocks can see
% orgLoc = get_param(get_param(btree.elem(1).blockPath,'Parent'),'Location');
% set_param(get_param(btree.elem(1).blockPath,'Parent'),'Location',...
%     [orgLoc(1),orgLoc(2),orgLoc(1)+maxXpos+30,orgLoc(2)+maxYpos+30]);
%showBtree(btree)

function out = checkSamePos(btree,xPos,yPos)
out = false;
for n=1:length(btree.elem)
    
    if ~isempty(btree.elem(n).posX) && btree.elem(n).posX == xPos ...
            && ~isempty(btree.elem(n).posY) && btree.elem(n).posY == yPos
        out = true;
        break;
    end
end


