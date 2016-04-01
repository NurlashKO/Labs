format long;
f = @(x)sin(pi*x);
a = 0;b = 1;
h = 1/4;
tr=si=si38=bo=0;
for i = 0:3
    tr += trapezoid(f, a+i*h, a+(i+1)*h, h);
    si += Simpson(f, a+i*h, a+(i+1)*h, h/2);
    si38 += Simpson38(f, a+i*h, a+(i+1)*h, h/3);
    bo += boole(f, a+i*h, a+(i+1)*h, h/4);
end;
tr
si
si38
bo
