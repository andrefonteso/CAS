%Bloc attenuation

%Function Definition
function [sg1,at1,sg2,at2,sg3,at3,sg4,at4,sg5,at5,sg6,at6,sg7,at7, agT] = bloco_atenuacao(f,L1,L2,ag2,L3,ag3,L4,ag4,L5,ag5,L6,L7, T,D, S, pH, rr, r, sps)

%Parameter Values (Boric Acid and Magnesium Sulphate)
f1 = 0.78 * sqrt(S/35) * (exp(T/26));
f2 = 42 * (exp(T/17));

%Speed of sound (m/s)
cmetro = 1448.96 + 4.591*T - 5.304*(10^(-2))*(T^(2)) +...
    + 2.374*(10^(-4))*(T^(3))...
    + 1.340*(S-35) + 1.630*(10^(-2))*D + 1.675*(10^(-7))*(D^(2)) +...
    - 1.025*(10^(-2))*T*(S-35) - 7.139*(10^(-13))*T*(D^(3));

%Conversion from m/s to cm/s
c=cmetro*100;

%Calculation of wavelength
lambda = c/(f*1000);

%Calculation of the transducer diameter
angulo = 0;
d = 2*r;
de = (pi*rr^2);

%Absorption Coefficient
a = ((0.106 * (f1 * f^2) * exp((pH - 8)/0.56)) / (f1^2 + f^2)) +...
    ((0.52 * (1 + (T/43)) * (S/45) * (f2 * f^2) *...
    exp(-(D/6))) / (f2^2 + f^2)) + (0.00049 * (f^2) * (exp(-(T/27 + D/17))));

%Attenuation
ab1 = a*(L1/1e5);

ab2 = a*(L2/1e5);

ab3 = a*(L3/1e5);

ab4 = a*(L4/1e5);

ab5 = a*(L5/1e5);

ab6 = a*(L6/1e5);

ab7 = a*(L7/1e5);

if  r < lambda;
    angulo = pi/2;
end
if  r > lambda;
    angulo = asin(lambda/d);
end

sp1 = 10*log10(((2*angulo*(L1)^2) + de)/de);
sp2 = 10*log10(((2*angulo*(L2)^2) + de)/de);
sp3 = 10*log10(((2*angulo*(L3)^2) + de)/de);
sp4 = 10*log10(((2*angulo*(L4)^2) + de)/de);
sp5 = 10*log10(((2*angulo*(L5)^2) + de)/de);
sp6 = 10*log10(((2*angulo*(L6)^2) + de)/de);
sp7 = 10*log10(((2*angulo*(L7)^2) + de)/de);

sg1 = 0;
sg2 = 0;
sg3 = 0;
sg4 = 0;
sg5 = 0;
sg6 = 0;
sg7 = 0;

at1=0;
at2=0;
at3=0;
at4=0;
at5=0;
at6=0;
at7=0;

sg1= 10^((-1*(ab1 + sp1))/10);
at1= ((L1/c)*sps);

%if(ag2<=angulo)
sg2= 10^((-1*(ab2 + sp2))/10);
at2= ((L2/c)*sps)-at1;
%end
%if(ag3<=angulo)
sg3 = 10^((-1*(ab3 + sp3))/10);
at3= ((L3/c)*sps)-at1;
%end
%if(ag4<=angulo)
sg4 = 10^((-1*(ab4 + sp4))/10);
at4= ((L4/c)*sps)-at1;
%end
%if(ag5<=angulo)
sg5 = 10^((-1*(ab5 + sp5))/10);
at5= ((L5/c)*sps)-at1;
%end
if (L6>0)
    sg6 = 10^((-1*(ab6 + sp6))/10);
    at6= ((L6/c)*sps)-at1;
end
if (L7>0)
    sg7 = 10^((-1*(ab7 + sp7))/10);
    at7= ((L7/c)*sps)-at1;
end

at1=at1/sps;
agT=angulo;