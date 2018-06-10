fa = 400e3;
fs = 20e3;

t=0:(1/fa):0.01;
s = sin(fs*2*pi*t);
s = s + 0.2*randn(size(s)) + 0.5*cos(fs*pi*t) + 0.5*cos(fs*4*pi*t);

close all; plot(t,s);

w1 = 18/200;
w2 = 22/200;
[b,a] = butter(3,[w1,w2],'bandpass');
[h,w] = freqz(b,a,1000);
figure; plot(w,abs(h));

sf = filter(b,a,s);
figure; plot(t,sf,t,sin(fs*2*pi*t),'m');