%% Solution to _Solar Radiation I_ exercise
%% 1. Load data

load solar

%% 2. Find 100-pt moving average

irrad_ma100 = movmean(irrad,100);

%% 3. Plot data and moving average

figure
plot(lambda,irrad,'o','MarkerSize',2)
hold on
plot(lambda,irrad_ma100,'LineWidth',2)
hold off
xlabel('Wavelength [nm]')
ylabel('Irradiance [W/m^2/nm]')
title('Measured solar irradiance')
legend('Raw data','Smoothed (100-point m.a.)')

%% 3. Find 500-pt moving average and plot

irrad_ma500 = movmean(irrad,500);

figure
plot(lambda,irrad,'o','MarkerSize',2)
hold on
plot(lambda,irrad_ma500,'LineWidth',2)
hold off
xlabel('Wavelength [nm]')
ylabel('Irradiance [W/m^2/nm]')
title('Measured solar irradiance')
legend('Raw data','Smoothed (500-point m.a.)')