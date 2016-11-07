function H = heun(f, a, b, ya, M)
    h = (b - a) / M;
    T(1) = a;
    Y(1) = ya;
    for j = 1:M
        T(j + 1) = T(j) + h;
        k1 = feval(f, T(j), Y(j));
        k2 = feval(f, T(j + 1), Y(j) + h*k1);
        Y(j + 1) = Y(j) + h/2*(k1+k2);
    end;
    H = [T', Y'];
end;
