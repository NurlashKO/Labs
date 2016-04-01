format long;
x = 5;
h = 0.01;
f = @(x) log(x);
(f(x + h) - 2*f(x) + f(x - h)) / (h**2)
