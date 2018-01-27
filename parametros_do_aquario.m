% considera�oes para os par�metros do aqu�rio
% 1. emissor e receptor est�o alinhados ( largura(x) e profundidade(z)
% iguais, s� muda o comprimento (y)
% 2. o comprimento do aquario (L) � ideal para acontecer uma reflex�o completa
% com o angulo de diretividade (que � o maior angulo poss�vel do l�bulo 
% principal utilizando o transdutor piezoeletrico escolhido)
% 3. para facilitar os c�lculos de do comprimento ideal, utilizamos largura
% igual profundidade (D = W)

% considera��es sobre a simula��o
% 1. ser�o considerados somente os caminhos do angulo de diretividade e o
% caminho direto (5 caminhos: um direto, dois que refletem nas laterais, e
% dois que refletem na superf�cie e o fundo
% 2. a reflex�o ser� considerada reflex�o completa com um eco (sem perdas 
% de energia ou refra�ao)

%-------------------------------------------------------------------------
% �ngulo de diretividade do transdutor calculado no COMSOL (rad)
%-------------------------------------------------------------------------
teta = pi/3;            % (ex.: 60� = pi/3 rad)

%-------------------------------------------------------------------------
%Par�metros do Aqu�rio definidos anteriormente
%-------------------------------------------------------------------------
w = 3;                  % largura 
d = w;                  % profundidade do aqu�rio 
l = w/sin(teta/2);      % comprimento do aqu�rio
% l(�le) � a distancia ideal para acontecer uma reflex�o completa


%%%%%%  Bloco multipath  %%%%%%

%-------------------------------------------------------------------------
%Definindo as dist�ncias de cada caminho do multipath
%-------------------------------------------------------------------------
% Caminho_1 = Caminho refletido na superf�cie
% Caminho_2 = Caminho refletido na lateral de tr�s
% Caminho_3 = Caminho direto
% Caminho_4 = Caminho refletido na lateral da frente
% Caminho_5 = Caminho refletido no fundo

Caminho_1 = sqrt(d^2 + l^2);
Caminho_2 = sqrt(w^2 + l^2);
Caminho_3 = l;
Caminho_4 = Caminho_1;
Caminho_5 = Caminho_2;

%-------------------------------------------------------------------------
% Valores dos par�metros do meio subaqu�tico 
%-------------------------------------------------------------------------
T = 32;                 % Temperatura (�C)
S = 1;                  % Salinidade (ppt)
dmax = d;
dmin = ;
D = mean(dmax,dmin);    % Profundidade (m)
pH = 7.2;               % acid�z da �gua - pH (potencial hidrogeni�nico) 

%-------------------------------------------------------------------------
%Velocidade do som na �gua (m/s)
%-------------------------------------------------------------------------
c = 1448.96 + 4.591*T - 5.304*(10^(-2))*(T^(2))...
    + 2.374*(10^(-4))*(T^(3)) + 1.340*(S-35) + 1.630*(10^(-2))*D...
    + 1.675*(10^(-7))*(D^(2)) - 1.025*(10^(-2))*T*(S-35)...
    - 7.139*(10^(-13))*T*(D^(3));

%Convers�o de (m/s) para (cm/s)
C=c*100;

%-------------------------------------------------------------------------
% Frequ�ncia do Sinal (kHz)
%-------------------------------------------------------------------------
f = 1:2:2000; 
lambda = C/(f*1000);    % comprimento de onda 

%-------------------------------------------------------------------------
% Definindo os atrasos de cada caminho do multipath atrav�s da equa��o de
% velocidade de propaga��o do som na �gua
%-------------------------------------------------------------------------
