% CALLMODEL_FOR Models a blue whale B call (FOR-loop version)
%
% Uses a model of the form
% y = A.*y0
% where A = A0*exp(-B*t).*sin(2*pi*fm*t)
% and y0 is a sum of harmonics
% yn = sin(2*pi*n*f0*t)

% Create the time base for the signal.
fs = 4000;
t = 0:(1/fs):1.5;

% Set the fundamental frequency of the call.
f0 = 175;

% How many harmonics?
N = 4;

% Create the harmonics.
y0 = zeros(size(t));
for k = 1:N
    y0 = y0 + sin(2*pi*k*f0*t);
    figure(k)
    plot(t(1:200),y0(1:200))
end

% Set the additional parameters in the model.
A0 = 2; % Initial amplitude.
B  = 1.5; % Amplitude decay rate.
fm = 0.65; % Frequency of the modulating envelope.
% Create the envelope
A  = A0*exp(-B*t).*sin(2*pi*fm*t);

% Create the call.
call = A.*y0;

% Plot the model call and listen to it.
figure
plot(t,call)
xlabel('Time')
ylabel('Amplitude')
title('{\bf Blue Whale B Call Model}')
soundsc(call,fs)
