function varargout = sfcockpitDisplay(varargin)
% SFCOCKPITDISPLAY MATLAB code for sfcockpitDisplay.fig
%      SFCOCKPITDISPLAY, by itself, creates a new SFCOCKPITDISPLAY or raises the existing
%      singleton*.
%
%      H = SFCOCKPITDISPLAY returns the handle to a new SFCOCKPITDISPLAY or the handle to
%      the existing singleton*.
%
%      SFCOCKPITDISPLAY('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SFCOCKPITDISPLAY.M with the given input arguments.
%
%      SFCOCKPITDISPLAY('Property','Value',...) creates a new SFCOCKPITDISPLAY or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before sfcockpitDisplay_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to sfcockpitDisplay_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help sfcockpitDisplay

% Last Modified by GUIDE v2.5 25-Dec-2012 12:32:08

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @sfcockpitDisplay_OpeningFcn, ...
    'gui_OutputFcn',  @sfcockpitDisplay_OutputFcn, ...
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

% --- Executes just before sfcockpitDisplay is made visible.
function sfcockpitDisplay_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to sfcockpitDisplay (see VARARGIN)

% Choose default command line output for sfcockpitDisplay
handles.output = hObject;
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/TimeOffset','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/APU_Master','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/APU_Start','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/Engine_Master','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/Engine_Start','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/CSTR','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/WPT','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/VORD','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/NDB','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/ARPT','Value','0');
    set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.ILS');
    set_param('DisplayModel/Inputs/UserSelection/EFISInput','Value','EFIS_Pressure.inHg');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/CabinPressure_sensor/CabinLowPrFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/APUData_sensor/APUFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/HydraulicPressure_sensor/HydLowPrFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/OilPressure_sensor/EngineOilLowPrFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/FuelPressure_sensor/FuelLowPrFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/FuelQuantity_sensor/FuelQnttyLowFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/LandingGearLeftLock_sensor/LGLeftLockFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/LandingGearRightLock_sensor/LGRightLockFault_UserInput','Value','0');
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/RPM_sensor/EngineSpeedFault_UserInput','Value','0');
end
% j = javaObjectEDT(javax.swing.JLabel(display_text));
% h_warning_text = findobj(gcf,'type','hgjavacomponent');
% set(h_warning_text,'tag','WarningText');
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes sfcockpitDisplay wait for user response (see UIRESUME)
% uiwait(handles.sfcockpitdisplay);


% --- Outputs from this function are returned to the command line.
function varargout = sfcockpitDisplay_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



% --- Executes during object creation, after setting all properties.
function slider2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes during object creation, after setting all properties.
function slider3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

% --- Executes during object creation, after setting all properties.
function NDMode_CreateFcn(hObject, eventdata, handles)
% hObject    handle to NDMode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
% if bdIsLoaded('DisplayModel')
%     set_param('DisplayModel/Inputs/NDPageInput','Value','NDPageInput.ILS');
%     % set(hObject, 'String',{'LS','VOR','NAV','ARC','PLAN'});
% end
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function AirSpeed_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AirSpeed (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject,'YAxisLocation','right',...
    'YColor',[1 1 1],'XTick',[],'FontWeight','bold',...
    'TickLength',[0.05 0.05],'LineWidth',1.5);
guidata(hObject, handles);
% Hint: place code in OpeningFcn to populate AirSpeed


% --- Executes during object creation, after setting all properties.
function Altitude_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Altitude (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% set(hObject,'Color',[169/256 169/256 169/256],'YColor',[1 1 1],'XTick',[],...
%     'FontWeight','bold','TickLength',[0.1 0.1],'LineWidth',1.5);
set(hObject,'YColor',[1 1 1],'XTick',[],...
    'FontWeight','bold','TickLength',[0.05 0.05],'LineWidth',1.5);
guidata(hObject, handles);
% Hint: place code in OpeningFcn to populate Altitude


% --- Executes during object creation, after setting all properties.
function Attitude_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Attitude (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% create patches
% XLimit = get(hObject,'XLim');
% YLimit = get(hObject,'YLim');
set(hObject,'XTick',[],'YTick',[]);
guidata(hObject, handles);
% Hint: place code in OpeningFcn to populate Attitude


% --- Executes during object creation, after setting all properties.
function Heading_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Heading (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject,'XAxisLocation','top',...
    'XColor',[1 1 1],'YTick',[],'FontWeight','bold',...
    'TickLength',[0.05 0.05],'LineWidth',1.5);
guidata(hObject, handles);
% Hint: place code in OpeningFcn to populate Heading


% --- Executes when selected object is changed in uipanel18.
function uipanel18_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel18
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'radiobutton1'
        disp('test1')
    case 'radiobutton2'
        disp('test2')
    case 'radiobutton3'
        disp('test3')
end


% --- Executes when selected object is changed in uipanel19.
function uipanel19_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel19
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'radiobutton4'
        disp('test4')
    case 'radiobutton5'
        disp('test5')
end


% --- Executes when selected object is changed in uipanel20.
function uipanel20_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel20
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'radiobutton6'
        disp('test6')
    case 'radiobutton7'
        disp('test7')
    case 'radiobutton8'
        disp('test8')
end


% --- Executes when selected object is changed in uipanel21.
function uipanel21_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel21
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'EFIS_inHg'
        set_param('DisplayModel/Inputs/UserSelection/EFISInput','Value','EFIS_Pressure.inHg');
    case 'EFIS_mmHg'
        set_param('DisplayModel/Inputs/UserSelection/EFISInput','Value','EFIS_Pressure.mmHg');
end

% --- Executes on button press in CSTR.
function CSTR_Callback(hObject, eventdata, handles)
% hObject    handle to CSTR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/CSTR','Value',num2str(get(hObject,'Value')));
    %      set_param('DisplayModel/CSTR','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of CSTR


% --- Executes on button press in WPT.
function WPT_Callback(hObject, eventdata, handles)
% hObject    handle to WPT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/WPT','Value',num2str(get(hObject,'Value')));
    %      set_param('DisplayModel/WPT','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of WPT


% --- Executes on button press in VORD.
function VORD_Callback(hObject, eventdata, handles)
% hObject    handle to VORD (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/VORD','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of VORD


% --- Executes on button press in NDB.
function NDB_Callback(hObject, eventdata, handles)
% hObject    handle to NDB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/NDB','Value',num2str(get(hObject,'Value')));
    %      set_param('DisplayModel/NDB','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of NDB


% --- Executes on button press in ARPT.
function ARPT_Callback(hObject, eventdata, handles)
% hObject    handle to ARPT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/NDAdditionalInput/ARPT','Value',num2str(get(hObject,'Value')));
    %      set_param('DisplayModel/ARPT','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of ARPT


% --- Executes when selected object is changed in uipanel23.
function uipanel23_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel23
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
% h = findobj(gcf,'Tag','NavigationDisplay');
% axes(h)
% switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
%     case 'CSTR'
%         rgb = imread('ngc6543a.jpg');
%         image(rgb);
%         axis off
%     case 'togglebutton8'
%         load mandrill
%         image(X)
%         colormap(map)
%         axis off
%         axis image
%     case 'togglebutton9'
%         k = 5;
%         n = 2^k-1;
%         [x,y,z] = sphere(n);
%         c = hadamard(2^k);
%         surf(x,y,z,c);
%         axis off
%     case 'togglebutton10'
%         load clown
%         imagesc(X)
%         axis off
%     case 'togglebutton11'
%         i = imread('eight.tif');
%         imagesc(i);
%         axis off
% end
% set(gca,'Tag','NavigationDisplay');


% --- Executes when selected object is changed in uipanel24.
function uipanel24_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel24
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
% h = findobj(gcf,'Tag','SystemDisplay');
% axes(h)
current_val = get_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value');
funcChangeBGColors(handles);
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'ENG'
        if ~strcmp(current_val, 'ECAMInput.ENG')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.ENG');
        else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
    case 'BLEED'
         if ~strcmp(current_val, 'ECAMInput.BLEED')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.BLEED');
         else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
    case 'PRESS'
        if ~strcmp(current_val, 'ECAMInput.PRESS')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.PRESS');
        else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
    case 'HYD'
        if ~strcmp(current_val, 'ECAMInput.HYD')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.HYD');
        else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
    case 'FUEL'
        if ~strcmp(current_val, 'ECAMInput.FUEL')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.FUEL');
        else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
    case 'APU'
        if ~strcmp(current_val, 'ECAMInput.APU')
            set(hObject,'BackgroundColor',[0/256 139/256 69/256]);
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.APU');
        else
            set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
        end
end

function funcChangeBGColors(handles)
set(handles.ENG,'BackgroundColor','black');
set(handles.BLEED,'BackgroundColor','black');
set(handles.PRESS,'BackgroundColor','black');
set(handles.HYD,'BackgroundColor','black');
set(handles.FUEL,'BackgroundColor','black');
set(handles.APU,'BackgroundColor','black');



% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over APUStart.
function IgnitionSwitch_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% rto = get('DisplayModel/Inputs/Sensors/Clock','runtimeobject');
% CurrSimTime = rto.InputPort(1).Data;
% set_param('DisplayModel/Inputs/Sensors/TimeOffset','Value','CurrSimTime');

function APUStart_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --- Executes on button press in APUStart.
function APUStart_Callback(hObject, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    %     h_IgnitionSw = findall(0,'tag','APUMaster');
    %     if get(h_IgnitionSw,'Value')>0
    set_param('DisplayModel/Inputs/UserSelection/APU_Start','Value','1');
    %     end
end
% clc
% h_IgnitionSw = findall(0,'tag','APUStart');
% disp('ignition switch')
% get(h_IgnitionSw,'Value')
% disp('apu switch')
% get(hObject,'Value')

% --- Executes on button press in APUMaster.
function APUMaster_Callback(hObject, eventdata, handles)
% hObject    handle to APUMaster (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/APU_Master','Value','1');
end
% Hint: get(hObject,'Value') returns toggle state of APUMaster


% --- Executes on button press in EngineMaster.
function EngineMaster_Callback(hObject, eventdata, handles)
% hObject    handle to EngineMaster (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/Engine_Master','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of EngineMaster


% --- Executes on button press in EngineStart.
function EngineStart_Callback(hObject, eventdata, handles)
% hObject    handle to EngineStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/Engine_Start','Value',num2str(get(hObject,'Value')));
        rto = get_param('DisplayModel/Inputs/Sensors/Clock','runtimeobject');
    CurrSimTime = rto.OutputPort(1).Data;
    set_param('DisplayModel/Inputs/Sensors/TimeOffset','Value',num2str(CurrSimTime));
end
% Hint: get(hObject,'Value') returns toggle state of EngineStart



% --- Executes during object creation, after setting all properties.
function NavigationDisplay_CreateFcn(hObject, eventdata, handles)
% hObject    handle to NavigationDisplay (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: place code in OpeningFcn to populate NavigationDisplay
% set(gca,'Visible','off');
set(gca,'Visible','on','Color',[0 0 0], 'XTick', [], 'YTick', [])
% text(0.4, 0.4, 'Starting...','Color',[0 1 0]);



% --- Executes during object creation, after setting all properties.
function SystemDisplay_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemDisplay (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: place code in OpeningFcn to populate SystemDisplay
set(gca,'Visible','on','Color',[0 0 0], 'XTick', [], 'YTick', [])
% text(0.4, 0.4, 'Starting...','Color',[0 1 0]);


% --- Executes during object creation, after setting all properties.
function FlapPosition_CreateFcn(hObject, eventdata, handles)
% hObject    handle to FlapPosition (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'Color',[0 0 0], 'XTick', [], 'YTick', [])
% text(0.4, 0.4, 'Starting...','Color',[0 1 0]);
% Hint: place code in OpeningFcn to populate FlapPosition


% --- Executes when user attempts to close sfcockpitdisplay.
function sfcockpitdisplay_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to sfcockpitdisplay (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel', 'SimulationCommand', 'stop');
    % Hint: delete(hObject) closes the figure
end
delete(hObject);


% --- Executes during object creation, after setting all properties.
function uipanel24_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uipanel24 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/UserSelection/ECAMInput','Value','ECAMInput.None');
end
% --- Executes on button press in APU.

% --- Executes during object creation, after setting all properties.
function EngineIndicator_CreateFcn(hObject, eventdata, handles)
% hObject    handle to EngineIndicator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'Color',[0 0 0], 'XTick', [], 'YTick', [])
% text(0.4, 0.4, 'Starting...','Color',[0 1 0]);
% Hint: place code in OpeningFcn to populate EngineIndicator


function IgnitionSwitch_Callback(hObject, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clc
h_IgnitionSw = findall(0,'tag','APUMaster');
disp('ignition switch')
get(hObject,'Value')
disp('apu switch')
get(h_IgnitionSw,'Value')



% --- Executes when selected object is changed in NDPageMode.
function NDPageMode_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in NDPageMode 
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
switch get(eventdata.NewValue,'Tag') % Get Tag of selected object.
    case 'ILS'
        set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.ILS');
    case 'VOR'
        set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.VOR');
    case 'NAV'
        set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.NAV');
    case 'ARC'
        set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.ARC');
    case 'PLAN'
        set_param('DisplayModel/Inputs/UserSelection/NDPageInput','Value','NDPageInput.PLAN');
end

% --- Executes on button press in APU_Fault.
function APU_Fault_Callback(hObject, eventdata, handles)
% hObject    handle to APU_Fault (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/APUData_sensor/APUFault_UserInput','Value',num2str(get(hObject,'Value')));   
end
% Hint: get(hObject,'Value') returns toggle state of APU_Fault


% --- Executes on button press in Eng_Oil_Pr_Low.
function Eng_Oil_Pr_Low_Callback(hObject, eventdata, handles)
% hObject    handle to Eng_Oil_Pr_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/OilPressure_sensor/EngineOilLowPrFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Eng_Oil_Pr_Low


% --- Executes on button press in Cabin_Pressure_Low.
function Cabin_Pressure_Low_Callback(hObject, eventdata, handles)
% hObject    handle to Cabin_Pressure_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/CabinPressure_sensor/CabinLowPrFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Cabin_Pressure_Low


% --- Executes on button press in Hyd_Pressure_Low.
function Hyd_Pressure_Low_Callback(hObject, eventdata, handles)
% hObject    handle to Hyd_Pressure_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/HydraulicPressure_sensor/HydLowPrFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Hyd_Pressure_Low

% --- Executes on button press in Fuel_Pressure.
function Fuel_Pressure_Callback(hObject, eventdata, handles)
% hObject    handle to Fuel_Pressure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/FuelPressure_sensor/FuelLowPrFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Fuel_Pressure

% --- Executes on button press in Fuel_Quantity.
function Fuel_Quantity_Callback(hObject, eventdata, handles)
% hObject    handle to Fuel_Quantity (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/FuelQuantity_sensor/FuelQnttyLowFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Fuel_Quantity


% --- Executes on button press in Landing_Gear.
function Landing_Gear_Callback(hObject, eventdata, handles)
% hObject    handle to Landing_Gear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/LandingGearLeftLock_sensor/LGLeftLockFault_UserInput','Value',num2str(get(hObject,'Value')));
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/LandingGearRightLock_sensor/LGRightLockFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Landing_Gear


% --- Executes on button press in Engine_Speed.
function Engine_Speed_Callback(hObject, eventdata, handles)
% hObject    handle to Engine_Speed (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if bdIsLoaded('DisplayModel')
    set_param('DisplayModel/Inputs/Sensors/SwitchedOn/RPM_sensor/EngineSpeedFault_UserInput','Value',num2str(get(hObject,'Value')));
end
% Hint: get(hObject,'Value') returns toggle state of Engine_Speed


function APU_Callback(hObject, eventdata, handles)
% hObject    handle to APU (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hint: get(hObject,'Value') returns toggle state of APU


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2
% --- Executes on button press in APUStart.



% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% --- Executes on button press in ENG.
function ENG_Callback(hObject, eventdata, handles)
% hObject    handle to ENG (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in BLEED.
function BLEED_Callback(hObject, eventdata, handles)
% hObject    handle to BLEED (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton3.
function pushbutton17_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in HYD.
function pushbutton18_Callback(hObject, eventdata, handles)
% hObject    handle to HYD (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in FUEL.
function FUEL_Callback(hObject, eventdata, handles)
% hObject    handle to FUEL (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton8.
function pushbutton20_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton11.
function pushbutton11_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in HYD.
function HYD_Callback(hObject, eventdata, handles)
% hObject    handle to HYD (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in radiobutton5.
function radiobutton5_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton5


% --- Executes on button press in radiobutton5.
function EFIS_mmHg_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton5


% --- Executes on button press in radiobutton6.
function radiobutton6_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton6


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider

% --- Executes on slider movement.
function slider3_Callback(hObject, eventdata, handles)
% hObject    handle to slider3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider

% --- Executes on button press in radiobutton6.
function EFIS_inHg_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton6


% --- Executes on button press in radiobutton6.
function radiobutton11_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton6


% --- Executes on button press in pushbutton22.
function pushbutton22_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton22 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton23.
function pushbutton23_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton23 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton24.
function pushbutton24_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton24 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in radiobutton4.
function radiobutton4_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton4


% --- Executes on button press in radiobutton4.
function radiobutton14_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton4


% --- Executes on button press in pushbutton25.
function pushbutton25_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton25 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton26.
function pushbutton26_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton26 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% --- Executes on button press in pushbutton27.
function pushbutton27_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton27 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton28.
function pushbutton28_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% --- Executes on button press in pushbutton29.
function pushbutton29_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton29 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object deletion, before destroying properties.
function AirSpeed_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to AirSpeed (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object deletion, before destroying properties.
function Altitude_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to Altitude (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function FCU_speed_CreateFcn(hObject, eventdata, handles)
% hObject    handle to FCU_speed (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function EFIS_pressure_CreateFcn(hObject, eventdata, handles)
% hObject    handle to EFIS_pressure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over EFIS_pressure.
function EFIS_pressure_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to EFIS_pressure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over APUStart.


% --- Executes during object creation, after setting all properties.
function IgnitionSwitch_CreateFcn(~, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function APUStart_CreateFcn(hObject, eventdata, handles)
% hObject    handle to APUStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function sfcockpitdisplay_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sfcockpitdisplay (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in pushbutton59.
function pushbutton59_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton59 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton60.
function pushbutton60_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton60 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton61.
function pushbutton61_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton61 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton62.
function pushbutton62_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton62 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton63.
function pushbutton63_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton63 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton64.
function pushbutton64_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton64 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton65.
function pushbutton65_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton65 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton66.
function pushbutton66_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton66 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton67.
function pushbutton67_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton67 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton68.
function pushbutton68_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton68 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function EDBL_CreateFcn(hObject, eventdata, handles)
% hObject    handle to EDBL (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in radiobutton28.
function radiobutton28_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton28


% --- Executes on button press in radiobutton29.
function radiobutton29_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton29 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton29


% --- Executes on button press in radiobutton30.
function radiobutton30_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton30 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton30


% --- Executes on button press in radiobutton31.
function radiobutton31_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton31 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton31


% --- Executes on button press in radiobutton32.
function radiobutton32_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton32 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton32


% --- Executes on button press in radiobutton33.
function radiobutton33_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton33 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton33


% --- Executes on button press in APU_Fault.
function checkbox34_Callback(hObject, eventdata, handles)
% hObject    handle to APU_Fault (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of APU_Fault


% --- Executes on button press in Eng_Oil_Pr_Low.
function checkbox35_Callback(hObject, eventdata, handles)
% hObject    handle to Eng_Oil_Pr_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Eng_Oil_Pr_Low


% --- Executes on button press in Cabin_Pressure_Low.
function checkbox36_Callback(hObject, eventdata, handles)
% hObject    handle to Cabin_Pressure_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Cabin_Pressure_Low


% --- Executes on button press in Hyd_Pressure_Low.
function checkbox37_Callback(hObject, eventdata, handles)
% hObject    handle to Hyd_Pressure_Low (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Hyd_Pressure_Low


% --- Executes on button press in Fuel_Pressure.
function checkbox38_Callback(hObject, eventdata, handles)
% hObject    handle to Fuel_Pressure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Fuel_Pressure


% --- Executes on button press in Fuel_Quantity.
function checkbox39_Callback(hObject, eventdata, handles)
% hObject    handle to Fuel_Quantity (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Fuel_Quantity


% --- Executes on button press in Landing_Gear.
function checkbox40_Callback(hObject, eventdata, handles)
% hObject    handle to Landing_Gear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Landing_Gear


% --- Executes on button press in Engine_Speed.
function checkbox41_Callback(hObject, eventdata, handles)
% hObject    handle to Engine_Speed (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hint: get(hObject,'Value') returns toggle state of Engine_Speed
