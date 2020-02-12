function s = dec2base27(d)
% private function returns the representation of D as a string in base 27
% -------------------------------------------------------------------------

%   This program is not officially supported.
%   This program can be freely customized.

%   DEC2BASE27(D) returns the representation of D as a string in base 27,
%   expressed as 'A'..'Z', 'AA','AB'...'AZ', until 'IV'. Note, there is no zero
%   digit, so strictly we have hybrid base26, base27 number system.  D must be a
%   negative integer bigger than 0 and smaller than 2^52, which is the maximum
%   number of columns in an Excel worksheet.
%
%   Examples
%       dec2base(1) returns 'A'
%       dec2base(26) returns 'Z'
%       dec2base(27) returns 'AA'
%-----------------------------------------------------------------------------
    b = 26;
    symbols = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

    d = d(:);
    if d ~= floor(d) | any(d < 0) | any(d > 1/eps)
        error('SDOxlsIF:dec2base27:Dec2BaseInput', 'D must be an integer, 0 <= D <= 2^52.')
    end

    % find the number of columns in new base
    n = max(1,round(log2(max(d)+1)/log2(b)));
    while any(b.^n <= d)
        n = n + 1;
    end

    % set b^0 column
    s(:,n) = rem(d,b);
    while n > 1 && any(d)
        if s(:,n) == 0
            s(:,n) = b;
        end
        if d > b
            % after the carry-over to the b^(n+1) column
            if s(:,n) == b
                % for the b^n digit at b, set b^(n+1) digit to b
                s(:,n-1) = floor(d/b)-1;
            else
                % set the b^(n+1) digit to the new value after the last carry-over.
                s(:,n-1) = rem(floor(d/b),b);
            end
        else
            s(:,n-1) = []; % remove b^(n+1) digit.
        end
        n = n - 1;
    end
    s = symbols(s);
end
%------------------------------------------------------------------------------
