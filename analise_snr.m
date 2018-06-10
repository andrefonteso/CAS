%% Escrito por Andr� Fontes de Oliveira em 2018 
% C�digos de simula��o do MatLab/Simulink de blocos do Simulink para 
% Disserta��o de Mestrado.
% "MODELO DE SIMULA��O PARA UM CANAL DE COMUNICA��O AC�STICO SUBAQU�TICO
% COM TRANSDUTORES PIEZOEL�TRICOS"
% Mestrado em Engenharia de Telecomunica��es
% Programa de P�s-Gradua��o em Engenharia de Telecomunica��es - PPGET
% Instituto Federal de Educa��o Ci�ncia e Tecnologia do Cear� - IFCE
% Orienta��o do Prof. Dr. Francisco Jos� Alves de Aquino 
%-----------------------------------------------------------------------
% Esse c�digo analisa a pot�ncia do sinal ac�stico antes de receber o ru�do 
% e a pot�ncia do sinal ac�stico depois de receber o ru�do presente no 
% canal de comunica��o do arquivo sistema_cas_oficial.slx.
% A fun��o SNR retorna a rela��o sinal-ru�do em decibeis do sinal 
% A rela��o sinal ru�do (Signal-to-Noise Ratio - SNR) do sistema de comunica��o
% retorna um valor em decib�is obtido atrav�s da raz�o da pot�ncia do sinal 
% ac�stico gerado pelo transdutor, x, calculando a raz�o de sua magnitude 
% quadr�tica somada � do ru�do, y.
%%
close all
 
t = 1:9000;
x = getdatasamples(semruido,[t]);  %valores no sinal sem ru�do
%plot(x)
s = getdatasamples(comruido,[t]);  %valores do sinal sem ru�do
%figure
%plot(s,'r')

SNR = snr(x,s-x);