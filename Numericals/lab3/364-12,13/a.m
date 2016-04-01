f=@(x)(1+x.**2).**(-1);
a=-1;
b=1;
M=10;
cTrapezoid(M, f, a, b, (b-a)/M)
cSimpson(M, f, a, b, (b-a)/M)
cMidPoint(M, f, a, b)
