function proplist = getExcelEquations(opt)
% getExcelEquations  Obtain currently selecte table data in Excel

%   Copyright 2012 The MathWorks, Inc. 

if ~exist('opt','var')
    opt.isRMI = false;
    opt.ExcelKeyword = '^<PROP>';
end
props = [];

[xlsfile,sheet] = getActiveExcelSheetRange();
[~,~,raw]= xlsread(xlsfile,sheet);

[row,col]= findKeywordPos(raw,opt);
if isempty(row)
    error('getExcelEquations:KeyWordNotFound','キーワード %s が見つかりません',opt.ExcelKeyword)
end

if opt.isRMI
   [Rrow,Rcol] = getActualRange(xlsfile,sheet,raw{row,col});
end

proplist = PropertyList();

k=1;
for n=row+1:size(raw,1)
    if ~isnan(raw{n,col})
        props = PropertyElement();
        props.Description = raw{n,col-1}; 
        props.Equation = raw{n,col}; 
        if any(strcmp(raw{n,col+1},{'PO','AC'}))
            props.ProoforAssume = raw{n,col+1}; 
        else
            props.ProoforAssume = 'PO'; 
        end
        props.isEnable = true; 
        if ~isnan(raw{n,col+2})
            props.ignoreSteps = raw{n,col+2};
        else
            props.ignoreSteps = 0;
        end
        if opt.isRMI
            props.RMI.xlsfile = xlsfile ; 
            props.RMI.sheet = sheet ; 
            props.RMI.Range = sprintf('%s%d:%s%d',char(Rcol+64),Rrow-row+n,char(Rcol+64),Rrow-row+n); 
        else
            props.RMI = []; 
        end
        proplist = proplist.addPropertyElement(props);
        k=k+1;
    end
end
        
function [row,col] = findKeywordPos(raw,opt)
txt = raw;
for n=1:numel(txt)
    if ~ischar(txt{n})
        txt{n} = '';
    end
end

if length(cell2mat(regexp(txt,opt.ExcelKeyword))) > 1
    error('getExcelEquations:MultipleKeywordFound','More than one Keyword %s is found!', opt.ExcelKeyword);
end
row = []; col = [];
for n=1:numel(txt)
    if ~isempty(regexp(txt{n},opt.ExcelKeyword,'once'))
        [row,col] =ind2sub(size(txt),n);
    end
end


function [Rrow,Rcol] = getActualRange(xlsfile,sheet,keyWord)
% Obtain Excel range of cell aquired by xlsread.

SearchRange = 'A1:Z10';

[~,~,raw]= xlsread(xlsfile,sheet,SearchRange);

ind = find(strcmp(raw,keyWord));
[Rrow,Rcol]=ind2sub(size(raw),ind);

