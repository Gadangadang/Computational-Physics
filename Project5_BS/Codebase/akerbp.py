import numpy as np
import matplotlib.pyplot as plt
from scipy import special, stats
from scipy.interpolate import UnivariateSpline

sigma = 0.4
E = 50
r = 0.04
S = 216.90

data = open("Akerbp.txt", "r")

V1 = []
X = []

for line in data:
    V1.append(float(line.split()[0]))
    X.append(float(line.split()[5]))
X1 = np.log(S/np.asarray(X))

data = open("Aker_numeric.txt", "r")

V2 = []
S2 = []
t = []

for val in data.readline().split():
    S2.append(float(val))

for line in data:
    t.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))

    V2.append(rest_list)

V2 = np.asarray(V2)
X2 = np.log(np.asarray(S2)/E)
plt.plot(X1,V1,label='AkerBP-Reele options verdier')
plt.plot(X2,V2[-1,:],label='AkerBP-numerisk options verdier')
plt.xlim([X1[-1],X1[0]])
plt.legend()
plt.xlabel('x-vals (log(S/E) for S = 216.90)')
plt.ylabel(r'Option-vals  for $V(X,\tau =3 dager)$')
plt.show()
