%% Solution to _UAV Capabilities III_ exercise
%% 1. Import data

UAV = readtable('UAVData.xlsx');

%% 2. Sort by ceiling

byCeiling = sortrows(UAV,'AltitudeCapability','descend');

%% 3. Plot ceiling as function of payload


for k = 1:5
    plot(byCeiling.PayloadWeight(k),byCeiling.AltitudeCapability(k),...
        '.','MarkerSize',25)
    hold on
    text(byCeiling.PayloadWeight(k)+20,byCeiling.AltitudeCapability(k),...
        byCeiling.UnmannedAerialVehicle{k})
end
plot(byCeiling.PayloadWeight(k+1:end),byCeiling.AltitudeCapability(k+1:end),...
        '.','MarkerSize',25)
hold off
xlabel('Payload [lb]')
ylabel('Ceiling [ft]')