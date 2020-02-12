function larrow = getLarrowCData(rarrow)

larrow = uint8(zeros(size(rarrow)));
M = size(rarrow,2);
for n=1:3
    for m=1:M
        larrow(:,m,n) = rarrow(:,M-m+1,n); 
    end
end
