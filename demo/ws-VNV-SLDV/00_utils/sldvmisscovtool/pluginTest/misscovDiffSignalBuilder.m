function misscovDiffSignalBuilder(blk1,blk2)
% helper function for plugin testing of sldvmisscovtool
% Compare two signal builder blocks

[timev1,datav1,siglabels1,grplabels1]=signalbuilder(blk1);
[timev2,datav2,siglabels2,grplabels2]=signalbuilder(blk2);

out = true;
if ~isequal(timev1,timev2)
    disp('[Alert] time vectors of Signal Builder block are different')
    timev1 %#ok
    timev2 %#ok
    out = false;
end

if ~isequal(datav1,datav2)
    disp('[Alert] data vectors of Signal Builder block are different')
    datav1 %#ok
    datav2 %#ok
    out = false;
end
if ~isequal(siglabels1,siglabels2)
    disp('[Alert] signal label vectors of Signal Builder block are different')
    siglabels1 %#ok
    siglabels2 %#ok
    out = false;
end

if ~isequal(grplabels1,grplabels2)
    disp('[Alert] Group label vectors of Signal Builder block are different')
    grplabels1 %#ok
    grplabels2 %#ok
    out = false;
end

if out
    fprintf('[Pass] %s and %s are identical\n',blk1,blk2);
end