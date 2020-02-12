classdef Launcher < rtw.connectivity.Launcher
%LAUNCHER class for launching examplePilF28335 application
%
%   LAUNCHER(COMPONENTARGS,BUILDER) instantiates a LAUNCHER object that you can
%   use to control starting and stopping of an application on the target
%   processor. In this case the Debug Server Scripting (dss) utility which 
%   ships with Code Composer Studio v4 (CCSv4) is used to download and 
%   run the executable.
%
%   See also RTW.CONNECTIVITY.LAUNCHER, RTWDEMO_CUSTOM_PIL
    
%   Copyright 2011 The MathWorks, Inc.
   
    properties
    
       % For the host-based example, additional arguments
       % may be provided when the executable is launched
       % as a separate process on the host. 
       ArgString = '';
       
       % Keep track of the process ID of the executable
       % so that this process can be killed when no longer
       % required
       ExePid = '';
                   
       % Keep track of a temporary file created by the
       % process launcher so that it can be deleted when
       % the process is terminated
       TempFile = ''; 
       
       % Keep track of a temporary file used to indicate that the
       % the executable has been properly downloaded and is 
       % executing on the embedded processor
       SemaphoreFile = ''; 

    end
    
    methods
        % constructor
        function this = Launcher(componentArgs, builder)
            error(nargchk(2, 2, nargin, 'struct'));
            % call super class constructor
            this@rtw.connectivity.Launcher(componentArgs, builder);
        end
        
        % destructor
        function delete(this) %#ok
            
            % This method is called when an instance of this class is cleared from memory,
            % e.g. when the associated Simulink model is closed. You can use
            % this destructor method to close down any processes, e.g. an IDE or
            % debugger that was originally started by this class. If the
            % stopApplication method already performs this housekeeping at the
            % end of each on-target simulation run then it is not necessary to
            % insert any code in this destructor method. However, if the IDE or
            % debugger may be left open between successive on-target simulation
            % runs then it is recommended to insert code here to terminate that
            % application.
                
        end
        
        % Start the application
        function startApplication(this)
            
            disp('Verifying MATLAB can communicate with the f28335.');
            %f28335InitDriver();
            
            % get name of the executable file to download
            exe = this.getBuilder.getApplicationExecutable;
            
            manualDownload = false;
            if ( ~manualDownload )
                % Use Debug Server Scripting (dss) utility which ships with 
                % Code Composer Studio v4 (CCSv4) is used to download and 
                % run the executable.
                
                % Get path information from MATLAB Preferences
                CCSRootDir          = getpref('examplePilF28335','CCSRootDir');
                examplePilF28335Dir = getpref('examplePilF28335','examplePilF28335Dir');
                targetConfigFile    = getpref('examplePilF28335','targetConfigFile');

                % Create strings to call dss
                dss              = fullfile(CCSRootDir,'scripting','bin','dss.bat');
                loadAndRunScript = fullfile(examplePilF28335Dir,'runProgram_CCSv4.js');
                programFile = exe;

                this.SemaphoreFile = tempname;
                commandString = sprintf('%s', dss);
                argString = sprintf('"%s" "%s" "%s" "%s"', loadAndRunScript, targetConfigFile, programFile, this.SemaphoreFile);

                disp(['Launcher command string:    ' commandString]);
                disp(['Launcher command arguments: ' argString]);

                % Launch process to download and run the embedded application
                [this.ExePid, this.TempFile] = ...
                    rtw.connectivity.Utils.launchProcess(...
                    commandString, ...
                    argString);
                
                % Pause to give application time to download and begin
                % Wait in a loop until the SemaphoreFile has been created
                % (indicating the program is downloaded and executing)
                maxPauseCnt = 30; % Max pause time = maxPauseCnt * 2 seconds
                curPauseSec = 0;
                while ~exist(this.SemaphoreFile,'file') && curPauseSec < maxPauseCnt
                    pause(2)
                    curPauseSec = curPauseSec + 1;
                end
                
                if ~exist(this.SemaphoreFile,'file')
                    error('Verification file does not exist');
                else
                    pause(1)
                    disp('Application is running');
                end
                
                % Verify that process launched properly
                if ~rtw.connectivity.Utils.isAlive(this.ExePid)
                   disp('')
                   disp(['Process is not alive, displaying contents '...
                        'of log file:'])
                   disp('')
                   type(this.TempFile)
                   disp('')
                   error(['Failed to start process with PID = '...
                        num2str(this.ExePid) ' using arguments '...
                        this.ArgString '. '])
                end
                % Pause in case board needs a few seconds to start the application
                pause(3)
                disp(['Started new process, pid = ' ...
                        int2str(this.ExePid) ])
                   
           end
        end
        
        % Stop the application
        function stopApplication(this)
            
           % Kill the process that launched the embedded application
           if ~isempty(this.ExePid)
               rtw.connectivity.Utils.killProcess(this.ExePid, ...
                                                  this.TempFile);
               disp(['Terminated process, pid = ' int2str(this.ExePid)]);
               
               if exist(this.SemaphoreFile, 'file')
                   delete(this.SemaphoreFile);
               else
                   error('F28335PIL:Launcher:StopApplication', ...
                         ['Cannot locate semaphore file.\n', ...
                         'Download and execution of code not successful.\n', ...
                         'Check PIL preferences to ensure the correct CCS configuration file (*.ccxml) is used.'])
               end
           end
           this.ExePid = '';
           this.SemaphoreFile = '';
           
           % Parse memory map and display results in MATLAB Command Window
           exe = this.getBuilder.getApplicationExecutable;
           [filePath, modelName] = fileparts(exe);
           mapFile = fullfile(filePath,[modelName '.map']);

           f28335ParseMemoryMap(modelName, mapFile);
           
        end
        
    end
end
