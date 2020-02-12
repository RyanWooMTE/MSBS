%% VECTORIZEDMAX  Times various ways to find maximum value in a matrix

%% Make a big matrix
N = 2e3;
x = rand(N);

%% Brute force programming
tic
y = x(1,1);
for j = 1:N
    for k=1:N
        if x(j,k) > y
            y = x(j,k);
        end
    end
end
toc

%% Inner loop down columns (takes advantage of column major format)
tic
y = x(1,1);
for k = 1:N
    for j=1:N
        if x(j,k) > y
            y = x(j,k);
        end
    end
end
toc

%% Using MAX function twice
tic
y = max(max(x));    %#ok
toc

%% Implicit reshaping
tic
y = max(x(:));      %#ok
toc

%% Explicity reshaping
tic
y = max(reshape(x,N*N,1));
toc
