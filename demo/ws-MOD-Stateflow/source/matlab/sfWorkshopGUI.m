function varargout = sfWorkshopGUI(varargin)
% sfWorkshopGUI M-file for sfWorkshopGUI.fig
%      sfWorkshopGUI, by itself, creates a new sfWorkshopGUI or raises the existing
%      singleton*.
%
%      H = sfWorkshopGUI returns the handle to a new sfWorkshopGUI or the handle to
%      the existing singleton*.
%
%      sfWorkshopGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in sfWorkshopGUI.M with the given input arguments.
%
%      sfWorkshopGUI('Property','Value',...) creates a new sfWorkshopGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before sfWorkshopGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to sfWorkshopGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help sfWorkshopGUI

% Last Modified by GUIDE v2.5 27-Mar-2008 10:34:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @sfWorkshopGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @sfWorkshopGUI_OutputFcn, ...
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


% --- Executes just before sfWorkshopGUI is made visible.
function sfWorkshopGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to sfWorkshopGUI (see VARARGIN)

% Choose default command line output for sfWorkshopGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes sfWorkshopGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% If the aerospace blockset isn't installed, we need to disable the sim
% speed command buttons.
if ~license('test','aerospace_blockset')
    set(handles.rdoRealTime,'enable','off');
    set(handles.rdo5x,'enable','off');
    set(handles.rdo10x,'enable','off');
    set(handles.rdo100x,'enable','off');
end



% --- Outputs from this function are returned to the command line.
function varargout = sfWorkshopGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbStart.
function pbStart_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to pbStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if strcmp(get(hObject,'string'),'Start Sim') %It's stopped...start it.
    set(handles.rdoRealTime,'enable','off');
    set(handles.rdo5x,'enable','off');
    set(handles.rdo10x,'enable','off');
    set(handles.rdo100x,'enable','off');
    set(handles.rdoOnOff,'enable','off');
    set(handles.rdoFanFail,'enable','off');
    set(handles.sldTemp,'enable','off');
    set(hObject,'string','Stop Sim')
    set_param(bdroot,'simulationcommand','start')
    
    % Turn Device On/Off
    set(handles.rdoOnOff,'value',0);
    onPath=[bdroot,'/Device Switch'];
    usagePath=[bdroot,'/Power Slider'];

    set(handles.slider2,'value',0)
    set_param(onPath,'sw','0');
    set_param(usagePath,'gain','0');
    set(handles.txtUsage,'string','0 %');
    set(handles.slider2,'enable','off')
    
    % Turn fan failure off
    set(handles.rdoFanFail,'value',0);
    onPath=[bdroot,'/Fan Switch'];
    set_param(onPath,'sw',num2str(~get(handles.rdoFanFail,'value')))
    
    % Set ambient temperature to 72
    set(handles.sldTemp,'value',72);
    val='72';
    set(handles.txtDeg,'string',[val,' Deg F']);
    ambientPath=[bdroot,'/Temperature Slider'];
    set_param(ambientPath,'gain',num2str(val));
    
    % if you click on buttons while the model is building, you get some
    % warnings.  This disables the GUI while we wait for the sim to start.
    notDoneBuilding=1;
    while notDoneBuilding
        pause(.25);
        simTime=get_param(bdroot,'simulationtime');
        if simTime>1
            set(handles.rdoOnOff,'enable','on');
            set(handles.rdoFanFail,'enable','on');
            set(handles.sldTemp,'enable','on');
            notDoneBuilding=0;
        end
    end
    
else %It's going...stop it.
    set(handles.rdoRealTime,'enable','on');
    set(handles.rdo5x,'enable','on');
    set(handles.rdo10x,'enable','on');
    set(handles.rdo100x,'enable','on');
    set(hObject,'string','Start Sim')
    set_param(bdroot,'simulationcommand','stop')
