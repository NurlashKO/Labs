
g = @(x) x.^5 - 3 * x.^3 - 2*x.^2 + 2
AP2fixedPoint(g, 0)
AP2draw(g)

g = @(x) cos(sin(x))
AP2fixedPoint(g, 0)
AP2draw(g)

g = @(x) x.^2 - sin(x + 0.15) 
AP2fixedPoint(g, 0)
AP2draw(g)

g = @(x) x.^(x - cos(x))
AP2fixedPoint(g, 0)
AP2draw(g)

