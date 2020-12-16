import numpy as np
import matplotlib.pyplot as plt
from scipy import special, stats
from scipy.interpolate import UnivariateSpline
from autograd import elementwise_grad as egrad
from scipy.misc import derivative
import autograd.numpy as npa

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


def Vana(S_t, ti, sigma, r):
    return N(d1(S_t, ti)) * S_t - N(d2(S_t, ti)) * E * np.exp(-r * (np.max(t) - ti))


for i in range(1, len(t)):
    plt.plot(S[1:-1], Vana(S[1:-1], T - t[i], sigma, r),
             label="V(S,t={:.1f})".format(T - t[i]))

plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel("Value of option")
plt.title("Analytical solution to Black-Scholes")
plt.savefig("Results/Av_sol.jpeg")
plt.show()


for i in range(1, len(t)):
    plt.plot(S, np.abs(V[i, :] - Vana(S, T - t[i], sigma, r)),
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


def gamma(V, S):
    dvds = np.diff(V, 1) / np.diff(S, 1)
    ddvdds = np.diff(dvds, 1) / np.diff(0.5 * (S[:-1] + S[1:]), 1)

    return ddvdds


sdata = open("greeks_s.txt", "r")

VS = []
sig = []
tsigma = []

for val in sdata.readline().split():
    sig.append(float(val))

for line in sdata:
    tsigma.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))

    VS.append(rest_list)

VS = np.asarray(VS)
sig = np.asarray(sig)
tsigma = np.asarray(tsigma)


def vega(VS, sig):

    firstdiv = np.diff(VS) / np.diff(sig)
    return firstdiv

# Usikker på denne også, mtp at vi plotter for t slik vi gjør, så ja..


rdata = open("greeks_r.txt", "r")
VR = []
rho = []
trho = []

for val in rdata.readline().split():
    rho.append(float(val))

for line in rdata:
    trho.append(float(line.split()[0]))
    rest_list = []

    for element in line.split()[1:]:
        rest_list.append(float(element))

    VR.append(rest_list)

VR = np.asarray(VR)
rho = np.asarray(rho)
trho = np.asarray(trho)


def rhos(VR, rho):
    firstdiv = np.diff(VR) / np.diff(rho)
    return firstdiv


