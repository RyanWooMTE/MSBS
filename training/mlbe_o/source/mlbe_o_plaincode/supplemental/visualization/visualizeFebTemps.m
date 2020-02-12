%% Load data
load('TempDataFeb.mat')

%% Show measurement locations
figure
plot(mapLon,mapLat,'k')
hold on
scatter(Longitude,Latitude,5,Temps)

%% Make grid of locations for interpolation
longfine = -10:0.5:30;
latfine = 35:0.5:65;

[longrid,latgrid] = meshgrid(longfine,latfine);

%% Interpolate scattered data onto grid
Tgrid = griddata(Longitude,Latitude,Temps,longrid,latgrid);

%% Visualize temperatures as a surface
figure
surf(longrid,latgrid,Tgrid)
colorbar
view(-105,50)

%% Visualize temperatures as an image
figure
imagesc(longfine,latfine,Tgrid)
colorbar
%  Change y-axis orientation
axis xy
%  Add map
hold on
plot(mapLon,mapLat,'k')
%  Alter colormap so that missing data is shown white
c = colormap;
c(1,:) = [1,1,1];
colormap(c)

%% Visualize temperatures as contours
figure
contour(longrid,latgrid,Tgrid,20)
colorbar
%  Add map
hold on
plot(mapLon,mapLat,'k')
