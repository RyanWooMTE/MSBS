function ret = getCellValue(varargin)
% private function to read values from excel work sheet
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    switch nargin
        case 1
            datarange = varargin{1};
        case 2
            sheet = varargin{1};
            range = varargin{2};
            datarange = sheet.Range(range);
    end
    ret = datarange.Value;
    if ~iscell(ret)
        if isUnspecified(ret)
            ret = '';
        else
            ret = num2str(ret);
        end
    else
        for k = 1:numel(ret)
            if isUnspecified(ret{k})
                ret{k} = '';
            else
                ret{k} = num2str(ret{k});
            end
        end
    end
end
% -------------------------------------------------------------------------

% -------------------------------------------------------------------------
function retVal = isUnspecified(value)
    if isa(value, 'double') && ...
            isequal(size(value), [1 1]) && ...
            isnan(value)
        retVal = true;
    else
        retVal = false;
    end
end
% -------------------------------------------------------------------------
