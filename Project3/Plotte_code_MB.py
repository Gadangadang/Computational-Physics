import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('Planets_pos.txt', 'r')
int_points,tot_p= data.readline().split(' ')[0:2]
int_points, tot_p = float(int_points), int(tot_p)
ax = plt.axes(projection='3d')
p =[]
potential = []
kinetic = []
t = []
for i in range(tot_p):
    p.append([])
i = 0
j = 0
for line in data:
    if i==1:
        x1 = float(line.split(' ')[0])
        x2 = float(line.split(' ')[1])
        x3 = float(line.split(' ')[2])
        potential.append(x1)
        kinetic.append(x2)
        t.append(x3)
    else:
        x1 = float(line.split(' ')[0])
        x2 = float(line.split(' ')[1])
        x3 = float(float(line.split(' ')[2]))
        p[j].append([x1,x2,x3])
        j+=1
    if i >= tot_p:
        i=0
        j=0
    else:
        i +=1
#print(p[i])
p = np.asarray(p)
potential = np.asarray(potential)

for i in range(tot_p):
    x,y,z = p[i,:,0], p[i,:,1], p[i,:,2]
    ax.plot3D(x,y,z)
year = 5
plt.show()
plt.subplot(1,2,1)
plt.scatter(t,potential)
plt.xlabel('Time[years]')
plt.ylabel('Potential-energi')
plt.ylim(-0.00011870,-0.000117)
plt.xlim(0,year)
plt.subplot(1,2,2)
plt.xlabel('Time[years]')
plt.ylabel('Kinetic-energi')
plt.ylim(0.000055,0.000065)
plt.xlim(0,year)
plt.scatter(t,kinetic)
plt.show()
