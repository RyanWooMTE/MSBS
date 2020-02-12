function removeUnConnectedLines(blk,LineInfo)
% delete lines if there are disconnected line(s)

%   Copyright 2012 The MathWorks, Inc. 

newlh = get_param(blk,'LineHandles');
PortHandles = get_param(blk,'PortHandles');
replh = [];

% Connects lines at first
for n=1:length(newlh.Inport)
    try
        if newlh.Inport(n) == -1 && numel(LineInfo.Inport) >= n && LineInfo.Inport(n) ~= -1
            SrcBlockHandle = get(LineInfo.Inport(n),'SrcPortHandle');
            delete_line(LineInfo.Inport(n))
            if SrcBlockHandle ~= -1
                replh(n) = add_line(get_param(blk,'Parent'),SrcBlockHandle,PortHandles.Inport(n),'autorouting','on');
            end
        end
    catch ME
        warning(ME.message)
    end
end

% Fix line positions after all lines are connected.
for n=1:length(replh)
    try
        if ishandle(replh(n)) && strcmp(get(replh(n),'type'),'line')
            set(replh(n),'Points',LineInfo.InportPos{n})
        end
    catch ME
        warning(ME.message)
    end
end
