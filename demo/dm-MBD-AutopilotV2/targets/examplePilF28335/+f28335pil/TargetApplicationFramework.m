classdef TargetApplicationFramework < rtw.pil.RtIOStreamApplicationFramework
%TARGETAPPLICATIONFRAMEWORK creates application framework for examplePilF28335
%
%   The TARGETAPPLICATIONFRAMEWORK allows you to specify additional files needed
%   to build an application for the target environment. These files may include
%   code for hardware initialization as well as device driver code for a
%   communications channel. 
%
%   See also RTW.PIL.RTIOSTREAMAPPLICATIONFRAMEWORK, RTWDEMO_CUSTOM_PIL
 
%   Copyright 2011 The MathWorks, Inc.
    
    methods
        % constructor
        function this = TargetApplicationFramework(componentArgs)
            error(nargchk(1, 1, nargin, 'struct'));
            % call super class constructor
            this@rtw.pil.RtIOStreamApplicationFramework(componentArgs);
            
            % To build the PIL application you must specify a main.c file.       
            % The following PIL main.c files are provided and can be             
            % added to the application framework via the "addPILMain"                
            % method:                                                            
            %                                                                    
            % 1) A main.c adapted for on-target PIL and suitable                 
            %    for most PIL implementations. Select by specifying              
            %    'target' argument to "addPILMain" method.                       
            %                                                                    
            % 2) A main.c adapted for host-based PIL such as the                 
            %    "mypil" host example. Select by specifying 'host'               
            %    argument to "addPILMain" method.                                
            % this.addPILMain('host');                                             
            this.addPILMain('target');
                                                                                
            % Additional source and library files to include in the build        
            % must be added to the BuildInfo property                            
                                                                                 
            % Get the BuildInfo object to update                                 
            buildInfo = this.getBuildInfo;

            % Add device driver files to implement the target-side of the
            % host-target rtIOStream communications channel
            
            examplePilF28335Dir = getpref('examplePilF28335','examplePilF28335Dir');
            rtiostream_src_path = fullfile(examplePilF28335Dir,'F28335SerialRtiostream');
            
            buildInfo.addIncludePaths(rtiostream_src_path);
            buildInfo.addSourcePaths(rtiostream_src_path);                      
            buildInfo.addSourceFiles('F28335SerialRtiostream-DevInit.c',rtiostream_src_path);
            buildInfo.addSourceFiles('F28335SerialRtiostream-Rtiostream.c',rtiostream_src_path);
            buildInfo.addSourceFiles('F28335SerialRtiostream-ProfilerTimer.c',rtiostream_src_path);
            
            TI_F28xxx_SysSWDir  = getpref('examplePilF28335','TI_F28xxx_SysSWDir');
            rtiostream_src_path = fullfile(TI_F28xxx_SysSWDir,...
                '~SupportFiles','DSP2833x_headers','source');
            buildInfo.addSourcePaths(rtiostream_src_path);                      
            buildInfo.addSourceFiles('DSP2833x_GlobalVariableDefs.c',rtiostream_src_path);
            
            % Extract parameters to configure target side communication
            cpuClockRateMHz = num2str(getpref('examplePilF28335','cpuClockRateMHz'));
            baudRate        = num2str(getpref('examplePilF28335','baudRate'));
            boardConfigPLL  = num2str(getpref('examplePilF28335','boardConfigPLL'));

            buildInfo.addDefines(['CPU_CLOCK_RATE_MHZ=' cpuClockRateMHz], 'OPTS'); 
            buildInfo.addDefines(['BAUD_RATE=' baudRate], 'OPTS'); 
            buildInfo.addDefines(['BOARD_CONFIG_PLL=' boardConfigPLL], 'OPTS'); 
            
        end
    end
end
