import matplotlib.pyplot as plt
import numpy as np

data = open('values.txt', 'r')
x_value = []
y_value = []
for line in data:
    l1, l2 = line.split(' ')
    y_value.append(float(l2))
    x_value.append(float(l1))


rho = np.asarray(x_value)
i  = np.linspace(1,len(rho), len(rho))
def anal(i):
    return np.sin(np.pi * i /len(rho))
plt.plot(x_value,np.asarray(y_value),"r--", label="n=10")
plt.plot(x_value,np.max(np.asarray(y_value))*anal(i))
plt.xlabel('x=(0,1)')
plt.ylabel('u(x)')
plt.legend()
plt.savefig("1_b.jpeg")
plt.show()

data.close()
