%% ADAMREADWRITE  Reads and writes an image file to/from disk

%% Read image from file
truck = imread('adamtruck.tif');
%  View
figure
image(truck)
axis image

%% Manipulate image
truck(:,:,2) = flipud(truck(:,:,2));
truck(:,:,1) = fliplr(truck(:,:,1));
%  View results
figure
image(truck)
axis image

%% Write image to file
imwrite(truck,'at_colorspin.jpg','jpg')

%% Check results
winopen('at_colorspin.jpg')
