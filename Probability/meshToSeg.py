def process() :
    a = []
    with open('mesh.txt') as f:
        for line in f:
            data = list(map(float, line.split()))
            a += data
    K = a[0]
    del a[0]
    a.sort()
    mi = min(a)
    W = int((max(a) - min(a)) / K + 1)
    fo = open("segmentData.txt", "w")
    print(str(len(a)) + " " + str(K))
    for i in range(int(K)) :
        L = mi + i * W
        R = mi + (i + 1) * W
        cnt = 0
        for x in a :
            if (L <= x and x < R) :
                cnt += 1
        fo.write(str(L) + " " + str(R) + " " + str(cnt) + "\n")
process()
