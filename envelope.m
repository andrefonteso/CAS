%Esse código analisa ...

close all

t = 1:9000;
sinal_com_ruido = getdatasamples(comruido,[t]);  %valores do sinal sem ruído

%plot(sinal_sem_ruido);
%figure
%plot(sinal_com_ruido);
%SNR = snr(x,s-x);   

L = size(t);
L = L(2);
Fs = 1/1000000;         % frequencia de amostragem
a = 10^9;
f = a*Fs*(0:(L/2))/L;

figure
plot(sinal_com_ruido)

y = hilbert(sinal_com_ruido);
env = abs(y);

for i=1:size(env)
    if(env(i)>1)
        a(i) = 1;
    end
    if(env(i)<1)
        a(i) = 0;
    end
end

plot_param = {'Color', 'red','Linewidth',2}; 
hold on
plot(t,env,plot_param{:})
hold off

figure
plot(a)
ylim([0 1.3])