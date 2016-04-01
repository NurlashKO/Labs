function y = cTrapezoid(M, f, a, b, h)
    s = 0;
    for i = 1:M-1
        s += f(a+h*i);
    end;
    y = h/2*(f(a)+f(b))+s*h;
end;
