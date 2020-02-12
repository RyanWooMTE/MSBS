%% Solution to _Spectral Measurement_ Exercise
% The spreadsheet |spectra.xlsx| contains 10 columns, each representing the 
% measured spectrum of a star. The value in each row is the observed intensity 
% of a particular wavelength of light. The header information provides the wavelength 
% of the first row ($\lambda_0$) and the difference between subsequent values 
% of the wavelength ($\Delta\lambda$). Wavelengths are given in nm.

%% 1. Import the first column from |spectra.xlsx|
% Below is the programmatic version of importing the first column.
data = xlsread('spectra.xlsx');
HD30584 = data(:,1);

%% 2. Create four scalar variables
% * |lambdastart| containing the value of $\lambda_0$ (630.02)
% * |dlambda| containing the value of $\Delta\lambda$ (0.14)
% * |nObs| containing the value of the number of observations (357)
% * |lambdaend| that contains the last value of the wavelength (that is, the 
%   wavelength corresponding to the last observation), according to the formula
%   $$\lambda_{end} = \lambda_0 + (n_{Obs} - 1)\Delta\lambda$$

nObs = 357;
lambdastart = 630.02;
dlambda = 0.14;
lambdaend = lambdastart + (nObs-1)*dlambda;

%% 3. Create a column vector of lambda values
% Create a column vector |lambda| that starts at |lambdastart|, and goes in 
% steps of |dlambda| to |lambdaend|.

lambda = (lambdastart:dlambda:lambdaend)';

%% 4. Plot HD30584 vs lambda and label plot

figure
plot(lambda,HD30584)
xlabel('\lambda [nm]')
ylabel('Intensity')
title('Measured spectrum for Star HD30584')

%% 5. Plot a line that goes through the dip

x = [656.28 656.28];
y = [1.6e-13 3.2e-13];
hold on
plot(x,y,'--')
hold off

%% 6. Create meanFlux = average of HD30584

meanFlux = mean(HD30584);

%% 7. Calculate the absolute difference between the flux and mean

anomaly = abs(HD30584 - meanFlux);

%% 8. Plot the anomaly vs wavelength

figure
plot(lambda,anomaly)
title('Spectral Anomaly for Star HD30584')
xlabel('\lambda [nm]')
ylabel('Deviation from mean intensity')

%% 9. Find the wavelength of the maximum anomaly

[maxAnom,idx] = max(anomaly);
Halpha = lambda(idx)

%% 10. Calculate the redshift
% Calculate the redshift $z = \lambda_{max}/656.28 -1$, where $\lambda_{max}$ 
% is the wavelength calculated in the previous step. From this, calculate the 
% speed (in km/s) of the star relative to Earth, by multiplying z by 300000 (the 
% approximate speed of light in km/s).

z = Halpha/656.28 - 1
speed = z*300000