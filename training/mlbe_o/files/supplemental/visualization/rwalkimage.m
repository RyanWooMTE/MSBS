%% RWALKIMAGE  Plots estimated probabilities of a certain random walk outcome
%
%  Performs a given number of random walks on a square grid, starting from
%  each possible location, and returns the matrix of proportions P that
%  the walk terminated at one particular boundary.

%  The random walks start at location (x0,y0), where x0 and y0 are 
%  integers between -10 and 10, and continue until one of the boundaries 
%  (x or y = +/- 10) is reached.  P is the proportion of times the eastern 
%  boundary (x = 10) is reached.  All directions are equally likely during 
%  the walk, and there is no path memory.
%  A surface plot of P is generated.

%% Initialization
%  Number of experiments to run
nexp = 100;
%  Set up grid of starting locations
%  (x & y are the same, so just use one variable)
xvec = -9:9;
n = length(xvec);
%  Set aside space for output
pmatrix = zeros(n);

%% Calculate probabilities
%  Loop over all starting positions
for k=1:n      % x
    for j=1:n  % y
        % Initialize counter of how many times x=10 is reached
        p = 0;
        % Do nexp walks
        for iexp=1:nexp
            % Start at (k,j)th starting location each time
        x = xvec(k);
        y = xvec(j);
            % Do one walk: walk until boundary is reached
            while (abs(x)<10) && (abs(y)<10),
                % Roll dice and move
                dice = randi(4);
                % Choose direction for move, based on dice roll
                switch dice
                    case 1      % 1 = N
                        y=y+1;
                    case 2      % 2 = E
                        x=x+1;
                    case 3      % 3 = S
                        y=y-1;
                    otherwise   % 4 = W
                        x=x-1;
                end
            end % Walk is done: we reached a boundary

            % Where did we end up?  if x=10, then increment counter
            if (x==10)
                p = p+1;
            end
        end % All experiments are done for this starting location
        
        % Get proportion of times x=10 was reached
        pmatrix(j,k) = p/nexp;
    end % y
end % x
%  Done with all starting locations

%% Visualize results
figure
surf(xvec,xvec,pmatrix)
xlabel('x'), ylabel('y')
title('probability of reaching x=10')
