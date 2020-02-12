function objs = validateIndexPortsInSimulinkBlocks(block, indexPorts, indexPortDatatypes, objs)

    [isValid, objs.invalidDataTypeIndices] = validateIndexDataType(block, indexPorts, indexPortDatatypes, objs.invalidDataTypeIndices);
    if isValid
        objs.invalidRangeIndices = validateIndexDataTypeRange(block, indexPorts, indexPortDatatypes, objs.invalidRangeIndices);   
    end
end

function [isValid, objs] = validateIndexDataType(block, indexPorts, indexPortDatatypes, objs)
    isValid = true;
    
    for ii=1:numel(indexPorts)
        match = matchDataType(indexPortDatatypes{ii}, SignalDataTypes.INTEGER);
        if ~match
            isValid = false;
            node.elemHandle = block;
            node.data = indexPorts(ii);
            objs{end+1} = node;
        end
    end
end


function objs = validateIndexDataTypeRange(block, indexPorts, indexPortDatatypes, objs)
    for ii=1:numel(indexPorts)
        isPortDataTypeWithinRange = validateIndexPortDataTypeRange(block, indexPortDatatypes{ii}, ii);
        if ~isPortDataTypeWithinRange
            node.elemHandle = block;
            node.data = indexPorts(ii);
            objs{end+1} = node;
        end
    end

end