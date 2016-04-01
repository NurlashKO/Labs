f = @(x)x.**3;
a=0;
b=1;
M=10;
cTrapezoid(M, f, a, b, (b-a)/M)
cSimpson(M, f, a, b, (b-a)/M)
