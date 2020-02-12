%% PLOTFLIGHT3  Solution to the "Following a Flight III" exercise.  

%% Run PLOTFLIGHT2 solution to previous exercise
plotFlight2

%% 1. Plot vertical lines representing the transtions between centers
%
% Any line is defined by two points.  For this exercise, the lower point of
% the desired vertical line has coordinates (x1,y1) where x1 is the time of
% the transition and y1 is the minimum altitude of the flight (or 0 is just
% as acceptable). The upper point has coordinates (x2,y2) where x2 is the
% time of the transition (so x2 = x1) and y2 is the maximum altitude of the
% flight. When you plot, the PLOT command requires the list of x values
% first and the y values second.  See centers and cities variables for center
% coordinates and regions.

hold on
minAlt = min(altitude);
maxAlt = max(altitude);

plot([centers(1) centers(1)], [minAlt maxAlt],'k')
plot([centers(2) centers(2)], [minAlt maxAlt],'k')
plot([centers(3) centers(3)], [minAlt maxAlt],'k')
plot([centers(4) centers(4)], [minAlt maxAlt],'k')
plot([centers(5) centers(5)], [minAlt maxAlt],'k')

hold off

%% 2. Add the text  
text(15,2000,cities(1,:))
text(70,2000,cities(2,:))
text(125,2000,cities(3,:))
text(165,2000,cities(4,:))
text(210,2000,cities(5,:))
text(249,2000,cities(6,:))