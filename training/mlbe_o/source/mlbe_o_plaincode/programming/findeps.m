%% FINDEPS  Find "epsilon", the biggest value such that 1 + epsilon = 1

%% Initialization
x = 1;
y = x;
z = x+y;

%% Loop until x+y == x
while z~=x
    % Divide y by 2
    y = y*0.5;
    z = x+y;
end

%% Report result
%  y is "epsilon"
fprintf('%4.2f + %9.3g is the same as %4.2f\n',x,y,x)
