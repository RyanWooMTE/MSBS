function predictedusage = analysis_func(datafile,polydegree,predictdate)
% ANALYSIS_FUNC  Performs analysis on electricity usage data
%  
% Inputs: 
% datafile - the name of the file from which to read the data [string]
% polydegree - the degree of the polynomial to fit to the data [scalar]
% predictdate - the end date at which to predict the usage [datetime]
%
% Outputs:
% predictedusage - the predicted usage at predictdate [scalar]

% Import data (with NaNs)
data = readtable(datafile);
sector = data.Properties.VariableNames{2};
usage = data{:,sector};
dates = data.Date;

% Normalize data from monthly usage to average daily usage
d = dates;
d(end+1) = d(end) + calmonths(1);
daysInMth = days(diff(d));
usage = usage./daysInMth; % per-day usage
% Fill missing data
usage = fillmissing(usage,'spline');

% Fit trend model
elapsedYears = years(dates - dates(1));
c = polyfit(elapsedYears,usage,polydegree);

endDuration = years(predictdate - dates(1));
elYrFit = linspace(0,endDuration,501);
usageFit = polyval(c,elYrFit);
predictedusage = usageFit(end);

% Display the predicted usage.
predictdate.Format = 'MMM yyyy';
disp(['Predicted ',sector,' usage in ',char(predictdate),...
' is ',num2str(predictedusage),' MWh/day'])

% Plot the data and model together.
plot(dates,usage,'o-','MarkerSize',4,'MarkerFaceColor',[0.5 0.5 1])
hold on
datesFit = dates(1) + years(elYrFit);
plot(datesFit,usageFit,'Color',[0.75 0 0],'LineWidth',2)
hold off
xlabel('Date')
ylabel('Usage [MWh/day]')
legend([sector ' data'],'Modeled trend','Location','NW')

end
