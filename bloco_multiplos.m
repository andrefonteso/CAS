%Bloc echoes

%Function Definition
function [eco1,eco2,ag2,eco3,ag3,eco4,ag4,eco5,ag5,eco6,eco7,P] = bloco_multiplos(TX,TY,TZ,RX,RY,RZ,CX,CY,CZ)

% D1=sqrt( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
%
%
%% Rxc2 = [2*w-x2, y2, z2]
%
% D2=sqrt( ((2*w-x2)-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
%
%
%% Rxc3 = [-x2, y2, z2]
%
% D3=sqrt( (-x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
%
%
%% Rxc4 = [x2, y2, 2*D-z2]
%
% D4=sqrt( (x2-x1)^2 + (y2-y1)^2 + ((2*D-z2)-z1)^2 )
%
%
%% Rxc5 = [x2, y2, -z2]
%
% D5=sqrt( (x2-x1)^2 + (y2-y1)^2 + (-z2-z1)^2 )
%
% Case z1==z2, i.e. at the same level the echoes are the same
%
%% Rxc6 = [x2, -y2, z2]
%
% D4=sqrt( (x2-x1)^2 + (-y2-y1)^2 + (z2-z1)^2 )
%
%
%% Rxc7 = [x2, 2*L-y2, z2]
%
% D5=sqrt( (x2-x1)^2 + ((2*L-y2)-y1)^2 + (z2-z1)^2 )
%
%result signal

eco1 = sqrt((RX-TX)^2 + (RY-TY)^2 + (RZ-TZ)^2);

eco2 = sqrt( ((2*CX-RX)-TX)^2 + (RY-TY)^2 + (RZ-TZ)^2 );

ag2 = asin(abs((2*CX-RX)-TX)/eco2);

eco3 = sqrt( (-RX-TX)^2 + (RY-TY)^2 + (RZ-TZ)^2 );

ag3 = asin((RX+TX)/eco3);

eco4 = sqrt( (RX-TX)^2 + (RY-TY)^2 + ((2*CZ-RZ)-TZ)^2 );

ag4 = asin(abs((2*CZ-RZ)-TZ)/eco4);

eco5 = sqrt( (RX-TX)^2 + (RY-TY)^2 + (-RZ-TZ)^2 );

ag5 = asin((RZ+TZ)/eco5);

if((RZ==TZ) && (RX==TX))
    eco6 = (RY+TY);
    eco7 = sqrt(((2*CY-RY)-TY)^2);
else
    eco6 = 0;
    eco7 = 0;
end

P=(RZ+TZ)/2;