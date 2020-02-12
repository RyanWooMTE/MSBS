%% Predicting Future Electricity Usage

%% Residential Usage 
% Set parameters for the analysis: residential usage, cubic polynomial fit, 
% and predict usage for Jan 2020.
datafile = 'elec_res.xlsx';
polydegree = 3;
enddate = datetime(2020,1,1);
 
% Predict residential usage in Jan 2020 using a cubic polynomial.
res2020 = polyPrediction(datafile,polydegree,enddate);


%%
function predictedusage = polyPrediction(datafile,polydegree,predictdate)

% Inputs:
% 
% * |datafile| - the name of the file from which to read the data [char]
% * |polydegree| - the degree of polynomial to use in fitting the data [scalar]
% * |predictdate| - the date for which to predict usage [datetime]
% 
% Outputs:
% 
% * |predictedusage| - usage predicted by the model at |predictdate| [scalar]
% 
% Import electricity usage data (with NaNs).

data = readtable(datafile);
sector = data.Properties.VariableNames{2};
usage = data{:,2};
dates = data.Date;

% Normalize data from monthly usage to average daily usage.
d = dates;
d(end+1) = d(end) + calmonths(1);
daysInMth = days(diff(d));
usage = usage./daysInMth; % per-day usage
 
% Fill in the missing values.
usage = fillmissing(usage,'spline');
 
% Find the polynomial fit, then evaluate the model through to the prediction 
% date
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
figure
plot(dates,usage,'o-','MarkerSize',4,'MarkerFaceColor',[0.5 0.5 1])
hold on
datesFit = dates(1) + years(elYrFit);
plot(datesFit,usageFit,'Color',[0.75 0 0],'LineWidth',2)
hold off
xlabel('Date')
ylabel('Usage [MWh/day]')
legend([sector ' data'],'Modeled trend','Location','NW')

end