import matplotlib.pyplot as plt
import numpy as np

data = open('valn0.txt', 'r')
y_value = []
x_value = []

for line in data:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))

plt.plot(x_value,y_value,"r-", label="n=10")
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.show()

data.close()

data1 = open('valn1.txt', 'r')
y1_value = []
x1_value = []

for line in data1:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))

plt.plot(x1_value, y1_value,"bo", label="n=100" )
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.show()

data1.close()

data2 = open('valn2.txt', 'r')
y2_value = []
x2_value = []

for line in data2:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))

print(y2_value)

plt.plot(x2_value, y2_value,"g--",label="n=1000" )
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.show()

data2.close()
