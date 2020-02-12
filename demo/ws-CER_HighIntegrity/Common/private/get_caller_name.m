function [Name,FullName] = get_caller_name(FlagDisp)
% get the name of the caller function

if ~nargin
  FlagDisp = 0;
end

if strcmp(version('-release'),'13')
  [Stack,~] = dbstack;
  StackName = {Stack.name};
else
  [Stack,~] = dbstack('-completenames');
  StackName = {Stack.file};
end

StackLength = length(Stack);

if StackLength<3
  FullName = '';
  Name = '';
else
  FullName = StackName{3};
  [~,Base,Ext] = fileparts(FullName);
  Name = [Base,Ext];
end

if FlagDisp && (StackLength>=4)
  StackLine = {Stack.line};
  disp(' ');
  for i=3:StackLength
    disp(['=> L',num2str(StackLine{i}),' in ',StackName{i}]);
  end
  disp(' ');
end
