
% Config

Airbag= 0;                                               

config_var_Airbag = Simulink.Variant;
config_var_Airbag.Condition = 'Airbag == 1';

config_var_noAirbag = Simulink.Variant;
config_var_noAirbag.Condition = 'Airbag == 0';


% I/O data

VehicleSpeed = mpt.Signal;
Engine_ON = mpt.Signal; 
LockPos = mpt.Signal; 
Airbag_Fired = mpt.Signal; 

LockDoorMotorCmd = mpt.Signal; 
LockLED = mpt.Signal; 
LockAppMode_Out = mpt.Signal;

