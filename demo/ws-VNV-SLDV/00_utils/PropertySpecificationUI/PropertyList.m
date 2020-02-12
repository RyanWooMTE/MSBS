classdef PropertyList
    % PropertyList stores all properties to be translated to block diagram.
    %

    %   Copyright 2012 The MathWorks, Inc. 
    
    properties
        elem;  % An element of PropertyElement
        isRMI; % Not in use now
    end
    methods
        %%
        function obj = PropertyList(varargin)
            % Class Constructor
            if nargin == 1 && isa(varargin{1},'PropertyBlock')
                obj.elem = PropertyElement(varargin{1});
            elseif nargin == 1 && isa(varargin{1},'PropertyElement')
                % Copy given PropertyElement
                obj.elem = varargin{1};
            else
                obj.elem = PropertyElement();
            end
        end
        
        %%
        function obj = addPropertyElement(obj,prop)
            % Method to add new PropertyElement
            if isempty(obj.elem) || isempty(obj.elem(1).Equation)
                obj.elem = prop;
            else
                obj.elem(end+1) = prop;
            end
        end
        
        %%
        function obj = deleteLastRow(obj)
            % Method to delete the last element
            if ~isempty(obj.elem)
                obj.elem(end) = [];
            end
        end
        
        %% props2tableData
        function tableData = props2tableData(obj)
            % Convert PropertyList to a table used by uitable in
            % PropertySpecificationUI
            tableData = cell(length(obj.elem),5);
            for n=1:length(obj.elem)
                tableData{n,1} = regexprep(obj.elem(n).Description,'\n','');
                tableData{n,2} = obj.elem(n).Equation;
                tableData{n,3} = obj.elem(n).ProoforAssume;
                tableData{n,4} = obj.elem(n).isEnable;
                tableData{n,5} = false;
                tableData{n,6} = ~isempty(obj.elem(n).RMI);
                tableData{n,7} = num2str(floor(obj.elem(n).ignoreSteps));
            end
        end
        %% table2props
        function obj = table2props(obj,tableData)
            % Convert a table used by uitable in PropertySpecificationUI to PropertyList
            
            obj.elem = []; %resetting element
            for n=1:size(tableData,1)
                if ~isempty(tableData{n,2})
                    props = PropertyElement();
                    props.Description = tableData{n,1};
                    props.Equation = tableData{n,2};
                    props.ProoforAssume = tableData{n,3};
                    props.isEnable = tableData{n,4};
                    props.ignoreSteps = floor(str2double(tableData{n,7}));
                    obj = obj.addPropertyElement(props);
                end
            end
        end
        function obj = checkPropertyCompatibility(obj)
            % Check that an equation stored in each elements are valid.
            for n=1:length(obj.elem)
                if isempty(obj.elem(n).Equation)
                    obj.elem(n) = [];
                else
                    bt = BlockTree(obj.elem(n).Equation);
                    if bt.status == false
                        obj.elem(n) = [];
                    end
                end
            end
        end
    end % methods
end % classdef
