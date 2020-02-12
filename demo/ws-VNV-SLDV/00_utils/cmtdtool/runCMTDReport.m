classdef runCMTDReport < handle
    % runCMTDReport  A class to create automatic test report generation
    %
    
    %   Copyright 2010-2011 The MathWorks, Inc.
    
    
    %% Propertis
    properties
        Model;
        Signal;
        FigFile;
        SimData;
        Setting;
        SDI;
    end
    methods
        function obj = runCMTDReport(blk)
            %%  Constructor
            if ~exist('blk','var')
                obj.Model.TestSubSys = gcb;
                obj.Model.TargetModel=bdroot(gcb);
            else
                if strcmp(blk,bdroot(blk))
                    % assuming SLDV test harness
                    hblk = find_system(blk,'SearchDepth',1,'Regexp', 'on','Name','^Test Unit');
                    if numel(hblk) == 1
                        blk = hblk{1};
                    end
                end
                obj.Model.TestSubSys = blk;
                obj.Model.TargetModel=bdroot(blk);
            end
            obj.Setting.ResultDir = fullfile(pwd,'figs');
            obj.Setting.FigPosition = [800 200];
            obj.Setting.PaperPosition = [0 0 15 5];
            % Reguler expression to find expected output signals
            obj.Setting.ExpectedSigStr='^Exp';
            % Reguler expression to find assertion signals
            obj.Setting.AssertionSigStr='^Assert';
            obj.Setting.ReportFileName = sprintf('%s_report',obj.Model.TargetModel);
            obj.Setting.isUseSDI = false;
            obj.Setting.usePortNameWhenNoSignalName = true;
            obj = obj.findSignalBuilderBlock;
            obj = obj.setSignalLoggingExpected;
            obj = obj.setSignalLoggingAssertion;
            obj = obj.setSignaLoggingTestSubSys;
            obj.configureForSDI();
            %% isJapaneseEnv
            if isJapaneseEnv();
                obj = obj.setLocale('ja');
            else
                obj = obj.setLocale('en');
            end
            
            if ~exist(obj.Setting.ResultDir,'dir')
                mkdir(obj.Setting.ResultDir)
            end
        end
        %% Configurations
        function obj = setLocale(obj,lang)
            switch lang
                case 'ja'
                    obj.Setting.ResultStr.OK='OK';
                    obj.Setting.ResultStr.NG='NG';
                    obj.Setting.ResultStr.NA='-';
                    if obj.Setting.isUseSDI
                        obj.Setting.RPTfile = 'runCMTDreportSDI.rpt';
                    else
                        obj.Setting.RPTfile = 'runCMTDreport.rpt';
                    end
                case 'en'
                    obj.Setting.ResultStr.OK='Pass';
                    obj.Setting.ResultStr.NG='Fail';
                    obj.Setting.ResultStr.NA='-';
                    obj.Setting.RPTfile = 'runCMTDreport_en.rpt';
            end
        end
        function obj = findSignalBuilderBlock(obj)
            % Find SignalBuider blocks
            blk=find_system(obj.Model.TargetModel,'MaskType','Sigbuilder block');
            if length(blk)>1 || isempty(blk)
                error('No or more than two Signal Builder blocks found in the model.')
            end
            obj.Model.SigBuilBlk=blk{1};
        end
        function configureForSDI(obj)
            set_param(obj.Model.TargetModel,'SaveOutput','on', ...
                'SaveFormat', 'StructureWithTime');
              
        end
        function grp = getSignalGroup(obj,nGrp)
            % Get group name in the SignalBuilder
            [t1,t2,t3,group]=signalbuilder(obj.Model.SigBuilBlk);
            if ~exist('nGrp','var')
                % No input argument means all group names
                grp=group;
            else
                % n-th group name if 2nd input argument is given
                grp = group{nGrp};
            end
        end
        function obj = setSignalLoggingExpected(obj)
            % Set logging signals on Expected Output signals
            obj.Signal.ExpectedSig = obj.setSignalLoggingRegex(obj.Setting.ExpectedSigStr);
        end
        function obj = setSignalLoggingAssertion(obj)
            % Set logging signals on Assertion signals
            obj.Signal.AssertionSig = obj.setSignalLoggingRegex(obj.Setting.AssertionSigStr);
        end
        
        function obj = setSignaLoggingTestSubSys(obj)
            % Set logging signals on Test targetted Subsystem
            lineH = get_param(obj.Model.TestSubSys,'LineHandles');
            portH = get_param(obj.Model.TestSubSys,'PortHandles');
            
            for n=1:length(portH.Inport)
                if ~isempty(get(portH.Inport(n),'Name'))
                    set(get(lineH.Inport(n),'SrcPortHandle'),'DataLogging',1);
                    obj.Signal.Inport{n} = get(portH.Inport(n),'Name');
                else
                    if obj.Setting.usePortNameWhenNoSignalName
                        % Use port name when signal name is not specified.
                        blk = find_system(obj.Model.TestSubSys,'SearchDepth',1,'BlockType','Inport','Port',num2str(n));
                        if length(blk) == 1
                            sigName = get_param(blk{1},'Name');
                            set(lineH.Inport(n),'Name',sigName);
                            set(get(lineH.Inport(n),'SrcPortHandle'),'DataLogging',1);
                            obj.Signal.Inport{n} = get(portH.Inport(n),'Name');                            
                        end
                    else
                        obj.Signal.Inport{n} = '';
                    end
                end
            end
            for n=1:length(portH.Outport)
                if ~isempty(get(portH.Outport(n),'Name'))
                    set(portH.Outport(n),'DataLogging',1);
                    obj.Signal.Outport{n} = get(portH.Outport(n),'Name');
                else
                    if obj.Setting.usePortNameWhenNoSignalName
                        % Use port name when signal name is not specified.
                        blk = find_system(obj.Model.TestSubSys,'SearchDepth',1,'BlockType','Outport','Port',num2str(n));
                        if length(blk) == 1
                            sigName = get_param(blk{1},'Name');
                            set(lineH.Outport(n),'Name',sigName);
                            set(get(lineH.Outport(n),'SrcPortHandle'),'DataLogging',1);
                            obj.Signal.Outport{n} = get(portH.Outport(n),'Name');
                        end
                    else
                        obj.Signal.Outport{n} = '';
                    end
                end
            end
        end
        function enableModelSignalLogging(obj)
            % Enable SignalLogging on model configuration
            set_param(obj.Model.TargetModel,'SignalLogging','on')
        end
        function name = getModelSignalLoggingName(obj)
            name = get_param(obj.Model.TargetModel,'SignalLoggingName');
        end
        
        %% For simulations
        function obj = runSim(obj,nSig)
            [time,tmp2]=signalbuilder(obj.Model.SigBuilBlk);
            obj.enableModelSignalLogging;
            signalbuilder(obj.Model.SigBuilBlk,'ACTIVEGROUP',nSig);
            sim(obj.Model.TargetModel,[min([time{:,nSig}]) max([time{:,nSig}])]);            
            obj.SimData.CurrentSimNum = nSig;
            obj.SimData.CurrentLogsOut = eval(obj.getModelSignalLoggingName);
            assignin('base',obj.getModelSignalLoggingName,eval(obj.getModelSignalLoggingName));
        end
        
        function obj = runSimAll(obj)
            % Run all simulations and draw figures
            Nsig = length(obj.getSignalGroup);
            open_system(obj.Model.SigBuilBlk)
            if obj.Setting.isUseSDI && Simulink.sdi.getRunCount > 0
                Simulink.sdi.clear;
                warning('cmtdtool:runCMTDReport:SDIClear','Simulation Data Inspector has been cleared')
            end
            
                
            for n=1:Nsig
                fprintf('Running %d/%d..',n,Nsig)
                obj = obj.runSim(n);
                obj = obj.storeSDI(sprintf('Test%d',n));
                if ~obj.Setting.isUseSDI
                    obj = obj.plotCurrentResults;
                    obj = obj.resultComparison;
                end
                fprintf('End\n');
            end
        end
        function obj = storeSDI(obj,TestName)
            obj.SDI.runID = Simulink.sdi.createRun(TestName,'base',{obj.getModelSignalLoggingName});
        end
        function runReport(obj)
            report(obj.Setting.RPTfile)
        end
        function obj = resultComparison(obj)
            isValid = true;
            isOK = ones(length(obj.Signal.AssertionSig),1);
            for n=1:length(obj.Signal.AssertionSig)
                sig = getSiginLogsOut(obj,obj.Signal.AssertionSig{n});
                if isempty(sig)
                    % Disable if Signal is empty
                    isValid = false;
                    obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).eachResultStr{n}=obj.Setting.ResultStr.NA;
                elseif any(sig.Data==false)
                    % Fail result if there is false
                    isOK(n) = false;
                    obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).eachResultStr{n}=obj.Setting.ResultStr.NG;
                else
                    % Pass result if there is no false
                    obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).eachResultStr{n}=obj.Setting.ResultStr.OK;
                    
                end
            end
            % Pass or Fail for all signals
            if ~isValid
                obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).All = obj.Setting.ResultStr.NA;
            elseif all(isOK)
                obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).All = obj.Setting.ResultStr.OK;
            else
                obj.SimData.ComparisonResult(obj.SimData.CurrentSimNum).All = obj.Setting.ResultStr.NG;
            end
            
        end
        %% For Drawing
        function obj = plotCurrentResults(obj)
            % Draw inputs, outpus, expected outputs, and assertion signals
            obj.FigFile(obj.SimData.CurrentSimNum).InputSig=...
                plotCurrentSig(obj,obj.Signal.Inport,'InputSig');
            obj.FigFile(obj.SimData.CurrentSimNum).OutputSig=...
                plotCurrentSig(obj,obj.Signal.Outport,'OutputSig');
            obj.FigFile(obj.SimData.CurrentSimNum).ExpectedSig=...
                plotCurrentSig(obj,obj.Signal.ExpectedSig,'ExpectedSig');
            obj.FigFile(obj.SimData.CurrentSimNum).AssertionSig=...
                plotCurrentSig(obj,obj.Signal.AssertionSig,'AssertionSig');
        end
        
        function figFile = plotCurrentSig(obj,SigNames,FileName)
            % Draw all signals included in SigNames and save as file
            figFile = {};
            Nsig = length(SigNames);
            ScreenPos = get(0,'ScreenSize');
            fh = figure('Position',[ 1 ScreenPos(4)/2 obj.Setting.FigPosition],...
                'Color',[1 1 1]);
            %,'PaperPosition',obj.Setting.PaperPosition
            for n=1:Nsig
                %subplot(Nsig,1,n)
                %sig = obj.SimData.CurrentLogsOut.(SigNames{n});
                try
                    sig = getSiginLogsOut(obj,SigNames{n});
                    if length(size(sig.Data)) > 2 && numel(sig.Time)==numel(double(sig.Data))
                        ydata = reshape(double(sig.Data),size(sig.Time));
                    else
                        ydata = sig.Data;
                    end
                    plot(sig.Time,ydata,'r-x')
                    
                    ylabel(SigNames{n},'Interpreter','none')
                    title(SigNames{n},'Interpreter','none')
                    xlabel('Time')
                catch ME
                    disp(ME.message)
                    uicontrol('Style','text','String','Graph not available',...
                        'Units','Pixel','Position',[200 100 400 50],'BackGroundColor',[1 1 1],'FontSize',20)
                end
                figFile{n} = fullfile(obj.Setting.ResultDir,...
                    sprintf('%s_Sig%03d_Sim%03d.bmp',FileName,n,obj.SimData.CurrentSimNum)); %#ok
                drawnow;
                print(fh,'-dbitmap','-r300',figFile{n});
            end
            close(fh)
        end
        
        
        %% Helper function
        function signal = getSiginLogsOut(obj,signame)
            obj.SimData.CurrentLogsOut.unpack('all');
            try
                signal = eval(signame);
            catch
                % Make it empty when no signal logging
                signal = [];
            end
        end
        function clearAllSignalLogging(obj)
            lineH = find_system(obj.Model.TargetModel,'FindAll','on', 'SearchDepth',1,'Regexp', 'on','type','line');
            for n=1:length(lineH)
                set(lineH(n),'DataLogging',false);
            end
        end
        function logSigName = setSignalLoggingRegex(obj,pat)
            % Set signal logging on signals which match regular expression pat
            lineH = find_system(obj.Model.TargetModel,'FindAll','on', 'LookUnderMasks','all','FollowLinks','on','Regexp', 'on','type','line','Name',pat);
            logSigName = {};
            ph = {};
            for n=1:length(lineH)
                ph{n}=get(lineH(n),'SrcPortHandle'); %#ok
            end
            for n=1:length(ph)
                set(ph{n},'DataLogging',1);
                logSigName{n}=get(ph{n},'UserSpecifiedLogName'); %#ok
            end
        end
    end
end