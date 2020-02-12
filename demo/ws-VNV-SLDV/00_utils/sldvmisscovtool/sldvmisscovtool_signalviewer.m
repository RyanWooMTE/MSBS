function varargout = sldvmisscovtool_signalviewer(varargin)
% SLDVMISSCOVTOOL_SIGNALVIEWER A helper tool calling from sldvmisscovtool
%

%   Copyright 2010-2011 The MathWorks, Inc. 

% Edit the above text to modify the response to help sldvmisscovtool_signalviewer

% Last Modified by GUIDE v2.5 13-Apr-2010 14:22:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @sldvmisscovtool_signalviewer_OpeningFcn, ...
    'gui_OutputFcn',  @sldvmisscovtool_signalviewer_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before sldvmisscovtool_signalviewer is made visible.
function sldvmisscovtool_signalviewer_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to sldvmisscovtool_signalviewer (see VARARGIN)
handles.simdata = [];
sigarg = find(strcmp(varargin, 'simdata'));

if ~isempty(sigarg)
    handles.simdata = varargin{sigarg+1};
    listSimdata2listbox(handles,handles.simdata)
end

handles = create_localized_messages(handles);
set_GUI_strings(hObject, eventdata, handles);

% Choose default command line output for sldvmisscovtool_signalviewer
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes sldvmisscovtool_signalviewer wait for user response (see UIRESUME)
% uiwait(handles.figure1);

%% create_localized_messages
function handles=create_localized_messages(handles)

% Objects that have 'String' properties
ja.string.load_simdata_pb = 'simdataをロード';
en.string.load_simdata_pb = 'Load simdata';
ja.string.create_figure_bt = 'figureを作成';
en.string.create_figure_bt = 'Create figure';

% Objects that have 'ToolTips' properties
ja.tooltips.load_simdata_pb = 'WorkSpaceからsimdata変数を読み込みます';
en.tooltips.load_simdata_pb = 'Load simdata from WorkSpace';
ja.tooltips.create_figure_bt = '新しいfigureを作成し、表示中のグラフを描画します。';
en.tooltips.create_figure_bt = 'Create new figure and draw there displaying plots.';

% Objects that have 'Label' properties
ja.label.preferences_menu = '設定';
en.label.preferences_menu = 'Preferences';
ja.label.lang_setting_menu = '言語';
en.label.lang_setting_menu = 'Language';
ja.label.show_legends_menu = '凡例を表示';
en.label.show_legends_menu = 'Display legends';
ja.label.draw_separate_menu = '別々に描画';
en.label.draw_separate_menu = 'Separate axes';


guistr_ja = ja;
guistr_en = en;

% Language setting is refers to MATLAB desktop language.
if any(strcmp(get(0,'lang'),{'ja_jp.shift_jis','japanese','ja_jp'}))
    handles.guistr = guistr_ja;
else
    handles.guistr = guistr_en;
end
handles.guistr_ja = guistr_ja;
handles.guistr_en = guistr_en;

%% set GUI strings
function set_GUI_strings(hObject, eventdata, handles) %#ok

% set String properties
flnames=fieldnames(handles.guistr.string);
for n=1:length(flnames)
    set(handles.(flnames{n}),'String',handles.guistr.string.(flnames{n}));
end

% set label properties
flnames=fieldnames(handles.guistr.label);
for n=1:length(flnames)
    set(handles.(flnames{n}),'Label',handles.guistr.label.(flnames{n}));
end


function listSimdata2listbox(handles,simdata)

str = {};
for n=1:length(simdata)
    str{n} = sprintf('%d',n);
end
set(handles.simdata_lb,'String',str,'Value',1)
%    set(handles.figure1,'WindowStyle','Modal')

% --- Outputs from this function are returned to the command line.
function varargout = sldvmisscovtool_signalviewer_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in signals_lb.
function signals_lb_Callback(hObject, eventdata, handles)
% hObject    handle to signals_lb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns signals_lb contents as cell array
%        contents{get(hObject,'Value')} returns selected item from signals_lb
strs = get(handles.signals_lb,'String');
vals = get(handles.signals_lb,'Value');

