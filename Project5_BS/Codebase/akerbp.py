import numpy as np
import matplotlib.pyplot as plt
from scipy import special, stats
from scipy.interpolate import UnivariateSpline

data = open("Akerbp.txt", "r")

V1 = []
S1 = []

for line in data:
    S1.append(float(line.split()[0]))
    V1.append(float(line.split()[1]))


data = open("Aker_numeric.txt", "r")

V2 = []
S2 = []
t = []

for val in data.readline().split():
    S2.append(float(val))

for line in data:
    t.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))

    V2.append(rest_list)

S1 = np.asarray(S1)
time = ['10.12','11.12','14.12','15.12']
ac_tim = [-1,-2,-5,-6]
plt.scatter(S1,np.asarray(V1),label='Reele options verdier')
for i, txt in enumerate(time):
    plt.annotate(txt, (S1[i], V1[i]))

V_num=[]
S_num = []
for j in range(len(time)):
    indx = int(np.where(np.abs(S1[j]-S2)==min(np.abs(S1[j]-S2)))[0][0])
    S_num.append(S2[indx])
    V_num.append(V2[int(-j-1)][indx])
plt.scatter(S_num,V_num,label='Numeriske options verdier')
for i, txt in enumerate(time):
    plt.annotate(txt, (S_num[i], V_num[i]))


plt.legend()
plt.xlabel('Stock-prizes')
plt.ylabel('Option-vals')
plt.show()
