%% DEADPIXELS  Removes spots in an image by smoothing via 2-D convolution

%% Load image
adam = imread('adamtruck.jpg');
%  Convert to grayscale
adamgr = mean(double(adam),3);

%% Set parameters
%  Number of "dead" pixels
nnoise = 200;
%  Size of smoothing mask (in pixels)
nmask = 3;

%% Make dead pixels
n = numel(adamgr);
k = randperm(n);
%  Set random selection to white (255)
adamgr(k(1:nnoise)) = 255;

%% Do smoothing
%  Make mask
w = ones(nmask)/(nmask*nmask);
%  Do convolution
adamsm = conv2(adamgr,w,'valid');

%% View original and smoothed images
%  Original
figure, colormap('gray')
imagesc(adamgr)
axis image
%  Smoothed
figure, colormap('gray')
imagesc(adamsm)
axis image
