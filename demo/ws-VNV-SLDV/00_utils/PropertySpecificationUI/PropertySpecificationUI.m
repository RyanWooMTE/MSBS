function PropertySpecificationUI(varargin)
% A Graphical User Interface of PropertySpecificationUI

%   Copyright 2012 The MathWorks, Inc. 

%% Construct GUI
DistanceFromBottom = 20;
DistanceFromTop = 20;

blk = '';

%% Initial configuration

% opt: a structure which contains common infomation for all lists in table
opt.isRMI = false;
% RMI = [];
opt.ExcelKeyword = '^<PROP>';

% Configuration for documentation
toolroot = fileparts(which(mfilename));
helpdescription = fullfile(toolroot,'doc_en/description.html');

        
% props : a struct of properties. This is the source of table and block
% diagram.

proplist = PropertyList();
% props(end) = []; % to make it zero length
handleInfo = {};

% If there is an existing figure, it will shown in frontend and it needs to
% be reused.
obj = findobj('Tag','PropertySpecificationUI');
if ~isempty(obj)
    figure(obj);
    return;
end

%% Initialization of GUI objects
handles.h1 = figure(...
    'Units','pixels',...
    'PaperUnits',get(0,'defaultfigurePaperUnits'),...
    'InvertHardcopy',get(0,'defaultfigureInvertHardcopy'),...
    'Color',[0.941176470588235 0.941176470588235 0.941176470588235],...
    'MenuBar','none',...
    'Name','PropertySpecificationUI',...
    'NumberTitle','off',...
    'Position',[4 228 1000 400],...
    'Resize','on',...
    'HandleVisibility','on',...
    'UserData',[],...
    'Tag','PropertySpecificationUI',...
    'ResizeFcn', @figureResizeFcnCallBack,...
    'CloseRequestFcn',@figureCloseRequestFcnCallBack,...
    'Visible','on' );


figurePosition = get(handles.h1,'Position');

handles.uitableVerificationEqs = uitable(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'ColumnFormat',{  'char' 'char' {'PO','AC'} 'logical' 'logical' 'logical' 'numeric' },...
    'ColumnName',{  '説明'; '検査式/前提条件'; '種別'; '有効'; '表示'; 'RMI'; 'Steps'},...
    'Data',{'','','PO', true,false,'',''},...
    'ColumnEditable',true,...
    'RowName','numbered',...
    'UserData',[],...
    'FontSize',10,...
    'CellEditCallback',@uitableVerificationEqs_CellEditCallback,...
    'Tag','uitableVerificationEqs' );
set(handles.uitableVerificationEqs,'Data',{'','','PO',true,false,'',''});





handles.buttonAddRow = uicontrol(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'FontUnits','pixels',...
    'Callback',@addRow_Callback,...
    'FontName',get(0,'defaultuicontrolFontName'),...
    'FontSize',18,...
    'String','+',...
    'Tag','addRow');

handles.buttonRemoveRow = uicontrol(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'FontUnits','pixels',...
    'Callback',@removeRow_Callback,...
    'FontName',get(0,'defaultuicontrolFontName'),...
    'FontSize',18,...
    'String','-',...
    'Tag','removeRow');

handles.generateBlock = uicontrol(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'FontUnits','pixels',...
    'Callback',@generateBlock_Callback,...
    'FontName',get(0,'defaultuicontrolFontName'),...
    'FontSize',12,...
    'String','Generate',...
    'Tag','generateBlock');

handles.importFromExcel = uicontrol(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'FontUnits','pixels',...
    'Callback',@importFromExcel_Callback,...
    'FontName',get(0,'defaultuicontrolFontName'),...
    'FontSize',12,...
    'HorizontalAlignment','center',...
    'String','<html>Import from<br>Excel<br>Selection</html>',...
    'Tag','importFromExcel');

handles.autoWirebt = uicontrol(...
    'Parent',handles.h1,...
    'Units','pixels',...
    'FontUnits','pixels',...
    'Callback',@autoWire_Callback,...
    'FontName',get(0,'defaultuicontrolFontName'),...
    'FontSize',12,...
    'HorizontalAlignment','center',...
    'String','<html>Automatic Wiring</html>',...
    'Tag','autoWirebt');

