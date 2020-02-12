scrsz = get(0,'ScreenSize');
figure(iter);
set(gcf,'Position',[1 1 scrsz(3)*.75 scrsz(4)]);
clf;

% The DataSet elements are:
%     1: 'AirData'
%     2: 'AilCmd'
%     3: 'APeng'
%     4: 'HDGmode'
%     5: 'Inertial'
%     6: 'TurnKnob'
%     7: 'HDGref'
%     8: 'MaxAilPass'
%     9: 'RollResponsePass'
%     10: 'MaxRollPass'
%     11: 'MaxRollRatePass'
%     12: 'MaxRollRef'
%     13: 'MinRollRef'

% Get the signals for plotting
AilCmd = sigsOut.getElement('AilCmd');
AilCmd = AilCmd.Values.Data;
Inertial = sigsOut.getElement('Inertial');
Time = Inertial.Values.phi.time;
Phi = Inertial.Values.phi.data;
P = Inertial.Values.p.data;
TurnKnob = sigsOut.getElement('TurnKnob');
TurnKnob = TurnKnob.Values.Data;
MaxRollRef = sigsOut.getElement('MaxRollRef');
MaxRollRef = MaxRollRef.Values.Data;
MinRollRef = sigsOut.getElement('MinRollRef');
MinRollRef = MinRollRef.Values.Data;
MaxAil(1:length(Time)) = 15;
MinAil(1:length(Time)) = -15;
MaxRollRate(1:length(Time)) = 6.6;
MinRollRate(1:length(Time)) = -6.6;
MaxRoll(1:length(Time)) = 33;
MinRoll(1:length(Time)) = -33;

% Plot roll angle response and limits    
subplot(5,1,1,'align');
plot(Time,MaxRollRef,'r',Time,MinRollRef,'r',Time,Phi,'k');
hold on;
legend('Max Roll This Test','Min Roll This Test','Actual Roll','Location','EastOutside');
grid on;
xlabel('Time');
ylabel('Deg');

subplot(5,1,2,'align');
plot(Time,MaxRoll,'r',Time,MinRoll,'r',Time,Phi,'k');
hold on;
legend('Max Absolute Roll','Min Absolute Roll','Actual Roll','Location','EastOutside');
grid on;
xlabel('Time');
ylabel('Deg');

% Plot roll rate response and limits    
subplot(5,1,3,'align');
plot(Time,MaxRollRate,'r',Time,MinRollRate,'r',Time,P,'k');
hold on;
legend('Maximun Roll Rate','Minimum Roll Rate','Actual Roll Rate','Location','EastOutside');
grid on;
xlabel('Time');
ylabel('Deg/Sec');

% Plot aileron response and limits    
subplot(5,1,4,'align');
plot(Time,MaxAil,'r',Time,MinAil,'r',Time,AilCmd,'k');
hold on;
legend('Maximun Aileron','Minimum Aileron','Actual Aileron Cmd','Location','EastOutside');
grid on;
xlabel('Time');
ylabel('Deg');

% Plot Turn Knob    
subplot(5,1,5,'align');
plot(Time,TurnKnob,'k');
hold on;
legend('Turn   Knob   Cmd','Location','EastOutside');
grid on;
xlabel('Time');
ylabel('Deg');
