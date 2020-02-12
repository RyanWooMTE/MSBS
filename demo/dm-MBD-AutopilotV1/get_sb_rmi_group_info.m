function rmi_group_info=get_sb_rmi_group_info(block,group)
% This function returns a structure with the requirements info for a
% particular group within a Signal Builder block  The result will be an
% empty string if the block is not a Signal Builder block or if there are 
% no requirements associated with the group.

% Initialize data to empty string
rmi_group_info=' ';

% Get the mask type for the block
mt=get_param(block,'MaskType');

% Return if it is not a Signal Builder
if ~strcmp(mt,'Sigbuilder block')
    return
end

% Get the rmi data for the block
reqlinks = rmi('get', block);

% Return if the rmi data is empty
if isempty(reqlinks)
    return
end

% Get the VnV Data from the workspace block under the subsystem
vnvdata=get_param([block '/FromWs'],'VnVData');
indexes=vnvdata.groupReqCnt;

% Get the indexes for this group and output that data
if ~isempty(indexes)
    if group==1 && indexes(group)~=0
        temp_info=reqlinks(1:indexes(group));
    elseif indexes(group)~=0
        starti=sum(indexes(1:group-1))+1;
        endi=starti+indexes(group)-1;
        temp_info=reqlinks(starti:endi);
    end
end

% Get the descriptions
if ~isempty(temp_info)
    temp=temp_info(1).description;
    if length(temp_info)>1
        for i=2:length(temp_info)
            temp=[temp ', ' temp_info(i).description];
        end
    end
    rmi_group_info=temp;
else
    rmi_group_info=' ';
end
    