import matplotlib.pyplot as plt
import numpy as np
data = open('Mon_vis.txt', 'r')
Mon = []
for line in data:
    x1 = float(line.split()[0])
    Mon.append(x1)
num_bins = len(Mon)
n, bins, patches = plt.hist(Mon, 200, facecolor='b')
plt.title("True beauty of capitalisme")
plt.xlabel("Money $$$")
plt.ylabel("Peepz :D")
plt.show()
