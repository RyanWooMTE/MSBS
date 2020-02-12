function ext = getFileExt(name)
% private function to get file extension
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    if length(name) > 4
        if strcmp(name(end-3), '.')
            ext = name(end-2:end);
        else
            ext = '';
        end
    else
        ext = '';
    end
end
% -------------------------------------------------------------------------
