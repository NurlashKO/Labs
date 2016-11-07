function [ t, y, g ] = RungeKutta( f, t0, b, y0, M )
% f - function f(t, y)
% [t0, b] - interval [t0, b] of function f(t, y)
% M - number of intervals
h = (b - t0) / M;
t(1) = t0;
y(1) = y0;

for k = 1:M
    t(k+1) = t(k) + h;
    g(k, 1) = f( t(k), y(k) );
    g(k, 2) = f( t(k) + h / 2, y(k) + h * g(k, 1) / 2);
    g(k, 3) = f( t(k) + h / 2, y(k) + h * g(k, 2) / 2);
    g(k, 4) = f( t(k) + h, y(k) + h * g(k, 3) );
    y(k+1) = y(k) + (h / 6) * (g(k, 1) + 2 * g(k, 2) + 2 * g(k, 3) + g(k, 4));
end

end

