function fixLineOverlap(sys)
% fixLineOverlap detects overlapping lines and change the line position
%

%   Copyright 2012 The MathWorks, Inc. 

lh = find_system(sys,'FindAll','on','SearchDepth',1,'LookUnderMasks','on','FollowLinks','on','Type','Line');

% For all lines in the system
for n=1:length(lh)
    Points = get(lh(n),'Points');
    % for all points of the line
    for n1=1:size(Points,1)-1
        la = Points(n1:n1+1,:);
        % search for all other lines
        for m=n+1:length(lh)
            mPoints = get(lh(m),'Points');
            for m1=1:size(mPoints,1)-1
                lb = mPoints(m1:m1+1,:);
                ovl = isOverlap(la,lb);
                if ovl == 1 % y-direction line overrap
                    mPoints(m1:m1+1,:) = mPoints(m1:m1+1,:)+[-4 0; -4 0];
                    set(lh(m),'Points',mPoints)
                elseif ovl == 2 % x-direction line overrap
                    if m1==1
                        % if line overrap is at source port, we move the block. 
                        bPos = get_param(get(lh(m),'SrcBlockHandle'),'Position');
                        set_param(get(lh(m),'SrcBlockHandle'),'Position',bPos+[0 4 0 4]);
                    elseif m1 == size(mPoints,1)-1
                        % if line overrap is at dst port, we also move the block. 
                        bPos = get_param(get(lh(m),'DstBlockHandle'),'Position');
                        set_param(get(lh(m),'DstBlockHandle'),'Position',bPos+[0 4 0 4]);
                    else
                        % otherwise, we move the line.
                        mPoints(m1:m1+1,:) = mPoints(m1:m1+1,:)+[0 4; 0 4];
                        set(lh(m),'Points',mPoints)
                    end
                    %hilite_system(get(lh(m),'DstBlockHandle'))
                end
            end
        end
    end
end

1;

function ovl = isOverlap(la, lb)
% find whether there is line overrap 
ovl = 0;
la = sort(la);
lb = sort(lb);

if la(1,1) == lb(1,1) && la(2,1) == lb(2,1) % X
    if ~(la(2,2) < lb(1,2) || lb(2,2) < la(1,2))
        ovl = 1;
    end
end
if la(1,2) == lb(1,2) && la(2,2) == lb(2,2) % Y
    if ~(la(2,1) < lb(1,1) || lb(2,1) < la(1,1))
        ovl = 2;
    end
end
