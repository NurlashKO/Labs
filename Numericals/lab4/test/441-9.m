format long

L = 25000;k=0.00003;y0=250;a=0;b=60;
f = @(t, y)k*y*(L-y);

e = euler(f, a, b, y0, 60*5)
plot(e(:, 1), e(:, 2))
pause
