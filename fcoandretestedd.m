clc; close all;

D = 12; % centro-centro
L = 8; % largura
P = 3; % profundide
Ds = 2*sqrt(D*D/4 + P*P/4);
Dd = Ds;
DL = 2*sqrt(D*D/4 + L*L/4);

v = 1500;

tdd = D/v;
ts = Ds/v;
td = Ds/v;
tl = DL/v;

f = 19000;
dt = 0.05/f;
t = 0:dt:0.001;
psinal = 10*sin(2*pi*f*t);
pg = [psinal, 0*psinal, psinal, 0*psinal];
pg = [pg, pg, pg];

tempo = 1:max(size(pg)); tempo = tempo - 1; tempo = tempo*dt;
figure; subplot(2,2,1); plot(tempo, pg);

% "atenuações":
aD = 10/(D*D);
aL = 1.0/(DL*DL);
as = 2/(Ds*Ds);
ad = 2.0/(Dd*Dd);

% atrasos + atenuações:
aDD = 0:dt:tdd;  %% direto
pgaD = [aDD*0, pg]*aD;
tt = max(size(pgaD));
tempo = 1:tt; tempo = tempo - 1; tempo = tempo*dt;
subplot(2,2,2); plot(tempo, pgaD);

asub = 0:dt:ts;  %% subida
pgas = [asub*0, pg]*as;
subplot(2,2,3); plot(pgas);

ades = 0:dt:td;  %% descida
pgad = [ades*0, pg]*ad;
%subplot(2,2,4); plot(pgad);

alat = 0:dt:tl;  %% lateral
pgal = [alat*0, pg]*aL;
subplot(2,2,4); plot(pgal);

%%% sinal total:
tt = max(size(pgaD));
stotal = pgaD + pgas(1:tt) + pgad(1:tt) + 2*pgal(1:tt);
tempo = 1:tt; tempo = tempo - 1; tempo = tempo*dt;
figure; plot(tempo, stotal);

%%%% ruido:
ruido = 0.1*randn(1,tt);
sr = stotal + ruido;
figure; plot(tempo, sr);

%%% filtro PB 1a. ordem:
tk=0:0.2:10;
h = exp(-tk); h = h/sum(h);
srf = conv(h,sr);
srf = srf(1:tt);
figure; plot(tempo, srf);

pgaD + pgas(1:tt) + pgad(1:tt) + 2*pgal(1:tt);
tempo = 1:tt; tempo = tempo - 1; tempo = tempo*dt;
figure; plot(tempo, pgaD, tempo, pgas(1:tt), tempo, 2*pgal(1:tt));