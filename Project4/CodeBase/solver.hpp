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
    double m_M;
    double m_E;
    int m_spins;
    int m_tot_spins;
    int m_cycles;
    int m_mcs;
    vec m_w;
    vec m_average;
    double m_init_temp;
    double m_init_temp_sq;
    int m_counter;
    mt19937_64 generator;
    uniform_real_distribution<double> dis;




    public:
    //Initializer
    void Initialize(int n_spins, int mcs, double init_temp, int param_1);
    //Functions
    void Metropolis();
    void MonteCarloV1();
    double up_down(double a);
    int periodic(int i, int limit, int add);
    double ran1();
    void init_output();
    void output();
    double TC_calc(double &Tc_L, double Li);
    void find_tc_with_read(double &Tc_L);





};

#endif // SOLVER_MCINT
