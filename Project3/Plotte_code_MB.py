import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
data = open('Planets_pos.txt', 'r')
int_points,tot_p= data.readline().split(' ')[0:2]
int_points, tot_p = float(int_points), int(tot_p)
ax = plt.axes(projection='3d')
p =[]
potential = []
for i in range(tot_p):
    p.append([])
    potential.append([])
i = 0

pe = 0
for line in data:
    #print(line)
    x1 = float(line.split(' ')[0])
    x2 = float(line.split(' ')[1])
    x3 = float(float(line.split(' ')[2]))
    x4 = float(float(line.split(' ')[3]))
    p[i].append([x1,x2,x3])
    potential[i].append(x4)
    pe +=1
    i +=1
    if i == tot_p:
        i=0
#print(p[i])
p = np.asarray(p)
potential = np.asarray(potential)

for i in range(tot_p):
    x,y,z = p[i,:,0], p[i,:,1], p[i,:,2]
    ax.plot3D(x,y,z)

plt.show()

points = range(10000)

plt.scatter(points,potential[0,:])
plt.ylim(-0.00011870,-0.000117)
plt.show()
