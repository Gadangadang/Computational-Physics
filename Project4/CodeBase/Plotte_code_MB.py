import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('MonteCarloRun.txt', 'r')

I_temp = []
Mcs_l =[]
E_average = []
E_variance = []
M_average = []
M_variance = []
M_abs_tot = []

data.readline().split("      ")[0:5] #Discard first line
for line in data:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        x4 = float(line.split()[3])
        x5 = float(line.split()[4])
        x6 = float(line.split()[5])
        x7 = float(line.split()[6])
        I_temp.append(x1)
        Mcs_l.append(x2)
        E_average.append(x3)
        E_variance.append(x4)
        M_average.append(x5)
        M_variance.append(x6)
        M_abs_tot.append(x7)

# Should probably amend this..
"""plt.title("Stuff [Plot]")
plt.plot(I_temp, M_abs_tot)
plt.xlabel('Stuff [K]')
plt.ylabel('Stuff [J]')
#plt.tight_layout()
plt.show()"""
plt.plot(Mcs_l,E_average)
plt.show()
