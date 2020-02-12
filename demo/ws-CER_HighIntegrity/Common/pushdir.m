% ===========================================================
% PUSHDIR
%
% Syntax: pushdir('directory_name');
%
% AUTHOR: Laurent Royer
% ===========================================================
function [varargout] = pushdir(TargetDir)

global DirStack

if nargout
  varargout{1} = 0;
end

if ~evalin('base','exist(''DirStack'')')
  evalin('base','global DirStack');
end

% =========================================================

if isempty(TargetDir)
  return;
end

CurrentDir = pwd;

% =========================================================

if length(TargetDir)>1 && TargetDir(min(2,length(TargetDir)))==':'

  if TargetDir(2)==':'
    FullTargetDir = TargetDir;
  end

else

  FullTargetDir = fullfile(CurrentDir,TargetDir);

end

% =========================================================

try
  cd(FullTargetDir);
catch
  if nargout
    varargout{1} = 4;
    return;
  else
    error(['ERROR : ',TargetDir,' is not a valid directory']);
  end
end

DirStack = [DirStack,{CurrentDir}];

% =========================================================

if length(dbstack) == 1
  disp(['CHANGING DIRECTORY TO : ',pwd]);
end

% =========================================================
% =========================================================
