format long
f1 = @(t, y)t*t-y;
f2 = @(t, y)-t*y;

y1 = @(t)-exp(-t)+t*t-2*t+2;
y2 = @(t)exp(-t*t/2);

b = 0.4;
M = 2;

E11 = heun(f1, 0, b, 1, M);
E12 = heun(f1, 0, b, 1, M*2);

E11
abs(E11(M+1, 2) - y1(b))
E12
abs(E12(2*M+1, 2) - y1(b))

E21 = heun(f2, 0, b, 1, M);
E22 = heun(f2, 0, b, 1, M*2);
E21
abs(E21(M+1, 2) - y2(b))
E22
abs(E22(M+1, 2) - y2(b))

