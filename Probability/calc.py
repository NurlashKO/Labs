import numpy as np
import parse
import DrawHist

table = []

def run() :

    global table
    table = parse.dataToTable()
    cnt = len(table)


    for r in table :
        r.append(r[0] * r[1])
    for r in table :
        r.append(r[0] * r[2])
    table[0].append(table[0][1]);
    for i in range(1, cnt) :
        table[i].append(table[i - 1][4] + table[i][1]);

    N = int(parse.sumCol(table, 1))

    for r in table :
        r.append(r[1] / (N + 0.0))
    for r in table :
        r.append(r[4] / (N + 0.0))
    Mean = np.sum(np.array(table)[:, 2]) / (N + 0.0)
    Vr = np.sum(np.array(table)[:, 3]) - N * (Mean ** 2)

    fo = open("result.txt", "w")

    for x in ["Mi", "Fi", "MiFi", "Mi^2Fi", "FI", "R/F", "C/F"] :
        fo.write('{:15}'.format(x))
    fo.write("\n")

    for r in table :
        for x in r :
            fo.write('{:15}'.format(str(format(x, '.2f'))))
        fo.write('\n')
    fo.write("Mean : sum(mi, fi) / N = " + str(np.sum(np.array(table)[:, 3])) + " / " + str(N) + " = " + str(Mean) + "\n")
    r = np.array(table)[:,0];
    Median = 0;
    buf = []
    for r in table :
        for i in range(int(r[1])) :
            buf.append(r[0])
    if (N % 2 == 1) :
        Median = buf[N // 2]
    else :
        Median = (buf[N // 2] + buf[N // 2 + 1]) / 2.0
    fo.write("Median : " + str(Median) + "\n");
    fo.write("Sample Variate : " + str((Vr / (N - 1.0))** 0.5) + "\n")
    fo.write("Population Variate : " + str((Vr / (N - .0))** 0.5) + "\n")
