function E = euler(f, a, b, ya, M)
    h = (b-a)/M;
    T(1) = a;
    Y(1) = ya;

    for j=1:M
        T(j + 1) = T(j) + h;
        Y(j + 1) = Y(j) + h * f(T(j), Y(j));
    end;
    E = [T', Y'];
end;
