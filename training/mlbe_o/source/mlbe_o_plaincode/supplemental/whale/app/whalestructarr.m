%% WHALESTRUCTARR  Makes a structure array and passes one element to CALLMODEL_STRUCT

%% Make 3 whale structures in an array
load('whaleimages')
%  Element 1
aquarium(1).name = 'Mushu';
aquarium(1).fundamentalfreq = 175;
aquarium(1).amplitude = 2;
aquarium(1).decayrate = 1.5;
aquarium(1).modulationfreq = 0.65;
aquarium(1).harmonics = 3;
aquarium(1).image = mushu;
%  Element 2
aquarium(2).name = 'Willy';
aquarium(2).fundamentalfreq = 180;
aquarium(2).amplitude = 2.5;
aquarium(2).decayrate = 1.9;
aquarium(2).modulationfreq = 0.5;
aquarium(2).harmonics = 5;
aquarium(2).image = willy;
%  Element 3
aquarium(3).name = 'Shamu';
aquarium(3).fundamentalfreq = 165;
aquarium(3).amplitude = 1;
aquarium(3).decayrate = 0.8;
aquarium(3).modulationfreq = 1.0;
aquarium(3).harmonics = 4;
aquarium(3).image = shamu;

%% Choose one whale and pass it to the function
whalenum = menu('Choose your whale',{aquarium.name});
%  Extract the chosen whale structure from the array
mywhale = aquarium(whalenum);
%  Pass the structure to the function
model = callmodel_struct(mywhale);

%% Visualize the result
whaleplot(model)
%  Uncomment the following line to hear the call
%  whaleplay(model)
