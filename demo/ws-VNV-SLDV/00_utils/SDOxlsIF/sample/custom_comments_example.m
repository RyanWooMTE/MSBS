function comments = custom_comments_example(objectName, modelName, object)
% An example of putting custom comments in the generated code via m script
% The comments will be placed right above the data declaration or definition 
% in the generated code. 
%   INPUTS:
%         objectName: name of the mpt parameter or signal object
%         modelName:  name of working model
%         object:     mpt parameter or signal object 
%   OUTPUT: 
%         comments:   a string with c comment convention   
%
% Note: This file has to be on the Matlab path.
% Recommend: using get_data_info to get data attributes for named object. 
% See also get_data_info.

%   Copyright 2003 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $
%   $Date: 2004/01/24 09:25:22 $

dataType = get_data_info(objectName,'DATATYPE');
description = get_data_info(objectName, 'DESCRIPTION');
% units    = get_data_info(objectName,'UNITS');
units    = get_data_info(objectName,'DOCUNITS');
sc       = get_data_info(objectName,'STORAGECLASS');
maxValue = get_data_info(objectName,'MAX');
maxValueStr = num2str(maxValue);
minValue = get_data_info(objectName,'MIN');
minValueStr = num2str(minValue);

cr = sprintf('\n');
comments = ['/* ラベル名: ',objectName,cr,...
          '           説明: ', description,cr,...
          '           単位: ', units,cr,...
          '           最大値: ', maxValueStr,cr,...
          '           最小値: ', minValueStr,' */'];
