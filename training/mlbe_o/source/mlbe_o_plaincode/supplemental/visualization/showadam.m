%% SHOWADAM  Shows a true color image and its component (RGB) planes

%% Load data
truck = imread('adamtruck.jpg');
whos truck

%% View image
figure('units','normalized','position',[0.25,0.3,0.5,0.6])
%  Set colormap to gray -- this affects only the RGB plane slices
colormap(gray(256))
%  True color image
subplot(2,3,2)
image(truck), axis image, axis off
title('Wow, a truck!')

%  Planes.  Each plane is a matrix => IMAGE treats it as an indexed image
%  Gray colormap shows the intensity in monochrome
cname = {'Red','Green','Blue'};
for k=1:3
    subplot(2,3,3+k)
    image(truck(:,:,k)), axis image, axis off
    title([cname{k},' plane'])
end
