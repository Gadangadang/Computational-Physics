import matplotlib.pyplot as plt
import numpy as np

data = open('valn0.txt', 'r')
y_value = []
x_value = []

data1 = open('valn1.txt', 'r')
y1_value = []
x1_value = []

data2 = open('valn2.txt', 'r')
y2_value = []
x2_value = []
ex_vals = []

for line in data:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))

for line in data1:
    y1_value.append(float(line.split(' ')[0]))
    x1_value.append(float(line.split(' ')[1]))

for line in data2:
    y2_value.append(float(line.split(' ')[0]))
    x2_value.append(float(line.split(' ')[1]))
    ex_vals.append(float(line.split(" ")[2]))

plt.plot(x2_value, ex_vals, "k-",label="Exact solution")
plt.plot(x_value,y_value,"r--", label="n=10")
plt.plot(x1_value, y1_value,"b--", label="n=100" )
plt.plot(x2_value, y2_value,"y--",label="n=1000" )
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.savefig("1_b.jpeg")
plt.show()

data.close()
data1.close()
data2.close()
