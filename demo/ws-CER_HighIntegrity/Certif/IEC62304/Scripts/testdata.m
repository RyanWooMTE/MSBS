% test data script för att ta ut 

f = [1,5.6,11.2,16.8,22.4,100]; 

% approximera filter med en tabell 
v_lo=5.6*[1,2,3,4];
filtergains = zeros(4,length(f)); 

F_LUT = [];
for i = 1:4
    lo = v_lo(i); hi = 2*v_lo(i);
    sys = tf(fir1(N,([lo,hi]/500)),1,0.001);
    F_LUT(i).bp    = [0,  lo/10, lo,  (lo+hi)/2, hi,  hi*10]'; 
    F_LUT(i).table = squeeze(abs(freqresp(sys,F_LUT(i).bp,'Hz')));
end    
