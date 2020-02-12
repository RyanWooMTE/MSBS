%% AUSMARRIAGEAXES  Plots Australian marriage data with dates on the axes

%% Get data
load ausmarriage
t = datenum(dates,'mm/dd/yyyy');

%% Plot data
figure
% Numeric labels
subplot(2,1,1)
plot(t,M)
title('plot without datetick')
% Date labels
subplot(2,1,2)
plot(t,M) 
datetick('x','mmm yy','keepticks')
title('plot with datetick')