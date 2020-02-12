%% WHALECALL Signal analysis of a recorded blue whale call.
%
% Data source: Bioacoustics Research Program
%              Cornell University Lab of Ornithology
%              http://birds.cornell.edu/brp/

%% Read in the data and listen to it.
[y,fs] = audioread('bluewhale.au');
%  Note: For versions prior to R2012b, use AUREAD instead of AUDIOREAD
sound(y,fs)
% Blue whale calls are so low that they are barely audible to humans. 
% The time scale in the data has been compressed by a factor of 10 to 
% raise the pitch and make the calls more clearly audible. The recording 
% is of a characteristic blue whale phrase of four calls: ABBB.

%% Visualize the signal.
t = 0:1/fs:(length(y)-1)/fs; % Time base.
figure
plot(t,y)
axis([0 t(end) -0.3 0.3])
text(3,0.2,'A Call')
text(8,0.15,'B Call')
text(13,0.15,'B Call')
text(18,0.15,'B Call')
xlabel('Time')
ylabel('Amplitude')
title('{\bf Blue Whale Phrase: ABBB}')

%% Index into the signal to better see the first B call.
BCall = y(2.45e4:3.10e4);
tB = 0:1/fs:(length(BCall)-1)/fs; % Time base.
figure
plot(tB,BCall)
axis([0 tB(end) -0.3 0.3])
xlabel('Time')
ylabel('Amplitude')
title('{\bf Blue Whale B Call}')
