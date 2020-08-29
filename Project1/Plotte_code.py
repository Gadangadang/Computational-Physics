import matplotlib.pyplot as plt
import numpy as np

data = open('Values.txt', 'r')
y_value = []
x_value = []
y_exact = []

for line in data:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))
    y_exact.append(float(line.split(' ')[2]))



y_value = np.asarray(y_value)

plt.plot(x_value,y_value/(-10), label="Numerical solve")
plt.plot(x_value, y_exact, label="Exact solution" )
plt.legend()
plt.show()
