import numpy as np
import matplotlib.pyplot as plt

data = open("u.txt","r")

V = []
S = []
t = []

for val in data.readline().split():
    S.append(float(val))


for line in data:
    t.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))


    V.append(rest_list)

V = np.asarray(V)
S = np.asarray(S)
t = np.asarray(t)

for i in range(len(t)):
    plt.plot(S[1:-1],V[i,1:-1],label="V(S,t={})".format(t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.show()
