f = open("data", "r")
s = f.read()
a = list(map(int, s.split(", ")))

a.sort()
print(a)
n = len(a)

print("(MIN, MAX) -> MAX - MIN " + "(" + str(max(a)) + ", " + str(min(a)) + ") -> " + str(max(a) - min(a)))
x = sum(a) / (n + 0.0)

print("SUM : " + str(sum(a)))
print("Mean : " + str(x))
s = 0
for d in a :
    s += abs(d - x)
print("M.A.D. : " + str(s / (n + 0.0)))

s = 0
for d in a :
    s += d ** 2

print("Sum x_i^2 : " + str(s))
s -= n * x * x
print("Population Variance : " + str(s / (n + 0.0)))
s = s / (n - 1.0)
print("SampleVariance, SampleStandardVariance -> " + str(s) + ", " + str(s ** 0.5))

p1 = (n + 1) / 4.0 - 1
p3 = 3*(n + 1) / 4.0 - 1
Q1 = a[int(p1)] + (p1 - int(p1))*(a[int(p1 + 1)] - a[int(p1)])
Q3 = a[int(p3)] + (p3 - int(p3))*(a[int(p3 + 1)] - a[int(p3)])

print("P1, P3 -> " + str(p1) + ", " + str(p3))
print("Q1, Q3 -> Q3 - Q1 : " + str(Q1) + ", " + str(Q3) + " -> " + str(Q3 - Q1))
