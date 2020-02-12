function flags = checkLicenses
% The Stateflow Workshop needs the following:
% MATLAB, Simulink, & Stateflow
% The following are very helpful, but can be worked around if need be.
% Aerospace Blockset, Simscape, Gauges

flags=[0,0];

%Check the minimum case
if ~license('test','simulink') || ~license('test','stateflow')  
    flags(1)=1;
end

if ~license('test','simscape')
% Change the configurable subsystem to the "simple" fan model
    set_param('Step_1/Fan Model','blockchoice','Simple')
    flags(2)=1;
end

if ~license('test','dial_and_gauge_blocks')
% Replace the thermometer with a display block
    replace_block('Step_1','Name','Thermometer','Display','noprompt');
    set_param('Step_1/Thermometer','position',[760,165,850,195]);
    flags(2)=1;
end

if ~license('test','aerospace_blockset')
% Delete the set-pace block & disable that section of the GUI
    set_param('Step_1/Temperature Model','blockchoice','(No Pace Control)')
    flags(2)=1;
end

