function name = modelname(in_name)
    persistent modelname;
    if (nargin==0)
        name = modelname;
    else
        modelname = in_name;
    end
end
