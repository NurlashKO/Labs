function P = AP2fixedPoint(g, p0)
    for i = 1:100
        p0 = g(p0);
    end
    P = p0;
end