%% Menubar

handles.file_mn = uimenu(...
    'Parent',handles.h1,...
    'Label','File',...
    'Tag','File_mn'...
    );

handles.setting_mn = uimenu(...
    'Parent',handles.h1,...
    'Label','Setting',...
    'Tag','setting_mn'...
    );
handles.rmi_mn = uimenu(...
    'Parent',handles.setting_mn,...
    'Label','Set Requirement Link',...
    'Tag','rmi_mn',...
    'Callback',@rmi_mn_Callback...
    );

handles.lang_mn = uimenu(...
    'Parent',handles.setting_mn,...
    'Label','Language Setting',...
    'Tag','lang_mn'...
    );
handles.japanese_mn = uimenu(...
    'Parent',handles.lang_mn,...
    'Label','Japanese',...
    'Tag','japanese_mn',...
    'Callback',@japanese_mn_Callback...
    );
handles.english_mn = uimenu(...
    'Parent',handles.lang_mn,...
    'Label','English',...
    'Tag','english_mn',...
    'Callback',@english_mn_Callback...
    );
handles.help_mn = uimenu(...
    'Parent',handles.h1,...
    'Label','Help',...
    'Tag','Help_mn'...
    );
handles.h61 = uimenu(...
    'Parent',handles.help_mn,...
    'Label','Help',...
    'Tag','format_mn',...
    'Callback',@help_mn_Callback...
    );

%% Locale settings
create_localized_messages();
if isJapaneseEnv
    japanese_mn_Callback() 
else
    english_mn_Callback() 
end

%% InitValue analysis given by Block's OpenFcn callback
tableData = {};
for n=1:2:nargin
    switch varargin{n}
        case 'TableData'
            tableData = varargin{n+1};
            if ~isempty(tableData)
                set(handles.uitableVerificationEqs,'Data',tableData);
            end
        case 'WindowStyle'
            set(handles.h1,'WindowStyle',varargin{n+1})
        case 'Block'
            blk = varargin{n+1};
    end
end
if ~isempty(blk)
    pbs = get_param(blk,'UserData');
    if ~isempty(pbs)
        proplist = PropertyList(pbs.pblock);
        set(handles.uitableVerificationEqs,'Data',proplist.props2tableData);
    end
elseif isempty(regexp(evalc('javaclasspath(''-all'')'),'LiteralEqParser','once'))
    web(helpdescription,'-helpbrowser')
    errordlg('JAVAライブラリがロードされていません。setup_PropertySpecificationUI.m を実行する必要があります。ヘルプをご参照下さい。')
    close(handles.h1)    
else
    web(helpdescription,'-helpbrowser')
    errordlg('このツールを起動する場合にはSimulinkライブラリブラウザ上のPropertySpecificationブロックから起動します。ヘルプをご参照下さい。')
    close(handles.h1)
end

%% Resize callback
    function figureResizeFcnCallBack(hObject, eventdata) %#ok
        TableLpos = 10;
        TableRposMinus = 140;
        BLen = 50;
        figurePosition = get(gcf,'Position');
        uitableVerificationEqsPos = [TableLpos DistanceFromBottom figurePosition(3)-TableRposMinus figurePosition(4)-DistanceFromBottom-DistanceFromTop];
        uitableVerificationEqsPos(uitableVerificationEqsPos<0) = 1;
        ColumnWidth = figurePosition(3)-1000+300;
        ColumnWidth(ColumnWidth<0) = 10;
        set(handles.uitableVerificationEqs,'Position',uitableVerificationEqsPos,...
            'ColumnWidth',{ 278 ColumnWidth BLen BLen BLen BLen BLen }); % 1st column is variable and fit to figure size.
        
        AddRemoveButtonHpos = 65;
        set(handles.buttonAddRow,'Position',...
            [figurePosition(3)-105 figurePosition(4)-AddRemoveButtonHpos 47 30]);
        set(handles.buttonRemoveRow,'Position',...
            [figurePosition(3)-50 figurePosition(4)-AddRemoveButtonHpos 47 30]);
        set(handles.importFromExcel,'Position',[figurePosition(3)-125 figurePosition(4)-120 120 50])
        set(handles.generateBlock,'Position',  [figurePosition(3)-125 figurePosition(4)-160 120 30])
        set(handles.autoWirebt,'Position',       [figurePosition(3)-125 figurePosition(4)-200 120 30])        
    end
