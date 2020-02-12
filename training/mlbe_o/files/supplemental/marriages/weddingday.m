%% WEDDINGDAY  Uses date and time functions to show marriage day trends

%% Load data
load ausmarriage

%% Convert dates
t = datenum(dates,'mm/dd/yyyy');
%  Determine day of the week
days = weekday(t);

%% Plot results
figure
plot(days,M,'o')
xlabel('Day of week (1 = Sun, 2 = Mon, etc.)')
ylabel('Number of weddings')

%% Explain an outlier
%  One obvious wedding day:
weekday('14-Feb-2007')

%% Distribution of days
%  accumarray totals M into "bins" defined by days
%  (>> doc accummarray for more details)
daytotals = accumarray(days,M);
figure
pie(daytotals)
legend({'Sun','Mon','Tue','Wed','Thu','Fri','Sat'},'Location','EastOutside')
