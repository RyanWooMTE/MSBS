classdef ConnectivityConfig < rtw.connectivity.Config
%CONNECTIVITYCONFIG configuration class for examplePilF28335
%
%   CONNECTIVITYCONFIG(COMPONENTARGS) creates instances of MAKEFILEBUILDER,
%   LAUNCHER, RTIOSTREAMHOSTCOMMUNICATOR and collects them together into a
%   connectivity configuration class for PIL.
%
%   This example uses serial port communication.
%
%   See also RTW.CONNECTIVITY.CONFIG, RTW.CONNECTIVITY.MAKEFILEBUILDER,
%   RTW.MYPIL.TARGETAPPLICATIONFRAMEWORK, RTW.MYPIL.LAUNCHER,
%   RTW.CONNECTIVITY.RTIOSTREAMHOSTCOMMUNICATOR, RTWDEMO_CUSTOM_PIL
    
%   Copyright 2011 The MathWorks, Inc.
    
    methods
        % Constructor
        function this = ConnectivityConfig(componentArgs)
            
            % An executable framework specifies additional source files and
            % libraries required for building the PIL executable
            targetApplicationFramework = ...
                f28335pil.TargetApplicationFramework(componentArgs);
            
            % Filename extension for executable on the target system
            exeExtension = '.out';

            % Create an instance of MakefileBuilder; this works in
            % conjunction with your template makefile to build the PIL
            % executable
            builder = rtw.connectivity.MakefileBuilder(componentArgs, ...
                targetApplicationFramework, ...
                exeExtension);
            
            % Launcher
            launcher = f28335pil.Launcher(componentArgs, builder);

            % Host side rtiostream communication
            hostCommunicator = rtw.connectivity.RtIOStreamHostCommunicator(...
                componentArgs, ...
                launcher, ...
                'rtiostreamserial.dll');
            
            % For some targets it may be necessary to set a timeout value
            % for initial setup of the communications channel. For example,
            % the target processor may take a few seconds before it is
            % ready to open its side of the communications channel. If a
            % non-zero timeout value is set then the communicator will
            % repeatedly try to open the communications channel until the
            % timeout value is reached.
            % hostCommunicator.setInitCommsTimeout(10); 
            
            % Configure a timeout period for reading of data by the host 
            % from the target. If no data is received with the specified 
            % period an error will be thrown.
            hostCommunicator.setTimeoutRecvSecs(30);
                       
            % Set serial host port settings
            baudRate = getpref('examplePilF28335','baudRate');
            COMPort  = getpref('examplePilF28335','COMPort');

            % Set serial host port settings
            rtIOStreamOpenArgs = {...
                '-baud', num2str(baudRate), ...
                '-port', COMPort, ...
                }; 
            
            hostCommunicator.setOpenRtIOStreamArgList(...              
                rtIOStreamOpenArgs);                                                                                           
                                               
            % Call super class constructor to register components
            this@rtw.connectivity.Config(componentArgs,...
                                         builder,...
                                         launcher,...
                                         hostCommunicator);
               
            % Register hardware configuration
            extendedHWConfig = f28335pil.ExtendedHardwareConfig;
            this.setExtendedHardwareConfig(extendedHWConfig);  
            
            % Register timer functions
            timer = f28335pil.Timer;
            this.setTimer(timer);
                                     
        end
    end
end

