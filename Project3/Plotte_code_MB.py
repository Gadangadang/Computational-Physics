import matplotlib.pyplot as plt

data = open('Planets_pos.txt', 'r')
tot_p,int_points = data[0].split(' ')
data.readline()
ax = plt.axes(projection='3d')
p =[[],[],[],[]]
for line in range(data):
    for i in range(tot_p):
        nr2 = int(3*(i+1))
        nr1 = int(3*i)
        x1,x2,x3 = line.split(' ')[nr1:nr2]
        p[i].append([x1,x2,x3])
for i in range(tot_p):
    x,y,z = p[i][:,0], p[i][:,1], p[i][:,2]
    ax.plot3D(x,y,z)
plt.show()
