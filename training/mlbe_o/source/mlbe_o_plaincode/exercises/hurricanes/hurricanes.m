%% HURRICANES Solution to "Atlantic Hurricanes" exercise

%% 1. Load MAT-file
load hurricaneData

%% 2. Plot the wind speeds through time
figure
plot(Dates,Windspeed,'.')
xlabel('Date')
ylabel('Wind speed [mph]')
title('Hurricane Wind Speeds')

%% 3. Find when the 10 highest wind speeds were recorded
[byWS,byWSidx] = sort(Windspeed,'descend');
windiest = Dates(byWSidx(1:10))

%% 4. Determine month for each hurricane
mth = month(Dates);

%% 5. Make a histogram of the number of observations by month
figure
histogram(mth,'BinMethod','integers')
xlabel('Month')
ylabel('Number of observations')
