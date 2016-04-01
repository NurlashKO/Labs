f=@(x)1/sqrt(x)
a=0.25;
b=4;
M=10;
cTrapezoid(M, f, a, b, (b-a)/M)
cSimpson(M, f, a, b, (b-a)/M)
