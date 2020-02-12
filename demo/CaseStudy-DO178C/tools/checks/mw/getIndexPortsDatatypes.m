function [indexPorts, indexPortDatatypes] = getIndexPortsDatatypes(blockType, blockHandle)

compiledPortDatatypes =  get_param(blockHandle, 'CompiledPortDatatypes');
portHandles = get_param(blockHandle, 'PortHandles');
switch blockType
    case 'Assignment'
        % For assignment blocks, first two inports are data ports
        indexPorts = portHandles.Inport(3:end);
        indexPortDatatypes = compiledPortDatatypes.Inport(3:end);
        
    case {'LookupNDDirect'}
        tableIsInput = get_param(blockHandle, 'TableIsInput');
        if strcmp(tableIsInput, 'on')
            % Last port is the table data, if it is taken from inport
            indexPorts = portHandles.Inport(1:end-1);
            indexPortDatatypes = compiledPortDatatypes.Inport(1:end-1);
        else
            % All inports are index ports
            indexPorts = portHandles.Inport(:);
            indexPortDatatypes = compiledPortDatatypes.Inport(:);
        end
        
    case 'Interpolation_n-D'
        tableSource = get_param(blockHandle, 'TableSource');
        if strcmp(tableSource, 'Dialog')
            indexPorts = portHandles.Inport(1:2:end);
            indexPortDatatypes = compiledPortDatatypes.Inport(1:2:end);
        else
            indexPorts = portHandles.Inport(1:2:end-1);
            indexPortDatatypes = compiledPortDatatypes.Inport(1:2:end-1);
        end
    case 'MultiPortSwitch'
          % For Index Vector/Multiport Switch blocks, first inport is the
          % index port
        indexPorts = portHandles.Inport(1);
        indexPortDatatypes = compiledPortDatatypes.Inport(1);
    
    case 'Selector'
          % For Index Vector/Multiport Switch blocks, first inport is the
          % data port
        indexPorts = portHandles.Inport(2:end);
        indexPortDatatypes = compiledPortDatatypes.Inport(2:end);
end      