%% Delta-v for a Booster Rocket I exercise
%
% Uses the rocket equation to calculate delta-v (total possible change of
% velocity) for a simple rocket, for a range of fuel masses, assuming that
% increasing fuel mass increases the height of the rocket, and therefore
% the mass of the rocket structure.

%% Set parameters
ve = 2.6;       % exhaust velocity [km/s]
mfix = 6.1;     % fixed mass of rocket [t]
alpha = 0.15;   % ratio of mass of structure to mass of fuel

%% Create vector of fuel masses
m = linspace(100,1000);

%% Calculate delta-v using rocket equation
dv = ve*log(1 + m./(alpha*m+mfix));

%% Plot results
plot(m,dv)
xlabel('Fuel mass [10^3 kg]')
ylabel('\Delta v [km/s]')
title('Total possible change of velocity for a solid booster rocket')
grid on
