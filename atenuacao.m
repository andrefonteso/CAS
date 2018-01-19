%-------------------------------------------------------------------------
% Parameter values that influences the attenuation of underwater mean
%-------------------------------------------------------------------------
T = 32; % Temperature (C)
S = 1; % Salinity (ppt)
D = 1; % Depth (m)
pH = 7.2; % pH
f1 = 0.78 * sqrt(S/35) * (exp(T/26)); % Boric acid
f2 = 42 * (exp(T/17)); % Magnesium sulfate
%-------------------------------------------------------------------------
% Auxiliary variables
%-------------------------------------------------------------------------
r = 1; % Transducer radium (cm)
rr = 10; % Reference radium
step = 500; % Jump between distances in (cm)
l = 0:step:(step*20+r); % Emitter to receiver distance
f = 0:50:1001; % Signal frequency (kHz)
% Transducer diameter calcule
d = 2*r;
f(1)=1;
l(1)=r;
%-------------------------------------------------------------------------
% Samples number for the graph
%-------------------------------------------------------------------------
saida = zeros(21,21);
saida2 = zeros(21,21);
saidat = zeros(21,21);
a = zeros(21);
lambda = zeros(21);
angulo = zeros(21);
de = zeros(21,21);
nm= zeros(21,21);
%-------------------------------------------------------------------------
% Sound speed calculus on water (m/s)
%-------------------------------------------------------------------------
cmetro = 1448.96 + 4.591*T - 5.304*(10^(-2))*(T^(2)) + 2.374*(10^(-4))*...
    (T^(3)) + 1.340*(S-35) + 1.630*(10^(-2))*D + 1.675*(10^(-7))*(D^(2)) -...
    1.025*(10^(-2))*T*(S-35) - 7.139*(10^(-13))*T*(D^(3));

% disp(’Sound speed (m/s):’);
%disp(c);
c=cmetro*100;
%-------------------------------------------------------------------------
% Cycle for the calculus of Coefficient of Absorption and attenuation
%-------------------------------------------------------------------------
for i = 1:1:21;
    % Counter that represents the distance (to simulate the behavior of
    % attenuation through several distances)
    for j = 1:1:21;
        % Counter that represents the frequency (to simulate the behavior of
        % attenuation through several frequencies)
        % Wavelength calculus
        lambda(j) = c/(f(j)*1000);
        %disp(’wavelength’);
        %disp(lambda);
        % Absorption coefficient
        a(j) = (((0.106 * (f1 * f(j)^2) * exp((pH - 8)/0.56)) / (f1^2 +...
            f(j)^2)) + ((0.52 * (1 + (T/43)) * (S/45) * (f2 * f(j)^2) *...
            exp(-(D/6))) / (f2^2 + f(j)^2)) + (0.00049 * (f(j)^2) *...
            (exp(-(T/27 + D/17)))));
        % Attenuation (dB)
        %saida(j,i) = -10*log(((2*(angulo)*(l(i))^2)/(pi*r^2))+a(j));
        saida(j,i) = a(j)*((l(i))/1e5);
        de=(pi*rr^2);
        %angulo(j) = asin(lambda(j)/d);
        if r<lambda(j);
            angulo(j) = pi/2;
            nm(j,i)=(2*angulo(j)*(l(i))^2);
        end
        if r>=lambda(j);
            angulo(j) = asin(lambda(j)/d);
            nm(j,i)=(2*angulo(j)*(l(i))^2);
        end
        saida2(j,i)=10*log10(nm(j,i)/de + 1);
        saidat(j,i)=saida(j,i)+saida2(j,i);
    end
end
%-------------------------------------------------------------------------
% Graphs
%-------------------------------------------------------------------------
saida(1,1)=0;
saida2(1,1)=saida2(2,1);
%subplot(2,1,1);
figure(1);
mesh((l-r)/100,f,saida);
title ('Absorption');
shading interp;
xlabel('Distance (m)');
ylabel('Frequency (kHz)');
zlabel ('Absorption (dB)');
%subplot(2,1,2)
figure(2);
mesh((l-r)/100,f,saida2, 'EdgeColor','none');
title ('Spreading');
shading interp;
xlabel('Distance (m)');
ylabel('Frequency (kHz)');
zlabel ('Spreading (dB)');
figure(3);
mesh((l-r)/100,f,saidat, 'EdgeColor','none');
title ('Attenuation');
shading interp;
xlabel('Distance (m)');
ylabel('Frequency (kHz)');
zlabel('Attenuation (dB)');