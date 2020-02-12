function LGMode_lct

% Initialize an empty structure
def = legacy_code('initialize');

% Fill the structure
def.SFunctionName = 'LGMode_lct_sfcn';
def.StartFcnSpec = 'void LandingGearMode_initialize(void)';
def.OutputFcnSpec = 'double y1 = LGMode_lct(uint8 u1, uint8 u2)';
def.SourceFiles   = {'LGMode_lct.c','LandingGearMode.c'};
def.HeaderFiles   = {'LGMode_lct.h'};
def.IncPaths = {'..\src','..\src\LandingGearMode_ert_rtw'};
def.SrcPaths = {'..\src','..\src\LandingGearMode_ert_rtw'};

def.Options.supportCoverage = true;
    
% Generate the C-MEX S-function
legacy_code('sfcn_cmex_generate',def);

% Compile the C-MEX S-function
legacy_code('compile',def);

% Generate masked S-function block
legacy_code('slblock_generate', def);
legacy_code('sfcn_tlc_generate', def);

% mex('tcu_lct_sfcn.c', '..\src\tcu_lct.c',...
%     '.\tcu_ert_rtw\tcu.c', '.\tcu_ert_rtw\tcu_data.c',...
%     '-I.\tcu_ert_rtw', '-I..\src','-g')