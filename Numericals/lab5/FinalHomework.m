%%p.457 #1
% f = @(t, y) (-exp(-t) + t * t - 2 * t + 2);
% f1 = @(t, y)(t * t - y);
% f2 = @(t, y)(- t * t + 2 * t + y );
% f3 = @(t, y)(t * t - 2 * t + 2 - y);
% f4 = @(t, y)(- t * t + 2 * t - 2 + y);
% [T1, Y1, D1] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 20 );
% [T2, Y2, D2] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 40 );
% plot(T1, Y1, T2, Y2, 2, f(2));
% grid on;
% 
% 
% %p.457 #3
% f = @(t, y) ( exp( - t * t / 2) );
% f1 = @(t, y) ( - t * y);
% f2 = @(t,y )( -y + t * t * y );
% f3 = @(t,y )(- t * t * t * y + 3 * t * y);
% f4 = @(t,y )(t * t * t* t * y + 3 * y);
% [T1, Y1, D1] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 20 );
% [T2, Y2, D2] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 40 );
% plot(T1, Y1, T2, Y2, 2, f(2), 'xr', 3, 0, 'w');
% grid on;

% p.457 #5
% f = @(t, y) ( 1 / (1 - t * t) );
% f1 = @(t, y) ( 2 * t * y * y);
% f2 = @(t,y )( 2 * y * y + 8 * t * t * y * y * y );
% f3 = @(t,y )(24 * t * y ^ 3 + 48 * t ^ 3 * y ^ 4 );
% f4 = @(t,y )(24 * y ^ 3 + 288 * t * t * y ^ 4 + 384 * t ^ 4 * y ^ 5 );
% [T1, Y1, D1] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 20 );
% [T2, Y2, D2] = TaylorMethod( f1, f2, f3, f4, 0, 2, 1, 40 );
% plot(T1, Y1, T2, Y2, 2, f(2), 'xr', 3, 0, 'w');
% grid on;
% 
% p.472 #2
% f = @(t, y)(3 * y + 3 * t);
% f4exact = @(t, y) ( 4 * exp(3 * t) / 3 - t - 1/3);
% [ t1, y1, g1 ] = RungeKutta( f, 0, 2, 1, 20 );
% [ t2, y2, g2 ] = RungeKutta( f, 0, 2, 1, 40 );
% plot(t1, y1, t2, y2, 2, f(2), 'xr', 3, 0, 'w');
% grid on;

% 
% p.472 #4
% f = @(t, y)( exp(-2 * t) - 2 * y );
% f5exact = @(t, y) ( 0.1 * exp(-2 * t) + t * exp(-2 * t) );
% [ t1, y1, g1 ] = RungeKutta( f, 0, 2, 0.1, 20 );
% [ t2, y2, g2 ] = RungeKutta( f, 0, 2, 0.1, 40 );
% fig5 = figure('Name', 'Problem 4');
% plot(t1, y1, t2, y2, 2, f5exact(2), 'xr', 3, 0, 'w');
% grid on;

% 
% p.472 #7
% f = @(t, y)( 2 * atan(t) );
% f6exact = @(t, y) ( 2 * t * atan(t) - log(1 + t * t) );
% [ t1, y1, ~ ] = RungeKutta( f, 0, 1, 0, 20 );
% plot(t1, y1, 1, f(1), 'xr', 3, 0, 'w');
% grid on;
% 
% p.472 #8
% f = @(t, y)( 0.01 * ( 70 - y ) * ( 50 - y )  );
% f7exact = @(t, y) ( 350 * (1 - exp(-0.2 * t)) * (7 - 5 * exp(-0.2 * t)) );
% [ t1, y1, g1 ] = RungeKutta( f, 0, 60, 0, 600 );
% plot(t1, y1, 60, f6exact(60), 'xr', 3, 0, 'w');
% grid on;
% 
% p.494 #3;
% f = @(t, x, y) (3 * x - y);
% g = @(t, x, y) (4 * x - y);
% [ t, x, y ] = RungeKutta2( f, g, 0, 2, 0.2, 0.5, 40 );
% plotyy(t, x, t, y);
% grid on;
% 
% p.494 # 8
% f = @(t, x, y) (y);
% g = @(t, x, y) (6 * cos(t) - x);
% [ t, x, y ] = RungeKutta2( f, g, 0, 2, 2, 3, 40 );
% plotyy(t, x, t, y);
% grid on;
% 
% p.494 #10
% f = @(t, x, y) (y);
% g = @(t, x, y) (8 * sin(5 * t) - 25 * x);
% [ t, x, y ] = RungeKutta2( f, g, 0, 2, 0, 0, 40 );
% plotyy(t, x, t, y);
% grid on;
% 
% p.494 #13
% f = @(t, x, y) (2 * x - 0.02 * x * y);
% g = @(t, x, y) (0.0002 * x * y - 0.8 * y);
% [ t1, x1, y1 ] = RungeKutta2( f, g, 0, 5, 3000, 120, 50 );
% [ t2, x2, y2 ] = RungeKutta2( f, g, 0, 5, 5000, 100, 50 );
% plotyy(t1, x1, t1, y1);
% grid on;
% 
% plot(x1, y1);
% grid on;
% 
% plotyy(t2, x2, t2, y2);
% grid on;
% 
% plot(x2, y2);
% grid on;
% 
% p.494 #16
% f = @(t, x, y) (y ^ 2 - x ^ 2);
% g = @(t, x, y) (2 * x * y);
% [ t1, x1, y1 ] = RungeKutta2( f, g, 0, 1.5, 2, 0.1, 30 );
% plotyy(t1, x1, t1, y1);
% grid on;
% 
% plot(x1, y1);
% grid on;
% 
% p.494 # 18
f = @(t, x, y) (x ^ 3 - 2 * x * y ^ 2);
g = @(t, x, y) (2 * x ^ 2 * y - y ^ 3);
[ t1, x1, y1 ] = RungeKutta2( f, g, 0, 2, 1, 0.2, 80 );
plotyy(t1, x1, t1, y1);
grid on;
% 
% plot(x1, y1);