function y = fa(x)
    EPS = 1e-10;
    if (abs(x-0.0) < EPS)
        y = 0.989992;
    end;
    if (abs(x-0.1) < EPS)
        y = 0.999135;
    end;
    if (abs(x-0.2) < EPS)
        y = 0.998295;
    end;
    if (abs(x-0.3)<EPS)
        y = 0.987480;
    end;
end;
