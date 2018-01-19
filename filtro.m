function Hd = filtro
% All frequency values are in MHz.
Fs = 25; % Sampling Frequency
N = 10; % Order
Fc = 2; % Cutoff Frequency
flag = 'scale'; % Sampling Flag
% Create the window vector for the design algorithm.
win = rectwin(N+1);
% Calculate the coefficients using the FIR1 function.
b = fir1(N, Fc/(Fs/2), 'low', win, flag );
Hd = dfilt.dffir(b);
% [EOF]

