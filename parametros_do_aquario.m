% consideraçoes para os parâmetros do aquário
% 1. emissor e receptor estão alinhados ( largura(x) e profundidade(z)
% iguais, só muda o comprimento (y)
% 2. o comprimento do aquario (L) é ideal para acontecer uma reflexão completa
% com o angulo de diretividade (que é o maior angulo possível do lóbulo 
% principal utilizando o transdutor piezoeletrico escolhido)
% 3. para facilitar os cálculos de do comprimento ideal, utilizamos largura
% igual profundidade (D = W)

% considerações sobre a simulação
% 1. serão considerados somente os caminhos do angulo de diretividade e o
% caminho direto (5 caminhos: um direto, dois que refletem nas laterais, e
% dois que refletem na superfície e o fundo
% 2. a reflexão será considerada reflexão completa com um eco (sem perdas 
% de energia ou refraçao)

%-------------------------------------------------------------------------
% Ângulo de diretividade do transdutor calculado no COMSOL (rad)
%-------------------------------------------------------------------------
teta = pi/3;            % (ex.: 60º = pi/3 rad)

%-------------------------------------------------------------------------
%Parâmetros do Aquário definidos anteriormente
%-------------------------------------------------------------------------
w = 3;                  % largura 
d = w;                  % profundidade do aquário 
l = w/sin(teta/2);      % comprimento do aquário
% l(éle) é a distancia ideal para acontecer uma reflexão completa


%%%%%%  Bloco multipath  %%%%%%

%-------------------------------------------------------------------------
%Definindo as distâncias de cada caminho do multipath
%-------------------------------------------------------------------------
% Caminho_1 = Caminho refletido na superfície
% Caminho_2 = Caminho refletido na lateral de trás
% Caminho_3 = Caminho direto
% Caminho_4 = Caminho refletido na lateral da frente
% Caminho_5 = Caminho refletido no fundo

Caminho_1 = sqrt(d^2 + l^2);
Caminho_2 = sqrt(w^2 + l^2);
Caminho_3 = l;
Caminho_4 = Caminho_1;
Caminho_5 = Caminho_2;

%-------------------------------------------------------------------------
% Valores dos parâmetros do meio subaquático 
%-------------------------------------------------------------------------
T = 32;                 % Temperatura (°C)
S = 1;                  % Salinidade (ppt)
dmax = d;
dmin = ;
D = mean(dmax,dmin);    % Profundidade (m)
pH = 7.2;               % acidêz da água - pH (potencial hidrogeniônico) 

%-------------------------------------------------------------------------
%Velocidade do som na água (m/s)
%-------------------------------------------------------------------------
c = 1448.96 + 4.591*T - 5.304*(10^(-2))*(T^(2))...
    + 2.374*(10^(-4))*(T^(3)) + 1.340*(S-35) + 1.630*(10^(-2))*D...
    + 1.675*(10^(-7))*(D^(2)) - 1.025*(10^(-2))*T*(S-35)...
    - 7.139*(10^(-13))*T*(D^(3));

%Conversão de (m/s) para (cm/s)
C=c*100;

%-------------------------------------------------------------------------
% Frequência do Sinal (kHz)
%-------------------------------------------------------------------------
f = 1:2:2000; 
lambda = C/(f*1000);    % comprimento de onda 

%-------------------------------------------------------------------------
% Definindo os atrasos de cada caminho do multipath através da equação de
% velocidade de propagação do som na água
%-------------------------------------------------------------------------
