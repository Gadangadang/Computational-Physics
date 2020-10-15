import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('Planets_pos.txt', 'r')
int_points,tot_p= data.readline().split(' ')[0:2]
int_points, tot_p = float(int_points), int(tot_p)
ax = plt.axes(projection='3d')
p =[]
potential = []
t = []
for i in range(tot_p):
    p.append([])
i = 0
j = 0
for line in data:
    if i==1:
        x1 = float(line.split(' ')[0])
        x2 = float(line.split(' ')[1])
        potential.append(x1)
        t.append(x2)
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

plt.show()
plt.scatter(t,potential)
plt.ylim(-0.00011870,-0.000117)
plt.xlim(0,10)
plt.show()
