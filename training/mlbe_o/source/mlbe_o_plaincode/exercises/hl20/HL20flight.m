% HL20FLIGHT Plots flight path of HL-20
%
% This script loads location data from the HL-20 lifting body and creates a 
% visualization of the flight path in cartesian coordinates.

%% 1. Load data
load HL20data

%% 2. Create plot
plot3(x,y,z)

%% 3. Add title and grid
title('Path of HL-20')
grid on
view(60,20)
