import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import interp1d, UnivariateSpline

dataL40 = open("MCL40.txt", "r")
cv40=[]
xi40 = []
t = []
dataL40.readline()
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
t6 = []


for line in dataL60:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv60.append(x1)
        xi60.append(x2)
        t6.append(x3)
dataL60.close()


dataL80 = open("MCL80.txt", "r")
cv80=[]
xi80 = []
t8 = []

for line in dataL80:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv80.append(x1)
        xi80.append(x2)
        t8.append(x3)
dataL80.close()



dataL100 = open("MCL100.txt", "r")
cv100=[]
xi100 = []
t1 = []


for line in dataL100:
        x1 = float(line.split()[0])
        x2 = float(line.split()[1])
        x3 = float(line.split()[2])
        cv100.append(x1)
        xi100.append(x2)
        t1.append(x3)
dataL100.close()

t = np.asarray(t)
cv40 = np.asarray(cv40)

#Cv40
tindex = np.argsort(t)
cv40 = cv40[tindex]
t = t[tindex]

spl40 = UnivariateSpline(t, cv40)
spl40.set_smoothing_factor(0.61)

#Cv60
t6 = np.asarray(t6)
cv60 = np.asarray(cv60)
t6index = np.argsort(t6)
cv60 = cv60[t6index]
t6 = t6[t6index]

spl60 = UnivariateSpline(t6, cv60)
spl60.set_smoothing_factor(5)

#Cv80
t8 = np.asarray(t8)
cv80 = np.asarray(cv80)
t8index = np.argsort(t8)
cv80 = cv80[t8index]
t8 = t8[t8index]

spl80 = UnivariateSpline(t8, cv80)
spl80.set_smoothing_factor(10.8)

#Cv100
t1 = np.asarray(t1)
cv100 = np.asarray(cv100)
t1index = np.argsort(t1)
cv100 = cv100[t1index]
t1 = t1[t1index]

spl100 = UnivariateSpline(t1, cv100)
spl100.set_smoothing_factor(13)

#plt.scatter(t, cv40, label="C_v 40")
plt.plot(t,spl40(t),"r",label="C_v 40 Univeriate spline")


#plt.scatter(t6, cv60, label="C_v 60")
plt.plot(t6,spl60(t6),"k",label="C_v 60 Univeriate spline")


#plt.scatter(t8, cv80, label="C_v 80")
plt.plot(t8,spl80(t8),"brown",label="C_v 80 Univeriate spline")


#plt.scatter(t1, cv100, label="C_v 100")
plt.plot(t1,spl100(t1),"green",label="C_v 100 Univeriate spline")

plt.legend()
plt.xlabel("T [J]")
plt.ylabel("C_v")
plt.savefig("Cv_of_T.jpeg")
plt.show()




"""
Interpolate to find vals
"""



cv40max = np.max( spl40(t) )
cv60max = np.max( spl60(t6) )
cv80max = np.max( spl80(t8) )
cv100max = np.max( spl100(t1) )


t40index = int(np.where(cv40max == spl40(t) )[0][0])

t40max = t[t40index]

t60index = int(np.where(cv60max == spl60(t6) )[0][0])
t60max = t[t60index]

t80index = int(np.where(cv80max == spl80(t8) )[0][0])
t80max = t[t80index]

t100index = int(np.where(cv100max == spl100(t1) )[0][0])
t100max = t[t100index]


a46 = (t40max - t60max)/(40**(-1) - 60**(-1))
a68 = (t60max - t80max)/(60**(-1) - 80**(-1))
a810 = (t80max - t100max)/(80**(-1) - 100**(-1))
amean = (a46 + a68 + a810)/3

tcinf_40 = t40max - amean*40**(-1)
tcinf_60 = t60max - amean*60**(-1)
tcinf_80 = t80max - amean*80**(-1)
tcinf_100 = t100max - amean*100**(-1)

Tcin_mean = (tcinf_40 + tcinf_60 + tcinf_80 + tcinf_100)/4
print("Tc at infinity is {:.3f}".format(Tcin_mean))
