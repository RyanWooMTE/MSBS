function rule = sldvdemo_custom_blkrep_rule_sqrt

    rule = Sldv.xform.BlkRepRule;
    rule.FileName = mfilename;

    rule.BlockType = 'Sqrt';

    rule.ReplacementPath = sprintf('sldvdemo_custom_blockreplib/Sqrt_Approx');

%   Copyright 2007-2012 The MathWorks, Inc.

    rule.ReplacementMode = 'Normal';

    parameter.OutMin = '$original.OutMin$';
    parameter.OutMax = '$original.OutMax$';
    parameter.OutDataTypeStr = '$original.OutDataTypeStr$';
    rule.ParameterMap = parameter;

    rule.IsReplaceableCallBack = @replacementTestFunction;    
end

function out = replacementTestFunction(blockH)    
    out = false;
    acceptedOutDataTypeStr = {'double','single',...
        'Inherit: Inherit via back propagation',...
        'Inherit: Same as first input'};
    outDataTypeStr = get_param(blockH,'OutDataTypeStr');
    I = strncmp(outDataTypeStr,acceptedOutDataTypeStr,length(outDataTypeStr));
    if ~isempty(I)

        portDataTypes = get_param(blockH,'CompiledPortDataTypes');

        out = any(strcmp(portDataTypes.Inport,{'double','single'})) &&  ...
            strcmp(portDataTypes.Inport,portDataTypes.Outport);
    end        
end