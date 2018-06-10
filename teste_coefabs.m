close all; clear all; clc;
frequencia = 0:100:100000;

% Par�metros Ambientais
T = 25;                             % Temperatura da �gua
S = 35;                             % Salinidade da �gua do mar do litoral brasileiro (1 milligram/liter [mg/L] = 1,000000002 part/million [ppm])
pH = 7.8;                           % Acidez da �gua

% Par�metro da Geometria do Aqu�rio
D = 3;          % Profundidade em m

%Valores dos par�metros Para o primeiro Coeficiente de Absor��o(alfa)  
f1 = 0.78 * sqrt(S/35) * (exp(T/26));    % �cido B�rico
f2 = 42 * (exp(T/17));                   % Sulfato de Magn�sio

%--------------------------------------------------------------------------
% Coeficiente de Absor��o(alfa). Escolher o tipo de express�o que depende 
% diretamente da frequencia do sinal.
%--------------------------------------------------------------------------

alfa = ((0.106 * (f1 * frequencia.^2) * exp((pH - 8) / 0.56)) / ...
    (f1^2 + frequencia.^2)) + ((0.52 * (1 + (T / 43)) * (S / 35) * ...
    (f2 * frequencia.^2) * exp(-(D / 6))) / (f2^2 + frequencia.^2)) + ...
    (0.00049 * (frequencia.^2) * (exp(-(T/27 + D/17))));

a = 10*log10(alfa);

plot(frequencia,a);