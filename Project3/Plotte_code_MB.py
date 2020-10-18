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
x,y,z = p[1,:,0], p[1,:,1], p[1,:,2]
ax.plot3D(x,y,z)
r=0.00464913034
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
"""x = r*np.cos(u)*np.sin(v)
y = r*np.sin(u)*np.sin(v)
z = r*np.cos(v)
ax.plot_wireframe(x, y, z, color="y")"""

ax.set_xlim3d([-np.max(p[-2,:,0]),np.max(p[-2,:,0])])
ax.set_ylim3d([-np.max(p[-2,:,1]),np.max(p[-2,:,1])])
ax.set_zlim3d([-1,1])

year = 5
plt.show()

plt.subplot(1,2,1)
plt.scatter(t,potential)
plt.xlabel('Time[years]')
plt.ylabel('Potential-energi')
plt.ylim(np.min(potential),np.max(potential))
plt.xlim(0,year)
plt.subplot(1,2,2)
plt.xlabel('Time[years]')
plt.ylabel('Kinetic-energi')
plt.ylim(np.min(kinetic),np.max(kinetic))
plt.xlim(0,year)
plt.scatter(t,kinetic)
plt.show()
