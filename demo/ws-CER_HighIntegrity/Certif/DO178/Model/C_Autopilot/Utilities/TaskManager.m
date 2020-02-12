function varargout = TaskManager(varargin)
% TASKMANAGER MATLAB code for TaskManager.fig
%      TASKMANAGER, by itself, creates a new TASKMANAGER or raises the existing
%      singleton*.
%
%      H = TASKMANAGER returns the handle to a new TASKMANAGER or the handle to
%      the existing singleton*.
%
%      TASKMANAGER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TASKMANAGER.M with the given input arguments.
%
%      TASKMANAGER('Property','Value',...) creates a new TASKMANAGER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before TaskManager_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to TaskManager_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help TaskManager

% Last Modified by GUIDE v2.5 18-Nov-2011 10:26:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @TaskManager_OpeningFcn, ...
                   'gui_OutputFcn',  @TaskManager_OutputFcn, ...
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


% --- Executes just before TaskManager is made visible.
function TaskManager_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to TaskManager (see VARARGIN)

% Choose default command line output for TaskManager
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes TaskManager wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = TaskManager_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in popupmenu_task.
function popupmenu_task_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu_task (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu_task contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu_task

map = mapTask2FileType();
prjTask = get(hObject,'String');

fileTypes = map(prjTask{get(hObject,'Value')});
prjFiles = MyProject.getFile('File Type',fileTypes);
if isempty(prjFiles)
    prjFiles = {''};
end

set(handles.popupmenu_file,'String',prjFiles)



% --- Executes during object creation, after setting all properties.
function popupmenu_task_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu_task (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
contents = load('ProjectTasks.mat');
set(hObject,'String',{contents.prjLCS.Name});
clear contents


% --- Executes on selection change in popupmenu_file.
function popupmenu_file_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu_file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu_file contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu_file


% --- Executes during object creation, after setting all properties.
function popupmenu_file_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu_file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_run.
function pushbutton_run_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton_cancel.
function pushbutton_cancel_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_cancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton_viewScript.
function pushbutton_viewScript_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_viewScript (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
