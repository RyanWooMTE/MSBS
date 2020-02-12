%% MARRIAGELOGIC  Uses logical indexing to highlight certain points on a plot

%% Load data
load ausmarriage

%% Convert dates
t = datenum(dates,'mm/dd/yyyy');
%  Determine day of the week
days = weekday(t);

%% Create logical arrays
sun = days==1;
wed = days==4;

%% Plot results
figure
%  Plot all data, then use logical variables to index into full data set to
%  plot subsets (Sundays [x] and Wednesdays [o])
plot(t,M,t(sun),M(sun),'x',t(wed),M(wed),'o')
%  Annotate
axis tight
datetick('x','dd-mmm')
xlabel('date')
ylabel('Marriages')
title('Australian marriages, 2007')
legend({'daily','Sundays','Wednesdays'},'location','north')
