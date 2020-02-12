% Determine if data type of the port/identifier matches the given type
function match = matchDataType(input, type)

match = true;
floatPointDataTypes = {'double', 'single'};
integerDataTypes = {'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32'};

switch type
    case SignalDataTypes.FLOAT
        if ~any(strcmp(input, floatPointDataTypes))
            match = false;
            return;
        end

    case SignalDataTypes.INTEGER
        if ~any(strcmp(input, integerDataTypes))
            match = false;
            return;
        end
    otherwise
        % Covered in the cases
end