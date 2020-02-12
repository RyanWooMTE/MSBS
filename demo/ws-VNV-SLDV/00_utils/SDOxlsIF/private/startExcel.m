function Excel = startExcel
% private function to start Excel as ActiveX server
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.
    Excel = [];
    try
        Excel = actxserver('excel.application');
    catch
        if ispc
            error('SDOxlsIF:startExcel:startExcel', ['Could not start Excel server. ' ...
                'See documentation for resulting limitations.'])
        end
    end

    % Do not display messages from Excel Application
    Excel.DisplayAlerts = 0;
end
% -------------------------------------------------------------------------
