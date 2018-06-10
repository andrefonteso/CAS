%Filtro FIR Passa banda;

close all
clc

t = 1:9000;
sinal_com_ruido = getdatasamples(comruido,[t]);  %valores do sinal sem ruído

L = size(t);
L = L(2);
Fs = 1/1000000;        % frequencia de amostragem
a = 10^9;
%f = a*Fs*(0:(L/2))/L;
f = (0:L-1)*(Fs/(L-1));

Ycom = fft(sinal_com_ruido);
P2 = abs(Ycom/L); 
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

b = fir1(10000,[0.0155 0.0235]);
[H, w] = freqz(b,1,L);
w = w*(Fs/(2*pi));

y = filter(b, 1, sinal_com_ruido);
Y = fft(y);
Y = Y/(L/2);
[H1, w1] = impz(b,1);

%Plotagem dos gráficos
subplot(3,2,1);
plot(f(1:L/2+1),abs(Ycom(1:L/2+1)),'b');
title('Resposta em frequência do sinal');
grid on;

subplot(3,2,2);
plot(w,(abs(H)),'r');
title('Resposta em frequência do filtro');
grid on;

subplot(3,2,3);
hold on
plot(f(1:L/2+1),abs(Ycom(1:L/2+1)),'b');
plot(w,(abs(H)),'r');
title('Resposta em frequência do sinal e do filtro');
grid on;
%hold off

subplot(3,2,4);
plot(w1,abs(H1));
title('Resposta ao impulso do filtro');
grid on;

subplot(3,2,5);
plot(f(1:L/2+1),abs(Y(1:L/2+1)));
title('Resposta em frequência do sinal filtrado');
grid on;