function [validSelection,covData,cvdo,cvto] = runcvsim(ModelName,simdata,selected,metrics)

simOpts = simget(ModelName);
hWaitbar = waitbar(0,'Recording coverage...');

covData = [];
cvdo = [];
cvto = [];
n=1;
validSelection = selected;
isModifiedExternalInput = false;
oldExternalInput = '';
oldLoadExternalInput = '';

% assign variables defined durig simulations
ignoreVar = {'vars_after';'vars_before';'hasFixptData';'timeSpan';'timeSpan';'timeStep';...
    'TClabel';'sIM_cMD_aRGS_fROM_cVSIM';'idx';'mFixpt'};
vars_before = who;

% exec cvsim for selected test cases
for idx=selected
    try
        TClabel = sprintf('TestCase%02d',idx);
        cvto = cvtest(ModelName,TClabel);
        
        switch metrics
            case 'decision'
                cvto.settings.decision=1;
                cvto.settings.condition=0;
                cvto.settings.mcdc=0;
            case'condition'
                cvto.settings.decision=1;
                cvto.settings.condition=1;
                cvto.settings.mcdc=0;
            case 'MCDC'
                cvto.settings.decision=1;
                cvto.settings.condition=1;
                cvto.settings.mcdc=1;
        end
        
        if length(simdata(idx).time) >= 2
            % the fundamental timeStep can actually be less than that, but
            % that's okay.
            timeStep = min(diff(simdata(idx).time));
            timeSpan = [ simdata(idx).time(1) (simdata(idx).time(end)+timeStep) ];
        else
            timeSpan = [0 10];
        end
        
        hasFixptData = false;
        for mFixpt=1:length(simdata(idx).signals)
            if strcmp(class(simdata(idx).signals(mFixpt).values),'embedded.fi')
                hasFixptData = true;
            end
        end
        if ~hasFixptData
            % This tool supports all version for built-in DataType
            cvdo = cvsim(cvto, timeSpan, simOpts, simdata(idx));
        else
            switch version('-release')
                case  {'2006b','2007a','2007b','2008a','2008b'}
                    ts=simdata2ts(simdata(idx));
                    % creating a string shows a list of comma separated timeseries
                    % variables
                    assignin('base','ts',ts)
                    str='ts{1}';
                    for nts = 2:length(ts)
                        str = sprintf('%s,ts{%d}',str,nts);
                    end
                    if ~isModifiedExternalInput
                        % storing old Configuration Parameter settings
                        oldExternalInput = get_param(ModelName,'ExternalInput');
                        oldLoadExternalInput = get_param(ModelName,'LoadExternalInput');
                        isModifiedExternalInput = true;
                    end
                    set_param(ModelName,'ExternalInput',str)
                    set_param(ModelName,'LoadExternalInput','on')
                    cvdo = cvsim(cvto, timeSpan, simOpts);

                    %error('This tool doesn''t support fixed-point datatype for this version.
                    % Fixed-point datatype is supported on MATLAB R2009a or later')
                case {'2009a','2009b'}
                    % For R2009a and R2009b, sim command accepts only
                    % Simulink.Timeseriese for fixed-point data type.
                    ts = simdata2ts(simdata(idx));
                    str='';
                    for nts = 1:length(ts)
                        str = sprintf('%s,ts{%d}',str,nts);
                    end
                    cvdo = eval(['cvsim(cvto, timeSpan, simOpts' str ');']);
                otherwise
                    cvdo = cvsim(cvto, timeSpan, simOpts, simdata(idx));
            end
        end
        
        if isempty(covData)
            covData = cvdo;
        else
            covData = covData + cvdo;
        end
        waitbar(n/length(selected),hWaitbar,sprintf('Recording coverage (%d/%d)...',n,length(selected)))
        n=n+1;
    catch
        ME = lasterror;
        msg = ME.message;
        warning('sldvmisscovtool:DataMissMatch','simdata(%d) does not match with model''s input\n%s',idx,msg)
        if isfield(ME,'cause')
            for m=1:length(ME.cause)
                disp(ME.cause{m}.message)
            end
        else
            disp(msg)
        end
        validSelection(validSelection==idx)=[]; % un-selected
        
    end
end

if isModifiedExternalInput
    % restoring modified ConfigurationParameter settings
    set_param(ModelName,'ExternalInput',oldExternalInput)
    set_param(ModelName,'LoadExternalInput',oldLoadExternalInput)
end

% assign variables defined durig simulations
vars_after = who;
vars_new = setdiff(vars_after,[vars_before;ignoreVar]);
for n=1:length(vars_new)
    assignin('base',vars_new{n},eval(vars_new{n}));
end

close(hWaitbar)
