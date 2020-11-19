import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('PE.txt', 'r')
counter=[]
Energy= []

for line in data:
    x1 = float(line.split()[0])
    x2 = float(line.split()[1])
    counter.append(x1)
    Energy.append(x2)
x =zip(counter,Energy)
num_bins = len(Energy)
plt.bar(Energy,counter,width=abs(Energy[1]-Energy[2]))
plt.show()
