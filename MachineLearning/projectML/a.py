from pybrain.tools.shortcuts import buildNetwork
from pybrain.datasets import SupervisedDataSet
from pybrain.supervised.trainers import BackpropTrainer
from parseData import parse
from pybrain.structure import MDLSTMLayer, LinearLayer, SigmoidLayer, SoftmaxLayer, TanhLayer, GaussianLayer
import matplotlib.pyplot as plt
import random

#parsing data from file
dataSet = parse("data.csv")
random.shuffle(dataSet)
#shuffle(dataSet)
#parameters of network
net = buildNetwork(3, 20, 1, bias=True, hiddenclass=SigmoidLayer, outclass=SigmoidLayer)

#net = buildNetwork(3, 2, 1, bias=True, hiddenclass=SoftmaxLayer, outclass=LinearLayer)
print(net.modules)
#parameters of dataset and testSet
ds = SupervisedDataSet(3, 1)
ts = SupervisedDataSet(3, 1)
#Load data to training dataset
buf = []
for item in dataSet[2000:10000]:
    ds.addSample(item[0], item[1])

for item in dataSet[1000:2000]:
    ts.addSample(item[0], item[1])

trainer = BackpropTrainer(net, ds)
#training
for i in range(40):
    trainer.train()
#Accuracy
print "Error: " + str(trainer.testOnData(ts))

g1 = []
g2 = []
diff = []
x = range(1000)
for i in range(1000):
    g1.append(net.activate(ts["input"][i]))
    g2.append(ts["target"][i])
    print("Output : " + str(g1[i]))
    print("Answer : " + str(g2[i]))
    print("+----------------------+")
    diff.append(g1[-1] - g2[-1])
    if (diff[-1] > 0.3):
        print(str(g2[-1]) + "!")

#plt.plot(x, g1)
#plt.plot(x, g2, color='r')
plt.plot(x, diff)
plt.show()
