function [ t, x, y ] = RungeKutta2( f, g, t0, b, x0, y0, M )
% f - function f(t, y)
% [t0, b] - interval [t0, b] of function f(t, y)
% M - number of intervals
h = (b - t0) / M;
t = zeros(1, M + 1);
x = zeros(1, M + 1);
y = zeros(1, M + 1);
t(1) = t0;
x(1) = x0;
y(1) = y0;



for k = 1:M
    t(k+1) = t(k) + h;
    
    f1 = f( t(k), x(k), y(k) );
    g1 = g( t(k), x(k), y(k) );
    
    f2 = f( t(k) + h / 2, x(k) + h * f1 / 2, y(k) + h * g1 / 2);
    g2 = g( t(k) + h / 2, x(k) + h * f1 / 2, y(k) + h * g1 / 2);
    
    f3 = f( t(k) + h / 2, x(k) + h * f2 / 2, y(k) + h * g2 / 2);
    g3 = g( t(k) + h / 2, x(k) + h * f2 / 2, y(k) + h * g2 / 2);
    
    f4 = f( t(k) + h, x(k) + h * f3, y(k) + h * g3 );
    g4 = g( t(k) + h, x(k) + h * f3, y(k) + h * g3 );
    
    if k== 1
    display(f1, 'f1');
    display(g1, 'g1');
    display(f2, 'f2');
    display(g2, 'g2');
    display(f3, 'f3');
    display(g3, 'g3');
    display(f4, 'f4');
    display(g4, 'g4');
    end;
    
    x(k+1) = x(k) + (h / 6) * (f1 + 2 * f2 + 2 * f3 + f4);
    y(k+1) = y(k) + (h / 6) * (g1 + 2 * g2 + 2 * g3 + g4);
end

end