function ts = simdata2ts(onesim)
% convert simdata to Simulink.TimeSeries
% ts: TimeSeries 

for n=1:length(onesim.signals)
    t = Simulink.Timeseries;
    t.Time = onesim.time;
    t.Data = onesim.signals(n).values;
    t.SignalName = onesim.signals(n).label;
    ts{n}=t;
end
