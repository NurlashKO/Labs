f1 = @(t, y)t*t-y;
f2 = @(t, y)-t*y;
y1 = -exp(-2)+2*2-2*2+2;
y2 = exp(-2);

E11 = euler(f1, 0, 2, 1, 20);
E12 = euler(f1, 0, 2, 1, 40);


E21 = euler(f2, 0, 2, 1, 20);
E22 = euler(f2, 0, 2, 1, 40);
