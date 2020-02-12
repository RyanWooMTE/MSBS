%% CASSINIPATH2 Solution to "The Cassini-Huygens Spacecraft II" Exercise

%% 1. Run the solution to the previous exercise
cassiniPath1

%% 2. Find Cassini's smallest distance to sun, and the year/day it happened
[minRad,minRadIdx] = min(Radius);
yearMin = Year(minRadIdx);
monthMin = Month(minRadIdx);
dayMin = Day(minRadIdx);

disp(['The minimum distance from the sun was: ',num2str(minRad),' AU']);
disp(['The minimum distance from the sun occured on: ',num2str(yearMin),':',num2str(monthMin),':',num2str(dayMin),' (YYYY:MM:DD)']);

%% 3. Plot path in Cartesian coordinates

%% 3.a. Convert lon/lat (in degrees) to radians
Azimuth = Longitude*(pi/180);
Elevation = Latitude*(pi/180);

%% 3.b. Convert Radius, Latitude, and Longitude to x,y,z 3D coordinates
[x,y,z] = sph2cart(Azimuth,Elevation,Radius);

%% 3.c. Plot x-y location
figure
plot(x,y)
xlabel('x location [AU]')
ylabel('y location [AU]')
title('Cassini-Huygens location in the Earth-Sun orbital plane')

%% Bonus
figure
plot3(x,y,z)
xlabel('x location [AU]')
ylabel('y location [AU]')
zlabel('z location [AU]')
title('Cassini-Huygens location in the Earth-Sun orbital plane')
