% -------------------------------------------------------------------
%  MATLAB file generated by Simulink.saveVars on 4-Jul-2011 17:48:06
%  MATLAB version: 7.13.0.31 (R2011b)
% -------------------------------------------------------------------


Airbag_Fired = mpt.Signal;
Airbag_Fired.RTWInfo.StorageClass = 'Auto';
Airbag_Fired.RTWInfo.Alias = '';
Airbag_Fired.RTWInfo.Alignment = -1;
Airbag_Fired.RTWInfo.CustomStorageClass = 'Default';
Airbag_Fired.Description = '';
Airbag_Fired.DataType = 'boolean';
Airbag_Fired.Min = 0;
Airbag_Fired.Max = 1;
Airbag_Fired.DocUnits = '';
Airbag_Fired.Dimensions = -1;
Airbag_Fired.DimensionsMode = 'Fixed';
Airbag_Fired.Complexity = 'real';
Airbag_Fired.SampleTime = -1;
Airbag_Fired.SamplingMode = 'Sample based';
Airbag_Fired.InitialValue = '';

LockAppMode = mpt.Signal;
LockAppMode.RTWInfo.StorageClass = 'Auto';
LockAppMode.RTWInfo.Alias = '';
LockAppMode.RTWInfo.Alignment = -1;
LockAppMode.RTWInfo.CustomStorageClass = 'Default';
LockAppMode.Description = '';
LockAppMode.DataType = 'Enum: LockingMode';
LockAppMode.Min = [];
LockAppMode.Max = [];
LockAppMode.DocUnits = '';
LockAppMode.Dimensions = -1;
LockAppMode.DimensionsMode = 'Fixed';
LockAppMode.Complexity = 'real';
LockAppMode.SampleTime = -1;
LockAppMode.SamplingMode = 'Sample based';
LockAppMode.InitialValue = '';

lockDoor_speedThreshTimer = mpt.Parameter;
lockDoor_speedThreshTimer.Value = 2;
lockDoor_speedThreshTimer.RTWInfo.StorageClass = 'Auto';
lockDoor_speedThreshTimer.RTWInfo.Alias = '';
lockDoor_speedThreshTimer.RTWInfo.Alignment = -1;
lockDoor_speedThreshTimer.RTWInfo.CustomStorageClass = 'Default';
lockDoor_speedThreshTimer.Description = '';
lockDoor_speedThreshTimer.DataType = 'fixdt(1,16,2)';
lockDoor_speedThreshTimer.Min = [];
lockDoor_speedThreshTimer.Max = [];
lockDoor_speedThreshTimer.DocUnits = 's';

lockDoor_speedThreshValue = mpt.Parameter;
lockDoor_speedThreshValue.Value = 5;
lockDoor_speedThreshValue.RTWInfo.StorageClass = 'Auto';
lockDoor_speedThreshValue.RTWInfo.Alias = '';
lockDoor_speedThreshValue.RTWInfo.Alignment = -1;
lockDoor_speedThreshValue.RTWInfo.CustomStorageClass = 'Default';
lockDoor_speedThreshValue.Description = '';
lockDoor_speedThreshValue.DataType = 'single';
lockDoor_speedThreshValue.Min = [];
lockDoor_speedThreshValue.Max = [];
lockDoor_speedThreshValue.DocUnits = 'km/h';

tp1 = mpt.Signal;
tp1.RTWInfo.StorageClass = 'Auto';
tp1.RTWInfo.Alias = '';
tp1.RTWInfo.Alignment = -1;
tp1.RTWInfo.CustomStorageClass = 'Default';
tp1.Description = '';
tp1.DataType = 'boolean';
tp1.Min = [];
tp1.Max = [];
tp1.DocUnits = '';
tp1.Dimensions = -1;
tp1.DimensionsMode = 'auto';
tp1.Complexity = 'auto';
tp1.SampleTime = -1;
tp1.SamplingMode = 'auto';
tp1.InitialValue = '';

