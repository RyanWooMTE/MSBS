% ===========================================================
% POPDIR
% AUTHOR: Laurent Royer
% ===========================================================

function [] = popdir(varargin)

global DirStack

% =========================================================
% case of full popdir
% =========================================================

if nargin
  if strcmpi(varargin{1},'all')
    while ~isempty(DirStack)
      popdir;
    end
    return;
  else
    error('ERROR popdir : argument is incorrect');
  end
end

% =========================================================

if ~evalin('base','exist(''DirStack'')')
  error('ERROR : directory stack is empty');
end

if isempty(DirStack)
  evalin('base','clear global DirStack');
  error('ERROR : directory stack is empty');
end

% =========================================================

try
  cd(DirStack{end});
catch
  error('ERROR : directory stack is corrupted');
end

DirStack = DirStack(1:end-1);

if isempty(DirStack)
  evalin('base','clear global DirStack');
end

% =========================================================

if length(dbstack) == 1
  disp(['CHANGING DIRECTORY TO : ',pwd]);
end

% =========================================================
% =========================================================
