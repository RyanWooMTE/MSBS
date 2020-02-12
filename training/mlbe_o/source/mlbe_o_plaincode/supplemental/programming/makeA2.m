function A = makeA2(m,n)

% MAKEA2 General purpose matrix creation function, v.2.
%
% A = MAKEA2(m,n) creates an m x n matrix A for which 
% the I, J th element is given by an arbitrary rule f, 
% specified in the local function.
%
% See also: MAKEA1, MAKEA3.

A = zeros(m,n);  % Preallocate memory for the variable to be created.

for I = 1:m
    for J = 1:n
        A(I,J) = f(I,J);
    end
end

function a = f(I,J)
a = I + J;  % Edit this line to change the matrix creation rule. 