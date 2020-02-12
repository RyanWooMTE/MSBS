%% PLOTFLIGHT1  Solution to the "Following a Flight I" Exercise.

%% 1.  Load the data
load flightData

%% 2.  Plot the flight with black dots as markers
plot(t,altitude,'k.-') % Plot it with black dots as markers and a solid line

%% 3.  Add annotations to the plot
title('Altitude of a flight from L.A. to Boston')
xlabel('Time (minutes after takeoff)')
ylabel('Altitude (feet above sea level)')
