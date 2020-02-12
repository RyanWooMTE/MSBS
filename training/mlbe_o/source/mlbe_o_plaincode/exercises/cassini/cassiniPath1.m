%% CASSINIPATH1 Solution to "The Cassini-Huygens Spacecraft I" Exercise

%% 1. Load the file cassiniData1.mat
load cassiniData1

%% 2. Plot Radius vs. Time with a blue, dashed line
plot(Time,Radius,'b--')

%% 3. Add annotations
xlabel('Time')
ylabel('Radius [AU]')
title('Cassini-Huygens Radius vs Time')

%% Bonus
tmax = 2.0045e3;
Rmax = 9.04;

hold on
plot(tmax,Rmax,'ro')
