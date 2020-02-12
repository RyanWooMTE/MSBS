%% Load gas price data
load gCosts

%% Plot gas prices
plot(Year,Australia,'.-')
hold on
plot(Year,Canada,'.--')
plot(Year,Germany,'.--')
plot(Year,Mexico,'.--')
hold off
legend(country,'Location','northwest')
title('Annual gas prices')
xlabel('Year')
ylabel('Price [US$/gallon]')