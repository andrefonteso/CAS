%% Estudo dos �ngulos Gerados pelo Transdutor Piezoel�trico
% Este estudo realciona o �ngulo de diretividade e os par�metros da 
% geometria do aqu�rio. Estes �ngulos foram obtidos atrav�s do gr�fico 
% polar do diagrama de radia��o obtidos no COMSOL. O objetivo desse estudo
% � encontrar o comprimento (L) e a profundidade (D) ideal da geometria do 
% aqu�rio no qual ser� realizado a simula��o.

clear all;
close all;
clc;

%-------------------------------------------------------------------------
%Exporta��o dos valores do grafico do padr�o de radia��o do transdutor
%gerado no COMSOL
%-------------------------------------------------------------------------
filed = fopen('C:\Users\andre\Desktop\padr�o de radia��o\angulos_padrao.txt');
inputText = textscan(filed,'%.2f',35,'Delimiter','\n');
angulos = inputText{1};
fclose(filed);

%-------------------------------------------------------------------------
% Inicializando os vetores dos par�metros da geometria do aqu�rio
%-------------------------------------------------------------------------
D = 1:.1:20;     % d � produnfidade do aqu�rio (dire��o z)
L = 1:.1:20;     % L � o comprimento do aqu�rio (dire��o y)

%-------------------------------------------------------------------------
%Estudo comparativo do �ngulo alfa, o comprimento e a profundidade
%todos os �ngulos poss�veis sem considerar os �ngulos do padr�o de radia��o
%-------------------------------------------------------------------------
theta = zeros(length(D),length(D)); %matriz de zeros 
for i = 1:length(D)
    for j = 1:length(D)
        theta(i,j) = radtodeg(atan(D(i)/L(j)));
    end
end

figure;
mesh(D,L,theta, 'EdgeColor','none');
shading interp;
title ('Estudo do Theta, L e D');
xlabel('Profundidade(m)');
ylabel('Comprimento(m)');
zlabel('�ngulo (graus)');

%-------------------------------------------------------------------------
%Fixando a profundidade D e encontrando o �ngulo de reflex�o Alfa ideal
%-------------------------------------------------------------------------
theta1 = zeros(length(L),1);
for i = 1:length(L)
    theta1(i) = radtodeg(atan(10/L(i)));
end

figure(2);
plot(L,theta1);
grid on;
xlabel('Comprimento(m)');
ylabel('�ngulo (graus)');
hold on;

%-------------------------------------------------------------------------
% Encontrando o comprimento (L) ideal para a geometria do aqu�rio
%-------------------------------------------------------------------------
pontos = zeros(10,2);
i_pontos = 1;

for i = 1:length(L)
    for j = 1:length(angulos)
        if (angulos(j)>=0 && abs(angulos(j) - theta1(i)) < 0.3)
            plot(L(i),theta1(i),'r*');
            pontos(i_pontos,1) = theta1(i);
            pontos(i_pontos,2) = L(i);
            i_pontos = i_pontos + 1;
        end
    end
end