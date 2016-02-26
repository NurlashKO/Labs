import os
from math import log
from os import listdir
mypath = os.getcwd() + "/ex6DataEmails"
words = {}
totalNonSpam = 0

for path in listdir(mypath + "/nonspam-train"):
    f = open(mypath + "/nonspam-train/" + path, "r")

    for line in f:
        for word in line.split():
            if (word not in words.keys()):
                words[word] = 0
            words[word] = words[word] + 1
            totalNonSpam = totalNonSpam + 1

pNonSpam = {}
for word in words:
    pNonSpam[word] = log(words[word] / (totalNonSpam + 0.0))


words = {}
totalSpam = 0

for path in listdir(mypath + "/spam-train"):
    f = open(mypath + "/spam-train/" + path, "r")

    for line in f:
        for word in line.split():
            if (word not in words.keys()):
                words[word] = 0
            words[word] = words[word] + 1
            totalSpam = totalSpam + 1

pSpam = {}
for word in words:
    pSpam[word] = log(words[word] / (totalSpam + 0.0))


ans = cnt = 0
for path in listdir(mypath + "/spam-test"):
    f = open(mypath + "/spam-test/" + path, "r")
    spam = notSpam = 0

    for line in f:
        for word in line.split():

            if (word not in pSpam.keys()):
                pSpam[word] = log(1 / (totalSpam + 0.0))
            if (word not in pNonSpam.keys()):
                pNonSpam[word] = log(1 / (totalNonSpam + 0.0))
            spam += pSpam[word]
            notSpam += pNonSpam[word]

    cnt += 1
    if (spam > notSpam):
        ans += 1

print("SPAM : " + str(ans))
print("NOT SPAM : " + str(cnt - ans))

ans = cnt = 0
for path in listdir(mypath + "/nonspam-test"):
    f = open(mypath + "/nonspam-test/" + path, "r")
    spam = notSpam = 0

    for line in f:
        for word in line.split():

            if (word not in pSpam.keys()):
                pSpam[word] = log(1 / (totalSpam + 0.0))
            if (word not in pNonSpam.keys()):
                pNonSpam[word] = log(1 / (totalNonSpam + 0.0))
            spam += pSpam[word]
            notSpam += pNonSpam[word]

    cnt += 1
    if (spam > notSpam):
        ans += 1

print("SPAM : " + str(ans))
print("NOT SPAM : " + str(cnt - ans))
