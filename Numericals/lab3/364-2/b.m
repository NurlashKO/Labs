f = @(x)sin(x);
a=0;
b=pi/4;
M=10;
cTrapezoid(M, f, a, b, (b-a)/M)
cSimpson(M, f, a, b, (b-a)/M)
