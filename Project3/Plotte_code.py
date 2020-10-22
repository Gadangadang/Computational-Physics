import matplotlib.pyplot as plt
import numpy as np

data = open('values_Euler.txt', 'r')
xE_value = []
yE_value = []
for line in data:
    l1, l2 = line.split(' ')
    yE_value.append(float(l2))
    xE_value.append(float(l1))


data = open('values_Verlet.txt', 'r')
xV_value = []
yV_value = []
for line in data:
    l1, l2 = line.split(' ')
    yV_value.append(float(l2))
    xV_value.append(float(l1))


s_r = 0.0046
fig, (ax1, ax2) = plt.subplots(1, 2)
fig.suptitle('Verlet vs Euler')
patchE = plt.Circle((0,0),radius = s_r, color = 'orange')
ax1.add_artist(patchE)
ax1.axis('equal')
ax1.plot(xE_value,np.asarray(yE_value),"r--", label="Earth orbit [Euler]")
ax1.legend()
patchV = plt.Circle((0,0),radius = s_r, color = 'orange')
ax2.add_artist(patchV)
ax2.axis('equal')
ax2.plot(xV_value,np.asarray(yV_value),"r--", label="Earth orbit [Verlet]")
ax2.legend()
plt.show()
data.close()