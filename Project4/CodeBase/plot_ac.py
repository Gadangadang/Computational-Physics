import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('MonteCarloRun.txt', 'r')


files = ["T_1_o.txt","T_1_n.txt","T_2_o.txt","T_2_n.txt"]
i = 0
f, (ax1, ax2, ax3) = plt.subplots(1, 3)
f2, (ax4, ax5, ax6) = plt.subplots(1, 3)
for name in files:
    Mcs_l =[]
    E_average = []
    M_abs_tot = []
    counter = []
    data = open(name,'r')
    data.readline().split("      ")[0:5]
    for line in data:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        x4 = float(line.split()[3])
        x5 = float(line.split()[4])
        x6 = float(line.split()[5])
        x7 = float(line.split()[6])
        x8 = float(line.split()[7])
        Mcs_l.append(x2)
        E_average.append(x3)
        M_abs_tot.append(x7)
        counter.append(x8)
    if i<2:
        ax1.plot(Mcs_l,counter)
        ax2.plot(Mcs_l,E_average)
        ax3.plot(Mcs_l, M_abs_tot)
    else:
        ax4.plot(Mcs_l,counter)
        ax5.plot(Mcs_l,E_average)
        ax6.plot(Mcs_l, M_abs_tot)

    if i==1:
        f.suptitle("Temperatur =1")
        f.legend(["Ordered configuration","Random configuration"])
        ax1.set_xlabel("MonteCarlo cycles")
        ax1.set_ylabel("Accepted configurations")
        ax2.set_xlabel("MonteCarlo cycles")
        ax2.set_ylabel("Mean Energy")
        ax3.set_xlabel("MonteCarlo cycles")
        ax3.set_ylabel("Mean Magnetisation")
        f.tight_layout()
        f.show()
    i +=1
    data.close()


f2.suptitle("Temperatur =1")
f2.legend(["Ordered configuration","Random configuration"])
ax4.set_xlabel("MonteCarlo cycles")
ax4.set_ylabel("Accepted configurations")
ax5.set_xlabel("MonteCarlo cycles")
ax5.set_ylabel("Mean Energy")
ax6.set_xlabel("MonteCarlo cycles")
ax6.set_ylabel("Mean Magnetisation")
plt.show()
