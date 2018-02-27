clear all
close all
clc

% f - signal frequency (kHz); 
f = 10:0.5:20;
%s - shipping factor (between 0 - 1);
s = 1;
% w - wind speed (m/s); NtOff, NsOff, NwOff, NthOff - Disable the
w = 10;
% corresponding equation;
% Mev - Manually entered value.

%Equation of Turbulence Noise
Nt = (10.^((17-30*log10(f))/10));

%Equation of Shipping Noise
Ns = (10.^((40+(20*(s-0.5))+(26*log10(f))-(60*log10(f+0.03)))/10));

%Equation of Wave Noise
Nw = (10.^((50+(7.5*(w^(1/2)))+(20*log10(f))-(40*log10(f+0.4)))/10));

%Equation of Thermal Noise
Nth = (10.^((-15+20*log10(f))/10));

%Total Noise

ruido_total = 1:length(f);
for i = 1:length(f)
ruido_total(i) = Nt(i) + Ns(i) + Nw(i) + Nth(i);
end

%sinal_ruidoso = awgn(sinal,ruido_total);

subplot(2,4,1); stem(f,Nt);
subplot(2,4,2); stem(f,Ns);
subplot(2,4,3); stem(f,Nw);
subplot(2,4,4); stem(f,Nth);
subplot(2,4,5); stem(f,ruido_total);