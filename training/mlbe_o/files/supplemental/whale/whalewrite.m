%% WHALEWRITE Demonstrates the use of AUDIOWRITE for exporting audio data.
%
% See also: WHALECALL.M

%% Run callmodel
callmodel
call = call/max(abs(call));

%% Interpolate call model to a finer timescale
fs = 44100;
tfine = t(1):(1/fs):t(end);
callfine = interp1(t,call,tfine,'spline');

%% Write the modeled call to an MP4 file 
audiowrite('whale.mp4',callfine,fs)

%% Open the default Windows media player and listen to the file
winopen('whale.mp4')