%% WORKSPACES
% Look at the function code at the end of this script. We can verify that 
% the function variables are local to the function workspace.
% 
% Watch the base workspace as this script executes.

a = 42;
b = foo(a);


function y = foo(x)
% FOO  Simple function to show workspace concepts

a = sin(x); % local variable
x = x + 1;  % x changes locally, but not in calling workspace
b = sin(x); % local variable

y = a*b;    % return value
end