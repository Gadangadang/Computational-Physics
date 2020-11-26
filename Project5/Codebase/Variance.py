import matplotlib.pyplot as plt
import numpy as np
V =[]
data = open('V_vis.txt','r')
data.readline().split("      ")[0:5]
for line in data:
    x1 = float(line.split()[0])
    V.append(x1)
mcs = np.linspace(1,len(V),len(V))
plt.plot(mcs,V)
plt.show()
