import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('MonteCarloRun.txt', 'r')


files = ["T_1_o.txt","T_1_n.txt","T_2_o.txt","T_2_n.txt"]
i = 0
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
    plt.plot(Mcs_l,counter)
    if i==1:
        plt.legend(["Ordered configuration","Random configuration"])
        plt.title("Temperatur =1")
        plt.xlabel("MonteCarlo cycles")
        plt.ylabel("Accepted configurations")
        plt.show()
    i +=1
    data.close()
plt.legend(["Ordered configuration","Random configuration"])
plt.title("Temperatur =2")
plt.xlabel("MonteCarlo cycles")
plt.ylabel("Accepted configurations")
plt.show()
