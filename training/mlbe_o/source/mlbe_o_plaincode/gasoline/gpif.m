% GPIF  Uses an IF statement to check if data exists before plotting.

%% Load data
load gPrices

%% Choose a country
% Enter a country name without capitalization to see the effect of the warning.
myctry = inputdlg('Enter a country: ');
myctry = myctry{1};
idx = strcmpi(myctry,country);

%% Check to see if data exists before plotting

if any(idx)  % Data exists?
    % Extract data for the chosen country
    myPrices = Prices(:,idx);
    % Check for proper capitalization of country name
    if ~strcmp(myctry,country{idx})
        warning(['Entered ',myctry,'. Modified to ',country{idx},'.'])
        myctry = country{idx};
    end
    % Make plot
    plot(Year,myPrices,'o-')
    xlabel('Year')
    ylabel([myctry,' prices'])
else
    % No data -- error!
    error(['No data for ',myctry])
end