function whaleplot(whale)
figure
subplot(1,2,1)
image(whale.image)
axis image
axis off
subplot(1,2,2)
plot(whale.t,whale.call)
