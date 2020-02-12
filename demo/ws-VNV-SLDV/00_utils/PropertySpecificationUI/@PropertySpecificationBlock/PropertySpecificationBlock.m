classdef PropertySpecificationBlock 
    % PropertySpecificationBlock class corresponds to PropertySpecification Block
    
    %   Copyright 2012 The MathWorks, Inc. 
    
    properties
        system = ''; % path to PropertySpecification block
        sysHandle;
        pblock = PropertyBlock().empty;
        isOnlyParseDiff = true;
        InputVar = {};
        inportBlockPath = {};
        gotoBlockPath = {};
    end
    properties (GetAccess = private, Constant = true)
        BlockDistance = 20;
        % reserved keyword which will be ignored as InputVar
        ignoreVar = {'after','prev','extend','detect','init','withinImplies'};
    end
    methods
        %%
        function obj = PropertySpecificationBlock(sys)
                        
            % Open new model if target block is not specified.
            if ~exist('sys','var')
                new_system();
                open_system(bdroot);
                obj.sysHandle = add_block('propertySpecificationLib/PropertySpecification',[bdroot '/PropertySpecification'],'MakeNameUnique', 'on');
                obj.system = getfullname(obj.sysHandle);
            else
                obj.system = sys;
                obj.sysHandle = get_param(obj.system,'Handle');
            end
            
        end
        %%
        function obj = generateDiagram(obj,plist)
            %
            obj.preloadLibrary();
            oldInports = obj.InputVar;
            obj.InputVar = getInputAndParameterVariables(obj.getAllEqs(plist),obj.ignoreVar);

            % get length of maximum number of string in given equations
            eqStrLen = obj.getMaxEquationStringLength(plist);
            
            % Showing Waitbar
            hWaitbar = waitbar(0,'Please wait...');
            
            prevPos.Bottom = 50;
            
            if ~obj.isOnlyParseDiff
                removeExistingObjects(obj)
                obj.inportBlockPath = {};
                obj.gotoBlockPath = {};
            end
            % Generating each property blocks by using PropertyBlock class
            pblock_old = obj.pblock;
            obj.pblock = PropertyBlock.empty;
            
            % deleting existing blocks that are not compared with old one
            if numel(plist.elem) < numel(pblock_old)
                for n=numel(plist.elem)+1:numel(pblock_old)
                    pblock_old(n).deleteBlock(obj.system);
                end
            end
            
            for nProp=1:length(plist.elem)
                if obj.isOnlyParseDiff
                    if numel(pblock_old) >= nProp
                        pblock_old(nProp).system = obj.system;
                        if plist.elem(nProp).isAllEquivalent(pblock_old(nProp))
                            prevPos = pblock_old(nProp).getPosition();
                            obj.pblock(nProp) = pblock_old(nProp);
                            waitbar(nProp/length(plist.elem),hWaitbar,sprintf('Skipping %d/%d\n',nProp,length(plist.elem)))
                            continue;
                        else
                            pblock_old(nProp).deleteBlock(obj.system);
                        end
                    end
                end
                waitbar(nProp/length(plist.elem),hWaitbar,sprintf('Processing %d/%d\n',nProp,length(plist.elem)))
                pb = PropertyBlock(plist.elem(nProp));
                pb = pb.generatePropertyBlock(obj.system,nProp,eqStrLen);
                newY = prevPos.Bottom + pb.getHeight()/2 + obj.BlockDistance;
                pb.moveBlocksToPos([250 newY]);
                
                prevPos = pb.getPosition();
                
                obj.pblock(nProp) = pb;
                
            end
            % Finally place inport blocks
            if obj.isOnlyParseDiff
                obj = obj.createInportBlocks(oldInports);
            else
                obj = obj.createInportBlocks();
            end
            
            obj = obj.moveInportBlocks();
            %obj = obj.setUserData();
            close(hWaitbar)
        end
        
        function obj = setUserData(obj)
            % Storing class object in UserData
            if strcmp(get_param(obj.system,'type'),'block')
                set_param(obj.system,'UserData',obj);
                set_param(obj.system,'UserDataPersistent','on');
            end
        end
        function removeExistingObjects(obj)
            % Ohterwise, we add blocks inside specified block.
            remainBlk = find_system(obj.system,'FindAll','on','LookUnderMasks','on');
            % Remove all blocks inside of the specified block
            for n=1:length(remainBlk)
                if ~ishandle(remainBlk(n)) || isequal(obj.sysHandle,remainBlk(n)) || strcmp(getfullname(remainBlk(n)),getfullname(obj.system))
                    continue;
                end
                switch get(remainBlk(n),'Type')
                    case 'block'
                        delete_block(remainBlk(n));
                    case 'line'
                        delete_line(remainBlk(n));
                end
            end
        end
        %%
        function obj = createInportBlocks(obj,oldInportVar)
            % Identify variable names used in the whole table
            if ~exist('oldInportVar','var')
                oldInportVar = {};
            end
            [~,addedInportIdx] = setdiff(obj.InputVar,oldInportVar);
            [~,deletedInportIdx] = setdiff(oldInportVar,obj.InputVar);
            for idx=1:length(addedInportIdx)
                InblockH = add_block('built-in/Inport', sprintf('%s/%s',obj.system,obj.InputVar{addedInportIdx(idx)}),'MakeNameUnique', 'on');
                obj.inportBlockPath{end+1} = get_param(InblockH,'Name');
                set_param(InblockH,'Name',obj.InputVar{addedInportIdx(idx)});
                GotoBlockH = add_block('built-in/Goto', sprintf('%s/%s_goto',obj.system,obj.InputVar{addedInportIdx(idx)}),'MakeNameUnique', 'on');
                obj.gotoBlockPath{end+1} = get_param(GotoBlockH,'Name');
                set_param(GotoBlockH,'GotoTag',obj.InputVar{addedInportIdx(idx)})
            end
            for idx=1:length(deletedInportIdx)
                inblk = find_system(obj.system,'SearchDepth',1,'LookUnderMasks','all','BlockType','Inport','Name',oldInportVar{deletedInportIdx(idx)});
                lh = get_param(inblk{1},'LineHandles');
                obj.inportBlockPath(strcmp(obj.inportBlockPath,get_param(inblk{1},'Name'))) = [];                
                gotoBlk = get_param(lh.Outport(1),'DstBlockHandle');
                obj.gotoBlockPath(strcmp(obj.gotoBlockPath,get_param(gotoBlk,'Name'))) = [];
                delete_block(inblk{1})
                delete_block(gotoBlk)
                delete_line(lh.Outport(1))
            end

        end
        %%
        function obj = moveInportBlocks(obj)
            verLen = obj.getVerLen(obj.InputVar);
            FromGotoWidth = 30+verLen*5;
            for n=1:length(obj.InputVar)
                inblk = [obj.system '/' obj.inportBlockPath{n}];
                gotoblk = [obj.system '/' obj.gotoBlockPath{n}];
                set_param(inblk,'Position',[20 30+40*(n-1) 50 44+40*(n-1)]);
                set_param(gotoblk,'Position',[70 30+40*(n-1) 70+FromGotoWidth 44+40*(n-1)],'ShowName','off');
                ph = get_param(inblk,'LineHandles');
                % remove connected line
                if ph.Outport(1) ~= -1
                    delete_line(ph.Outport(1))
                end
                add_line(obj.system,[get_param(inblk,'Name') '/1'],...
                    [get_param(gotoblk,'Name') '/1'],'autorouting','on')
            end
        end
        %%
        function obj = updateBlock(obj,sys)
            obj.system = sys;
        end
        %%
    end % method
    methods (Static)
        function preloadLibrary()
            % Preload nessesary library
            if isempty(find_system('SearchDepth', 0, 'Name', 'simulink'))
                load_system('simulink');
            end
            if isempty(find_system('SearchDepth', 0, 'Name', 'sldvlib'))
                load_system('sldvlib');
            end
            if isempty(find_system('SearchDepth', 0, 'Name', 'propertySpecificationOperatorLib'))
                load_system('propertySpecificationOperatorLib')
            end
            if isempty(find_system('SearchDepth', 0, 'Name', 'propertySpecificationLib'))
                load_system('propertySpecificationLib')
            end
        end
        function eqStrLen = getMaxEquationStringLength(plist)
            % get length of maximum number of string in given equations
            eqStrLen  = 0;
            % find maximum length of literal equation
            for n=1:length(plist.elem)
                if ~isempty(plist.elem(n).Equation)
                    if numel(plist.elem(n).Equation) > eqStrLen
                        eqStrLen = numel(plist.elem(n).Equation);
                    end
                end
            end
        end
        %%
        function verLen = getVerLen(InputVar)
            % find maximum length of variable name
            verLen = 0;
            for n=1:length(InputVar)
                if numel(InputVar{n}) > verLen
                    verLen = numel(InputVar{n});
                end
            end
        end
        function allEqs = getAllEqs(plist)
            allEqs = {};
            for n=1:length(plist.elem)
                allEqs{end+1} = plist.elem(n).Equation; %#ok
            end
        end
    end
    
end