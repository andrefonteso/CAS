%% Estudo dos Ângulos Gerados pelo Transdutor Piezoelétrico
% Este estudo realciona o ângulo de diretividade e os parâmetros da 
% geometria do aquário. Estes ângulos foram obtidos através do gráfico 
% polar do diagrama de radiação obtidos no COMSOL. O objetivo desse estudo
% é encontrar o comprimento (L) e a profundidade (D) ideal da geometria do 
% aquário no qual será realizado a simulação.

clear all;
close all;
clc;

%-------------------------------------------------------------------------
%Exportação dos valores do grafico do padrão de radiação do transdutor
%gerado no COMSOL
%-------------------------------------------------------------------------
filed = fopen('C:\Users\andre\Desktop\padrão de radiação\angulos_padrao.txt');
inputText = textscan(filed,'%.2f',35,'Delimiter','\n');
angulos = inputText{1};
fclose(filed);

%-------------------------------------------------------------------------
% Inicializando os vetores dos parâmetros da geometria do aquário
%-------------------------------------------------------------------------
D = 1:.1:20;     % d é produnfidade do aquário (direção z)
L = 1:.1:20;     % L é o comprimento do aquário (direção y)

%-------------------------------------------------------------------------
%Estudo comparativo do ângulo alfa, o comprimento e a profundidade
%todos os ângulos possíveis sem considerar os ângulos do padrão de radiação
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
zlabel('Ângulo (graus)');

%-------------------------------------------------------------------------
%Fixando a profundidade D e encontrando o ângulo de reflexão Alfa ideal
%-------------------------------------------------------------------------
theta1 = zeros(length(L),1);
for i = 1:length(L)
    theta1(i) = radtodeg(atan(10/L(i)));
end

figure(2);
plot(L,theta1);
grid on;
xlabel('Comprimento(m)');
ylabel('Ângulo (graus)');
hold on;

%-------------------------------------------------------------------------
% Encontrando o comprimento (L) ideal para a geometria do aquário
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