% Position and size of the axis
pos.X = 0.43;
pos.Y = 0.16;
pos.Width = 0.546;
pos.Height = 0.786;
pos.margin = 0.06;
WSratio = 0.1;

if ~isfield(handles,'selectedlist') || isempty(handles.selectedlist)
    return;
end
ah = findobj(handles.figure1,'Type','axes');
for n=1:length(ah)
    delete(ah(n))
end
legstr={};
Nselected=length(vals);
if strcmp(get(handles.draw_separate_menu,'Checked'),'on') && Nselected < 11    
    for n=1:Nselected
        m = handles.selectedlist{vals(n)}(1);
        sign = handles.selectedlist{vals(n)}(2);
        %lot(handles.axes1,handles.simdata(m).time,handles.simdata(m).signals(sign).values,markerstr(m,sign));
        H = (pos.Height-(Nselected-1)*pos.margin)/Nselected;
        handles.ah(n) = axes('Position',[pos.X pos.Y+(n-1)*(pos.margin+H) pos.Width H]);
        stairs(handles.ah(n),handles.simdata(m).time,handles.simdata(m).signals(sign).values,markerstr(m,sign));
        maxv = max(handles.simdata(m).signals(sign).values(:));
        minv = min(handles.simdata(m).signals(sign).values(:));
        delta = WSratio*(maxv-minv);
        if minv<maxv
            ylim([minv-delta maxv+delta])
        end
        %xlabel('Time')
        ylabel(sprintf('%d-%d:%s',m,sign,handles.simdata(m).signals(sign).label),'Interpreter','none')
    end
else
    handles.axes1 = axes('Position',[pos.X pos.Y pos.Width pos.Height]);
    handles.output = hObject;
    guidata(hObject, handles);
    maxv=[]; minv=[];
    hold(handles.axes1,'on')
    for n=1:Nselected
        m = handles.selectedlist{vals(n)}(1);
        sign = handles.selectedlist{vals(n)}(2);
        %lot(handles.axes1,handles.simdata(m).time,handles.simdata(m).signals(sign).values,markerstr(m,sign));
        stairs(handles.axes1,handles.simdata(m).time,handles.simdata(m).signals(sign).values,markerstr(m,sign));
        maxv = max([maxv; handles.simdata(m).signals(sign).values(:)]);
        minv = min([minv; handles.simdata(m).signals(sign).values(:)]);

        legstr{end+1} =  sprintf('%d-%d:%s',m,sign,handles.simdata(m).signals(sign).label);
    end
    delta = WSratio*(maxv-minv);
    if minv<maxv
        ylim([minv-delta maxv+delta])
    end
    legend(handles.axes1,legstr,'Interpreter','none')
    if strcmp(get(handles.show_legends_menu,'Checked'),'off')
        legend(handles.axes1,'off')
    end
    hold(handles.axes1,'off')
end
handles.output = hObject;
guidata(hObject, handles);


function str = markerstr(n,m)

plotCol={'r-','b-','g-','m-','c-','y-','k-','r:','b:','g:','y:','m:','c:','k:',...
    'r--','b--','g--','y--','m--','c--','k--','r-.','b-.','g-.','y-.','m-.','c-.','k-.'};
plotSym={'o','x','+','*','s','d','v','^','<','>','p','h'};

str = sprintf('%s%s%s',plotCol{mod(m-1,length(plotCol))+1},plotSym{mod(n-1,length(plotSym))+1});

% --- Executes during object creation, after setting all properties.
function signals_lb_CreateFcn(hObject, eventdata, handles)
% hObject    handle to signals_lb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in close_window_pb.
function close_window_pb_Callback(hObject, eventdata, handles)
% hObject    handle to close_window_pb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

close(handles.figure1)


% --- Executes on selection change in simdata_lb.
function simdata_lb_Callback(hObject, eventdata, handles)
% hObject    handle to simdata_lb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns simdata_lb contents as cell array
%        contents{get(hObject,'Value')} returns selected item from simdata_lb

