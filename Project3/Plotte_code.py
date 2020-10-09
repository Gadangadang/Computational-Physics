import matplotlib.pyplot as plt
import numpy as np

data = open('values.txt', 'r')
x_value = []
y_value = []
for line in data:
    l1, l2 = line.split(' ')
    y_value.append(float(l2))
    x_value.append(float(l1))

figure, ax = plt.subplots()
s_r = 0.0046
patch = plt.Circle((0,0),radius = s_r, color = 'orange')
ax.add_artist(patch)
ax.axis('equal')
ax.plot(x_value,np.asarray(y_value),"r--", label="Earth orbit")
plt.legend(loc="upper right")
plt.show()
data.close()
