function y = boole(f, a, b, h)
    y = 2*h/45*(7*f(a)+32*f(a+h)+12*f(a+2*h)+32*f(a+3*h)+7*f(b));
end;
