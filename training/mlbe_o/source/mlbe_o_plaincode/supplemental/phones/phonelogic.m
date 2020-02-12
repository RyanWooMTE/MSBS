load phoneData

%% Were there any smartphones released prior to 2011 with a processor speed of at least 1000 MHz?
%  Find the fast phones
fast = phones.Processorspeed >= 1000;
%  Find the old phones
cutdate = datetime(2011,1,1);
old = phones.Releasedate < cutdate;
%  Find the phones that satisfy both criteria
oldandfast = old & fast;
any(oldandfast)

%% How many phones satisfy the criteria?
nnz(oldandfast)

%% Which phones?
phones.Name(oldandfast)
% Get all the information on these phones.
phones(oldandfast,:) 

%% Are smartphones getting heavier?  Lighter?
Weight = phones.Weight;
yr = year(phones.Releasedate);
%  Use logical indexing to get the weights for each year in turn
mean(Weight(yr == 2009))
mean(Weight(yr == 2010))
mean(Weight(yr == 2011))

%% Compare the average weight of Android and Apple phones
%  Find just Android OS phones
droid = strcmp(phones.OS,'Android');
%  Find just iOS phones
apple = strcmp(phones.OS,'iOS');
%  Use logical indexing to compare average weights
mean(phones.Weight(droid))
mean(phones.Weight(apple))
