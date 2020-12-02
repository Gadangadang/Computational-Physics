import numpy as np
import matplotlib.pyplot as plt

data = open("u.txt","r")

V = []
S = []
t = []

for line in data:
    for element in line.split():
        S.append(float(element))
    break

for line in data:
    t.append(float(line.split()[0]))
    rest_list = []
    i = 0
    for element in line.split():
        if i == 0:
            pass
        else:
            rest_list.append(float(element))

    V.append(rest_list)

V = np.asarray(V)
S = np.asarray(S)
t = np.asarray(t)

for i in range(len(t)):
    plt.plot(S,V[:,i],label="V(S,t={})".format(t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.show()
