function AP2draw(g)
    pause
    x = 0:0.1:1
    plot(x, g(x))
    hold on
    x = 0:0.1:1
    plot(x, x)
    hold off
    pause
end
