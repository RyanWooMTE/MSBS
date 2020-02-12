classdef LifeCycleStep < handle
    properties
        Name                % string
        Tool                % string
        LifeCycleStatus     % string
        Description         % string
        VararginName        % cell array
        VararginDefaultValue   % cell array
        Callback     % string
    end
    
    methods
        %------------------------------------------------------------------
        function this = LifeCycleStep()
        end
        
        function this = set.LifeCycleStatus(this,value)
            p = Simulink.ModelManagement.Project.CurrentProject();            
            labels = p.getLabels('Model Life Cycle Status');
            if ismember(value,{labels.Name})
               this.LifeCycleStatus = value;
            else
                error('Input must belong to Life Cycle Status category.');
            end
        end
        %------------------------------------------------------------------
        function Run(this, varargin)
            % Check correct number of arguments
            if numel(varargin) ~= numel(this.VararginName)
                error('Function expects %d argument(s) : "%s"',numel(this.VararginName), this.VararginName{:});
            end
            
            feval(this.Callback,varargin{:})

        end
    end
end