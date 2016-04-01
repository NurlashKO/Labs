format long;
%% Each method gives us next answers
correctAnswer = -0.04;
A = -0.0400020001332990;
B = -0.0400000799971600;
C = -0.0399999914538207;
error1 = abs(correctAnswer - A)
error2 = abs(correctAnswer - B)
error3 = abs(correctAnswer - C)
%%error1 =    2.00013329899884e-06
%%error2 =    7.99971600004556e-08
%%error3 =    8.54617929896273e-09
%% Its clear that answer (C) is most accurate
