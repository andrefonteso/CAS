%% Estudo da Análise dos Ruídos Ambientais
% Esse estudo realiza uma análise das equações existentes na literatura
% que descrevem os tipos de ruidos existentes no ambiente subaquático. 
% São eles, o ruído de turbulências, o ruido de navegações, o ruído das 
% ondas e o ruído térmico. Para representar o ruído total desse ambiente é 
% somado todos estes ruídos.

clear all;
close all;
clc;

% f - signal frequency (kHz); 
f = 10:.5:20;
% s - shipping factor (between 0 - 1);
s = 0;
% w - wind speed (m/s); 
w = 20;

%Ruido de Turbulências
Nt = (10.^((17-30*log10(f))/10));

%Ruido de Nevegações
Ns = (10.^((40+(20*(s-0.5))+(26*log10(f))-(60*log10(f+0.03)))/10));

%Ruido das Ondas
Nw = (10.^((50+(7.5*(w^(1/2)))+(20*log10(f))-(40*log10(f+0.4)))/10));

%Ruído Térmico 
Nth = (10.^((-15+20*log10(f))/10));

%Ruído Total
ruido_total = 1:length(f);
for i = 1:length(f)
ruido_total(i) = Nt(i) + Ns(i) + Nw(i) + Nth(i);
end

subplot(2,4,1); stem(f,Nt);
subplot(2,4,2); stem(f,Ns);
subplot(2,4,3); stem(f,Nw);
subplot(2,4,4); stem(f,Nth);
subplot(2,4,5); stem(f,ruido_total);

%sinal_ruidoso = awgn(sinal,ruido_total);