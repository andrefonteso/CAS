%-------------------------------------------------------------------------
% Parameter values that influences the attenuation of underwater mean
%-------------------------------------------------------------------------
T = 32; % Temperature (C)
S = 1; % Salinity (ppt)
D = 1; % Depth (m)
pH = 7.2; % pH
f1 = 0.78 * sqrt(S/35) * (exp(T/26)); % Boric acid
f2 = 42 * (exp(T/17)); %Magnesium sulfate
%-------------------------------------------------------------------------
% Auxiliary variables
%-------------------------------------------------------------------------
f = 1:2:2000;
% Signal frequency(kHz)
% Transducer diameter calculus
%-------------------------------------------------------------------------
% Samples number for the graph
%-------------------------------------------------------------------------
a1 = zeros(1000);
a2 = zeros(1000);
a3 = zeros(1000);
a4 = zeros(1000);
%-------------------------------------------------------------------------
% Sound speed calcule on water (m/s)
%-------------------------------------------------------------------------
cmetro = 1448.96 + 4.591*T - 5.304*(10^(-2))*(T^(2)) + 2.374 *...
    (10^(-4))*(T^(3)) + 1.340*(S-35) + 1.630*(10^(-2))*D +...
    1.675*(10^(-7))*(D^(2)) - 1.025*(10^(-2))*T*(S-35) -...
    7.139*(10^(-13))*T*(D^(3));
%disp(’Sound speed (m/s):’); disp(c);
c=cmetro*100;
%-------------------------------------------------------------------------
% Cycle for the calculate of Coefficient of Absorption and attenuation
%-------------------------------------------------------------------------
for j = 1:1:1000;
    % Counter that represents the frequency (to simulate the behavior of
    % attenuation through several frequencies)
    % Absorption coefficient
    a1(j) = (((0.106 * (f1 * f(j)^2) *...
        exp((pH - 8)/0.56)) / (f1^2 + f(j)^2))/-10);
    a2(j) = (((0.52 * (1 + (T/43)) * (S/45) *...
        (f2 * f(j)^2) * exp(-(D/6))) / (f2^2 + f(j)^2))/-10);
    a3(j) = ((0.00049 *(f(j)^2) * (exp(-(T/27 + D/17))))/-10);
    % a4(j)=a1(j)+a2(j)+a3(j);
    a4(j)= 10^(a3(j)/10);
    % Attenuation (dB)
    %saida(j,i) = -10*log(((2*(angulo)*(l(i))^2)/(pi*r^2))+a(j));
end

%-------------------------------------------------------------------------
% Graphics
%-------------------------------------------------------------------------
figure(1);
plot(log10(f*1000),a1);
hold all
plot(log10(f*1000),a2);
hold all
plot(log10(f*1000),a3);
hold all
plot(log10(f*1000),a4);
xlabel('Frequency (MHz)')
ylabel('Magnitude (dB)')
title ('Plot of the four components of attenuation')
figure(2)
subplot(2,2,1); plot(log10(f*1000),a1);
xlabel('log(Frequency) (MHz)')
ylabel('Magnitude (dB)')
subplot(2,2,2); plot(log10(f*1000),a2);
xlabel('log(Frequency) (MHz)')
ylabel('Magnitude (dB)')
subplot(2,2,3); plot(log10(f*1000),a3);
xlabel('log(Frequency)(MHz)')
ylabel('Magnitude (dB)')
subplot(2,2,4); plot(log10(f*1000),a4);
xlabel('log(Frequency) (MHz)')
ylabel('Magnitude (dB)')
title ('Subplots of the four components of attenuation')