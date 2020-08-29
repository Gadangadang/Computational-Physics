import matplotlib.pyplot as plt

data = open('Values.txt', 'r')
y_value = []
x_value = []
for line in data:
    y_value.append(float(line.split(' ')[0]))
    x_value.append(float(line.split(' ')[1]))
print(x_value[::-1])
plt.plot(x_value[::-1],y_value[::-1])
plt.show()
