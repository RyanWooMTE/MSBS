function ResultDescription = hisl_0019(system)

ResultDescription = {};
deviantBlocks = {};
signedIntTypes = {'int8', 'int16', 'int32'};

modelAdvisorObject = Simulink.ModelAdvisor.getModelAdvisor(system);
modelAdvisorObject.setCheckResultStatus(false);  

% Check that input for bitwise operator blocks are of unsigned datatypes.
bitOperatorBlks = find_system(system, 'FollowLinks', 'on', 'LookUnderMasks', 'all', 'MaskType', 'Bitwise Operator');
for blkIdx=1:length(bitOperatorBlks)
   compiledPortDataTypes = get_param(bitOperatorBlks{blkIdx},'CompiledPortDataTypes');
   ipDataTypes = compiledPortDataTypes.Inport;
   % Enough if one of them is checked, since different input types throw
   % model compilation error
   baseType = Advisor.Utils.Simulink.outDataTypeStr2baseType(system, ipDataTypes{1});
   % Check if the type is any of the integer types/ signed fixed point
   % type.
   if any(strcmp(baseType, signedIntTypes))  || contains(baseType, 'fixdt(1') || contains(baseType, 'sfix')
      deviantBlocks{end+1} = bitOperatorBlks(blkIdx);
   end   
end

if ~isempty(deviantBlocks)
    ft = ModelAdvisor.FormatTemplate('ListTemplate');
    ft.setSubResultStatus('Warn');
    ft.setSubResultStatusText('Found following bitwise operator block(s) with  signed integer data type for input:');
    ft.setListObj(deviantBlocks);
    
    setRecAction(ft, 'Consider changing the datatype of the input signals of bitwise blocks to unsigned integers.');
    ResultDescription{end+1} = ft;
    
else
    modelAdvisorObject.setCheckResultStatus(true);    
    ResultDescription{end+1} = ModelAdvisor.Text('Passed.',{'bold','pass'});
    
end
