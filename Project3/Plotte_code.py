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
patch = plt.Circle((0,0),radius = s_r)
ax.add_artist(patch)
ax.plot(x_value,np.asarray(y_value),"r--", label="Numerical eigenvector")
#plt.scatter(0,0,s=0.0046,c='yellow')
plt.show()
data.close()
