
width = 0
def process() :
    global width
    fo = open("data", "w")
    with open('segmentData.txt') as openfileobject:
        for line in openfileobject:
            st = list(map(float, line.split(" ")))
            fo.write(str((st[0] + st[1]) / 2.0) + " " + str(st[2]) + "\n");
            width = st[1] - st[0];
    fo.close()
