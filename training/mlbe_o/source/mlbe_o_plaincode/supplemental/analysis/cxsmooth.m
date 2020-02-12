%% CXSMOOTH Demonstrates smoothing of time series data

%% Load currency exchange data
load cx
%  Extract dates and exchange rates for Danish Krone
date = Data(:,1);
DKK = Data(:,5);

%% Perform smoothing
%  50-point window
w = ones(50,1)/50;
smDKK1 = filter(w,1,DKK);
%  200-point window
w = ones(200,1)/200;
smDKK2 = filter(w,1,DKK);

%% Plot the results
figure
plot(date,DKK,'.',date,smDKK1,date,smDKK2,'linewidth',2)
axis([min(date),max(date),1.5,4])
datetick('x','mm/yy','keeplimits')
xlabel('Date'), ylabel('Exchange rate')