from math import log
def calcEntr(dataSet):
    cnt = len(dataSet)
    labelCount = {}
    for feat in dataSet:
        featLabel = feat[-1]
        if (featLabel not in labelCount.keys()):
            labelCount[featLabel] = 0
        labelCount[featLabel] += 1
    entr = 0.0

    for key in labelCount:
        p = (labelCount[key]) / (cnt + 0.0)
        entr -= p * log(p, 2)
    return entr



def createDataSet(file):
    dataSet = []
    with open(file, "r") as lines:
        for s in lines:
            dataSet.append(s.split(" "));
    labels = ['A1', 'A2', 'A3', 'A4', 'A5', 'A6']

    for i in range(len(dataSet)):
        dataSet[i].pop();
        dataSet[i] = list(map(int, dataSet[i]))
        dataSet[i][0], dataSet[i][-1] = dataSet[i][-1], dataSet[i][0]
    return dataSet, labels

myData, labels = createDataSet("monks-2.train")
print(calcEntr(myData))

def splitDataSet(dataSet, axis, value):
    retDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            reducedFeatVec = featVec[:axis]
            reducedFeatVec.extend(featVec[axis+1:])
            retDataSet.append(reducedFeatVec)
    return retDataSet


def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1
    baseEntropy = calcEntr(dataSet)
    bestInfoGain = 0.0; bestFeature = -1
    for i in range(numFeatures):
        featList = [example[i] for example in dataSet]
        uniqueVals = set(featList)
        newEntropy = 0.0
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet)/float(len(dataSet))
            newEntropy += prob * calcEntr(subDataSet)
        infoGain = baseEntropy - newEntropy
        if (infoGain > bestInfoGain):
            bestInfoGain = infoGain
            bestFeature = i
    return bestFeature



def majorityCnt(classList):
    classCount={}
    for vote in classList:
        if vote not in classCount.keys():
            classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = collections.OrderedDict(sorted(d.items(), reverse = True))
    return sortedClassCount[0][0]

def createTree(dataSet,labels):
    classList = [example[-1] for example in dataSet]
    if classList.count(classList[0]) == len(classList):
        return classList[0]
    if len(dataSet[0]) == 1:
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel:{}}
    del(labels[bestFeat])
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]
        myTree[bestFeatLabel][value] = createTree(splitDataSet\
        (dataSet, bestFeat, value),subLabels)
    return myTree


tr = createTree(myData, labels)

def testOnData(tree):
    ans = 0
    print(tree)
    data, labels = createDataSet('monks-2.test')
    for test in data :
        tm = {}
        cur = tree
        for i in range(6):
            tm[labels[i]] = test[i]
        for i in range(6):
            x = list(cur.keys())[0];
            if (tm[x] not in cur[x]):
                cur[x][tm[x]] = 1
            cur = cur[x][tm[x]]
            if (type(cur) is int):
                break;
        if (cur == test[6]):
            ans += 1
    print(ans)

testOnData(tr)


