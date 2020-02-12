function misscovPluginTest()
% Test script for plugin script of sldvmisscovtool
%

simdata = importCSVfile('import',fullfile(pwd,'TestCase01'));
%simdata = importCSVfile2('import',fullfile(pwd,'TestCase02'));
% simdata =  importMATfile('import','simdatasample01');
% simdata = importCSVfile2('import','TestCase04');
% simdata = importCSVfile2('import','TestCase05');
%simdata = importCSVfile('import','TestCase02');

assignin('base','simdata',simdata);

testCVSfile(simdata,{'TestCSV1','TestCSV2'});
testCVSfile2(simdata,{'TestCSV3','TestCSV4'});
testSignalBuilder(simdata);



%% CVS with common time
function simdata_new = testCVSfile(simdata,TestDir)
misscovClearTestDir(TestDir,'.csv')

exportCSVfile('export',1:length(simdata),TestDir{1},{'TestCase'});
simdata_new = importCSVfile('import',TestDir{1});
exportCSVfile('export',1:length(simdata),TestDir{2},{'TestCase'});

misscovCompareSimdata(simdata,simdata_new)
misscovTextDiffDir(TestDir,'.csv')

%%  CVS with seperate time
function simdata_new=testCVSfile2(simdata,TestDir)
misscovClearTestDir(TestDir,'.csv')

exportCSVfile2('export',1:length(simdata),TestDir{1},{'TestCase'});
simdata_new = importCSVfile2('import',fullfile(pwd,TestDir{1}));
exportCSVfile2('export',1:length(simdata),TestDir{2},{'TestCase'});

misscovCompareSimdata(simdata,simdata_new)
misscovTextDiffDir(TestDir,'.csv')

%% SignalBuilder
function simdata_new = testSignalBuilder(simdata)
% misscovClearTestDir(TestDir,'.csv')

exportSignalBuilder('export',1:length(simdata));
sigblock = find_system(bdroot,'Tag','STV Subsys');
sigblock=sigblock{1};
simdata_new = importSignalBuilder('import',sigblock);
exportSignalBuilder('export',1:length(simdata));
sigblock2 = find_system(bdroot,'Tag','STV Subsys');
sigblock2=sigblock2{1};

misscovCompareSimdata(simdata,simdata_new)
misscovDiffSignalBuilder(sigblock,sigblock2)

