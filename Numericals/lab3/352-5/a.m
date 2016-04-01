f = @(x)1;
trapezoid(f, 0, 1, 1)
f = @(x)x;
trapezoid(f, 0, 1, 1)
f = @(x)x**2;
trapezoid(f, 0, 1, 1)
%% f(x)=1, gives 1
%% f(x)=x, gives 0.5
%% f(x)=x^2, gives 0.5 which is wrong. True value is 1/3. Its lowest value for which rule doesn't hold.
