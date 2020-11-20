import matplotlib.pyplot as plt
import numpy as np

dataL40 = open(".txt", "r")
cv40=[]
xi40 = []
t = []

for line in dataL40:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv40.append(x1)
        xi40.append(x2)

dataL40.close()



dataL60 = open(".txt", "r")

dataL60.close()



dataL80 = open(".txt", "r")

dataL80.close()



dataL100 = open(".txt", "r")

dataL100.close()
