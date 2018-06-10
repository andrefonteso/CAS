x = getdatasamples(semruido,[1:9000]);
plot(x)
s = getdatasamples(comruido,[1:9000]);
figure
plot(s,'r')
SNR = snr(x,s-x)