signame = get(handles.simdata_lb,'String');
selected = get(handles.simdata_lb,'Value');
str = {};
handles.selectedlist = {};
if isempty(handles.simdata)
    return;
end

for n=1:length(selected)
    for m=1:length(handles.simdata(n).signals)
        dtstr='';
        if strcmp(class(handles.simdata(selected(n)).signals(m).values),'embedded.fi')
            dtstr='(fixpt)';
        else
            dtstr=sprintf('(%s)',class(handles.simdata(selected(n)).signals(m).values));
        end
        str{end+1} = sprintf('%d-%d:%s%s',selected(n),m,handles.simdata(selected(n)).signals(m).label,dtstr);
        handles.selectedlist{end+1} = [selected(n),m];
    end
end
set(handles.signals_lb,'String',str,'Value',1)
handles.output = hObject;
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function simdata_lb_CreateFcn(hObject, eventdata, handles)
% hObject    handle to simdata_lb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end




% --- Executes on button press in load_simdata_pb.
function load_simdata_pb_Callback(hObject, eventdata, handles)
% hObject    handle to load_simdata_pb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if evalin('base','exist(''simdata'',''var'')')
    handles.simdata = evalin('base','simdata');
else
    return;
end
listSimdata2listbox(handles,handles.simdata);
handles.output = hObject;
guidata(hObject, handles);

% --------------------------------------------------------------------
function Preferences_menu_Callback(hObject, eventdata, handles)
% hObject    handle to Preferences_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function show_datatypes_menu_Callback(hObject, eventdata, handles)
% hObject    handle to show_datatypes_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if strcmp(get(hObject,'Checked'),'off')
    set(hObject,'Checked','on')
    listbox2_Callback(hObject, eventdata, handles)
else
    set(hObject,'Checked','off')
    listbox2_Callback(hObject, eventdata, handles)
end
% --------------------------------------------------------------------
function show_legends_menu_Callback(hObject, eventdata, handles)
% hObject    handle to show_legends_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if strcmp(get(hObject,'Checked'),'off')
    set(hObject,'Checked','on')
    legend(handles.axes1,'show')
else
    set(hObject,'Checked','off')
    legend(handles.axes1,'hide')
end


% --------------------------------------------------------------------
function draw_separate_menu_Callback(hObject, eventdata, handles)
% hObject    handle to draw_separate_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if strcmp(get(hObject,'Checked'),'off')
    set(hObject,'Checked','on')
     signals_lb_Callback(hObject, eventdata, handles)
else
    set(hObject,'Checked','off')
     signals_lb_Callback(hObject, eventdata, handles)
end



% --- Executes on button press in create_figure_bt.
function create_figure_bt_Callback(hObject, eventdata, handles)
% hObject    handle to create_figure_bt (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

axh = findobj(handles.figure1,'Type','axes');
fh = figure();
for n=length(axh):-1:1
    naxh = copyobj(axh(n),fh);
    if ~strcmp(get(naxh,'Tag'),'legend')
    pos = get(naxh,'Position');
    set(naxh,'Position',[0.1,pos(2),0.85,pos(4)])
    end
end


% --------------------------------------------------------------------
function preferences_menu_Callback(hObject, eventdata, handles)
% hObject    handle to preferences_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function lang_setting_menu_Callback(hObject, eventdata, handles)
% hObject    handle to lang_setting_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)




% --------------------------------------------------------------------
function lang_ja_menu_Callback(hObject, eventdata, handles)
% hObject    handle to lang_ja_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.guistr = handles.guistr_ja;
set_GUI_strings(hObject, eventdata, handles);
handles.output = hObject;
guidata(hObject, handles);


% --------------------------------------------------------------------
function lang_en_menu_Callback(hObject, eventdata, handles)
% hObject    handle to lang_en_menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.guistr = handles.guistr_en;
set_GUI_strings(hObject, eventdata, handles);
handles.output = hObject;
guidata(hObject, handles);