end
% --- Executes on slider movement.
function sldTemp_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to sldTemp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
val=num2str(get(hObject,'value'));
set(handles.txtDeg,'string',[val,' Deg F']);

ambientPath=[bdroot,'/Temperature Slider'];

set_param(ambientPath,'gain',num2str(val));

% --- Executes during object creation, after setting all properties.
function sldTemp_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to sldTemp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in rdoOnOff.
function rdoOnOff_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdoOnOff (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdoOnOff

onPath=[bdroot,'/Device Switch'];
usagePath=[bdroot,'/Power Slider'];
    
if get(hObject,'value') %is on
    set(handles.slider2,'enable','on')
    set(handles.slider2,'value',400*.2) % 20%
    set(handles.txtUsage,'string','20 %');
    set_param(onPath,'sw','1');
    set_param(usagePath,'gain',num2str(400*.2));
else %is off
    set(handles.slider2,'value',0)
    set_param(onPath,'sw','0');
    set_param(usagePath,'gain','0');
    set(handles.txtUsage,'string','0 %');
    set(handles.slider2,'enable','off')
end

% --- Executes on button press in rdoFanFail.
function rdoFanFail_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdoFanFail (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdoFanFail
onPath=[bdroot,'/Fan Switch'];
set_param(onPath,'sw',num2str(~get(hObject,'value')))


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of
%        slider

val=get(hObject,'value');
usage=val/400; %0 to 400 on the slider

usagePath=[bdroot,'/Power Slider'];

if val>=(.2*400) % usage is 20% minimum if it's just on
    set(handles.txtUsage,'string',[num2str(usage*100),' %']);
    set_param(usagePath,'gain',num2str(val));
else % don't allow the usage to go below 20%
    set(hObject,'value',.2*400);
    set(handles.txtUsage,'string','20 %');
    set_param(usagePath,'gain',num2str(400*.2));
end



    

% --- Executes during object creation, after setting all properties.
function slider2_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes during object creation, after setting all properties.
 function text5_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to text5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% --- Executes during object creation, after setting all properties.
 function txtUsage_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to txtUsage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% --- Executes during object creation, after setting all properties.
 function figure1_CreateFcn(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Turns off the warning that you see when you change the pace of the
% simulation.  You're changing the value of a block in a library link.
msgID='Simulink:SL_SetParamLinkChangeWarn';
warning('off',msgID);

% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure

%See the CreateFcn above.  Just putting things back the way we found them.
msgID='Simulink:SL_SetParamLinkChangeWarn';
warning('on',msgID);

delete(hObject);

% --- Executes on button press in rdoRealTime.
function rdoRealTime_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdoRealTime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdoRealTime

paceBlk=[bdroot,'/Temperature Model/(Pace Control)/Simulation Pace'];

try 
    set_param(paceBlk,'SimulationPace','1');
catch
    fprintf('The speed settings have no effect with your current Temperature Model\n')
end


% --- Executes on button press in rdo5x.
function rdo5x_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdo5x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdo5x
paceBlk=[bdroot,'/Temperature Model/(Pace Control)/Simulation Pace'];

try 
    set_param(paceBlk,'SimulationPace','5');
catch
    fprintf('The speed settings have no effect with your current Temperature Model\n')
end



% --- Executes on button press in rdo10x.
function rdo10x_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdo10x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdo10x
paceBlk=[bdroot,'/Temperature Model/(Pace Control)/Simulation Pace'];

try 
    set_param(paceBlk,'SimulationPace','10');
catch
    fprintf('The speed settings have no effect with your current Temperature Model\n')
end



% --- Executes on button press in rdo100x.
function rdo100x_Callback(hObject, eventdata, handles) %#ok<DEFNU>
% hObject    handle to rdo100x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rdo100x
paceBlk=[bdroot,'/Temperature Model/(Pace Control)/Simulation Pace'];

try 
    set_param(paceBlk,'SimulationPace','1');
catch
    fprintf('The speed settings have no effect with your current Temperature Model\n')
end

