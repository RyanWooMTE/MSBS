
%% Initialize legacy code tool data structure
def = legacy_code('initialize') ;
%% Specify Source File
def.SourceFiles = {'add.c'};
%% Specify Header File
def.HeaderFiles = {'add.h'};
%% Specify the Name of the generated S-function
def.SFunctionName = 'Adder';
%% Create a c-mex file for S-function
legacy_code('sfcn_cmex_generate', def);
%% Define function signature and target the Output method
def.OutputFcnSpec = ['double y1 = add(double u1, double u2)'];
%% Compile/Mex and generate a block that can be used in simulation
legacy_code('generate_for_sim', def);
%% Create a TLC file for Code Generation
legacy_code('sfcn_tlc_generate', def);
%% Create a Masked S-function Block 
legacy_code('slblock_generate', def);