f = @(x)sin(pi*x);
a = 0;b = 1;
trapezoid(f, a, b, 1)
Simpson(f, a, b, 1/2)
Simpson38(f, a, b, 1/3)
boole(f, a, b, 1/4)

