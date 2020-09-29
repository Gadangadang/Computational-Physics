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

plt.plot(x_value,np.asarray(y_value),"r--", label="Numerical eigenvector")
plt.plot(x_value,np.max(np.asarray(y_value))*anal(i), label = "Analytical solution")
plt.xlabel('$\\rho$')
plt.ylabel('u($\\rho$)')
plt.title("Vertical displacment as a function of $\\rho$")
plt.legend()
plt.savefig("1_b.jpeg")
plt.show()
NAoffset = (np.asarray(y_value) - np.max(np.asarray(y_value))*anal(i))/np.asarray(y_value)
plt.plot(x_value, NAoffset)
plt.xlabel('$\\rho$')
plt.ylabel('Numerical vs analytical')
plt.title("Numerical vs Analytical difference")
plt.show()
data.close()
