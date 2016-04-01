for i = 0:6
    f=@(x)x^i;
    boole(f, 0, 4, 1)
end;
%%RESULTS:
%ans =  4
%ans =  8
%ans =  21.333
%ans =  64
%ans =  204.80
%ans =  682.67
%ans =  2346.7

%%TRUE ANSWERS:
%% 4
%% 8
%% 21.333 
%% 64
%% 204.8
%% 682.6666667
%% 2346.5714
%% the function x^6 is lowest power of x for which rule in not exact
