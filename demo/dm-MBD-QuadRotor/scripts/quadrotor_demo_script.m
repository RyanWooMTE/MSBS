%% QuadRotor Control Demo
%
% This demo is designed to demonstrate entire model-based design process
%
% Written by Sang-Ho Yoon
% 

%% QuadRotor Vehicle Modeling
%
% *1. CAD IMPORT*
%
% <matlab:winopen('..\CAD'); *Example CAD files*>
%
% <matlab:initQuadrotorNano;smimport('QUADROTOR','modelName','Quadrotor_BodyOld'); *Import CAD files*>
%
% *2. Completed Vehicle Model*
%
% The completed model includes Motors, External Forces and Ground Stop
%
% <matlab:initQuadrotorNano;open_system('QuadRotorPlant'); Open *QuadRotorPlant.slx*>
% 

%% Controller Modeling from Requirement
%
% *1. Functional Requirement*
%
% <matlab:winopen('..\requirements\QuadRotor_SRS.docx'); Open *QuadRotor_SRS.docx*>
%
% *2. Control Model*
%
% <matlab:initQuadrotorNano;open('QuadRotorController.slx') Open *QuadRotorController.slx*>
%
% *3. Control Parameter Tuning*
%
% <matlab:initQuadrotorNano;open_system('QuadRotorSystem_NoTune'); Open *QuadRotorSystem_NoTune.slx*>
%

%% Final QuadRotor Control System Model
%
% <matlab:initQuadrotorNano;open_system('QuadRotorSystem'); Open completed *QuadRotorSystem* model>
%

%% Implementation
%
% *1. Generate Codes from QuadRotorController Model*
%
% <matlab:open('QuadRotorController.slx') Open *QuadRotorController.slx*>
%

%% Code Verification
%
% *1. Software-in-the-loop*
%
% <matlab:open('QuadRotorController_SIL.slx'); Open *QuadRotorController_SIL.slx*>
%
% *2. Processor-in-the-loop*
%

