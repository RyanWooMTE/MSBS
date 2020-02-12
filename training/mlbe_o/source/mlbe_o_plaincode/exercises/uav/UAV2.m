%% Solution to _UAV Capabilities II_ exercise
%% 1. Load data

UAV = readtable('UAVData.xlsx');

%% 2. How many can carry a load of 500lb or more?

num_heavy = nnz(UAV.PayloadWeight >= 500);
disp([num2str(num_heavy),' UAVs can carry 500 lb or more'])

%% 3. What is average payload capacity of UAVs that can fly at 30000ft or higher?

fly_high = UAV.AltitudeCapability >= 30000;
high_load = mean(UAV.PayloadWeight(fly_high));
disp(['Average payload for UAVs with a ceiling of at least 30,000 is ',...
    num2str(high_load)])

%% 4. Display those which can carry 200lb at 30000 ft or higher for at least 6 hrs

requirements = (UAV.PayloadWeight >= 200) & fly_high & (UAV.Endurance >= 6);
disp('UAVs that are up to the task:')
disp(UAV.UnmannedAerialVehicle(requirements))