%% Add row callback
    function addRow_Callback(hObject, eventdata) %#ok
        proplist = proplist.addPropertyElement(PropertyElement());
        newData = proplist.props2tableData();
        set(handles.uitableVerificationEqs,'Data',newData);
    end
%% Remove row callback
    function removeRow_Callback(hObject, eventdata) %#ok
        Data = get(handles.uitableVerificationEqs,'Data');
        if size(Data,1) < 2
            return;
        end
        proplist = proplist.deleteLastRow();
        newData = proplist.props2tableData;
        set(handles.uitableVerificationEqs,'Data',newData);
    end

%% Generate Block
    function generateBlock_Callback(hObject, eventdata)
        % Error detection
        if isempty(blk)
            return;
        end
        try
            orgPos = get_param(blk,'Position');
        catch %#ok
            warndlg('PropertySpecification block has been deleted. Please close this Window.')
            return;
        end
        LineInfo = storeConnectedLineInfo(blk);
        proplist.table2props(get(handles.uitableVerificationEqs,'Data'));
        proplist_new = proplist.checkPropertyCompatibility();
        if isa(pbs,'PropertySpecificationBlock')
            %pbs.isOnlyParseDiff = false;
            pbs.isOnlyParseDiff = true;
            pbs = pbs.updateBlock(blk);
            pbs = pbs.generateDiagram(proplist_new);
            set_param(blk,'UserData',pbs);
        else
            pbs = PropertySpecificationBlock(blk);
            pbs.isOnlyParseDiff = false;
            pbs = pbs.generateDiagram(proplist_new);
            pbs.isOnlyParseDiff = true;
            set_param(blk,'UserData',pbs);
        end
        set(handles.uitableVerificationEqs,'Data',proplist.props2tableData());

        % Even if block position is changed, we fix to the original position.
        removeUnConnectedLines(blk,LineInfo);
        set_param(blk,'Position',orgPos); 
        if ~isempty(handleInfo)
            handleInfo = autoWire(blk);
        end
    end

%% Import from Excel
    function  importFromExcel_Callback(hObject, eventdata) %#ok
        proplist = getExcelEquations(opt);
        tableData = proplist.props2tableData;
        set(handles.uitableVerificationEqs,'Data',tableData);
    end

%% Table Edit callback
    function uitableVerificationEqs_CellEditCallback(hObject, eventdata) %#ok
        tabledata =  get(handles.uitableVerificationEqs,'Data');
        proplist = proplist.table2props(tabledata);
        for m=1:size(tabledata,1)
            % enable/disable
            if length(pbs.pblock) >= m
                pbs.pblock(m).isEnable = tabledata{m,4};
                pbs.pblock(m).updateTCAPBlock();
            end
            if tabledata{m,5} % display
                vsub = find_system(blk,'LookUnderMasks','all','SearchDepth',1,'Name',sprintf('EQ%03d',m));                
                if length(vsub) == 1
                    open_system(vsub{1},'force');
                    tabledata{m,5} = false;
                    set(handles.uitableVerificationEqs,'Data',tabledata);
                end
            end            
        end
    end
%% Figure close callback
    function figureCloseRequestFcnCallBack(hObject, eventdata)
        try
            if ~isempty(blk)
                generateBlock_Callback(hObject, eventdata);
            end
        catch ME
            delete(handles.h1)
            rethrow(ME)
        end
        delete(handles.h1)
    end

%% Automatic wiring
    function autoWire_Callback(hObject, eventdata) %#ok
        if ~isempty(blk)
            handleInfo = autoWire(blk);
        end
    end

