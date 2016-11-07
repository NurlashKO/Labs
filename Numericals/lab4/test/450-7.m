f = @(S, R)1/S;
S0 = 0.1;
SM = 5.1;
R0 = 0;

H = heun(f, S0, SM, R0, 50);

H
