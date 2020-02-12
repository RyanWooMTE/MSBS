function tcov = getTotalCov(ModelName,cvto,UsercovData)

% determin if model reference blocks are inside the model.
mdlblks = find_system(ModelName,'FollowLinks','on',...
    'LookUnderMasks','all',...
    'BlockType','ModelReference');
% If there are model reference blocks, tool always shows GenCov
% button.
% Otherwise, tool doesn't shows GenCov button if 100% coverage
% satisfied.
if ~isempty(mdlblks)
    tcov = 0;
else
    tcov = 1;
    if cvto.settings.decision
        dccov = decisioninfo(UsercovData,ModelName);
        if ~isempty(dccov)
            tcov = tcov * dccov(1)/dccov(2);
        end
    end
    if cvto.settings.condition
        cdcov = conditioninfo(UsercovData,ModelName);
        if ~isempty(cdcov)
            tcov = tcov* cdcov(1)/cdcov(2);
        end
    end
    if cvto.settings.mcdc
        mcdccov = mcdcinfo(UsercovData,ModelName);
        if ~isempty(mcdccov)
            tcov = tcov* mcdccov(1)/mcdccov(2);
        end
    end
end