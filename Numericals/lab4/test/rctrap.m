format long
function [T, S, B] = rctrap(f, a, b, n)
    M = 1;
    h = b - a;
    T(1)=h*(feval(f, a)+feval(f, b))/2;
    err = 1;
    j = 1;
    while err > 5e-6
        M = 2*M;
        h = h/2;
        s=0;
        for k = 1:M/2
            x = a + h*(2*k-1);
            s = s + feval(f, x);
        end;
        T(j+1)=T(j)/2 + h*s;
        S(j) = (4*T(j + 1) - T(j)) / 3;
        if (j > 1)
            B(j - 1) = (16 * S(j) - S(j - 1))/15;
        end;
        err = abs(T(j + 1) - T(j));
        j = j + 1;
    end;
end;

[T, S, B] = rctrap(@(x)x*x+x+1, 0, 10, 100);
T
S
B
