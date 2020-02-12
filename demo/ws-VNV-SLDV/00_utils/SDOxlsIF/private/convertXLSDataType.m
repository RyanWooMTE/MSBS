function propVal = convertXLSDataType(hObj, propName, propVal)
% private function to convert data type to express in excel worksheet
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    try
        mlDataType = class(propVal);
    catch
        warning('SDOxlsIF:convertXLSDataType:UnknownDataType', ...
            'Unknown Data Type of property ''%s'' for %s object', propName, class(hObj))
        return;
    end
    valLen = length(propVal);
    switch mlDataType
        case {'char'}
            % Do nothing
        case {'Simulink.StructElement', 'Simulink.BusElement'}
            switch valLen
                case 0
                    % Do nothing
                case 1
                    propVal = propVal.Name;
                otherwise
                    % Elements are expressed like '[name1, name2, ...]'
                    str = '[';
                    for k = 1:valLen
                        str = [str, propVal(k).Name, ' '];
                    end
                    str(end) = ']';
                    propVal = strrep(str, ' ', ', ');
            end
        otherwise
            if isnumeric(propVal)
                switch valLen
                    case 0
                        % Do nothing
                    case 1
                        propVal = num2str(propVal);
                    otherwise
                        propVal = mat2str(propVal);
                        propVal = strrep(propVal, ' ', ', ');
                        propVal = strrep(propVal, ';', sprintf(';\n'));
                end
            end
    end
% -------------------------------------------------------------------------
