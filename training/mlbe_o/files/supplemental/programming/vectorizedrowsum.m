%% VECTORIZEDROWSUM  Times various ways to find row sums of a matrix

%% Make a big matrix
N = 3e3;
x = rand(N);

%% Brute force programming
tic
y1 = zeros(N,1);
for j=1:N
    for k=1:N
        y1(j) = y1(j) + sum(x(j,k));
    end
end
toc

%% Partly vectorized (one loop)
tic
y2 = zeros(N,1);
for j=1:N
    y2(j) = sum(x(j,:));
end
toc

%% Transpose and SUM
tic
y3 = sum(x');   % Note the Code Analyzer warning
toc

%% Using SUM with a dimension argument
tic
y4 = sum(x,2);
toc
