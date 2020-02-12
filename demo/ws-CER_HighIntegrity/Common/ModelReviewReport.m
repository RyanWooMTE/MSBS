function [] = ModelReviewReport(varargin)
% Model Review Report
% Reviews and Static Analyses at the Model Level
% Model Review Report of all models located in the current directory,
% containing
% - System Design Description
% - Web View
% - MA Static Check Report
% - Manual Review Document


%% Configuration (set flag to false to disable the feature)
Flag.Debug = true;       % execution may be paused through mouse position
Flag.Toc = false;        % elapsed time display
Flag.Echo = true;        % progress messages display

Flag.SDD = false;        % generation of the System Design Description document
Flag.WebView = false;    % generation of the Web View document
Flag.MACheck = false;    % generation of the ModelAdvisor Static Check Report
Flag.MRD = false;        % generation of the Manual Review Document
Flag.MACheckExt = '';

Flag.AddProduct = false; % add to Simulink Project 

Flag.Line =  @()disp('===============================================');

% Now parse the flags passed in function arguments
Flag = parseArgs(Flag,varargin{:});


%% Check the current MATLAB release

AllowedReleases = {'R2011b','R2012a','R2012b'};

Flag.CurrentRelease = ['R',version('-release')];
if ~ismember(Flag.CurrentRelease,AllowedReleases)
    error(['This tool is validated for the following MATLAB releases only: ',...
        sprintf('%s',[char(AllowedReleases),ones(length(AllowedReleases),1)*32]')]);
end


%% Reports location
workDir = getWorkProducts();

% Check that the current directory is relevant
if ~exist(workDir,'dir')
    error('[ERR] "Artefacts" directory is missing');
end

ReportLocation = fullfile(workDir,'ModelReview');
if ~exist(ReportLocation,'dir')
    if exist(ReportLocation,'file')
        error(['[ERR] Cannot create directory <',ReportLocation,'>']);
    else
        mkdir(ReportLocation);
    end
end


%% Models processing
if Flag.Echo,Flag.Line();end

ModelList = getModelList();
NbModel = length(ModelList);

HWaitBar = waitbar(0,'Starting the model review...');

for Ind = 1:NbModel
    
    [~,SrcModelName,~] = fileparts(ModelList(Ind).name);
    SrcSubPath = SrcModelName;
    
    OpenSystemList = get_param(find_system(0,'SearchDepth',0),'name');
    if isempty(OpenSystemList)
        OpenSystemList = {}; 
    elseif ~iscell(OpenSystemList)
        OpenSystemList = {OpenSystemList};
    end
    AlreadyOpen = ismember(SrcModelName,OpenSystemList);
    
    if ~AlreadyOpen
        open_system(SrcModelName);
    end
    
    
%    set_param(SrcModelName,'CheckSSInitialOutputMsg','off');
%    set_param(SrcModelName,'UnderSpecifiedDataTypeMsg','none');
%    set_param(SrcModelName,'SolverPrmCheckMsg','none');
    
    %% Generation of work products (per Subsystem)
    
    if Flag.Debug,ctrlc;end
    if Flag.SDD
        waitbar(3*(Ind-1)/(3*NbModel+1),HWaitBar,[strrep(SrcModelName,'_','\_'),': System Design Description']);
        SDD_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag);
    end
    
    if Flag.Debug,ctrlc;end
    if Flag.WebView
        waitbar((3*(Ind-1)+1)/(3*NbModel+1),HWaitBar,[strrep(SrcModelName,'_','\_'),': WebView']);
        WebView_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag);
    end
    
    if Flag.Debug,ctrlc;end
    if Flag.MACheck
        waitbar((3*(Ind-1)+2)/(3*NbModel+1),HWaitBar,[strrep(SrcModelName,'_','\_'),': Static Checks']);
        
        MACheck_Generate(SrcModelName,SrcSubPath,ReportLocation,Flag);
    end

    if ~AlreadyOpen
        bdclose(SrcModelName);
    end
    
end

%% Generation of work products (overall)
if Flag.Debug,ctrlc;end
if Flag.MRD
    waitbar(3*NbModel/(3*NbModel+1),HWaitBar,'Model Review Document');
    MRD_Generate(ReportLocation,Flag);
end

close(HWaitBar);

end


%% =========================================
function flags = parseArgs(flags, varargin)
    i = 1;
    while i<nargin-1
        if ~ischar(varargin{i}) || ~strncmp(varargin{i},'-',1)
          error('All options must be of type ''-<options>''')                     
        end
        flag = varargin{i};
        flag = flag(2:end);
        i = i+1;
        if i < nargin &&  ~strncmp(varargin{i},'-',1)
            % if the next option is NOT a character that starts with '-'
            flags.(flag) = varargin{i};
            i = i+1;
        else 
            % no value passed, use default; set true
            flags.(flag) = 1; 
        end
    end
end
