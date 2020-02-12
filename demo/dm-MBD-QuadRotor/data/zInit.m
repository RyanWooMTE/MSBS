function zpos = zInit(nompos,yaw,pitch,roll)

temp = nompos*angle2dcm(deg2rad(yaw),deg2rad(pitch),deg2rad(roll));

zpos = temp(3);
