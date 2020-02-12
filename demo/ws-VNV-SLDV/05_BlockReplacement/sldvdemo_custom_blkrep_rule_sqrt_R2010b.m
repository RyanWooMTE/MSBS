function rule = sldvdemo_custom_blkrep_rule_sqrt_R2010b

    rule = Sldv.xform.BlkRepRule;
    rule.FileName = mfilename;

    rule.BlockType = 'Math';

    rule.ReplacementPath = sprintf('sldvdemo_custom_blockreplib_R2010b/Sqrt_Approx');

%   Copyright 2007-2012 The MathWorks, Inc.

    rule.ReplacementMode = 'Normal';

    parameter.OutMin = '$original.OutMin$';
    parameter.OutMax = '$original.OutMax$';
    parameter.OutDataTypeStr = '$original.OutDataTypeStr$';
    rule.ParameterMap = parameter;

    rule.IsReplaceableCallBack = @replacementTestFunction;
    
end

function out = replacementTestFunction(blockH)

    out = strcmp(get_param(blockH,'Function'),'sqrt');
    if out
        out = false;
        acceptedOutDataTypeStr = {'double','single',...
            'Inherit: Inherit via back propagation',...
            'Inherit: Same as input'};
        outDataTypeStr = get_param(blockH,'OutDataTypeStr');
        I = strncmp(outDataTypeStr,acceptedOutDataTypeStr,length(outDataTypeStr));
        if ~isempty(I)

            portDataTypes = get_param(blockH,'CompiledPortDataTypes');

            out = any(strcmp(portDataTypes.Inport,{'double','single'})) &&  ...
                strcmp(portDataTypes.Inport,portDataTypes.Outport);
        end
    end
    
end
