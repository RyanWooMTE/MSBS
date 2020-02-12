%% Solution to _UAV Capabilities I_ exercise

%% 2. Import data as table
UAV = readtable('UAVData.xlsx');

%% 3. Calculate total load capacity
UAV.LoadCap = UAV.Endurance.*UAV.PayloadWeight;

%% 4. Sort table by load capacity
byCapacity = sortrows(UAV,'LoadCap','descend');

disp('UAVs in order of total load capacity:')
disp(byCapacity.UnmannedAerialVehicle)

%% 5. Create histogram
histogram(UAV.LoadCap,'BinWidth',500)
xlabel('Total load capacity [lb-hr]')
ylabel('Number of UAVs')
title('Distribution of load capacity of 33 UAVs')
