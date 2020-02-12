%% Supported format

%% Constant
%
% If the given string is also defined in the bese workspace as a variable name
% and if its class name is parameter object (|*.Parameter|) or base type 
% (|'logical','int8','int16','int32','int8','int16','int32','double','single'|)
% , the string will be assigned to
% a Constant block ans the string will be specified as Value property.
% The data type is set to |"Inherit: Inherit via back propagation"|.

%% Inport
%
% The string will become Inport block if the string matches the following
% conditions:
%
% * Not a Constant
% * Not reserved name

%% Supported Operators
% The supported operators and those precedence levels are almost the same with
% <matlab:web(['jar:file:///',docroot,'/techdoc/help.jar!/matlab_prog/f0-40063.html#bqjivpq'],'-helpbrowser') MATLAB Language>.
%
% * Parenthes ()
% * Embedded functions
% * Unary |+, -|
% * Cast (|single, double, uint8, uint16, uint32, int8, int16, int32, Fixed-point expression ex:fixdt(1,16,2,0)|)
% * Logical NOT |~|
% * Multiply |* / %(mod)|
% * Addition, subtraction: |+, -|
% * Relational operators: |==, <, >, <=, >=, ~=|
% * |AND &&|
% * |OR || |
% * Implies: |==>|, WithinImplies: |==>>|, Implies with Test Objective: |=@>|

%% Embedded functions
% 
% |*abs*([expr])|
% : Absolute 
%
% |*prev*([expr],[Integer])|
% : The value previos |[Integer]| steps. 
%
% |*init*([expr],[Integer])|
% |[expr]| is true for initial |[Integer]| steps from step 0.
%
% |*withinImplies*([expr],[expr])|
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/withinimplies.html'],'-helpbrowser') Within Implies block of Simulink Design Verifier>
%
% |*after*([expr],[INTEGER])| 
% : True if |[expr]| is true for more than and equal to |[INTEGER]| steps. 
%
% |*extend*([expr],[INTEGER])|
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/extender.html'],'-helpbrowser') Extender block of Simulink Design Verifier>
%
% |*detect*([expr],[INTEGER])| 
% <matlab:web(['jar:file:///',docroot,'/toolbox/sldv/help.jar!/ref/detector.html'],'-helpbrowser') Detector block of Simulink Design Verifier>

