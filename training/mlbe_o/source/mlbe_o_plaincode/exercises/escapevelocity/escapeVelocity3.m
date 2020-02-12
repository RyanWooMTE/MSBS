%% Solution to _Escape Velocity III_ exercise

%% Create structure array of planetary data
planets(1).name = 'Mercury';
planets(1).mass = 3.3e23;
planets(1).radius = 2.44e6;

planets(2).name = 'Mars';
planets(2).mass = 6.42e23;
planets(2).radius = 3.4e6;

planets(3).name = 'Jupiter';
planets(3).mass = 1.9e27;
planets(3).radius = 7.15e7;

planets(4).name = 'Uranus';
planets(4).mass = 8.68e25;
planets(4).radius = 2.56e7;

%% Loop through planets
for k=1:4
    [r,Ve,g] = veandg3(planets(k));
end


