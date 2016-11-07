function [T, Y, D] = TaylorMethod( f1, f2, f3, f4, a, b, ya, M )
%Input  - df = [y' y'' y''' y'''']
%       - a and b are the left and right points
%       - ya is the initial condition
%       - M is the number of steps
%Output - T4 = [T' Y'] where T is the vector of abscissas and Y is the
%         vector of odinates
h = (b - a) / M;
Y = zeros(1, M + 1);
T = a : h : b;
Y(1) = ya;
D = zeros(4, 4);
for i = 1: M
    D(i, 1) = f1(T(i), Y(i));
    D(i, 2) = f2(T(i), Y(i));
    D(i, 3) = f3(T(i), Y(i));
    D(i, 4) = f4(T(i), Y(i));
    Y(i+1) = Y(i) + h * ( D(i, 1) + h * ( D(i, 2) / 2 + h * ( D(i, 3) / 6 + h * D(i, 4) ) ) );
end

end

