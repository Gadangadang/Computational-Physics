#ifndef SOLVER_HPP
#define SOLVER_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include "armadillo"
#include <string>

using namespace arma;
using namespace std;

class Black_scholes
{
    private:
      mat m_Amtrx;
      vec m_u;
      double m_h;
      double m_dt;
      int m_N;
      double m_alpha;
      string m_filename;
      double m_T;
      vec m_S;
      double m_a;
      double m_b;
    public:
      void Initialize(double T,double X, int N, string filename);
      void D1d_explicit();
      void calc_utilde();
      void print_vals(vec u, double t);
      void init_print();
      void Crank_Nic();
};

#endif // ISING_MCINT
