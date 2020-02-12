function setSimdata2ModelDatatype(datatypes,selected)
% override Data-types of signals in simdata defined in base WorkSpace

odata = evalin('base','simdata');
simdata = odata;
builtinDT = {'double','single','int8','int16','int32','uint8','uint16','uint32','boolean'};

for m=selected
    try
        for n=1:length(datatypes)
            tmpd = odata(m).signals(n).values; 
            if any(strcmp(datatypes{n},builtinDT))
                % fource casting (don't use cast function because it doesnot support boolean)
                simdata(m).signals(n).values = eval(sprintf('%s(tmpd)',datatypes{n}));
            else
                simdata(m).signals(n).values = fi(tmpd,fixdt(datatypes{n}));
            end
        end
    catch
        warning('sldvmisscovtool:checkDatatypeMatching','simdata(%d) is not match with model''s input',m)
    end
end

assignin('base','simdata',simdata)