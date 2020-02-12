function startupWorkshop(useSVN,folder)
%%FUNCTION STARTUPWORKSHOP(STANDARD,USESVN)
% This will setup a WorkShop folder copying the source of the workshop into
% the WorkShop folder according to the chosen STANDARD 
%
% 1. Copy files and folders relevant to the standard
% 2. Optionally on USESVN: Create SVN repo & Add files to the SVN repo
% 3. Move into the WorkShop folder and start the project

% outside the project 
topFolder = fullfile(fileparts(mfilename('fullpath')),'..');

if nargin < 1
    useSVN = 1;
end
if nargin < 2    
    % default put this in parallell to the checked out folder
    folder = fullfile(topFolder,'..'); 
end



wsFolder   = fullfile(folder,'HIWS_Sandbox');
repoFolder = fullfile(folder,'HIWS_Repos');

% 0. Init to avoid problems 
clear mex 
Simulink.ModelManagement.Project.Canvas.Menu.close
pause(1)

fprintf('### Moving workshop to separate directory\n');


% 1. Copy folders to workshop sandbox

fprintf('### Copying files ...\n');
res = loc_queryOverWrite(wsFolder);
if ~res
    error('Could not complete the creation of the workshop');
end


% Copy folders into {project/<from>, workshop/<to>}
folders = {...
    'Certification Workshops.pptx',...
    'CertifKit workshop Project.docx',...
    'Certif',...
    'Common'};

for idx = 1:length(folders)
    src = fullfile(topFolder,folders{idx});     
    dst = fullfile(wsFolder,folders{idx});    
    copyfile(src,dst,'f')        
end

fprintf('   ...OK\n');

% 2. Optionally create repository

if useSVN 
    fprintf('### Creating SVN Repo...\n');
    res = loc_queryOverWrite(repoFolder);
    loc_svnCreateRepoFromExisting(repoFolder,wsFolder);
    fprintf('   ...OK\n');
end

fprintf('Complete, go to standard and open project\n');
% Go to the export
cd(fullfile(wsFolder)); 

%% Local Functions

% Query Overwriting of the folder 
% return result, 1 if overwritten 0 otherwise
function res = loc_queryOverWrite(folder)
if exist(folder,'dir')
   res = input(['Folder ',strrep(folder,'\','\\'),' exists, Overwrite (y/n)[n]:'], 's');
   if strcmp(res,'y') || strcmp(res,'Y')
       res = 1; 
       try           
           rmdir(folder,'s');
       catch ME
           pause(1)
           rmdir(folder,'s');
       end   
       try
          mkdir(folder);
       catch
           pause(1)
           mkdir(folder);
       end
   else
       res = 0; 
       return
   end
   
else
    res = 1;
    mkdir(folder);
end


function loc_svnCreateRepoFromExisting(repofolder,importfolder)

% repofolder   = fullfile(pwd,repofolder);
% importfolder = fullfile(pwd,importfolder);

% create repo
cmdString = sprintf('svnadmin create  --pre-1.6-compatible %s',repofolder);
system(cmdString);
% create repo trunk dir
cmdString=sprintf('svn mkdir file:///%s/trunk -m "Initial revision"',repofolder);
system(cmdString);
% import files -> repo
cmdString=sprintf('svn import -q %s file:///%s/trunk -m "Importing file"',importfolder,repofolder);
system(cmdString);
% checkout repo -> files
cmdString=sprintf('svn checkout --quiet --force file:///%s/trunk %s',repofolder,importfolder);
system(cmdString);

