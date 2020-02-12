function addExpectedOutputToSignalBuilder(blk,sigName)
% addExpectedOutputToSignalBuilder  add Signals into existing SignalBuilder
% 
% This function adds signals into specified SignalBuilder block
% 
% input:
%  blk: Block path to SignalBuilder block
%  sigName: A cell array of signal names to be added.

%   Copyright 2010-2011 The MathWorks, Inc. 

%% Retain exising line connection and delete lines
lh = get_param(blk,'LineHandles');
for n=1:length(lh.Outport)
    lineDst{n} = sprintf('%s/%d',get(lh.Outport(n),'DstBlock'),get(get(lh.Outport(n),'DstPortHandle'),'PortNumber'));
end

for n=1:length(lh.Outport)
    delete_line(lh.Outport(n));
end

% obtain existing time, data, and signal names and delete it.
[time,data,sign,grpn] = signalbuilder(blk);

for n=1:length(sigName)
    time(end+1,1) = time(1,1);
    data(end+1,1) = data(1,1);
    sign{end+1} = sigName{n};
end
pos = get_param(blk,'Position');
pos(4) = pos(4) + 20*length(sigName);
delete_block(blk);

% create new SignalBuilder and reconnect lines
signalbuilder(blk,'create',time,data,sign,grpn);
set_param(blk,'Position',pos);

for n=1:length(lineDst)
    add_line(bdroot,sprintf('%s/%d',get_param(blk,'Name'),n),lineDst{n});
end
