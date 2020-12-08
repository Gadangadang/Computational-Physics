import numpy as np
import matplotlib.pyplot as plt
from scipy import special, stats
from scipy.interpolate import UnivariateSpline

sigma = 0.4
E = 50
r = 0.04


data = open("u.txt", "r")

V = []
S = []
t = []

for val in data.readline().split():
    S.append(float(val))


for line in data:
    t.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))

    V.append(rest_list)

V = np.asarray(V)
S = np.asarray(S)
t = np.asarray(t)
T = np.max(t)

for i in range(len(t)):
    plt.plot(S, V[i, :], label="V(S,t={:.1f})".format(T - t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.title("Numerical solution to Black-Scholes")
plt.savefig("Results/Num_sol.jpeg")
plt.show()


def d1(S_t, ti):
    global t
    global sigma
    global E

    return 1 / (sigma * np.sqrt(np.max(t) - ti)) * (np.log(S_t / E) + (r + sigma**2 / 2) * (np.max(t) - ti))


def d2(S_t, ti):
    return d1(S_t, ti) - sigma * np.sqrt(np.max(t) - ti)


def N(d):
    return stats.norm.cdf(d)  # (special.erf(d/np.sqrt(2)) + 1)/np.sqrt(2)


def Vana(S_t, ti):
    return N(d1(S_t, ti)) * S_t - N(d2(S_t, ti)) * E * np.exp(-r * (np.max(t) - ti))


for i in range(1, len(t)):
    plt.plot(S[1:-1], Vana(S[1:-1], T - t[i]),
             label="V(S,t={:.1f})".format(T - t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.title("Analytical solution to Black-Scholes")
plt.savefig("Results/Av_sol.jpeg")
plt.show()
"""
start = int(np.where(np.abs(S-30) < 0.1)[0][0])
end = int(np.where(np.abs(S-(np.max(S)/2 + 15)) < 0.1)[0][0])"""

for i in range(1, len(t)):
    plt.plot(S, np.abs(V[i, :] - Vana(S, T - t[i])),
             label="|V_dif|,t={:.1f}".format(T - t[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value difference for option ")
plt.title("Value difference for analytical and numerical calculation of option")
plt.savefig("Results/Diff_ana_num.jpeg")
plt.show()

# GREEEEKS


def delta(V, S):
    V_spl = UnivariateSpline(S, V, s=0, k=4)
    V_spl_1d = V_spl.derivative(n=1)
    return V_spl_1d(S)

# Usikker på om denne er riktig da


def gamma(V, S):
    V_spl = UnivariateSpline(S, V, s=0, k=4)
    V_spl_2d = V_spl.derivative(n=2)
    return V_spl_2d(S)


"""
def vega():
    return
"""
# Usikker på denne også, mtp at vi plotter for t slik vi gjør, så ja..


def theta(V, t):
    V_spl = UnivariateSpline(t, V, s=0, k=4)
    V_spl_1d = V_spl.derivative(n=1)
    return V_spl_1d(t)


"""
def rho():
    return
"""

for i in range(1, len(t)):
    plt.plot(S[1:-1], delta(V[i, 1:-1], S[1:-1]),
             label=r"$\Delta$ for t = {:.1f}".format(T - t[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\Delta$ ")
plt.title(r"Greek $\Delta$ as function of stock price")
plt.show()

for i in range(1, len(t)):
    plt.plot(S[1:-1], gamma(V[i, 1:-1], S[1:-1]),
             label=r"$\gamma$ for t = {:.1f}".format(T - t[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\gamma$ ")
plt.title(r"Greek $\gamma$ as function of stock price")
plt.show()

tgrad = np.linspace(0,np.max(t),len(V))

j = int(0.1*len(S))

dVdt = np.zeros((len(V),len(S)))
for i in range(len(V)):
    dVdt[:,i] = theta(V[:, i], tgrad)

print(np.shape(dVdt))

for i in range(len(t)):
    plt.plot(S, dVdt[i,:],
                 label=r"$\Theta$ for t = {:.1f}".format(T - t[i]))


plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\Theta$ ")
plt.title(r"Greek $\Theta$ as function of stock price")
plt.show()
