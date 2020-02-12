function ret = convertLocalizedPropName(defInfo, val, prefix)
% private function to convert a property name to a default name
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    ret = val;
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        s = defInfo.(fieldNames{k});
        if isstruct(s)
            if isfield(s, 'Localization')
                % This struct has 'Localization' field.
                lv = s.Localization;
                if strcmp(lv, val)
                    % PREFIX may be '' or 'RTWInfo.' or 'RTWInfo.CustomAttributes.'
                    ret = [prefix, fieldNames{k}];
                    return;
                end
            else
                % Search for 'Localization' field recursively
                ret = convertLocalizedPropName(s, val, [prefix, fieldNames{k}, '.']);
            end
        end
    end
end
% -------------------------------------------------------------------------
