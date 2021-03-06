function memorySectionData = f28335ParseMemoryMap(modelName, mapFile ,memoryDesignations)
% F28335PARSEMEMORYMAP Example utility to parse CCSv4 memory map text file
%  - This file is called by f28335pil.Launcher at the end of a PIL 
%    simulation to parse the memory map generated by CCSv4.
%  - This is an example of how to parse a text file. You can use this
%    as a starting point for more advanced parsing.

% Copyright 2011 The MathWorks, Inc.

    if nargin < 1
        modelName = bdroot;
    end
    
    if nargin < 2
        mapFile = [modelName '.map'];
    end
    if nargin < 3
        memoryDesignations = {'RAML4L7','RAML0L3'};
    end

    % Parse memory map text file
    memorySectionData = getMemoryMapData(mapFile ,memoryDesignations);

    % Create a hyperlink to memory map file
    [~, name, ext] = fileparts(mapFile);
    mapName = [name ext];
    mapHtml = ['<a href="matlab:edit(''' mapFile ''')">' ...
              mapName '</a>'];
    
    % Create summary table of memory usage          
    tableStr = sprintf('\n%15s %15s %15s\n', 'Section Name', 'Length', 'Used');
    for ii = 1:size(memorySectionData,2)
         tableStr = [tableStr ...
              sprintf('\n%15s %15i %15i',...
                  memorySectionData(ii).MemorySectionName,...
                  memorySectionData(ii).MemoryLength, ...
                  memorySectionData(ii).MemoryUsed)];     %#ok<AGROW>
    end
    
    % Display results in MATLAB Command Window
    disp(' ')
    disp(['Memory usage extracted from ' mapHtml ])
    disp(tableStr)
    disp(' ')

end


function memorySectionData = getMemoryMapData(mapFile ,memoryDesignations)
% The function returns memory statistics in bytes for requested memory designations.

    fileContent = getFileContent(mapFile);
    
    numDesignations = numel(memoryDesignations);
    
    memoryLength = zeros(numDesignations, 1, 'double');
    memoryUsed   = zeros(numDesignations, 1, 'double');
    
    for designationCount = 1:numDesignations
        [memoryLength(designationCount), ...
         memoryUsed(designationCount)] = getMemoryDesignationUsageData(fileContent, memoryDesignations{designationCount});
    end
    
    memorySectionData = struct('MemorySectionName', memoryDesignations, ...
                               'MemoryLength',      num2cell(transpose(memoryLength)), ...
                               'MemoryUsed',        num2cell(transpose(memoryUsed)));
    
end


function fileContent = getFileContent(mapFileName)
    
    fileId = fopen(mapFileName, 'r');

    fileContent = fread(fileId, inf, 'char*1=>char')';

    fclose(fileId);
    
end


function [memoryLength, memoryUsed] = getMemoryDesignationUsageData(fileContent, memoryDesignation)

    memoryAreaHeader = memoryDesignation;
    memoryAreaFooter = 'RWIX';

    stringSearchExpression = [memoryAreaHeader, '(.*?)', memoryAreaFooter];

    memoryHexString = cell2mat(regexp(fileContent, stringSearchExpression, 'tokens', 'once'));

    memoryHexValues = sscanf(memoryHexString, '%x%x%x%x');

    memoryLength = memoryHexValues(2);
    memoryUsed   = memoryHexValues(3);

end
