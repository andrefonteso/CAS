%Signal noisy block

%Function Definition
function saida = bloco_sinal_ruido(sinal)

saida=sinal;
    r1 = randn(1)/12;
    r2 = randn(1)/6.8;
    r3 = randn(1)/136;
    r4 = randn(1)/3;
    r5 = randn(1)/56;
    r6 = randn(1)/7.9;
    r7 = randn(1)/2.5;
    r8 = randn(1)/0.1;
    r9 = randn(1)/1.1;
    r10 = randn(1)/0.29;
    r11 = r10*1.15;
for i = 1:numel(sinal)
    saida(i) = sinal(i)+ 0.7*value*...
        (sin(r1*i)+ sin(r2*i)+ sin(r3*i)+ sin(r6*i) + sin(r4*i) + ...
        sin(r5*i) + sin(r7*i)+ sin(r8*i)+ sin(r9*i)+ sin(r10*i) + sin(r11*i) + 3*randn(1));
end