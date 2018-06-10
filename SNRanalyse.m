%Esse c�digo analisa a pot�ncia do sinal ac�stico antes de receber o ru�do 
%e a pot�ncia do sinal ac�stico depois de receber o ru�do.
%A fun��o SNR retorna a rela��o sinal-ru�do em decibeis do sinal 

%A rela��o sinal ru�do (Signal-to-Noise Ratio - SNR) do sistema de comunica��o
%retorna um valor em decib�is obtido atrav�s da raz�o da pot�ncia do sinal 
%ac�stico gerado pelo transdutor, x, calculando
%a raz�o de sua magnitude quadr�tica somada � do ru�do, y.

close all
 
t = 1:9000;
x = getdatasamples(semruido,[t]);  %valores no sinal sem ru�do
%plot(x)
s = getdatasamples(comruido,[t]);  %valores do sinal sem ru�do
%figure
%plot(s,'r')

SNR = snr(x,s-x)