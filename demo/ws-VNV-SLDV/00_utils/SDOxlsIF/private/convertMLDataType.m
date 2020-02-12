function propVal = convertMLDataType(hObj, propName, propVal)
% private function to convert data type to load as MATLAB variable
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    try
        mlDataType = eval(sprintf('class(hObj.%s);', propName));
        %mlDataType = class(hObj.(propName));
    catch
        warning('SDOxlsIF:convertMLDataType:UnknownDataType', ...
            'Unknown Data Type of property ''%s'' for %s object', propName, class(hObj))
        return;
    end
    switch mlDataType
        case {'char'}
            % Do nothing
        case {'logical'}
            propVal = evalfNeeded(propVal);
            propVal = logical(propVal);
        otherwise
            propVal = evalfNeeded(propVal);
            % In case of Simulink.StructElement and Simulink.BusElement
%             if isa(propVal, 'Simulink.StructElement')
%                 if  strcmp(class(hObj), 'Simulink.Bus') && ~strcmp(class(propVal), 'Simulink.BusElement')
%                     warning('SDOxlsIF:convertMLDataType:InvalidElementDataType', ...
%                         'Invalid data type for ELEMENTS: ''Simulink.Bus''')
%                     propVal = '';
%                 end
%                 if  strcmp(class(hObj), 'Simulink.StructType') && ~strcmp(class(propVal), 'Simulink.StructElement')
%                     warning('SDOxlsIF:convertMLDataType:InvalidElementDataType', ...
%                         'Invalid data type for ELEMENTS: ''Simulink.StructType''')
%                     propVal = '';
%                 end
%             end
    end
end
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
function retVal = evalfNeeded(origVal)
  if ischar(origVal)
    try
      retVal = evalin('base', origVal);
    catch
      retVal = origVal;
    end
  else
    retVal = origVal;
  end
end
% -------------------------------------------------------------------------
