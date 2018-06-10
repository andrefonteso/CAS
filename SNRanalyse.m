%Esse código analisa a potência do sinal acústico antes de receber o ruído 
%e a potência do sinal acústico depois de receber o ruído.
%A função SNR retorna a relação sinal-ruído em decibeis do sinal 

%A relação sinal ruído (Signal-to-Noise Ratio - SNR) do sistema de comunicação
%retorna um valor em decibéis obtido através da razão da potência do sinal 
%acústico gerado pelo transdutor, x, calculando
%a razão de sua magnitude quadrática somada à do ruído, y.

close all
 
t = 1:9000;
x = getdatasamples(semruido,[t]);  %valores no sinal sem ruído
%plot(x)
s = getdatasamples(comruido,[t]);  %valores do sinal sem ruído
%figure
%plot(s,'r')

SNR = snr(x,s-x)