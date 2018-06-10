%A combina��o de sinais em dB se forma sempre com base em sua pot�ncia ou
%energia. Se voc� tem uma caixa cuja sensibilidade � de 103 dB SPL e outra
%com sensibilidade de 100 dB SPL isto significa que a primeira � capaz de
%gerar 3 dB a mais de pot�ncia ac�stica, ou o dobro, que a segunda, j� que a
%pot�ncia el�trica aplicada a ambas foi a mesma: 1 W e medimos o SPL � mesma dist�ncia: 1m.

%Para somarmos os sinais de duas fontes devemos considerar suas rela��es de fase.
%Onde:
%Lt = n�vel total em dB
%L1 = n�vel em dB do sinal 1
%L2 = n�vel em dB do sinal 2
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

%Para sinais sem nenhuma correla��o, tais como fontes de ru�do independentes,
%somam-se as pot�ncias de ambos os sinais:
Lt = 10*log10(10^(L1/10) + 10^(L2/10))

%Para dois sinais senoidais com uma rela��o de fase conhecida teremos:
Lt_2 = 10*log10(10^(L1/10) + 10^(L2/10) + 2*(10^(L1/20)*10^(L2/20))*cos(a1-a2));