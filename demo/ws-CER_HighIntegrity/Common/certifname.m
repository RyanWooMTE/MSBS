function name = certifname(in_name)
    persistent certifname;
    if (nargin==0)
        name = certifname;
    else
        certifname = in_name;
    end
end
