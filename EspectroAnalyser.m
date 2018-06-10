%Esse c�digo analisa ...

close all

t = 1:9000;
sinal_sem_ruido = getdatasamples(semruido,[t]);  %valores no sinal sem ru�do
sinal_com_ruido = getdatasamples(comruido,[t]);  %valores do sinal sem ru�do

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
title('Densidade Espectral de Pot�ncia do Sinal sem o Ru�do')
xlabel('Frequ�ncia (kHz)')
ylabel('Amplitude do Sinal sem Ru�do')

%S� ru�do
X = sinal_com_ruido - sinal_sem_ruido;

Yruido = fft(X);
P2 = abs(Yruido/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

subplot(3,1,2)
plot(f,P1,'k')
grid on;
title('Densidade Espectral de Pot�ncia do Ru�do')
xlabel('Frequ�ncia (kHz)')
ylabel('Amplitude do Ru�do')

% Sinal com ruido
Ycom = fft(sinal_com_ruido);
P2 = abs(Ycom/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

subplot(3,1,3)
plot(f,P1,'k') 
grid on;
title('Densidade Espectral de Pot�ncia do Sinal com o Ru�do')
xlabel('Frequ�ncia (kHz)')
ylabel('Amplitude do Sinal com Ru�do')

