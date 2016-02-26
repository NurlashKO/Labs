import calc
import numpy as np
import matplotlib.pyplot as plt
import parse
import segToData

def show() :

    table = np.array(calc.table)
    width = segToData.width
    x = table[:, 0]
    for i in range(len(x)) :
        x[i] -= width / 2.0
    f, axarr = plt.subplots(3, sharex=True)
    axarr[0].set_title('Probability and Statistics')
    axarr[0].bar(x, table[:, 1], width, color='blue', error_kw=dict(elinewidth=0.5,ecolor='red'))
    axarr[1].bar(x, table[:, 5], width, color='blue', error_kw=dict(elinewidth=0.5,ecolor='red'))
    axarr[2].bar(x, table[:, 6], width, color='blue', error_kw=dict(elinewidth=0.5,ecolor='red'))
    plt.show()

