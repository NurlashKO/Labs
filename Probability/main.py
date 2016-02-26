import calc
import parse
import segToData
import DrawHist
import os
import meshToSeg


print("Choose DataProcess Mode :")
print("1 -> Pure Data")
print("2 -> Segmented Data")
print("3 -> Table Random Data")
m = int(input())
if (m == 1) :
    calc.run()
    os.system("subl result.txt")
if (m == 2) :
    segToData.process()
    calc.run()
    os.system("subl result.txt")
    DrawHist.show()
if (m == 3) :
    meshToSeg.process()
    segToData.process()
    calc.run()
    os.system("subl result.txt")
    DrawHist.show()
