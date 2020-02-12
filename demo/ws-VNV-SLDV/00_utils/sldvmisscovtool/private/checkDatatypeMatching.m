function out=checkDatatypeMatching(datatypes,selected)

simdata = evalin('base','simdata');

out=true;
for m=selected
    try
        for n=1:length(simdata(m).signals)
            % comparing datatype with simdata and its defined in
            % corresponding ports.
            switch class(simdata(m).signals(n).values(1))
                case 'logical'
                    % In case of boolean, we treat separately bacause of
                    % boolean <==> logical comparison.
                    if ~strcmp('boolean',datatypes{n})
                        out=false;
                    end
                case {'double','single','int8','int16','int32','uint8','uint16','uint32'}
                    if ~isa(simdata(m).signals(n).values,datatypes{n})
                        out=false;
                            
                    end
                case 'embedded.fi'
                    % 
                    tmpv = simdata(m).signals(n).values(1);
                    if ~isequal(fi(1,tmpv.numerictype),fi(1,fixdt(datatypes{n}))) ||...
                            ~isequal(fi(2,tmpv.numerictype),fi(2,fixdt(datatypes{n})))
                        out = false;
                    end
                otherwise
                    % suppose data type is fixed point
                    out=false;
            end
        end
    catch
        warning('sldvmisscovtool:checkDatatypeMatching','simdata(%d) is not match with model''s input',m)
    end
end
