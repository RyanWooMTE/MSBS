function model = callmodel_fh(whale,postproc)

% CALLMODEL_FH Models a blue whale B call and calls a function on the result.
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
% postproc  A post-processing function to call after the model is computed
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
postproc(model)
