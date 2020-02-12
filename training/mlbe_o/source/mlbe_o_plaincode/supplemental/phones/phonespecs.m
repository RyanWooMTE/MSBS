%% Load a table of data
load phoneData

%% Sort by one variable
byWeight = sortrows(phones,'Weight');
%  View the specs for the lightest and heaviest phones
byWeight([1,end],:)

%% Extract a portion of the table
%  Define the names of the variables to extract
vars = {'Manufacturer','Name','Weight','Height','Width','Depth','Processorspeed'};
under150 = byWeight(1:14,vars);

%% Extract data from the table using dot indexing
weight = under150.Weight;
speed = under150.Processorspeed;
scatter(weight,speed)
xlabel('Weight [g]'), ylabel('Processor speed [MHz]')
title('Smart phone specs')

%% Extract data from the table using named table indexing
%  Define the names of the variables to extract
vars = {'Height','Width','Depth'};
%  Extract the data as a matrix
dims = under150{:,vars};

%% Add new variables to the table
volume = prod(dims,2);
under150.Volume = volume;
density = weight./volume;
under150.Density = density;

%% Modify the table's properties
under150.Properties.VariableUnits = {'','','g','cm','cm','cm','MHz','cm^3','g/cm^3'};
