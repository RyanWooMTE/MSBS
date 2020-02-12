%% SMOOTH2D  2-dimensional smoothing

%% Create data with noise
x = 1:0.25:2*pi;
y = 1:0.25:2*pi;
[X,Y] = meshgrid(x,y);
Z = sin(X).*sin(Y) + 0.4*rand(size(X));

%% View original data
figure
surf(X,Y,Z)

%% Do smoothing
span = 5;
% Create the smoothing window.
window = ones(span,span)/span^2;
% Filter the data with a convolution and return the central part.
smZ = convn(Z,window,'same');

%% View smoothed data
figure
surf(X,Y,smZ)
