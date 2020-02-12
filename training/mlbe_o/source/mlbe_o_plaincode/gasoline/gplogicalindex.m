%% GPLOGICALINDEX  Uses logical indexing to extract subsets of data

%% Load data
load gPrices

%% Extract countries with prices always < 5
idx = all(Prices < 5);
country(idx)'

% Prices for these countries
Prices1 = Prices(:,idx);

%% Years in which all countries had prices < 4.5
idx = all(Prices < 4.5, 2);
Year(idx)

% Prices for these years
Prices2 = Prices(idx,:);

%% Years where prices in at least 8 of the countries went up
pricesUp = diff(Prices) > 0;
idx = sum(pricesUp, 2) >= 8;
Year([false;idx]) % never take first year

Prices3 = Prices([false;idx],:);
