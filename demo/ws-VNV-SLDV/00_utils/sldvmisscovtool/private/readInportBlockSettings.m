function [inportBlks, inportBlkDT] = readInportBlockSettings(ModelName)

% read inport block datatypes
inportBlks = find_system(ModelName,'SearchDepth',1,'BlockType','Inport');
builtinDT = {'double','single','int8','int16','int32','uint8','uint16','uint32','boolean'};

inportBlkDT = getInportBlockDataTypes(inportBlks);
isCompileNeeded=false;
for n=1:length(inportBlkDT)
    % The model includes un-built-in data type as inputs
    if ~any(strcmp(builtinDT,inportBlkDT{n}))
        isCompileNeeded=true;
    end
end

% if there are inherit datatype, we comple the model.
if isCompileNeeded
    try
        eval(sprintf('%s([],[],[],''compile'');',ModelName));
        for n=1:length(inportBlks)
            dt = get_param(inportBlks{n},'CompiledPortDataTypes');
            inportBlkDT{n}=dt.Outport{1};
        end
        eval(sprintf('%s([],[],[],''term'');',ModelName));
    catch
        error('Compiling model failed');
        eval(sprintf('%s([],[],[],''term'');',ModelName));
    end
end

function inportBlkDT = getInportBlockDataTypes(inportBlks)
% Get inport block's data type to conserve order of number of inport

inportBlkDT = cell(size(inportBlks));

for n=1:length(inportBlks)
    portNum = str2double(get_param(inportBlks{n},'Port'));
    inportBlkDT{portNum} = get_param(inportBlks{n},'DataType');
end
