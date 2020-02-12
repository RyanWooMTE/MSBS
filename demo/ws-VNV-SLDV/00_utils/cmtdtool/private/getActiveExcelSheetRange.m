function [xlsfile,sheet,Range,UsedRange] = getActiveExcelSheetRange()
% getActiveExcelSheetRange Obtain active range, sheet, file name of Excel
% 

%   Copyright 2010-2011 The MathWorks, Inc. 

xlsfile=''; sheet=''; Range=''; UsedRange='';
try
    excel = actxGetRunningServer('Excel.Application');
catch
    if isJapaneseEnv()
        warndlg('Excelが開かれていません','Warning')
    else
        warndlg('Excel is not opend.','Warning')
    end
    return;
end
if isempty(excel.ActiveWorkbook)
    if isJapaneseEnv()
        warndlg('アクティブなExcel Workbookを特定できません.Excelを開いている場合には、開きなおしてください。','Warning')
    else
        warndlg('Active Excel Workbook cannot be determined. If Excel is opened, please close and open the file again.','Warning')
    end    
    return;
end
if excel.ActiveWorkBook.Saved == 0
   if isJapaneseEnv()
     Btn = questdlg('Excelが変更されています。未保存部分は反映されませんが続行しますか？','Unsaved change','Yes','No','Yes');
   else
     Btn = questdlg('Excel is modified and not saved. Do you continue?','Unsaved change','Yes','No','Yes');
   end
   if strcmp(Btn,'No')
        return;
    end
end
str = excel.selection.Address;
Range = regexprep(str,'\$','');

xlsfile = fullfile(excel.ActiveWorkbook.Path,excel.ActiveWorkbook.Name);
sheet = excel.ActiveSheet.Name;
UsedRange =  get(excel.ActiveSheet.UsedRange,'Address');
UsedRange = regexprep(UsedRange,'\$','');