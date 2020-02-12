function A = makeA1(m,n)

% MAKEA1 General purpose matrix creation function, v.1.
%
% A = MAKEA1(m,n) creates an m x n matrix A for which 
% the I, J th element is given by an arbitrary rule f, 
% specified in the local function.
%
% See also: MAKEA2, MAKEA3.

for I = 1:m
    for J = 1:n
        A(I,J) = f(I,J); %#ok
    end
end

function a = f(I,J)
a = I + J;  % Edit this line to change the matrix creation rule. 