function y = Simpson38(f, a, b, h)
    y = 3*h/8*(f(a) + 3*f(a+h) + 2*f(a+2*h)+ f(b));
end;
