format long;
x = 5;
h = 0.1;
f = @(x) log(x);
(-f(x + 2*h) + 16*f(x + h) - 30*f(x) + 16*f(x - h) - f(x - 2*h))/(12*h*h)
