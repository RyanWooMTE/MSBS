%% Delta-v for a Booster Rocket II exercise
% 
% Uses the rocket equation to calculate delta-v (total possible change of
% velocity) for a simple rocket, for a range of fuel masses, assuming that
% increasing fuel mass increases the height of the rocket, and therefore
% the mass of the rocket structure.

%% 1. Previous exercise

ve = 2.6;       % exhaust velocity [km/s]
mfix = 6.1;     % fixed mass of rocket [tonnes (t)]
alpha = 0.15;   % ratio of mass of structure to mass of fuel

% Create a vector of masses from 100 t to 1000 t.
m = linspace(100,1000);

%% 2. Create column vector |perc|

perc = (0.5:0.1:1.5)';

%% 3. Multiply |alpha| by |perc| and plot

dv = ve*log(1 + m./(perc*alpha.*m+mfix));
plot(m,dv)
grid on
title('Total possible \Deltav: Effect of changing \alpha')
xlabel('Fuel mass [10^3 kg]')
ylabel('\Delta v [km/s]')

%% 4. Multiply |mfix| by |perc| and plot

dv = ve*log(1 + m./(alpha*m+mfix*perc));
plot(m,dv)
grid on
title('Total possible \Deltav: Effect of changing m_{fix}')
xlabel('Fuel mass [10^3 kg]')
ylabel('\Delta v [km/s]')