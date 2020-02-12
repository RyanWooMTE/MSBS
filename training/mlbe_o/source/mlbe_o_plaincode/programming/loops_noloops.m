% LOOPS_NOLOOPS Example of avoiding FOR-loops 
% while trying to calculate the mean of a subset 
% of data: those values greater than 0.5.

%% Create some data
n = 10;
x = rand(1,n)

%% First with loops
% Initialize variables to calculate mean.
xtot = 0;
nx   = 0;
 
% Loop through x to find values greater than 0.5.
for k=1:n
    % look at each element of x
    if (x(k)>0.5)
        % add to running sum & increment number of elements
        xtot = xtot + x(k);
        nx   = nx + 1;
    end
end
 
% Calculate the mean.
disp('mean of those values of x greater than 0.5 is:')
disp(xtot/nx)

%% And now without loops

idx = (x>0.5);  % logical array
y   = x(idx);   % logical indexing to extract values > 0.5
disp('mean of those values of x greater than 0.5 is:')
disp(mean(y))
 
% Note |disp(mean(x(x>0.5)))| would achieve the same result in one line 
% (but, arguably, isn't as readable).