function [ncall,t] = callmodel_slow(N,f0,A0,B,fm,v)

% CALLMODEL_SLOW Models a blue whale B call (inefficient).
%
% Uses a model of the form
% y = A.*y0 + (random noise)
% where A = A0*exp(-B*t).*sin(2*pi*fm*t)
% and y0 is a sum of harmonics
% yn = sin(2*pi*n*f0*t)
%
% Inputs:
% N     The number of harmonics in the call.
% f0    Fundamental frequency of the call.
% A     Initial amplitude of the call.
% B     Amplitude decay rate.
% fm    Frequency of the modulating envelope.
% v     Amplitude of random noise.
%
% Outputs:
% call  The model call.
% t     Time base for the model call.

% Create the time base for the signal.
fs = 4000;
t = 0:(1/fs):1.5;

% Create the harmonics.
y0 = zeros(size(t));
for k = 1:N
    y0 = y0 + sin(2*pi*k*f0*t);
end

% Create the envelope
A  = A0*exp(-B*t).*sin(2*pi*fm*t);

% Create the call.
call = A.*y0;

% Add channel noise to the call.
for k = 1:length(call)
    n = v*randn;
    ncall(k) = call(k) + n;
end