%% RMI
    function rmi_mn_Callback(hObject, eventdata) %#ok
        if strcmp(get(hObject,'Checked'),'on')
            set(hObject,'Checked','off')
            opt.isRMI = false;
        else
            set(hObject,'Checked','on')
            opt.isRMI = true;
        end
    end


    function create_localized_messages()
               
        ja.string.generateBlock = 'サブシステムを更新';
        en.string.generateBlock = 'Refresh SubSystem';
        ja.string.importFromExcel = '<html>Excelから<br>インポート</html>';
        en.string.importFromExcel = '<html>Import from<br>Excel sheet</html>';
        %ja.string. = '';
        %en.string. = '';

        ja.string.autoWirebt = '自動結線';
        en.string.autoWirebt = 'Automatic wiring';     

        %ja.string. = '';
        %en.string. = '';
        ja.label.rmi_mn = 'Excelへのリンクを自動的に設定';
        en.label.rmi_mn = 'Automatically set a link to Excel';
        ja.label.help_mn = 'ヘルプ';
        en.label.help_mn = 'Help';
        ja.label.setting_mn = '設定';
        en.label.setting_mn = 'Settings';
        % ja.message. = '';
        % en.message. = '';
        
        % ja.label. = '';
        % en.label. = '';
        % ja.warndlg{1} = '';
        % en.warndlg{1} = '';
        ja.uitableVerificationEqs = {'説明'; '検査式/前提条件'; '種別'; '有効'; '表示'; 'RMI'; '遅延' };
        en.uitableVerificationEqs = {'Description'; 'Property / Assumption'; 'Type'; 'Enable'; 'Display'; 'RMI'; 'Delay' };
 
        guistr_ja = ja;
        guistr_en = en;
        
        % Language setting is refers to MATLAB desktop language.
        if isJapaneseEnv()
            guistr = guistr_ja;
            changeFontName(handles,'Monospaced')
        else
            guistr = guistr_en;
            changeFontName(handles,'Arial')
        end
        handles.guistr_ja = guistr_ja;
        handles.guistr_en = guistr_en;
    end

%% set GUI strings
    function set_GUI_strings() 
        
        % set String properties
        flnames=fieldnames(handles.guistr.string);
        for n=1:length(flnames)
            set(handles.(flnames{n}),'String',handles.guistr.string.(flnames{n}));
        end
        
        % set Title properties
%         flnames=fieldnames(handles.guistr.title);
%         for n=1:length(flnames)
%             set(handles.(flnames{n}),'Title',handles.guistr.title.(flnames{n}));
%         end
%         
        % set label properties
        flnames=fieldnames(handles.guistr.label);
        for n=1:length(flnames)
            set(handles.(flnames{n}),'Label',handles.guistr.label.(flnames{n}));
        end
        
        % set tooltips properties
        % flnames=fieldnames(handles.guistr.tooltips);
        % for n=1:length(flnames)
        %     set(handles.(flnames{n}),'TooltipString',handles.guistr.tooltips.(flnames{n}));
        % end
 set(handles.uitableVerificationEqs,'ColumnName',handles.guistr.uitableVerificationEqs)

    end

%% Change FontName to use differenct fonts in JA and EN
    function changeFontName(handles,FontName)
        flnames = fieldnames(handles);
        for n=1:length(flnames)
            hn = handles.(flnames{n});
            if ishandle(hn)
                if any(strcmp(get(hn,'Type'),{'uicontrol','uipanel','uitable'}))
                    set(hn,'FontName',FontName)
                end
            end
        end
    end

    function japanese_mn_Callback(hObject, eventdata) 
        handles.guistr = handles.guistr_ja;
        set_GUI_strings();
        changeFontName(handles,'MS Gothic')
        set(handles.japanese_mn,'Checked','on')
        set(handles.english_mn,'Checked','off')
        toolroot = fileparts(which(mfilename));
        helpdescription = fullfile(toolroot,'doc_ja/description.html');
    end

    function english_mn_Callback(hObject, eventdata) 
        handles.guistr = handles.guistr_en;
        set(handles.japanese_mn,'Checked','off')
        set(handles.english_mn,'Checked','on')
        set_GUI_strings();
        %docpath = setDocPath(handles);
        changeFontName(handles,'Arial')
        toolroot = fileparts(which(mfilename));
        helpdescription = fullfile(toolroot,'doc_en/description.html');
    end
    function help_mn_Callback(hObject, eventdata) 
            web(helpdescription,'-helpbrowser')
    end
end