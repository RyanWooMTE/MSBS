
p = fileparts(mfilename('fullpath'));
cd([p,'/Tests'])
open_system('DLS_Controller_testHarness');
reportName = fullfile(getWorkProducts,'ModelTest','DLS_Controller_Report');
report('DLS_Controller_Report.rpt',['-o',reportName],'-quiet');
cd ..

