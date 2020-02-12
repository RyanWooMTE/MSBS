%% MYDIVIDE Solves linear systems Ax = b and determines the nature of the solution.
%
% A and b must be defined in the calling workspace.
%
% Call MYDIVIDE to find a solution x = A\b to the system
% and display a message identifying the solution type.
%
% See also MLDIVIDE, LINSOLVE.

%% Solve system using the MATLAB backslash and display result.
x = A\b %#ok

%% Gather basic information about the system.
[m,n] = size(A);
r = rank(A);
R = rank([A,b]);

%% Linear algebra tells us:
% o The system has an exact solution if and only if r == R
% o Solutions are unique if and only if r == n

% Determine type of solution and display a message.
if (r == R)
    disp('Exact solution')
    if (r < n)
        disp('Nonunique')
    else
       disp('Unique')
    end
else
    disp('Least squares solution')
    if (r < n)
        disp('Nonunique')
    else
       disp('Unique')
    end
end
