function y = fb(x)
    EPS = 1e-10;
    if (abs(x-0.0) < EPS)
        y = 0.141120;
    end;
    if (abs(x-0.1) < EPS)
        y = 0.041580;
    end;
    if (abs(x-0.2) < EPS)
        y = -0.058374;
    end;
    if (abs(x-0.3) < EPS)
        y = 0.157746;
    end;
end;
