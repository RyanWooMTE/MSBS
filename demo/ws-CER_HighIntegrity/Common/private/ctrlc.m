% CTRLC
% dev : L.Royer

% if get(0,'PointerLocation')==[1 1]
if all(get(0,'PointerLocation')<=[5 5])
    
    switch menu(...
            ['EXECUTION PAUSED... ',get_caller_name(1)],...
            'Terminate the current script or function',...
            'Switch to keyboard mode',...
            'Continue the current execution')
        %   switch (input(sprintf( ...
        %       '%s\n%s\n%s\n%s', ...
        %       '1 - Terminate the current script or function', ...
        %       '2 - Switch to keyboard mode', ...
        %       '3 - Continue the current execution', ...
        %       ' Choix ? ' )))
        
        case 1
            dbquit;
            
        case 2
            disp('=> Type ''return'' to go back to the script execution or ''dbquit'' pour l''interrompre');
            keyboard;
            
    end
    
end