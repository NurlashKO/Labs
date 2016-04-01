function y = cMidPoint(M, f, a, b)
    h = (b-a)/M;
    y=0;
    for i = 1:M
        y += f(a+(i-1/2)*h);
    end;
    y*=h;
end;
