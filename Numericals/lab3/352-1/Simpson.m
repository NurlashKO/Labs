function y = Simpson(f, a, b, h)
    y = h/3*(f(a) + 4*f(a+h) + f(b));
end;
