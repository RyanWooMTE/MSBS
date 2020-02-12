%% Load gas price data
load AuDeMx

%% Convert prices to $US/L
gal2lit = 0.2642;
Australia = gal2lit*Australia;
Germany = gal2lit*Germany;
Mexico = gal2lit*Mexico;

%% Plot gas prices
plot(Year,Australia,'.-')
hold on 
plot(Year,Germany,'.--')
plot(Year,Mexico,'.--')
hold off

title('Annual gasoline prices')
xlabel('Year')
ylabel('Price [$US/L]')
legend('Australia','Germany','Mexico','Location','northwest')