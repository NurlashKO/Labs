function y = cSimpson(M, f, a, b, h)
    s1=s2=0;
    for i = 1:M/2-1
        s1+=f(a+(i+i)*h);
    end;
    for i = 1:M/2
        s2+=f(a+(i+i-1)*h);
    end;
    y=h/3*(f(a)+f(b))+2*h/3*s1+4*h/3*s2;
end;
