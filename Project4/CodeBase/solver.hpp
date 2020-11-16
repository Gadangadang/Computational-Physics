#ifndef SOLVER_HPP
#define SOLVER_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include "armadillo"

using namespace arma;
using namespace std;

class solver
{
    private:
    // Attributes
    mat m_smatrix;
    long m_part;
    double m_M;
    double m_E;
    int m_spins;
    int m_mcs;
    vec m_w;
    vec m_average;
    double m_init_temp;

    mt19937_64 generator;
    uniform_real_distribution<double> dis;




    public:
    //Initializer
    void Initialize(int n_spins, int mcs, double init_temp);
    //Functions
    void Metropolis();
    void MonteCarloV1();
    int periodic(int i, int limit, int add);
    double ran1();
    void output();
    




};

#endif // SOLVER_MCINT 
