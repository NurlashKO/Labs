format long;
x = 5;
h = 0.05;
f = @(x) log(x)
(f(x + h) - 2*f(x) + f(x - h)) / (h**2)
