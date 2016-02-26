import random
import numpy as np
import operator

fo = open("iris.txt", "r")
setosa = []
versicolur = []
virginica = []
for i in range(50) :
    setosa.append(fo.readline().rstrip('\n').split(","))

for i in range(50) :
    versicolur.append(fo.readline().rstrip('\n').split(","))

for i in range(50) :
    virginica.append(fo.readline().rstrip('\n').split(","))

K = 1

flowers = [setosa[0][4], versicolur[0][4], virginica[0][4]]

random.shuffle(setosa)
random.shuffle(versicolur)
random.shuffle(virginica)

t = 10
#Last 5
testSet = []
testSet += setosa[-t:]
testSet += versicolur[-t:]
testSet += virginica[-t:]
#All others
data = []
data += setosa[:-t]
data += versicolur[:-t]
data += virginica[:-t]

def sqr(x) :
    return x ** 2
def dist(a, b) :
    for i in range(4) :
        a[i] = float(a[i])
        b[i] = float(b[i])
    return sqr(a[0] - b[0]) + sqr(a[1] - b[1]) + sqr(a[2] - b[2]) + sqr(a[3] - b[3])

for K in range(1, 15) :
    print("K : " + str(K))

    correct = 0
    for x in testSet :
        cur = []
        for y in data :
            cur.append([dist(x, y), y[4]])
        cur.sort()
        cnt = {key:0 for key in flowers}
        for i in range(K) :
            cnt[cur[i][1]] += 1
        mx = flowers[0]
        for f in flowers :
            if (cnt[f] > cnt[mx]) :
                mx = f
        if mx == x[4] :
            correct += 1

    print("Error : " + str(correct / (len(testSet) + 0.0)))

#Solution
data = setosa + versicolur + virginica
fo.close()
fo = open("forTest", "r")
testSet = []
for i in range(5) :
    f = []
    for j in range(4) :
        s = fo.readline().split(" ")
        f.append(s[-1])
    testSet.append(f)

K = 10
for x in testSet :
    cur = []
    for y in data :
        cur.append([dist(x, y), y[4]])
    cur.sort()
    cnt = {key:0 for key in flowers}
    for i in range(K) :
        cnt[cur[i][1]] += 1
    mx = flowers[0]
    for f in flowers :
        if (cnt[f] > cnt[mx]) :
            mx = f
    print(mx)






