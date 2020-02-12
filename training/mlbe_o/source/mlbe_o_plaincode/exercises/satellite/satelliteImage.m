%% Solution to _Satellite Terrain Image_ exercise

%% 1. Load the file surfaceData.mat
load surfaceData

%% 2. Display Altitude (vs. Longitude and Latitude) using the following functions:
% a. SURF
figure
surf(Longitude, Latitude, Altitude)
xlim([36 39])
ylim([-5 -2])
zlim([0 5000])
title('SURF')

%% b. MESH
figure
mesh(Longitude, Latitude, Altitude)
xlim([36 39])
ylim([-5 -2])
zlim([0 5000])
title('MESH')

%% c. CONTOUR (with 20 levels)
figure
contour(Longitude, Latitude, Altitude, 20)
title('CONTOUR')

%% d. CONTOURF (with 20 levels)
figure
contourf(Longitude, Latitude, Altitude, 20)
title('CONTOURF')

%% e. CONTOUR3 (with 50 levels)
figure
contour3(Longitude, Latitude, Altitude, 50)
xlim([36 39])
ylim([-5 -2])
zlim([0 5000])
title('CONTOUR3')

%% f. IMAGESC
figure
imagesc(Altitude)
title('IMAGESC')
