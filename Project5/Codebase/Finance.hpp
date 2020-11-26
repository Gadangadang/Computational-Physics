#ifndef SOLVER_HPP
#define SOLVER_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include "armadillo"
#include <string>

using namespace arma;
using namespace std;

class Finance
{
    private:
    // Attributes
    vec m_avec;
    int m_agents;
    double m_m_0;
    int m_mcs;
    double m_beta;
    double m_variance;
    double m_norm;
    int m_counter;
    string m_filename;
    mt19937_64 generator;
    uniform_real_distribution<double> dis;

    public:
    //Values under are chosen to be public for testing purposes.

    void Initialize(int mcs, int agents, double m_0, string filename);
    //Functions
    void Metropolis();
    void MonteCarlo();
    void calc_variance();
    void print_vec(string filename);
    double ran1();
    double p_dist(double delta_m);
    void print_variance();
};

#endif // ISING_MCINT
