function name = addExtIfNeeded(name)
% private function to add file extension "xls"
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    if (length(name) < 5) || (~isequal(name(end-3:end), '.xls'))
        name = [name, '.xls'];
    end
end
% -------------------------------------------------------------------------
