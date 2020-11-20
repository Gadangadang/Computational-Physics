import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('E.txt', 'r')
counter=[]
Energy= []

for line in data:
    x1 = float(line.split()[0])
    Energy.append(x1)
num_bins = len(Energy)
n, bins, patches = plt.hist(Energy, 800, density=True, facecolor='g')
plt.show()
