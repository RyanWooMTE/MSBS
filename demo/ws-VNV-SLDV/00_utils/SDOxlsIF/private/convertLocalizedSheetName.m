function ret = convertLocalizedSheetName(defInfo, val)
% private function to convert a localized sheet name to a default name
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    ret = val;
    fieldNames = fieldnames(defInfo);
    for k = 1:length(fieldNames)
        switch fieldNames{k};
            case {'Parameter', 'Signal'}
                if strcmp(val, defInfo.(fieldNames{k}).SheetName1)
                    ret = fieldNames{k};
                elseif strcmp(val, defInfo.(fieldNames{k}).SheetName2)
                    ret = [fieldNames{k}, 'RTWInfo'];
                end
            otherwise
                if strcmp(val, defInfo.(fieldNames{k}).SheetName)
                    ret = fieldNames{k};
                end
        end
    end
end
% -------------------------------------------------------------------------
