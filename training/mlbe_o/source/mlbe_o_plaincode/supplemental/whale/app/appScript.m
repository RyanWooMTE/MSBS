load('whaledata.mat')

whalenum = menu('Choose your whale',{aquarium.name});

plotorplay = menu('Which post-processing task?','Plot waveform','Play sound');

if plotorplay == 1
    analysisfn = @whaleplot;
else
    analysisfn = @whaleplay;
end

whaledata = aquarium(whalenum);
whalemodel = callmodel_fh(whaledata,analysisfn);
