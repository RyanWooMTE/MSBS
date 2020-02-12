function ret = isSlVnVInstalled
% isSlVnVInstalled - Check whether Simulink Verification and Validation is installed for current
% user.  This includes testing for a license (but NOT checking
% it out) and testing for a particular file associated with SLDV.
% Return 1 if installed, otherwise return 0.

%  Copyright 2010-2011 The MathWorks, Inc.


    mlock;
    persistent pathExist;
    
    if isempty(pathExist)
        %  avoid use exist() to check for the existence of Contents.m to improve performance 
        pathExist =  ~isempty(dir([matlabroot '/toolbox/slvnv/slvnv/Contents.m']));     
    end
    
    ret = license('test', 'SL_Verification_Validation') && pathExist;
