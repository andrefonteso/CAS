%% Escrito por Andr� Fontes de Oliveira em 2018 
% C�digos de simula��o do MatLab/Simulink de blocos do Simulink para 
% Disserta��o de Mestrado.
% "MODELO DE SIMULA��O PARA UM CANAL DE COMUNICA��O AC�STICO SUBAQU�TICO
% COM TRANSDUTORES PIEZOEL�TRICOS"
% Mestrado em Engenharia de Telecomunica��es
% Programa de P�s-Gradua��o em Engenharia de Telecomunica��es - PPGET
% Instituto Federal de Educa��o Ci�ncia e Tecnologia do Cear� - IFCE
% Orienta��o do Prof. Dr. Francisco Jos� Alves de Aquino 
%--------------------------------------------------------------------------
% Estudo da An�lise dos Ru�dos Ambientais
% Esse estudo realiza uma an�lise das equa��es existentes na literatura
% que descrevem os tipos de ruidos existentes no ambiente subaqu�tico. 
% S�o eles, o ru�do de turbul�ncias, o ruido de navega��es, o ru�do das 
% ondas e o ru�do t�rmico. Para representar o ru�do total desse ambiente s�o 
% somados todos estes ru�dos.
%%
clear all;
close all;
clc;

% f - signal frequency (kHz); 
f = 10000:1000:20000;
% s - shipping factor (between 0 - 1);
s = 0;
% w - wind speed (m/s); 
w = 15;

%Ruido de Turbul�ncias
Nt = (10.^((17-30*log10(f))/10));

%Ruido de Nevega��es
Ns = (10.^((40+(20*(s-0.5))+(26*log10(f))-(60*log10(f+0.03)))/10));

%Ruido das Ondas
Nw = (10.^((50+(7.5*(w^(1/2)))+(20*log10(f))-(40*log10(f+0.4)))/10));

%Ru�do T�rmico 
Nth = (10.^((-15+20*log10(f))/10));

%Ru�do Total
ruido_total = 1:length(f);
for i = 1:length(f)
ruido_total(i) = Nt(i) + Ns(i) + Nw(i) + Nth(i);
end

subplot(2,4,1); stem(f,Nt);
subplot(2,4,2); stem(f,Ns);
subplot(2,4,3); stem(f,Nw);
subplot(2,4,4); stem(f,Nth);
subplot(2,4,5); stem(f,ruido_total);