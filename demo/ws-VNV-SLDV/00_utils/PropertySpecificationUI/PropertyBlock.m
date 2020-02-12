classdef PropertyBlock < PropertyElement
    % A class corresponding to PropertyBlock(s) in PropertySpecification
    % block

    %   Copyright 2012 The MathWorks, Inc. 
    
    properties
        InputVar = {};
        ParamVar = {};
        system;
        BlockPath;
    end
    properties(Constant=true, GetAccess = private)
        BlockDistance = 30;
        TCAPDistance = 10;
        FromGotoHeight =20;
        % reserved keyword which will be ignored as InputVar
        ignoreVar = {'after','prev','extend','detect','init','withinImplies'};
    end
    
    methods
        %%
        function obj = PropertyBlock(propelem)
            % PropertyBlock constructor
            if ~exist('propelem','var')
                propelem = [];
            end
            % calling super class (PropertyElement) constructor
            obj = obj@PropertyElement(propelem);
            [obj.InputVar, obj.ParamVar] = getInputAndParameterVariables(obj.Equation,obj.ignoreVar);
        end
        %%
        function obj = generatePropertyBlock(obj,sys,nProp,len)
            % generates a set of block corresponds to an property.
            if ~exist('len','var')
                len = [];
            end         
            obj.system = sys;
            obj = obj.addTCAPBlocks(nProp);
            obj = obj.addEquation2SimulinkBlock(nProp,len);
            obj = obj.addIgnoreStepBlock(nProp);
            obj = obj.updateTCAPBlock();
            obj = obj.wireBlocks();
            obj = obj.placeInportFromBlock(50);
        end
        %%
        function obj = updateTCAPBlock(obj)
            % update Enable/Disable of SLDV blocks  
            if ~obj.isEnable
                set_param([obj.system '/' obj.BlockPath.Assumption]   ,'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.TestCondition],'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.Proof]        ,'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.TestObjective],'Enabled','off')                
            elseif strcmp(obj.ProoforAssume,'PO')
                set_param([obj.system '/' obj.BlockPath.Assumption]   ,'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.TestCondition],'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.Proof]        ,'Enabled','on')
                set_param([obj.system '/' obj.BlockPath.TestObjective],'Enabled','on')                
            else % obj.ProoforAssume == 'TO'
                set_param([obj.system '/' obj.BlockPath.Assumption]   ,'Enabled','on')
                set_param([obj.system '/' obj.BlockPath.TestCondition],'Enabled','on')
                set_param([obj.system '/' obj.BlockPath.Proof]        ,'Enabled','off')
                set_param([obj.system '/' obj.BlockPath.TestObjective],'Enabled','off')                
            end
            set_param([obj.system '/' obj.BlockPath.TestObjective],'OutEnabled','off')
        end
        %%
        function pos = getPosition(obj)
            % returns position struct of Equation2Simulink block
            if ~isempty(obj.BlockPath.Equation2Simulink)
                bpos = get_param([obj.system '/' obj.BlockPath.Equation2Simulink],'Position');
                pos.LeftCenter(1) = bpos(1);
                pos.LeftCenter(2) = (bpos(2)+bpos(4))/2;
                pos.Height = bpos(4)-bpos(2);
                pos.Bottom = bpos(4);
                pos.Top = bpos(2);                
            else
                pos = [];
            end
        end
        function height = getHeight(obj)
            % returns height of Equation2Simulink block
            if ~isempty(obj.BlockPath.Equation2Simulink)
                bpos = get_param([obj.system '/' obj.BlockPath.Equation2Simulink],'Position');
                height = bpos(4)-bpos(2);
            else
                height = 0;
            end  
        end
        %%
        function moveBlocksToPos(obj,newPos)
            % Move a set of blocks involving to an property.
            
            if ~all(size(newPos) == [1 2])
                error('PropertySpecificationUI:PropertyBlock:Error','Move size must be [1 2]')
            end
            orgPos = obj.getPosition();
            relPos = newPos - orgPos.LeftCenter;
            % move all blocks in this object
            fld = fieldnames(obj.BlockPath);
            try
            for n=1:length(fld)
               
                if strcmp(fld{n},'FromBlock')
                    for m=1:length(obj.BlockPath.FromBlock)
                        % In case of From block, all blocks needed to be
                        % moved.
                        bpos = get_param([obj.system '/' obj.BlockPath.(fld{n}){m}],'Position');
                        set_param([obj.system '/' obj.BlockPath.(fld{n}){m}],'Position',...
                            [bpos(1)+relPos(1) bpos(2)+relPos(2) bpos(3)+relPos(1) bpos(4)+relPos(2)])
                        
                    end
                elseif ~isempty(obj.BlockPath.(fld{n}))
                    bpos = get_param([obj.system '/' obj.BlockPath.(fld{n})],'Position');
                    set_param([obj.system '/' obj.BlockPath.(fld{n})],'Position',...
                        [bpos(1)+relPos(1) bpos(2)+relPos(2) bpos(3)+relPos(1) bpos(4)+relPos(2)])
                end
            end
            catch ME
                warning(ME.message);
            end
                
        end
        %%
        function obj = deleteBlock(obj,sys)
            if exist('sys','var')
                obj.system = sys;               
            end
            % deleting lines
            obj.deleteLines(obj.BlockPath.Equation2Simulink);
            obj.deleteLines(obj.BlockPath.IgnoreSteps);
            obj.deleteLines(obj.BlockPath.Assumption);
            obj.deleteLines(obj.BlockPath.TestCondition);
            obj.deleteLines(obj.BlockPath.Proof);
            obj.deleteLines(obj.BlockPath.TestObjective);
            for n=1:length(obj.BlockPath.FromBlock)
                obj.deleteLines(obj.BlockPath.FromBlock{n});
            end
            delete_block([obj.system '/' obj.BlockPath.Equation2Simulink]);
            obj.BlockPath.Equation2Simulink = [];
            if ~isempty(obj.BlockPath.IgnoreSteps)
                delete_block([obj.system '/' obj.BlockPath.IgnoreSteps])
            end
            obj.BlockPath.IgnoreSteps = [];
            delete_block([obj.system '/' obj.BlockPath.Assumption])
            obj.BlockPath.Assumption = [];
            delete_block([obj.system '/' obj.BlockPath.TestCondition])
            obj.BlockPath.TestCondition = [];
            delete_block([obj.system '/' obj.BlockPath.Proof])
            obj.BlockPath.Proof = [];
            delete_block([obj.system '/' obj.BlockPath.TestObjective])
            obj.BlockPath.TestObjective = [];
            for n=1:length(obj.BlockPath.FromBlock)
                delete_block([obj.system '/' obj.BlockPath.FromBlock{n}])
            end
            obj.BlockPath.FromBlock = {};
        end
    end % methods
    methods (Access = private) 

        %%
        function obj = addTCAPBlocks(obj,nProp)
            % adding SLDV blocks
            Assumption = add_block('sldvlib/Assumption',sprintf('%s/Assumtion%03d',obj.system,nProp));
            obj.BlockPath.Assumption = get(Assumption,'Name');
            TestCondition = add_block('sldvlib/Test Condition',sprintf('%s/TestCondition%03d',obj.system,nProp));
            obj.BlockPath.TestCondition = get(TestCondition,'Name');
            Proof = add_block('sldvlib/Proof Objective',sprintf('%s/Proof%03d',obj.system,nProp));
            obj.BlockPath.Proof = get(Proof,'Name');
            TestObj = add_block('sldvlib/Test Objective',sprintf('%s/TestObjective%03d',obj.system,nProp));
            obj.BlockPath.TestObjective = get(TestObj,'Name');
        end
        %%
        function obj = addEquation2SimulinkBlock(obj,nProp,len)
            % adding Equation2SimulinkBlock
            InputVarStr = obj.makeArgStr(obj.InputVar);
            ParamVarStr = obj.makeArgStr(obj.ParamVar);
                Equation2Simulink =  add_block('propertySpecificationLib/LiteralEq2Simulink',sprintf('%s/EQ%03d',obj.system,nProp));
                obj.BlockPath.Equation2Simulink = get_param(Equation2Simulink,'Name');
                set_param(Equation2Simulink,'LinkStatus','none')
                set_param(Equation2Simulink,'InputVar',InputVarStr,'ParamVar',ParamVarStr,'VerifEq',obj.Equation)
                % Configuring hight and width
                orgPos = get_param(Equation2Simulink,'Position');
                if ~isempty(len)
                    newPos = [orgPos(1) orgPos(2) orgPos(1)+len*5 orgPos(2)+numel(obj.InputVar)*obj.FromGotoHeight];
                    set_param(Equation2Simulink,'Position',newPos);
                end

        end
        %%
        function obj = addIgnoreStepBlock(obj,nProp)
            % adding IgnoreStep Block in propertySpecificationOperatorLib.mdl
            if isnumeric(obj.ignoreSteps) && obj.ignoreSteps > 0 && strcmp(obj.ProoforAssume,'PO')
                IgnoreSteps = add_block('propertySpecificationOperatorLib/initialTrue',sprintf('%s/initialTrue%03d',obj.system,nProp));
                obj.BlockPath.IgnoreSteps = get_param(IgnoreSteps,'Name');
                set_param(IgnoreSteps,'DelayCount',num2str(obj.ignoreSteps),'ShowName','off');                
            else
                obj.BlockPath.IgnoreSteps = '';
            end
            
        end
        %%
        function obj = wireBlocks(obj)
            % Connects all related blocks except Inport/From blocks            
            if ~isempty(obj.BlockPath.IgnoreSteps)
                % Ignore steps
                DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.Equation2Simulink],1,[obj.system '/' obj.BlockPath.IgnoreSteps],1,obj.BlockDistance)
                add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.Equation2Simulink],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.IgnoreSteps],'Name') '/1'],'autorouting','on')
                % Assumption
                DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.IgnoreSteps],1,[obj.system '/' obj.BlockPath.Assumption],1,obj.BlockDistance)
                add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.IgnoreSteps],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.Assumption],'Name') '/1'],'autorouting','on')                
            else
                % Assumption
                DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.Equation2Simulink],1,[obj.system '/' obj.BlockPath.Assumption],1,obj.BlockDistance)
                add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.Equation2Simulink],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.Assumption],'Name') '/1'],'autorouting','on')                                
            end
            % Test Condition
            DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.Assumption],1,[obj.system '/' obj.BlockPath.TestCondition],1,obj.TCAPDistance)
            add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.Assumption],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.TestCondition],'Name') '/1'],'autorouting','on')
            % Proof
            DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.TestCondition],1,[obj.system '/' obj.BlockPath.Proof],1,obj.TCAPDistance)
            add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.TestCondition],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.Proof],'Name') '/1'],'autorouting','on')
            % Test Objective
            DiagramAlign.alignToSrcOutport([obj.system '/' obj.BlockPath.Proof],1,[obj.system '/' obj.BlockPath.TestObjective],1,obj.TCAPDistance)
            add_line(obj.system,[get_param([obj.system '/' obj.BlockPath.Proof],'Name') '/1'],[get_param([obj.system '/' obj.BlockPath.TestObjective],'Name') '/1'],'autorouting','on')
        end
        function obj = placeInportFromBlock(obj,FromGotoWidth)
            % placing From blocks to Equation2Simulink block.
            obj.BlockPath.FromBlock = {};
            for n=1:length(obj.InputVar)
                FromBlk = add_block('built-in/From',sprintf('%s/%s_from',obj.system,obj.InputVar{n}),'MakeNameUnique', 'on');
                obj.BlockPath.FromBlock{end+1} = get_param(FromBlk,'Name');
                
                % Change width of FromBlock
                orgPos = get_param(FromBlk,'Position');
                set_param(FromBlk,'Position',[orgPos(1) orgPos(2) orgPos(1)+FromGotoWidth orgPos(4)])
                
                set_param(FromBlk,'GotoTag',obj.InputVar{n},'ShowName','off')

                DiagramAlign.alignToDstInport(FromBlk,1,[obj.system '/' obj.BlockPath.Equation2Simulink],n,20)
                add_line(obj.system,[get_param(FromBlk,'Name') '/1'],sprintf('%s/%d',get_param([obj.system '/' obj.BlockPath.Equation2Simulink],'Name'),n),'autorouting','on');
            end
        end
        function obj = deleteLines(obj,blk)
            % delete lines connected to  blk
            if isempty(blk)
                return;
            end
            lh = get_param([obj.system '/' blk],'LineHandles');
            PortName={'Inport','Outport'};
            for m=1:length(PortName)
                for n=1:length(lh.(PortName{m}))
                    if lh.(PortName{m})(n) ~= -1
                        delete_line(lh.(PortName{m})(n))
                    end
                end
            end
        end
    end
    methods(Access = private, Static)
        function VarStr = makeArgStr(CellVar)
            % Make string which used as argument of Masked block
            VarStr = '';
            if ~isempty(CellVar)
                for m=1:length(CellVar)
                    VarStr = [VarStr ',' CellVar{m}]; %#ok
                end
                VarStr = VarStr(2:end);
            end
        end

    end
end
