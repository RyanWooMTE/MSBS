function blkStruct = slblocks

%   Copyright 2012 The MathWorks, Inc. 

%
blkStruct.Name        = 'SLDV Property specification';
blkStruct.OpenFcn     = 'propertySpecificationLib';
blkStruct.MaskDisplay = sprintf('SLDV Property specification');
blkStruct.Browser(1).Library = 'propertySpecificationLib';
blkStruct.Browser(1).Name    = 'SLDV Property specification';