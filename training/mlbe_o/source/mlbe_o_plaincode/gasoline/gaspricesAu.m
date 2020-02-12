load AuDeMx

gal2lit = 0.2642;
Australia = gal2lit*Australia;
plot(Year,Australia,'.-')
title('Annual gasoline prices')
xlabel('Year')
ylabel('Price [$US/L]')