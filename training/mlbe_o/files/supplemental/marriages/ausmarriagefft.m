%% AUSMARRIAGEFFT  Performs spectral (frequency) analysis of Australian marriage data

%% Load data
load ausmarriage
t = datenum(dates,'mm/dd/yyyy');

%% Plot data
figure
plot(t,M)
datetick('x','mmm dd')
xlim([t(1) t(end)])
title('Australian Marriages, 2007')
xlabel('Date')
ylabel('Number of Marriages')

%% Frequency analysis.
Y = fft(M-mean(M)); % Take the FFT (after removing the offset)
n = length(Y); % FFT length
nyq = ceil((n+1)/2);
P = Y.*conj(Y)/n; % Compute the power
Fs = 1; % Samples/day
f = (0:nyq-1)*(Fs/n); % Frequency scale (cycles/day)
p = 1./f; % Period scale (days/cycle)

%% Plot the spectrum.
figure
plot(f,P(1:nyq),'.-')
xlabel('Frequency [days^{-1}]')
ylabel('Power')
yl=ylim;
line(1./[7,7],yl,'color','r','linestyle',':')
line(2./[7,7],yl,'color','r','linestyle',':')
line(3./[7,7],yl,'color','r','linestyle',':')
line(2./[365,365],yl,'color',[0 0.5 0],'linestyle',':')

figure
semilogx(p,P(1:nyq),'.-')
xlabel('Period [days]')
ylabel('Power')
yl=ylim;
line([7,7],yl,'color','r','linestyle',':')
line([365,365]/2,yl,'color',[0 0.5 0],'linestyle',':')
