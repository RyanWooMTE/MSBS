function sfCockpitDisplay_helper(block, eventData)
% The figure's handle is stored in the block's UserData
h_blk = get(block,'BlockHandle');
blk_name = get(h_blk,'Name');
set(0,'ShowHiddenHandles','On');
switch blk_name
    case 'Out1' % Engine/Warnings Display
        %% creating and populating left axis
        value = block.InputPort(1).Data;
        warning_struct = calcWarning(value.warn_msgID,value.flightmode);
        numlinesDisp1 = 4;
        messagevalues_in = warning_struct.text;
        color = warning_struct.color;
        display_id = warning_struct.display_id;
        if size(color,1)>numlinesDisp1
            if any(strcmp(cellstr(color(numlinesDisp1+1:end,:)),'red'))
                numidx = numlinesDisp1 + find(strcmp(cellstr(color(numlinesDisp1+1:end,:)),'red'));
                display_id(numidx) = 2;
            end
        end
        numdisplay1_index = find(display_id==1);
        messagevalues_disp1 = messagevalues_in(numdisplay1_index,:);
        color_disp1 = color(numdisplay1_index,:);
        %         level_disp1 = level(numdisplay1_index);
        
        numdisplay2_index = find(display_id==2);
        messagevalues_disp2 = messagevalues_in(numdisplay2_index,:);
        color_disp2 = color(numdisplay2_index,:);
        %         level_disp2 = level(numdisplay2_index);
        clear messagevalues_in
        %% populating error messages in ED/W
        h_text_ax = findobj(0,'tag','EDBL_ax');
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_text_ax);
        %         axes(h_text_ax)
        h_chklist = findobj(0,'tag','EDBL_text');
        switch value.ED_Mode_L
            case -1
                if isempty(h_chklist)
                    text(0.1, 0.2, '...','Color',[0 1 0],'tag','EDBL_text','FontSize',15,'FontWeight','Bold');
                end
            case 0
                % do nothing
            case 1  % normal running mode
                %% populating take-off/landing checklists display
                display_text = '';
                numLines = size(messagevalues_disp1,1);
                for i = 1:numLines
                    if strcmp(color_disp1(i,:),'amber')
                        display_text = [display_text '\color{magenta}'...
                            messagevalues_disp1(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp1(i,:),'red  ')
                        display_text = [display_text '\color{red}'...
                            messagevalues_disp1(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp1(i,:),'blue ')
                        display_text = [display_text '\color{blue}'...
                            messagevalues_disp1(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp1(i,:),'white')
                        display_text = [display_text '\color{white}'...
                            messagevalues_disp1(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp1(i,:),'green')
                        display_text = [display_text '\color{green}'...
                            messagevalues_disp1(i,:)...
                            '\newline'];
                    else
                    end
                end
                if ~isempty(display_text)
                    display_text(end-8:end) = [];
                end
                set(h_chklist,'Position',[0,0.5],'String',display_text,'tag','EDBL_text','FontSize',7,'interpreter','tex');
        end
        %% populating AutoBrake display
        h_text_ax = findobj(0,'tag','EDBR_ax');
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_text_ax);
        %         axes(h_text_ax)
        h_chklist = findobj(0,'tag','EDBR_text');
        switch value.ED_Mode_R
            case -1
                if isempty(h_chklist)
                    text(0.1, 0.2, '...','Color',[0 1 0],'tag','EDBR_text','FontSize',15,'FontWeight','Bold');
                end
            case 0
                % do nothing
            case 1  % normal running mode
                display_text = '';
                numLines = size(messagevalues_disp2,1);
                for i = 1:numLines
                    if strcmp(color_disp2(i,:),'amber')
                        display_text = [display_text '\color{magenta}'...
                            messagevalues_disp2(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp2(i,:),'red  ')
                        display_text = [display_text '\color{red}'...
                            messagevalues_disp2(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp2(i,:),'blue ')
                        display_text = [display_text '\color{blue}'...
                            messagevalues_disp2(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp2(i,:),'white')
                        display_text = [display_text '\color{white}'...
                            messagevalues_disp2(i,:)...
                            '\newline'];
                    elseif strcmp(color_disp2(i,:),'green')
                        display_text = [display_text '\color{green}'...
                            messagevalues_disp2(i,:)...
                            '\newline'];
                    else
                    end
                end
                if ~isempty(display_text)
                    display_text(end-8:end) = [];
                end
                
                %                 h_text_ax = findobj(0,'tag','EDBR_ax');
                %                 axes(h_text_ax)
                %                 h_chklist = findobj(0,'tag','EDBR_text');
                %                 if ~isempty(h_chklist)
                %                     delete(h_chklist)
                %                 end
                set(h_chklist,'Position',[0,0.5],'String',display_text,'tag','EDBR_text','FontSize',7,'interpreter','tex');
        end
    case 'Out2' % System Display
        %% populating ECAM Display
        h_text = findobj(0, 'tag','ECAMDispText');
        H_axes = findobj(0, 'tag','SystemDisplay');
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',H_axes)
        %         axes(H_axes);
        if isempty(h_text)
            h_text = text(0.4,0.5,'','tag','ECAMDispText');
        end
        value = block.InputPort(1).Data;
        switch value
            case -1
                set(h_text,'String','Display Starting...', 'Position',[0.25,0.5],'Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 1
                set(h_text,'String','PushbackAndTaxi', 'Position',[0.15,0.5],'color',[0 0 1],'FontSize',15,'FontWeight','Bold');
            case 2
                set(h_text,'String','TakeoffCruiseDescent', 'Position',[0.1,0.5], 'color',[0 0 1],'FontSize',15,'FontWeight','Bold');
            case 3
                set(h_text,'String','Land', 'Position',[0.4,0.5], 'color',[0 0 1],'FontSize',15,'FontWeight','Bold');
            case 4
                set(h_text,'String','Engine Page', 'Position',[0.3,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 5
                set(h_text,'String','Air Bleed Page', 'Position',[0.3,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 7
                set(h_text,'String','Hydraulic Page', 'Position',[0.2,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 8
                set(h_text,'String','APU Page', 'Position',[0.3,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 9
                set(h_text,'String','FUEL Page', 'Position',[0.3,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 10
                set(h_text,'String','Cabin Pressure Page', 'Position',[0.2,0.5], 'color',[1 0 0],'FontSize',15,'FontWeight','Bold');
            case 11
                set(h_text,'String','APU Started', 'Position',[0.3,0.5], 'color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 12
                set(h_text,'String','Engine Started', 'Position',[0.3,0.5], 'color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            otherwise
                set(h_text,'String','NO PAGE', 'Position',[0.4,0.5],'FontSize',15,'FontWeight','Bold');
        end
        
    case 'Out3' % FCU Display
        %%
        h_FCU_speed = findobj(0, 'tag','FCU_speed');
        h_FCU_heading = findobj(0, 'tag','FCU_heading');
        h_FCU_altitude = findobj(0, 'tag','FCU_altitude');
        value = block.InputPort(1).Data;
        set(h_FCU_speed,'String',num2str(value.Speed,'%.1f'));
        set(h_FCU_heading,'String',num2str(value.Heading,'%.1f'));
        set(h_FCU_altitude,'String',num2str(value.Altitude,'%.1f'));
    case 'Out4' % EFIS Pressure
        %%
        h_EFIS_Pressure = findobj(0, 'tag','EFIS_pressure');
        value = block.InputPort(1).Data;
        set(h_EFIS_Pressure,'String',num2str(value,'%.1f'));
    case 'Out5' % Engine Display
        %% finding parent axes and deleting children
        h_axes_L = findall(0, 'tag','EngineIndicator');
        h_axes_R = findall(0, 'tag','FlapPosition');
        %% Creating Objects in Top Left of Upper ECAM display
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes_L)
        %         axes(h_axes_L)
        h_EPR_E1 = findobj(0, 'tag','EPR_E1');
        if isempty(h_EPR_E1)
            delete(get(h_axes_L,'Children'))
            delete(get(h_axes_R,'Children'))
            h_EPR_E1 = text(0.05,0.7,'','tag','EPR_E1','FontSize',7);
        end
        
        h_EPR_E2 = findobj(0, 'tag','EPR_E2');
        if isempty(h_EPR_E2)
            h_EPR_E2 = text(0.55,0.7,'','tag','EPR_E2','FontSize',7);
        end
        
        h_EGT_E1 = findobj(0, 'tag','EGT_E1');
        if isempty(h_EGT_E1)
            h_EGT_E1 = text(0.05,0.5,'','tag','EGT_E1','FontSize',7);
        end
        
        h_EGT_E2 = findobj(0, 'tag','EGT_E2');
        if isempty(h_EGT_E2)
            h_EGT_E2 = text(0.55,0.5,'','tag','EGT_E2','FontSize',7);
        end
        
        h_N1_RPM_E1 = findobj(0, 'tag','N1_RPM_E1');
        if isempty(h_N1_RPM_E1)
            h_N1_RPM_E1 = text(0.05,0.3,'','tag','N1_RPM_E1','FontSize',7);
        end
        
        h_N1_RPM_E2 = findobj(0, 'tag','N1_RPM_E2');
        if isempty(h_N1_RPM_E2)
            h_N1_RPM_E2 = text(0.55,0.3,'','tag','N1_RPM_E2','FontSize',7);
        end
        %% Populating objects in Top Left of Upper ECAM display
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes_L)
        value = block.InputPort(1).Data;
        
        switch value.ED_Mode_L
            case -1
                h_start_text = findobj(h_axes_L, 'tag','starting');
                if isempty(h_start_text)
                    text(0, 0.4, 'Display Starting...','Color',[0 1 0],'tag','starting','FontWeight','bold','FontSize',12);
                end
            case 0
                % do nothing
            case 1
                h_start_text = findobj(h_axes_L, 'tag','starting');
                if ~isempty(h_start_text)
                    delete(h_start_text);
                end
                set(h_EPR_E1,'String',num2str(value.EPR1,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
                set(h_EGT_E1,'String',num2str(value.EGT1,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
                set(h_N1_RPM_E1,'String',num2str(value.N1_L,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
                set(h_EPR_E2,'String',num2str(value.EPR2,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
                set(h_EGT_E2,'String',num2str(value.EGT2,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
                set(h_N1_RPM_E2,'String',num2str(value.N1_R,'%.1f'), 'Color',[1 1 1],'FontWeight','bold','FontSize',12);
            otherwise
                set(h_EPR_E1,'String','ERROR');
                set(h_EGT_E1,'String','ERROR', 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
                set(h_N1_RPM_E1,'String','ERROR', 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
                set(h_EPR_E2,'String','ERROR', 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
                set(h_EGT_E2,'String','ERROR', 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
                set(h_N1_RPM_E2,'String','ERROR', 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
        end
        
        %% Creating Objects in Top Right of Upper ECAM display
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes_R);
        %         axes(h_axes_R)
        h_FOB = findobj(0, 'tag','FOB');
        if isempty(h_FOB)
            h_FOB = text(0.1,0.8,'','tag','FOB');
        end
        %% Populating objects in Top Right of Upper ECAM display
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes_R);
        switch value.ED_Mode_R
            case -1
                h_start_text = findobj(h_axes_R, 'tag','starting');
                if isempty(h_start_text)
                    text(0, 0.4, 'Display Starting...','Color',[0 1 0],'tag','starting','FontWeight','bold','FontSize',12);
                end
            case 0
                % do nothing
            case 1  % normal running mode
                h_start_text = findobj(h_axes_R, 'tag','starting');
                if ~isempty(h_start_text)
                    delete(h_start_text);
                end
                set(h_FOB,'String',['FOB: ' num2str(value.FuelQuantity,'%6.0f') ' lbs'], 'Color',[1 0 0],'FontWeight','bold','FontSize',12);
                h_flaps = findobj(h_axes_R, 'tag','flaps');
                if ~isempty(h_flaps)
                    delete(h_flaps);
                end
                set(h_axes_R,'NextPlot','add');
                switch value.FlapConfig
                    case 1
                        h_line = plot(h_axes_R, [0.2 0.4 0.8],[0.25 0.35 0.35],'-ow');
                    case 2
                        h_line = plot(h_axes_R, [0.2 0.4 0.8],[0.2 0.35 0.3],'-ow');
                    case 3
                        h_line = plot(h_axes_R, [0.2 0.4 0.8],[0.15 0.35 0.25],'-ow');
                end
                set(h_axes_R,'NextPlot','Replace','XLim', [0 1], 'YLim',[0 1]);
                set(h_line,'tag','flaps');
            otherwise
                set(h_FOB,'String','ERROR');
        end
    case 'Out6' % Navigational Display
        %%
        h_axes = findall(0, 'tag','NavigationDisplay');
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes);
        % axes(h_axes);
        h_text = findobj(h_axes, 'tag','NDModeText');
        if isempty(h_text)
            h_text = text(0.3,0.5,'','tag','NDModeText');
        end
        value = block.InputPort(1).Data;
        switch value
            case -1
                set(h_text,'String','Display Starting...','Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 1
                z = complex(1,1+rand/10);
                compass(h_axes, z,'-r')
                set(h_axes,'tag','NavigationDisplay');
                h_p = findall(h_axes,'type','patch');
                set(h_p,'FaceColor',[0 0 0]);
                h_t = findall(h_axes,'type','text');
                set(h_t,'Color',[1 1 1])
                h_l = findall(h_axes,'type','line');
                set(h_l,'Color',[1 1 1])
                h_text = findobj(h_axes, 'tag','NDModeText');
                if isempty(h_text)
                    h_text = text(0.4,0.4,'','tag','NDModeText');
                end
                Y_limit = ylim;
                X_limit = xlim;
                set(h_text,'String','ILS', 'color',[1 0 0],'Position',[(X_limit(1)+(X_limit(2)-X_limit(1))/2.5) (Y_limit(2)+ (Y_limit(2)-Y_limit(1))/15)],'FontSize',15,'FontWeight','Bold');
                set(h_fig,'CurrentAxes',h_axes);
            case 2
                %                 z = complex(1,1+rand/10);
                %                 compass(h_axes, z,'-r')
                %                 set(gca,'tag','NavigationDisplay');
                %                 h_p = findall(gca,'type','patch');
                %                 set(h_p,'FaceColor',[0 0 0]);
                %                 h_t = findall(gca,'type','text');
                %                 set(h_t,'Color',[1 1 1])
                %                 h_l = findall(gca,'type','line');
                %                 set(h_l,'Color',[1 1 1])
                h_text = findobj(h_axes, 'tag','NDModeText');
                if isempty(h_text)
                    h_text = text(0.4,0.4,'','tag','NDModeText');
                end
                Y_limit = ylim;
                X_limit = xlim;
                set(h_text,'String','VOR',  'color',[1 0 0],'Position',[(X_limit(1)+(X_limit(2)-X_limit(1))/2.5) (Y_limit(2)+ (Y_limit(2)-Y_limit(1))/15)],'FontSize',15,'FontWeight','Bold');
            case 3
                %                 z = complex(1,1+rand/100);
                %                 compass(h_axes, z,'-r')
                %                 set(gca,'tag','NavigationDisplay');
                %                 h_p = findall(gca,'type','patch');
                %                 set(h_p,'FaceColor',[0 0 0]);
                %                 h_t = findall(gca,'type','text');
                %                 set(h_t,'Color',[1 1 1])
                %                 h_l = findall(gca,'type','line');
                %                 set(h_l,'Color',[1 1 1])
                h_text = findobj(h_axes, 'tag','NDModeText');
                Y_limit = ylim;
                if isempty(h_text)
                    h_text = text(0.4,0.4,'','tag','NDModeText');
                end
                Y_limit = ylim;
                X_limit = xlim;
                set(h_text,'String','NAV',  'color',[1 0 0],'Position',[(X_limit(1)+(X_limit(2)-X_limit(1))/2.5) (Y_limit(2)+ (Y_limit(2)-Y_limit(1))/15)],'FontSize',15,'FontWeight','Bold');
            case 4
                %                 z = complex(1,1+rand/10);
                %                 compass(h_axes, z,'-r')
                %                 set(gca,'tag','NavigationDisplay');
                %                 h_p = findall(gca,'type','patch');
                %                 set(h_p,'FaceColor',[0 0 0]);
                %                 h_t = findall(gca,'type','text');
                %                 set(h_t,'Color',[1 1 1])
                %                 h_l = findall(gca,'type','line');
                %                 set(h_l,'Color',[1 1 1])
                h_text = findobj(h_axes, 'tag','NDModeText');
                if isempty(h_text)
                    h_text = text(0.4,0.4,'','tag','NDModeText');
                end
                Y_limit = ylim;
                X_limit = xlim;
                set(h_text,'String','ARC',  'color',[1 0 0],'Position',[(X_limit(1)+(X_limit(2)-X_limit(1))/2.5) (Y_limit(2)+ (Y_limit(2)-Y_limit(1))/15)],'FontSize',15,'FontWeight','Bold');
            case 5
                %                 z = complex(1,1+rand/10);
                %                 compass(h_axes, z,'-r')
                %                 set(gca,'tag','NavigationDisplay');
                %                 h_p = findall(gca,'type','patch');
                %                 set(h_p,'FaceColor',[0 0 0]);
                %                 h_t = findall(gca,'type','text');
                %                 set(h_t,'Color',[1 1 1])
                %                 h_l = findall(gca,'type','line');
                %                 set(h_l,'Color',[1 1 1])
                h_text = findobj(h_axes, 'tag','NDModeText');
                if isempty(h_text)
                    h_text = text(0.4,0.4,'','tag','NDModeText');
                end
                Y_limit = ylim;
                X_limit = xlim;
                set(h_text,'String','PLAN',  'color',[1 0 0],'Position',[(X_limit(1)+(X_limit(2)-X_limit(1))/2.5) (Y_limit(2)+ (Y_limit(2)-Y_limit(1))/15)],'FontSize',15,'FontWeight','Bold');
            otherwise
                set(h_text,'String','NO PAGE');
        end
    case 'Out7' % Additional Navigational Data
        %%
        h_axes = findobj(0, 'tag','NavigationDisplay_Add');
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_axes);
        value = block.InputPort(1).Data;
        namesofText = fieldnames(value);
        numberofFields = length(namesofText);
        colors = ['m' 'c' 'g' 'w' 'r'];
        for numCount = 1 : numberofFields
            if (value.(namesofText{numCount}))
                %                         axes(h_axes)
                h_text = findobj(0, 'tag',[namesofText{numCount} '_text']);
                if isempty(h_text)
                    numpoints = randi(3);
                    X_limits = xlim(h_axes);
                    Y_limits = ylim(h_axes);
                    Xcoord = (X_limits(1)+X_limits(2))./2+randn(1,numpoints).*(X_limits(2)-X_limits(1))/10;
                    Ycoord = (Y_limits(1)+Y_limits(2))./2+randn(1,numpoints).*(Y_limits(2)-Y_limits(1))/10;
                    for i = 1:numpoints
                        %                                 text(Xcoord(i),Ycoord(i),5,[num2str(Xcoord(i),'%.1f') ',' num2str(Ycoord(i),'%.1f')],'tag',[namesofText{numCount} '_text'],'color',colors(numCount));
                        text(Xcoord(i),Ycoord(i),5,num2str(i),'tag',[namesofText{numCount} '_text'],'color',colors(numCount));
                    end
                else
                    coord = get(h_text,'Position');
                    numpoints = size(coord,1);
                    if numpoints>1
                        coord = cell2mat(coord);
                    end
                    X_limits = xlim(h_axes);
                    Y_limits = ylim(h_axes);
                    Xcoord = coord(:,1)+randn(size(coord,1),1).*(X_limits(2)-X_limits(1))/75;
                    Ycoord = coord(:,2)+randn(size(coord,1),1).*(Y_limits(2)-Y_limits(1))/75;
                    for i = 1:numpoints
                        %                                 set(h_text(i),'Position',[Xcoord(i),Ycoord(i)],'string',[num2str(Xcoord(i),'%.1f') ',' num2str(Ycoord(i),'%.1f')],'tag',[namesofText{numCount} '_text'],'color',colors(numCount));
                        set(h_text(i),'Position',[Xcoord(i),Ycoord(i)],'string',num2str(i),'tag',[namesofText{numCount} '_text'],'color',colors(numCount));
                    end
                end
            else
                h_text = findobj(0, 'tag',[namesofText{numCount} '_text']);
                delete(h_text);
            end
        end
    case 'Out8' %PFD Display
        %%
        value = block.InputPort(1).Data;
        h_AirSpeed_ax = findobj(0, 'tag','AirSpeed');
        h_AirSpeed_text = findobj(0, 'tag','AirSpeed_text');
        if isempty(h_AirSpeed_text)
            h_AirSpeed_text = text(0.48,0.48,'','tag','AirSpeed_text','parent',h_AirSpeed_ax);
        end
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_AirSpeed_ax);
        %         axes(h_AirSpeed_ax)
        switch value.AirSpeedMode
            case -1
                set(h_AirSpeed_text,'String','...','Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
                %                 set(h_AirSpeed_ax,'Ytick',0:0.2:1);
            case 1
                YTick_ax = get(h_AirSpeed_ax,'YTick');
                if isempty(YTick_ax)||((value.AirSpeed - YTick_ax(1)) < 15)||((YTick_ax(end) - value.AirSpeed) < 15)
                    delete(h_AirSpeed_text)
                    YLim = [round(value.AirSpeed/10)*10-40 round(value.AirSpeed/10)*10+40];
                    numcurrenty_tick = (YLim(1):10:YLim(2))';
                    set(h_AirSpeed_ax,'Color',[70/256 130/256 180/256],'YLim',YLim,'ytickLabel','','ytick',numcurrenty_tick);
                    currenty_tick = num2str(numcurrenty_tick);
                    text(0.5*ones(length(numcurrenty_tick),1),numcurrenty_tick,currenty_tick,'Color',[1 1 1],'FontWeight','bold','Tag','AirSpeed_text','FontSize',7);
                end
                h_marker = findobj(h_AirSpeed_ax, 'tag','AirSpeed_marker');
                delete(h_marker);
                set(h_AirSpeed_ax,'NextPlot','add')
                plot(h_AirSpeed_ax,0.15,value.AirSpeed,'>r','markersize',9,'LineWidth',5,'tag','AirSpeed_marker')
                set(h_AirSpeed_ax,'XLim',[0 1],'YMinorTick','On');
            otherwise
                set(gca,'Ytick',[])
                h = findall(h_AirSpeed_ax);
                set(h,'Color',[0 0 0]);
        end
        h_Altitude_ax = findobj(0, 'tag','Altitude');
        h_Altitude_text = findobj(0, 'tag','Altitude_text');
        if isempty(h_Altitude_text)
            h_Altitude_text = text(0.48,0.48,'','tag','Altitude_text','parent',h_Altitude_ax);
        end
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_Altitude_ax);
        %         axes(h_Altitude_ax)
        switch value.AltMode
            case -1
                set(h_Altitude_text,'String','...','Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 1
                YTick_ax = get(h_Altitude_ax,'YTick');
                if isempty(YTick_ax)||((value.Altitude - YTick_ax(1)) < 50)||((YTick_ax(end) - value.Altitude) < 50)
                    delete(h_Altitude_text)
                    YLim = [round(value.Altitude/10)*10-100 round(value.Altitude/10)*10+100];
                    numcurrenty_tick = (YLim(1):20:YLim(2))';
                    set(h_Altitude_ax,'Color',[70/256 130/256 180/256],'YLim',YLim,'ytickLabel','','ytick',numcurrenty_tick);
                    currenty_tick = num2str(numcurrenty_tick);
                    text(0.3*ones(length(numcurrenty_tick),1),numcurrenty_tick,currenty_tick,'Color',[1 1 1],'FontWeight','bold', 'tag','Altitude_text','FontSize',7);
                end
                h_marker = findobj(h_Altitude_ax, 'tag','Altitude_marker');
                delete(h_marker);
                set(h_Altitude_ax,'NextPlot','add')
                plot(h_Altitude_ax,0.9,value.Altitude,'<r','markersize',9,'LineWidth',5,'tag','Altitude_marker');
                set(h_Altitude_ax,'Xlim',[0 1],'YMinorTick','On');
            otherwise
                set(gca,'Ytick',[])
                h = findall(h_Altitude_ax);
                set(h,'Color',[0 0 0]);
        end
        h_Attitude_ax = findobj(0, 'tag','Attitude');
        h_Attitude_text = findobj(0, 'tag','Attitude_text');
        if isempty(h_Attitude_text)
            h_fig = findall(0, 'tag','sfcockpitdisplay');
            h_Attitude_ax = findobj(0, 'tag','Attitude');
            set(h_fig,'CurrentAxes',h_Altitude_ax);
            h_Attitude_text = text(0.2,0.45,'','tag','Attitude_text','parent',h_Attitude_ax);
        end
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_Attitude_ax);
        switch value.AttMode
            case -1
                set(h_Attitude_text,'String','Display Starting...','Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 1
                h_patch = findobj(0,'Tag','PFDPatch');
                    delete(h_patch)
                    h_fig = findall(0, 'tag','sfcockpitdisplay');
                    set(h_fig,'CurrentAxes',h_Attitude_ax);
                    h = area([0.5-((value.Attitude/30)*0.5) 0.5+((value.Attitude/30)*0.5); 0.5-((value.Attitude/30)*0.5) 0.5+((value.Attitude/30)*0.5)],'tag','PFDPatch');
                    set(h(1),'FaceColor',[160/256 82/256 45/256]);
                    set(h(2),'FaceColor',[30/256 144/256 255/256]);
                    set(get(h(1),'parent'),'tag','Attitude', 'Yticklabel',[],'Xticklabel',[]);
                h_fig = findall(0, 'tag','sfcockpitdisplay');
                h_centerLines_ax = findall(0, 'tag','PFD_indicatorlines');
                set(h_fig,'CurrentAxes',h_centerLines_ax);
                h_centerLine = findobj(0,'tag','PFD_CenterLine');
                if isempty(h_centerLine)
                    for i = 1:7
                        line([0.1 0.9],[0.1 0.1]+(i*0.1),'color','white')
                        text(0,0.1+i*0.1,num2str(-30+(i-1)*10),'Color','white','FontSize',8,'FontWeight','bold','tag','PFD_CenterLine_tick');
                        text(0.9,0.1+i*0.1,num2str(-30+(i-1)*10),'Color','white','FontSize',8,'FontWeight','bold','tag','PFD_CenterLine_tick');
                    end
                    for i = 1:6
                        line([0.3 0.7],[0.15 0.15]+(i*0.1),'color','white')
                    end
                    line([0.5 0.5],[0.1 0.9],'Color','red','linewidth',5,'tag','PFD_CenterLine');
                    line([0.1 0.9],[0.5 0.5],'Color','red','linewidth',5);
                    set(h_centerLines_ax,'YLim',[0 1],'XLim',[0 1])
                end
                set(h_fig,'CurrentAxes',h_Attitude_ax);
            otherwise
                set(gca,'Ytick',[])
                h = findall(h_Attitude_ax);
                set(h,'Color',[0 0 0]);
        end
        h_Heading_ax = findobj(0, 'tag','Heading');
        h_Heading_text = findobj(0, 'tag','Heading_text');
        if isempty(h_Heading_text)
            h_Heading_text = text(0.48,0.48,'','tag','Heading_text','parent',h_Heading_ax);
        end
        h_fig = findall(0, 'tag','sfcockpitdisplay');
        set(h_fig,'CurrentAxes',h_Heading_ax);
        switch value.HeadingMode
            case -1
                set(h_Heading_text,'String','...','Color',[0 1 0],'FontSize',15,'FontWeight','Bold');
            case 1
                XTick_ax = get(h_Heading_ax,'XTick');
                if isempty(XTick_ax)||((value.Heading - XTick_ax(1)) < 3)||((XTick_ax(end) - value.Heading) < 3)
                    delete(h_Heading_text);
                    XLim = [round(value.HeadingMode/10)*10-5 round(value.HeadingMode/10)*10+5];
                    numcurrentx_tick = (XLim(1):XLim(2))';
                    set(h_Heading_ax,'Color',[70/256 130/256 180/256],'XLim',XLim,'xtickLabel','','xtick',numcurrentx_tick);
%                     numcurrentx_tick = num2str(numcurrentx_tick);
                    currentx_tick = num2str(numcurrentx_tick);
                    text(numcurrentx_tick-0.1,0.5*ones(length(numcurrentx_tick),1),currentx_tick,'Color',[1 1 1],'FontWeight','bold','Tag','Heading_text','FontSize',7);
                end
                h_marker = findobj(h_Heading_ax, 'tag','Heading_marker');
                delete(h_marker);
                set(h_Heading_ax,'NextPlot','add')
                plot(h_Heading_ax,value.Heading,0.15,'^r','markersize',9,'LineWidth',5,'tag','Heading_marker')
                set(h_Heading_ax,'YLim',[0 1],'XMinorTick','On');
            otherwise
                set(h_Heading_ax,'Xtick',[])
                h = findall(h_Heading_ax);
                set(h,'Color',[0 0 0]);
        end
end
end
function warning_struct = calcWarning(warn_msgID, FlightPhase)
%%
filename = [pwd '\data\Warnings_MsgID_Color_Priority_Phase.txt'];
Warnings_MsgID_Color_Priority_Phase = dlmread(filename,'\t',1,0);
Warnings_MsgID_Color_Priority_Phase(~(Warnings_MsgID_Color_Priority_Phase(:,3)==FlightPhase),:) = [];
temp_msgID = zeros(sum(warn_msgID~=0),1);
for i = 1 : sum(warn_msgID~=0)
    temp = find(Warnings_MsgID_Color_Priority_Phase(:,1)==warn_msgID(i));
    if ~isempty(temp)
        temp_msgID(i) = temp;
    end
end
temp_msgID = temp_msgID(temp_msgID~=0);
Warnings_MsgID_Color_Priority_Phase = Warnings_MsgID_Color_Priority_Phase(temp_msgID,:);
Warnings_MsgID_Color_Priority_Phase = sortrows(Warnings_MsgID_Color_Priority_Phase,5);
%% Message ID and text
filename = [pwd '\data\Warnings_MsgID_MsgTEXT.txt'];
fileID = fopen(filename,'r');
dataArray = textscan(fileID,'%f %s %[^\n\r]','HeaderLines',1, 'Delimiter', '\t', 'ReturnOnError', false);
fclose(fileID);
MsgID = dataArray{:, 1};
MsgTEXT = dataArray{:, 2};
clearvars filename delimiter startRow formatSpec fileID dataArray ans;
%% Color ID and text
filename = [pwd '\data\Warnings_ColorID_Color.txt'];
fileID = fopen(filename,'r');
dataArray = textscan(fileID, '%f%s%[^\n\r]', 'Delimiter', '\t', 'HeaderLines' ,1, 'ReturnOnError', false);
fclose(fileID);
ColorID = dataArray{:, 1};
Color = dataArray{:, 2};
clearvars filename delimiter startRow formatSpec fileID dataArray ans;
%% stitch the data together
text = char(zeros(size(Warnings_MsgID_Color_Priority_Phase,1),32));
color = char(zeros(size(Warnings_MsgID_Color_Priority_Phase,1),5));
display_id = zeros(size(Warnings_MsgID_Color_Priority_Phase,1),1);
for i = 1:size(Warnings_MsgID_Color_Priority_Phase,1)
    text(i,:) = MsgTEXT{MsgID==Warnings_MsgID_Color_Priority_Phase(i,1)};
    color(i,:) = Color{ColorID==Warnings_MsgID_Color_Priority_Phase(i,2)};
    display_id(i) = Warnings_MsgID_Color_Priority_Phase(i,4);
end
warning_struct.text = text(:,2:end-1);
warning_struct.color = color;
warning_struct.display_id = display_id;
end


