import numpy as np
import matplotlib.pyplot as plt
from scipy import special

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
    plt.plot(S,V[i,:],label="V(S,t={})".format(t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.show()


sigma = 0.4
E = 50
r = 0.04

def d1(S_t,ti):
    global t
    global sigma
    global E

    return 1/(sigma*np.sqrt(np.max(t)-ti)) * ( np.log(S_t/E) + (r + sigma**2/2)*(np.max(t)-ti))

def d2(S_t, ti):
    return d1(S_t, ti) -sigma*np.sqrt(ti)

def N(d):
    return (special.erf(d/np.sqrt(2)) + 1)/np.sqrt(2)

def Vana(S_t,ti):
    return N( d1(S_t, ti) )*S_t - N(d2(S_t,ti))*E*np.exp(-r*ti)

for i in range(len(t)-1):
    plt.plot(S[1:-1],Vana(S[1:-1],1-t[i]),label="V(S,t={})".format(t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.show()
