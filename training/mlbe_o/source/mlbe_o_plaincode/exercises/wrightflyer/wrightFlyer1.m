%% Solution to Wright Flyer Wind Tunnel Test I exercise

%% 1. Load data

load wrightWindTunnel

%% 2. Find mean and standard deviation

meanFl = mean(lift);
stdFl = std(lift);
meanFd = mean(drag);
stdFd = std(drag);

% Verify they are reasonably consistent across tests
disp('The mean and standard deviation of the lift force measurements are:')
disp([meanFl;stdFl])
disp('The mean and standard deviation of the drag force measurements are:')
disp([meanFd;stdFd])

%% 3. Calculate coefficient of drag

A = 510;
CD = drag./(A*Pd);

%% 4. Plot drag coefficients

plot(alpha,CD,'o-')
xlabel('Angle of attack [degrees]')
ylabel('Coefficient of drag (C_D)')
legend('Run 1','Run 2','Run 3','Run 4','Run 5','Location','NorthWest')
