function removeConnectedLines(blk,handleInfo)

%   Copyright 2012 The MathWorks, Inc. 

if ~isempty(handleInfo)
    for nh = 1:length(handleInfo)
        for m=1:length(handleInfo{nh})
            try
                switch get(handleInfo{nh}(m),'Type')
                    case 'line'
                        delete_line(handleInfo{nh}(m))
                    case 'block'
                        delete_block(handleInfo{nh}(m))
                end
            catch
                % do nothing
            end
        end
    end
else
    % In case of normal line, just delete them
    lh = get_param(blk,'LineHandles');
    for n=1:length(lh.Inport)
        if lh.Inport(n) ~= -1
            delete_line(lh.Inport(n))
        end
    end    
end