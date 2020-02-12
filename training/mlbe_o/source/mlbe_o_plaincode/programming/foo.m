% FOO  Simple function to show workspace concepts

function y = foo(x)

a = sin(x); % local variable
x = x + 1;  % x changes locally, but not in calling workspace
b = sin(x); % local variable

y = a*b;    % return value