for i in range(1, len(t)):
    plt.plot(S[1:-1], delta(V[i, 1:-1], S[1:-1]),
             label=r"$\Delta$ for t = {:.1f}".format(T - t[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\Delta$ ")
plt.title(r"Greek $\Delta$ as function of stock price")
plt.savefig("Results/delta.jpeg")
plt.show()


for i in range(1, len(t)):
    plt.plot(S[1:-3], gamma(V[i, 1:-1], S[1:-1]),
             label=r"$\gamma$ for t = {:.1f}".format(T - t[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\gamma$ ")
plt.title(r"Greek $\gamma$ as function of stock price")
plt.savefig("Results/gamma.jpeg")
plt.show()


# Rho and Vega
for i in range(len(tsigma)):
    plt.plot(sig[:-1], vega(VS[i], sig),
             label=r"$\nu$($\sigma$), t={:.1f}".format(T - tsigma[i]))

plt.legend()
plt.xlabel("Volatility")
plt.ylabel(r"vega ")
plt.title(r"Greek vega as function of volatility")
plt.savefig("Results/vega.jpeg")
plt.show()


for i in range(len(trho)):
    plt.plot(rho[:-1], rhos(VR[i], rho),
             label=r"$\rho$(r), t={:.1f}".format(T - trho[i]))

plt.legend()
plt.xlabel("Risk free interest rate")
plt.ylabel(r"$\rho$ ")
plt.title(r"Greek $\rho$ as function of risk free interest rate")
plt.savefig("Results/rho.jpeg")
plt.show()


# FOOOR TAUUU

vtid = np.zeros(len(t))
for i in range(len(t)):
    vtid[i] = V[i, -1]


def theta(vtid, t):
    dvdt = -np.diff(vtid) / np.diff(t)
    return dvdt


plt.plot(t[:-1], theta(vtid, t), label=r"$\Theta$ as function of time")
plt.legend()
plt.xlabel(r"Time $\tau$")
plt.ylabel(r"$\tau$ ")
plt.title(r"Greek $\Theta$ as function of $\tau$")
plt.savefig("Results/tau.jpeg")
plt.show()

# Derivation of anaytical expression


def delta_ana(S, tau):
    a = (special.erf((np.log(S / E)) / (np.sqrt(2) * sigma * tau))) / np.sqrt(2)
    b = - (np.exp(-np.log(S / E)**2 / (2 * sigma**2 * tau))) / \
        (S * sigma * np.sqrt(np.pi * tau))
    c = np.exp(-np.log(S / E)**2 / (2 * sigma**2 * tau)) / \
        (sigma * np.sqrt(np.pi * tau))
    return a + b + c


def gamma_ana(S, tau):
    a = -np.exp((-np.log(S / E)**2) / (2 * sigma**2 * tau) - r *
                tau) / (np.sqrt(np.pi) * sigma**3 * tau**(3 / 2) * S**2)
    b = (np.exp(r * tau) * S - E) * np.log(S / E) - sigma**2 * \
        tau * np.exp(r * tau) * S - E * sigma**2 * tau
    return a * b


def theta_ana(tau, S):
    a = E / np.sqrt(2) * np.exp(-r * tau) * (-(np.sqrt(2) * np.log(S / E) * np.exp((-np.log(
        S / E)**2) / (2 * sigma**2 * tau))) / (np.sqrt(np.pi * tau) * sigma**2) - np.sqrt(tau))
    b = -E * r * np.exp(-r * tau) / np.sqrt(2) * (special.erf(np.log(S / E) /
                                                              (np.sqrt(2 * tau) * sigma)) - sigma * np.sqrt(tau))
    c = (S * np.log(S / E) * np.exp((-np.log(S / E)**2) /
                                    (2 * sigma**2 * tau))) / (2 * np.sqrt(np.pi) * sigma * tau**(3 / 2))
    return a + b + c


def vega_ana(sigma, S, tau):
    a = (E * np.exp(-r * tau)) / (np.sqrt(2)) * ((-np.sqrt(2) * np.log(S / E) *\
         np.exp((-np.log(S / E)**2) / (2 * sigma**2 * tau))) / (np.sqrt(np.pi * tau) * \
         sigma**2) - np.sqrt(tau))

    b = (S * np.log(S / E) * np.exp((-np.log(S / E)**2) /\
        (2 * sigma**2 * tau))) / (np.sqrt(np.pi * tau) * sigma**2)


    return a + b


def rho_ana(r, S, tau):
    a = E * tau * np.exp(-r * tau) / np.sqrt(2)
    b = sigma * np.sqrt(tau) - special.erf(np.log(S / E) /
                                           (np.sqrt(2 * tau) * sigma))
    return a * b

print(trho)

for i in range(len(trho)-1):
    plt.plot(S, delta_ana(S, trho[i]),
             label=r"$\Delta$ for t = {:.1f}".format(T - trho[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\Delta_{analytical}$ ")
plt.title(r"Greek $\Delta_{analytical}$ as function of stock price")
plt.savefig("Results/delta_ana.jpeg")
plt.show()

for i in range(len(trho)-1):
    plt.plot(S, gamma_ana(S, trho[i]),
             label=r"$\gamma$ for t = {:.1f}".format(T - trho[i]))
plt.legend()
plt.xlabel("Price of underlying asset")
plt.ylabel(r"$\gamma_{analytical}$ ")
plt.title(r"Greek $\gamma_{analytical}$ as function of stock price")
plt.savefig("Results/gamma_ana.jpeg")
plt.show()

St = np.max(S)


plt.plot(trho, theta_ana(St, trho),
         label=r"$\Theta$($\tau$)")
plt.legend()
plt.xlabel(r"Time $\tau$ ")
plt.ylabel(r"$\Theta_{analytical}$ ")
plt.title(r"Greek $\Theta_{analytical}$ as function of time")
plt.savefig("Results/theta_ana.jpeg")
plt.show()

for i in range(len(tsigma)-1):
    plt.plot(sig, vega_ana(sig, St, tsigma[i]),
             label=r"$\nu$ for t = {:.1f}".format(T - tsigma[i]))
plt.legend()
plt.xlabel(r"Volatility $\sigma$")
plt.ylabel(r"$\nu_{analytical}$ ")
plt.title(r"Greek $\nu_{analytical}$ as function of volatility")
plt.savefig("Results/vega_ana.jpeg")
plt.show()



for i in range(len(trho)-1):
    plt.plot(rho, rho_ana(rho, St, trho[i]),
             label=r"$\rho$ for t = {:.1f}".format(T - trho[i]))
plt.legend()
plt.xlabel("Risk free interest rate")
plt.ylabel(r"$\rho_{analytical}$ ")
plt.title(r"Greek $\rho_{analytical}$ as function of risk free interest rate")
plt.savefig("Results/rho_ana.jpeg")
plt.show()
