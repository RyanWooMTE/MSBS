classdef Timer < rtw.connectivity.Timer
% TIMER Get timing information for examplePilF28335 application 
%
%   See also RTW.CONNECTIVITY.TIMER

%   Copyright 2009-2011 The MathWorks, Inc.

    methods

        function this = Timer
            
            % Configure data type returned by timer reads
            this.setTimerDataType('uint32');

            % The micros() function returns microseconds
            ticksPerSecond = 150e6; 
            this.setTicksPerSecond(ticksPerSecond);

            % The timer counts upwards
            this.setCountDirection('down');

            % Extract path information from MATLAB Preferences
            examplePilF28335Dir = getpref('examplePilF28335','examplePilF28335Dir');
            
            % Configure source files required to access the timer
            headerFile = fullfile(examplePilF28335Dir,...
                                  'F28335SerialRtiostream',...
                                  'F28335SerialRtiostream-ProfilerTimer.h');
            
            timerSourceFile = fullfile(examplePilF28335Dir,...
                                  'F28335SerialRtiostream',...
                                  'F28335SerialRtiostream-ProfilerTimer.c');
            
            this.setSourceFile(timerSourceFile);
            this.setHeaderFile(headerFile);

            % Configure the expression used to read the timer
            readTimerExpression = 'profileTimerRead()';
            this.setReadTimerExpression(readTimerExpression);
            
        end  
    end
end

