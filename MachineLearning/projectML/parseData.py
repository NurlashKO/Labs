# -*- coding: utf-8 -*-
def parse(fileName):
    with open(fileName, 'r') as f:
        parsedData = []
        f.readline()
        for line in f:
            cur = line.split(";")
            if (cur[5].strip() == '0' and cur[6].strip() == '0'):
                continue

            if (cur[-1].strip() != "Азота диоксид" or cur[-2] != "Алматы"):
                continue

            parsedData.append([list(map(float, cur[4:7])), float(cur[-3])])

    return parsedData
