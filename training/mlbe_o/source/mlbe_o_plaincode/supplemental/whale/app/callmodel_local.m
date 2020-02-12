function model = callmodel_local(whale,postproc)

% CALLMODEL_LOCAL Models a blue whale B call (using local functions for post-processing).
%
% Uses a model of the form
% y = A.*y0
% where A0 = A*exp(-B*t).*sin(2*pi*fm*t)
% and y0 is a sum of harmonics
% yn = sin(2*pi*n*f0*t)
% 
% Inputs:
% whale     A structure containing fields:
%           name
%           fundamentalfreq
%           amplitude
%           decayrate
%           modulationfreq
%           harmonics
%           image
% postproc  A string specifying which post-processing function to call after the model is computed
%           Options are 'plot' or 'play'
% 
% Outputs:
% model     A structure containing fields:
%           call
%           t
%           image

% Create the time base for the signal
fs = 4000;
t = 0:(1/fs):1.5;

f0 = whale.fundamentalfreq;
% Create the harmonics
y0 = zeros(size(t));
for k = 1:whale.harmonics
    y0 = y0 + sin(2*pi*k*f0*t);
end

% Create the envelope
A  = whale.amplitude*exp(-whale.decayrate*t).*sin(2*pi*whale.modulationfreq*t);

% Create the call
model.call = A.*y0;
model.t = t;
model.image = whale.image;

% Call post-processing function
switch postproc
    case 'plot'
        whaleplot(model)
    case 'play'
        whaleplay(model)
    otherwise
        error(['Unknown option: ',postproc])
end

function whaleplot(whale)
figure
subplot(1,2,1)
image(whale.image)
axis image
axis off
subplot(1,2,2)
plot(whale.t,whale.call)

function whaleplay(whale)
figure
image(whale.image)
axis image
axis off
fs = 1/(whale.t(2)-whale.t(1));
soundsc(whale.call,fs)
