% CLASS RESULTLOGGER
% This is a singleton class that enable verification blocks logging of the 
% assertions to put into a report 
%
% METHODS : 
%   RESULTLOGGER.LOG(TYPE) : TYPE in {'info',['assert']} 
%       adds log to the object
%   RESULTLOGGER.CLEAR   : clear the logs
%   RESULTLOGGER.GETLOGS : get all of the logs 
%   RESULTLOGGER.PRINT   : print logs to string 

classdef ResultLogger < handle 
    
    properties 
        logs = struct('assert',[],'info',[]); 
    end
    
    % HIDDEN METHODS 
    methods (Hidden)
        function obj = ResultLogger()
        end
        
        function x_log(obj,type)
            if nargin == 1
                type = 'assert';
            end
            
            newlog = struct('model',bdroot,...
                'block',gcb,...
                'time',get_param(bdroot,'SimulationTime'),...
                'desc',get_param(gcb,'Description'));
            if isempty(obj.logs.(type))
                obj.logs.(type) = newlog; 
            else
                obj.logs.(type)(end+1) = newlog; 
            end
        end
        
        function logs = x_getLogs(obj)
            logs = obj.logs;
        end
        
        function x_clear(obj)
            obj.logs = struct('assert',[],'info',[]); 

        end
         
        function s = x_print(obj,type)
            if nargin == 1
                s = x_print(obj,'assert');
                s = [s, x_print(obj,'info')];
            else
                logs = obj.logs.(type);
                if isempty(logs)
                    s=sprintf('No logs to display\n');
                else
                    s=sprintf('Displaying %d logs\n',length(logs));
                end
                for i=1:length(logs)
                    s=sprintf('%sLog %d: Time %f: Block %s\n',s,i,logs(i).time,logs(i).block);
                    s=sprintf('%s     : Description: "%s"\n',s,logs(i).desc);
                end            
            end
        end
        
    end 
    
    % PUBLIC METHODS
    methods

        function display(obj)
            fprintf('%s',x_print(obj));
        end
        
    end
    
    
    % PUBLIC STATIC METHODS
    % These are for external use as per the singleton pattern 
    methods (Static) 
        
        % FUNCTION GETINSTANCE : get singleton instance
        function obj = getInstance()            
            persistent instance;
            if isempty(instance)
                instance = ResultLogger();
            end
            obj = instance;                
        end
        
        % FUNCTION LOG(TYPE) : add a log of TYPE 
        function log(varargin) 
           obj = ResultLogger.getInstance(); 
           obj.x_log(varargin{:});
        end
        
        % FUNCTION LOGS = GETLOGS() : return all of the logged elements 
        function logs = getLogs()
           obj = ResultLogger.getInstance(); 
           logs = obj.x_getLogs();
        end

        % FUNCTION CLEAR() : clear all logs 
        function clear() 
           obj = ResultLogger.getInstance();
           obj.x_clear();
        end
        
        % FUNCTION DISP() : display the object
        function disp()
            obj = ResultLogger.getInstance();
            obj.display();
        end
                
        % FUNCTION STR=PRINT() : return string of the printed logs 
        function str = print(varargin)
            obj = ResultLogger.getInstance();
            str = obj.x_print(varargin{:});
        end           
               
    end
end