try
   ExecutionProfileTimeSeries = timeseries(...
       executionProfile.getSectionProfile(1).getTimes,...
       t,...
       'Name', 'executionProfile');
end
