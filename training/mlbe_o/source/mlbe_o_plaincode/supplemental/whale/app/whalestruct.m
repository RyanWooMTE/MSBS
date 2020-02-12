%% WHALESTRUCT  Creates a structure and passes it to CALLMODEL_STRUCT

%% Make a whale structure
whale.name = 'Mushu';
whale.fundamentalfreq = 175;
whale.amplitude = 2;
whale.decayrate = 1.5;
whale.modulationfreq = 0.65;
whale.harmonics = 3;

load('whaleimages')
whale.image = mushu;

%% Pass the structure to the function
model = callmodel_struct(whale)

%% Visualize the result
whaleplot(model)
%  Uncomment the following line to hear the call
%  whaleplay(model)
