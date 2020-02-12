%% 1. Load 747 image
img = imread('747.jpg');
figure
image(img)
axis image
axis off

%% 2. Select points
waitfor(msgbox({'Please enter 6 points on the boundary of the wing';...
    'The sixth point does not need to coincide with the first point'}))
%% 3. Find coordinates
[x,y] = ginput(6);

%  Add colored rectangle to the image
patch(x,y,'b','FaceAlpha',0.2)

%% 4. Determine area
pixarea = polyarea(x,y);

%% 5. Convert area
realarea = 2*pixarea/(1.466^2);

%% 6. Report estimated wing area
disp(['Estimated wing area is: ',num2str(realarea), ' square feet']);
