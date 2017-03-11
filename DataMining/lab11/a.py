import csv
import random
import math
import numpy as np

def K(x1, x2):
    return np.dot(x1, x2) + 0.00001
def dist(a, b):
    s = 0
    for i in range(len(a)):
        s = s + (a[i] - b[i])**2
    return s**0.5

lines = csv.reader(open("iris.txt", "r"))
dataset = list(lines)
n = len(dataset)
for i in range(len(dataset)):
    dataset[i] = [float(x) for x in dataset[i]]
nk = [0]*n
x = dataset
y = [0]*n
for i in range(n):
    y[i] = x[i][-1]
    x[i] = x[i][0:-1]
for i in range(n):
    nk[i] = 1/K(x[i], x[i])

t = 0
L = n*[0]
Ln = n*[1]
C = 100

while (dist(L, Ln) > 0.0001):
    L = Ln
    for i in range(n):
        s = 0
        for j in range(n):
            s = s + L[j] * y[j] * K(x[i], x[j])
        Ln[i] = Ln[i] + nk[i] * s
        Ln[i] = max(0, min(Ln[i], C))
print(L)
