x1=[0:9];
x2=[10:2.5:17.5];
x3=[20:5:80];
D=[x1,x2,x3];

% %Compare the EMS effect on each tech
% zigbee_out=xlsread('dataTemp','sheet2','C5:D31');
% wifi_out=xlsread('dataTemp','sheet1','K8:L80');
% ble_out=xlsread('dataTemp','sheet1','F8:G34');
% 
% figure(1)
% plot(D,ble_out,'*-');
% title('RSSI of Bluetooth with/without EMS vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Without EMS effect','With EMS effect');
% 
% figure(2)
% plot(D,zigbee_out,'*-');
% title('RSSI of Xbee with/without EMS vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Without EMS effect','With EMS effect');
% 
% figure(3)
% plot(D,wifi_out,'*-');
% title('RSSI of ESP8266 with/without EMS vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Without EMS effect','With EMS effect');
% 
% %Compare three tech. indoor and outdoor without EMS effect
% nEMS_out=xlsread('dataTemp','sheet1','S8:U34');
% nEMS_in=xlsread('dataTemp','sheet1','O8:Q34');
% % 
% figure(4)
% plot(D,nEMS_out,'*-');
% title('Outdoor RSSI of three technologies vs. Distance from transmitter ')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('BLE','WIFI','Xbee');
% 
% figure(5)
% plot(D,nEMS_in,'*-');
% title('Indoor RSSI of three technologies vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('BLE','WIFI','Xbee');

%Compare the in/outdoor effect on each tech
ble_out_nems=xlsread('dataTemp','sheet1','X8:Y34');
wifi_out_nems=xlsread('dataTemp','sheet1','Z8:AA34');
zigbee_out_nems=xlsread('dataTemp','sheet1','AB8:AC34');

% figure(6)
% plot(D,ble_out_nems,'*-');
% title('RSSI of Bluetooth in/outdoor vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Indoor','Outdoor');
% 
% figure(7)
% plot(D,zigbee_out_nems,'*-');
% title('RSSI of Xbee in/outdoor vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Indoor','Outdoor');
% 
% figure(8)
% plot(D,wifi_out_nems,'*-');
% title('RSSI of ESP8266 in/outdoor vs. Distance from transmitter')
% xlabel('Distance from transmitter (m) ')
% ylabel('RSSI (dBm)')
% legend('Indoor','Outdoor');

%Path Loss Model
plc=2;%Path loss component
d1=1;
d2=D;
p_xbee_1=zigbee_out_nems(2);
p_xbee_2=p_xbee_1-10*plc*log10(d2/d1);

p_wifi_1=wifi_out_nems(2);
p_wifi_2=p_wifi_1-10*plc*log10(d2/d1);

p_ble_1=ble_out_nems(2);
p_ble_2=p_ble_1-10*plc*log10(d2/d1);

plot(D,p_wifi_2)
title('Mathematical diagram of path loss model');
xlabel('Distance of measured points');
ylabel('RSSI(dBm)')