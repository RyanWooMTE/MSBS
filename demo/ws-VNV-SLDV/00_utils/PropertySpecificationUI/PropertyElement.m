classdef PropertyElement
    % PropertyElement stores an property

    %   Copyright 2012 The MathWorks, Inc. 
    
    properties
        Description = '';
        Equation = '';
        ProoforAssume = 'PO';
        isEnable = true;
        ignoreSteps = 0;
        RMI = [];
    end
    properties  (GetAccess = private, Constant = true)
        % These members are checked when checkDiff is called
        DiffMember = {'Equation','Description','ProoforAssume','ignoreSteps','RMI'};
    end
    methods
        function obj = PropertyElement(varargin)
            if nargin == 1 && isa(varargin{1},'PropertyElement')
                % Copy Constructor
                propele = PropertyElement();
                fld = fieldnames(propele);
                prop = varargin{1};
                for m=1:length(prop)
                    for n=1:length(fld)
                        obj(m).(fld{n}) = prop(m).(fld{n});
                    end
                end
            end
        end

        %% Check that a specific property has the same variable
        function tf = isEquavalent(obj,cmpelem,member)
            if ~isa(cmpelem,'PropertyElement') || ~any(strcmp(member,obj.DiffMember))
                error('PropertySpecificationUI:PropertyElement:DiffError','Comparison should be done with PropertyElement object and 3rd argument should be a member of PropertyElement class.')                
            end
            tf = isequal(obj.(member),cmpelem.(member));            
        end
        %% Check that all properties are the same
        function tf = isAllEquivalent(obj,cmpelem)           
            if ~isa(cmpelem,'PropertyElement')
                error('PropertySpecificationUI:PropertyElement:DiffError','Comparison should be done with PropertyElement object and 3rd argument should be a member of PropertyElement class.')                
            end
            if numel(cmpelem) ~= 1
                error('PropertySpecificationUI:PropertyElement:DiffError','Number of input argument should be one.')
            end
            tf = true;
            for n=1:length(obj.DiffMember)
                if ischar(obj.(obj.DiffMember{n}))
                    % skip start and end white space
                    newtf = strcmp(regexprep(obj.(obj.DiffMember{n}),'^\s+|\s+$',''),regexprep(cmpelem.(obj.DiffMember{n}),'^\s+|\s+$',''));
                else
                    newtf = isequal(obj.(obj.DiffMember{n}),cmpelem.(obj.DiffMember{n}));
                end
               tf = tf && newtf;
            end
        end
    end % methods
end % classdef