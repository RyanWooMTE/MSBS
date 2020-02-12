function [stat,msg] = exportSignalBuilder(Mode,selected)
% Export function of sldvmisscovtool (Signal Buider)
%

%   Copyright 2010-2011 The MathWorks, Inc. 

stat = [];
msg = [];
switch Mode
    case 'description'
        if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
            stat = 'SignalBuider�u���b�N��';
            msg = ['[�G�N�X�|�[�g]' 10 ...
                '�ǂݍ��܂�Ă���e�X�g�P�[�X��SignalBuider�u���b�N�֏����o���܂�'];
        else
            stat = 'To Signal Builder block';
            msg = ['[Export]' 10 ...
                'Export loaded data into Signalbuilder block'];
        end
    case 'export'
        simdata = evalin('base','simdata');
        simdata = simdata(selected);
        testcaseName = {};
        if isfield(simdata,'signalName')
            for n=1:length(simdata)
                testcaseName{n} = simdata(n).signalName;%#ok
            end
        end
        stat = simdata2SignalBuilder(simdata,testcaseName,'');
end