Vehicle_Speed_Cond = mpt.Signal;
Vehicle_Speed_Cond.RTWInfo.StorageClass = 'Auto';
Vehicle_Speed_Cond.RTWInfo.Alias = '';
Vehicle_Speed_Cond.RTWInfo.Alignment = -1;
Vehicle_Speed_Cond.RTWInfo.CustomStorageClass = 'Default';
Vehicle_Speed_Cond.Description = '';
Vehicle_Speed_Cond.DataType = 'single';
Vehicle_Speed_Cond.Min = [];
Vehicle_Speed_Cond.Max = [];
Vehicle_Speed_Cond.DocUnits = 'km/h';
Vehicle_Speed_Cond.Dimensions = -1;
Vehicle_Speed_Cond.DimensionsMode = 'Fixed';
Vehicle_Speed_Cond.Complexity = 'real';
Vehicle_Speed_Cond.SampleTime = -1;
Vehicle_Speed_Cond.SamplingMode = 'Sample based';
Vehicle_Speed_Cond.InitialValue = '';

Engine_ON = mpt.Signal;
Engine_ON.RTWInfo.StorageClass = 'Auto';
Engine_ON.RTWInfo.Alias = '';
Engine_ON.RTWInfo.Alignment = -1;
Engine_ON.RTWInfo.CustomStorageClass = 'Default';
Engine_ON.Description = '';
Engine_ON.DataType = 'boolean';
Engine_ON.Min = [];
Engine_ON.Max = [];
Engine_ON.DocUnits = '';
Engine_ON.Dimensions = -1;
Engine_ON.DimensionsMode = 'auto';
Engine_ON.Complexity = 'auto';
Engine_ON.SampleTime = -1;
Engine_ON.SamplingMode = 'auto';
Engine_ON.InitialValue = '';

LockDoorRequest = mpt.Signal;
LockDoorRequest.RTWInfo.StorageClass = 'Auto';
LockDoorRequest.RTWInfo.Alias = '';
LockDoorRequest.RTWInfo.Alignment = -1;
LockDoorRequest.RTWInfo.CustomStorageClass = 'Default';
LockDoorRequest.Description = '';
LockDoorRequest.DataType = 'boolean';
LockDoorRequest.Min = [];
LockDoorRequest.Max = [];
LockDoorRequest.DocUnits = '';
LockDoorRequest.Dimensions = -1;
LockDoorRequest.DimensionsMode = 'auto';
LockDoorRequest.Complexity = 'auto';
LockDoorRequest.SampleTime = -1;
LockDoorRequest.SamplingMode = 'auto';
LockDoorRequest.InitialValue = '';

Luxury = Simulink.Parameter;
Luxury.Value = 0;
Luxury.RTWInfo.StorageClass = 'Auto';
Luxury.RTWInfo.Alias = '';
Luxury.RTWInfo.Alignment = -1;
Luxury.RTWInfo.CustomStorageClass = 'ImportedDefine';
Luxury.RTWInfo.CustomAttributes.HeaderFile = 'myVariant.h';
Luxury.Description = '';
Luxury.DataType = 'boolean';
Luxury.Min = [];
Luxury.Max = [];
Luxury.DocUnits = '';

Lowcost = Simulink.Parameter;
Lowcost.Value = 1;
Lowcost.RTWInfo.StorageClass = 'Auto';
Lowcost.RTWInfo.Alias = '';
Lowcost.RTWInfo.Alignment = -1;
Lowcost.RTWInfo.CustomStorageClass = 'ImportedDefine';
Lowcost.RTWInfo.CustomAttributes.HeaderFile = 'myVariant.h';
Lowcost.Description = '';
Lowcost.DataType = 'boolean';
Lowcost.Min = [];
Lowcost.Max = [];
Lowcost.DocUnits = '';

US = Simulink.Parameter;
US.Value = 1;
US.RTWInfo.StorageClass = 'Auto';
US.RTWInfo.Alias = '';
US.RTWInfo.Alignment = -1;
US.RTWInfo.CustomStorageClass = 'ImportedDefine';
US.RTWInfo.CustomAttributes.HeaderFile = 'myVariant.h';
US.Description = '';
US.DataType = 'boolean';
US.Min = [];
US.Max = [];
US.DocUnits = '';

