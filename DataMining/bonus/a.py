import random
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats
import pylab as pl

f = open("backup.txt", "r")
cnt = {}
X=[39,704,825]
items = []

def get_sample():
    sample = []
    for _ in range(10000):
        sample.append(random.choice(items))
    return sample

def distr(sample, X):
    N = len(sample)
    cnt = 0
    for item in sample:
        for x in X:
            if (x in item):
                cnt += 1
                break
    return cnt/(N+0.0)

def distrA(sample, X):
    N = len(sample)
    res = []
    for item in sample:
        f = 0
        for x in X:
            if (x in item):
                f = 1
                break
        res.append(res)
    return res

for line in f:
    item = map(int, line.split())
    items.append(item)
    for x in item:
        if not x in cnt:
            cnt[x] = 0
        cnt[x] += 1

for (key, value) in cnt.items():
    print(key, value)

sample_sup = []
for samples in range(100):
    sample = get_sample()
    sample_sup.append(distr(sample, X))
mean = np.mean(sample_sup)
dev = np.std(sample_sup)

# FIRST

h = sorted(sample_sup)
fit = stats.norm.pdf(h, np.mean(h), np.std(h))  #this is a fitting indeed
pl.plot(h,fit,'-o')
pl.hist(h,normed=True)      #use this to draw histogram of your data
pl.show()                   #use may also need add this

# SECOND
lower = mean - 1.96 * dev / 100
upper = mean + 1.96 * dev / 100
print("lower: ", lower)
print("upper: ", upper)

# THIRD
actual_sup = distr(items, X)
print("Error: ", abs(mean - actual_sup))

# Fourth
print('{:0.6f}'.format(upper - lower))
