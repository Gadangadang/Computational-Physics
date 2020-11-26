import matplotlib.pyplot as plt
import numpy as np
data = open('Mon_vis.txt', 'r')
Mon = []
for line in data:
    x1 = float(line.split()[0])
    Mon.append(x1)
num_bins = len(Mon)
Mon = np.asarray(Mon)
plt.axvspan(0, 200, facecolor='saddlebrown', alpha=0.5, label="Peasants (from Borgen)") # X coordinate
plt.axvspan(200, 600, facecolor='silver', alpha=0.5, label="Middle class (from Toten)") # X coordinate
plt.axvspan(600, np.max(Mon), facecolor='gold', alpha=0.5, label="Upper class (from Stavanger)") # X coordinate

n, bins, patches = plt.hist(Mon, 200, facecolor='b')
#plt.axhspan(0, np.max(np.asarray(n)), facecolor='0.2', alpha=0.5) #Y coordinate

plt.title("True beauty of capitalisme")
plt.xlabel("Money $$$")
plt.ylabel("Peepz :D")
plt.legend()
plt.show()
