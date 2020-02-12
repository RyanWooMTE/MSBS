%% VEANDG  Solution to Escape Velocity III exercise
function [r,Ve,g] = veandg(planet)

% Extract data from structure input
pname = planet.name;
M = planet.mass;
R = planet.radius;

% Calculate Ve and g
G = 6.673e-11;
r = linspace(R,5*R);
Ve = sqrt(2*G*M./r);
g = G*M./(r.^2);

% Use figure command to create new figure window
figure
% Plot escape velocity on left y-axis
yyaxis left
plot(r,Ve)
ylabel('Escape velocity (V_e) [m/s]')
% Plot gravitational acceleration on right y-axis
yyaxis right
plot(r,g)
ylabel('Acceleration (g) [m/s^2]')
% Add title and x-axis label
xlabel('Distance from planet''s center of mass (r) [m]')
title(['Escape velocity and gravitation acceleration of ',pname])

end