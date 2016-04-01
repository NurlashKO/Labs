function res = f(x, y, x0)
    N = length(x);
    res = 0;
    for i = 1:N
        v = y(i);
        for j = 1:N 
            if (i != j)
                v = v / (x(i) - x(j));
                v = v * (x0 - x(j));
            endif;
        end;
        res = res + v;
    end;
    res;
end;
