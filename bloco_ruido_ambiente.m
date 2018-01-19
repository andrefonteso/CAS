%Ambient noise block

%Function Definition
function saida = bloco_ruido_ambiente(f, s, w, NtOff, NsOff, NwOff, NthOff, Mev)
% f - signal frequency (kHz); s - shipping factor (between 0 - 1);
% w - wind speed (m/s); NtOff, NsOff, NwOff, NthOff - Disable the
% corresponding equation;
% Mev - Manually entered value.

%Equation of Turbulence Noise
Nt = (10^((17-30*log10(f))/10))*NtOff;

%Equation of Shipping Noise
Ns = (10^((40+(20*(s-0.5))+(26*log10(f))-(60*log10(f+0.03)))/10))*NsOff;

%Equation of Wave Noise
Nw = (10^((50+(7.5*(w^(1/2)))+(20*log10(f))-(40*log10(f+0.4)))/10))*NwOff;

%Equation of Thermal Noise
Nth = (10^((-15+20*log10(f))/10))*NthOff;

%Total Noise
saida = Nt + Ns + Nw + Nth + Mev;

