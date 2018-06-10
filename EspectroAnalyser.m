%Esse código analisa ...

close all

t = 1:9000;
sinal_sem_ruido = getdatasamples(semruido,[t]);  %valores no sinal sem ruído
sinal_com_ruido = getdatasamples(comruido,[t]);  %valores do sinal sem ruído

%plot(sinal_sem_ruido);
%figure
%plot(sinal_com_ruido);
%SNR = snr(x,s-x);   

L = size(t);
L = L(2);
Fs = 1/1000000;        % frequencia de amostragem
a = 10^9;
f = a*Fs*(0:(L/2))/L;

% Sinal sem ruido
Ysem = fft(sinal_sem_ruido);
P2 = abs((Ysem)/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

figure; 
subplot(3,1,1) 
plot(f,P1,'k')
grid on;
title('Densidade Espectral de Potência do Sinal sem o Ruído')
xlabel('Frequência (kHz)')
ylabel('Amplitude do Sinal sem Ruído')

%Só ruído
X = sinal_com_ruido - sinal_sem_ruido;

Yruido = fft(X);
P2 = abs(Yruido/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

subplot(3,1,2)
plot(f,P1,'k')
grid on;
title('Densidade Espectral de Potência do Ruído')
xlabel('Frequência (kHz)')
ylabel('Amplitude do Ruído')

% Sinal com ruido
Ycom = fft(sinal_com_ruido);
P2 = abs(Ycom/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

subplot(3,1,3)
plot(f,P1,'k') 
grid on;
title('Densidade Espectral de Potência do Sinal com o Ruído')
xlabel('Frequência (kHz)')
ylabel('Amplitude do Sinal com Ruído')

