function whaleplay(whale)
figure
image(whale.image)
axis image
axis off
fs = 1/(whale.t(2)-whale.t(1));
soundsc(whale.call,fs)
