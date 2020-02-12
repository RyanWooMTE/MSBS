function sys = utilPreparXLS2TT()
% Utility for preparing Subsystem blocks as a base of XLS2TT functions

load_system('simulink')
load_system('sldvlib')
load_system('sflib')

new_system();
mdl = bdroot;
open_system(mdl)

sldvVerificationSubsys = 'built-in/Subsystem';

% adding verification subsystem
sys = add_block(sldvVerificationSubsys,sprintf('%s/VerificationSubsystem',mdl));
set_param(sys,'Position',[30 30 150 80]);
existing_inblk = find_system(mdl,'LookUnderMasks','on','BlockType','Inport');
delete_block(existing_inblk)
