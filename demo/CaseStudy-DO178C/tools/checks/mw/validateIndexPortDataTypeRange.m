function out = validateIndexPortDataTypeRange(blockHandle, indexportType, indexportNum)

out = true;

dataTypeRangeMap = containers.Map({'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32'},... 
                    {[-128,127], [0, 255], [-32768 , 32768], [0, 65535], [-2147483648, 2147483648], [0, 4294967295]});
blockType = get_param(blockHandle, 'BlockType');
switch blockType
    
    case {'Assignment', 'Selector'}       
        portHandles =  get_param(blockHandle, 'PortHandles');
        inPorts = portHandles.Inport;
        
        % For Assignment/Selector Blocks, first inport is data port
        dataPortHandle = inPorts(1);
        compiledPortDimensions = get_param(dataPortHandle, 'CompiledPortDimensions');
        portDimensions = compiledPortDimensions(2:end);
        
        portDataTypeRange = dataTypeRangeMap(indexportType);
        if (portDimensions(indexportNum) < portDataTypeRange(1)) || (portDimensions(indexportNum) > portDataTypeRange(2))
            out = false;
        end

    case 'LookupNDDirect' 
        tableIsInput = get_param(blockHandle, 'TableIsInput');
        if strcmp(tableIsInput, 'on')
            portHandles = get_param(blockHandle, 'PortHandles');
            inportHandles = portHandles.Inport;
            
            % For LookupNDDirect Block, last inport is the table data port
            tablePortHandle = inportHandles(end);
            compiledPortDimensions = get_param(tablePortHandle, 'CompiledPortDimensions');
            tableDimensions = compiledPortDimensions(2:end);
            
            portDataTypeRange = dataTypeRangeMap(indexportType);
            if (tableDimensions(indexportNum) < portDataTypeRange(1)) || (tableDimensions(indexportNum) > portDataTypeRange(2))
                out = false;
            end

        end
        
    case 'MultiPortSwitch'
        % For Index Vector/Multiport Switch blocks, first inport is the
        % index port
        numOfInputs =  str2double(get_param(blockHandle, 'Inputs')); 
        portDataTypeRange = dataTypeRangeMap(indexportType);
        if numOfInputs > portDataTypeRange(2)
            out = false;
        end         
end

