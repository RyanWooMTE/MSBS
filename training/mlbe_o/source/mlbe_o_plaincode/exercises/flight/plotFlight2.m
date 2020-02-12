%% PLOTFLIGHT2  Solution to the "Following a Flight II" exercise.

%% Load data and create plot from previous exercise
plotFlight1

%% 1. Find the bad altitude value
tBad = 257; % Find this by zooming in on the plot from plotFlight1.

%% 2. Replace the value with the mean of the surrounding points
altitude(tBad) = 1/2*(altitude(tBad-1)+altitude(tBad+1));

%% 3. Plot the fixed altitude vector.
plot(t,altitude,'k.-')
title('Altitude of a flight from L.A. to Boston')
xlabel('Time (minutes after takeoff)')
ylabel('Altitude (feet above sea level)')
