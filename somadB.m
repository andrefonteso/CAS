%A combinação de sinais em dB se forma sempre com base em sua potência ou
%energia. Se você tem uma caixa cuja sensibilidade é de 103 dB SPL e outra
%com sensibilidade de 100 dB SPL isto significa que a primeira é capaz de
%gerar 3 dB a mais de potência acústica, ou o dobro, que a segunda, já que a
%potência elétrica aplicada a ambas foi a mesma: 1 W e medimos o SPL à mesma distância: 1m.

%Para somarmos os sinais de duas fontes devemos considerar suas relações de fase.
%Onde:
%Lt = nível total em dB
%L1 = nível em dB do sinal 1
%L2 = nível em dB do sinal 2
%a1 = fase do sinal 1
%a2 = fase do sinal 2

clear all;
close all;
clc;;
%caminho3
L1=7.7815;
L2=0.0173;
%caminho4
% L1=8.2661;
% L2=0.0194;    
a1=1;
a2=1;

%Para sinais sem nenhuma correlação, tais como fontes de ruído independentes,
%somam-se as potências de ambos os sinais:
Lt = 10*log10(10^(L1/10) + 10^(L2/10))

%Para dois sinais senoidais com uma relação de fase conhecida teremos:
Lt_2 = 10*log10(10^(L1/10) + 10^(L2/10) + 2*(10^(L1/20)*10^(L2/20))*cos(a1-a2));