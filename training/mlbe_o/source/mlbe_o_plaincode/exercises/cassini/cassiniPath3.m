%% CASSINIPATH3 Solution to "The Cassini-Huygens Spacecraft III" Exercise

%% 1. Load the file cassiniData2
load cassiniData2

%% Extract Year, Month, Day, X, Y, Z
Year = data(:,1);
Month = data(:,2);
Day = data(:,3);
X = data(:,4);
Y = data(:,5);
Z = data(:,6);

%% 2. Compute the radius (distance from sun)
Radius = sqrt(X.^2 + Y.^2 + Z.^2);

%% 3. Determine the dates on which the probe crossed each planet's orbit.
planetRadii = [0.39,0.72,1.0,1.51,5,9.04,19.18,30.06];

% Compute when the probe and each planet had the same distance from the sun
Mercury_index = (Radius == planetRadii(1));
Venus_index = (Radius == planetRadii(2));
Earth_index = (Radius == planetRadii(3));
Mars_index = (Radius == planetRadii(4));
Jupiter_index = (Radius == planetRadii(5));
Saturn_index = (Radius == planetRadii(6));

% Create the output data
Mercury_Date = [Year(Mercury_index) Month(Mercury_index) Day(Mercury_index)];
Venus_Date = [Year(Venus_index) Month(Venus_index) Day(Venus_index)];
Earth_Date = [Year(Earth_index) Month(Earth_index) Day(Earth_index)];
Mars_Date = [Year(Mars_index) Month(Mars_index) Day(Mars_index)];
Jupiter_Date = [Year(Jupiter_index) Month(Jupiter_index) Day(Jupiter_index)];
Saturn_Date = [Year(Saturn_index)  Month(Saturn_index) Day(Saturn_index)];

% Display the output data
disp('Mercury Crossing (YYYY MM DD): ')
disp(Mercury_Date)
disp('Venus Crossing (YYYY MM DD): ')
disp(Venus_Date)
disp('Earth Crossing (YYYY MM DD): ')
disp(Earth_Date)
disp('Mars Crossing (YYYY MM DD): ')
disp(Mars_Date)
disp('Jupiter Crossing (YYYY MM DD): ')
disp(Jupiter_Date)
disp('Saturn Crossing (YYYY MM DD): ')
disp(Saturn_Date)

%% 4. Plot the XY position for each year
%   Extract each year's data
I1997 = (Year == 1997);
I1998 = (Year == 1998);
I1999 = (Year == 1999);
I2000 = (Year == 2000);
I2001 = (Year == 2001);
I2002 = (Year == 2002);
I2003 = (Year == 2003);
I2004 = (Year == 2004);

%   Create the figure and plot in different colors
hold on
plot(X(I1997),Y(I1997),'r')
plot(X(I1998),Y(I1998),'g')
plot(X(I1999),Y(I1999),'b')
plot(X(I2000),Y(I2000),'c')
plot(X(I2001),Y(I2001),'m')
plot(X(I2002),Y(I2002),'y')
plot(X(I2003),Y(I2003),'k')
plot(X(I2004),Y(I2004),'r:')

%% 5. Add in the orbits of Mercury, Venus, Earth, Mars, Jupiter, and Saturn
%  Create a unit circle
theta = linspace(0,2*pi,100);
xc = cos(theta);
yc = sin(theta);

%  Plot each planet's orbit as a dotted black line
plot(planetRadii(1)*xc,planetRadii(1)*yc,'k:')
plot(planetRadii(2)*xc,planetRadii(2)*yc,'k:')
plot(planetRadii(3)*xc,planetRadii(3)*yc,'k:')
plot(planetRadii(4)*xc,planetRadii(4)*yc,'k:')
plot(planetRadii(5)*xc,planetRadii(5)*yc,'k:')
plot(planetRadii(6)*xc,planetRadii(6)*yc,'k:')
