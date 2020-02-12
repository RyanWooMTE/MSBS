function ret = isValidClassName(cls)
% private function to check class name list
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    ret = true;
    validCls = {'Parameter', 'Signal', 'AliasType', ...
        'NumericType', 'StructType', 'Bus'};
    for k = 1:length(cls)
        if isempty(strmatch(cls{k}, validCls, 'exact'))
            ret = false;
        end
    end
end
% -------------------------------------------------------------------------
