%% BITSOFADAM Demonstrates the use of IMREAD for importing images.
%
% See also: ADAMTRUCK.TIF

%% Read image
%  Uses optional parameter 'pixelregion' to select particular regions of
%  the image
whole = imread('adamtruck.tif');
truck = imread('adamtruck.tif','pixelregion',{[150,300],[20,140]});
face = imread('adamtruck.tif','pixelregion',{[100,260],[120,260]});

%% Show whole image
figure
image(whole)
axis image

%% Show parts of the image
figure
image(truck)
axis image

figure
image(face)
axis image
