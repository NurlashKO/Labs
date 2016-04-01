f=@(x)(2+sin(2*sqrt(x)));
a=0;
b=1;
M=10;
cTrapezoid(M, f, a, b, (b-a)/M)
cSimpson(M, f, a, b, (b-a)/M)
