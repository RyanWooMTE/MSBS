function predictedusage = analysis_struct(model)
% ANALYSIS_FUNC  Performs analysis on electricity usage data
%  
% Inputs: 
% model - a structure containing the following fields:
%    datafile - the name of the file from which to read the data [string]
%    polydegree - the degree of the polynomial to fit to the data [scalar]
%    predictdate - the end date at which to predict the usage [datetime]
%    monthavg - the number of months to use in averaging [scalar]
%    nummonthmodel - the number of months to use in the model [scalar]
%    makeplot - option whether to make a plot or not [logical]
%
% Outputs:
% predictedusage - the predicted usage at predictdate [scalar]

% Extract some of the fields
predictdate = model.predictdate;
monthavg = model.monthavg;
nummonthmodel = model.nummonthmodel;

% Import data (with NaNs)
data = readtable(model.datafile);
sectors = data.Properties.VariableNames(2:end);
usage = data{:,sectors};
dates = data.Date;

% Normalize data from monthly usage to average daily usage
d = dates;
d(end+1) = d(end) + calmonths(1);
daysInMth = days(diff(d));
usage = usage./daysInMth; % per-day usage
% Fill missing data
usage = fillmissing(usage,'spline');

% Fit trend model
% Create a numeric independent variable (from dates) for the data 
elapsedYears = years(dates - dates(1));
% Create a numeric independent variable for the fit
modelend = dates(end);
modelstart = modelend - calmonths(nummonthmodel-1);
modelidx = isbetween(dates,modelstart,modelend);
elapsedYears = elapsedYears(modelidx);

endduration = years(predictdate - dates(1));
elYrPred = linspace(elapsedYears(1),endduration,501);
datesPred = dates(1) + years(elYrPred); % created for plotting


for k = 1:length(sectors)
    u = usage(:,k);
    usageAvg = movmean(u,monthavg);
    % Do polynomial fit
    c = polyfit(elapsedYears,usageAvg(modelidx),model.polydegree);
    % Evaluate fit up to the predict date
    usagePred = polyval(c,elYrPred);
    % Get model value at end date and display result
    predictedusage(k) = usagePred(end);
    predictdate.Format = 'MMM yyyy';
    disp(['Predicted ',sectors{k},' usage in ',char(predictdate),...
    ' is ',num2str(predictedusage(k)),' MWh/day'])
    
    if model.makeplot
        % Plot data, moving average, and model together
        figure
        % Plot data with customized markers
        plot(dates,u,'o-','MarkerSize',4,'MarkerFaceColor',[0.5 0.5 1])
        hold on
        % Add moving average with a green line
        plot(dates,usageAvg(:,1),'Color',[0 .5 0],'LineWidth',2)
        % Add model with a thick red line
        plot(datesPred,usagePred,'Color',[0.75 0 0],'LineWidth',2)
        plot(predictdate,predictedusage(k),'x','MarkerSize',10,'Color',[0.75 0 0],'LineWidth',2)
        hold off
        % Add labels
        xlabel('Date')
        ylabel('Usage [MWh]')
        legend([sectors{k},' Data'],[num2str(monthavg) '-month average'],'Modeled trend','Location','NW')
    end
end

end
