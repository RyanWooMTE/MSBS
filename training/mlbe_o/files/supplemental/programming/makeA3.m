function A = makeA3(m,n)

% MAKEA3 General purpose matrix creation function, v.3.
%
% A = MAKEA3(m,n) creates an m x n matrix A for which 
% the I, J th element is given by an arbitrary rule f, 
% specified in the local function.
%
% See also: MAKEA1, MAKEA2.

% Put the row and column indices in vectors.
R = 1:m;
C = 1:n;
% Call meshgrid to generate arrays that, face-to-face,
% give all combinations of the indices.  Meshgrid usually works with (x,y)
% coordinates: x is across (columns), y is down (rows)
[CC,RR] = meshgrid(C,R);
% Now call the local function a single time, passing all 
% combinations of indices at once.
A = f(RR,CC);

function a = f(I,J)
a = I + J;  % Edit this line to change the matrix creation rule. 