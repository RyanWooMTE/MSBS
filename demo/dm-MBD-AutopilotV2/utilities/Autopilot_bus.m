function Autopilot_bus() 
% AUTOPILOT_BUS initializes a set of bus objects in the MATLAB base workspace 

% Bus object: slBus1 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'altRate';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = -20000;
elems(1).Max = 20000;
elems(1).DocUnits = sprintf('');
elems(1).Description = sprintf('');

elems(2) = Simulink.BusElement;
elems(2).Name = 'alpha';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = -90;
elems(2).Max = 90;
elems(2).DocUnits = sprintf('');
elems(2).Description = sprintf('');

elems(3) = Simulink.BusElement;
elems(3).Name = 'beta';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).SamplingMode = 'Sample based';
elems(3).Min = -180;
elems(3).Max = 180;
elems(3).DocUnits = sprintf('');
elems(3).Description = sprintf('');

elems(4) = Simulink.BusElement;
elems(4).Name = 'airspeed';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'double';
elems(4).SampleTime = -1;
elems(4).Complexity = 'real';
elems(4).SamplingMode = 'Sample based';
elems(4).Min = 0;
elems(4).Max = 1000;
elems(4).DocUnits = sprintf('');
elems(4).Description = sprintf('');

elems(5) = Simulink.BusElement;
elems(5).Name = 'alt';
elems(5).Dimensions = 1;
elems(5).DimensionsMode = 'Fixed';
elems(5).DataType = 'double';
elems(5).SampleTime = -1;
elems(5).Complexity = 'real';
elems(5).SamplingMode = 'Sample based';
elems(5).Min = 0;
elems(5).Max = 65000;
elems(5).DocUnits = sprintf('');
elems(5).Description = sprintf('');

slBus1 = Simulink.Bus;
slBus1.HeaderFile = '';
slBus1.Description = sprintf('');
slBus1.DataScope = 'Auto';
slBus1.Alignment = -1;
slBus1.Elements = elems;
assigninContext('slBus1', slBus1)

% Bus object: slBus2 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'phi';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = -180;
elems(1).Max = 180;
elems(1).DocUnits = sprintf('');
elems(1).Description = sprintf('');

elems(2) = Simulink.BusElement;
elems(2).Name = 'theta';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = -90;
elems(2).Max = 90;
elems(2).DocUnits = sprintf('');
elems(2).Description = sprintf('');

elems(3) = Simulink.BusElement;
elems(3).Name = 'psi';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).SamplingMode = 'Sample based';
elems(3).Min = -180;
elems(3).Max = 180;
elems(3).DocUnits = sprintf('');
elems(3).Description = sprintf('');

elems(4) = Simulink.BusElement;
elems(4).Name = 'p';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'double';
elems(4).SampleTime = -1;
elems(4).Complexity = 'real';
elems(4).SamplingMode = 'Sample based';
elems(4).Min = -180;
elems(4).Max = 180;
elems(4).DocUnits = sprintf('');
elems(4).Description = sprintf('');

elems(5) = Simulink.BusElement;
elems(5).Name = 'q';
elems(5).Dimensions = 1;
elems(5).DimensionsMode = 'Fixed';
elems(5).DataType = 'double';
elems(5).SampleTime = -1;
elems(5).Complexity = 'real';
elems(5).SamplingMode = 'Sample based';
elems(5).Min = -90;
elems(5).Max = 90;
elems(5).DocUnits = sprintf('');
elems(5).Description = sprintf('');

elems(6) = Simulink.BusElement;
elems(6).Name = 'r';
elems(6).Dimensions = 1;
elems(6).DimensionsMode = 'Fixed';
elems(6).DataType = 'double';
elems(6).SampleTime = -1;
elems(6).Complexity = 'real';
elems(6).SamplingMode = 'Sample based';
elems(6).Min = -180;
elems(6).Max = 180;
elems(6).DocUnits = sprintf('');
elems(6).Description = sprintf('');

slBus2 = Simulink.Bus;
slBus2.HeaderFile = '';
slBus2.Description = sprintf('');
slBus2.DataScope = 'Auto';
slBus2.Alignment = -1;
slBus2.Elements = elems;
assigninContext('slBus2', slBus2)

