function name = certiffolder(in_name)
    persistent certiffolder;
    if (nargin==0)
        name = certiffolder;
    else
        certiffolder = in_name;
    end
end
