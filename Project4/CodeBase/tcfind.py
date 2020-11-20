import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import interp1d

dataL40 = open("MCL40.txt", "r")
cv40=[]
xi40 = []
t = []

for line in dataL40:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv40.append(x1)
        xi40.append(x2)
        t.append(x3)
dataL40.close()


dataL60 = open("MCL60.txt", "r")
cv60=[]
xi60 = []


for line in dataL60:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv60.append(x1)
        xi60.append(x2)
dataL60.close()



dataL80 = open("MCL80.txt", "r")
cv80=[]
xi80 = []


for line in dataL80:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv80.append(x1)
        xi80.append(x2)
dataL80.close()



dataL100 = open("MCL100.txt", "r")
cv100=[]
xi100 = []


for line in dataL100:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv100.append(x1)
        xi100.append(x2)
dataL100.close()

plt.scatter(t, cv40, label="C_v 40")
spl40 = UnivariateSpline(t, cv40)
spl40.set_smoothing_factor(0.5)
plt.plot(t,spl40,label="C_v 40 spline")

plt.scatter(t, cv60, label="C_v 60")
spl60 = UnivariateSpline(t, cv60)
spl60.set_smoothing_factor(0.5)
plt.plot(t,spl60,label="C_v 60 spline")

plt.scatter(t, cv80, label="C_v 80")
spl80 = UnivariateSpline(t, cv80)
spl80.set_smoothing_factor(0.5)
plt.plot(t,spl80,label="C_v 80 spline")

plt.scatter(t, cv100, label="C_v 100")
spl100 = UnivariateSpline(t, cv100)
spl100.set_smoothing_factor(0.5)
plt.plot(t,spl100,label="C_v 100 spline")

plt.legend()
plt.xlabel("T [K]")
plt.ylabel("C_v")
plt.savefig("Cv_of_T.jpeg")
plt.show()

t = np.asarray(t)
cv40max = np.max( spl40 )
cv60max = np.max( spl60 )
cv80max = np.max( spl80 )
cv100max = np.max( spl100 )

t40index = int(np.where(cv40max == cv40 )[0])
t40max = t[t40index]

t60index = int(np.where(cv60max == cv60 )[0])
t60max = t[t60index]

t80index = int(np.where(cv80max == cv80 )[0])
t80max = t[t80index]

t100index = int(np.where(cv100max == cv100 )[0])
t100max = t[t100index]

cvinter = np.array([cv40max, cv60max, cv80max, cv100max])
tinter = np.array([t40max, t60max, t80max, t100max])
