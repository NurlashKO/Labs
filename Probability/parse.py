import segToData

def process(line) :
    return list(map(float, line.split(" ")))

def dataToTable() :
    table = []
    with open('data') as openfileobject:
        for line in openfileobject:
            table.append(process(line))
    return table

def sumCol(matrix, col) :
    ans = 0
    for r in matrix :
        ans += r[col]
    return ans;
