import matplotlib.pyplot as plt
import numpy as np

data = open('Values.txt', 'r')
y_value = []
x_value = []
y_exact = []
relativeerror = []

for line in data:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))
    y_exact.append(float(line.split(' ')[2]))
    relativeerror.append(float(line.split(' ')[3]))



y_value = np.asarray(y_value)

plt.plot(x_value,y_value, label="Numerical solve")
plt.plot(x_value, y_exact, label="Exact solution" )
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.show()


plt.plot()
