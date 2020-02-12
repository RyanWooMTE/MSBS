%% BWADAM  Compares different ways to average a uint8 array

%% Read data
x = imread('adamtruck.jpg');

%% Calculate the average across the 3rd dimension in different ways
%  Direct calculation (uses uint8 arithmetic)
intsty1 = (x(:,:,1) + x(:,:,2) + x(:,:,3))/3;
%  Call MEAN and SUM
intsty2 = mean(x,3);
intsty3 = sum(x,3)/3;

%% Compare results
%  Look at class of results
whos intsty1 intsty2 intsty3
%  Look at values
fprintf('intsty1 ranges from %d to %d; average value is %f\n',...
    min(intsty1(:)),max(intsty1(:)),mean(intsty1(:)))
fprintf('intsty2 ranges from %d to %d; average value is %f\n',...
    min(intsty2(:)),max(intsty2(:)),mean(intsty2(:)))

%  Compare methods 2 & 3 -- should be the same
diff23 = abs(intsty3(:)-intsty2(:));
if (max(diff23) == 0)
    disp('intsty2 and intsty3 are the same')
else
    disp('intsty2 and intsty3 are different')
end

%% Visualize results
%  Original image
figure
image(x)
axis image
%  Average 1
figure
colormap('gray')
imagesc(intsty1,[0,255])
axis image
colorbar
%  Average 2 (same as 3)
figure
colormap('gray')
imagesc(intsty2,[0,255])
axis image
colorbar
