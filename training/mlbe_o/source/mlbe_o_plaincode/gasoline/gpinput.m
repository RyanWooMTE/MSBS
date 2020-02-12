% GPINPUT Demonstrates various user input methods.

%% Load data
load gPrices

%% Choose a country (INPUTDLG)
myctry = inputdlg('Enter a country:');
idx = strcmp(myctry,country);    %#ok

%% Choose a country (LISTDLG)
idx = listdlg('PromptString','Select a country:',...
              'SelectionMode','single',...
              'ListString',country);
myctry = country{idx};    %#ok

%% Choose a country (INPUT)
myctry = input('Enter a country: ','s');
idx = strcmp(myctry,country);