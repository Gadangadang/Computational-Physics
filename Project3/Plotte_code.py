import matplotlib.pyplot as plt
import numpy as np

data = open('values.txt', 'r')
x_value = []
y_value = []
for line in data:
    l1, l2 = line.split(' ')
    y_value.append(float(l2))
    x_value.append(float(l1))


plt.plot(x_value,np.asarray(y_value),"r--", label="Numerical eigenvector")
plt.show()
data.close()
